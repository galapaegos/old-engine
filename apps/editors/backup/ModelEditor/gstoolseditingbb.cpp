#include "gstoolseditingbb.h"

namespace gs
{
	gstoolseditingbb::gstoolseditingbb (const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInst) :
		gswindow (0, "gstoolseditingbb", "gseditingbb", 0, x, y, w, h, hParent, hInst)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
	}

	gstoolseditingbb::~gstoolseditingbb ()
	{
	}

	void gstoolseditingbb::onCommand (WPARAM wParam, LPARAM lParam)
	{
	}

	LRESULT gstoolseditingbb::gstoolsEditingBBWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolseditingbb *w = (gstoolseditingbb*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
		case WM_COMMAND:
			w->onCommand (wParam, lParam);
			break;

		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 0;
	}
};