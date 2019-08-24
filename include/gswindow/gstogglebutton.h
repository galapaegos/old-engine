#ifndef _gstogglebutton_h_
#define _gstogglebutton_h_

#include <gswindow/gsbutton.h>

namespace gswin
{
	class gstogglebutton : public gsbutton
	{
	public:
		gstogglebutton (gswidget *parent, const gsutil::gsstring &title="", const int &id=-1, const int &x=0, const int &y=0, const int &w=0, const int &h=0);
		~gstogglebutton ();
	};
};

#endif
