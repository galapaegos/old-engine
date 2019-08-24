#ifndef _gstoolsprimitives_h_
#define _gstoolsprimitives_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gsglobalconfig.h"
#include "gsutil/gsqueue.h"

namespace gs
{
	class gstoolsprimitives : public gswindow
	{
	public:
		gstoolsprimitives (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolsprimitives ();

		virtual void onCommand (WPARAM wParam, LPARAM lParam);
		virtual void onDestroy ();
		virtual void onPaint ();
		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsPrimitivesWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
		gsqueue <gsbutton*> m_PrimitiveList;
	};
};

#endif