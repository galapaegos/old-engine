#ifndef _gsstatusbar_h_
#define _gsstatusbar_h_

#include "gswindow/gscontrol.h"

namespace gswin
{
	class gsstatusbar : public gscontrol
	{
	public:
		gsstatusbar (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		~gsstatusbar ();
	};
};

#endif
