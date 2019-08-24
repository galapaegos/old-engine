#ifndef _ModelEditorTools_h_
#define _ModelEditorTools_h_

#include "gswindow/gswindow.h"

#include "ModelEditorToolsCtl.h"
#include "../ModelEditorConfig.h"

class ModelEditorTools : public gswin::gswindow
{
public:
	ModelEditorTools (const int &x, const int &y, const int &w, const int &h);
	virtual ~ModelEditorTools ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);
	virtual void onKeyDown (void *wParam, void *lParam);
	virtual void onNotify (void *wParam, void *lParam);

private:
	ModelEditorToolsCtl *m_pTabCtl;
};

#endif
