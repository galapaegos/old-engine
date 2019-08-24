#ifndef _gsrenderer_h_
#define _gsrenderer_h_

#include <gsgeom/gsgeometrychunk.h>

#include <gsgfx/gsrenderfeatures.h>

#include <gsimage/gstexture.h>

#include <gswindow/gswindow.h>

namespace gsgfx
{
	class GS gsrenderer
	{
	public:
		gsrenderer ();
		virtual ~gsrenderer ();

		//creation parameters
		virtual void create (gswin::gswindow *w);
		virtual void reset ();
		virtual void destroy ();

		virtual void beginframe (const gsgeom::gscolor &color);
		virtual void endframe ();

		virtual gsgfx::gsrenderfeatures getFeatures ();

		virtual void setMaterial (gsgeom::gsmaterial *m);
		virtual void enableMaterial (gsgeom::gsmaterial *m);
		virtual void cycleMaterial (gsgeom::gsmaterial *pOld, gsgeom::gsmaterial *pNew);
		virtual void disableMaterial (gsgeom::gsmaterial *m);
		
		virtual void setShader (gsgeom::gsshader *s);
		virtual void enableShader (gsgeom::gsshader *s, gsutil::gsqueue <gsgeom::gsshadervariable*> *l);
		virtual void disableShader (gsgeom::gsshader *s);

		virtual void setLight (gsgeom::gslight *l);
		virtual void enableLight (const unsigned int &index, gsgeom::gslight *l);
		virtual void disableLight (const unsigned int &index);

		virtual void setTexture (gsimage::gstexture *t, gsgeom::gstextureinfo *texInfo);
		virtual void enableTexture (const unsigned int &index, gsimage::gstexture *t);
		virtual void disableTexture (const unsigned int &index, gsimage::gstexture *t);

		virtual gsgeom::gsmatrix getTransform ();
		virtual void setTransform (const gsgeom::gsmatrix &m);

		virtual void render (gsgeom::gsgeometrychunk *geometry);

		virtual void drawText (const gsgeom::gsvec3f &pos, const gsgeom::gscolor &col, const gsutil::gsstring &text);
		
		virtual void setProjection (const gsgeom::gsmatrix &proj);
		virtual void setView (const gsgeom::gsmatrix &view);
		
	protected:
		gsutil::gsstring m_strDriver;
		gswin::gswindow *m_pWindow;

		gsgeom::gsmatrix m_currentTransform;

		gsutil::gsqueue <gsimage::gstexture*> m_TextList;
	};
};

#endif

