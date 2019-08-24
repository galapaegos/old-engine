#include "ModelEditorToolsSelectPanel.h"

ModelEditorToolsSelectPanel::ModelEditorToolsSelectPanel (gswidget *parent) : 
	gswin::gstabpanel (0, "STATIC", "Select", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	m_pX = new gswin::gsbutton (this, "X", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 5, 5, 25, 25);
	add (m_pX);

	m_pY = new gswin::gsbutton (this, "Y", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 35, 5, 25, 25);
	add (m_pY);

	m_pZ = new gswin::gsbutton (this, "Z", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 65, 5, 25, 25);
	add (m_pZ);

	m_pT = new gswin::gsbutton (this, "T", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 5, 35, 25, 25);
	add (m_pT);

	m_pR = new gswin::gsbutton (this, "R", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 35, 35, 25, 25);
	add (m_pR);

	m_pS = new gswin::gsbutton (this, "S", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 65, 35, 25, 25);
	add (m_pS);

	m_pP1 = new gswin::gscheckbox (this, "P1", WS_CHILD|WS_VISIBLE, 5, 65, 25, 25);
	add (m_pP1);

	m_pP2 = new gswin::gscheckbox (this, "P2", WS_CHILD|WS_VISIBLE, 35, 65, 25, 25);
	add (m_pP2);

	m_pP3 = new gswin::gscheckbox (this, "P3", WS_CHILD|WS_VISIBLE, 65, 65, 25, 25);
	add (m_pP3);
}

ModelEditorToolsSelectPanel::~ModelEditorToolsSelectPanel ()
{
}

void ModelEditorToolsSelectPanel::onClose ()
{
}

void ModelEditorToolsSelectPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;
}
