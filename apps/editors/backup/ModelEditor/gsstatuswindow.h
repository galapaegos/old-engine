#ifndef _gsstatuswindow_h_
#define _gsstatuswindow_h_

#include "gstabctl.h"
#include "gsstatustabctl.h"
#include "galapaegos/gskernel.h"

namespace gs
{
	class gsstatuswindow : public gswindow
	{
	public:
		gsstatuswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsstatuswindow ();

		virtual void onNotify (LPARAM lParam);
		
		static LRESULT CALLBACK gsstatusWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
		LONG m_callback;

		gsstatustabctl *tabctl;
	};
};

#endif