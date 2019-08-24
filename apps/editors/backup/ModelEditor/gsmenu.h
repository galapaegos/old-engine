#ifndef _gsmenu_h_
#define _gsmenu_h_

#include <windows.h>

//engine includes
#include "gsmenuitem.h"

namespace gs
{
	enum GSMENU_TYPE
	{
		GSMENU_POPUP,
		GSMENU_NORMAL,
	};
	class gsmenu
	{
		typedef struct
		{
			gsmenu *menu;
			gsmenuitem *item;
			int position;
		} SubMenuItem;
	public:
		gsmenu ();
		gsmenu (const char *pstr);
		gsmenu (GSMENU_TYPE d);
		gsmenu (GSMENU_TYPE d, const char *pstr);
		~gsmenu ();

		void insertMenu (gsmenu *menu);
		void insertItem (gsmenuitem *item);
		char *getName () { return m_strName; }

		HMENU getMenu () { return m_hMenu; }

		static int m_iUniqueId;
	private:
		int convertType (const int type);
		int m_iType;
		char m_strName[256];
		HMENU m_hMenu;

		gsqueue<SubMenuItem*> m_qMenus;
	};
};

#endif