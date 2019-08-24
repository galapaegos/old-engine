#ifndef _test_h_
#define _test_h_

#include "gswindow.h"

namespace gs
{
	enum GSMENU_ITEM_TYPE
	{
		GSMENU_ITEM_STRING		= 1,
		GSMENU_ITEM_CHECKBOX	= 2,
		GSMENU_ITEM_HBAR		= 4,
		GSMENU_ITEM_VBAR		= 8,
	};

	class gsmenuitem
	{
	public:
		gsmenuitem (const int id, const int type);
		gsmenuitem (const int id, const int type, const char *pName);
		~gsmenuitem ();

		int getId () { return m_iId; }
		int getType () { return m_iType; }
		char *getName () { return m_strName; }

	private:
		int m_iId, m_iType;
		char m_strName[256];
	};
};

#endif