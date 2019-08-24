#ifndef _gskeystatus_h_
#define _gskeystatus_h_

#include "gswindow.h"
#include "gscheckbox.h"

namespace gs
{
	class gskeystatus : public gswindow
	{
	public:
		gskeystatus (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gskeystatus ();

		virtual void onCommand (WPARAM wParam, LPARAM lParam);

		void toggleX ();
		void toggleY ();
		void toggleZ ();
		void toggleR ();
		void toggleT ();
		void toggleV ();

		void uncheckX () { m_pX->uncheck (); }
		void uncheckY () { m_pY->uncheck (); }
		void uncheckZ () { m_pZ->uncheck (); }
		void uncheckR () { m_pR->uncheck (); }
		void uncheckT () { m_pT->uncheck (); }
		void uncheckV () { m_pV->uncheck (); }

		void checkX () { m_pX->check (); }
		void checkY () { m_pY->check (); }
		void checkZ () { m_pZ->check (); }
		void checkR () { m_pR->check (); }
		void checkT () { m_pT->check (); }
		void checkV () { m_pV->check (); }

		bool isCheckedP1 () { return m_p1->getStatus (); }
		bool isCheckedP2 () { return m_p2->getStatus (); }
		bool isCheckedP3 () { return m_p3->getStatus (); }

		static LRESULT CALLBACK gskeystatusWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		gscheckbox *m_pX;
		gscheckbox *m_pY;
		gscheckbox *m_pZ;

		gscheckbox *m_pR;
		gscheckbox *m_pT;
		gscheckbox *m_pV;

		gscheckbox *m_p1;
		gscheckbox *m_p2;
		gscheckbox *m_p3;
	};
};

#endif