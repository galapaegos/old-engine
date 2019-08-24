#ifndef _gstoolsediting_h_
#define _gstoolsediting_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gslistbox.h"
#include "gstoolseditingscene.h"

#include "galapaegos/gskernel.h"

namespace gs
{
	class gstoolsediting : public gswindow
	{
	public:
		gstoolsediting (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolsediting ();

		void buildList ();
		void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsEditingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
		void addScene (gsscene *t, int spacing = 0);

		//List showing all scenes, and we need to keep a list of all the pointers in the scene
		//There is no way to find a subscene, so keeping a list with pointers to them all is
		//a fast and simple solution.
		gslistbox *m_pList;
		gsutil::gsqueue <gsscene *> m_sceneList;

		//Add source scene as a subscene to destinatation scene
		gsbutton *m_pAdd;
		bool m_bAddSrc;
		unsigned m_iAddSrc;

		//Remove source scene, delete its contents
		gsbutton *m_pRemove;

		//Move source scene to destination as a subchild
		gsbutton *m_pMove;
		bool m_bMoveSrc;
		unsigned int m_iMoveSrc;

		//Merge selected scene, prompt user with another list to select the destination scene
		gsbutton *m_pMerge;
		bool m_bMergeSrc;
		unsigned int m_iMergeSrc;

		//This needs to spawn a window to input the dimensions of the bb, or generate the bb based
		//on the given scene
		gsbutton *m_pGenerateBB;

		//Save out source scene file
		gsbutton *m_pSave;
	};
};

#endif