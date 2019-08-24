#ifndef _ModelEditorToolsEditPanel_h_
#define _ModelEditorToolsEditPanel_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gslistbox.h"
#include "gswindow/gstabpanel.h"

#include "../ModelEditorConfig.h"
#include "ModelEditorToolsEditScene.h"

//Edit Scene positioning, so we can merge scenes together or break them apart
class ModelEditorToolsEditPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsEditPanel (gswidget *parent);
	virtual ~ModelEditorToolsEditPanel ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);
	virtual void refreshList ();

	gsgeom::gsscene *findScene (const int &x);

protected:
	gswin::gslistbox *m_pSceneList;
	gswin::gsbutton *m_pAdd, *m_pAddAsChild, *m_pMerge, *m_pRemove, *m_pRefresh;

	gsgeom::gsscene *findSceneHelper (gsgeom::gsscene *s, const int &x);

private:
	virtual void refreshListHelper (gsgeom::gsscene *s, int count=0);

	int countHelper;
};

#endif
