#include "test.h"

int main (int argc, char *argv[])
{
	float step = 1.f;
	gsstring strBitmap;

	if (argc < 2)
	{
		printf ("Usage: large-land-generator.exe heightmap.bmp [-s]\n-s: Step size");
		return -1;
	}
	else
	{
		printf ("---- Processing passed arguments ----\n");

		strBitmap = gsstring (argv[1]);

		gsutil::gsqueue <gsstring> args;
		for (int x = 2; x < argc; x++) 
			args.add (gsstring (argv[x]));

		//process args here:
		for (int y = 0; y < args.getSize (); y+=2)
		{
			if (args[y] == "-s")
				step = (float)atof (args[y+1].str ());
		}
	}

	gsutil::gstimer time;
	float currentTime = time.getTime ();

	gsresourcemgr *r = new gsresourcemgr;
	gsresourcemgr::set (r);

	printf ("Step 1: Loading heightmap\n");

	gsimage::gstexture *heightMap = new gsimage::gsbmp;
	heightMap->load (strBitmap);

	int gw = heightMap->getWidth ();
	int gh = heightMap->getHeight ();
	int totalVerts = gw*gh;

	printf ("heightmap:\nwidth:%i height:%i\n", gw, gh);
	printf ("number of points: %i\n", totalVerts);

	return 0;
}

