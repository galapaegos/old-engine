#ifndef _gstoolsobjects_h_
#define _gstoolsobjects_h_

#include "gstabpanel.h"
#include "gsbutton.h"
#include "gsgroup.h"

namespace gs
{
	class gstoolsobjects : public gstabpanel
	{
	public:
		gstoolsobjects (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolsobjects ();

		static LRESULT CALLBACK gstoolsObjectsWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
	};
};

#endif