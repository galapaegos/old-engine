#include "gsmainwindow.h"

namespace gs
{
	gsmainwindow::gsmainwindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
		const int x, const int y, const int w, const int h,
		HWND hParent, HINSTANCE hInstance) : 
	gswindow (exStyle, pclass, ptitle, style,
		x, y, w, h,
		hParent, hInstance, gsmainWindowWndProc)
	{
		m_iRun = 1;
		
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pMenu = NULL;

		onCreate ();
	}

	gsmainwindow::~gsmainwindow ()
	{
		if (m_pMenu)
			delete m_pMenu;
	}

	void gsmainwindow::onCreate ()
	{
		gsmenu *pFile = new gsmenu ("File");
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "New World"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Open World"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_VBAR));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "New"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Open"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Close"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_VBAR));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Save"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Save As"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Save As Primitive"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_VBAR));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Import"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Export"));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_VBAR));
		pFile->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Exit"));
		gsmenu *pEdit = new gsmenu ("Edit");
		pEdit->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Undo"));
		pEdit->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Redo"));
		pEdit->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Cut"));
		pEdit->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Copy"));
		pEdit->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Paste"));
		pEdit->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Delete"));
		gsmenu *pView = new gsmenu ("View");
		gsmenu *pAbout = new gsmenu ("About");
		pAbout->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "About"));
		pAbout->insertItem (new gsmenuitem (gsmenu::m_iUniqueId, GSMENU_ITEM_STRING, "Help"));

		m_pMenu = new gsmenu;
		m_pMenu->insertMenu (pFile);
		m_pMenu->insertMenu (pEdit);
		m_pMenu->insertMenu (pView);
		m_pMenu->insertMenu (pAbout);

		SetMenu (getHandle (), m_pMenu->getMenu ());
	}
	void gsmainwindow::onDestroy ()
	{
		m_iRun = 0;
		PostQuitMessage (0);
	}
	void gsmainwindow::onPaint ()
	{
		PAINTSTRUCT ps;
		BeginPaint (getHandle (), &ps);
		EndPaint (getHandle (), &ps);
	}
	void gsmainwindow::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
			case VK_ESCAPE:
				m_iRun = 0;
				PostQuitMessage (0);
				break;
		}
	}

	void gsmainwindow::onShowWindow ()
	{
		UpdateWindow (m_ChildWindows[2]->getHandle ());
	}

	void gsmainwindow::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == 0)
		{
			int icontrol = LOWORD (wParam);

			switch (icontrol)
			{
			case 0: //new world
				{
					//MessageBox (NULL, "new", "msg", MB_OK);
					gsnewworld *n = new gsnewworld (0, "newworld", "Create new section of world",
						WS_OVERLAPPEDWINDOW, getWidth ()/2 - 150, getHeight ()/2 - 300,
						300, 600, getHandle (), getInst ());
				}
				break;

			case 1: //open world
				{
					//gsopenworld *o = new gsopenworld
				}
				break;

			case 3: //new scene
				{
					//prompt user its ok
					//remove all scenes from scene renderlist
				}
				break;

			case 4: //open scene
				{
					OPENFILENAME f;
					char buf[255];
					memset (&f, 0, sizeof (f));
					f.lStructSize = sizeof (f);
					f.hwndOwner = getHandle ();
					f.lpstrFilter = "Scene\0*.scene\0";
					f.nMaxFile = 256;
					f.lpstrFile = buf;
					f.lpstrFile[0] = '\0';
					f.lpstrInitialDir = ""; //config will store this
					f.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;

					if (GetOpenFileName (&f) != 0)
					{
						gsstring pStr = (char*)f.lpstrFile;
						gskernel *k = gskernel::get ();
						gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE_FILE, pStr));
						gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
					}
				}
				break;

			case 5: //close
				{
				}
				break;

			case 7: //save scene
				{
					OPENFILENAME f;
					char buf[255];
					memset (&f, 0, sizeof (OPENFILENAME));
					f.lStructSize = sizeof (OPENFILENAME);
					f.hwndOwner = getHandle ();
					f.lpstrFilter = "Scene\0*.scene\0";
					f.lpstrFile = buf;
					f.lpstrFile[0] = '\0';
					f.nFilterIndex = 0;
					f.nMaxFile = 256;
					f.lpstrFileTitle = "";
					f.nMaxFileTitle = 0;
					f.lpstrInitialDir = ""; //config will store this
					f.lpstrTitle = "";
					f.Flags = OFN_PATHMUSTEXIST;
					f.lpstrDefExt = "";

					if (GetSaveFileName (&f) != 0)
					{
						// create a gsscene, fill in the camera options and add 
						//the m_RenderQueue as child scenes to this one

						//gsscene *s = m_SceneLoader.read (f.lpstrFile);
						//gskernel::get ().addEvent (gsevent (GS_ADD_SCENE, s));
						//gskernel::get ().addEvent (gsevent (GS_UPDATE, NULL));

						gsstring pStr = f.lpstrFile;
						gskernel::get ()->addEvent (gsevent (GS_SAVE_SCENE, pStr));
						gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
					}
				}
				break;
				
			case 8://save as
				{
				}
				break;

			case 9://save as primitive
				{
				}
				break;

			case 11: //import
				{
				}
				break;

			case 12: //export
				{
				}
				break;

			case 14:
				m_iRun = 0;
				PostQuitMessage (0);
				break;

			case 15: //undo
				{
				}
				break;

			case 16: //redo
				{
				}
				break;

			case 17: //cut
				{
				}
				break;

			case 18: //copy
				{
				}
				break;

			case 19: //paste
				{
				}
				break;

			case 20: //delete
				{
				}
				break;

			case 21: //about
				{
					gsabout *pAbout = new gsabout (getWidth ()/2 - 125, 
						getHeight ()/2 - 100, 250, 200, getInst ());
					pAbout->show ();
				}
				break;

			case 23: //help
				{
				}
				break;
			}
		}
	}

	LRESULT CALLBACK gsmainwindow::gsmainWindowWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsmainwindow *w = (gsmainwindow*)GetWindowLong (hWnd, GWL_USERDATA);
				
		switch (message)
		{
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			case WM_SHOWWINDOW:
			//	w->onPaint ();
				break;
				
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;
				
			case WM_DESTROY:
				w->onDestroy ();
				break;
				
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}
};