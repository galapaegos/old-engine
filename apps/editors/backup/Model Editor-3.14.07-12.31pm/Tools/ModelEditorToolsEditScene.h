#ifndef _ModelEditorToolsEditScene_h_
#define _ModelEditorToolsEditScene_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsbutton.h"
#include "gswindow/gslistbox.h"
#include "gswindow/gswindow.h"

#include "../ModelEditorConfig.h"

//Edit Scene positioning, so we can merge scenes together or break them apart
class ModelEditorToolsEditScene : public gswin::gswindow
{
public:
	ModelEditorToolsEditScene (gsgeom::gsscene *s, const int &x, const int &y, const int &w, const int &h);
	virtual ~ModelEditorToolsEditScene ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

	virtual void refreshScene ();

protected:
	gswin::gslistbox *m_pPoints, *m_pIndices, *m_pNormals, *m_pColors, *m_pTexCoords;
	gswin::gsbutton *m_pRefresh, *m_pOk;

	gsgeom::gsscene *m_pCurrentScene;
};

#endif
