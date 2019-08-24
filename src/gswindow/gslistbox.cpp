#include "gswindow/gslistbox.h"

namespace gswin
{
	gslistbox::gslistbox (gswidget *parent, const gsutil::gsstring &windowTitle, 
		unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h) : 
		gscontrol (0, "LISTBOX", windowTitle, style|WS_CHILD|WS_VISIBLE, id, x, y, w, h, parent)
	{
		m_iSize = 0;
	}

	gslistbox::~gslistbox ()
	{
	}

	void gslistbox::add (const gsutil::gsstring &item)
	{
		SendMessage (getHandle (), LB_INSERTSTRING, m_iSize++, (LPARAM)item.str ());
	}

	void gslistbox::add (gsimage::gstexture *pBitmap)
	{
		add (pBitmap, "");
	}

	void gslistbox::add (gsimage::gstexture *pBitmap, const gsutil::gsstring &item)
	{
		// create bitmap here
		HBITMAP hBitmap = NULL;
	}

	void gslistbox::clear ()
	{
		ListBox_ResetContent (getHandle ());
		m_iSize = 0;
	}

	void gslistbox::remove (int index)
	{
		ListBox_DeleteString (getHandle (), index);
		m_iSize --;
	}

	int gslistbox::getSelected ()
	{
#ifdef WIN32
		int index = (int)SendMessage (getHandle (), LB_GETCURSEL, 0, 0);
		if (index == LB_ERR)
			return -1;
		else
			return index;
#else
		return -1;
#endif
	}

	gsutil::gsstring gslistbox::getSelectedItem ()
	{
#ifdef WIN32
		int index = (int)SendMessage (getHandle (), LB_GETCURSEL, 0, 0);
		if (index == LB_ERR)
			return "";

		int size = (int)SendMessage (getHandle (), LB_GETTEXTLEN, index, 0);
		char *tmp = new char[size+1];
		SendMessage (getHandle (), LB_GETTEXT, index, (LPARAM)tmp);
		tmp[size] = '\0';
		gsutil::gsstring temp = tmp;
		delete [] tmp;

		return temp;
#else
		return "";
#endif
	}
};
