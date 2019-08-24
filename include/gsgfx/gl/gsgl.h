#ifndef _gsgl_h_
#define _gsgl_h_

#ifdef WIN32
#include <windows.h>
#include <gl/glu.h>
#else
#include <X11/Xlib.h>
#include <Xm/Xm.h>
//#include <Xm/XmAll.h>
#endif

#include <gsgfx/gl/gsext.h>
#include <gsgfx/gl/gsfbo.h>
#include <gsgfx/gl/gspbuffer.h>
#include <gsgfx/gl/gsshaderprogram.h>
#include <gsgfx/gl/gstexturemanager.h>
#include <gsgfx/gl/gsvbo.h>

#include <gsscene/gsmaterialset.h>

#include <gsgfx/gsrenderer.h>

#include <gsimage/gstexture.h>

#include <gswindow/gswindow.h>

using namespace gsext;

namespace gsgfx
{
	class GS gsgl : public gsgfx::gsrenderer
	{
	public:
		gsgl ();
		virtual ~gsgl ();

		void create (gswin::gswindow *w);
		void reset ();
		void destroy ();

		void beginframe (const gsgeom::gscolor &color);
		void endframe ();

		void render (gsgeom::gsgeometrybuffer *buffer);

		//material properties
		void setMaterial (gsgeom::gsmaterial *m);
		void enableMaterial (gsgeom::gsmaterial *m);
		void cycleMaterial (gsgeom::gsmaterial *pOld, gsgeom::gsmaterial *pNew);
		void disableMaterial (gsgeom::gsmaterial *m);
		
		//lights
		void enableLight (const unsigned int &index, gsgeom::gslight *l);
		void disableLight (const unsigned int &index);

		//shaders:
		//setShader will keep a pointer to the compiled version for quick lookups
		void setShader (gsgeom::gsshader *s);
		void enableShader (gsgeom::gsshader *s, gsutil::gsqueue <gsgeom::gsshadervariable*> *l);
		void disableShader (gsgeom::gsshader *s);

		//textures:
		//setTexture will add it to the internal texture manager, and enabling it will add it appropriately.
		void setTexture (gsimage::gstexture *t, gsgeom::gstextureinfo *texInfo);
		void enableTexture (const unsigned int &index, gsimage::gstexture *t);
		void disableTexture (const unsigned int &index, gsimage::gstexture *t);

		void drawText (const gsgeom::gsvec3f &pos, const gsgeom::gscolor &col, const gsutil::gsstring &text);

		void makeCurrent ();
		
		void setProjection (const gsgeom::gsmatrix &proj);
		void setView (const gsgeom::gsmatrix &view);

	private:
		void process (gsgeom::gsgeometrybuffer *buffer);
		void unprocess (gsgeom::gsgeometrybuffer *buffer);
#ifdef WIN32
		unsigned int m_Font;
		HWND m_hWnd;
		HDC m_hDC;
		HGLRC m_hGLRC;
		PIXELFORMATDESCRIPTOR m_pfd;
#else
		GLXContext m_glxC;
		Display *m_display;
		Window m_Window;
#endif

		gsgfx::gstexturemanager m_TexMgr;
	};
};

#endif
