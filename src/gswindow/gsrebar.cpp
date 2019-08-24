#include "gswindow/gsrebar.h"

namespace gswin
{
	gsrebar::gsrebar (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, 
		const int &w, const int &h, gswidget *parent) : gscontrol (exStyle, REBARCLASSNAME, title, style, id, x, y, w, h, parent)
	{
	}

	gsrebar::~gsrebar ()
	{
	}
};
