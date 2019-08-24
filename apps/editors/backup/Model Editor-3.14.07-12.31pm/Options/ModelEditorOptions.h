#ifndef _ModelEditorOptions_h_
#define _ModelEditorOptions_h_

#include "gswindow/gswindow.h"
#include "ModelEditorOptionsCtl.h"
#include "../ModelEditorConfig.h"

class ModelEditorOptions : public gswin::gswindow
{
public:
	ModelEditorOptions (const int &x, const int &y, const int &w, const int &h);
	virtual ~ModelEditorOptions ();

	virtual void onClose ();

private:
	ModelEditorOptionsCtl *m_pCtl;
};

#endif