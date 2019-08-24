#include "TriangulatePanel.h"
#include "../TerrainConfig.h"

TriangulatePanel::TriangulatePanel (const unsigned long &exStyle, const gsutil::gsstring &c, const gsutil::gsstring &t, const unsigned long &style, gswidget *parent) : gswin::gstabpanel (
	exStyle, c, t, style, parent)
{
	gswin::gsvbox *b = new gswin::gsvbox (this);

	gswin::gshbox *d = new gswin::gshbox (this);
	d->add (new gswin::gsdescription (this, "Iterations:"));
	m_pIterations = new gswin::gstextbox (this, "", gswin::gsTEXT_LEFT);
	d->add (m_pIterations);
	b->add (d);

	gswin::gshbox *f = new gswin::gshbox (this);
	b->add (f);
	gswin::gshbox *g = new gswin::gshbox (this);
	b->add (g);
	gswin::gshbox *h = new gswin::gshbox (this);
	b->add (h);
	gswin::gshbox *i = new gswin::gshbox (this);
	b->add (i);

	m_pOk = new gswin::gsbutton (this, "Ok");
	b->add (m_pOk);
}

TriangulatePanel::~TriangulatePanel ()
{
}

void TriangulatePanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if ((HWND)lp == m_pOk->getHandle ())
	{
		int i = atoi (m_pIterations->getText ().str ());

		if (i <= 0)
		{
			MessageBox (NULL, "Please input iteration >= 1.", "Error", MB_OK);
			return;
		}

		gsgeom::gsscene *s = TerrainConfig::get ()->m_pScene;
		for (unsigned int x = 0; x < s->m_Geometry->m_vIndices.getSize (); x++)
		{
			TerrainConfig::get ()->m_pScene->m_Scene.lock ();
			subdivideSmooth (s, i);
			TerrainConfig::get ()->m_pScene->m_Scene.unlock ();
		}
	}
}

void TriangulatePanel::subdivideSmooth (gsgeom::gsscene *s, const int &levels)
{
	if (levels <= 0)
		return;

	s->m_Scene.lock ();
	for (unsigned int x = 0; x < s->m_Geometry->m_vIndices.getSize (); x++)
	{
		gsgeom::gsgeometryinfo::IndexType *it = s->m_Geometry->m_vIndices[x];
		switch (it->indexType)
		{
		case gsgeom::gsgeometryinfo::GS_TRIANGLE:
			{
				gsutil::gsarray <unsigned int> newIndices;
				for (unsigned int y = 0; y < it->m_vIndices.getSize (); y+=3)
				{
					unsigned int index1 = it->m_vIndices[y + 0];
					unsigned int index2 = it->m_vIndices[y + 1];
					unsigned int index3 = it->m_vIndices[y + 2];
					gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[index1];
					gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[index2];
					gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[index3];

					gsgeom::gsvec3f np1 = (p1 + p2)/2;
					gsgeom::gsvec3f np2 = (p2 + p3)/2;
					gsgeom::gsvec3f np3 = (p3 + p1)/2;

					s->m_Geometry->m_vPoints.add (np1);
					s->m_Geometry->m_vPoints.add (np2);
					s->m_Geometry->m_vPoints.add (np3);

					newIndices.add (index1);
					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 3);
					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 1);

					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 3);
					newIndices.add (index2);
					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 2);

					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 2);
					newIndices.add (index3);
					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 1);

					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 1);
					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 3);
					newIndices.add (s->m_Geometry->m_vPoints.getSize () - 2);
				}
				it->m_vIndices.resize (newIndices.getSize ());
				for (unsigned int z = 0; z < newIndices.getSize (); z++)
					it->m_vIndices.add (newIndices[z]);
			}
			break;

		case gsgeom::gsgeometryinfo::GS_SQUARE:
			{
				for (unsigned int y = 0; y < it->m_vIndices.getSize (); y+=4)
				{
					gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[it->m_vIndices[y + 0]];
					gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[it->m_vIndices[y + 1]];
					gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[it->m_vIndices[y + 2]];
					gsgeom::gsvec3f p4 = s->m_Geometry->m_vPoints[it->m_vIndices[y + 3]];

					gsgeom::gsvec3f centroid1 = (1/3)*p1 + (1/3)*p2 + (1/3)*p3;
					gsgeom::gsvec3f centroid2 = (1/3)*p2 + (1/3)*p3 + (1/3)*p4;

					s->m_Geometry->m_vPoints.add (centroid1);
					s->m_Geometry->m_vPoints.add (centroid2);
				}
			}
			break;
		}
	}
	s->m_Scene.unlock ();

	subdivideSmooth (s, levels - 1);
}
