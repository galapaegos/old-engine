#ifndef _gsdescription_h_
#define _gsdescription_h_

#include "gswindow.h"

namespace gs
{
	class gsdescription : public gswindow
	{
	public:
		gsdescription (const char *title, 
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsdescription ();

		static LRESULT CALLBACK gsdescriptionWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		LONG m_Callback;
	};
};

#endif