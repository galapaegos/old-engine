#ifndef _gswindow_h_
#define _gswindow_h_

#include <windows.h>
#include <commdlg.h>
#include <commctrl.h>
#include <stdio.h>
#include "gsutil/gsqueue.h"
#include "galapaegos/gskernel.h"

namespace gs
{
	class gswindow
	{
	public:
		gswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		gswindow (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance, void *proc);
		~gswindow ();

		int getWidth () { return m_iWidth; }
		int getHeight () { return m_iHeight; }

		int getX () { return m_iX; }
		int getY () { return m_iY; }

		HWND getHandle () { return m_hWnd; }
		HWND getParent () { return m_hParent; }

		virtual void add (gswindow *w) { m_ChildWindows.add (w); }

		void show ()
		{
			ShowWindow (m_hWnd, SW_SHOW);

			for (int x = 0; x < m_ChildWindows.getSize (); x++)
				m_ChildWindows[x]->show ();
		}

		void hide ()
		{
			ShowWindow (m_hWnd, SW_HIDE);

			for (int x = 0; x < m_ChildWindows.getSize (); x++)
				m_ChildWindows[x]->hide ();
		}
		
		virtual void onActivateApp () {}
		virtual void onClose () {}
		virtual void onCreate () {}
		virtual void onDestroy () {}
		virtual void onEnable () {}
		virtual void onKeyDown (WPARAM wParam, LPARAM lParam) {}
		virtual void onMouseMove () {}
		virtual void onMove () {}
		virtual void onMoving () {}
		virtual void onNCActivate () {}
		virtual void onNCCalcSize () {}
		virtual void onNCDestroy () {}
		virtual void onPaint () {}
		virtual void onParentNotify () {}
		virtual void onShowWindow () {}
		virtual void onSize () {}
		virtual void onSizing () {}
		virtual void onWindowPosChanged () {}
		virtual void onWindowPosChanging () {}
		
		virtual void onGetHMenu () {}
		virtual void onGetFont () {}
		virtual void onGetText () {}
		virtual void onGetTextLength () {}
		virtual void onSetFont () {}
		virtual void onSetIcon () {}
		virtual void onSetText () {}

		virtual HINSTANCE getInst () { return m_hInst; }

	protected:
		gsutil::gsqueue<gswindow*> m_ChildWindows;

	private:
		HWND m_hWnd;
		HWND m_hParent;

		int m_iWidth;
		int m_iHeight;

		int m_iX;
		int m_iY;

		HINSTANCE m_hInst;

		HFONT m_hFont;
	};
};

#endif