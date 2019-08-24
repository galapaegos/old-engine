#include <gs/gsrenderer.h>

namespace gs
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

	void gsrenderer::beginframe ()
	{
	}

	void gsrenderer::endframe ()
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

	void gsrenderer::render (const gsgeom::gsgeometrybuffer *geometry)
	{
	}
	
	void gsrenderer::setProjection (const gsgeom::gsmatrix &proj)
	{
	}

	void gsrenderer::setView (const gsgeom::gsmatrix &view)
	{
	}
};
