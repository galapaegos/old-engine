#include <gsscene/gscameranode.h>

namespace gsscene
{
	gscameranode::gscameranode ()
	{
		m_iType = 0;
		m_pCamera = new gsgeom::gscamera;
	}

	gscameranode::~gscameranode ()
	{
		delete m_pCamera;
	}

	gsgeom::gscamera *gscameranode::getCamera ()
	{
		return m_pCamera;
	}

	void gscameranode::setType (const unsigned int &type)
	{
		m_iType = type;
	}

	unsigned int gscameranode::getType ()
	{
		return m_iType;
	}

	void gscameranode::setOrthographic (const int &iWidth, const int &iHeight, const float &fNear, const float &fFar)
	{
		m_pCamera->setOrthogonal (iWidth, iHeight, fNear, fFar);
	}

	void gscameranode::setProjection (const int &iWidth, const int &iHeight, const float &fAngle, const float &fNear, const float &fFar)
	{
		m_pCamera->setProjection (iWidth, iHeight, fAngle, fNear, fFar);
	}

	void gscameranode::setView (const gsgeom::gsvec3f &pos, const gsgeom::gsvec3f &org, const gsgeom::gsvec3f &world)
	{
		m_pCamera->setView (pos, org, world);
	}

	void gscameranode::render (gsgfx::gsrenderer *renderer)
	{
		renderer->setProjection (m_pCamera->getProjection ());
		renderer->setView (m_pCamera->getView ());

		gsscenenode::render (renderer);
	}
};
