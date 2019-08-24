#ifndef _gsslider_h_
#define _gsslider_h_

#include <gswindow/gscontrol.h>

namespace gswin
{
	#define gsSLIDER_AUTOTICKS TBS_AUTOTICKS
	#define gsSLIDER_VERT TBS_VERT
	#define gsSLIDER_HORZ TBS_HORZ
	#define gsSLIDER_TOP TBS_TOP
	#define gsSLIDER_BOTTOM TBS_BOTTOM
	#define gsSLIDER_LEFT TBS_LEFT
	#define gsSLIDER_RIGHT TBS_RIGHT
	#define gsSLIDER_BOTH TBS_BOTH
	#define gsSLIDER_NOTICKS TBS_NOTICKS
	#define gsSLIDER_ENABLESELRANGE TBS_ENABLESELRANGE
	#define gsSLIDER_FIXEDLENGTH TBS_FIXEDLENGTH
	#define gsSLIDER_NOTHUMB TBS_NOTHUMB
	#define gsSLIDER_TOOLTIPS TBS_TOOLTIPS
	#define gsSLIDER_REVERSED TBS_REVERSED
	#define gsSLIDER_DOWNISLEFT TBS_DOWNISLEFT
	#define gsSLIDER_NOTIFYBEFOREMOVE TBS_NOTIFYBEFOREMOVE
	#define gsSLIDER_TRANSPARENTBKGND TBS_TRANSPARENTBKGND

	class gsslider : public gswin::gscontrol
	{
	public:
		gsslider (gswidget *parent, const gsutil::gsstring &title="", 
			unsigned long style=gsSLIDER_AUTOTICKS, const int &id=-1, const int &x=0, const int &y=0, 
			const int &w=0, const int &h=0);
		~gsslider ();

		void setRange (const int &min, const int &max);
		void setPosition (const int &pos);

		int getPosition ();
		int getRangeMin ();
		int getRangeMax ();

		virtual void getDefaultSize (int *w, int *h) { *w = 80; *h = 20; }
	};
};

#endif
