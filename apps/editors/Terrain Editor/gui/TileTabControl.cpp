#include "TileTabControl.h"

#include "GeneratePanel.h"
#include "ModifyPanel.h"
#include "PaintPanel.h"
#include "RenderPanel.h"
#include "TriangulatePanel.h"

TileTabControl::TileTabControl (const unsigned long &exStyle, 
	const gsutil::gsstring &c, const gsutil::gsstring &t, 
	const unsigned long &style, const int &x, const int &y,	const int &w, 
	const int &h) : gswin::gswindow (exStyle, c, t, style, x, y, w, h)
{
	m_pTabCtl = new gswin::gstabctl (0, "TabControl", TCS_MULTILINE|WS_CHILD|WS_VISIBLE, this);

	GeneratePanel *gp = new GeneratePanel (0, "STATIC", "Generate Panel", gswin::gsWINDOW_GROUP|gswin::gsSTATIC_OWNERDRAW|gswin::gsWINDOW_CHILD|gswin::gsWINDOW_VISIBLE, m_pTabCtl);
	m_pTabCtl->add (gp);
	gp->show ();

	ModifyPanel *mp = new ModifyPanel (0, "STATIC", "Modify Panel", gswin::gsWINDOW_GROUP|gswin::gsSTATIC_OWNERDRAW|gswin::gsWINDOW_CHILD|gswin::gsWINDOW_VISIBLE, m_pTabCtl);
	m_pTabCtl->add (mp);
	mp->hide ();

	PaintPanel *pp = new PaintPanel (0, "STATIC", "Paint Panel", gswin::gsWINDOW_GROUP|gswin::gsSTATIC_OWNERDRAW|gswin::gsWINDOW_CHILD|gswin::gsWINDOW_VISIBLE, m_pTabCtl);
	m_pTabCtl->add (pp);
	pp->hide ();

	RenderPanel *rp = new RenderPanel (0, "STATIC", "Render Panel", gswin::gsWINDOW_GROUP|gswin::gsSTATIC_OWNERDRAW|gswin::gsWINDOW_CHILD|gswin::gsWINDOW_VISIBLE, m_pTabCtl);
	m_pTabCtl->add (rp);
	rp->hide ();

	TriangulatePanel *tp = new TriangulatePanel (0, "STATIC", "Triangulate Panel", gswin::gsWINDOW_GROUP|gswin::gsSTATIC_OWNERDRAW|gswin::gsWINDOW_CHILD|gswin::gsWINDOW_VISIBLE, m_pTabCtl);
	m_pTabCtl->add (tp);
	tp->hide ();
}

TileTabControl::~TileTabControl ()
{
}

void TileTabControl::onNotify (void *wParam, void *lParam)
{
	m_pTabCtl->onNotify (wParam, lParam);
}
