#include "gstoolseffect.h"

namespace gs
{
	gstoolseffect::gstoolseffect (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gstabpanel (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsEffectWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pEffect = new gscombobox (10, 10, w - 20, 100, getHandle (), getInst ());
		m_pEffect->add ("Multi-texture");
	}
	
	gstoolseffect::~gstoolseffect ()
	{
	}

	void gstoolseffect::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
		case ' ':
			{
				delete this;
			}
			break;
		}
	}

	void gstoolseffect::onCommand (WPARAM wParam, LPARAM lParam)
	{
	}

	LRESULT CALLBACK gstoolseffect::gstoolsEffectWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolseffect *w = (gstoolseffect*)GetWindowLong (hWnd, GWL_USERDATA);
		switch (message)
		{
		case WM_KEYDOWN:
			w->onKeyDown (wParam, lParam);
			break;

		case WM_COMMAND:
			w->onCommand (wParam, lParam);
			break;

		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
		}

		return 1;
	}
};