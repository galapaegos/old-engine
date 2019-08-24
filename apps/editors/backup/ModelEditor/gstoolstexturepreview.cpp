#include "gstoolstexturepreview.h"

namespace gs
{
	gstoolstexturepreview::gstoolstexturepreview (const gsstring &name, const int x, 
		const int y, const int w, const int h, HWND hParent, HINSTANCE hInst, HBITMAP hBit) : 
	gswindow (WS_EX_TOOLWINDOW, "gstoolstexturepreview", 
		name.str (), WS_OVERLAPPEDWINDOW, x, y, w, h, hParent, hInst, 
		gstoolsTexturingPreviewWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		m_hBitmap = hBit;
	}

	gstoolstexturepreview::~gstoolstexturepreview ()
	{
	}

	void gstoolstexturepreview::onPaint ()
	{
		PAINTSTRUCT ps;
		BeginPaint (getHandle (), &ps);

		HDC hDest = GetDC (getHandle ());
		HDC hdc = CreateCompatibleDC (NULL);
		SelectObject (hdc, m_hBitmap);

		BITMAP bmp;
		GetObject (m_hBitmap, sizeof (BITMAP), &bmp);
		BitBlt (hDest, 0, 0, bmp.bmWidth, bmp.bmHeight, hdc, 0, 0, SRCCOPY);
		DeleteDC (hdc);

		EndPaint (getHandle (), &ps);
	}

	LRESULT CALLBACK gstoolstexturepreview::gstoolsTexturingPreviewWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolstexturepreview *w = (gstoolstexturepreview*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
			case WM_PAINT:
				w->onPaint ();
				break;

			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
};