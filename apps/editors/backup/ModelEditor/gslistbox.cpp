#include "gslistbox.h"

namespace gs
{
	gslistbox::gslistbox (const int x, const int y, const int w, const int h, 
		HWND hParent, HINSTANCE hInst) : gswindow (0, "LISTBOX", "", 
		LBS_STANDARD|WS_CHILD, x, y, w, h, hParent, hInst)
	{
		m_Callback = GetWindowLong (getHandle (), GWL_WNDPROC);
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		SetWindowLong (getHandle (), GWL_WNDPROC, (LONG)gslistboxWindowWndProc);

		m_iSize = 0;
	}

	gslistbox::~gslistbox ()
	{
	}

	void gslistbox::add (const char *pItem)
	{
		SendMessage (getHandle (), LB_INSERTSTRING, m_iSize++, (LPARAM)pItem);
		UpdateWindow (getHandle ());
	}

	void gslistbox::add (gstexture *pBitmap)
	{
		add (pBitmap, "");
	}

	void gslistbox::add (gstexture *pBitmap, const char *pItem)
	{
		// create bitmap here
		HBITMAP hBitmap = NULL;
		//int item = SendMessage (getHandle (), LB_ADDSTRING, 0, pItem);
		//SendMessage (getHandle (), LB_SETITEMDATA, item, hBitmap);
	}

	void gslistbox::clearSelected ()
	{
		SendMessage (getHandle (), LB_SETCURSEL, -1, 0);
		UpdateWindow (getHandle ());
	}

	void gslistbox::clearList ()
	{
		SendMessage (getHandle (), LB_RESETCONTENT, 0, 0);
		UpdateWindow (getHandle ());
	}

	void gslistbox::remove (int index)
	{
	}

	LRESULT CALLBACK gslistbox::gslistboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gslistbox *w = (gslistbox*)GetWindowLong (hWnd, GWL_USERDATA);

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