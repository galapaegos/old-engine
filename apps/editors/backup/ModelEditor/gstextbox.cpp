#include "gstextbox.h"

namespace gs
{
	gstextbox::gstextbox (const char *title,
		const int x, const int y, const int w, const int h,
		HWND hParent, HINSTANCE hInstance) : 
	gswindow (WS_EX_CLIENTEDGE, "EDIT", title, WS_CHILD|ES_LEFT,
		x, y, w, h, hParent, hInstance)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gstextboxWindowWndProc);
	}

	gstextbox::~gstextbox ()
	{
	}

	const gsstring gstextbox::getText ()
	{
		SendMessage (getHandle (), EM_GETLINECOUNT, 0, 0);

		//Then line has no text
		//if (count == 1)

		char buf[256];
		buf[0] = '\0';

		int count = SendMessage (getHandle (), WM_GETTEXT, 256, (LPARAM)buf);
		buf[count] = '\0';

		gsstring temp = buf;
		return temp;
	}

	LRESULT CALLBACK gstextbox::gstextboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstextbox *w = (gstextbox*)GetWindowLong (hWnd, GWL_USERDATA);

		return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	}
};