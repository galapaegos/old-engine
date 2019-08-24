#ifndef _gsgroup_h_
#define _gsgroup_h_

#include "gswindow.h"

namespace gs
{
	class gsgroup : public gswindow
	{
	public:
		gsgroup (const char *pclass, const char *ptitle,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsgroup ();
		
		static LRESULT CALLBACK gsgroupWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		HWND m_hParent;
	};
};

#endif
