#ifndef _gstoolsshaders_h_
#define _gstoolsshaders_h_

#include "gstabpanel.h"
#include "gsbutton.h"
#include "gsgroup.h"

namespace gs
{
	class gstoolsshaders : public gstabpanel
	{
	public:
		gstoolsshaders (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolsshaders ();

		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsShadersWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
	};
};

#endif