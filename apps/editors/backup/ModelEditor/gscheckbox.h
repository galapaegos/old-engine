#ifndef _gscheckbox_h_
#define _gscheckbox_h_

#include "gswindow.h"

namespace gs
{
	class gscheckbox : public gswindow
	{
	public:
		gscheckbox (const char *title, 
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gscheckbox ();

		void check ();
		void uncheck ();

		void toggle ();

		bool getStatus ();

		static LRESULT CALLBACK gscheckboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		LONG m_Callback;

	private:
		bool m_bCheck;
	};
};

#endif