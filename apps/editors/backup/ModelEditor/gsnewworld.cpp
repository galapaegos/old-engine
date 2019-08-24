#include "gsnewworld.h"

namespace gs
{
	gsnewworld::gsnewworld (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
		gswindow (exStyle, pclass, ptitle, style, x, y, w, h, hParent, hInstance, 
			wndprocNewWorld)
	{
	}

	gsnewworld::~gsnewworld ()
	{
	}

	LRESULT gsnewworld::wndprocNewWorld (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc (hWnd, message, wParam, lParam);
	}
};