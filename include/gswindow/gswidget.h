#ifndef _gswidget_h_
#define _gswidget_h_

#ifdef WIN32
#include <windows.h>
#include <windowsX.h>
#include <commdlg.h>
#include <commctrl.h>
#else
#include <X11/Xlib.h>
#include <Xm/XmAll.h>
#include <GL/GLwDrawA.h>
#endif

#include <stdio.h>
#include <gsutil/gsqueue.h>
#include <gsutil/gsstring.h>

namespace gswin
{
	enum
	{
#ifdef WIN32
		gsWINDOW_EX_ACCEPTFILES = WS_EX_ACCEPTFILES,
		gsWINDOW_EX_APPWINDOW = WS_EX_APPWINDOW,
		gsWINDOW_EX_CLIENTEDGE = WS_EX_CLIENTEDGE,
		//gsWINDOW_EX_COMPOSITED = WS_EX_COMPOSITED,
		gsWINDOW_EX_CONTEXTHELP = WS_EX_CONTEXTHELP,
		gsWINDOW_EX_CONTROLPARENT = WS_EX_CONTROLPARENT,
		gsWINDOW_EX_DLGMODALFRAME = WS_EX_DLGMODALFRAME,
		//gsWINDOW_EX_LAYERED = WS_EX_LAYERED,
		//gsWINDOW_EX_LAYOUTRTL = WS_EX_LAYOUTRTL,
		gsWINDOW_EX_LEFT = WS_EX_LEFT,
		gsWINDOW_EX_LEFTSCROLLBAR = WS_EX_LEFTSCROLLBAR,
		gsWINDOW_EX_LTRREADING = WS_EX_LTRREADING,
		gsWINDOW_EX_MDICHILD = WS_EX_MDICHILD,
		//gsWINDOW_EX_NOACTIVATE = WS_EX_NOACTIVATE,
		//gsWINDOW_EX_NOINHERITLAYOUT = WS_EX_NOINHERITLAYOUT,
		gsWINDOW_EX_NOPARENTNOTIFY = WS_EX_NOPARENTNOTIFY,
		gsWINDOW_EX_OVERLAPPEDWINDOW = WS_EX_OVERLAPPEDWINDOW,
		gsWINDOW_EX_PALETTEWINDOW = WS_EX_PALETTEWINDOW,
		gsWINDOW_EX_RIGHT = WS_EX_RIGHT,
		gsWINDOW_EX_RIGHSCROLLBAR = WS_EX_RIGHTSCROLLBAR,
		gsWINDOW_EX_RTLREADING = WS_EX_RTLREADING,
		gsWINDOW_EX_STATICEDGE = WS_EX_STATICEDGE,
		gsWINDOW_EX_TOOLWINDOW = WS_EX_TOOLWINDOW,
		gsWINDOW_EX_TOPMOST = WS_EX_TOPMOST,
		gsWINDOW_EX_TRANSPARENT = WS_EX_TRANSPARENT,
		gsWINDOW_EX_WINDOWEDGE = WS_EX_WINDOWEDGE,

		gsWINDOW_BORDER = WS_BORDER,
		gsWINDOW_CAPTION = WS_CAPTION,
		gsWINDOW_CHILD = WS_CHILD,
		gsWINDOW_CHILDWINDOW = WS_CHILDWINDOW,
		gsWINDOW_CLIPCHILDREN = WS_CLIPCHILDREN,
		gsWINDOW_CLIPSLIBLINGS = WS_CLIPSIBLINGS,
		gsWINDOW_DISABLED = WS_DISABLED,
		gsWINDOW_DLGFRAME = WS_DLGFRAME,
		gsWINDOW_GROUP = WS_GROUP,
		gsWINDOW_HSCROLL = WS_HSCROLL,
		gsWINDOW_ICONIC = WS_ICONIC,
		gsWINDOW_MAXIMIZE = WS_MAXIMIZE,
		gsWINDOW_MAXIMIZEBOX = WS_MAXIMIZEBOX,
		gsWINDOW_MINIMIZE = WS_MINIMIZE,
		gsWINDOW_MINIMIZEBOX = WS_MINIMIZEBOX,
		gsWINDOW_OVERLAPPED = WS_OVERLAPPED,
		gsWINDOW_OVERLAPPEDWINDOW = WS_OVERLAPPEDWINDOW,
		gsWINDOW_POPUP = WS_POPUP,
		gsWINDOW_POPUPWINDOW = WS_POPUPWINDOW,
		gsWINDOW_SIZEBOX = WS_SIZEBOX,
		gsWINDOW_SYSMENU = WS_SYSMENU,
		gsWINDOW_TABSTOP = WS_TABSTOP,
		gsWINDOW_THICKFRAME = WS_THICKFRAME,
		gsWINDOW_TILED = WS_TILED,
		gsWINDOW_TILEDWINDOW = WS_TILEDWINDOW,
		gsWINDOW_VISIBLE = WS_VISIBLE,
		gsWINDOW_VSCROLL = WS_VSCROLL
#else
		gsWINDOW_EX_ACCEPTFILES,
		gsWINDOW_EX_APPWINDOW,
		gsWINDOW_EX_CLIENTEDGE,
		//gsWINDOW_EX_COMPOSITED = WS_EX_COMPOSITED,
		gsWINDOW_EX_CONTEXTHELP,
		gsWINDOW_EX_CONTROLPARENT,
		gsWINDOW_EX_DLGMODALFRAME,
		//gsWINDOW_EX_LAYERED = WS_EX_LAYERED,
		gsWINDOW_EX_LAYOUTRTL,
		gsWINDOW_EX_LEFT,
		gsWINDOW_EX_LEFTSCROLLBAR,
		gsWINDOW_EX_LTRREADING,
		gsWINDOW_EX_MDICHILD,
		//gsWINDOW_EX_NOACTIVATE = WS_EX_NOACTIVATE,
		gsWINDOW_EX_NOINHERITLAYOUT,
		gsWINDOW_EX_NOPARENTNOTIFY,
		gsWINDOW_EX_OVERLAPPEDWINDOW,
		gsWINDOW_EX_PALETTEWINDOW,
		gsWINDOW_EX_RIGHT,
		gsWINDOW_EX_RIGHSCROLLBAR,
		gsWINDOW_EX_RTLREADING,
		gsWINDOW_EX_STATICEDGE,
		gsWINDOW_EX_TOOLWINDOW,
		gsWINDOW_EX_TOPMOST,
		gsWINDOW_EX_TRANSPARENT,
		gsWINDOW_EX_WINDOWEDGE,

		gsWINDOW_BORDER,
		gsWINDOW_CAPTION,
		gsWINDOW_CHILD,
		gsWINDOW_CHILDWINDOW,
		gsWINDOW_CLIPCHILDREN,
		gsWINDOW_CLIPSLIBLINGS,
		gsWINDOW_DISABLED,
		gsWINDOW_DLGFRAME,
		gsWINDOW_GROUP,
		gsWINDOW_HSCROLL,
		gsWINDOW_ICONIC,
		gsWINDOW_MAXIMIZE,
		gsWINDOW_MAXIMIZEBOX,
		gsWINDOW_MINIMIZE,
		gsWINDOW_MINIMIZEBOX,
		gsWINDOW_OVERLAPPED,
		gsWINDOW_OVERLAPPEDWINDOW,
		gsWINDOW_POPUP,
		gsWINDOW_POPUPWINDOW,
		gsWINDOW_SIZEBOX,
		gsWINDOW_SYSMENU,
		gsWINDOW_TABSTOP,
		gsWINDOW_THICKFRAME,
		gsWINDOW_TILED,
		gsWINDOW_TILEDWINDOW,
		gsWINDOW_VISIBLE,
		gsWINDOW_VSCROLL
#endif
	};

	class GS gswidget
	{
	public:
		// All windows need to inherit these guys
		gswidget (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		gswidget (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent, void *WndProc);
		virtual ~gswidget ();

		void setWidth (const int &w) { m_iWidth = w; }
		int getWidth () { return m_iWidth; }
		void setHeight (const int &h) { m_iHeight = h; }
		int getHeight () { return m_iHeight; }

		void setX (const int &x) { m_iX = x; }
		int getX () { return m_iX; }
		void setY (const int &y) { m_iY = y; }
		int getY () { return m_iY; }

		gsutil::gsstring &getClass () { return m_strClass; }
		gsutil::gsstring &getTitle () { return m_strTitle; }

		int getId () { return m_iId; }

		virtual void setTitle (const gsutil::gsstring &title);

		virtual int getAreaWidth ()
		{
#ifdef WIN32
			RECT r; GetClientRect (getHandle (), &r); return (r.right - r.left);
#else
			return 0;
#endif
		}
		virtual int getAreaHeight ()
		{
#ifdef WIN32
			RECT r; GetClientRect (getHandle (), &r); return (r.bottom - r.top);
#else
			return 0;
#endif
		}

		virtual int getResizeW () { return 0; }
		virtual int getResizeH () { return 0; }

		virtual void resize (const int &x, const int &y, const int &w, const int &h);

		gswidget *find (const int &id);
		gswidget *find (void *handle);

		virtual void add (gswidget *w) { m_ChildWindows.add (w); }

		gswidget *getParent () { return m_pParent; }

		virtual void getDefaultSize (int *w, int *h) { *w = 0; *h = 0; }

#ifdef WIN32
		HWND getHandle () { return m_hWnd; }
		virtual HINSTANCE getInst () { return m_hInst; }
#else
		Widget getHandle () { return m_Window; }
		XtAppContext getInst () { return m_Context; }
		Display *getDisplay () { return m_display; }
#endif

		virtual void show ();
		virtual void hide ();

		virtual void handle () {}
		virtual void onClose ();

		virtual void onCommand (void *wParam, void *lParam) {}
		virtual void onDestroy () {}
		virtual void onKeyDown (void *wParam, void *lParam) {}
		virtual void onMouseMove (void *wParam, void *lParam) {}
		virtual void onMouseWheel (void *wParam, void *lParam) {}
		virtual void onMouseLeftDown (void *wParam, void *lParam) {}
		virtual void onMouseMiddleDown (void *wParam, void *lParam) {}
		virtual void onMouseRightDown (void *wParam, void *lParam) {}
		virtual void onMouseLeftUp (void *wParam, void *lParam) {}
		virtual void onMouseMiddleUp (void *wParam, void *lParam) {}
		virtual void onMouseRightUp (void *wParam, void *lParam) {}
		virtual void onNotify (void *wParam, void *lParam) { for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++) m_ChildWindows[x]->onNotify (wParam, lParam); }
		virtual void onPaint () {}

	protected:
		gswidget *m_pParent;
		gsutil::gsqueue<gswidget*> m_ChildWindows;

#ifdef WIN32
		HWND m_hWnd;
		HINSTANCE m_hInst;
		HFONT m_hFont;
		bool m_bUnregister;
		static bool m_bInitCommonControls;
#else
		XtAppContext m_Context;
		Widget m_Window;
		Display *m_display;
#endif

		int m_iWidth;
		int m_iHeight;

		int m_iX;
		int m_iY;

		gsutil::gsstring m_strClass;
		gsutil::gsstring m_strTitle;

	private:
		int m_iId;
	};
};

#endif
