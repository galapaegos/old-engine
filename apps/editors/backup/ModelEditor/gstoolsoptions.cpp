#include "gstoolsoptions.h"

namespace gs
{
	gstoolsoptions::gstoolsoptions (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : gswindow (exStyle, pclass, ptitle,
			style, x, y, w, h, hParent, hInstance, gstoolsoptionsWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pTabCtl = new gstoolsoptionsctl (0, 0, w - 5, h - 5, getHandle (), getInst ());
	}

	gstoolsoptions::~gstoolsoptions ()
	{
	}

	void gstoolsoptions::onDestroy ()
	{
		delete this;
	}

	void gstoolsoptions::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
	}

	LRESULT gstoolsoptions::gstoolsoptionsWndProc (HWND hWnd, UINT message, WPARAM wParam,
		LPARAM lParam)
	{
		gstoolsoptions *w = (gstoolsoptions*)GetWindowLong (hWnd, GWL_USERDATA);

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