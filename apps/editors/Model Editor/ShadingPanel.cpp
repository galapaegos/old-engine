#include "ShadingPanel.h"

ShadingPanel::ShadingPanel (data *pd, gswin::gswidget *parent) : gswin::gstabpanel (0, "STATIC", "Shading", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, -1, parent)
{
	gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);
	gswin::gsbox *c = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	c->add (new gswin::gsdescription (this, "Type of effect:"));
	b->add (c);
	gswin::gsbox *d = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	gswin::gslistbox *l = new gswin::gslistbox (this, "", gswin::gsLISTBOX_STANDARD, -1, 0, 0, 0, 100);
	l->add ("multi-texturing");
	l->add ("render to texture");
	l->add ("shader");
	d->add (l, gswin::gsEXPAND);
	b->add (d);
}

ShadingPanel::~ShadingPanel ()
{
}
