#include "gsgroup.h"

namespace gs
{
	gsgroup::gsgroup (const char *pclass, const char *ptitle,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
	gswindow (0, pclass, ptitle, WS_GROUP,
		x, y, w, h, hParent, hInstance, gsgroupWindowWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		m_hParent = hParent;
	}
	
	gsgroup::~gsgroup ()
	{
	}
	
	LRESULT CALLBACK gsgroup::gsgroupWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsgroup *w = (gsgroup*)GetWindowLong (hWnd, GWL_USERDATA);
		switch (message)
		{
			case WM_COMMAND:
				SendMessage (w->m_hParent, message, wParam, lParam);
				break;
			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 0;
	}
};