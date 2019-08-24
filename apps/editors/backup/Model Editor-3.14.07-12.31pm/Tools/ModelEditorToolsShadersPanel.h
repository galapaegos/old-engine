#ifndef _ModelEditorToolsShadersPanel_h_
#define _ModelEditorToolsShadersPanel_h_

#include "gswindow/gslistbox.h"
#include "gswindow/gstabpanel.h"

#include "../ModelEditorConfig.h"

class ModelEditorToolsShadersPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsShadersPanel (gswidget *parent);
	~ModelEditorToolsShadersPanel ();

	virtual void onClose ();

private:
	gsutil::gsstring m_strShaderDirectory;
	gswin::gslistbox *m_pListBox;
};

#endif
