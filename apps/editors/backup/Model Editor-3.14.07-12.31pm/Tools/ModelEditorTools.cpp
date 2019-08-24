#include "ModelEditorTools.h"

ModelEditorTools::ModelEditorTools (const int &x, const int &y, const int &w, const int &h) : 
	gswin::gswindow (0, "ModelEditorTools", "Model Editing Tools", WS_OVERLAPPEDWINDOW, x, y, w, h)
{
	ModelEditorConfig::WindowConfig *wc = ModelEditorConfig::get ()->getWindow (getClass ());
	if (wc && wc->x > 0 && wc->y > 0 && wc->w > 0 && wc->h > 0)
		resize (wc->x, wc->y, wc->w, wc->h);

	m_pTabCtl = new ModelEditorToolsCtl (this);
}

ModelEditorTools::~ModelEditorTools ()
{
}

void ModelEditorTools::onNotify (void *wParam, void *lParam)
{
	m_pTabCtl->onNotify (wParam, lParam);
}

void ModelEditorTools::onKeyDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;
}

void ModelEditorTools::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;
}

void ModelEditorTools::onClose ()
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

	//for (int x = 0; x < m_ChildWindows.getSize (); x++)
	//	SendMessage (m_ChildWindows[x]->getHandle (), WM_CLOSE, 0, 0);

	for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		m_ChildWindows[x]->onClose ();

	hide ();
}

