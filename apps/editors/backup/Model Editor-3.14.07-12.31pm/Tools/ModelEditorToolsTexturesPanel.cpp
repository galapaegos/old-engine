#include "ModelEditorToolsTexturesPanel.h"

ModelEditorToolsTexturesPanel::ModelEditorToolsTexturesPanel (gswidget *parent) :
	gswin::gstabpanel (0, "STATIC", "Textures", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	m_strSearchDirectory = ModelEditorConfig::get ()->getParser ()->find ("/Config/Textures");
	gsutil::gsstring cwd = gsutil::gssystem::getCurrentDirectory ();

	int count = gsutil::gssystem::getDirectorySize (m_strSearchDirectory, "bmp");

	gsutil::gsarray <gsutil::gsstring> textures (count);
	gsutil::gssystem::getDirectoryList (m_strSearchDirectory, "bmp", textures);

	m_pListBox = new gswin::gslistbox (this, "ListBox", gswin::gsLISTBOX_STANDARD, 5, 5, getWidth () - 25, getHeight () - 55);
	for (unsigned int j = 0; j < textures.getSize (); j++)
		m_pListBox->add (textures[j]);
	m_pListBox->show ();

	textures.clear ();

	m_pOk = new gswin::gsbutton (this, "Ok", BS_PUSHBUTTON|WS_CHILD, 5, getHeight () - 50, getWidth ()/3 - 25, 25);
	m_pApply = new gswin::gsbutton (this, "Apply", BS_PUSHBUTTON|WS_CHILD, getWidth ()/3 + 5, getHeight () - 50, getWidth ()/3 - 25, 25);
	m_pCancel = new gswin::gsbutton (this, "Cancel", BS_PUSHBUTTON|WS_CHILD, getWidth ()*2/3 + 5, getHeight () - 50, getWidth ()/3 - 25, 25);
}

ModelEditorToolsTexturesPanel::~ModelEditorToolsTexturesPanel ()
{
}

void ModelEditorToolsTexturesPanel::onClose ()
{
}

void ModelEditorToolsTexturesPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wp) == LBN_DBLCLK)
	{
		ModelEditorToolsTexturesPreview *preview = new ModelEditorToolsTexturesPreview (0, "ModelEditorToolsTexturesPreview",
			m_strSearchDirectory + m_pListBox->getSelectedItem (), WS_OVERLAPPEDWINDOW, 0, 0, 0, 0);
		preview->show ();
	}

	if ((HWND)lp == m_pApply->getHandle ())
	{
		int p1 = 0, p2 = 0, p3 = 0;
		p1 = ModelEditorConfig::get ()->Index.getX ();
		p2 = ModelEditorConfig::get ()->Index.getY ();
		p3 = ModelEditorConfig::get ()->Index.getZ ();

		if (p1 == -1 || p2 == -1 || p3 == -1)
		{
			MessageBox (NULL, "Please select primitive to color", "Message", MB_OK);
			return;
		}

		gsgeom::gsgeometryinfo *g = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry;
		//g->m_vColors[p1] = m_Color;
		//g->m_vColors[p2] = m_Color;
		//g->m_vColors[p3] = m_Color;
	}
}
