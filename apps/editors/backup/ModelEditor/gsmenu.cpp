#include "gsmenu.h"

namespace gs
{
	int gsmenu::m_iUniqueId = 0;

	gsmenu::gsmenu (const char *pstr)
	{
		m_iType = GSMENU_NORMAL;
		m_hMenu = CreateMenu ();
		strncpy (m_strName, pstr, strlen (pstr) + 1);
	}

	gsmenu::gsmenu ()
	{
		m_iType = GSMENU_NORMAL;

		m_hMenu = CreateMenu ();

		strncpy (m_strName, "", 256);
	}

	gsmenu::gsmenu (GSMENU_TYPE d, const char *pstr)
	{
		m_iType = d;

		if (m_iType == GSMENU_POPUP)
			m_hMenu = CreatePopupMenu ();
		else
			m_hMenu = CreateMenu ();

		strncpy (m_strName, pstr, strlen (pstr) + 1);
	}

	gsmenu::gsmenu (GSMENU_TYPE d)
	{
		m_iType = d;

		if (m_iType == GSMENU_POPUP)
			m_hMenu = CreatePopupMenu ();
		else
			m_hMenu = CreateMenu ();

		strncpy (m_strName, "", strlen ("") + 1);
	}

	gsmenu::~gsmenu ()
	{
		for (int x = 0; x < m_qMenus.getSize (); x ++)
		{
			SubMenuItem *t = m_qMenus[x];

			if (t->menu)
				delete t->menu;
			if (t->item)
				delete t->item;

			delete t;
		}
		m_qMenus.clear ();
		DestroyMenu (m_hMenu);
	}

	void gsmenu::insertItem (gsmenuitem *item)
	{
		int pos = m_qMenus.getSize ();

		SubMenuItem *it = new SubMenuItem;
		it->item = item;
		it->menu = NULL;
		it->position = pos;

		int i = AppendMenu (m_hMenu, convertType (item->getType ()), gsmenu::m_iUniqueId++, item->getName ());

		m_qMenus.add (it);
	}

	void gsmenu::insertMenu (gsmenu *menu)
	{
		int pos = m_qMenus.getSize ();

		SubMenuItem *it = new SubMenuItem;
		it->item = NULL;
		it->menu = menu;
		it->position = pos;

		AppendMenu (m_hMenu, MF_STRING|MF_POPUP, (UINT_PTR)menu->getMenu (), menu->getName ());

		m_qMenus.add (it);
	}

	int gsmenu::convertType (const int type)
	{
		int iType = 0;
		if ((type|GSMENU_ITEM_STRING) == 1)
			iType = iType | MF_STRING;
		if ((type|GSMENU_ITEM_HBAR) == 4)
			iType = iType | MF_MENUBREAK;
		if ((type|GSMENU_ITEM_VBAR) == 8)
			iType = iType | MF_SEPARATOR;

		return iType;
	}
}