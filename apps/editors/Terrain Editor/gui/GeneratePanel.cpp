#include "GeneratePanel.h"
#include "../TerrainConfig.h"

GeneratePanel::GeneratePanel (const unsigned long &exStyle, const gsutil::gsstring &c, 
	const gsutil::gsstring &t, const unsigned long &style, gswidget *parent) : 
	gswin::gstabpanel (exStyle, c, t, style, parent)
{
	gswin::gsvbox *b = new gswin::gsvbox (this);
	
	gswin::gshbox *d = new gswin::gshbox (this);
	d->add (new gswin::gsdescription (this, "X:"));
	m_pX = new gswin::gstextbox (this, "", gswin::gsTEXT_LEFT);
	d->add (m_pX);
	b->add (d);

	gswin::gshbox *e = new gswin::gshbox (this);
	e->add (new gswin::gsdescription (this, "Y:"));
	m_pY = new gswin::gstextbox (this, "", gswin::gsTEXT_LEFT);
	e->add (m_pY);
	b->add (e);

	gswin::gshbox *f = new gswin::gshbox (this);
	f->add (new gswin::gsdescription (this, "Z:"));
	m_pZ = new gswin::gstextbox (this, "", gswin::gsTEXT_LEFT);
	f->add (m_pZ);
	b->add (f);
	
	gswin::gshbox *g = new gswin::gshbox (this);
	g->add (new gswin::gsdescription (this, "Width:"));
	m_pW = new gswin::gstextbox (this, "", gswin::gsTEXT_LEFT);
	g->add (m_pW);
	b->add (g);

	gswin::gshbox *h = new gswin::gshbox (this);
	h->add (new gswin::gsdescription (this, "Height:"));
	m_pH = new gswin::gstextbox (this, "", gswin::gsTEXT_LEFT);
	h->add (m_pH);
	b->add (h);

	m_pOk = new gswin::gsbutton (this, "Ok", gsBUTTON_PUSHBUTTON);
	b->add (m_pOk);

	gswin::gshbox *i = new gswin::gshbox (this);
	b->add (i);
	gswin::gshbox *j = new gswin::gshbox (this);
	b->add (j);
	gswin::gshbox *k = new gswin::gshbox (this);
	b->add (k);
	gswin::gshbox *l = new gswin::gshbox (this);
	b->add (l);
}

GeneratePanel::~GeneratePanel ()
{
}

void GeneratePanel::onCommand (void *wParam, void *lParam)
{
	LPARAM lp = (LPARAM)lParam;
	WPARAM wp = (WPARAM)wParam;

	if ((HWND)lp == m_pOk->getHandle ())
	{
		//x, y, z offset
		float x = (float)atof (m_pX->getText ().str ());
		float y = (float)atof (m_pY->getText ().str ());
		float z = (float)atof (m_pZ->getText ().str ());

		float w = (float)atof (m_pW->getText ().str ());
		float h = (float)atof (m_pH->getText ().str ());

		if (w == 0 || h == 0)
		{
			MessageBox (NULL, "Please input dimensions.", "error", MB_OK);
			return;
		}

		gsgeom::gsscene *s = TerrainConfig::get ()->m_pScene;
		if (!s)
			return;

		gsgeom::gsgeometryinfo *g = s->m_Geometry;
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				g->m_vPoints.add (gsgeom::gsvec3f (i + x, y, j + z));

		gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
		it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		for (int k = 0; k < (int)w - 1; k++)
		{
			for (int l = 0; l < (int)h - 1; l++)
			{
				it->m_vIndices.add ((int)w*k + l);
				it->m_vIndices.add ((int)w*k + l + 1);
				it->m_vIndices.add ((int)w*(k + 1) + l + 1);
				
				it->m_vIndices.add ((int)w*(k + 1) + l + 1);
				it->m_vIndices.add ((int)w*(k + 1) + l);
				it->m_vIndices.add ((int)w*k + l);
			}
		}

		g->m_vIndices.add (it);
	}
}
