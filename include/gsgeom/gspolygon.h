#ifndef _gspolygon_h_
#define _gspolygon_h_

#include <gsgeom/gsbbox.h>
#include <gsgeom/gsbox.h>
#include <gsgeom/gscolor.h>
#include <gsgeom/gsmatrix.h>
#include <gsgeom/gsvector.h>

#include <gsutil/gsarray.h>

namespace gsgeom
{
	class GS gspolygon
	{
	public:
		gspolygon ();
		~gspolygon ();

		void add (const gsgeom::gsvec3f &v);
		void add (const gsgeom::gsvec2i &e);

		void clear ();

		void get (gsutil::gsarray <gsgeom::gsvec3f> &points);
		void get (gsutil::gsarray <gsgeom::gsvec2i> &edges);
		void get (gsutil::gsarray <unsigned int> &indices);

		void process ();

	protected:
		gsutil::gsarray <gsgeom::gsvec3f> m_vPoints;
		gsutil::gsarray <gsgeom::gsvec2i> m_vEdges;
		gsutil::gsarray <unsigned int> m_vIndices;
	};
};

#endif
