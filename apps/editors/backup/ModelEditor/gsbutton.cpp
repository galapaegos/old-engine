#include "gsbutton.h"

namespace gs
{
	gsbutton::gsbutton (const char *title,
		const int x, const int y, const int w, const int h,
		HWND hParent, HINSTANCE hInstance) : 
	gswindow (0, "BUTTON", title, WS_CHILD|BS_PUSHBUTTON|BS_TEXT,
		x, y, w, h, hParent, hInstance)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gsbuttonWindowWndProc);
	}

	gsbutton::~gsbutton ()
	{
	}

	LRESULT CALLBACK gsbutton::gsbuttonWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsbutton *w = (gsbutton*)GetWindowLong (hWnd, GWL_USERDATA);

		return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	}
};