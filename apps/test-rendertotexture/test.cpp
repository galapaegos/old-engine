#include "test.h"

class RenderToTexture : public gswin::gswindow
{
public:
	RenderToTexture () : gswin::gswindow (0, "gs", "gsrendertotexture test", gswin::gsWINDOW_OVERLAPPEDWINDOW)
	{
		m_bRotate = false;

		m_kernel = new gs::gskernel;
		m_kernel->init (this, getAreaWidth (), getAreaHeight ());

		//r2t
		gsgeom::gsscene *r2t = new gsgeom::gsscene;
		r2t->m_RenderTarget = gsgeom::gsscene::RENDER_PREPROCESS;

		gsgeom::gscamera *cr2t = new gsgeom::gscamera;
		cr2t->setProjection (getAreaWidth (), getAreaHeight (), 45.f, 1.f, 300.f);
		cr2t->setView (gsgeom::gsvec3f (2, 2, 2), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		r2t->m_Camera = cr2t;

		gsgeom::gsgeometryinfo *gir2t = new gsgeom::gsgeometryinfo;
		gir2t->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gir2t->m_vPoints.add (gsgeom::gsvec3f (1, 0, 0));
		gir2t->m_vPoints.add (gsgeom::gsvec3f (0, 0, 1));

		gir2t->m_vColors.add (gsgeom::gscolor (1, 0, 0));
		gir2t->m_vColors.add (gsgeom::gscolor (0, 1, 0));
		gir2t->m_vColors.add (gsgeom::gscolor (0, 0, 1));
		r2t->m_Geometry = gir2t;

		gsgeom::gsgeometryinfo::IndexType *itr2t = new gsgeom::gsgeometryinfo::IndexType;
		itr2t->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		itr2t->m_vIndices.add (0);
		itr2t->m_vIndices.add (1);
		itr2t->m_vIndices.add (2);

		//scene
		m_pScene = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (5, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, 5));

		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 0.5));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 0.5));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 0.5));
		
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));

		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));

		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));

		gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
		it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		it->m_vIndices.add (0);
		it->m_vIndices.add (1);
		it->m_vIndices.add (2);
		gi->m_vIndices.add (it);

		m_pScene->m_Geometry = gi;

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (getAreaWidth (), getAreaHeight (), 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		m_pScene->m_Camera = c;

		m_kernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pScene));
	}

	~RenderToTexture ()
	{
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswin::gswindow::handle ();
		}
	}

	void onMouseMove (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		int x = LOWORD (lParam);
		int y = HIWORD (lParam);

		RECT r;
		GetClientRect (getHandle (), &r);

		POINT p;
		GetCursorPos (&p);
		ScreenToClient (getHandle (), &p);

		gsgeom::gsray ray = m_pScene->m_Camera->getPicked ((float)p.x, (float)((r.bottom - r.top) - p.y));

		if (m_bRotate)
		{
			float difx = (float)(x - oldx)*0.05f;
			float dify = (float)(y - oldy)*0.05f;

			gsgeom::gscamera *c = m_pScene->m_Camera;

			//x direction
			c->pitch (dify);

			//y direction
			c->yaw (difx);
		}

		oldx = x;
		oldy = y;
#endif
	}
	
	void onMouseWheel (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		gsgeom::gscamera *c = m_pScene->m_Camera;
		short w = HIWORD (wp);

		float dx = -w/120.f;

		c->moveForward (dx*1.5f);
#endif
	}

	void onMouseRightDown (void *wParam, void *lParam)
	{
		m_bRotate = true;
	}

	void onMouseRightUp (void *wParam, void *lParam)
	{
		m_bRotate = false;
	}

private:
	gs::gskernel *m_kernel;
	gsgeom::gsscene *m_pScene, *m_pPicking;

	int oldx, oldy;
	bool m_bRotate;
};

int main (int argc, char *argv[])
{
	RenderToTexture *l = new RenderToTexture;

	l->handle ();

	return 0;
}
