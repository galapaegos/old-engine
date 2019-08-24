#ifndef _gsbutton_h_
#define _gsbutton_h_

#include "gscontrol.h"

namespace gswin
{
	#define gsBUTTON_AUTORADIOBUTTON BS_AUTORADIOBUTTON
	#define gsBUTTON_DEFPUSHBUTTON BS_DEFPUSHBUTTON
	#define gsBUTTON_GROUPBOX BS_GROUPBOX
	#define gsBUTTON_LEFTTEXT BS_LEFTTEXT
	#define gsBUTTON_OWNERDRAW BS_OWNERDRAW
	#define gsBUTTON_PUSHBUTTON BS_PUSHBUTTON
	#define gsBUTTON_RADIOBUTTON BS_RADIOBUTTON
	#define gsBUTTON_USERBUTTON BS_USERBUTTON
	#define gsBUTTON_BITMAP BS_BITMAP
	#define gsBUTTON_BOTTOM BS_BOTTOM
	#define gsBUTTON_CENTER BS_CENTER
	#define gsBUTTON_ICON BS_ICON
	#define gsBUTTON_FLAT BS_FLAT
	#define gsBUTTON_LEFT BS_LEFT
	#define gsBUTTON_MULTILINE BS_MULTILINE
	#define gsBUTTON_NOTIFY BS_NOTIFY
	#define gsBUTTON_PUSHLIKE BS_PUSHLIKE
	#define gsBUTTON_RIGHT BS_RIGHT
	#define gsBUTTON_RIGHTBUTTON BS_RIGHTBUTTON
	#define gsBUTTON_TEXT BS_TEXT
	#define gsBUTTON_TOP BS_TOP
	#define gsBUTTON_TYPEMASK BS_TYPEMASK
	#define gsBUTTON_VCENTER BS_VCENTER
	//gsBUTTON_SPLITBUTTON = BS_SPLITBUTTON,
	//gsBUTTON_DEFSPLITBUTTON = BS_DEFSPLITBUTTON,
	//gsBUTTON_COMMANDLINK = BS_COMMANDLINK,
	//gsBUTTON_DEFCOMMANDLINK = BS_DEFCOMMANDLINK

	class GS gsbutton : public gscontrol
	{
	public:
		gsbutton (gswidget *parent, const gsutil::gsstring &title="", unsigned long style=BS_DEFPUSHBUTTON, 
			const int &id=-1, const int &x=0, const int &y=0, const int &w=0, const int &h=0);
		virtual ~gsbutton ();

		virtual void getDefaultSize (int *w, int *h) { *w = 80; *h = 20; }
	};
};

#endif
