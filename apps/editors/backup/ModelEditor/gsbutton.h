#ifndef _gsbutton_h_
#define _gsbutton_h_

#include "gswindow.h"

namespace gs
{
	class gsbutton : public gswindow
	{
	public:
		gsbutton (const char *title, 
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsbutton ();

		static LRESULT CALLBACK gsbuttonWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		LONG m_Callback;
	};
};

#endif