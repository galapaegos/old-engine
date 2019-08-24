#ifndef _gstextbox_h_
#define _gstextbox_h_

#include "gscontrol.h"

namespace gswin
{
	enum
	{
		gsTEXT_AUTOHSCROLL = ES_AUTOHSCROLL,
		gsTEXT_AUTOVSCROLL = ES_AUTOVSCROLL,
		gsTEXT_CENTER = ES_CENTER,
		gsTEXT_LEFT = ES_LEFT,
		gsTEXT_LOWERCASE = ES_LOWERCASE,
		gsTEXT_MULTILINE = ES_MULTILINE,
		gsTEXT_NOHIDESEL = ES_NOHIDESEL,
		gsTEXT_NUMBER = ES_NUMBER,
		gsTEXT_OEMCONVERT = ES_OEMCONVERT,
		gsTEXT_PASSWORD = ES_PASSWORD,
		gsTEXT_READONLY = ES_READONLY,
		gsTEXT_UPPERCASE = ES_UPPERCASE,
		gsTEXT_WANTRETURN = ES_WANTRETURN
	};

	class gstextbox : public gscontrol
	{
	public:
		gstextbox (gswidget *parent, const gsutil::gsstring &windowTitle="", 
			unsigned long style=gsTEXT_LEFT, const int &id=-1, const int &x=0, const int &y=0, 
			const int &w=0, const int &h=0);
		virtual ~gstextbox ();

		const gsutil::gsstring getText ();

		virtual void getDefaultSize (int *w, int *h) { *w = 80; *h = 20; }
	};
};

#endif
