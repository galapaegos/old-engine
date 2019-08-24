#include "gstoolsoptions.h"

namespace gs
{
	gstoolsoptionsctl::gstoolsoptionsctl (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInst) :
		gstabctl (0, "", WS_CHILD|WS_VISIBLE, x, y, w, h, hParent, hInst)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pGeneral = new gstoolsoptionsgeneral (2, 28, getWidth () - 8, getHeight () - 52, getHandle (), getInst ());

		add (m_pGeneral);

		TCITEM i;
		i.pszText = "General";
		i.mask = TCIF_TEXT|TCIF_IMAGE;
		i.iImage = -1;

		TabCtrl_InsertItem (getHandle (), 0, &i);

		m_pNetwork = new gstoolsoptionsnetwork (2, 28, getWidth () - 8, getHeight () - 52, getHandle (), getInst ());

		add (m_pNetwork);

		i.pszText = "Network";

		TabCtrl_InsertItem (getHandle (), 1, &i);

		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gstoolsoptionsctlWndProc);
	}

	gstoolsoptionsctl::~gstoolsoptionsctl ()
	{
	}

	void gstoolsoptionsctl::onCommand (WPARAM wParam, LPARAM lParam)
	{
	}

	void gstoolsoptionsctl::onNotify (WPARAM wParam, LPARAM lParam)
	{
		switch (HIWORD (wParam))
		{
		case TCN_SELCHANGE:
			{
				int sel = TabCtrl_GetCurSel (getHandle ());

				for (int x = 0; x < m_ChildWindows.getSize (); x++)
				{
					if (x == sel)
						m_ChildWindows[x]->show ();
					else
						m_ChildWindows[x]->hide ();
				}
			}
			break;
		}
	}

	LRESULT gstoolsoptionsctl::gstoolsoptionsctlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsoptionsctl *w = (gstoolsoptionsctl*)GetWindowLong (hWnd, GWL_USERDATA);

		switch (message)
		{
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			case WM_NOTIFY:
				w->onNotify (wParam, lParam);
				break;

			default:
				return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
		}

		return 0;
	}
};