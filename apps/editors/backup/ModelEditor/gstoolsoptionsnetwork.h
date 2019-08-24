#ifndef _gstoolsoptionsnetwork_h_
#define _gstoolsoptionsnetwork_h_

#include "gstabpanel.h"

namespace gs
{
	class gstoolsoptionsnetwork : public gstabpanel
	{
	public:
		gstoolsoptionsnetwork (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInstance);
		~gstoolsoptionsnetwork ();

		static LRESULT CALLBACK gstoolsoptionsnetworkWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
};

#endif