#ifndef _gsrebar_h_
#define _gsrebar_h_

#include "gswindow/gscontrol.h"

namespace gswin
{
	class gsrebar : gscontrol
	{
	public:
		gsrebar (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		~gsrebar ();
	};
};

#endif
