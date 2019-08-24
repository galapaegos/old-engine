#ifndef _gsfrustum_h_
#define _gsfrustum_h_

#include <gsgeom/gsplane.h>
#include <gsgeom/gsmatrix.h>

namespace gsgeom
{
	class GS gsfrustum
	{
	public:
		gsfrustum ();
		~gsfrustum ();

		void set (const gsgeom::gsmatrix &proj, const gsgeom::gsmatrix &view);
		bool occlude (const gsgeom::gsvec3f vMin, const gsgeom::gsvec3f vMax);

	private:
		gsplane l, r, t, b, n, f;
	};
}

#endif

