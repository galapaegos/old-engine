#ifndef _ModelEditorToolsTerrainPanel_h_
#define _ModelEditorToolsTerrainPanel_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gsdescription.h"
#include "gswindow/gstabpanel.h"
#include "gswindow/gstextbox.h"

#include "../ModelEditorConfig.h"

class ModelEditorToolsTerrainPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsTerrainPanel (gswidget *parent);
	virtual ~ModelEditorToolsTerrainPanel ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

private:
	gswin::gstextbox *m_pWidth, *m_pHeight, *m_pDepth, *m_pXOffset, *m_pYOffset, *m_pZOffset;
	gswin::gsbutton *m_pOk, *m_pCancel, *m_pHeightMap;
};

#endif
