#include "test.h"

#include <gsutil/gscpu.h>

class terrainROAM : public gswin::gswindow
{
public:
	terrainROAM (const int &x, const int &y, const int &w, const int &h) : gswin::gswindow (0, "class", "Test", gswin::gsWINDOW_OVERLAPPEDWINDOW, 0, x, y, w, h) 
	{
		m_bRotate = false;

		kern = new gskernel;

		kern->init (this, w, h);

		gsgeom::gsterrain *t = new gsgeom::gsterrain (33, 257, 257);
		t->init (15.f);

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (w, h, 45.f, 1.f, 800.f);
		c->setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));

		m_pScene = t->getScene ();
		m_pScene->m_Camera = c;

		kern->addEvent (gs::gsevent (GS_ADD_SCENE, m_pScene));
	}
	~terrainROAM ()
	{
		kern->shutdown ();
		delete kern;
	}

	void onMouseMove (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		int x = LOWORD (lParam);
		int y = HIWORD (lParam);

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
	}

	void onMouseWheel (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		gsgeom::gscamera *c = m_pScene->m_Camera;
		short w = HIWORD (wp);

		float dx = -w/120.f;

		c->moveForward (dx*0.5f);
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
	gskernel *kern;
	gsgeom::gsscene *m_pScene;

	int oldx, oldy;
	bool m_bRotate;
};

int main (int argc, char *argv[])
{
	int aw = GetSystemMetrics (SM_CXSCREEN);
	int ah = GetSystemMetrics (SM_CYSCREEN);

	terrainROAM w (aw/2 - 1280/2, ah/2 - 1024/2, 1280, 1024);

	w.handle ();

	return 0;
}

