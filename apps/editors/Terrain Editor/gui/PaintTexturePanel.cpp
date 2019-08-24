#include "PaintTexturePanel.h"

PaintTexturePanel::PaintTexturePanel (const unsigned long &exStyle, const gsutil::gsstring &c,
	const gsutil::gsstring &t, const unsigned long &style, gswidget *parent) : 
	gswin::gstabpanel (exStyle, c, t, style, parent)
{
}

PaintTexturePanel::~PaintTexturePanel ()
{
}
