#include "TerrainEditor.h"

TerrainEditor::TerrainEditor (const int &w, const int &h) : gswin::gswindow (0, "Terraineditor", "Terrain Editor v0.1", 0, 0, 0, w, h)
{
	m_bLeftDown = false;
	m_bRightDown = false;

	m_pKernel = new gs::gskernel;
	m_pKernel->init (getHandle (), w, h);

	ToolsWindow = new TileTabControl (WS_EX_OVERLAPPEDWINDOW, "TileTabControl", "Tools Window", WS_OVERLAPPEDWINDOW, 800, 0, 250, 600);
	ToolsWindow->show ();

	gswin::gsmenu *pFile = new gswin::gsmenu ("File");
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Open"));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Save"));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_VBAR));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Exit"));
	gswin::gsmenu *pAbout = new gswin::gsmenu ("About");
	pAbout->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "About"));
	pAbout->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Help"));

	gswin::gsmenu *mainMenu = new gswin::gsmenu;
	mainMenu->insertMenu (pFile);
	mainMenu->insertMenu (pAbout);

	setMenu (mainMenu);

	m_pTopLevel = new gsgeom::gsscene;
	{
		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (w, h, (float)w/(float)h, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (10, 10, 10), 
					gsgeom::gsvec3f (0, 0, 0), 
					gsgeom::gsvec3f (0, 1, 0));
		m_pTopLevel->m_Camera = c;

		gsgeom::gseffect *e = new gsgeom::gseffect;
		e->setBlend (true);
		e->setBlendFunc (gsgeom::gseffect::BLEND_ONE, gsgeom::gseffect::BLEND_ONE_MINUS_SRC_ALPHA);
		e->setDepthTest (true);
		e->setDepthValue (1.f);
		e->setDepthFunc (gsgeom::gseffect::DEPTH_LEQUAL);
		e->setCulling (true);
		e->setCullFace (gsgeom::gseffect::CULL_FRONT);
		m_pTopLevel->m_pEffect = e;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		m_pTopLevel->m_Geometry = gi;
	}

	m_pCurrentScene = TerrainConfig::get ()->m_pScene;
		m_pCurrentScene->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pTopLevel->m_ChildNodes.add (m_pCurrentScene);

	m_pPicking = new gsgeom::gsscene;
		m_pPicking->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pTopLevel->m_ChildNodes.add (m_pPicking);

	m_bSelected = false;

	m_pKernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pTopLevel));
}

TerrainEditor::~TerrainEditor ()
{
	delete m_pKernel;
}

void TerrainEditor::handle ()
{
	while (m_iRun == 1)
		gswin::gswindow::handle ();
}

void TerrainEditor::onClose ()
{
	m_iRun = 0;
	m_pKernel->addEvent (gs::gsevent (gs::GS_QUIT, NULL));
}

void TerrainEditor::onCommand (void *wParam, void *lParam)
{
#ifdef WIN32
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wp) == 0)
	{
		int icontrol = LOWORD (wp);

		switch (icontrol)
		{
		case 0:
			{
				//clear m_pCurrentScene
				while (m_pCurrentScene->m_ChildNodes.getSize () > 0)
				{
					gsgeom::gsscene *s = m_pCurrentScene->m_ChildNodes[0];
					delete s;
					m_pCurrentScene->m_ChildNodes.erase (0);
				}

				//get the filename for loaded file
				OPENFILENAME f;
				char buf[255] = "";
				memset (&f, 0, sizeof (f));
				f.lStructSize = sizeof (f);
				f.hwndOwner = getHandle ();
				f.lpstrFile = buf;
				f.lpstrFile[0] = '\0';
				f.nMaxFile = sizeof (buf);
				f.lpstrFilter = "Xml\0*.xml\0";
				f.nFilterIndex = 1;
				f.lpstrFileTitle = NULL;
				f.nMaxFileTitle = 0;
				f.lpstrInitialDir = NULL; //config will store this
				f.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;

				if (GetOpenFileName (&f) != 0)
				{
					gsutil::gsstring pStr = (char*)f.lpstrFile;

					gsutil::gsXMLParser *parser = new gsutil::gsXMLParser;
					parser->loadFile (pStr);

					gsutil::gsXMLDocument *doc = parser->getDocument ();
					gsutil::gsXMLElement *root = doc->getRoot ();

					if (root->getName () == "Config")
					{
						m_pCurrentScene->m_Geometry->m_mutex.lock ();

						for (unsigned int x = 0; x < root->getChildrenSize (); x++)
						{
							gsutil::gsXMLElement *c = root->getChild (x);
							if (c->getName () == "Quad")
							{
								gsgeom::gsscene *child = new gsgeom::gsscene;
								child->m_Geometry = new gsgeom::gsgeometryinfo;

								for (unsigned int y = 0; y < c->getChildrenSize (); y++)
								{
									gsutil::gsXMLElement *d = c->getChild (y);

									if (d->getName () == "v")
									{
										gsutil::gsstring strX = d->getAttribute ("x");
										gsutil::gsstring strY = d->getAttribute ("y");
										gsutil::gsstring strZ = d->getAttribute ("z");

										child->m_Geometry->m_vPoints.add (
											gsgeom::gsvec3f ((float)atof (strX.str ()), 
															 (float)atof (strY.str ()), 
															 (float)atof (strZ.str ())));
									}

									if (d->getName () == "heightmap")
									{
										gsimage::gsbmp *b = new gsimage::gsbmp;
										b->load (d->getValue ());

										child->m_Geometry->m_Textures.add (b);

										child->m_Geometry->m_iTextureCount = 1;
										child->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
										child->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
										child->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 1));
										child->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));
									}
								}

								gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
								child->m_Geometry->m_vIndices.add (i);

								i->indexType = gsgeom::gsgeometryinfo::GS_SQUARE;
								i->m_vIndices.add (0);
								i->m_vIndices.add (1);
								i->m_vIndices.add (2);
								i->m_vIndices.add (3);

								m_pCurrentScene->m_ChildNodes.add (child);
							}
						}

						m_pCurrentScene->m_Geometry->m_mutex.lock ();
					}
				}
			}
			break;

		case 1: //save xml files along with heightmaps
			{
				OPENFILENAME f;
				char buf[255] = "";
				memset (&f, 0, sizeof (f));
				f.lStructSize = sizeof (f);
				f.hwndOwner = getHandle ();
				f.lpstrFile = buf;
				f.lpstrFile[0] = '\0';
				f.nMaxFile = sizeof (buf);
				f.lpstrFilter = "Xml\0*.xml\0";
				f.nFilterIndex = 1;
				f.lpstrFileTitle = NULL;
				f.nMaxFileTitle = 0;
				f.lpstrInitialDir = NULL; //config will store this
				f.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;

				if (GetSaveFileName (&f) != 0)
				{
					gsutil::gsstring pStr = (char*)f.lpstrFile;

					gsutil::gsXMLParser *parser = new gsutil::gsXMLParser;
					gsutil::gsXMLDocument *doc = parser->getDocument ();
					gsutil::gsXMLElement *prop = new gsutil::gsXMLElement;
					prop->setName ("?xml");
					gsutil::gsXMLElement *attrib1 = new gsutil::gsXMLElement;
					attrib1->setName ("version");
					attrib1->setValue ("1.0");
					prop->addAttribute (attrib1);
					gsutil::gsXMLElement *attrib2 = new gsutil::gsXMLElement;
					attrib2->setName ("encoding");
					attrib2->setValue ("ISO-8859-1");
					prop->addAttribute (attrib2);
					doc->addProperty (prop);
					gsutil::gsXMLElement *root = doc->getRoot ();
					root->setName ("Config");

					for (unsigned int x = 0; x < m_pCurrentScene->m_ChildNodes.getSize (); x++)
					{
						gsgeom::gsscene *s = m_pCurrentScene->m_ChildNodes[x];

						gsutil::gsXMLElement *c = new gsutil::gsXMLElement;
						c->setName ("Quad");
						for (unsigned int y = 0; y < s->m_Geometry->m_vPoints.getSize (); y++)
						{
							gsutil::gsXMLElement *p = new gsutil::gsXMLElement;
							p->setName ("v");
							gsutil::gsXMLElement *v1 = new gsutil::gsXMLElement;
							v1->setName ("x");
							v1->setValue (s->m_Geometry->m_vPoints[y].getX ());
							p->addAttribute (v1);
							gsutil::gsXMLElement *v2 = new gsutil::gsXMLElement;
							v2->setName ("x");
							v2->setValue (s->m_Geometry->m_vPoints[y].getY ());
							p->addAttribute (v2);
							gsutil::gsXMLElement *v3 = new gsutil::gsXMLElement;
							v3->setName ("x");
							v3->setValue (s->m_Geometry->m_vPoints[y].getZ ());
							p->addAttribute (v3);
							c->addChild (p);
						}

						for (unsigned int z = 0; z < s->m_Geometry->m_Textures.getSize (); z++)
						{
							gsutil::gsXMLElement *t = new gsutil::gsXMLElement;
							t->setName ("heightmap");
							t->setValue (s->m_Geometry->m_Textures[z]->getName ());
							c->addChild (t);
						}

						root->addChild (c);
					}
					
					parser->saveFile (pStr);
				}
			}
			break;

		case 3: //exit
			m_iRun = 0;
			break;

		case 5: //about
			break;
		}
	}
#endif
}

void TerrainEditor::onKeyDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	switch (wp)
	{
	case 'A':
	case VK_LEFT:
		{
			m_pKernel->m_pRenderMutex->lock ();
			gsgeom::gsscene *s = TerrainConfig::get ()->m_pScene;
			s->m_Camera->moveLeft (-0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;

	case 'D':
	case VK_RIGHT:
		{
			m_pKernel->m_pRenderMutex->lock ();
			gsgeom::gsscene *s = TerrainConfig::get ()->m_pScene;
			s->m_Camera->moveLeft (0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;

	case 'W':
	case VK_UP:
		{
			m_pKernel->m_pRenderMutex->lock ();
			gsgeom::gsscene *s = TerrainConfig::get ()->m_pScene;
			s->m_Camera->moveUp (-0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;

	case 'S':
	case VK_DOWN:
		{
			m_pKernel->m_pRenderMutex->lock ();
			gsgeom::gsscene *s = TerrainConfig::get ()->m_pScene;
			s->m_Camera->moveUp (-0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;
	}
}

void TerrainEditor::onDestroy ()
{
	m_iRun = 0;
	m_pKernel->addEvent (gs::gsevent (gs::GS_QUIT, NULL));
}

void TerrainEditor::onMouseMove (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);


	if (m_bRightDown)
	{
		float difx = (float)(x - oldx)*0.005f;
		float dify = (float)(y - oldy)*0.005f;

		m_pKernel->m_pRenderMutex->lock ();
		gsgeom::gscamera *c = m_pTopLevel->m_Camera;

		//x direction
		c->pitch (dify);

		//y direction
		c->yaw (difx);

		m_pKernel->m_pRenderMutex->unlock ();
	}

	oldx = x;
	oldy = y;
}

void TerrainEditor::onMouseWheel (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	m_pKernel->m_pRenderMutex->lock ();

	gsgeom::gscamera *c = m_pTopLevel->m_Camera;
	short w = HIWORD (wp);

	float dx = -w/120.f;

	c->moveForward (dx*1.5f);

	m_pKernel->m_pRenderMutex->unlock ();
}

void TerrainEditor::onMouseLeftDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);

	float fx = (float)x;
	float fy = (float)(getHeight () - y) - 48.f;
	gsgeom::gsray r = m_pTopLevel->m_Camera->getPicked (fx, fy);


	if (m_bSelected)
	{
		if (gscol::gscollision::isRayIntersect (r, m_pCurrentScene))
		{
			gsgeom::gsscene *s = gscol::gscollision::RayIntersectScene (r, m_pCurrentScene);
			if (s)
			{
				if (TerrainConfig::get ()->m_pPicked == s)
				{
					m_pPicking->m_Geometry->m_vPoints.clear ();
					if (m_pPicking->m_Geometry->m_vIndices.getSize () != 0)
						m_pPicking->m_Geometry->m_vIndices[0]->m_vIndices.clear ();

					TerrainConfig::get ()->m_pPicked = NULL;
					m_bSelected = false;
				}
				else
				{
					TerrainConfig::get ()->m_pPicked = s;
					m_pPicking->m_Geometry->m_vPoints.clear ();
					for (unsigned int i = 0; i < m_pPicking->m_Geometry->m_vPoints.getSize (); i++)
						m_pPicking->m_Geometry->m_vPoints.add (s->m_Geometry->m_vPoints[i]);
					for (unsigned int i = 0; i < s->m_Geometry->m_vPoints.getSize (); i++)
						m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));

					//Pointer to an index type
					gsgeom::gsgeometryinfo::IndexType *it = NULL;

					//no index, so add one
					if (m_pPicking->m_Geometry->m_vIndices.getSize () == 0)
						m_pPicking->m_Geometry->m_vIndices.add (new gsgeom::gsgeometryinfo::IndexType);
					else
						m_pPicking->m_Geometry->m_vIndices[0]->m_vIndices.clear ();
					//set it with the current IndexType
					it = m_pPicking->m_Geometry->m_vIndices[0];
					it->indexType = gsgeom::gsgeometryinfo::GS_LINE;

					it->m_vIndices.add (0);
					for (unsigned int i = 1; i < s->m_Geometry->m_vPoints.getSize (); i++)
					{
						it->m_vIndices.add (i);
						it->m_vIndices.add (i);
					}
					it->m_vIndices.add (0);

					m_bSelected = true;
				}
			}
		}
	}
	else
	{
		if (gscol::gscollision::isRayIntersect (r, m_pCurrentScene))
		{
			gsgeom::gsscene *s = gscol::gscollision::RayIntersectScene (r, m_pCurrentScene);
			
			//clear previously picked
			m_pPicking->m_Geometry->m_vPoints.clear ();

			//add geometry for this new scene
			for (unsigned int i = 0; i < s->m_Geometry->m_vPoints.getSize (); i++)
				m_pPicking->m_Geometry->m_vPoints.add (s->m_Geometry->m_vPoints[i]);
			for (unsigned int i = 0; i < s->m_Geometry->m_vPoints.getSize (); i++)
				m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));

			//Pointer to an index type
			gsgeom::gsgeometryinfo::IndexType *it = NULL;

			//no index, so add one
			if (m_pPicking->m_Geometry->m_vIndices.getSize () == 0)
				m_pPicking->m_Geometry->m_vIndices.add (new gsgeom::gsgeometryinfo::IndexType);
			else
				m_pPicking->m_Geometry->m_vIndices[0]->m_vIndices.clear ();
			//set it with the current IndexType
			it = m_pPicking->m_Geometry->m_vIndices[0];
			it->indexType = gsgeom::gsgeometryinfo::GS_LINE;

			//set Indices
			it->m_vIndices.add (0);
			for (unsigned int i = 1; i < m_pPicking->m_Geometry->m_vPoints.getSize (); i++)
			{
				it->m_vIndices.add (i);
				it->m_vIndices.add (i);
			}
			it->m_vIndices.add (0);

			m_bSelected = true;
			TerrainConfig::get ()->m_pPicked = s;
		}
	}
}

void TerrainEditor::onMouseLeftUp (void *wParam, void *lParam)
{
}

void TerrainEditor::onMouseMiddleDown (void *wParam, void *lParam)
{
}

void TerrainEditor::onMouseMiddleUp (void *wParam, void *lParam)
{
}

void TerrainEditor::onMouseRightDown (void *wParam, void *lParam)
{
	m_bRightDown = true;
}

void TerrainEditor::onMouseRightUp (void *wParam, void *lParam)
{
	m_bRightDown = false;
}
