#ifndef _gstabpanel_h_
#define _gstabpanel_h_

#include "gscontrol.h"

namespace gswin
{
	class gstabpanel : public gscontrol
	{
	public:
		gstabpanel (unsigned long exStyle, const gsutil::gsstring &className, 
			const gsutil::gsstring &windowTitle, unsigned long style, const int &id, gswidget *parent);
		virtual ~gstabpanel ();
	};
};

#endif
