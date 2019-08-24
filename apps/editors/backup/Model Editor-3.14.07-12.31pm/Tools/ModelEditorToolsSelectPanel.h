#ifndef _ModelEditorToolsSelectPanel_h_
#define _ModelEditorToolsSelectPanel_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gscheckbox.h"
#include "gswindow/gstabpanel.h"

#include "../ModelEditorConfig.h"

//Edit Scene positioning, so we can merge scenes together or break them apart
class ModelEditorToolsSelectPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsSelectPanel (gswidget *parent);
	virtual ~ModelEditorToolsSelectPanel ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

protected:
	gswin::gsbutton *m_pX, *m_pY, *m_pZ, *m_pT, *m_pR, *m_pS;
	gswin::gscheckbox *m_pP1, *m_pP2, *m_pP3;
};

#endif
