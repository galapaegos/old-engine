#ifndef _gstoolstabctl_h_
#define _gstoolstabctl_h_

#include "gstabctl.h"
#include "gstoolseffect.h"
#include "gstoolslighting.h"
#include "gstoolsobjects.h"
#include "gstoolsprimitives.h"
#include "gstoolsshaders.h"
#include "gstoolsterrain.h"
#include "gstoolstexturing.h"
#include "galapaegos/gskernel.h"

namespace gs
{
	class gstoolstabctl : public gswindow
	{
	public:
		gstoolstabctl (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolstabctl ();
		
		static LRESULT CALLBACK gstoolsTabCtlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
		void show (int x) { m_ChildWindows[x]->show (); }
		void hide (int x) { m_ChildWindows[x]->hide (); }
		int numChildren () { return m_ChildWindows.getSize (); }

		LONG m_Callback;
	};
};

#endif