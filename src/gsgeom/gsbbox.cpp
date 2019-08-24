#include "gsgeom/gsbbox.h"

namespace gsgeom
{
	gsbbox::gsbbox ()
	{
	}

	gsbbox::gsbbox (const gsgeom::gsvec3f &vMin, const gsgeom::gsvec3f &vMax)
	{
		m_vMin = vMin;
		m_vMax = vMax;
	}

	gsbbox::~gsbbox ()
	{
	}

	void gsbbox::compute ()
	{
	}
};

