#include "ModelEditorOptionsSavePanel.h"

ModelEditorOptionsSavePanel::ModelEditorOptionsSavePanel (gswidget *parent) : 
gswin::gstabpanel (0, "STATIC", "Save", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
}

ModelEditorOptionsSavePanel::~ModelEditorOptionsSavePanel ()
{
}