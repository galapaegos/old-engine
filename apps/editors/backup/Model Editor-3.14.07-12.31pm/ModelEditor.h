#ifndef _ModelEditor_h_
#define _ModelEditor_h_

#include "gsgeom/gseffect.h"
#include "gsphyzics/gscollision.h"
#include "gswindow/gsmenu.h"

#include "ModelEditorAbout.h"
#include "ModelEditorConfig.h"
#include "Tools/ModelEditorTools.h"
#include "Options/ModelEditorOptions.h"

using namespace gs;

class ModelEditor : public gswin::gswindow
{
public:
	ModelEditor (const int &w, const int &h);
	~ModelEditor ();

	virtual void handle ();
	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);
	virtual void onKeyDown (void *wParam, void *lParam);
	virtual void onMouseMove (void *wParam, void *lParam);
	virtual void onMouseWheel (void *wParam, void *lParam);
	virtual void onMouseLeftDown (void *wParam, void *lParam);
	virtual void onMouseLeftUp (void *wParam, void *lParam);
	virtual void onMouseRightDown (void *wParam, void *lParam);

private:
	gskernel *m_pKernel;
	gswin::gsmenu *m_pMainMenu;

	ModelEditorTools *m_pTools;
	ModelEditorOptions *m_pOptions;

	gsgeom::gsscene *m_pCurrentScene, *m_pHud, *m_pGrid, *m_pPicking;

	//index to selected face
	int index1, index2, index3;

	int oldx, oldy;

	bool m_bSelected, m_bLeftButton;
};

#endif
