#include "ModelEditorOptions.h"

ModelEditorOptions::ModelEditorOptions (const int &x, const int &y, const int &w, const int &h) : gswin::gswindow (0, "ModelEditorOptions",
	"Options", WS_OVERLAPPEDWINDOW, x, y, w, h)
{
	ModelEditorConfig::WindowConfig *wc = ModelEditorConfig::get ()->getWindow (getClass ());
	if (wc)
		resize (wc->x, wc->y, wc->w, wc->h);

	m_pCtl = new ModelEditorOptionsCtl (this);
}

ModelEditorOptions::~ModelEditorOptions ()
{
}

void ModelEditorOptions::onClose ()
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

	for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		m_ChildWindows[x]->onClose ();

	hide ();
}
