#ifndef _gslight_h_
#define _gslight_h_

#include "gsgeom/gsvec2.h"
#include "gsgeom/gsvec3.h"
#include "gsgeom/gsvec4.h"
#include "gsgeom/gscolor.h"

namespace gsgeom
{	
	class GS gslight
	{
	public:
		enum LIGHT_TYPE
		{
			LIGHT_SPOT,
			LIGHT_POINT,
			LIGHT_AREA,
			LIGHT_DIRECTIONAL
		};

		gslight ();
		gslight (const gsvec3f &pos, const gscolor &dif, const LIGHT_TYPE t);
		~gslight ();
		
		void setPos (const gsvec3f &pos) { m_vPos = pos; }
		void setDir (const gsvec3f &dir) { m_vDir = dir; }
		void setAmbient (const gsgeom::gscolor &amb) { m_cAmbient = amb; }
		void setDiffuse (const gsgeom::gscolor &dif) { m_cDiffuse = dif; }
		void setSpecular (const gsgeom::gscolor &spec) { m_cSpecular = spec; }
		void setType (LIGHT_TYPE t) { m_lType = t; }
		
		gsgeom::gsvec3f	getPos () { return m_vPos; }
		gsgeom::gsvec3f getDir () { return m_vDir; }
		gsgeom::gscolor getAmbient () { return m_cAmbient; }
		gsgeom::gscolor	getDiffuse () { return m_cDiffuse; }
		gsgeom::gscolor getSpecular () { return m_cSpecular; }
		LIGHT_TYPE getType () { return m_lType; }
		
	private:
		gsgeom::gsvec3f	m_vPos, m_vDir;
		gsgeom::gscolor m_cAmbient, m_cDiffuse, m_cSpecular;
		
		LIGHT_TYPE	m_lType;
	};
};

#endif

