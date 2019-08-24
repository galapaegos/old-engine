#include "gswindow/gswindow.h"

namespace gswin
{
	gswindow::gswindow (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &ptitle, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h) : gsmain (exStyle, pclass, ptitle, style, id, x, y, w, h, NULL)
	{
		m_iRun = 1;
	}

	gswindow::~gswindow ()
	{
	}

	void gswindow::onClose ()
	{
		m_iRun = 0;
	}

	void gswindow::onPaint ()
	{
#ifdef WIN32
		PAINTSTRUCT ps;
		BeginPaint (getHandle (), &ps);
		EndPaint (getHandle (), &ps);
#endif
	}

	void gswindow::handle ()
	{
		while (m_iRun == 1)
		{
			gswin::gswindow::process ();
		}
	}

	void gswindow::process ()
	{
		if (m_iRun == 1)
		{
#ifdef WIN32
			Sleep (1);
			if (PeekMessage (&m_message, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage (&m_message);
				DispatchMessage (&m_message);
			}
#else
			//XtAppMainLoop (m_Context);
			XEvent e;
			XtAppNextEvent (m_Context, &e);
			XtDispatchEvent (&e);

			switch (e.type)
			{
			case Expose:
				onPaint ();
				break;
			}
#endif
		}
	}

	void gswindow::onKeyDown (void *wParam, void *lParam)
	{
#ifdef WIN32
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		switch (wp)
		{
		case VK_ESCAPE:
			break;
		}
#endif
	}

	void gswindow::setMenu (gswin::gsmenu *m)
	{
#ifdef WIN32
		SetMenu (getHandle (), m->getMenu ());
#endif
	}
};
