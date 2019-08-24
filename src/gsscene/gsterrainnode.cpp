#include <gsscene/gsterrainnode.h>

namespace gsscene
{
	gsterrainnode::gsterrainnode ()
	{
	}

	gsterrainnode::gsterrainnode (const unsigned int &width, const unsigned int &height)
	{
		gsutil::gsarray <gsgeom::gsvec3f> *verts = new gsutil::gsarray <gsgeom::gsvec3f>;
		gsutil::gsarray <gsgeom::gscolor> *colors = new gsutil::gsarray <gsgeom::gscolor>;

		for (unsigned int w = 0; w < width; w++)
		{
			for (unsigned int h = 0; h < height; h++)
			{
				verts->add (gsgeom::gsvec3f ((float)w, 0.f, (float)h));
				colors->add (gsgeom::gscolor (1.f, 1.f, 1.f));
			}
		}

		gsutil::gsarray <unsigned short> *ind = new gsutil::gsarray <unsigned short>;

		for (unsigned int t = 0; t < width - 1; t++)
		{
			for (unsigned int u = 0; u < height - 1; u++)
			{
				ind->add (t*width + u);
				ind->add (t*width + height + u);
				ind->add (t*width + height + u + 1);

				ind->add (t*width + height + u + 1);
				ind->add (t*width + u + 1);
				ind->add (t*width + u);
			}
		}
	}

	gsterrainnode::~gsterrainnode ()
	{
	}
};
