#include "gsabout.h"

namespace gs
{
	gsabout::gsabout (const int x, const int y, const int w, const int h, HINSTANCE hInst) :
		gswindow (WS_EX_TOPMOST, "ABOUT", "About", WS_OVERLAPPEDWINDOW,
			x, y, w, h, NULL, hInst, gsaboutWindowWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		m_pDescription = new gsdescription (
			"    This is private software.  If you have a copy of this software without authorization, you will get owned by me.",
			0, 0, getWidth (), getHeight (), getHandle (), getInst ());
	}

	gsabout::~gsabout ()
	{
		delete m_pDescription;
	}

	void gsabout::onDestroy ()
	{
		delete this;
	}

	LRESULT gsabout::gsaboutWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsabout *w = (gsabout*)GetWindowLong (hWnd, GWL_USERDATA);
		switch (message)
		{
		case WM_DESTROY:
			w->onDestroy ();
			break;

		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 0;
	}
};