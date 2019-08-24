#include "gswindow/gscombobox.h"

namespace gswin
{
	gscombobox::gscombobox (gswidget *parent, const gsutil::gsstring &title, long style, const int &id,
		const int x, const int y, const int w, const int h) : gscontrol (0, "COMBOBOX", title, 
		gsWINDOW_CHILD|gsWINDOW_VISIBLE|style, id, x, y, w, h, parent)
	{
		m_iSize = 0;
	}

	gscombobox::~gscombobox ()
	{
	}

	void gscombobox::add (const gsutil::gsstring &pItem)
	{
#ifdef WIN32
		SendMessage (getHandle (), CB_INSERTSTRING, m_iSize++, (LPARAM)pItem.str ());
		UpdateWindow (getHandle ());
#endif
	}

	void gscombobox::add (gsimage::gstexture *pBitmap)
	{
		add (pBitmap, "");
	}

	void gscombobox::add (gsimage::gstexture *pBitmap, const gsutil::gsstring &pItem)
	{
		// create bitmap here
		//HBITMAP hBitmap = NULL;
		//int item = SendMessage (getHandle (), LB_ADDSTRING, 0, pItem);
		//SendMessage (getHandle (), LB_SETITEMDATA, item, hBitmap);
	}

	void gscombobox::remove (int index)
	{
	}

	gsutil::gsstring gscombobox::getSelectedItem ()
	{
#ifdef WIN32
		int index = (int)SendMessage (getHandle (), CB_GETCURSEL, 0, 0);
		if (index == LB_ERR)
			return "";

		int size = (int)SendMessage (getHandle (), CB_GETLBTEXTLEN, index, 0);
		char *tmp = new char[size+1];
		SendMessage (getHandle (), CB_GETLBTEXT, index, (LPARAM)tmp);
		tmp[size] = '\0';
		gsutil::gsstring temp = tmp;
		delete [] tmp;

		return temp;
#else
		return "";
#endif
	}

	int gscombobox::getSelected ()
	{
#ifdef WIN32
		int index = (int)SendMessage (getHandle (), CB_GETCURSEL, 0, 0);
		if (index == LB_ERR)
			return -1;
		else
			return index;
#else
		return -1;
#endif
	}
};
