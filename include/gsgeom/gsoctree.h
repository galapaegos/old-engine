#ifndef _gsoctree_h_
#define _gsoctree_h_

#include <gsgeom/gsbbox.h>
#include <gsgeom/gsspatial.h>

namespace gsgeom
{
	class GS gsoctree : public gsgeom::gsspatial
	{
	public:
		//bucket is the number of points 'total'.  
		//so if there are 2001 vertices in a region, it will subdivide and place those points within.
		gsoctree (const unsigned int &bucket=2000, const unsigned int &maxLevel=20);
		virtual ~gsoctree ();

	private:
		void computeHelper (gsgeom::gsbbox &b, const unsigned int &depth);
		void reduce ();

		gsoctree *m_pParent;
		gsoctree *_11, *_12, *_13, *_14, *_21, *_22, *_23, *_24;

		unsigned int m_iBucket, m_iMaxLevel;
	};
};

#endif
