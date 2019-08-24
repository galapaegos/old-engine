#include "gstoolslighting.h"

namespace gs
{
	gstoolslighting::gstoolslighting (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gstabpanel (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsLightingWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
	}
	
	gstoolslighting::~gstoolslighting ()
	{
	}

	void gstoolslighting::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
		case ' ':
			{
				delete this;
			}
			break;
		}
	}

	LRESULT CALLBACK gstoolslighting::gstoolsLightingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolslighting *w = (gstoolslighting*)GetWindowLong (hWnd, GWL_USERDATA);
		
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