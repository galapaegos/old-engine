#ifndef _gstoolseditingscene_h_
#define _gstoolseditingscene_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gslistbox.h"

#include "gsutil/gsstring.h"

#include "galapaegos/gskernel.h"

#include "gstoolseditingmodify.h"

namespace gs
{
	class gstoolseditingscene : public gswindow
	{
	public:
		gstoolseditingscene (const gsutil::gsstring &title, const int &x, const int &y, const int &w, const int &h, HWND hParent, HINSTANCE hInstance, gsscene *s);
		virtual ~gstoolseditingscene ();

		void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsEditingSceneWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:

		void buildListBox ();

		gsscene *m_pScene;

		gslistbox *m_pVertexList;
		gslistbox *m_pColorList;
		gslistbox *m_pNormalList;
		gslistbox *m_pTexCoordList;
	};
};

#endif