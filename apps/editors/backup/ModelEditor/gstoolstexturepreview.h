#ifndef _gstoolstexturepreview_h_
#define _gstoolstexturepreview_h_

#include "gswindow.h"

namespace gs
{
	class gstoolstexturepreview : public gswindow
	{
	public:
		gstoolstexturepreview (const gsstring &name, const int x, const int y, 
			const int w, const int h, HWND hParent, HINSTANCE hInst, HBITMAP hBit);
		~gstoolstexturepreview ();

		void onPaint ();

		static LRESULT CALLBACK gstoolsTexturingPreviewWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		HBITMAP m_hBitmap;
	};
};

#endif