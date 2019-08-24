#ifndef _gstoolsoptionsctl_h_
#define _gstoolsoptionsctl_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsdescription.h"
#include "gstextbox.h"
#include "gstabctl.h"

#include "gstoolsoptionsgeneral.h"
#include "gstoolsoptionsnetwork.h"

namespace gs
{
	class gstoolsoptionsctl : public gstabctl
	{
	public:
		gstoolsoptionsctl (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInstance);
		~gstoolsoptionsctl ();

		void onCommand (WPARAM wParam, LPARAM lParam);
		void onNotify (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsoptionsctlWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		gstoolsoptionsgeneral *m_pGeneral;
		gstoolsoptionsnetwork *m_pNetwork;
	};
};

#endif