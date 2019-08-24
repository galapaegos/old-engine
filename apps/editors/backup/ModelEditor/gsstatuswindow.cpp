#include "gsstatuswindow.h"

namespace gs
{
	gsstatuswindow::gsstatuswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
	gswindow (exStyle, pclass, ptitle, style,
		x, y, w, h,
		hParent, hInstance, gsstatusWindowWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		tabctl = new gsstatustabctl (0, "SysTabControl32", "", WS_CHILD|WS_VISIBLE,
			0, 0, w, h, getHandle (), getInst ());
	}
	
	gsstatuswindow::~gsstatuswindow ()
	{
		delete tabctl;
	}

	void gsstatuswindow::onNotify (LPARAM lParam)
	{
		NMHDR FAR *tem=(NMHDR FAR *)lParam;

		if (tem->code== TCN_SELCHANGE)
		{
			int num=TabCtrl_GetCurSel(tem->hwndFrom);
			for (int x = 0; x < m_ChildWindows.getSize (); x++)
			{
				if (num == x)
					m_ChildWindows[x]->show ();
				else
					m_ChildWindows[x]->hide ();
			}
		}
	}
	
	LRESULT CALLBACK gsstatuswindow::gsstatusWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsstatuswindow *w = (gsstatuswindow*)GetWindowLong (hWnd, GWL_USERDATA);
		
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