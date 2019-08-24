#ifndef _gstooltip_h_
#define _gstooltip_h_

#include "gswindow/gscontrol.h"

namespace gswin
{
	class gstooltip : public gscontrol
	{
	public:
		gstooltip (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		~gstooltip ();
	};
};

#endif
