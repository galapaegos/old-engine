#ifndef _gsmenu_h_
#define _gsmenu_h_

#ifdef WIN32
#include <windows.h>
#endif
#include "gswindow/gsmenuitem.h"

namespace gswin
{
	enum GSMENU_TYPE
	{
		GSMENU_POPUP,
		GSMENU_NORMAL,
	};

	class GS gsmenu
	{
		struct SubMenuItem
		{
			gsmenu *menu;
			gsmenuitem *item;
			int position;
		};

	public:
		gsmenu ();
		gsmenu (const char *pstr);
		gsmenu (GSMENU_TYPE d);
		gsmenu (GSMENU_TYPE d, const char *pstr);
		virtual ~gsmenu ();

		void insertMenu (gsmenu *menu);
		void insertItem (gsmenuitem *item);
		char *getName () { return m_strName; }

#ifdef WIN32
		HMENU getMenu () { return m_hMenu; }
#endif

		static int m_iUniqueId;
	private:
		int convertType (const int type);
		int m_iType;
		char m_strName[256];

#ifdef WIN32
		HMENU m_hMenu;
#endif

		gsutil::gsqueue <SubMenuItem*> m_qMenus;
	};
};

#endif
