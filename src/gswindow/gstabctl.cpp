#include "gswindow/gstabctl.h"

namespace gswin
{
	gstabctl::gstabctl (gswidget *parent, DWORD exStyle, const gsutil::gsstring &title, DWORD style, const int &id,
		const int &x, const int &y, const int &w, const int &h) : gscontrol (exStyle, WC_TABCONTROL, title, style, id, x, y, w, h, 
		parent)
	{
		m_iCurrentTab = 0;
		//resize control to fit inside parent window!
		if (!x && !y && !w && !h)
		{
			RECT r;
			GetClientRect (parent->getHandle (), &r);
			resize (r.left, r.top, r.right - r.left, r.bottom - r.top);
		}
	}
	
	gstabctl::~gstabctl ()
	{
	}

	void gstabctl::add (gswidget *w)
	{
		TCITEM i;
		i.pszText = reinterpret_cast <LPSTR> (const_cast <char*> (w->getTitle ().str ()));
		i.mask = TCIF_TEXT|TCIF_IMAGE;
		i.iImage = -1;

		TabCtrl_InsertItem (getHandle (), m_ChildWindows.getSize (), &i);
		
		m_ChildWindows.add (w);
	}

	void gstabctl::onNotify (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		NMHDR FAR *tem = (NMHDR FAR *)lp;

		switch (tem->code)
		{
		case TCN_SELCHANGE:
			{
				m_iCurrentTab = TabCtrl_GetCurSel(getHandle ());
				//show ();
				for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
				{
					if (m_iCurrentTab == x)
						m_ChildWindows[x]->show ();
					else
						m_ChildWindows[x]->hide ();
				}
			}
			break;

		case TCN_SELCHANGING:
			{
				int num = TabCtrl_GetCurSel(tem->hwndFrom);
				gswidget *w = reinterpret_cast <gswidget*> (static_cast <ULONG_PTR> (GetWindowLong (m_ChildWindows[num]->getHandle (), GWL_USERDATA)));
				w->hide ();
			}
			break;
		}
	}

	void gstabctl::show ()
	{
		UpdateWindow (getHandle ());

		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		{
			if (m_iCurrentTab == x)
				m_ChildWindows[x]->show ();
			else
				m_ChildWindows[x]->hide ();
		}
	}
};
