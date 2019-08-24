#include "RenderPanel.h"

RenderPanel::RenderPanel (const unsigned long &exStyle, const gsutil::gsstring &c, const gsutil::gsstring &t, const unsigned long &style, gswidget *parent) : gswin::gstabpanel (exStyle,
	 c, t, style, parent)
{
}

RenderPanel::~RenderPanel ()
{
}

void RenderPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;
}
