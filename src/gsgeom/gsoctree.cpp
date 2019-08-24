#include "gsgeom/gsoctree.h"

namespace gsgeom
{
	gsoctree::gsoctree (const unsigned int &bucket, const unsigned int &maxLevel) : m_pParent (NULL), m_iBucket (bucket), m_iMaxLevel (maxLevel),
		_11 (NULL), _12 (NULL), _13 (NULL), _14 (NULL), _21 (NULL), _22 (NULL), _23 (NULL), _24 (NULL)
	{
	}

	gsoctree::~gsoctree ()
	{
	}
};
