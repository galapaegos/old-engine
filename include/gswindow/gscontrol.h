#ifndef _gscontrol_h_
#define _gscontrol_h_

#include <gswindow/gswidget.h>

namespace gswin
{
	class GS gscontrol : public gswidget
	{
	public:
		gscontrol (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		virtual ~gscontrol ();

		static LRESULT gscontrolWinProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		LONG m_Callback;
	};
};

#endif
