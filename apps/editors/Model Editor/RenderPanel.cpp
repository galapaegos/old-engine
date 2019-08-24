#include "RenderPanel.h"

RenderPanel::RenderPanel (data *d, gswin::gswidget *parent) : gswin::gstabpanel (0, "STATIC", "Rendering", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, -1, parent)
{
	gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);
	b->add (new gswin::gslistbox (this), gswin::gsEXPAND);
}

RenderPanel::~RenderPanel ()
{
}
