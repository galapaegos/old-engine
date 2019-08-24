#ifndef _gstoolstexturing_h_
#define _gstoolstexturing_h_

#include "gsglobalconfig.h"

//#include <dirent.h>
#include "gstabpanel.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gslistbox.h"
#include "gstoolstexturepreview.h"

namespace gs
{
	class gstoolstexturing : public gswindow
	{
	public:
		gstoolstexturing (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolstexturing ();

		void onDestroy ();
		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsTexturingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
		gslistbox *m_pTextureList;
		gsbutton *m_pApplyTexturing;
		gsbutton *m_pPreview;
	};
};

#endif