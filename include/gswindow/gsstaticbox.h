#ifndef _gsstaticbox_h_
#define _gsstaticbox_h_

#include <gswindow/gsbutton.h>

namespace gswin
{
	class gsstaticbox : public gswin::gsbutton
	{
	public:
		gsstaticbox (gswidget *parent, const gsutil::gsstring &title="",
			const int &x=0, const int &y=0, const int &w=0, const int &h=0);
		~gsstaticbox ();

		virtual void getDefaultSize (int *w, int *h);

	private:
	};
};

#endif
