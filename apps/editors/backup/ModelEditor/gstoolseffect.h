#ifndef _gstoolseffect_h_
#define _gstoolseffect_h_

#include "gstabpanel.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gscombobox.h"

namespace gs
{
	class gstoolseffect : public gstabpanel
	{
	public:
		gstoolseffect (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolseffect ();

		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsEffectWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		gscombobox *m_pEffect;
	};
};

#endif