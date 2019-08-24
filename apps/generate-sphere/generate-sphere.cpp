#include "generate-sphere.h"

int main (int argc, char *argv[])
{
	if (argc != 5)
	{
		printf ("not enough paramters!\nUsage: generate-sphere.exe radius points levels landmass.scene\n");
		return -1;
	}

	float radius = atof (argv[1]);
	int count = atoi (argv[2]);
	int levels = atoi (argv[3]);
	gsutil::gsstring file = argv[4];

	gsgeom::gsscene *s = new gsgeom::gsscene;
	gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
	//end points
	//gi->m_vPoints.add (gsgeom::gsvec3f (0, -radius, 0));
	//gi->m_vPoints.add (gsgeom::gsvec3f (0, radius, 0));
	for (int x = 0; x < count; x++)
	{
		for (int y = 0; y < levels; y++)
		{
			float theta = x*M_PI/count;
			float phi = y*2*M_PI/levels;
			float sinTheta = sinf (theta);
			float sinPhi = sinf (phi);
			float cosTheta = cosf (theta);
			float cosPhi = cosf (phi);
			gi->m_vPoints.add (gsgeom::gsvec3f (radius*cosPhi*sinTheta, radius*sinPhi*sinTheta, radius*cosTheta));
		}
	}
	//for (int x = 0; x < 1; x++)
	//{
	//	for (int y = 0; y <= levels; y++)
	//	{
	//		gi->m_vIndices.add (0);
	//		gi->m_vIndices.add ((x + 1)*count + y + 2);
	//		gi->m_vIndices.add ((x + 1)*count + y + 3);
	//	}
	//}
	gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
	it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
	for (int x = 0; x < count; x++)
	{
		for (int y = 0; y < levels; y++)
		{
			it->m_vIndices.add (x*count + y);
			it->m_vIndices.add ((x + 1)*count + y);
			it->m_vIndices.add ((x + 1)*count + y + 1);

			it->m_vIndices.add ((x + 1)*count + y + 1);
			it->m_vIndices.add (x*count + y + 1);
			it->m_vIndices.add (x*count + y);
		}
	}
	gi->m_vIndices.add (it);
	//for (int x = count; x <= count; x++)
	//{
	//	for (int y = 0; y <= levels; y++)
	//	{
	//		gi->m_vIndices.add (x*count + y + 2);
	//		gi->m_vIndices.add ((x + 1)*count + y + 2);
	//		gi->m_vIndices.add ((x + 1)*count + y + 3);

	//		gi->m_vIndices.add ((x + 1)*count + y + 3);
	//		gi->m_vIndices.add (x*count + y + 3);
	//		gi->m_vIndices.add (x*count + y + 2);
	//	}
	//}

	for (int x = 0; x < gi->m_vPoints.getSize (); x++)
	{
		gsgeom::gsvec3f norm = gsgeom::gsvec3f (0, 0, 0) - gi->m_vPoints[x];
		norm.normalize ();

		gi->m_vNormals.add (norm);
		gi->m_vColors.add (gsgeom::gscolor (norm[0], norm[1], norm[2], 1));
	}
	s->m_Geometry = gi;

	gs::gssceneloader::write (s, file);

	return 0;
}
