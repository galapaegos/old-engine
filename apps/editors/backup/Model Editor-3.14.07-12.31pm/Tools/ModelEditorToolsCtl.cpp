#include "ModelEditorToolsCtl.h"

ModelEditorToolsCtl::ModelEditorToolsCtl (gswidget *parent) : gstabctl (0, "ModelEditorToolsCtl", TCS_MULTILINE|WS_CHILD|WS_VISIBLE, parent)
{
	m_pCamera = new ModelEditorToolsCameraPanel (this);
	add (m_pCamera);
	m_pCamera->show ();

	m_pEdit = new ModelEditorToolsEditPanel (this);
	add (m_pEdit);
	m_pEdit->hide ();

	m_pPrimitives = new ModelEditorToolsPrimitivesPanel (this);
	add (m_pPrimitives);
	m_pPrimitives->hide ();

	m_pShaders = new ModelEditorToolsShadersPanel (this);
	add (m_pShaders);
	m_pShaders->hide ();
	
	m_pTextures = new ModelEditorToolsTexturesPanel (this);
	add (m_pTextures);
	m_pTextures->hide ();

	m_pTerrain = new ModelEditorToolsTerrainPanel (this);
	add (m_pTerrain);
	m_pTerrain->hide ();

	m_pTriangulate = new ModelEditorToolsTriangulate (this);
	add (m_pTriangulate);
	m_pTriangulate->hide ();

	m_pPaint = new ModelEditorToolsPaintPanel (this);
	add (m_pPaint);
	m_pPaint->hide ();

	m_pSelect = new ModelEditorToolsSelectPanel (this);
	add (m_pSelect);
	m_pSelect->hide ();
}

ModelEditorToolsCtl::~ModelEditorToolsCtl ()
{
}

void ModelEditorToolsCtl::onClose ()
{
	for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		m_ChildWindows[x]->onClose ();
}

void ModelEditorToolsCtl::onCommand (void *wParam, void *lParam)
{
}
