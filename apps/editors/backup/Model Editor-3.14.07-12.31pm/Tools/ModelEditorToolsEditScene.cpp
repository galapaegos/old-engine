#include "ModelEditorToolsEditScene.h"

ModelEditorToolsEditScene::ModelEditorToolsEditScene (gsgeom::gsscene *s, const int &x, const int &y, const int &w, const int &h) : 
	gswin::gswindow (WS_EX_TOOLWINDOW, "ModelEditorToolsEditScene", "Edit Scene", WS_OVERLAPPEDWINDOW|WS_VISIBLE, x, y, w, h)
{
	m_pCurrentScene = s;
	m_pPoints = new gswin::gslistbox (this, "", WS_CHILD|LBS_STANDARD|LBS_HASSTRINGS|WS_VISIBLE, 5, 5, getWidth () - 20, getHeight ()/6);
	add (m_pPoints);

	m_pIndices = new gswin::gslistbox (this, "", WS_CHILD|LBS_STANDARD|LBS_HASSTRINGS|WS_VISIBLE, 5, getHeight ()/6 + 5, getWidth () - 20, getHeight ()/6);
	add (m_pIndices);

	m_pNormals = new gswin::gslistbox (this, "", WS_CHILD|LBS_STANDARD|LBS_HASSTRINGS|WS_VISIBLE, 5, getHeight ()/3 + 5, getWidth () - 20, getHeight ()/6);
	add (m_pNormals);

	m_pColors = new gswin::gslistbox (this, "", WS_CHILD|LBS_STANDARD|LBS_HASSTRINGS|WS_VISIBLE, 5, getHeight ()/2 + 5, getWidth () - 20, getHeight ()/6);
	add (m_pColors);

	m_pTexCoords = new gswin::gslistbox (this, "", WS_CHILD|LBS_STANDARD|LBS_HASSTRINGS|WS_VISIBLE, 5, getHeight ()*2/3 + 5, getWidth () - 20, getHeight ()/6);
	add (m_pTexCoords);

	refreshScene ();

	m_pOk = new gswin::gsbutton (this, "Ok", BS_PUSHBUTTON|WS_CHILD, getWidth ()/8, getHeight () - 60, getWidth ()/4, 25);
	m_pRefresh = new gswin::gsbutton (this, "Refresh", BS_PUSHBUTTON|WS_CHILD, getWidth ()*5/8, getHeight () - 60, getWidth ()/4, 25);

	setTitle (s->m_strName);
}

ModelEditorToolsEditScene::~ModelEditorToolsEditScene ()
{
}

void ModelEditorToolsEditScene::onClose ()
{
	DestroyWindow (getHandle ());
	UnregisterClass (getClass ().str (), getInst ());
	delete this;
}

void ModelEditorToolsEditScene::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if ((HWND)lp == m_pRefresh->getHandle ())
		refreshScene ();
}

void ModelEditorToolsEditScene::refreshScene ()
{
	if (!m_pCurrentScene)
		return;

	gsgeom::gsgeometryinfo *g = m_pCurrentScene->m_Geometry;

	m_pPoints->clear ();
	for (unsigned int i = 0; i < g->m_vPoints.getSize (); i++)
	{
		gsutil::gsstring point = gsutil::gsstring (g->m_vPoints[i].getX ()) + " " + gsutil::gsstring (g->m_vPoints[i].getY ()) + gsutil::gsstring (g->m_vPoints[i].getZ ());
		m_pPoints->add (point);
	}
	m_pPoints->show ();

	m_pIndices->clear ();
	for (unsigned int i = 0; i < g->m_vIndices.getSize (); i++)
	{
		m_pIndices->add (gsutil::gsstring ("type: ") + gsutil::gsstring (g->m_vIndices[i]->indexType));
		for (unsigned int j = 0; j < g->m_vIndices[i]->m_vIndices.getSize (); j++)
			m_pIndices->add (gsutil::gsstring (g->m_vIndices[i]->m_vIndices[j]));
	}
	m_pIndices->show ();

	m_pNormals->clear ();
	for (unsigned int i = 0; i < g->m_vNormals.getSize (); i++)
	{
		gsutil::gsstring point = gsutil::gsstring (g->m_vNormals[i].getX ()) + " " + gsutil::gsstring (g->m_vNormals[i].getY ()) + gsutil::gsstring (g->m_vNormals[i].getZ ());
		m_pNormals->add (point);
	}
	m_pNormals->show ();

	m_pColors->clear ();
	for (unsigned int i = 0; i < g->m_vColors.getSize (); i++)
	{
		gsutil::gsstring point = gsutil::gsstring (g->m_vColors[i].getR ()) + " " + gsutil::gsstring (g->m_vColors[i].getG ()) + " " + gsutil::gsstring (g->m_vColors[i].getB ()) + " " + gsutil::gsstring (g->m_vColors[i].getA ());
		m_pColors->add (point);
	}
	m_pColors->show ();

	m_pTexCoords->clear ();
	for (unsigned int i = 0; i < g->m_vTexCoordinates.getSize (); i++)
	{
		gsutil::gsstring point = gsutil::gsstring (g->m_vTexCoordinates[i].getX ()) + " " + gsutil::gsstring (g->m_vTexCoordinates[i].getY ());
		m_pTexCoords->add (point);
	}
	m_pTexCoords->show ();
}
