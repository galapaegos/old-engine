#ifndef _gsmain_h_
#define _gsmain_h_

#include "gswidget.h"

namespace gswin
{
	class GS gsmain : public gswidget
	{
	public:
		gsmain (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		virtual ~gsmain ();

#ifdef WIN32
		static LRESULT gsmainWinProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif
	};
};

#endif
