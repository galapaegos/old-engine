#include "gscombobox.h"

namespace gs
{
	gscombobox::gscombobox (const int x, const int y, const int w, const int h, 
		HWND hParent, HINSTANCE hInst) : gswindow (0, "COMBOBOX", "", 
		CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD, x, y, w, h, hParent, hInst)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gscomboboxWindowWndProc);

		m_iSize = 0;
	}

	gscombobox::~gscombobox ()
	{
	}

	void gscombobox::add (const char *pItem)
	{
		SendMessage (getHandle (), CB_INSERTSTRING, m_iSize++, (LPARAM)pItem);
		UpdateWindow (getHandle ());
	}

	void gscombobox::add (gstexture *pBitmap)
	{
		add (pBitmap, "");
	}

	void gscombobox::add (gstexture *pBitmap, const char *pItem)
	{
		// create bitmap here
		HBITMAP hBitmap = NULL;
		//int item = SendMessage (getHandle (), LB_ADDSTRING, 0, pItem);
		//SendMessage (getHandle (), LB_SETITEMDATA, item, hBitmap);
	}

	void gscombobox::remove (int index)
	{
	}

	LRESULT CALLBACK gscombobox::gscomboboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gscombobox *w = (gscombobox*)GetWindowLong (hWnd, GWL_USERDATA);

		//switch (message)
		//{
		//case WM_MEASUREITEM:
		//	{
		//		LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT)lParam;
		//		lpmis->itemHeight = 30;

		//		return 1;
		//	}
		//	break;

		//case WM_DRAWITEM:
		//	{
		//		LPDRAWITEMSTRUCT lpdis = (LPDRAWITEMSTRUCT)lParam;

		//		if (lpdis->itemID == -1)
		//			break;

		//		switch (lpdis->itemAction)
		//		{
		//		case ODA_SELECT:
		//		case ODA_DRAWENTIRE:
		//			{
		//				// get the data
		//				// create compatible dc
		//				// select the object
		//				// bitblt
		//				// display the text
		//				// delete the bitmap

		//				//if (lpdis->itemState & ODS_SELECTION)
		//				//{
		//					//focus around the texture
		//					//set dimsenions
		//					//DrawFocusRect
		//				//}
		//			}
		//			break;
		//		case ODA_FOCUS:
		//			break;
		//		}
		//		return 1;
		//	}
		//	break;
		//}

		return CallWindowProc ((WNDPROC)w->m_Callback, hWnd, message, wParam, lParam);
	}
};