#include "ModelEditor.h"

ModelEditor::ModelEditor (const int &w, const int &h) : gswin::gswindow (0, "modeleditor", "Model Editor v0.1", WS_BORDER|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX, 0, 0, w, h)
{
	//resizing window to previous dimensions
	ModelEditorConfig::WindowConfig *wc = ModelEditorConfig::get ()->getWindow (getClass ());
	if (wc)
		resize (wc->x, wc->y, wc->w, wc->h);

	//creating menu
	gswin::gsmenu *pFile = new gswin::gsmenu ("File");
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "New")); //0
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Open"));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Close"));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_VBAR));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Save")); //4
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Save As"));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Save As Primitive"));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_VBAR));
	pFile->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Exit")); //8
	gswin::gsmenu *pEdit = new gswin::gsmenu ("Edit");
	pEdit->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Undo")); //9
	pEdit->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Redo"));
	pEdit->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Cut"));
	pEdit->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Copy"));
	pEdit->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Paste"));
	pEdit->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Delete"));
	gswin::gsmenu *pView = new gswin::gsmenu ("View");
	pView->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Tools")); //15
	pView->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Options"));
	gswin::gsmenu *pAbout = new gswin::gsmenu ("About");
	pAbout->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "About"));
	pAbout->insertItem (new gswin::gsmenuitem (gswin::gsmenu::m_iUniqueId, gswin::GSMENU_ITEM_STRING, "Help"));

	m_pMainMenu = new gswin::gsmenu;
	m_pMainMenu->insertMenu (pFile);
	m_pMainMenu->insertMenu (pEdit);
	m_pMainMenu->insertMenu (pView);
	m_pMainMenu->insertMenu (pAbout);

	SetMenu (getHandle (), m_pMainMenu->getMenu ());

	ModelEditorConfig::get ()->m_pMainWindow = this;
	m_bSelected = false;
	m_bLeftButton = false;

	//int frameHeight = GetSystemMetrics (SM_CYCAPTION) + GetSystemMetrics (SM_CYMENU) + GetSystemMetrics (SM_CYSIZEFRAME);
	WINDOWINFO windInf;
	windInf.cbSize = sizeof (WINDOWINFO);
	GetWindowInfo (getHandle (), &windInf);

	//creating and initializing engine
	m_pKernel = new gs::gskernel;
	m_pKernel->init (getHandle (), getWidth (), getHeight ());
	ModelEditorConfig::get ()->m_pKernel = m_pKernel;

	oldx = 0;
	oldy = 0;

	m_pCurrentScene = NULL;

	//creating a grid
	m_pGrid = new gsgeom::gsscene;
	m_pGrid->m_strName = "grid";
	gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
	{
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-9, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-9, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-8, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-8, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-7, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-7, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-6, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-6, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-4, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-4, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-3, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-3, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-2, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-2, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-1, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-1, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (1, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (1, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (2, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (2, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (4, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (4, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (5, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (5, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (6, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (6, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (7, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (7, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (8, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (8, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (9, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (9, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 10));

		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -9));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -9));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -8));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -8));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -7));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -7));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -6));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -6));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -4));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -4));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -3));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -3));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -2));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -2));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -1));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -1));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 1));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 1));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 2));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 2));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 4));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 4));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 5));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 5));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 6));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 6));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 7));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 7));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 8));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 8));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 9));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 9));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 10));

		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
	}
	m_pGrid->m_Geometry = gi;

	//default effects
	gsgeom::gseffect *effect = new gsgeom::gseffect;
	//enable blending
	effect->setBlend (true);
	effect->setBlendFunc (gsgeom::gseffect::BLEND_ONE, gsgeom::gseffect::BLEND_ONE_MINUS_SRC_ALPHA);
	//enable depth testing
	effect->setDepthTest (true);
	effect->setDepthValue (1.f);
	effect->setDepthFunc (gsgeom::gseffect::DEPTH_LEQUAL);
	//enable culling
	effect->setCulling (true);
	effect->setCullFace (gsgeom::gseffect::CULL_FRONT);
	m_pGrid->m_pEffect = effect;

	//current scene
	ModelEditorConfig::get ()->m_pCurrentScene = new gsgeom::gsscene;
	ModelEditorConfig::get ()->m_pCurrentScene->m_strName = "current scene";
	gsgeom::gsgeometryinfo *geom = new gsgeom::gsgeometryinfo;
	ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry = geom;

	gsgeom::gscamera *c = new gsgeom::gscamera;
	c->setProjection (getWidth (), getHeight (), 45.f, 1.f, 300.f);
	c->setView (gsgeom::gsvec3f (10, 10, 10),
				gsgeom::gsvec3f (0, 0, 0),
				gsgeom::gsvec3f (0, 1, 0));
	m_pGrid->m_Camera = c;
	ModelEditorConfig::get ()->m_pMainCamera = c;
	ModelEditorConfig::get ()->m_pCurrentScene->m_Camera = c;
	m_pGrid->m_ChildNodes.add (ModelEditorConfig::get ()->m_pCurrentScene);
	
	m_pPicking = new gsgeom::gsscene;
	m_pPicking->m_strName = "picking";
	gsgeom::gsgeometryinfo *pickingGI = new gsgeom::gsgeometryinfo;
	gsgeom::gsgeometryinfo::IndexType *pickingIT = new gsgeom::gsgeometryinfo::IndexType;
	pickingIT->indexType = gsgeom::gsgeometryinfo::GS_LINE;
	m_pPicking->m_Geometry = pickingGI;

	gsgeom::gseffect *effectPicking = new gsgeom::gseffect;
	effectPicking->setLineSettings (true);
	effectPicking->setLineWidth (5.f);
	m_pPicking->m_pEffect = effectPicking;
	m_pGrid->m_ChildNodes.add (m_pPicking);

	{
		m_pHud = new gsgeom::gsscene;
		m_pHud->m_strName = "HUD";
		gsgeom::gsgeometryinfo *ghud = new gsgeom::gsgeometryinfo;
		gsgeom::gsgeometryinfo::IndexType *hudIT = new gsgeom::gsgeometryinfo::IndexType;
		hudIT->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f, (float)getHeight (), -0.2f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth (), (float)getHeight (), -0.2f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth (), (float)getHeight ()*8.f/10.f, -0.2f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth (), (float)getHeight ()*8.f/10.f, -0.2f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f, (float)getHeight ()*8.f/10.f, -0.2f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f, (float)getHeight (), -0.2f));

		ghud->m_vColors.add (gsgeom::gscolor (0.f, 1.f, 0.f, 0.5f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 1.f, 0.f, 0.5f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 1.f, 0.f, 0.5f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 1.f, 0.f, 0.5f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 1.f, 0.f, 0.5f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 1.f, 0.f, 0.5f));
		m_pHud->m_Geometry = ghud;

		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f + 5.f, (float)getHeight ()*8.f/10.f + 5.f, -0.15f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f + 10.f, (float)getHeight ()*8.f/10.f + 5.f, -0.15f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f + 10.f, (float)getHeight ()*8.f/10.f + 10.f, -0.15f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f + 10.f, (float)getHeight ()*8.f/10.f + 10.f, -0.15f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f + 5.f, (float)getHeight ()*8.f/10.f + 10.f, -0.15f));
		ghud->m_vPoints.add (gsgeom::gsvec3f ((float)getWidth ()*9.f/10.f + 5.f, (float)getHeight ()*8.f/10.f + 5.f, -0.15f));

		ghud->m_vColors.add (gsgeom::gscolor (0.f, 0.f, 0.f, 1.f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 0.f, 0.f, 1.f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 0.f, 0.f, 1.f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 0.f, 0.f, 1.f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 0.f, 0.f, 1.f));
		ghud->m_vColors.add (gsgeom::gscolor (0.f, 0.f, 0.f, 1.f));

		gsgeom::gstextinfo *renderables = new gsgeom::gstextinfo;
		renderables->m_Position.set ((float)getWidth ()*9.f/10.f + 20.f, (float)getHeight ()*9.f/10.f + 5.f, -0.1f);
		renderables->m_Color.set (0.f, 0.f, 0.f, 1.f);
		renderables->m_Text = gsutil::gsstring ("FPS: ");
		m_pHud->m_vTextList.add (renderables);

		gsgeom::gstextinfo *ti = new gsgeom::gstextinfo;
		ti->m_Position.set ((float)getWidth ()*9.f/10.f + 20.f, (float)getHeight ()*8.f/10.f + 5.f, -0.1f);
		ti->m_Color.set (0.f, 0.f, 0.f, 1.f);
		ti->m_Text = gsutil::gsstring ("Hud");
		m_pHud->m_vTextList.add (ti);

		gsgeom::gscamera *chud = new gsgeom::gscamera;
		chud->setOrthogonal (getWidth (), getHeight (), 0.1f, 300.f);
		m_pHud->m_Camera = chud;

		m_pGrid->m_ChildNodes.add (m_pHud);
	}

	//adding scenes
	m_pKernel->addEvent (gsevent (GS_ADD_SCENE, m_pGrid));
	//m_pKernel->addEvent (gsevent (GS_ADD_SCENE, ModelEditorConfig::get ()->m_pCurrentScene));

	//creating tool window
	m_pTools = new ModelEditorTools (getWidth (), 0, 350, getHeight ());							
	add (m_pTools);
	m_pTools->show ();

	//creating options window
	m_pOptions = new ModelEditorOptions (getWidth (), 0, 350, getHeight ());
	add (m_pOptions);
	m_pOptions->show ();
	m_pTools->show ();
}

ModelEditor::~ModelEditor ()
{
	m_pKernel->shutdown ();

	delete m_pMainMenu;
	delete m_pTools;
	delete m_pKernel;

	ModelEditorConfig::get ()->m_pKernel = NULL;
}

void ModelEditor::handle ()
{
	while (m_iRun == 1)
		gswin::gswindow::handle ();
}

void ModelEditor::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wParam) == 0)
	{
		int icontrol = LOWORD (wParam);

		switch (icontrol)
		{
		case 0: //new
			break;

		case 1: //open
			{
				OPENFILENAME f;
				char buf[255] = "";
				memset (&f, 0, sizeof (f));
				f.lStructSize = sizeof (f);
				f.hwndOwner = getHandle ();
				f.lpstrFile = buf;
				f.lpstrFile[0] = '\0';
				f.nMaxFile = sizeof (buf);
				f.lpstrFilter = "Scene\0*.scene\0";
				f.nFilterIndex = 1;
				f.lpstrFileTitle = NULL;
				f.nMaxFileTitle = 0;
				f.lpstrInitialDir = NULL; //config will store this
				f.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;

				if (GetOpenFileName (&f) != 0)
				{
					gsstring pStr = (char*)f.lpstrFile;
					m_pCurrentScene = gssceneloader::read (pStr);

					if (!m_pCurrentScene->m_Camera)
					{
						gsgeom::gscamera *c = new gsgeom::gscamera;
						c->setProjection (getWidth (), getHeight (), 45.f, 1.f, 300.f);
						c->setView (gsgeom::gsvec3f (10, 10, 10),
									gsgeom::gsvec3f (0, 0, 0),
									gsgeom::gsvec3f (0, 1, 0));
						m_pCurrentScene->m_Camera = c;
					}

					m_pCurrentScene->m_ChildNodes.add (m_pCurrentScene);
				}
			}
			break;

		case 2: //close
			break;

		case 4: //save
			break;
		case 5: //save as
			break;
		case 6: //save as primitive
			{
				gsgeom::gsscene *s = ModelEditorConfig::get ()->m_pCurrentScene;
				//gs::gssceneloader::write (s, "name");

				//write out xml file. add button to the primitives list
			}
			break;

		case 8:
			onClose ();
			break;

		case 15:
			m_pTools->show ();
			break;

		case 16:
			m_pOptions->show ();
		}
	}
}

void ModelEditor::onClose ()
{
	WINDOWINFO wi;
	wi.cbSize = sizeof (WINDOWINFO);
	GetWindowInfo (getHandle (), &wi);
	ModelEditorConfig::WindowConfig wc;
	wc.x = wi.rcWindow.left;
	wc.y = wi.rcWindow.top;
	wc.w = wi.rcWindow.right - wi.rcWindow.left;
	wc.h = wi.rcWindow.bottom - wi.rcWindow.top;
	wc.winName = getClass ();

	ModelEditorConfig::get ()->setWindow (wc);

	m_pKernel->addEvent (gsevent (GS_QUIT, NULL));
	PostQuitMessage (0);

	for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		SendMessage (m_ChildWindows[x]->getHandle (), WM_CLOSE, 0, 0);

	m_iRun = 0;
}

void ModelEditor::onKeyDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	switch (wp)
	{
	case 'A':
		{
			ModelEditorAbout *mw = new ModelEditorAbout (getWidth ()/2 - 100, getHeight ()/2 - 100, 200, 200);
			mw->show ();
		}
		break;

	case VK_ESCAPE:
		SendMessage (getHandle (), WM_CLOSE, 0, 0);
		break;

	case VK_UP:
		{
			gsgeom::gscamera *c = ModelEditorConfig::get ()->m_pMainCamera;
			c->moveForward (-0.5f);
		}
		break;

	case VK_DOWN:
		{
			gsgeom::gscamera *c = ModelEditorConfig::get ()->m_pMainCamera;
			c->moveForward (0.5f);
		}
		break;
	}
}

void ModelEditor::onMouseLeftDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	m_bLeftButton = true;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);
}

void ModelEditor::onMouseLeftUp (void *wParam, void *lParam)
{
	m_bLeftButton = false;
}

void ModelEditor::onMouseRightDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);

	gsgeom::gscamera *c = ModelEditorConfig::get ()->m_pMainCamera;

	float fx = (float)x;
	float fy = (float)(getHeight () - y) - 48.f;
	gsgeom::gsray r = c->getPicked (fx, fy);

	if (m_bSelected)
	{
		m_pHud->m_Geometry->m_mutex.lock ();
		m_pHud->m_Geometry->m_vColors[6].set (0.f, 0.f, 0.f, 1.f);
		m_pHud->m_Geometry->m_vColors[7].set (0.f, 0.f, 0.f, 1.f);
		m_pHud->m_Geometry->m_vColors[8].set (0.f, 0.f, 0.f, 1.f);
		m_pHud->m_Geometry->m_vColors[9].set (0.f, 0.f, 0.f, 1.f);
		m_pHud->m_Geometry->m_vColors[10].set (0.f, 0.f, 0.f, 1.f);
		m_pHud->m_Geometry->m_vColors[11].set (0.f, 0.f, 0.f, 1.f);
		m_pHud->m_Geometry->m_mutex.unlock ();

		m_bSelected = false;

		if (gscol::gscollision::isRayIntersect (r, ModelEditorConfig::get ()->m_pCurrentScene))
		{
			gsgeom::gsvec3i index = gscol::gscollision::RayIntersectIndex (r, ModelEditorConfig::get ()->m_pCurrentScene);
			ModelEditorConfig::get ()->Index.set (index[0], index[1], index[2]);

			if (index[0] == -1 || index[1] == -1 || index[2] == -1)
			{
				m_pPicking->m_Geometry->m_mutex.lock ();
				m_pPicking->m_Geometry->m_vPoints.clear ();
				m_pPicking->m_Geometry->m_vColors.clear ();
				m_pPicking->m_Geometry->m_mutex.unlock ();
			}
			else
			{
				gsgeom::gsvec3f p1 = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_vPoints[index[0]];
				gsgeom::gsvec3f p2 = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_vPoints[index[1]];
				gsgeom::gsvec3f p3 = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_vPoints[index[2]];

				//same face as before?
				if ((p1 == m_pPicking->m_Geometry->m_vPoints[0]) && (p2 == m_pPicking->m_Geometry->m_vPoints[2]) &&	(p3 == m_pPicking->m_Geometry->m_vPoints[4]) ||
					(p2 == m_pPicking->m_Geometry->m_vPoints[0]) && (p3 == m_pPicking->m_Geometry->m_vPoints[2]) &&	(p1 == m_pPicking->m_Geometry->m_vPoints[4]) ||
					(p3 == m_pPicking->m_Geometry->m_vPoints[0]) && (p1 == m_pPicking->m_Geometry->m_vPoints[2]) &&	(p2 == m_pPicking->m_Geometry->m_vPoints[4]))
				{
					ModelEditorConfig::get ()->Index.set (-1, -1, -1);

					m_pPicking->m_Geometry->m_mutex.lock ();
					m_pPicking->m_Geometry->m_vPoints.clear ();
					m_pPicking->m_Geometry->m_vColors.clear ();
					m_pPicking->m_Geometry->m_mutex.unlock ();
				}
				else
				{
					m_pHud->m_Geometry->m_mutex.lock ();
					m_pHud->m_Geometry->m_vColors[6].set (1.f, 1.f, 0.f, 1.f);
					m_pHud->m_Geometry->m_vColors[7].set (1.f, 1.f, 0.f, 1.f);
					m_pHud->m_Geometry->m_vColors[8].set (1.f, 1.f, 0.f, 1.f);
					m_pHud->m_Geometry->m_vColors[9].set (1.f, 1.f, 0.f, 1.f);
					m_pHud->m_Geometry->m_vColors[10].set (1.f, 1.f, 0.f, 1.f);
					m_pHud->m_Geometry->m_vColors[11].set (1.f, 1.f, 0.f, 1.f);
					m_pHud->m_Geometry->m_mutex.unlock ();

					m_pPicking->m_Geometry->m_mutex.lock ();
					m_pPicking->m_Geometry->m_vPoints[0] = p1;
					m_pPicking->m_Geometry->m_vPoints[1] = p2;
					m_pPicking->m_Geometry->m_vPoints[2] = p2;
					m_pPicking->m_Geometry->m_vPoints[3] = p3;
					m_pPicking->m_Geometry->m_vPoints[4] = p3;
					m_pPicking->m_Geometry->m_vPoints[5] = p1;
					m_pPicking->m_Geometry->m_mutex.unlock ();

					m_bSelected = true;
				}
			}
		}
		else
		{
			m_pPicking->m_Geometry->m_mutex.lock ();
			m_pPicking->m_Geometry->m_vPoints.clear ();
			m_pPicking->m_Geometry->m_vColors.clear ();
			m_pPicking->m_Geometry->m_mutex.unlock ();
		}
	}
	else
	{
		if (gscol::gscollision::isRayIntersect (r, ModelEditorConfig::get ()->m_pCurrentScene))
		{
			m_pHud->m_Geometry->m_mutex.lock ();
			m_pHud->m_Geometry->m_vColors[6].set (1.f, 1.f, 0.f, 1.f);
			m_pHud->m_Geometry->m_vColors[7].set (1.f, 1.f, 0.f, 1.f);
			m_pHud->m_Geometry->m_vColors[8].set (1.f, 1.f, 0.f, 1.f);
			m_pHud->m_Geometry->m_vColors[9].set (1.f, 1.f, 0.f, 1.f);
			m_pHud->m_Geometry->m_vColors[10].set (1.f, 1.f, 0.f, 1.f);
			m_pHud->m_Geometry->m_vColors[11].set (1.f, 1.f, 0.f, 1.f);
			m_pHud->m_Geometry->m_mutex.unlock ();

			//TODO:
			//gsgeom::gsvec3i index = gscol::gscollision::RayIntersectIndex (r, ModelEditorConfig::get ()->m_pCurrentScene);
			//ModelEditorConfig::get ()->Index.set (index[0], index[1], index[2]);
			
			//gsgeom::gsvec3f p1 = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_vPoints[index[0]];
			//gsgeom::gsvec3f p2 = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_vPoints[index[1]];
			//gsgeom::gsvec3f p3 = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_vPoints[index[2]];

			//gsgeom::gsface f;
			//f.setFace (p1, p2, p3);

			//m_pPicking->m_Geometry->m_mutex.lock ();
			//m_pPicking->m_Geometry->m_vPoints.add (f.getP1 ());
			//m_pPicking->m_Geometry->m_vPoints.add (f.getP2 ());
			//m_pPicking->m_Geometry->m_vPoints.add (f.getP2 ());
			//m_pPicking->m_Geometry->m_vPoints.add (f.getP3 ());
			//m_pPicking->m_Geometry->m_vPoints.add (f.getP3 ());
			//m_pPicking->m_Geometry->m_vPoints.add (f.getP1 ());

			//m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));
			//m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));
			//m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));
			//m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));
			//m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));
			//m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 0, 1));
			//m_pPicking->m_Geometry->m_mutex.unlock ();

			m_bSelected = true;
		}
	}
}

void ModelEditor::onMouseMove (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);

	gsgeom::gscamera *c = ModelEditorConfig::get ()->m_pMainCamera;
	if (wp == MK_LBUTTON && m_bLeftButton)
	{
		float difx = (float)(x - oldx)*0.05f;
		float dify = (float)(y - oldy)*0.05f;

		//x direction
		c->pitch (dify);

		//y direction
		c->yaw (difx);
	}

	oldx = x;
	oldy = y;
}

void ModelEditor::onMouseWheel (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	gsgeom::gscamera *c = ModelEditorConfig::get ()->m_pMainCamera;
	short w = HIWORD (wp);

	float dx = -w/120.f;

	c->moveForward (dx);
}
