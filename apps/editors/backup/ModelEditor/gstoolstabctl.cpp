#include "gstoolstabctl.h"

namespace gs
{
	gstoolstabctl::gstoolstabctl (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
	gswindow (exStyle, pclass, ptitle, style,
		x, y, w, h,
		hParent, hInstance)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gstoolsTabCtlWndProc);

		int frame = GetSystemMetrics (SM_CXSIZEFRAME);

		gstoolsprimitives *gstp = new gstoolsprimitives (0, "gstoolsprimitives", "", WS_CHILD|WS_VISIBLE,
			0, 30, w - frame, h - 30 - frame, getHandle (), getInst ());

		TC_ITEM item;

		item.mask = TCIF_TEXT | TCIF_STATE | TCIF_IMAGE;
		item.iImage = -1;
		item.pszText = "Primitives";
		TabCtrl_InsertItem(getHandle (), 0, &item);

		m_ChildWindows.add (gstp);
		gstp->show ();

		// adding the gstoolsediting panel
		//gstoolsediting *gste = new gstoolsediting (0, "gstoolsediting", "", WS_CHILD|WS_VISIBLE,
		//	0, 30, w - frame, h - 30 - frame, getHandle (), getInst ());

		//item.pszText = "Editing";
		//TabCtrl_InsertItem (getHandle (), 1, &item);

		//m_ChildWindows.add (gste);
		//gste->hide ();

		// adding the gstoolseffect panel
		gstoolseffect * gstef = new gstoolseffect (0, "gstoolseffect", "", WS_CHILD|WS_VISIBLE,
			0, 30, w - frame, h - 30 - frame, getHandle (), getInst ());

		item.pszText = "Effects";
		TabCtrl_InsertItem (getHandle (), 1, &item);

		m_ChildWindows.add (gstef);
		gstef->hide ();
	}
	
	gstoolstabctl::~gstoolstabctl ()
	{
	}
	
	LRESULT CALLBACK gstoolstabctl::gstoolsTabCtlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolstabctl *w = (gstoolstabctl*)GetWindowLong (hWnd, GWL_USERDATA);
		
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