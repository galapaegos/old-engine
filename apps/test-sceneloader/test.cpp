#include "test.h"

#ifdef WIN32
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

class Loader : public gswin::gswindow
{
public:
	Loader () : gswindow (0, "sceneloader", "Scene Loader", 0, 0, 0, 800, 600)
	{
		m_kernel = new gs::gskernel;
		m_kernel->init (this, getWidth (), getHeight ());

		gswin::gsmenu *pFile = new gswin::gsmenu ("File");
		pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Open"));
		pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Close"));
		pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_VBAR));
		pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Exit"));
		gswin::gsmenu *pAbout = new gswin::gsmenu ("About");
		pAbout->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "About"));
		pAbout->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Help"));

		m_pMenu = new gswin::gsmenu;
		m_pMenu->insertMenu (pFile);
		m_pMenu->insertMenu (pAbout);
#ifdef WIN32
		SetMenu (getHandle (), m_pMenu->getMenu ());
#endif
		m_pCurrentScene = NULL;
	}
	~Loader ()
	{
		delete m_kernel;
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();
		}
	}

	void onDestroy ()
	{
		m_iRun = 0;
		//m_kernel->addEvent (gsevent (gs::GS_QUIT, NULL));
	}

	void onKeyDown (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		switch (wp)
		{
		case VK_ESCAPE:
			m_iRun = 0;
			//m_kernel->addEvent (gsevent (gs::GS_QUIT, NULL));
			break;

		case VK_UP:
			{
				if (m_pCurrentScene->m_Camera)
					m_pCurrentScene->m_Camera->moveForward (-0.5f);
			}
			break;

		case VK_DOWN:
			{
				if (m_pCurrentScene->m_Camera)
					m_pCurrentScene->m_Camera->moveForward (0.5f);
			}
			break;
		}
#endif
	}

	virtual void onMouseMove (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		int x = LOWORD (lParam);
		int y = HIWORD (lParam);

		if (!m_pCurrentScene)
			return;

		gsgeom::gscamera *c = m_pCurrentScene->m_Camera;
		if (wp == MK_LBUTTON && m_bRotate && c != NULL)
		{
			float difx = (float)(x - oldx)*0.05f;
			float dify = (float)(y - oldy)*0.05f;

			//x direction
			c->pitch (dify);

			//y direction
			c->yaw (difx);
		}

		oldx = x;
		oldy = y;
#endif
	}

	virtual void onMouseWheel (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		gsgeom::gscamera *c = m_pCurrentScene->m_Camera;
		if (!c)
			return;

		short w = HIWORD (wp);

		float dx = -w/120.f;

		c->moveForward (dx);
#endif
	}

	virtual void onMouseLeftDown (void *wParam, void *lParam)
	{
		m_bRotate = true;
	}

	virtual void onMouseLeftUp (void *wParam, void *lParam)
	{
		m_bRotate = false;
	}

	void onCommand (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		if (HIWORD (wp) == 0)
		{
			int icontrol = LOWORD (wp);

			switch (icontrol)
			{
			case 0: //open
				{
					OPENFILENAME f;
					char buf[255] = "";
					memset (&f, 0, sizeof (f));
					f.lStructSize = sizeof (f);
					f.hwndOwner = getHandle ();
					f.lpstrFile = buf;
					f.lpstrFile[0] = '\0';
					f.nMaxFile = sizeof (buf);
					f.lpstrFilter = "Scene\0*.scene\0";
					f.nFilterIndex = 1;
					f.lpstrFileTitle = NULL;
					f.nMaxFileTitle = 0;
					f.lpstrInitialDir = NULL; //config will store this
					f.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;

					if (GetOpenFileName (&f) != 0)
					{
						gsstring pStr = (char*)f.lpstrFile;
						m_pCurrentScene = gssceneloader::read (pStr);

						if (!m_pCurrentScene->m_Camera)
						{
							gsgeom::gscamera *c = new gsgeom::gscamera;
							c->setProjection (getWidth (), getHeight (), 45.f, 1.f, 300.f);
							c->setView (gsgeom::gsvec3f (10, 10, 10),
										gsgeom::gsvec3f (0, 0, 0),
										gsgeom::gsvec3f (0, 1, 0));
							m_pCurrentScene->m_Camera = c;
						}

						if (m_pCurrentScene->m_vLight.getSize () <= 0)
						{
							gsgeom::gslight *l = new gsgeom::gslight (gsgeom::gsvec3f (128, 100, 128), gsgeom::gscolor (0.5, 0.5, 0.5, 0.5), gsgeom::gslight::LIGHT_POINT);
							m_pCurrentScene->m_vLight.add (l);
						}

						m_kernel->addEvent (gsevent (GS_ADD_SCENE, m_pCurrentScene));
					}
				}
				break;

			case 1: //close
				{
					m_kernel->addEvent (gsevent (GS_REM_SCENE, m_pCurrentScene));
				}
				break;

			case 3: //exit
				m_iRun = 0;
				break;
			}
		}
#endif
	}

private:
	gs::gskernel *m_kernel;
	gswin::gsmenu *m_pMenu;

	gsgeom::gsscene *m_pCurrentScene;

	int oldx, oldy;
	bool m_bRotate;
};

int main (int argc, char *argv[])
{
	Loader *l = new Loader;

	l->handle ();

	return 0;
}
