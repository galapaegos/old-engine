#include "gswindow/gsstatusbar.h"

namespace gswin
{
	gsstatusbar::gsstatusbar (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, 
		const int &w, const int &h, gswidget *parent) : gscontrol (exStyle, STATUSCLASSNAME, title, style, id, x, y, w, h, parent)
	{
	}
	
	gsstatusbar::~gsstatusbar ()
	{
	}
};
