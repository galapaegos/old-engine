#include "TerrainPanel.h"

TerrainPanel::TerrainPanel (data *d, gswin::gswidget *parent) : gswin::gstabpanel (0, "STATIC", "Terrain", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, -1, parent)
{
	gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);
}

TerrainPanel::~TerrainPanel ()
{
}
