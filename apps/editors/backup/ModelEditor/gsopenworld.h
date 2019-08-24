#ifndef _gsopenworld_h_
#define _gsopenworld_h_

#include "gswindow.h"

namespace gs
{
	class gsopenworld : public gswindow
	{
	public:
		gsopenworld (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsopenworld ();
	};
};

#endif