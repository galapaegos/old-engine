#include "GenerateTiles.h"

GenerateTiles::GenerateTiles (const int &x, const int &y, const int &w, const int &h) : gswin::gswindow (0, 
	 "GenerateTiles", "Generate Tiles", WS_OVERLAPPEDWINDOW, x, y, w, h)
{
	gswin::gsdescription *pWidthDesc = new gswin::gsdescription ("Number of width tiles:", 5, 5, 120, 25, this);
	m_pWidth = new gswin::gstextbox ("", WS_CHILD|ES_LEFT, 130, 5, 50, 25, this);

	gswin::gsdescription *pHeightDesc = new gswin::gsdescription ("Number of height tiles:", 5, 35, 120, 25, this);
	m_pHeight = new gswin::gstextbox ("", WS_CHILD|ES_LEFT, 130, 35, 50, 25, this);

	m_pOk = new gswin::gsbutton ("Ok", BS_PUSHBUTTON|WS_CHILD, 5, 70, w/2 - 10, 25, this);
	m_pCancel = new gswin::gsbutton ("Cancel", BS_PUSHBUTTON|WS_CHILD, w/2 + 5, 70, w/2 - 10, 25, this);
}

GenerateTiles::~GenerateTiles ()
{
}

void GenerateTiles::onClose ()
{
	delete this;
}

void GenerateTiles::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if ((HWND)lp == m_pOk->getHandle ())
	{
		int w = atoi (m_pWidth->getText ().str ());
		int h = atoi (m_pHeight->getText ().str ());

		if (w == 0 || h == 0)
			return;

		gsgeom::gsscene *s = TileConfig::get ()->m_pScene;

		s->m_Geometry->m_mutex.lock ();

		gsutil::gsarray <gsgeom::gsvec3f> temp;
		temp.resize (w*h);
		for (int x = 0; x < w; x++)
			for (int y = 0; y < h; y++)
				temp.add (gsgeom::gsvec3f ((float)x, 0, (float)y));

		for (int x = 0; x < w - 1; x++)
		{
			for (int y = 0; y < h - 1; y++)
			{
				gsgeom::gsscene *child = new gsgeom::gsscene;
				s->m_ChildNodes.add (child);

				gsgeom::gseffect *effect  = new gsgeom::gseffect;
				effect->setLineSettings (true);
				effect->setLineWidth (3.f);
				child->m_pEffect = effect;

				gsgeom::gsgeometryinfo *g = new gsgeom::gsgeometryinfo;
				child->m_Geometry = g;

				g->m_vPoints.add (temp[w*x + y]);
				g->m_vPoints.add (temp[w*x + y + 1]);
				g->m_vPoints.add (temp[w*(x + 1) + y + 1]);
				g->m_vPoints.add (temp[w*(x + 1) + y]);

				g->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
				g->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
				g->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
				g->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));

				gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
				g->m_vIndices.add (i);
				i->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
				i->m_vIndices.add (0);
				i->m_vIndices.add (1);
				i->m_vIndices.add (2);
				i->m_vIndices.add (2);
				i->m_vIndices.add (3);
				i->m_vIndices.add (0);
			}
		}

		s->m_Geometry->m_mutex.unlock ();

		temp.clear ();

		delete this;
	}
	else if ((HWND)lp == m_pCancel->getHandle ())
	{
		delete this;
	}
}
