#ifndef _gstoolswindow_h_
#define _gstoolswindow_h_

#include "gstabctl.h"
#include "gstoolseffect.h"
#include "gstoolslighting.h"
#include "gstoolsobjects.h"
#include "gstoolsprimitives.h"
#include "gstoolsshaders.h"
#include "gstoolsterrain.h"
#include "gstoolstexturing.h"
#include "gstoolstabctl.h"
#include "galapaegos/gskernel.h"

namespace gs
{
	class gstoolswindow : public gswindow
	{
	public:
		gstoolswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolswindow ();

		virtual void onNotify (LPARAM lParam);
		
		static LRESULT CALLBACK gstoolsWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		
		LONG m_Callback;

	private:
		gstoolstabctl *tabctl;
		gskernel *m_pKernel;
	};
};

#endif