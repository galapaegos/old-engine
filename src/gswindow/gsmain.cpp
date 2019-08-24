#include "gswindow/gsmain.h"

namespace gswin
{
	gsmain::gsmain (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, 
		const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent) : gswin::gswidget (exStyle, pclass, title, 
#ifdef WIN32
		style, id, x, y, w, h, parent, gsmainWinProc)
#else
		style, id, x, y, w, h, parent)
#endif
	{
	}

	gsmain::~gsmain ()
	{
	}

#ifdef WIN32
	LRESULT gsmain::gsmainWinProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsmain *w = reinterpret_cast <gsmain*> (static_cast <ULONG_PTR> (GetWindowLong (hWnd, GWL_USERDATA)));

		switch (message)
		{
		case WM_COMMAND:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onCommand ((void*)wParam, (void*)lParam);
			break;

		case WM_CLOSE:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onClose ();
			break;

		//case WM_DESTROY:
			//if (!w)
			//	return DefWindowProc (hWnd, message, wParam, lParam);
			//else
			//	w->onDestroy ();
			//break;

		case WM_LBUTTONDOWN:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseLeftDown ((void*)wParam, (void*)lParam);
			break;

		case WM_LBUTTONUP:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseLeftUp ((void*)wParam, (void*)lParam);
			break;

		case WM_MBUTTONDOWN:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseMiddleDown ((void*)wParam, (void*)lParam);
			break;

		case WM_MBUTTONUP:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseMiddleUp ((void*)wParam, (void*)lParam);
			break;

		case WM_MOUSEMOVE:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseMove ((void*)wParam, (void*)lParam);
			break;

		case 0x020A:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseWheel ((void*)wParam, (void*)lParam);
			break;

		case WM_NOTIFY:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onNotify ((void*)wParam, (void*)lParam);
			break;

		case WM_PAINT:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
                w->onPaint ();
			break;

		case WM_RBUTTONDOWN:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseRightDown ((void*)wParam, (void*)lParam);
			break;

		case WM_RBUTTONUP:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
				w->onMouseRightUp ((void*)wParam, (void*)lParam);
			break;

		case WM_KEYDOWN:
			if (!w)
				return DefWindowProc (hWnd, message, wParam, lParam);
			else
                w->onKeyDown ((void*)wParam, (void*)lParam);
			break;

		//case WM_SIZE:
			//if (!w)
			//	return DefWindowProc (hWnd, message, wParam, lParam);
			//else
			//	w->onSize ((void*)wParam, (void*)lParam);
			//break;

		//case WM_MOVE:
			//if (!w)
			//	return DefWindowProc (hWnd, message, wParam, lParam);
			//else
			//	w->onSize ((void*)wParam, (void*)lParam);
			//break;

		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 0;
	}
#endif
};
