#include "gsgeom/gslight.h"

namespace gsgeom
{
	gslight::gslight ()
	{
		m_vPos = gsvec3f (0.f, 10.f, 0.f);
		m_cAmbient = gscolor (0.2f, 0.2f, 0.2f, 1.f);
		m_cDiffuse = gscolor (0.5f, 0.5f, 0.5f, 1.f);
		m_cSpecular = gscolor (0.f, 0.f, 0.f, 1.f);
		m_lType = LIGHT_POINT;
	}
	
	gslight::gslight (const gsvec3f &pos, const gscolor &dif, const LIGHT_TYPE t)
	{
		m_vPos = pos;
		m_cDiffuse = dif;
		m_lType = t;
	}

	gslight::~gslight ()
	{
	}
};
