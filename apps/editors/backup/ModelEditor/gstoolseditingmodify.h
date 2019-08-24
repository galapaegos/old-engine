#ifndef _gstoolseditingmodify_h_
#define _gstoolseditingmodify_h_

#include "gswindow.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gslistbox.h"
#include "gstextbox.h"

#include "gsutil/gsstring.h"

#include "galapaegos/gskernel.h"

namespace gs
{
	enum EDITING_TYPE
	{
		EDIT_VERTEX,
		EDIT_COLOR,
		EDIT_NORMAL,
		EDIT_TEXCOORD
	};

	class gstoolseditingmodify : public gswindow
	{
	public:
		gstoolseditingmodify (const gsutil::gsstring &title, const int &x, const int &y, const int &w, const int &h, 
			HWND hParent, HINSTANCE hInstance, gsscene *s, const int &index, const EDITING_TYPE &type);
		~gstoolseditingmodify ();

		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsEditingModifyWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		gstextbox *m_pEdit;
		gsbutton *m_pOk, *m_pCancel;

		EDITING_TYPE m_type;
		gsscene *m_pScene;
		int m_iIndex;
	};
};

#endif