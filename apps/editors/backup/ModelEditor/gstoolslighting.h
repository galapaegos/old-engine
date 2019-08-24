#ifndef _gstoolslighting_h_
#define _gstoolslighting_h_

#include "gstabpanel.h"
#include "gsbutton.h"
#include "gsgroup.h"

namespace gs
{
	class gstoolslighting : public gstabpanel
	{
	public:
		gstoolslighting (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolslighting ();

		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsLightingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
	};
};

#endif