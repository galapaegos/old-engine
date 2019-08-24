#include "gswindow/gstogglebutton.h"

namespace gswin
{
	gstogglebutton::gstogglebutton (gswidget *parent, const gsutil::gsstring &title, const int &id, const int &x, const int &y, const int &w, const int &h) :
		gswin::gsbutton (parent, title, gsBUTTON_DEFPUSHBUTTON, id, x, y, w, h)
	{
	}

	gstogglebutton::~gstogglebutton ()
	{
	}
};
