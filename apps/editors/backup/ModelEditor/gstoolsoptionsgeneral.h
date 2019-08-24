#ifndef _gstoolsoptionsgeneral_h_
#define _gstoolsoptionsgeneral_h_

#include "gsdescription.h"
#include "gstabpanel.h"

namespace gs
{
	class gstoolsoptionsgeneral : public gstabpanel
	{
	public:
		gstoolsoptionsgeneral (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInstance);
		~gstoolsoptionsgeneral ();

		static LRESULT CALLBACK gstoolsoptionsgeneralWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
};

#endif