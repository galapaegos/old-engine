#include "gswindow/gsmenuitem.h"

namespace gswin
{
	gsmenuitem::gsmenuitem (const int id, const int type)
	{
		m_iId = id;
		m_iType = type;
		strncpy (m_strName, "", strlen ("") + 1);
	}

	gsmenuitem::gsmenuitem (const int id, const int type, const char *pName)
	{
		m_iId = id;
		m_iType = type;
		strncpy (m_strName, pName, strlen (pName) + 1);
	}

	gsmenuitem::~gsmenuitem ()
	{
	}
};
