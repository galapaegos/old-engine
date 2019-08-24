#include "ModifyPanel.h"
#include "../TerrainConfig.h"

ModifyPanel::ModifyPanel (const unsigned long &exStyle, const gsutil::gsstring &c, 
	const gsutil::gsstring &t, const unsigned long &style, gswidget *parent) : 
	gswin::gstabpanel (exStyle, c, t, style, parent)
{
	gswin::gsvbox *b = new gswin::gsvbox (this);

	gswin::gshbox *d = new gswin::gshbox (this);
	m_pFlatten = new gswin::gsbutton (this, "Lower", gsBUTTON_AUTOCHECKBOX|gsBUTTON_PUSHLIKE);
	d->add (m_pFlatten);
	b->add (d);

	gswin::gshbox *e = new gswin::gshbox (this);
	m_pRaise = new gswin::gsbutton (this, "Raise", gsBUTTON_AUTOCHECKBOX|gsBUTTON_PUSHLIKE);
	e->add (m_pRaise);
	b->add (e);

	gswin::gshbox *f = new gswin::gshbox (this);
	b->add (f);
	gswin::gshbox *g = new gswin::gshbox (this);
	b->add (g);
	gswin::gshbox *h = new gswin::gshbox (this);
	b->add (h);
	gswin::gshbox *i = new gswin::gshbox (this);
	b->add (i);
}

ModifyPanel::~ModifyPanel ()
{
}

void ModifyPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if ((HWND)lp == m_pFlatten->getHandle ())
	{
		if (!TerrainConfig::get ()->m_bFlatten)
			TerrainConfig::get ()->m_bFlatten = true;
		else
			TerrainConfig::get ()->m_bFlatten = false;
	}
	else if ((HWND)lp == m_pRaise->getHandle ())
	{
		if (!TerrainConfig::get ()->m_bRaise)
			TerrainConfig::get ()->m_bRaise = true;
		else
			TerrainConfig::get ()->m_bRaise = false;
	}
}
