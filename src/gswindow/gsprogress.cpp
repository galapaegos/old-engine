#include "gswindow/gsprogress.h"

namespace gswin
{
	gsprogress::gsprogress (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent) : 
		gswin::gscontrol (0, PROGRESS_CLASS, title, style, id, x, y, w, h, parent)
	{
		m_iStart = 0; m_iEnd = 100;
	}

	gsprogress::~gsprogress ()
	{
	}

	void gsprogress::setRange (const int &start, const int &end)
	{
		m_iStart = start; m_iEnd = end;
		SendMessage (getHandle (), PBM_SETRANGE, m_iStart, m_iEnd);
	}

	void gsprogress::setRange (const int &size)
	{
		m_iEnd = size;
		SendMessage (getHandle (), PBM_SETRANGE, m_iStart, m_iEnd);
	}

	void gsprogress::progress (const int &i)
	{
		m_iCurrent = i;
		SendMessage (getHandle (), PBM_SETPOS, i, 0);
	}
}
