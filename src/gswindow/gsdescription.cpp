#include "gswindow/gsdescription.h"

namespace gswin
{
	gsdescription::gsdescription (gswidget *parent, const gsutil::gsstring &title, 
		const long &style, const int &id,const int &x, const int &y, const int &w, const int &h) : 
		gscontrol (0, "STATIC", title, gsWINDOW_CHILD|gsWINDOW_VISIBLE|style, id, x, y, w, h, parent)
	{
	}

	gsdescription::~gsdescription ()
	{
	}
};
