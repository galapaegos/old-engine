#include "gstoolsoptionsnetwork.h"

namespace gs
{
	gstoolsoptionsnetwork::gstoolsoptionsnetwork (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInstance) 
		: gstabpanel (0, "gstoolsoptionsnetwork", "General", WS_CHILD|WS_VISIBLE, x, y, w, h, hParent, hInstance, gstoolsoptionsnetworkWndProc)
	{
	}

	gstoolsoptionsnetwork::~gstoolsoptionsnetwork ()
	{
	}

	LRESULT gstoolsoptionsnetwork::gstoolsoptionsnetworkWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsoptionsnetwork *w = (gstoolsoptionsnetwork*)GetWindowLong (hWnd, GWL_USERDATA);

		switch (message)
		{					
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;

			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 0;
	}
};