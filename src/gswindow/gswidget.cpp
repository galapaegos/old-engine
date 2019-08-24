#include "gswindow/gswidget.h"

namespace gswin
{
#ifdef WIN32
	bool gswidget::m_bInitCommonControls = true;

	gswidget::gswidget (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &ptitle, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent, void *WndProc)
	{
		m_iId = id;
		if (m_bInitCommonControls)
		{
			INITCOMMONCONTROLSEX cc;
			cc.dwSize = sizeof (INITCOMMONCONTROLSEX);
			cc.dwICC = ICC_TAB_CLASSES|ICC_PROGRESS_CLASS;
			if (!InitCommonControlsEx (&cc))
				MessageBox (NULL, "unable to init common controls", "msg", MB_OK);

			m_bInitCommonControls = false;
		}

		if (WndProc)
			m_bUnregister = true;

		if (parent)
			m_hInst = parent->getInst ();
		else
			m_hInst = GetModuleHandle (NULL);

		HWND hParent = NULL;
		if (parent)
			hParent = parent->getHandle ();
		m_pParent = parent;

		m_strClass = pclass;
		m_strTitle = ptitle;

		m_iWidth = w;
		m_iHeight = h;

		m_iX = x;
		m_iY = y;

		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX); 

		wcex.style			= CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc	= (WNDPROC)WndProc;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.hInstance		= m_hInst;
		wcex.hIcon			= LoadIcon (m_hInst, (LPCTSTR)IDI_APPLICATION);
		wcex.hCursor		= LoadCursor (NULL, IDC_ARROW);
		//wcex.hbrBackground	= (HBRUSH) (COLOR_WINDOW+1);
		wcex.hbrBackground	= (HBRUSH)(COLOR_BACKGROUND);
		wcex.lpszMenuName	= NULL;
		wcex.lpszClassName	= pclass.str ();
		wcex.hIconSm		= LoadIcon (m_hInst, (LPCTSTR)IDI_APPLICATION);

		if (!RegisterClassEx(&wcex))
		{
			char *pMsgBuf;
			char *pDisplayBuf;
			DWORD dw = GetLastError();

			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
				NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &pMsgBuf,	0, NULL );

			pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
			wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
			MessageBox(NULL, pDisplayBuf, "Error", MB_OK); 
			return;
		}


		m_hWnd = CreateWindowEx (exStyle, pclass.str (), ptitle.str (), style, x, y, w, h, hParent, NULL, m_hInst, NULL);

		if (!m_hWnd)
		{
			char *pMsgBuf;
			char *pDisplayBuf;
			DWORD dw = GetLastError(); 

			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
				NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &pMsgBuf,	0, NULL );

			pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
			wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
			MessageBox(NULL, pDisplayBuf, "Error", MB_OK); 
			return;
		}

		SetWindowLong (getHandle (), GWL_USERDATA, static_cast <LONG> (reinterpret_cast <ULONG_PTR> (this)));

		ShowWindow(m_hWnd, SW_SHOWNORMAL);

		m_hFont = CreateFont(8, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "MS Sans Serif");
		LRESULT l = SendMessage (getHandle (), WM_SETFONT, (WPARAM)m_hFont, TRUE);
	}

	gswidget::gswidget (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &ptitle, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent)
	{
		m_iId = id;
		if (m_bInitCommonControls)
		{
			INITCOMMONCONTROLSEX cc;
			cc.dwSize = sizeof (INITCOMMONCONTROLSEX);
			cc.dwICC = ICC_TAB_CLASSES|ICC_PROGRESS_CLASS;
			if (!InitCommonControlsEx (&cc))
				MessageBox (NULL, "unable to init common controls", "msg", MB_OK);

			m_bInitCommonControls = false;
		}

		if (parent)
			m_hInst = parent->getInst ();
		else
			m_hInst = GetModuleHandle (NULL);

		HWND hParent = NULL;
		if (parent)
			hParent = parent->getHandle ();
		m_pParent = parent;

		m_strClass = pclass;
		m_strTitle = ptitle;

		m_iWidth = w;
		m_iHeight = h;

		m_iX = x;
		m_iY = y;


		m_hWnd = CreateWindowEx (exStyle, pclass.str (), ptitle.str (), style, x, y, w, h, hParent, NULL, m_hInst, NULL);
		if (!m_hWnd)
		{
			char *pMsgBuf;
			char *pDisplayBuf;
			DWORD dw = GetLastError(); 

			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
				NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &pMsgBuf,	0, NULL );

			pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
			wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
			MessageBox(NULL, pDisplayBuf, "Error", MB_OK); 
			return;
		}

		SetWindowLong (getHandle (), GWL_USERDATA, static_cast <LONG> (reinterpret_cast <ULONG_PTR> (this)));

		ShowWindow(m_hWnd, SW_SHOWNORMAL);

		m_hFont = CreateFont(8, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "MS Sans Serif");
		LRESULT l = SendMessage (getHandle (), WM_SETFONT, (WPARAM)m_hFont, TRUE);
	}

#else
	gswidget::gswidget (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent)
	{
		m_iWidth = w;
		m_iHeight = h;

		m_iX = x;
		m_iY = y;

		int argc = 0;
		char **argv;

		XInitThreads ();
		XtToolkitInitialize ();
		Arg args[2];
		XtSetArg (args[0], XtNwidth, w);
		XtSetArg (args[1], XtNheight, h);
		m_Context = XtCreateApplicationContext ();
		m_display = XtOpenDisplay (m_Context, NULL, title.str (), pclass.str (), NULL, 0, &argc, argv);
		XtDisplayInitialize (m_Context, m_display, title.str (), pclass.str (), NULL, 0, &argc, argv);
		m_Window = XtAppCreateShell (title.str (), pclass.str (), applicationShellWidgetClass, m_display, args, 2);

		XtRealizeWidget (m_Window);
	}
#endif

	gswidget::~gswidget ()
	{
#ifdef WIN32
		if (m_hWnd != NULL)
			DestroyWindow (m_hWnd);
		m_hWnd = NULL;

		if (m_bUnregister)
			UnregisterClass (getClass ().str (), getInst ());
#endif
	}

	void gswidget::resize (const int &x, const int &y, const int &w, const int &h)
	{
		setX (x); setY (y); setWidth (w); setHeight (h);
#ifdef WIN32
		MoveWindow (getHandle (), x, y, w, h, true);
		UpdateWindow (getHandle ());
#endif
	}

	void gswidget::show ()
	{
#ifdef WIN32
		ShowWindow (m_hWnd, SW_SHOW);
		UpdateWindow (m_hWnd);
#endif

		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
			m_ChildWindows[x]->show ();
	}

	void gswidget::hide ()
	{
#ifdef WIN32
		ShowWindow (m_hWnd, SW_HIDE);
#endif

		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
			m_ChildWindows[x]->hide ();
	}

	void gswidget::setTitle (const gsutil::gsstring &title)
	{
#ifdef WIN32
		if (SetWindowText (getHandle (), title.str ()))
			m_strTitle = title;
#endif
	}

	void gswidget::onClose ()
	{ 
#ifdef WIN32 
		DestroyWindow (getHandle ());
#endif
	}

	gswidget *gswidget::find (const int &id)
	{
		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		{
			if (id == m_ChildWindows[x]->getId ())
				return m_ChildWindows[x];
			else
			{
				gswidget *w = m_ChildWindows[x]->find (id);
				if (w)
					return w;
			}
		}

		//couldn't find widget
		return NULL;
	}

	gswidget *gswidget::find (void *handle)
	{
		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		{
			if (handle == m_ChildWindows[x]->getHandle ())
				return m_ChildWindows[x];
			else
			{
				gswidget *w = m_ChildWindows[x]->find (handle);
				if (w)
					return w;
			}
		}

		//couldn't find widget
		return NULL;
	}
};
