#include "gswindow/gsslider.h"

namespace gswin
{
	gsslider::gsslider (gswidget *parent, const gsutil::gsstring &title, unsigned long style, const int &id, 
		const int &x, const int &y, const int &w, const int &h) : gscontrol (0, 
		TRACKBAR_CLASS, title, style|gsWINDOW_CHILD|gsWINDOW_VISIBLE, id, x, y, w, h, parent)
	{
		setRange (0, 100);
	}

	gsslider::~gsslider ()
	{
	}

	void gsslider::setPosition (const int &pos)
	{
		SendMessage (getHandle (), TBM_SETPOS, true, pos);
	}

	void gsslider::setRange (const int &min, const int &max)
	{
		SendMessage (getHandle (), TBM_SETRANGEMIN, true, min);
		SendMessage (getHandle (), TBM_SETRANGEMAX, true, max);
	}

	int gsslider::getPosition ()
	{
		return (int)SendMessage (getHandle (), TBM_GETPOS, 0, 0);
	}

	int gsslider::getRangeMin ()
	{
		return (int)SendMessage (getHandle (), TBM_GETRANGEMIN, 0, 0);
	}

	int gsslider::getRangeMax ()
	{
		return (int)SendMessage (getHandle (), TBM_GETRANGEMAX, 0, 0);
	}
};
