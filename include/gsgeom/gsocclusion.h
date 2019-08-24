#ifndef _gsocclusion_h_
#define _gsocclusion_h_

#include <gsgeom/gscamera.h>
#include <gsgeom/gsfrustum.h>

namespace gsgeom
{
	class GS gsocclusion
	{
	public:
		gsocclusion ();
		~gsocclusion ();

		bool occlude (gsgeom::gsscene *s, gsgeom::gscamera *c);
	};
};

#endif

