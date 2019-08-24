#ifndef _ModelEditorToolsPaintPanel_h_
#define _ModelEditorToolsPaintPanel_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gscheckbox.h"
#include "gswindow/gsdescription.h"
#include "gswindow/gstabpanel.h"
#include "gswindow/gstextbox.h"

#include "../ModelEditorConfig.h"

class ModelEditorToolsPaintPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsPaintPanel (gswidget *parent);
	virtual ~ModelEditorToolsPaintPanel ();

	virtual void onCommand (void *wParam, void *lParam);

private:
	gswin::gsbutton *m_pPaintBrush, *m_pFillBrush;
	//gswin::gsbutton *m_pPickColor;

	gsgeom::gscolor m_Color;

	gswin::gscheckbox *m_pChar, *m_pFloat;
	gswin::gstextbox *m_pR, *m_pG, *m_pB, *m_pA;
	gswin::gsbutton *m_pApply;
};

#endif
