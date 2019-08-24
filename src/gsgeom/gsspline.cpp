#include "gsgeom/gsspline.h"

namespace gsgeom
{
	gsspline::gsspline ()
	{
	}

	gsspline::~gsspline ()
	{
	}

	void gsspline::generate (const int nPoints, gsvec3f v1, gsvec3f v2)
	{
		m_sType = GSSPLINE_QUADRIC;

		float a = 1.0f;
		float b = 1.0f - a;

		float distance = v1.distance (v2);
		//float offset = distance/(float)nPoints;

		for (int x = 0; x < nPoints; x++)
		{
			gsvec3f v = gsvec3f (v1[0]*a + v2[0]*b,
								   v1[1]*a + v2[1]*b,
								   v1[2]*a + v2[2]*b);

			m_vPoints.add (v);

			a = a - 1.0f/distance;
			b = 1.0f - a;
		}
	}

	void gsspline::generate (const int nPoints, gsvec3f v1, gsvec3f v2, gsvec3f v3)
	{
		m_sType = GSSPLINE_CUBIC;

		//float a = 1.0f;
		//float b = 1.0f - a;

		for (int x = 0; x < nPoints; x++)
		{

		}
	}

	void gsspline::generate (const int nPoints, gsvec3f v1, gsvec3f v2, 
		gsvec3f v3, gsvec3f v4)
	{
		m_sType = GSSPLINE_QUARTIC;
	}
};

