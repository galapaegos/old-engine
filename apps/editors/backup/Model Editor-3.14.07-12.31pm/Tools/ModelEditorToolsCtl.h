#ifndef _ModelEditorToolsCtl_h_
#define _ModelEditorToolsCtl_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gstabctl.h"

#include "ModelEditorToolsPrimitivesPanel.h"
#include "ModelEditorToolsShadersPanel.h"
#include "ModelEditorToolsTexturesPanel.h"
#include "ModelEditorToolsEditPanel.h"
#include "ModelEditorToolsCameraPanel.h"
#include "ModelEditorToolsTerrainPanel.h"
#include "ModelEditorToolsTriangulate.h"
#include "ModelEditorToolsPaintPanel.h"
#include "ModelEditorToolsSelectPanel.h"

class ModelEditorToolsCtl : public gswin::gstabctl
{
public:
	ModelEditorToolsCtl (gswidget *parent);
	virtual ~ModelEditorToolsCtl ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

private:
	ModelEditorToolsPrimitivesPanel *m_pPrimitives;
	ModelEditorToolsShadersPanel *m_pShaders;
	ModelEditorToolsTexturesPanel *m_pTextures;
	ModelEditorToolsEditPanel *m_pEdit;
	ModelEditorToolsCameraPanel *m_pCamera;
	ModelEditorToolsTerrainPanel *m_pTerrain;
	ModelEditorToolsTriangulate *m_pTriangulate;
	ModelEditorToolsPaintPanel *m_pPaint;
	ModelEditorToolsSelectPanel *m_pSelect;

	gs::gskernel *m_pKernel;
};

#endif
