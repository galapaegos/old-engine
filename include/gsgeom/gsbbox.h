#ifndef _gsbbox_h_
#define _gsbbox_h_

#include <gsgeom/gsspatial.h>

namespace gsgeom
{
	class GS gsbbox : public gsspatial
	{
	public:
		gsbbox ();
		gsbbox (const gsvec3f &vMin, const gsvec3f &vMax);
		virtual ~gsbbox ();

		void compute ();

		void set (const gsvec3f &vMin, const gsvec3f &vMax) { m_vMin = vMin; m_vMax = vMax; }
		inline gsvec3f getMin () { return m_vMin; }
		inline gsvec3f getMax () { return m_vMax; }

	private:
		gsvec3f m_vMin;
		gsvec3f m_vMax;
	};
};

#endif

