#include "OptionsPanel.h"

OptionsPanel::OptionsPanel (data *d, gswin::gswidget *parent) : gswin::gstabpanel (0, "STATIC", "Options", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, -1, parent)
{
	gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);
}

OptionsPanel::~OptionsPanel ()
{
}
