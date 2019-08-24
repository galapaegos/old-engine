#include "gswindow/gstextbox.h"

namespace gswin
{
	gstextbox::gstextbox (gswidget *parent, const gsutil::gsstring &windowTitle, unsigned long style, const int &id, 
		const int &x, const int &y, const int &w, const int &h) : gscontrol (WS_EX_CLIENTEDGE, 
		"EDIT", windowTitle, style|gsWINDOW_CHILD|gsWINDOW_VISIBLE, id, x, y, w, h, parent)
	{
	}

	gstextbox::~gstextbox ()
	{
	}

	const gsutil::gsstring gstextbox::getText ()
	{
		int count = GetWindowTextLength (getHandle ());
		char *buf = new char[count+1];
		int read = GetWindowText (getHandle (), buf, count + 1);

		gsutil::gsstring temp = buf;
		delete buf;
		return temp;
	}
};
