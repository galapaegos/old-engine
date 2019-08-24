#include "gswindow/gscontrol.h"

namespace gswin
{
	gscontrol::gscontrol (unsigned long exStyle, const gsutil::gsstring &pclass, const gsutil::gsstring &title, unsigned long style, const int &id,
		const int &x, const int &y,	const int &w, const int &h, gswidget *parent) : gswidget (exStyle, pclass, title, style, id, x, y, w, h, parent)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		if (!m_Callback)
		{
			char *pMsgBuf;
			char *pDisplayBuf;
			DWORD dw = GetLastError();

			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
				NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &pMsgBuf,	0, NULL );

			pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
			wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
			MessageBox(NULL, pDisplayBuf, "Error", MB_OK); 
		}
		if (!SetWindowLong (getHandle (), GWL_WNDPROC, static_cast <LONG> (reinterpret_cast <ULONG_PTR> (gscontrolWinProc))))
		{
			char *pMsgBuf;
			char *pDisplayBuf;
			DWORD dw = GetLastError();

			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
				NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
				(LPTSTR) &pMsgBuf,	0, NULL );

			pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
			wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
			MessageBox(NULL, pDisplayBuf, "Error", MB_OK); 
		}
		parent->add (this);
	}

	gscontrol::~gscontrol ()
	{
	}

	LRESULT gscontrol::gscontrolWinProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gscontrol *w = reinterpret_cast <gscontrol*> (static_cast <ULONG_PTR> (GetWindowLong (hWnd, GWL_USERDATA)));

		switch (message)
		{
		case WM_COMMAND:
			if (!w)
				return CallWindowProc (reinterpret_cast <WNDPROC> (static_cast <ULONG_PTR> (w->m_Callback)), hWnd, message, wParam, lParam);
			else
				w->onCommand ((void*)wParam, (void*)lParam);
			break;

		//case WM_CLOSE:
			//if (!w)
			//	return CallWindowProc (reinterpret_cast <WNDPROC> (static_cast <ULONG_PTR> (w->m_Callback)), hWnd, message, wParam, lParam);
			//else
			//	w->onClose ();
			//break;

		//case WM_DESTROY:
			//if (!w)
			//	return DefWindowProc (hWnd, message, wParam, lParam);
			//else
			//	w->onDestroy ();
			//break;

		//case WM_NOTIFY:
			//if (!w)
			//	return CallWindowProc (reinterpret_cast <WNDPROC> (static_cast <ULONG_PTR> (w->m_Callback)), hWnd, message, wParam, lParam);
			//else
			//	w->onNotify ((void*)wParam, (void*)lParam);
			//break;

		//case WM_PAINT:
			//if (!w)
			//	return DefWindowProc (hWnd, message, wParam, lParam);
			//else
			//	w->onPaint ();
			//break;

		//case WM_KEYDOWN:
			//if (!w)
			//	return CallWindowProc (reinterpret_cast <WNDPROC> (static_cast <ULONG_PTR> (w->m_Callback)), hWnd, message, wParam, lParam);
			//else
            //    w->onKeyDown ((void*)wParam, (void*)lParam);
			//break;

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
			if (!w)
				return 0;
			else
				return CallWindowProc (reinterpret_cast <WNDPROC> (static_cast <ULONG_PTR> (w->m_Callback)), hWnd, message, wParam, lParam);
		}

		return 0;
	}
};
