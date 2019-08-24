#include "gsdescription.h"

namespace gs
{
	gsdescription::gsdescription (const char *title,
		const int x, const int y, const int w, const int h,
		HWND hParent, HINSTANCE hInstance) : 
	gswindow (0, "STATIC", title, WS_CHILD|SS_LEFT,
		x, y, w, h, hParent, hInstance)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gsdescriptionWindowWndProc);
	}

	gsdescription::~gsdescription ()
	{
	}

	LRESULT CALLBACK gsdescription::gsdescriptionWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsdescription *w = (gsdescription*)GetWindowLong (hWnd, GWL_USERDATA);

		return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	}
};