#include "gstabpanel.h"

namespace gs
{
	gstabpanel::gstabpanel (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance, void *proc) :
	gswindow (exStyle, pclass, ptitle, style, x, y, w, h, hParent, hInstance, proc)
	{
	}
	
	gstabpanel::~gstabpanel ()
	{
	}
};