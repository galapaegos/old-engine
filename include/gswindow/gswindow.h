#ifndef _gswindow_h_
#define _gswindow_h_

#ifdef WIN32
#include <windows.h>
#include <commdlg.h>
#include <commctrl.h>
#else
#include <X11/Xlib.h>
#include <Xm/XmAll.h>
#endif

#include <stdio.h>
#include "gsmain.h"
#include "gsmenu.h"

namespace gswin
{
	class GS gswindow : public gsmain
	{
	public:
		gswindow (unsigned long exStyle=0, const gsutil::gsstring &pclass="Galapaegos3D", const gsutil::gsstring &title="Title", unsigned long style=gsWINDOW_OVERLAPPEDWINDOW, const int &id=-1, const int &x=0, const int &y=0, const int &w=800, const int &h=600);
		virtual ~gswindow ();

		virtual void onCommand (void *wParam, void *lParam) {}
		virtual void onClose ();
		virtual void onDestroy () {}
		virtual void onKeyDown (void *wParam, void *lParam);
		virtual void onPaint ();
		virtual void onSize (void *wParam, void *lParam) {}
		virtual void handle ();
		virtual void process ();
		virtual void setMenu (gswin::gsmenu *m);

	protected:
#ifdef WIN32
		MSG m_message;
#endif

		int m_iRun;
	};
};

#endif
