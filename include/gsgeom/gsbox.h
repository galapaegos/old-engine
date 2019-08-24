#ifndef _gsgeombox_h_
#define _gsgeombox_h_

#include <gsgeom/gsvector.h>
#include <gsgeom/gsplane.h>

namespace gsgeom
{
	class GS gsbox
	{
	public:
		gsbox ();
		gsbox (const gsgeom::gsvec3f &vMin, const gsgeom::gsvec3f &vMax);
		~gsbox ();

		inline gsgeom::gsvec3f getMin () { return m_vMin; }
		inline gsgeom::gsvec3f getMax () { return m_vMax; }

	private:
		gsgeom::gsvec3f m_vMin;
		gsgeom::gsvec3f m_vMax;
	};
};

#endif

