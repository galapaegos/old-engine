#include "test.h"

#include <shellapi.h>

class window : public gswin::gswindow
{
public:
	window () : gswindow (0, "window", "Test", 0, 0, 0, 250, 400)
	{
		gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);

		/*
		gsBUTTON_AUTORADIOBUTTON 
		gsBUTTON_DEFPUSHBUTTON 
		gsBUTTON_GROUPBOX 
		gsBUTTON_LEFTTEXT 
		#define gsBUTTON_OWNERDRAW 
		#define gsBUTTON_PUSHBUTTON 
		#define gsBUTTON_RADIOBUTTON 
		#define gsBUTTON_USERBUTTON 
		#define gsBUTTON_BITMAP 
		#define gsBUTTON_BOTTOM 
		#define gsBUTTON_CENTER 
		#define gsBUTTON_ICON 
		#define gsBUTTON_FLAT 
		#define gsBUTTON_LEFT 
		#define gsBUTTON_MULTILINE 
		#define gsBUTTON_NOTIFY 
		#define gsBUTTON_PUSHLIKE 
		#define gsBUTTON_RIGHT 
		#define gsBUTTON_RIGHTBUTTON 
		gsBUTTON_TEXT BS_TEXT
		gsBUTTON_TOP BS_TOP
		gsBUTTON_TYPEMASK BS_TYPEMASK
		gsBUTTON_VCENTER
		*/
		b->add (new gswin::gsbutton (b, "AutoRadioButton", gsBUTTON_AUTORADIOBUTTON));
		b->add (new gswin::gsbutton (b, "DefPushButton", gsBUTTON_DEFPUSHBUTTON));
		b->add (new gswin::gsbutton (b, "GroupBox", gsBUTTON_GROUPBOX));
		b->add (new gswin::gsbutton (b, "LeftText", gsBUTTON_LEFTTEXT));
		b->add (new gswin::gsbutton (b, "PushButton", gsBUTTON_PUSHBUTTON));
		b->add (new gswin::gsbutton (b, "Bottom", gsBUTTON_BOTTOM));
		b->add (new gswin::gsbutton (b, "Center", gsBUTTON_CENTER));
		b->add (new gswin::gsbutton (b, "Flat", gsBUTTON_FLAT));
		b->add (new gswin::gsbutton (b, "Multiline\nButton", gsBUTTON_MULTILINE));
		b->add (new gswin::gsbutton (b, "PushLike", gsBUTTON_PUSHLIKE));
		b->add (new gswin::gsbutton (b, "Right", gsBUTTON_RIGHT));
		b->add (new gswin::gsbutton (b, "RightButton", gsBUTTON_RIGHTBUTTON));
		b->add (new gswin::gsbutton (b, "Text", gsBUTTON_TEXT));
		b->add (new gswin::gsbutton (b, "Top", gsBUTTON_TOP));
		b->add (new gswin::gsbutton (b, "VCenter", gsBUTTON_VCENTER));
	}

	virtual ~window () {}

	virtual void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();
		}
	}

	virtual void onCommand (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;
	}

private:
};

int main (int argc, char *argv[])
{
	window *w = new window;

	w->handle ();

	return 0;
}
