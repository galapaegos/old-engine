#ifndef _gsmainwindow_h_
#define _gsmainwindow_h_

#include "gswindow.h"
#include "gsmenu.h"
#include "gsabout.h"
#include "galapaegos/gskernel.h"
#include "galapaegos/gssceneloader.h"

#include "gsnewworld.h"
#include "gsopenworld.h"

namespace gs
{
	class gsmainwindow : public gswindow
	{
	public:
		gsmainwindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsmainwindow ();

		int m_iRun;
		
		static LRESULT CALLBACK gsmainWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
		virtual void onCommand (WPARAM wParam, LPARAM lParam);
		virtual void onCreate ();
		virtual void onDestroy ();
		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onPaint ();
		virtual void onShowWindow ();

	private:
		gsmenu *m_pMenu;
	};
};

#endif