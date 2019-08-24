#ifndef _gsabout_h_
#define _gsabout_h_

#include "gswindow.h"
#include "gsdescription.h"

namespace gs
{
	class gsabout : public gswindow
	{
	public:
		gsabout (const int x, const int y, const int w, const int h, HINSTANCE hInst);
		~gsabout ();

		virtual void onDestroy ();

		static LRESULT CALLBACK gsaboutWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	private:
		gsdescription *m_pDescription;
	};
};

#endif