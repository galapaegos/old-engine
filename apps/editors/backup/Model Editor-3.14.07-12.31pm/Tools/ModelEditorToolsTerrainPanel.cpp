#include "ModelEditorToolsTerrainPanel.h"

ModelEditorToolsTerrainPanel::ModelEditorToolsTerrainPanel (gswidget *parent) : 
	gswin::gstabpanel (0, "STATIC", "Terrain", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	gswin::gsdescription *dw = new gswin::gsdescription (this, "width:", 5, 5, 60, 20);
	m_pWidth = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 80, 5, 50, 20);
	gswin::gsdescription *dh = new gswin::gsdescription (this, "height:", 5, 35, 600, 20);
	m_pHeight = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 80, 35, 50, 20);

	gswin::gsdescription *ox = new gswin::gsdescription (this, "X Offset:", 155, 5, 60, 20);
	m_pXOffset = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 230, 5, 50, 20);
	gswin::gsdescription *oy = new gswin::gsdescription (this, "Y Offset:", 155, 35, 60, 20);
	m_pYOffset = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 230, 35, 50, 20);
	gswin::gsdescription *oz = new gswin::gsdescription (this, "Z Offset:", 155, 65, 60, 20);
	m_pZOffset = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 230, 65, 50, 20);

	m_pOk = new gswin::gsbutton (this, "Ok", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, getWidth ()/8, getHeight () - 60, getWidth ()/4, 25);
	m_pCancel = new gswin::gsbutton (this, "Cancel", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, getWidth ()*5/8, getHeight () - 60, getWidth ()/4, 25);
}

ModelEditorToolsTerrainPanel::~ModelEditorToolsTerrainPanel ()
{
}

void ModelEditorToolsTerrainPanel::onClose ()
{
}

void ModelEditorToolsTerrainPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if ((HWND)lp == m_pOk->getHandle ())
	{
		int w = atoi (m_pWidth->getText ().str ());
		int h = atoi (m_pHeight->getText ().str ());

		int i = atoi (m_pXOffset->getText ().str ());
		int j = atoi (m_pYOffset->getText ().str ());
		int k = atoi (m_pZOffset->getText ().str ());

		if (w <= 0 || h <= 0)
			return;

		//terrain generation: adding the generated terrain as a child to the current scene
		//gsgeom::gsscene *s = new gsgeom::gsscene;
		//s->m_strName = "terrain";
		//gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_mutex.lock ();
		gsgeom::gsgeometryinfo *gi = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry;
		for (int x = 0; x < w; x++)
		{
			for (int y = 0; y < h; y++)
			{
				gi->m_vPoints.add (gsgeom::gsvec3f ((float)(i + x), (float)(j), (float)(k + y)));
			}
		}

		for (int x = 0; x < w; x++)
		{
			for (int y = 0; y < h; y++)
			{
				gi->m_vColors.add (gsgeom::gscolor (float (x/w), float (y/h), float (x/w) - 1.f, float (y/h) - 1.f));
			}
		}

		gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
		it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;

		for (int x = 0; x < w - 1; x++)
		{
			for (int y = 0; y < h - 1; y++)
			{
				it->m_vIndices.add (w*x + y);
				it->m_vIndices.add (w*x + y + 1);
				it->m_vIndices.add (w*(x + 1) + y + 1);

				it->m_vIndices.add (w*(x + 1) + y + 1);
				it->m_vIndices.add (w*(x + 1) + y);
				it->m_vIndices.add (w*x + y);
			}
		}
		gi->m_vIndices.add (it);
		//s->m_Geometry = gi;
		//ModelEditorConfig::get ()->m_pCurrentScene->m_ChildNodes.add (s);
		ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry->m_mutex.unlock ();
	}
}
