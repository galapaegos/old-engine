#include "ModelEditorToolsCameraPanel.h"

ModelEditorToolsCameraPanel::ModelEditorToolsCameraPanel (gswidget *parent) : 
	gswin::gstabpanel (0, "STATIC", "Camera", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
}

ModelEditorToolsCameraPanel::~ModelEditorToolsCameraPanel ()
{
}

void ModelEditorToolsCameraPanel::onClose ()
{
}

void ModelEditorToolsCameraPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;
}
