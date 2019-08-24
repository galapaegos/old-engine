#ifndef _gsshaderprogram_h_
#define _gsshaderprogram_h_

#include <gsgeom/gsshader.h>
#include <gsgeom/gsshadervariable.h>

#include <gsgfx/gl/gsext.h>

#include <gsimage/gstexture.h>

using namespace gsext;

namespace gsgfx
{
	class gsshaderprogram
	{
	public:
		gsshaderprogram ();
		virtual ~gsshaderprogram ();

		virtual void load (gsgeom::gsshader *pProgram);
		virtual void unload ();

		virtual void enable ();
		virtual void disable ();

		void passVariable (gsgeom::gsshadervariable *v);

		bool isEnabled () { return m_bEnabled; }

	private:
		gsgeom::gsshader *m_pShader;

		GLhandleARB context;
		GLhandleARB vertexShader;
		GLhandleARB pixelShader;

		bool m_bEnabled;
	};
};

#endif
