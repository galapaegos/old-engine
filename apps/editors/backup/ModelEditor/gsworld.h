#ifndef _gsworld_h_
#define _gsworld_h_

#include "gswindow.h"
#include "gsmenu.h"
#include "gsglobalconfig.h"
#include "gstoolsprimitives.h"
#include "gstoolstexturing.h"
#include "gstoolsoptions.h"
#include "gstoolseffect.h"
#include "gstoolslighting.h"
#include "gstoolsshaders.h"
#include "gstoolsterrain.h"
#include "gstoolstexturing.h"
#include "gstoolsediting.h"
#include "gskeystatus.h"
#include "galapaegos/gskernel.h"
#include "gsphyzics/gscollision.h"

namespace gs
{
	class gsworld : public gswindow
	{
		enum WORLD_EDIT
		{
			EDIT_FACE,
			EDIT_SNAPTOGRID,
		};
	public:
		gsworld (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gsworld ();

		virtual void setRoot (HWND hWnd) { m_hRoot = hWnd; }
		virtual HWND getRoot () { return m_hRoot; }

		virtual void init ();
		virtual void destroy ();
		virtual void render ();
		virtual void onPaint ();
		virtual void onCommand (WPARAM wParam, LPARAM lParam);
		virtual void onMouseMove (WPARAM wParam, LPARAM lParam);
		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onLButtonDown (WPARAM wParam, LPARAM lParam);
		virtual void onMButtonDown (WPARAM wParam, LPARAM lParam);
		virtual void onRButtonDown (WPARAM wParam, LPARAM lParam);
		virtual void onLButtonUp (WPARAM wParam, LPARAM lParam);
		virtual void onMButtonUp (WPARAM wParam, LPARAM lParam);
		virtual void onRButtonUp (WPARAM wParam, LPARAM lParam);
		
		static LRESULT CALLBACK gsworldWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		void cleanScene (gsscene *s);

		bool m_bPicking;
		int m_iSelected;
		gsface m_pSelectedFace;

		gskeystatus *m_pKeyStatus;

		bool m_bRotate;
		bool m_bRotateObject;
		bool m_bTranslate;
		bool m_bScale;
		bool m_bMove;
		bool m_bAction;

		bool m_bXAxis;
		bool m_bYAxis;
		bool m_bZAxis;

		int m_iOldx;
		int m_iOldy;

		HWND m_hRoot;

		gskernel	*kern;
	};
};

#endif