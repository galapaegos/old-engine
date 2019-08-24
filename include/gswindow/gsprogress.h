#ifndef _gsprogress_h_
#define _gsprogress_h_

#include "gswindow/gscontrol.h"

namespace gswin
{
	class gsprogress : public gscontrol
	{
	public:
		gsprogress (unsigned long exStyle, const gsutil::gsstring &title, unsigned long style, const int &id, const int &x, const int &y, const int &w, const int &h, gswidget *parent);
		~gsprogress ();

		void setRange (const int &start, const int &end);
		void setRange (const int &size);

		void progress (const int &i);

	private:
		int m_iStart, m_iEnd;
		int m_iCurrent;
	};
};

#endif
