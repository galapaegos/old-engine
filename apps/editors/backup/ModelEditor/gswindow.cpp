#include "gswindow.h"

namespace gs
{
	gswindow::gswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance)
	{
		m_hInst = hInstance;
		m_hParent = hParent;

		m_iWidth = w;
		m_iHeight = h;

		m_iX = x;
		m_iY = y;

		m_hWnd = CreateWindowEx (exStyle, pclass, ptitle, style,
			x, y, w, h, hParent, NULL, hInstance, NULL);

		if (!m_hWnd)
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
			return;
		}

		ShowWindow(m_hWnd, SW_SHOWNORMAL);

		m_hFont = CreateFont(8, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "MS Sans Serif");
		LRESULT l = SendMessage (getHandle (), WM_SETFONT, (WPARAM)m_hFont, TRUE);
	}

	gswindow::gswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance, void *proc)
	{	
		m_iWidth = w;
		m_iHeight = h;

		m_iX = x;
		m_iY = y;

		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX); 

		wcex.style			= CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc	= (WNDPROC)proc;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.hInstance		= hInstance;
		wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
		wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
		//wcex.hbrBackground	= NULL;
		wcex.lpszMenuName	= NULL;
		wcex.lpszClassName	= pclass;
		wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);

		RegisterClassEx(&wcex);

		m_hWnd = CreateWindowEx (exStyle, pclass, ptitle, style,
			x, y, w, h, hParent, NULL, hInstance, NULL);

		if (!m_hWnd)
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
			return;
		}

		ShowWindow(m_hWnd, SW_SHOWNORMAL);

		m_hFont = CreateFont(8, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "MS Sans Serif");
		LRESULT l = SendMessage (getHandle (), WM_SETFONT, (WPARAM)m_hFont, TRUE);
	}

	gswindow::~gswindow ()
	{
		if (m_hWnd != NULL)
			DestroyWindow (m_hWnd);
	}
};