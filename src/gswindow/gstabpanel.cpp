#include "gswindow/gstabpanel.h"

namespace gswin
{
	gstabpanel::gstabpanel (unsigned long exStyle, const gsutil::gsstring &className, const gsutil::gsstring &windowTitle, 
		unsigned long style, const int &id, gswidget *parent) : gscontrol (exStyle, className, 
		windowTitle, style, id, 0, 0, 0, 0, parent)
	{
		//parent has to be a gstabctl, so its ok to do this:
		resize (2, 30, parent->getWidth () - 4, parent->getHeight () - 30);
	}
	
	gstabpanel::~gstabpanel ()
	{
	}
};
