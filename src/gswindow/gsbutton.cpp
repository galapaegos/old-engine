#include "gswindow/gsbutton.h"

namespace gswin
{
	gsbutton::gsbutton (gswidget *parent, const gsutil::gsstring &title, unsigned long style, const int &id,
		const int &x, const int &y, const int &w, const int &h) : gscontrol (0, "BUTTON", 
		title, gsWINDOW_CHILD|gsWINDOW_VISIBLE|style, id, x, y, w, h, parent)
	{
	}

	gsbutton::~gsbutton ()
	{
	}
};
