#include "gswindow/gsgroup.h"

namespace gswin
{
	gsgroup::gsgroup (gswidget *parent, long style, const int &id, const int x, const int y, const int w, 
		const int h) : gscontrol (0, "STATIC", "", style|gsWINDOW_CHILD|gsWINDOW_VISIBLE, id,
		x, y, w, h, parent)
	{
		if (w == 0 || h == 0)
		{
			RECT r;
			GetClientRect (parent->getHandle (), &r);

			resize (r.left, r.top, r.right - r.left, r.bottom - r.top);
		}
	}
	
	gsgroup::~gsgroup ()
	{
	}
};
