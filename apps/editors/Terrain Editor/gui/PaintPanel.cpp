#include "PaintPanel.h"

PaintPanel::PaintPanel (const unsigned long &exStyle, const gsutil::gsstring &c, 
	const gsutil::gsstring &t, const unsigned long &style, gswidget *parent) : 
	gswin::gstabpanel (exStyle, c, t, style, parent)
{
	gswin::gshbox *h = new gswin::gshbox (this);
	gswin::gsvbox *v1 = new gswin::gsvbox (this);
	{
		gswin::gshbox *h1 = new gswin::gshbox (this);
		h1->add (new gswin::gsdescription (this, "Texture unit 0:"));
		h1->add (new gswin::gsbutton (this, "Choose Texture"));
		v1->add (h1);
		gswin::gshbox *h2 = new gswin::gshbox (this);
		h2->add (new gswin::gsdescription (this, "Texture unit 1:"));
		h2->add (new gswin::gsbutton (this, "Choose Texture"));
		v1->add (h2);
		gswin::gshbox *h3 = new gswin::gshbox (this);
		h3->add (new gswin::gsdescription (this, "Texture unit 2:"));
		h3->add (new gswin::gsbutton (this, "Choose Texture"));
		v1->add (h3);
		gswin::gshbox *h4 = new gswin::gshbox (this);
		h4->add (new gswin::gsdescription (this, "Texture unit 3:"));
		h4->add (new gswin::gsbutton (this, "Choose Texture"));
		v1->add (h4);
	}
	h->add (v1);
	gswin::gsvbox *v2 = new gswin::gsvbox (this);
	{
		gswin::gshbox *hb = new gswin::gshbox (this);
		gswin::gscombobox *c = new gswin::gscombobox (this, "Combine", gswin::gsCOMBOBOX_DROPDOWNLIST);
		c->add ("replace");
		c->add ("modulate");
		c->add ("add");
		c->add ("addsigned");
		c->add ("interpolate");
		c->add ("subtract");
		c->add ("dot3");
		v2->add (c);

		gswin::gshbox *hc = new gswin::gshbox (this);
		hc->add (new gswin::gsdescription (this, "Arg0"));
		v2->add (hc);
	}
	h->add (v2);
}

PaintPanel::~PaintPanel ()
{
}

void PaintPanel::onNotify (void *wParam, void *lParam)
{
	//m_pTabCtrl->onNotify (wParam, lParam);
}
