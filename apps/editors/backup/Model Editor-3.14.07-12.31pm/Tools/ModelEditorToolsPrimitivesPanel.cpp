#include "ModelEditorToolsPrimitivesPanel.h"

ModelEditorToolsPrimitivesPanel::ModelEditorToolsPrimitivesPanel (gswidget *parent) : 
	gswin::gstabpanel (0, "STATIC", "Primitives", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	currentx = 5;
	currenty = 5;

	m_strPrimitiveDirectory = ModelEditorConfig::get ()->getParser ()->find ("/Config/Primitives/Directory");
	gsutil::gsXMLElement *root = ModelEditorConfig::get ()->getParser ()->findElement ("/Config/Primitives");

	int count = gsutil::gssystem::getDirectorySize (m_strPrimitiveDirectory, "scene");

	m_strPrimList.resize (count);
	//gsutil::gssystem::getDirectoryList (m_strPrimitiveDirectory, "scene", m_strPrimList);

	if (root)
	{
		for (unsigned int j = 0; j < root->getChildrenSize (); j++)
		{
			gsutil::gsXMLElement *child = root->getChild (j);
			if (child->getName () == "Directory")
				continue;

			gsutil::gsstring label = child->getAttribute ("label");
			gsutil::gsstring file = m_strPrimitiveDirectory + child->getValue ();
			gswin::gsbutton *b = new gswin::gsbutton (this, label, BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, currentx, currenty, 25, 25);
			add (b);

			m_strPrimList.add (file);

			m_pPrimList.add (gs::gssceneloader::read (file));

			currentx += 30;
			if (currentx > getWidth ())
			{
				currentx = 5;
				currenty += 30;
			}
		}
	}
}

ModelEditorToolsPrimitivesPanel::~ModelEditorToolsPrimitivesPanel ()
{
}

void ModelEditorToolsPrimitivesPanel::onClose ()
{
	if (m_strPrimitiveDirectory.size () > 0)
	{
		gsutil::gsXMLElement *e = ModelEditorConfig::get ()->getParser ()->findElement ("/Config/Primitives/Directory");
		e->setValue (m_strPrimitiveDirectory);
	}
}

void ModelEditorToolsPrimitivesPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wp) == BN_CLICKED)
	{
		for (unsigned int x = 0; x < m_ChildWindows.getSize (); x++)
		{
			if ((HWND)lp == m_ChildWindows[x]->getHandle ())
			{
				//TODO: watch the type
				gsgeom::gsscene *curScene = ModelEditorConfig::get ()->m_pCurrentScene;
				gsgeom::gsgeometryinfo *gi = NULL;

				if (!curScene)
					ModelEditorConfig::get ()->m_pCurrentScene = new gsgeom::gsscene;

				if (!curScene->m_Geometry)
				{
					gi = new gsgeom::gsgeometryinfo;
					curScene->m_Geometry = gi;
				}
				else
					gi = curScene->m_Geometry;

				for (unsigned int y = 0; y < m_pPrimList[x]->m_Geometry->m_vPoints.getSize (); y++)
					gi->m_vPoints.add (m_pPrimList[x]->m_Geometry->m_vPoints[y]);

				for (unsigned int y = 0; y < m_pPrimList[x]->m_Geometry->m_vNormals.getSize (); y++)
					gi->m_vNormals.add (m_pPrimList[x]->m_Geometry->m_vNormals[y]);

				for (unsigned int y = 0; y < m_pPrimList[x]->m_Geometry->m_vColors.getSize (); y++)
					gi->m_vColors.add (m_pPrimList[x]->m_Geometry->m_vColors[y]);

				for (unsigned int y = 0; y < m_pPrimList[x]->m_Geometry->m_vIndices.getSize (); y++)
					gi->m_vIndices.add (m_pPrimList[x]->m_Geometry->m_vIndices[y]);

				for (unsigned int y = 0; y < m_pPrimList[x]->m_Geometry->m_vTexCoordinates.getSize (); y++)
					gi->m_vTexCoordinates.add (m_pPrimList[x]->m_Geometry->m_vTexCoordinates[y]);
			}
		}
	}
}
