#ifndef _gsip_h_
#define _gsip_h_

#include "gswindow/gscontrol.h"

namespace gswin
{
#ifdef WIN32
#define gsIP_IPADDRESS WC_IPADDRESS
#endif
	class gsip : public gscontrol
	{
	public:
		gsip (gswidget *parent, unsigned long exStyle, const gsutil::gsstring &title="", unsigned long style=0, const int &id=-1, const int &x=0, const int &y=0, const int &w=0, const int &h=0);
		~gsip ();
	};
};

#endif
