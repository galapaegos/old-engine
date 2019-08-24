#ifndef _gsmenuitem_h_
#define _gsmenuitem_h_

#include "gsutil/gsstring.h"

namespace gswin
{
	enum GSMENU_ITEM_TYPE
	{
		GSMENU_ITEM_STRING		= 1,
		GSMENU_ITEM_CHECKBOX	= 2,
		GSMENU_ITEM_HBAR		= 4,
		GSMENU_ITEM_VBAR		= 8,
	};

	class GS gsmenuitem
	{
	public:
		gsmenuitem (const int id, const int type);
		gsmenuitem (const int id, const int type, const char *pName);
		virtual ~gsmenuitem ();

		int getId () { return m_iId; }
		int getType () { return m_iType; }
		char *getName () { return m_strName; }

	private:
		int m_iId, m_iType;
		char m_strName[256];
	};
};

#endif
