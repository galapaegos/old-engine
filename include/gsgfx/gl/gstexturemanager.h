#ifndef _gstexturemanager_h_
#define _gstexturemanager_h_

#include <gsgfx/gl/gsext.h>
#include <gsgfx/gl/gsgltexture.h>

using namespace gsext;
using namespace gsgeom;

namespace gsgfx
{
	class GS gstexturemanager
	{
	public:
		gstexturemanager ();
		~gstexturemanager ();

		void setTexture (gsimage::gstexture *t, gsgeom::gstextureinfo *texInfo);

		void enableTexture (const unsigned int &stage, gsimage::gstexture *t);
		void disableTexture (const unsigned int &stage, gsimage::gstexture *t);

		void parseTextureEnvironment (gsgeom::gstextureinfo *texInfo);

		void clear ();

	private:
		gsgfx::gsgltexture *findTexture (gsimage::gstexture *t);

		gsutil::gsqueue <gsgltexture*> m_TexList;
	};
};

#endif
