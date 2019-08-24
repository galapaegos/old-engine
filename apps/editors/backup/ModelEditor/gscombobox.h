#ifndef _gscombobox_h_
#define _gscombobox_h_

#include "gswindow.h"
#include "gsutil/gsqueue.h"

namespace gs
{
class gscombobox : public gswindow
	{
	public:
		gscombobox (const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInst);
		~gscombobox ();

		void add (const char *pItem);
		void add (gsimage::gstexture *pBitmap);
		void add (gsimage::gstexture *pBitmap, const char *pItem);

		void remove (int index);

		int getSelected () 
		{ 
			int index = (int)SendMessage (getHandle (), CB_GETCURSEL, 0, 0);
			if (index == LB_ERR)
				return -1;
			else
				return index;
		}

		gsstring getSelectedItem ()
		{
			int index = (int)SendMessage (getHandle (), CB_GETCURSEL, 0, 0);
			if (index == LB_ERR)
				return "";

			int size = (int)SendMessage (getHandle (), CB_GETLBTEXTLEN, index, 0);
			char *tmp = new char[size+1];
			SendMessage (getHandle (), CB_GETLBTEXT, index, (LPARAM)tmp);
			tmp[size] = '\0';
			gsstring temp = tmp;
			delete [] tmp;

			return temp;
		}

		static LRESULT CALLBACK gscomboboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		inline int getSize () { return m_iSize; }
	private:
		LONG m_Callback;
		int m_iSize;
	};
};

#endif