#include "gstabctl.h"

namespace gs
{
	gstabctl::gstabctl (DWORD exStyle, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gswindow (exStyle, WC_TABCONTROL, ptitle, style, 
		x, y, w, h, hParent, hInstance)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		//m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		//SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gstabctlWndProc);
	}
	
	gstabctl::~gstabctl ()
	{
	}

	//LRESULT CALLBACK gstabctl::gstabctlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	//{
	//	gstabctl *w = (gstabctl*)GetWindowLong (hWnd, GWL_USERDATA);
	//	return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	//}
};