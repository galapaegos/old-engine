#include <gsgfx/gsrenderer.h>

namespace gsgfx
{
	gsrenderer::gsrenderer ()
	{
	}

	gsrenderer::~gsrenderer ()
	{
	}

	void gsrenderer::create (gswin::gswindow *w)
	{
		gsAssert (w);

		m_pWindow = w;
	}

	void gsrenderer::reset ()
	{
	}

	void gsrenderer::destroy ()
	{
	}

	void gsrenderer::beginframe (const gsgeom::gscolor &color)
	{
	}

	void gsrenderer::endframe ()
	{
	}

	gsgfx::gsrenderfeatures gsrenderer::getFeatures ()
	{
		gsgfx::gsrenderfeatures rf;
		return rf;
	}

	void gsrenderer::setMaterial (gsgeom::gsmaterial *m)
	{
	}

	void gsrenderer::enableMaterial (gsgeom::gsmaterial *m)
	{
	}

	void gsrenderer::cycleMaterial (gsgeom::gsmaterial *pOld, gsgeom::gsmaterial *pNew)
	{
	}

	void gsrenderer::disableMaterial (gsgeom::gsmaterial *m)
	{
	}

	void gsrenderer::setLight (gsgeom::gslight *l)
	{
	}

	void gsrenderer::enableLight (const unsigned int &index, gsgeom::gslight *l)
	{
	}

	void gsrenderer::disableLight (const unsigned int &index)
	{
	}

	void gsrenderer::setShader (gsgeom::gsshader *s)
	{
	}

	void gsrenderer::enableShader (gsgeom::gsshader *s, gsutil::gsqueue <gsgeom::gsshadervariable*> *l)
	{
	}

	void gsrenderer::disableShader (gsgeom::gsshader *s)
	{
	}

	void gsrenderer::setTexture (gsimage::gstexture *t, gsgeom::gstextureinfo *texInfo)
	{
		gsAssert (t);

		m_TextList.add (t);
	}

	void gsrenderer::enableTexture (const unsigned int &index, gsimage::gstexture *t)
	{
	}

	void gsrenderer::disableTexture (const unsigned int &index, gsimage::gstexture *t)
	{
	}

	gsgeom::gsmatrix gsrenderer::getTransform ()
	{
		return m_currentTransform;
	}

	void gsrenderer::setTransform (const gsgeom::gsmatrix &m)
	{
		m_currentTransform = m;
	}

	void gsrenderer::render (gsgeom::gsgeometrychunk *geometry)
	{
	}

	void gsrenderer::drawText (const gsgeom::gsvec3f &pos, const gsgeom::gscolor &col, const gsutil::gsstring &text)
	{
	}
	
	void gsrenderer::setProjection (const gsgeom::gsmatrix &proj)
	{
	}

	void gsrenderer::setView (const gsgeom::gsmatrix &view)
	{
	}
};
