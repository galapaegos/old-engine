#ifndef _ModelEditorToolsCameraPanel_h_
#define _ModelEditorToolsCameraPanel_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gstabpanel.h"

#include "../ModelEditorConfig.h"

class ModelEditorToolsCameraPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsCameraPanel (gswidget *parent);
	virtual ~ModelEditorToolsCameraPanel ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

private:

	//gswin::gsbutton *m_pOrbit, *m_pFPS;
	//gswin::gsbutton *m_pSelection;
};

#endif
