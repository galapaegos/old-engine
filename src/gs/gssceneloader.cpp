#include <gs/gssceneloader.h>
#include <gs/gsresourcemgr.h>

namespace gs
{
	namespace gssceneloader
	{
		/*
		gsgeom::gsscene *read (const gsstring &pfile)
		{
			FILE *f = fopen (pfile.str (), "r");
			if (!f)
				return NULL;

			gsutil::gsqueue<gsstring> m_List;
			gsgeom::gsscene *newScene = new gsgeom::gsscene;

			readFile (f, m_List);
			readHelper (f, newScene, m_List);

			return newScene;
		}

		void readHelper (FILE *pFile, gsgeom::gsscene *s, gsutil::gsqueue<gsstring> &list)
		{
			if (list.getSize () == 0)
				readFile (pFile, list);
			gsstring temp = list[0];

			while ((temp.find ("[scene version=") == -1) && (list.getSize () > 0))
			{
				list.erase (0);
				temp = list[0];
			}

			if (list.getSize () == 0)
				return;

			//find the version, make sure we can read the file
			temp.remove ("[scene version=");
			temp.remove ("]");

			// temp now contains the version, and we'll want to
			// perform some kinda check here eventually

			//were done with the version
			list.erase (0);
			if (list.getSize () == 0)
				readFile (pFile, list);

			//eat the '{' and that is all
			list.erase (0);
			if (list.getSize () == 0)
				readFile (pFile, list);

			temp = list[0];

			if (temp.find ("[camera]") > -1)
			{
				//eating the '[camera]' string
				list.erase (0);
				if (list.getSize () == 0)
					readFile (pFile, list);
				temp = list[0];

				// eat the '{'
				list.erase (0);
				if (list.getSize () == 0)
					readFile (pFile, list);
				temp = list[0];

				//'width x height' fov nearplane farplane
				int xpos = temp.find ('x');
				gsstring width = temp.substring (0, xpos);
				temp.remove (0, xpos + 1);
				int spos = temp.find (' ');
				gsstring height = temp.substring (0, spos);

				//int w = atoi (width.str ());
				//int h = atoi (height.str ());

				temp.remove (0, spos + 1);

				//read fov
				spos = temp.find (' ') + 1;
				gsstring fov = temp.substring (0, spos);

				//float ffov = (float)atof (fov.str ());

				temp.remove (0, spos);

				//read nearplane value
				spos = temp.find (' ') + 1;
				gsutil::gsstring strFnear = temp.substring (0, spos);

				//float fnear = (float)atof (strFnear.str ());

				temp.remove (0, spos);

				//read farplane value
				//float ffar = (float)atof (temp.str ());

				// position look-at
				list.erase (0);
				if (list.getSize () == 0)
					readFile (pFile, list);
				temp = list[0];

				// read position
				int bpos = temp.find (']') + 1;
				gsstring pos = temp.substring (0, bpos + 1);

				pos.remove ("[");
				pos.remove ("]");

				gsgeom::gsvec3f vpos;
				{
					float x = (float)atof (pos.str ());
					pos.remove (0, pos.find (' ')+1);

					float y = (float)atof (pos.str ());
					pos.remove (0, pos.find (' ')+1);

					float z = (float)atof (pos.str ());

					vpos.set (x, y, z);
				}

				temp.remove (0, bpos + 1);

				gsstring dir = temp;

				dir.remove ("[");
				dir.remove ("]");

				gsgeom::gsvec3f vdir;
				{
					float x = (float)atof (dir.str ());
					dir.remove (0, dir.find (' ')+1);

					float y = (float)atof (dir.str ());
					dir.remove (0, dir.find (' ')+1);

					float z = (float)atof (dir.str ());

					vdir.set (x, y, z);
				}

				//add the camera info to the scene
				//s->m_CameraInfo = new gscamerainfo (vpos, vdir, w, h, 
				//	ffov, fnear, ffar);

				list.erase (0);

				//eat the '}'
				if (list.getSize () == 0)
					readFile (pFile, list);
				list.erase (0);
				if (list.getSize () == 0)
					readFile (pFile, list);
				temp = list[0];
			}

			if (list.getSize () == 0)
				readFile (pFile, list);
			temp = list[0];

			gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;

			while (temp.find ("}") == -1)
			{
				if (temp.find ("vertices") > -1)
				{
					//vertices 'size'
					temp.remove ("vertices ");
					int numVertices = atoi (temp.str ());
					gi->m_vPoints.resize (numVertices + 1);
					for (int i = 0; i < numVertices; i++)
					{
						list.erase (0);
						if (list.getSize () == 0)
							readFile (pFile, list);
						temp = list[0];

						float x = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float y = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float z = (float)atof (temp.str ());

						gi->m_vPoints.add (gsgeom::gsvec3f (x, y, z));
					}

					list.erase (0);
					if (list.getSize () == 0)
						readFile (pFile, list);
					temp = list[0];
				}
				else if (temp.find ("indices") > -1)
				{
					//indices 'size'
					temp.remove ("indices ");
					int numIndices = atoi (temp.str ());

					temp.remove (0, temp.find (' ') + 1);

					temp.remove ("type ");
					int type = atoi (temp.str ());

					gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
					it->indexType = type;
					it->m_vIndices.resize (numIndices);
					for (int i = 0; i < numIndices; i++)
					{
						list.erase (0);
						if (list.getSize () == 0)
							readFile (pFile, list);
						temp = list[0];

						while (temp.find (' ') != -1)
						{
							int x = atoi (temp.str ());
							temp.remove (0, temp.find (' ') + 1);

							it->m_vIndices.add (x);
							i++;
						}

						int y = atoi (temp.str ());
						it->m_vIndices.add (y);
						i++;
					}

					if (list.getSize () == 0)
						readFile (pFile, list);
					list.erase (0);
					if (list.getSize () == 0)
						readFile (pFile, list);
					temp = list[0];

					gi->m_vIndices.add (it);
				}
				else if (temp.find ("colors") > -1)
				{
					//colors 'size'
					temp.remove ("colors ");
					int numColors = atoi (temp.str ());

					gi->m_vColors.resize (numColors);

					if (list.getSize () == 0)
						readFile (pFile, list);

					for (int i = 0; i < numColors; i++)
					{
						list.erase (0);
						if (list.getSize () == 0)
							readFile (pFile, list);
						temp = list[0];

						float r = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float g = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float b = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float a = (float)atof (temp.str ());

						gi->m_vColors.add (gsgeom::gscolor (r, g, b, a));
					}

					if (list.getSize () == 0)
						readFile (pFile, list);
					list.erase (0);
					if (list.getSize () == 0)
						readFile (pFile, list);
					temp = list[0];
				}
				else if (temp.find ("normals") > -1)
				{
					//normals 'size'
					temp.remove ("normals ");
					int numNormals = atoi (temp.str ());

					gi->m_vNormals.resize (numNormals);

					for (int i = 0; i < numNormals; i++)
					{
						list.erase (0);
						if (list.getSize () == 0)
							readFile (pFile, list);
						temp = list[0];

						float x = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float y = (float)atof (temp.str ());
						temp.remove (0, temp.find (' ') + 1);

						float z = (float)atof (temp.str ());

						gi->m_vNormals.add (gsgeom::gsvec3f (x, y, z));
					}

					list.erase (0);
					if (list.getSize () == 0)
						readFile (pFile, list);
					temp = list[0];
				}
				else if (temp.find ("textures") > -1)
				{
					//textures 'size'
					//TODO: must finish this, and add in blending factors, etc for multitexturing
					temp.remove ("textures ");
					int numTextures = atoi (temp.str ());

					//gi->m_iTextureCount = numTextures;
					for (int i = 0; i < numTextures; i++)
					{
						list.erase (0);
						if (list.getSize () == 0)
							readFile (pFile, list);
						temp = list[0];

						//removing [texture='name.*']
						temp.remove ("[");
						temp.remove (0, temp.find ("=")+1);
						gsstring texName = temp.substring (0, temp.find ("]"));
						temp.remove ("]");


						//unsigned int tex = gsresourcemgr::get ()->load (texName.str ());
						//gi->m_Textures.add (tex);

						list.erase (0);
						if (list.getSize () == 0)
							readFile (pFile, list);
						temp = list[0];

						temp.remove ("tu");
						int numTU = atoi (temp.str ());

						gi->m_vTexCoordinates.resize (numTU);

						for (int a = 0; a < numTU; a++)
						{
							list.erase (0);
							if (list.getSize () == 0)
								readFile (pFile, list);
							temp = list[0];

							temp.remove ("[");
							temp.remove ("]");

							float x = (float)atof (temp.str ());
							temp.remove (0, temp.find (' ') + 1);

							float y = (float)atof (temp.str ());

							gi->m_vTexCoordinates.add (gsgeom::gsvec2f (x, y));
						}
					}
				}
				else if (temp.find ("lights ") > -1)
				{
					temp.remove ("lights ");
					int numLights = atoi (temp.str ());

					//removing line 'lights '
					list.erase (0);
					temp = list[0];

					for (int x = 0; x < numLights; x++)
					{
						gsgeom::gslight *l = new gsgeom::gslight;

						//[light]										|= n
						//{
						//	[pos]									|= [0 0 0]
						//	[type]									|= type
						//	[color]									|= [0 0 0]
						//	[direction]								|= [0 0 0]
						//}

						// remove '[light]'
						list.erase (0);
						temp = list[0];

						// remove '{'
						list.erase (0);
						temp = list[0];

						// position
						gsstring pos = temp;

						pos.remove ("[");
						pos.remove ("]");

						gsgeom::gsvec3f vpos;
						{
							float x = (float)atof (pos.str ());
							pos.remove (0, pos.find (' ')+1);

							float y = (float)atof (pos.str ());
							pos.remove (0, pos.find (' ')+1);

							float z = (float)atof (pos.str ());

							vpos.set (x, y, z);
						}

						list.erase (0);
						temp = list[0];

						l->setPos (vpos);

						// type
						gsstring type = temp;
						type.remove ("[");
						type.remove ("]");

						if (type == "spot")
							l->setType (gsgeom::gslight::LIGHT_SPOT);
						else if (type == "directional")
							l->setType (gsgeom::gslight::LIGHT_DIRECTIONAL);
						else if (type == "point")
							l->setType (gsgeom::gslight::LIGHT_POINT);
						else if (type == "area")
							l->setType (gsgeom::gslight::LIGHT_AREA);

						list.erase (0);
						temp = list[0];

						// color
						gsstring color = temp;

						color.remove ("[");
						color.remove ("]");
						
						gsgeom::gscolor c;
						{
							float r = (float)atof (color.str ());
							color.remove (0, color.find (' ')+1);

							float g = (float)atof (color.str ());
							color.remove (0, color.find (' ')+1);

							float b = (float)atof (color.str ());
							color.remove (0, color.find (' ')+1);

							float a = (float)atof (color.str ());

							c = gsgeom::gscolor (r, g, b, a);
						}

						list.erase (0);
						temp = list[0];

						l->setColor (c);

						// direction
						gsstring dir = temp;

						dir.remove ("[");
						dir.remove ("]");
						
						gsgeom::gsvec3f vdir;
						{
							float x = (float)atof (dir.str ());
							dir.remove (0, dir.find (' ')+1);

							float y = (float)atof (dir.str ());
							dir.remove (0, dir.find (' ')+1);

							float z = (float)atof (dir.str ());

							vdir.set (x, y, z);
						}

						list.erase (0);
						temp = list[0];

						// remove '}'
						list.erase (0);
						temp = list[0];

						//s->m_lLights.add (l);
					}
				}
				else if (temp.find ("effects ") > -1)
				{
					temp.remove ("effects ");
					int numEffects = atoi (temp.str ());

					list.erase (0);
					temp = list[0];

					//goal: 
					//gseffect is a virtual class:  we read the type and create the object pertaining to the specific effect
					//then the class is passed the rest of the list to evaluate any options it needs
					//
					//eg type = "multitexturing"
					// gseffect *e = new gsmultitexturing (list);

					for (int x = 0;  x < numEffects;)
					{
						temp.remove ("[");
						temp.remove ("]");

						//gseffect *e = NULL;
						if (temp == "multitexture")
						{
							x++;
						}
						else if (temp == "")
						{
						}
						else
						{
							list.erase (0);
							temp = list[0];
						}
					}
				}
				else if (temp.find ("[scene version=") > -1)
				{
					gsgeom::gsscene *child = new gsgeom::gsscene;
					readHelper (pFile, child, list);

					s->m_ChildNodes.add (child);
					temp = list[0];
				}
				else
				{
					//unidentifiable line, so lets just remove it and start over
					list.erase (0);
					temp = list[0];
				}
			}

			s->m_Geometry = gi;
		}

		void readFile (FILE *pFile, gsutil::gsqueue <gsutil::gsstring> &list, int readAhead)
		{
			for (int x = 0; x < readAhead; x++)
			{
				char temp[255];
				gsstring s;
				fgets (temp, 254, pFile);
				s = temp;
				list.add (s);
			}
		}

		void write (gsgeom::gsscene *s, const gsstring &pfile)
		{
			FILE *f = fopen (pfile.str (), "w+");

			if (!f)
				return;

			writeHelper (s, f);

			fclose (f);
		}

		void writeHelper (gsgeom::gsscene *s, FILE *pf, const int &numTabs)
		{
			//write the version
			gsstring temp = "";

			for (int x = 0; x < numTabs; x++)
				temp += "\t";
			temp += "[scene version=0.1]\n";
			for (int x = 0; x < numTabs; x++)
				temp += "\t";
			temp += "{\n";

			fwrite (temp.str (), temp.size (), 1, pf);

			//write camera information
			//if (s->m_CameraInfo)
			//{
			//	temp.clear ();

			//	//add tabs
			//	for (int x = 0; x < numTabs; x++)
			//		temp += "\t";
			//	temp += "\t[camera]\n\t{\n";

			//	fwrite (temp.str (), temp.size (), 1, pf);

			//	temp.clear ();
			//	//add tabs
			//	for (int x = 0; x < numTabs; x++)
			//		temp += "\t";
			//	temp += "\t\t";
			//	temp += s->m_CameraInfo->getWidth ();
			//	temp += "x";
			//	temp += s->m_CameraInfo->getHeight ();
			//	temp += " ";
			//	temp += s->m_CameraInfo->getFOV ();
			//	temp += " ";
			//	temp += s->m_CameraInfo->getNear ();
			//	temp += " ";
			//	temp += s->m_CameraInfo->getFar ();
			//	temp += "\n";
			//	//add tabs
			//	for (int x = 0; x < numTabs; x++)
			//		temp += "\t";
			//	temp += "\t\t[";
			//	temp += s->m_CameraInfo->getPos ()[0];
			//	temp += " ";
			//	temp += s->m_CameraInfo->getPos ()[1];
			//	temp += " ";
			//	temp += s->m_CameraInfo->getPos ()[2];
			//	temp += "] [";
			//	temp += s->m_CameraInfo->getDir ()[0];
			//	temp += " ";
			//	temp += s->m_CameraInfo->getDir ()[1];
			//	temp += " ";
			//	temp += s->m_CameraInfo->getDir ()[2];
			//	temp += "]\n\t}\n";

			//	fwrite (temp.str (), temp.size (), 1, pf);
			//}

			//write vectors
			temp.clear ();
			//add tabs
			for (int x = 0; x < numTabs; x++)
				temp += "\t";
			temp += "\tvertices ";
			temp += s->m_Geometry->m_vPoints.getSize ();
			temp += "\n";

			fwrite (temp.str (), temp.size (), 1, pf);

			for (unsigned int x = 0; x < s->m_Geometry->m_vPoints.getSize (); x++)
			{

				gsstring v;
				//add tabs
				for (int y = 0; y < numTabs; y++)
					v += "\t";
				v += "\t";
				v += s->m_Geometry->m_vPoints[x].getX ();
				v += " ";
				v += s->m_Geometry->m_vPoints[x].getY ();
				v += " ";
				v += s->m_Geometry->m_vPoints[x].getZ ();
				v += "\n";

				fwrite (v.str (), v.size (), 1, pf);
			}

			for (unsigned int b = 0; b < s->m_Geometry->m_vIndices.getSize (); b++)
			{
				//write indices
				temp.clear ();
				for (int x = 0; x < numTabs; x++)
					temp += "\t";
				temp += "\tindices ";
				temp += gsstring (s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ());
				temp += " type ";
				temp += s->m_Geometry->m_vIndices[b]->indexType;
				temp += "\n";

				fwrite (temp.str (), temp.size (), 1, pf);
				unsigned int pos = 0;

				//store in groups of ten
				while (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
				{
					gsstring v;

					for (int y = 0; y < numTabs; y++)
						v += "\t";
					v += "\t";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					v += " ";
					pos ++;
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += " ";
					if (pos < s->m_Geometry->m_vIndices[b]->m_vIndices.getSize ())
						v += s->m_Geometry->m_vIndices[b]->m_vIndices[pos];
					pos ++;
					v += "\n";

					fwrite (v.str (), v.size (), 1, pf);
				}
			}

			//write colors
			temp.clear ();
			//add tabs
			for (int x = 0; x < numTabs; x++)
				temp += "\t";
			temp += "\tcolors ";
			temp += s->m_Geometry->m_vColors.getSize ();
			temp += "\n";

			fwrite (temp.str (), temp.size (), 1, pf);

			for (unsigned int x = 0; x < s->m_Geometry->m_vColors.getSize (); x++)
			{
				gsstring v;
				for (int y = 0; y < numTabs; y++)
					v += "\t";
				v += "\t";
				v += s->m_Geometry->m_vColors[x].getR ();
				v += " ";
				v += s->m_Geometry->m_vColors[x].getG ();
				v += " ";
				v += s->m_Geometry->m_vColors[x].getB ();
				v += " ";
				v += s->m_Geometry->m_vColors[x].getA ();
				v += "\n";

				fwrite (v.str (), v.size (), 1, pf);
			}

			//write normals
			temp.clear ();
			//add tabs
			for (int x = 0; x < numTabs; x++)
				temp += "\t";
			temp += "\tnormals ";
			temp += s->m_Geometry->m_vNormals.getSize ();
			temp += "\n";

			fwrite (temp.str (), temp.size (), 1, pf);

			for (unsigned int x = 0; x < s->m_Geometry->m_vNormals.getSize (); x++)
			{
				gsstring v;
				for (int y = 0; y < numTabs; y++)
					v += "\t";
				v += "\t";
				v += s->m_Geometry->m_vNormals[x].getX ();
				v += " ";
				v += s->m_Geometry->m_vNormals[x].getY ();
				v += " ";
				v += s->m_Geometry->m_vNormals[x].getZ ();
				v += "\n";

				fwrite (v.str (), v.size (), 1, pf);
			}

			//write textures

			//write child scenes
			for (unsigned int c = 0; c < s->m_ChildNodes.getSize (); c++)
				writeHelper (s->m_ChildNodes[c], pf, numTabs+1);

			//add tabs
			temp.clear ();
			for (int x = 0; x < numTabs; x++)
				temp += "\t";
			temp += "}\n";

			fwrite (temp.str (), temp.size (), 1, pf);
		}
		*/
	};
};

/*
namespace gs
{
	gssceneloader::gssceneloader ()
	{
		m_pScene = NULL;
	}

	gssceneloader::~gssceneloader ()
	{
		while (m_qFileList.getSize () > 0)
		{
			delete m_qFileList[0];
			m_qFileList.erase (0);
		}

		if (m_pScene)
			delete m_pScene;
	}

	gsscene *gssceneloader::read (const char *pstr)
	{
		FILE *f = fopen (pstr, "r");

		if (f == NULL)
			return NULL;

		while (!feof (f))
		{
			char temp[80];
			fgets (temp, 80, f);
			int isize = (int)strlen (temp);
			char *ptr = new char[isize+1];
			for (int x = 0; x < isize; x++)
				ptr[x] = temp[x];
			ptr[isize] = '\0';
			m_qFileList.add (ptr);
		}

		fclose (f);

		m_pScene = new gsscene;

		readVersion ();

		while (m_qFileList.getSize () > 0)
		{
			delete m_qFileList[0];
			m_qFileList.erase (0);
		}

		return m_pScene;
	}

	void gssceneloader::write (const char *pstr, gsscene *s)
	{
		while (m_qFileList.getSize () > 0)
		{
			delete m_qFileList[0];
			m_qFileList.erase (0);
		}

		writeVersion (0, s);

		FILE *f = fopen (pstr, "w");

		while (m_qFileList.getSize () > 0)
		{
			char *temp = m_qFileList[0];
			fwrite (temp, strlen (temp), 1, f);

			delete m_qFileList[0];
			m_qFileList.erase (0);
		}

		fclose (f);
	}

	void gssceneloader::eatBrace ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		if (strncmp (temp, "{", 1) == 0)
		{
			delete temp;
			m_qFileList.erase (0);
		}
		else if (strncmp (temp, "}", 1) == 0)
		{
			delete temp;
			m_qFileList.erase (0);
		}
	}

	void gssceneloader::eatSpace ()
	{
		char *temp = m_qFileList[0];

		int size = 0;
		int len = (int)strlen (temp);

		while ((temp[size] == ' ') || 
			   (temp[size] == '\t'))
			size ++;

		char *str = new char [len - size + 1];

		int newsize = len - size;

		for (int x = 0; x < newsize; x++)
			str[x] = temp[size + x];
		str[newsize] = '\0';

		delete temp;
		m_qFileList[0] = str;
	}

	void gssceneloader::eat (const char character)
	{
		char *temp = m_qFileList[0];

		int len = (int)strlen (temp);
		int size = 0;
		bool cont = true;

		while (cont == true)
		{
			if (temp[size] == character)
				cont = false;
			
			size ++;
		}

		char *str = new char [len - size + 1];

		for (int x = 0; x < len - size; x++)
			str[x] = temp[size + x];
		str[len - size] = '\0';

		delete temp;
		m_qFileList[0] = str;
	}

	void gssceneloader::eatNonNumber ()
	{
		char *temp = m_qFileList[0];

		int size = 0;
		int len = (int)strlen (temp);

		while ((temp[size] != '0') && 
			   (temp[size] != '1') && 
			   (temp[size] != '2') && 
			   (temp[size] != '3') && 
			   (temp[size] != '4') && 
			   (temp[size] != '5') && 
			   (temp[size] != '6') && 
			   (temp[size] != '7') && 
			   (temp[size] != '8') && 
			   (temp[size] != '9'))
			size ++;

		char *str = new char [len - size + 1];

		int newsize = len - size;

		for (int x = 0; x < newsize; x++)
			str[x] = temp[size + x];
		str[newsize] = '\0';

		delete temp;
		m_qFileList[0] = str;
	}

	void gssceneloader::format ()
	{
		char *temp = m_qFileList[0];

		int size = 0;
		int len = (int)strlen (temp);

		while ((temp[size] != '\n'))
			size ++;

		char *str = new char [size + 1];

		for (int x = 0; x < size; x++)
			str[x] = temp[x];
		str[size] = '\0';

		delete temp;
		m_qFileList[0] = str;
	}

	void gssceneloader::readVersion ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		if (strncmp (temp, "version 1.0", sizeof (temp) + 1) != 0)
			return;

		delete m_qFileList[0];
		m_qFileList.erase (0);

		eatBrace ();
		readCamera ();
		readScene ();
		eatBrace ();
	}

	void gssceneloader::readCamera ()
	{
		eatSpace ();

		char *temp = m_qFileList[0];
		if (strncmp (temp, "[scene camera]", sizeof (temp) + 1) != 0)
			return;

		delete m_qFileList[0];
		m_qFileList.erase (0);

		eatBrace ();
		//read crap into this object
		eatSpace ();
		temp = m_qFileList[0];

		float w, h, fov, n, f;
		gsvec3f *p, *d;

		w = readFloat ();
		eatNonNumber (); //eats the x
		h = readFloat ();
		fov = readFloat ();
		n = readFloat ();
		f = readFloat ();

		delete m_qFileList[0];
		m_qFileList.erase (0);

		p = readVec3f ();
		d = readVec3f ();

		delete m_qFileList[0];
		m_qFileList.erase (0);

		gscamerainfo *c = new gscamerainfo (*p, *d, w, h, fov, n, f);
		m_pScene->m_CameraInfo = c;

		eatBrace ();
	}

	void gssceneloader::readScene ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];
		if (strncmp (temp, "[scene]", sizeof (temp) + 1) != 0)
			return;

		delete m_qFileList[0];
		m_qFileList.erase (0);

		eatBrace ();

		eatSpace ();
		temp = m_qFileList[0];
		if (strncmp (temp, "vertices", 8) == 0)
		{
			eat (' ');
			int numverts = readInt ();

			delete m_qFileList[0];
			m_qFileList.erase (0);

			while (numverts > 0)
			{
				m_pScene->m_vPoints.add (readVec3f ());

				delete m_qFileList[0];
				m_qFileList.erase (0);

				numverts --;
			}
		}

		eatSpace ();
		temp = m_qFileList[0];
		if (strncmp (temp, "colors", 6) == 0)
		{
			eat (' ');
			int numcolors = readInt ();

			delete m_qFileList[0];
			m_qFileList.erase (0);

			while (numcolors > 0)
			{
				//TODO: add a 'readColor' function
				//m_pScene->m_vColors.add (readVector ());

				delete m_qFileList[0];
				m_qFileList.erase (0);

				numcolors --;
			}
		}

		eatSpace ();
		temp = m_qFileList[0];
		if (strncmp (temp, "normals", 7) == 0)
		{
			eat (' ');
			int numnormals = readInt ();

			delete m_qFileList[0];
			m_qFileList.erase (0);

			while (numnormals > 0)
			{
				m_pScene->m_vNormals.add (readVec3f ());

				delete m_qFileList[0];
				m_qFileList.erase (0);

				numnormals --;
			}
		}

		eatSpace ();
		temp = m_qFileList[0];
		if (strncmp (temp, "textures", 8) == 0)
		{
			eat (' ');
			int numtextures = readInt ();

			delete m_qFileList[0];
			m_qFileList.erase (0);

			while (numtextures > 0)
			{
				eatBrace ();
				eatSpace ();
				format ();

				m_pScene->m_Textures.add (gsresourcemgr::get ()->load (m_qFileList[0]));
				delete m_qFileList[0];
				m_qFileList.erase (0);

				int numuvs = readInt ();

				delete m_qFileList[0];
				m_qFileList.erase (0);

				while (numuvs > 0)
				{
					m_pScene->m_vTexCoordinates.add (readVec2f ());

					delete m_qFileList[0];
					m_qFileList.erase (0);

					numuvs --;
				}
				eatBrace ();
				numtextures --;
			}
		}

		eatSpace ();
		temp = m_qFileList[0];
		if (strncmp (temp, "lights", 6) == 0)
		{
			eat (' ');
			int numlights = readInt ();

			delete m_qFileList[0];
			m_qFileList.erase (0);

			while (numlights > 0)
			{
				m_pScene->m_vPoints.add (readVec3f ());

				delete m_qFileList[0];
				m_qFileList.erase (0);
			}
		}

		eatBrace ();
	}

	int gssceneloader::readInt ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		int size = 0;
		int len = (int)strlen (temp);
		int iVal;

		while ((temp[size] == '0') || 
			   (temp[size] == '1') ||
			   (temp[size] == '2') || 
			   (temp[size] == '3') || 
			   (temp[size] == '4') || 
			   (temp[size] == '5') || 
			   (temp[size] == '6') || 
			   (temp[size] == '7') || 
			   (temp[size] == '8') || 
			   (temp[size] == '9'))
			size ++;

		char *str = new char [len - size + 1];
		char *val = new char [size + 1];

		int newsize = len - size;

		for (int x = 0; x < len; x++)
		{
			if (x < size)
				val[x] = temp[x];
			else
                str[x - size] = temp[x];
		}

		val[size] = '\0';
		str[newsize] = '\0';

		iVal = atoi (val);

		delete val;
		delete temp;
		m_qFileList[0] = str;

		return iVal;
	}

	const char *gssceneloader::readChar ()
	{
		char *temp = m_qFileList[0];
		return NULL;
	}

	float gssceneloader::readFloat ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		int size = 0;
		int len = (int)strlen (temp);
		float fVal;

		while ((temp[size] == '0') || 
			   (temp[size] == '1') ||
			   (temp[size] == '2') || 
			   (temp[size] == '3') || 
			   (temp[size] == '4') || 
			   (temp[size] == '5') || 
			   (temp[size] == '6') || 
			   (temp[size] == '7') || 
			   (temp[size] == '8') || 
			   (temp[size] == '9') ||
			   (temp[size] == '.'))
			size ++;

		char *str = new char [len - size];
		char *val = new char [size];

		int newsize = len - size;

		for (int x = 0; x < len; x++)
		{
			if (x < size)
				val[x] = temp[x];
			else
                str[x - size] = temp[x];
		}

		fVal = (float)atof (val);

		delete val;
		delete temp;
		m_qFileList[0] = str;

		return fVal;
	}

	gsvec2f *gssceneloader::readVec2f ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		//if (temp[0] == '[')
		//	return NULL;

		eat ('[');
		float x,y;
		x = readFloat ();
		y = readFloat ();
		eat (']');

		return new gsvec2f (x, y);
	}

	gsvec3f *gssceneloader::readVec3f ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		//if (temp[0] == '[')
		//	return NULL;

		eat ('[');
		float x,y,z;
		x = readFloat ();
		y = readFloat ();
		z = readFloat ();
		eat (']');

		return new gsvec3f (x, y, z);
	}

	gsvec4f *gssceneloader::readVec4f ()
	{
		eatSpace ();
		char *temp = m_qFileList[0];

		//if (temp[0] == '[')
		//	return NULL;

		eat ('[');
		float x,y,z,w;
		x = readFloat ();
		y = readFloat ();
		z = readFloat ();
		w = readFloat ();
		eat (']');

		return new gsvec4f (x, y, z, w);
	}

	void gssceneloader::writeVersion (const int depth, gsscene *s)
	{
		writeString (depth, "version 1.0\n");
		writeString (depth, "{\n");

		if (s->m_CameraInfo)
			writeCamera (depth + 1, s);
		writeScene (depth + 1, s);

		for (int x = 0; x < s->m_ChildNodes.getSize (); x++)
			writeVersion (depth + 1, s->m_ChildNodes[x]);

		writeString (depth, "}\n");
	}

	void gssceneloader::writeCamera (const int depth, gsscene *s)
	{
		writeString (depth, "[scene camera]\n");
		writeString (depth, "{\n");

		float width, height, fov, near, far;
		gsvec3f p, d;

		width = s->m_CameraInfo->getWidth ();
		height = s->m_CameraInfo->getHeight ();
		fov = s->m_CameraInfo->getFOV ();
		near = s->m_CameraInfo->getNear ();
		far = s->m_CameraInfo->getFar ();

		p = s->m_CameraInfo->getPos ();
		d = s->m_CameraInfo->getDir ();

		char *line1 = new char[80];
		strcpy (line1, "");
		sprintf (line1, "%fx%f %f %f %f\n", width, height, fov, near, far);
		writeString (depth + 1, line1);

		char *line2 = new char[80];
		strcpy (line2, "");
		sprintf (line2, "[%f %f %f] [%f %f %f]\n", p[0], p[1], p[2], d[0], d[1], d[2]);
		writeString (depth + 1, line2);

		writeString (depth, "}\n");
	}

	void gssceneloader::writeScene (const int depth, gsscene *s)
	{
		writeString (depth, "[scene]\n");
		writeString (depth, "{\n");

		int numverts = s->m_vPoints.getSize ();
		char *strverts = new char[80];
		strcpy (strverts, "");
		sprintf (strverts, "vertices %i\n", numverts);
		writeString (depth + 1, strverts);

		for (int a = 0; a < numverts; a++)
		{
			char *vert = new char[80];
			strcpy (vert, "");
			sprintf (vert, "[%f %f %f]\n", s->m_vPoints[a]->getX (),
				s->m_vPoints[a]->getY (),
				s->m_vPoints[a]->getZ ());
			writeString (depth + 1, vert);
		}

		int numcolors = s->m_vColors.getSize ();
		char *strcolors = new char[80];
		strcpy (strcolors, "");
		sprintf (strcolors, "colors %i\n", numcolors);
		writeString (depth + 1, strcolors);

		for (int b = 0; b < numcolors; b++)
		{
			char *vert = new char[80];
			strcpy (vert, "");
			sprintf (vert, "[%f %f %f]\n", s->m_vColors[b]->getR (),
				s->m_vColors[b]->getG (),
				s->m_vColors[b]->getB ());
			writeString (depth + 1, vert);
		}

		int numnormals = s->m_vNormals.getSize ();
		char *strnormals = new char[80];
		strcpy (strnormals, "");
		sprintf (strnormals, "normals %i\n", numnormals);
		writeString (depth + 1, strnormals);

		for (int c = 0; c < numnormals; c++)
		{
			char *vert = new char[80];
			strcpy (vert, "");
			sprintf (vert, "[%f %f %f]\n", s->m_vNormals[c]->getX (),
				s->m_vNormals[c]->getY (),
				s->m_vNormals[c]->getZ ());
			writeString (depth + 1, vert);
		}

		writeString (depth, "}\n");
	}

	void gssceneloader::writeString (const int depth, const char *str)
	{
		char *temp = new char[80];
		strcpy (temp, "");
		for (int x = 0; x < depth; x++)
			temp[x] = '\t';
		temp[depth] = '\0';
		strcat (temp, str);
		m_qFileList.add (temp);
	}
};
*/
