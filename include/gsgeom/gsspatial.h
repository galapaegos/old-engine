#ifndef _gsspatial_h_
#define _gsspatial_h_

#include <gsgeom/gsmatrix.h>
#include <gsgeom/gsvector.h>

#include <gsutil/gsqueue.h>

namespace gsgeom
{
	class GS gsspatial
	{
	public:
		gsspatial () {}
		virtual ~gsspatial () {}

	protected:
		gsspatial *m_pParent;
		gsutil::gsqueue <gsspatial*> m_vChildren;
	};
};

#endif
