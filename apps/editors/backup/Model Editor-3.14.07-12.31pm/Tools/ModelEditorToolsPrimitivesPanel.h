#ifndef _ModelEditorToolsPrimitivesPanel_h_
#define _ModelEditorToolsPrimitivesPanel_h_

#include "gswindow/gsbutton.h"
#include "gswindow/gstabpanel.h"

#include "../ModelEditorConfig.h"

class ModelEditorToolsPrimitivesPanel : public gswin::gstabpanel
{
public:
	ModelEditorToolsPrimitivesPanel (gswidget *parent);
	virtual ~ModelEditorToolsPrimitivesPanel ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

private:
	gsutil::gsstring m_strPrimitiveDirectory;
	int currentx, currenty;
	gsutil::gsarray <gsutil::gsstring> m_strPrimList;
	gsutil::gsqueue <gsgeom::gsscene*> m_pPrimList;
};

#endif
