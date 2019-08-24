#ifndef _gstabpanel_h_
#define _gstabpanel_h_

#include "gswindow.h"

namespace gs
{
	class gstabpanel : public gswindow
	{
	public:
		gstabpanel (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance, void *proc);
		~gstabpanel ();
	};
};

#endif