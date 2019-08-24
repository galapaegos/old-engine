#include "gstoolsobjects.h"

namespace gs
{
	gstoolsobjects::gstoolsobjects (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gstabpanel (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsObjectsWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
	}
	
	gstoolsobjects::~gstoolsobjects ()
	{
	}

	LRESULT CALLBACK gstoolsobjects::gstoolsObjectsWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsobjects *w = (gstoolsobjects*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
			case WM_PAINT:
				w->onPaint ();
				break;
					
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