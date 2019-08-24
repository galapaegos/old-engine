#ifndef _ModelEditorOptionsCtl_h_
#define _ModelEditorOptionsCtl_h_

#include "gswindow/gstabctl.h"
#include "ModelEditorOptionsGeneralPanel.h"
#include "ModelEditorOptionsSavePanel.h"

class ModelEditorOptionsCtl : public gswin::gstabctl
{
public:
	ModelEditorOptionsCtl (gswidget *parent);
	~ModelEditorOptionsCtl ();

private:
	ModelEditorOptionsGeneralPanel *m_pGeneral;
	ModelEditorOptionsSavePanel *m_pSave;
};

#endif