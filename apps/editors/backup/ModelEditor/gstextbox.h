#ifndef _gstextbox_h_
#define _gstextbox_h_

#include "gswindow.h"

namespace gs
{
	class gstextbox : public gswindow
	{
	public:
		gstextbox (const char *title, 
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstextbox ();

		const gsstring getText ();

		static LRESULT CALLBACK gstextboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		LONG m_Callback;
	};
};

#endif