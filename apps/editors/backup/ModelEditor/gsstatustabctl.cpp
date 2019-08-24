#include "gsstatustabctl.h"

namespace gs
{
	gsstatustabctl::gsstatustabctl (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
	gswindow (exStyle, pclass, ptitle, style,
		x, y, w, h,
		hParent, hInstance)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gsstatusTabCtlWndProc);
	}
	
	gsstatustabctl::~gsstatustabctl ()
	{
	}
	
	LRESULT CALLBACK gsstatustabctl::gsstatusTabCtlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsstatustabctl *w = (gsstatustabctl*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{			
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;
					
			case WM_DESTROY:
				w->onDestroy ();
				break;
		}

		return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	}
};