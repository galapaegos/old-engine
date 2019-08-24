#include "gsopenworld.h"

namespace gs
{
	gsopenworld::gsopenworld (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : gswindow (exStyle, pclass, ptitle, style, x, y, w, h,
			hParent, hInstance)
	{
	}

	gsopenworld::~gsopenworld ()
	{
	}
};