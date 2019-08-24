#include "EditPanel.h"

EditPanel::EditPanel (data *d, gswin::gswidget *parent) : gswin::gstabpanel (0, "STATIC", "Edit", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, -1, parent)
{
	gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);
	gswin::gsbox *c = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	c->add (new gswin::gslistbox (this), gswin::gsEXPAND);
	b->add (c);

}

EditPanel::~EditPanel ()
{
}
