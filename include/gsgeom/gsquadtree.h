#ifndef _gsquadtree_h_
#define _gsquadtree_h_

#include <gsgeom/gsspatial.h>

namespace gsgeom
{
	class gsquadtree : public gsgeom::gsspatial
	{
	public:
		gsquadtree ();
		virtual ~gsquadtree ();

		void compute ();
	};
};

#endif
