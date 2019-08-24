#include "ModelEditorOptionsCtl.h"

ModelEditorOptionsCtl::ModelEditorOptionsCtl (gswidget *parent) : 
	gswin::gstabctl (0, "ModelEditorOptionsCtl", WS_CHILD|WS_VISIBLE, parent)
{
	m_pGeneral = new ModelEditorOptionsGeneralPanel (this);
	add (m_pGeneral);
	m_pGeneral->show ();

	m_pSave = new ModelEditorOptionsSavePanel (this);
	add (m_pSave);
	m_pSave->show ();
}

ModelEditorOptionsCtl::~ModelEditorOptionsCtl ()
{
}