#ifndef _gsnewworld_h_
#define _gsnewworld_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gslistbox.h"

namespace gs
{
	class gsnewworld : public gswindow
	{
	public:
		gsnewworld (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsnewworld ();

		static LRESULT wndprocNewWorld (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
};

#endif