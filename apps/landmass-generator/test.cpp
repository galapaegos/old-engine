#include "test.h"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf ("not enough paramters!\nUsage: landmass-generator.exe directory/\n");
		return -1;
	}

	gsutil::gsstring dir = argv[1];

	if (gsutil::gssystem::getDirectorySize (dir, "bmp") <= 0)
	{
		printf ("Directory has no files to process!\n");
		return -1;
	}

	gsutil::gsarray <gsutil::gsstring> list;
	gsutil::gssystem::getDirectoryList (dir, "bmp", list);

	gsresourcemgr *r = new gsresourcemgr;
	gsresourcemgr::set (r);

	for (unsigned int j = 0; j < list.getSize (); j++)
	{
		gsutil::gstimer time;
		float currentTime = time.getTime ();

		printf ("Step 1: Loading heightmap %s\n", list[j].str ());

		gsutil::gsstring inFile = dir + list[j];
		gsutil::gsstring outFile = dir + list[j].substring (0, list[j].find ('.')) + ".scene";
		gsutil::gsstring xmlConf = dir + list[j].substring (0, list[j].find ('.')) + ".xml";

		gsimage::gstexture *heightMap = new gsimage::gsbmp;
		heightMap->load (inFile);

		int gw = heightMap->getWidth ();
		int gh = heightMap->getHeight ();
		int totalVerts = gw*gh;

		gsutil::gsXMLParser xmlParser;
		xmlParser.loadFile (xmlConf);

		float destX = 0.f, destY = 0.f, destWidth = 1.f, destHeight = 1.f, destMultY = 1.f;

		destX = (float)atof (xmlParser.find ("/Config/Y").str ());
		destY = (float)atof (xmlParser.find ("/Config/X").str ());
		destWidth = (float)atof (xmlParser.find ("/Config/Width").str ());
		destHeight = (float)atof (xmlParser.find ("/Config/Height").str ());
		destMultY = (float)atof (xmlParser.find ("/Config/destY").str ());

		printf ("heightmap:\nwidth:%i height:%i\n", gw, gh);
		printf ("number of points: %i\n", totalVerts);

		float newTime = time.getTime ();
		float step1Delta = newTime - currentTime;
		printf ("Step 1: Completed in %fs\n", step1Delta/1000.f);

		currentTime = newTime;

		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;

		printf ("Step 2: Generate all points\n");
		for (int x = 0; x < gw; x++)
		{
			for (int y = 0; y < gh; y++)
				gi->m_vPoints.add (gsgeom::gsvec3f (destX + destWidth*(float)x/(float)gw, 
													destY*(heightMap->getData ()[x*gw + gh]/255.f), 
													destY + destHeight*(float)y/(float)gh));
		}

		printf ("Step 3: Generate all normals\n");
		for (unsigned int x = 0; x < gi->m_vPoints.getSize (); x++)
		{
			gsgeom::gsvec3f n = gi->m_vPoints[x];
			n.normalize ();

			gi->m_vNormals.add (n);
		}

		newTime = time.getTime ();
		float step2Delta = newTime - currentTime;
		printf ("Step 4: Completed in %fs\n", step2Delta/1000.f);

		currentTime = newTime;

		printf ("Step 5: Generate vertex list with %i vertices\n", gi->m_vPoints.getSize ());
		gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
		it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		for (int x = 0; x < gw - 1; x++)
		{
			float old = time.getTime ();
			int y = 0;
			for (y = 0; y < gh - 1; y++)
			{
				it->m_vIndices.add (gw*x + y);
				it->m_vIndices.add (gw*x + y + 1);
				it->m_vIndices.add (gw*(x + 1) + y + 1);
				
				it->m_vIndices.add (gw*(x + 1) + y + 1);
				it->m_vIndices.add (gw*(x + 1) + y);
				it->m_vIndices.add (gw*x + y);
			}
			float cur = time.getTime ();

			printf ("Completed row %i in %fs, %f%% completed\n", x, (cur - old)/1000.f, (float)((x*gw + y)/(float)totalVerts)*100.f);
		}

		gi->m_vIndices.add (it);

		s->m_Geometry = gi;

		newTime = time.getTime ();
		float step3Delta = newTime - currentTime;
		printf ("Step 6: Completed in %fs\n", step3Delta/1000.f);

		currentTime = newTime;

		printf ("Step 7: write scene to file\n");
		gssceneloader::write (s, outFile);

		newTime = time.getTime ();
		float step4Delta = newTime - currentTime;
		printf ("Step 8: Completed in %fs\n", step4Delta/1000.f);

		printf ("Step 9: Clean up memory\n");
		//cleanup gi

		newTime = time.getTime ();
		float step5Delta = newTime - currentTime;
		printf ("Step 10: Completed in %fs\n", step5Delta/1000.f);

		printf ("Completed land generation in %f\n", (step1Delta + step2Delta + step3Delta + step4Delta + step5Delta)/1000.f);

		delete s;
	}

	list.clear ();

	delete r;

	return 0;
}
