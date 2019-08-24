#ifndef _gstabctl_h_
#define _gstabctl_h_

#include "gswindow.h"

namespace gs
{
	class gstabctl : public gswindow
	{
	public:
		gstabctl (DWORD exStyle, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstabctl ();

		static LRESULT CALLBACK gstabctlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		LONG m_Callback;
	};
};

#endif