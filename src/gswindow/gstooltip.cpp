#include "gswindow/gstooltip.h"

namespace gswin
{
	gstooltip::gstooltip (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, 
		const int &w, const int &h, gswidget *parent) : gscontrol (exStyle, TOOLTIPS_CLASS, title, style, id, x, y, w, h, parent)
	{
		SetWindowPos(getHandle (), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}

	gstooltip::~gstooltip ()
	{
	}
};
