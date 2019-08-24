#include "gstoolswindow.h"

namespace gs
{
	gstoolswindow::gstoolswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
	gswindow (exStyle, pclass, ptitle, style,
		x, y, w, h,
		hParent, hInstance, gstoolsWindowWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		int frame = GetSystemMetrics (SM_CXSIZEFRAME);

		tabctl = new gstoolstabctl (0, "SysTabControl32", "", WS_CHILD|WS_VISIBLE,
			0, 0, w, h, getHandle (), getInst ());
	}
	
	gstoolswindow::~gstoolswindow ()
	{
	}

	void gstoolswindow::onNotify (LPARAM lParam)
	{
		NMHDR FAR *tem=(NMHDR FAR *)lParam;

		if ((tem->code== TCN_SELCHANGE) || (tem->code == TCN_SELCHANGING))
		{
			int num=TabCtrl_GetCurSel(tem->hwndFrom);
			for (int x = 0; x < tabctl->numChildren (); x++)
			{
				if (num == x)
					tabctl->show (x);
				else
					tabctl->hide (x);
			}
		}
	}
	
	LRESULT CALLBACK gstoolswindow::gstoolsWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolswindow *w = (gstoolswindow*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
			case WM_NOTIFY:
				w->onNotify (lParam);
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