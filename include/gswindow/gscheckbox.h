#ifndef _gscheckbox_h_
#define _gscheckbox_h_

#include "gsbutton.h"

namespace gswin
{
	#define gsBUTTON_3STATE BS_3STATE
	#define gsBUTTON_AUTO3STATE BS_AUTO3STATE
	#define gsBUTTON_AUTOCHECKBOX BS_AUTOCHECKBOX
	#define gsBUTTON_CHECKBOX BS_CHECKBOX

	class GS gscheckbox : public gsbutton
	{
	public:
		gscheckbox (gswidget *parent, const gsutil::gsstring &title="", unsigned long style=gsBUTTON_CHECKBOX, 
			const int &id=-1, const int x=0, const int y=0, const int w=0, const int h=0);
		~gscheckbox ();

		void check ();
		void uncheck ();

		void toggle ();

		bool getStatus ();
		virtual void getDefaultSize (int *w, int *h) { *w = 80; *h = 20; }


	private:
		bool m_bCheck;
	};
};

#endif
