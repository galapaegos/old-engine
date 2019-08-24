#include "gstoolsoptionsgeneral.h"

namespace gs
{
	gstoolsoptionsgeneral::gstoolsoptionsgeneral (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInstance) 
		: gstabpanel (0, "gstoolsoptionsgeneral", "", WS_CHILD|WS_VISIBLE, x, y, w, h, hParent, hInstance, gstoolsoptionsgeneralWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		gsdescription *desc = new gsdescription ("test", 10, 10, getWidth () - 20, getHeight () - 20, getHandle (), getInst ());
	}

	gstoolsoptionsgeneral::~gstoolsoptionsgeneral ()
	{
	}

	LRESULT gstoolsoptionsgeneral::gstoolsoptionsgeneralWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsoptionsgeneral *w = (gstoolsoptionsgeneral*)GetWindowLong (hWnd, GWL_USERDATA);

		switch (message)
		{					
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;
					
			case WM_DESTROY:
				w->onDestroy ();
				break;

			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 0;
	}
};