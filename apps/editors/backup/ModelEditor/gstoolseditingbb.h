#ifndef _gstoolseditingbb_h_
#define _gstoolseditingbb_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gslistbox.h"

namespace gs
{
	class gstoolseditingbb : public gswindow
	{
	public:
		gstoolseditingbb (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInst);
		~gstoolseditingbb ();

		void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsEditingBBWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
	};
};

#endif