#include "gscheckbox.h"

namespace gs
{
	gscheckbox::gscheckbox (const char *title,
		const int x, const int y, const int w, const int h,
		HWND hParent, HINSTANCE hInstance) : 
	gswindow (0, "BUTTON", title, WS_CHILD|BS_AUTOCHECKBOX,
		x, y, w, h, hParent, hInstance)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gscheckboxWindowWndProc);
		m_bCheck = false;
	}

	gscheckbox::~gscheckbox ()
	{
	}

	void gscheckbox::check ()
	{
		SendMessage (getHandle (), BM_SETCHECK, BST_CHECKED, NULL);
		m_bCheck = true;
	}

	void gscheckbox::uncheck ()
	{
		SendMessage (getHandle (), BM_SETCHECK, BST_UNCHECKED, NULL);
		m_bCheck = false;
	}

	void gscheckbox::toggle ()
	{
		if (m_bCheck)
			uncheck ();
		else
			check ();
	}

	bool gscheckbox::getStatus ()
	{
		LRESULT res = SendMessage (getHandle (), BM_GETSTATE, NULL, NULL);

		if (res == BST_CHECKED)
			m_bCheck = true;
		else if (res == BST_UNCHECKED)
			m_bCheck = false;

		return m_bCheck;
	}

	LRESULT CALLBACK gscheckbox::gscheckboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gscheckbox *w = (gscheckbox*)GetWindowLong (hWnd, GWL_USERDATA);

		return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	}
};