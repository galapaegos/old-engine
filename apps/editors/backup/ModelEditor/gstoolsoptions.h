#ifndef _gstoolsoptions_h_
#define _gstoolsoptions_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsdescription.h"
#include "gstextbox.h"
#include "gstabctl.h"

#include "gstoolsoptionsctl.h"

namespace gs
{
	class gstoolsoptions : public gswindow
	{
	public:
		gstoolsoptions (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolsoptions ();

		void onDestroy ();
		void onKeyDown (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsoptionsWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		gstoolsoptionsctl *m_pTabCtl;
	};
};

#endif