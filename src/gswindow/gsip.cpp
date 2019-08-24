#include "gswindow/gsip.h"

namespace gswin
{
	gsip::gsip (gswidget *parent, unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id,
		const int &x, const int &y, const int &w, const int &h) : 
		gscontrol (exStyle, gsIP_IPADDRESS, title, style, id, x, y, w, h, parent)
	{
	}

	gsip::~gsip ()
	{
	}
};
