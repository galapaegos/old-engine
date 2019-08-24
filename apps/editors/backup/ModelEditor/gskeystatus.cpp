#include "gskeystatus.h"

namespace gs
{
	gskeystatus::gskeystatus (DWORD exStyle, const char *pclass, const char *ptitle,
		DWORD style, const int x, const int y, const int w, const int h, HWND hParent,
		HINSTANCE hInst) : gswindow (exStyle, pclass, ptitle, style, x, y, w, h,
		hParent, hInst, gskeystatusWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pX = new gscheckbox ("X:", 40, 0, 40, 25, getHandle (), getInst ());
		m_pY = new gscheckbox ("Y:", 40, 25, 40, 25, getHandle (), getInst ());
		m_pZ = new gscheckbox ("Z:", 40, 50, 40, 25, getHandle (), getInst ());

		m_pR = new gscheckbox ("R:", 40, 75, 40, 25, getHandle (), getInst ());
		m_pT = new gscheckbox ("T:", 40, 100, 40, 25, getHandle (), getInst ());
		m_pV = new gscheckbox ("V:", 40, 125, 40, 25, getHandle (), getInst ());

		m_p1 = new gscheckbox ("p1", 0, 0, 40, 25, getHandle (), getInst ());
		m_p2 = new gscheckbox ("p2", 0, 25, 40, 25, getHandle (), getInst ());
		m_p3 = new gscheckbox ("p3", 0, 50, 40, 25, getHandle (), getInst ());
	}

	gskeystatus::~gskeystatus ()
	{
	}

	void gskeystatus::toggleX ()
	{
		m_pX->toggle ();
	}

	void gskeystatus::toggleY ()
	{
		m_pY->toggle ();
	}

	void gskeystatus::toggleZ ()
	{
		m_pZ->toggle ();
	}

	void gskeystatus::toggleR ()
	{
		m_pR->toggle ();
	}

	void gskeystatus::toggleT ()
	{
		m_pT->toggle ();
	}

	void gskeystatus::toggleV ()
	{
		m_pV->toggle ();
	}

	void gskeystatus::onCommand (WPARAM wParam, LPARAM lParam)
	{
	}

	LRESULT gskeystatus::gskeystatusWndProc (HWND hWnd, UINT message, WPARAM wParam,
		LPARAM lParam)
	{
		gskeystatus *w = (gskeystatus*)GetWindowLong (hWnd, GWL_USERDATA);

		switch (message)
		{
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}
};