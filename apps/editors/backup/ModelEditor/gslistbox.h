#ifndef _gslistbox_h_
#define _gslistbox_h_

#include "gswindow.h"
#include "gsutil/gsqueue.h"
#include "gsimage/gstexture.h"

namespace gs
{
	class gslistbox : public gswindow
	{
	public:
		gslistbox (const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInst);
		~gslistbox ();

		void add (const char *pItem);
		void add (gsimage::gstexture *pBitmap);
		void add (gsimage::gstexture *pBitmap, const char *pItem);

		void remove (int index);

		void clearSelected ();
		void clearList ();

		int getSelected () 
		{ 
			int index = (int)SendMessage (getHandle (), LB_GETCURSEL, 0, 0);
			if (index == LB_ERR)
				return -1;
			else
				return index;
		}

		gsstring getSelectedItem ()
		{
			int index = (int)SendMessage (getHandle (), LB_GETCURSEL, 0, 0);
			if (index == LB_ERR)
				return "";

			int size = (int)SendMessage (getHandle (), LB_GETTEXTLEN, index, 0);
			char *tmp = new char[size+1];
			SendMessage (getHandle (), LB_GETTEXT, index, (LPARAM)tmp);
			tmp[size] = '\0';
			gsstring temp = tmp;
			delete [] tmp;

			return temp;
		}

		static LRESULT CALLBACK gslistboxWindowWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		inline int getSize () { return m_iSize; }
	private:
		LONG m_Callback;
		int m_iSize;
	};
};

#endif