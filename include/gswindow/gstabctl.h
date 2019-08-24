#ifndef _gstabctl_h_
#define _gstabctl_h_

#include "gscontrol.h"

namespace gswin
{
	class gstabctl : public gscontrol
	{
	public:
		gstabctl (gswidget *parent, DWORD exStyle, const gsutil::gsstring &title, DWORD style, const int &id=-1, const int &x=0, const int &y=0, const int &w=0, const int &h=0);
		virtual ~gstabctl ();

		virtual void onNotify (void *wParam, void *lParam);
		virtual void add (gswidget *w);

		virtual void show ();
		
	private:
		int m_iCurrentTab;
	};
};

#endif
