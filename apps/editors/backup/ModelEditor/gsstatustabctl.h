#ifndef _gsstatusstabctl_h_
#define _gsstatusstabctl_h_

#include "gstabctl.h"
#include "galapaegos/gskernel.h"

namespace gs
{
	class gsstatustabctl : public gswindow
	{
	public:
		gsstatustabctl (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsstatustabctl ();
		
		static LRESULT CALLBACK gsstatusTabCtlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
		void show (int x) { m_ChildWindows[x]->show (); }
		void hide (int x) { m_ChildWindows[x]->hide (); }
		int numChildren () { return m_ChildWindows.getSize (); }

		LONG m_Callback;
	};
};

#endif