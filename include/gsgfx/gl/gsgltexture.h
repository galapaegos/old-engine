#ifndef _gsgltexture_h_
#define _gsgltexture_h_

#include <gsgeom/gstextureinfo.h>

#include <gsgfx/gl/gsext.h>

#include <gsimage/gstexture.h>

#include <gsutil/gsassert.h>
#include <gsutil/gsqueue.h>

namespace gsgfx
{
	class gsgltexture
	{
	public:
		gsgltexture ();
		~gsgltexture ();

		void load ();

		void bind ();
		void unbind ();

		void process ();

		gsimage::gstexture *m_pTexture;
		unsigned int m_iId;

		gsgeom::gstextureinfo *m_pTexInfo;
	};
};

#endif
