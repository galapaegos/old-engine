#ifndef _gsspline_h_
#define _gsspline_h_

#include "gsgeom/gsvector.h"
#include "gsgeom/gsray.h"
#include "gsgeom/gsmatrix.h"
#include "gsutil/gsqueue.h"

namespace gsgeom
{
	class gsspline
	{
	public:
		enum GSSPLINE_TYPE
		{
			GSSPLINE_QUADRIC,
			GSSPLINE_CUBIC,
			GSSPLINE_QUARTIC,
			GSSPLINE_QUINTIC,
			GSSPLINE_SEXTIC,
			GSSPLINE_SEPTIC,
			GSSPLINE_OCTIC,
			GSSPLINE_NONTIC,
			GSSPLINE_DECATIC,
		};

		gsspline ();
		~gsspline ();

		void generate (const int nPoints, gsvec3f v1, gsvec3f v2);
		void generate (const int nPoints, gsvec3f v1, gsvec3f v2, gsvec3f v3);
		void generate (const int nPoints, gsvec3f v1, gsvec3f v2, 
			gsvec3f v3, gsvec3f v4);

		inline GSSPLINE_TYPE getType () { return m_sType; }

	private:
		GSSPLINE_TYPE m_sType;
		gsutil::gsqueue<gsvec3f> m_vPoints;
	};
};

#endif

