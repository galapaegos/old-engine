#ifndef _ModelEditorToolsTexturesPanel_h_
#define _ModelEditorToolsTexturesPanel_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gslistbox.h"
#include "gswindow/gstabpanel.h"

#include "../ModelEditorConfig.h"
#include "ModelEditorToolsTexturesPreview.h"

class ModelEditorToolsTexturesPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsTexturesPanel (gswidget *parent);
	~ModelEditorToolsTexturesPanel ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

private:
	gsutil::gsstring m_strSearchDirectory;
	gswin::gslistbox *m_pListBox;

	gswin::gsbutton *m_pOk, *m_pCancel, *m_pApply;
};

#endif
