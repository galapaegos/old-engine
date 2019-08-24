#ifndef _gsmenuediting_h_
#define _gsmenuediting_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gstoolsprimitives.h"
#include "gstoolstexturing.h"
#include "gstoolsoptions.h"
#include "gstoolseffect.h"
#include "gstoolslighting.h"
#include "gstoolsshaders.h"
#include "gstoolsterrain.h"
#include "gstoolstexturing.h"
#include "gstoolsediting.h"

namespace gs
{
	class gsmenuediting : public gswindow
	{
	public:
		gsmenuediting (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsmenuediting ();

		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onCommand (WPARAM wParam, LPARAM lParam);
		virtual void onDestroy ();

		static LRESULT CALLBACK gsmenuEditingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
		gsbutton *m_pPrimitives;
		gsbutton *m_pTextures;
		gsbutton *m_pOptions;
		gsbutton *m_pLighting;
		gsbutton *m_pShaders;
		gsbutton *m_pEditing;
		gsbutton *m_pTerrain;
		gsbutton *m_pEffect;
		//gsbutton *m_pEditing;
	};
};

#endif