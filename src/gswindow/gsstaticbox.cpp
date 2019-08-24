#include "gswindow/gsstaticbox.h"

namespace gswin
{
	gsstaticbox::gsstaticbox (gswidget *parent, const gsutil::gsstring &title, const int &x, const int &y, const int &w, const int &h) : 
		gsbutton (parent, title, gsBUTTON_GROUPBOX, x, y, w, h)
	{
		if (parent && !w && !h)
		{
			RECT r;
			GetClientRect (parent->getHandle (), &r);

			resize (r.left, r.top, r.right - r.left, r.bottom - r.top);
		}
	}

	gsstaticbox::~gsstaticbox ()
	{
	}

	void gsstaticbox::getDefaultSize (int *w, int *h)
	{
		int curw = 2;
		int curh = 2;

		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		{
			curw += m_ChildWindows[x]->getWidth () + 2;
			curh += m_ChildWindows[x]->getHeight () + 2;
		}


		*w = curw;
		*h = curh;
	}
};
