#include "ModelEditorToolsShadersPanel.h"

ModelEditorToolsShadersPanel::ModelEditorToolsShadersPanel (gswidget *parent) :
	gswin::gstabpanel (0, "STATIC", "Shaders", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	m_strShaderDirectory = ModelEditorConfig::get ()->getParser ()->find ("/Config/Shaders");

	//int count = gsutil::gssystem::getDirectorySize (m_strSearchDirectory, "bmp");

	//gsutil::gsarray <gsutil::gsstring> textures (count);
	//gsutil::gssystem::getDirectoryList (m_strSearchDirectory, "vert", textures);

	//m_pListBox = new gswin::gslistbox ("ListBox", WS_CHILD|LBS_HASSTRINGS|WS_VISIBLE, 5, 5, getWidth () - 30, getHeight () - 30, this);
	//for (int j = 0; j < textures.getSize (); j++)
	//	m_pListBox->add (textures[j]);
	//m_pListBox->show ();
}

ModelEditorToolsShadersPanel::~ModelEditorToolsShadersPanel ()
{
}

void ModelEditorToolsShadersPanel::onClose ()
{
}
