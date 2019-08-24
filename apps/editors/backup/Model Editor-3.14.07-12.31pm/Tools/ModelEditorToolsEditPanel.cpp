#include "ModelEditorToolsEditPanel.h"

ModelEditorToolsEditPanel::ModelEditorToolsEditPanel (gswidget *parent) : 
	gswin::gstabpanel (0, "STATIC", "Edit", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	m_pSceneList = new gswin::gslistbox (this, "Scene List", WS_CHILD|LBS_STANDARD|WS_VISIBLE, 5, 5, getWidth () - 25, getHeight () - 130);
	add (m_pSceneList);
	refreshList ();

	m_pAdd = new gswin::gsbutton (this, "Add", BS_PUSHBUTTON|WS_CHILD, 5, getHeight () - 125, getWidth ()/3 - 25, 25);
	add (m_pAdd);

	m_pAddAsChild = new gswin::gsbutton (this, "Add As Child", BS_PUSHBUTTON|WS_CHILD, getWidth ()/3 + 5, getHeight () - 125, getWidth ()/3 - 25, 25);
	add (m_pAddAsChild);

	m_pRemove = new gswin::gsbutton (this, "Remove", BS_PUSHBUTTON|WS_CHILD, getWidth ()*2/3 + 5, getHeight () - 125, getWidth ()/3 - 25, 25);
	add (m_pRemove);

	m_pMerge = new gswin::gsbutton (this, "Merge", BS_PUSHBUTTON|WS_CHILD, 5, getHeight () - 95, getWidth ()/3 - 25, 25);
	add (m_pMerge);

	m_pRefresh = new gswin::gsbutton (this, "Refresh", BS_PUSHBUTTON|WS_CHILD, getWidth ()/3 + 5, getHeight () - 95, getWidth ()/3 - 25, 25);
	add (m_pRefresh);
}

ModelEditorToolsEditPanel::~ModelEditorToolsEditPanel ()
{
}

void ModelEditorToolsEditPanel::onClose ()
{
}

void ModelEditorToolsEditPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if ((HWND)lp == m_pRefresh->getHandle ())
		refreshList ();

	if ((HIWORD (wp) == LBN_DBLCLK) && ((HWND)lp == m_pSceneList->getHandle ()))
	{
		int dskW = ModelEditorConfig::get ()->desktopWidth;
		int dskH = ModelEditorConfig::get ()->desktopHeight;
		ModelEditorToolsEditScene *es = new ModelEditorToolsEditScene (findScene (m_pSceneList->getSelected ()), 
			dskW/2 - 250, dskH/2 - 300, 500, 600);
		es->show ();
	}
}

void ModelEditorToolsEditPanel::refreshList ()
{
	m_pSceneList->clear ();
	//Can't do this, I need to put some locks around this before accessing it
	ModelEditorConfig::get ()->m_pKernel->m_pRenderMutex->lock ();
	for (unsigned int x = 0; x < ModelEditorConfig::get ()->m_pKernel->m_RenderQueue.getSize (); x++)
		refreshListHelper (ModelEditorConfig::get ()->m_pKernel->m_RenderQueue[x]);
	ModelEditorConfig::get ()->m_pKernel->m_pRenderMutex->unlock ();

	m_pSceneList->show ();
}

void ModelEditorToolsEditPanel::refreshListHelper (gsgeom::gsscene *s, int count)
{
	gsutil::gsstring temp;
	int i = 0;
	while (i < count)
	{
		temp += " ";
		i++;
	}
	temp += s->m_strName;

	m_pSceneList->add (temp);

	for (unsigned int x = 0; x < s->m_ChildNodes.getSize (); x++)
	{
		refreshListHelper (s->m_ChildNodes[x], count + 1);
	}
}

gsgeom::gsscene *ModelEditorToolsEditPanel::findScene (const int &x)
{
	countHelper = 0;

	for (unsigned int i = 0; i < ModelEditorConfig::get ()->m_pKernel->m_RenderQueue.getSize (); i++)
	{
		gsgeom::gsscene *s = findSceneHelper (ModelEditorConfig::get ()->m_pKernel->m_RenderQueue[i], x);
		if (s)
			return s;
	}

	return NULL;
}

gsgeom::gsscene *ModelEditorToolsEditPanel::findSceneHelper (gsgeom::gsscene *s, const int &x)
{
	if (x == countHelper)
		return s;

	for (unsigned int i = 0; i < s->m_ChildNodes.getSize (); i++)
	{
		countHelper ++;

		gsgeom::gsscene *scene = findSceneHelper (s->m_ChildNodes[i], x);
		if (scene)
			return scene;
	}

	return NULL;
}
