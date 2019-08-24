#ifndef _gsline_h_
#define _gsline_h_

#include "gsgeom/gsvector.h"
#include "gsgeom/gsray.h"

namespace gsgeom
{
	class GS gsline
	{
	public:
		gsline () {}
		~gsline () {}

		gsvec3f getP1 () { return m_P1; }
		gsvec3f getP2 () { return m_P2; }

		/*gsray operator= (const gsline &l)
		{
			gsray r;
			r = gsray (l.getP1 (), l.getP2 ());
			return r;
		}*/
	private:

		gsvec3f	m_P1;
		gsvec3f	m_P2;
	};
};

#endif

