#include "gsgeom/gsocclusion.h"

namespace gsgeom
{
	gsocclusion::gsocclusion ()
	{
	}

	gsocclusion::~gsocclusion ()
	{
	}

	bool gsocclusion::occlude (gsgeom::gsscene *s, gsgeom::gscamera *c)
	{
		gsgeom::gsfrustum f;
		f.set (c->getProjection (), c->getView ());
		return f.occlude (s);
	}
};
