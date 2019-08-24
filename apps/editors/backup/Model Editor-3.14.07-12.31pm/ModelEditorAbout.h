#ifndef _ModelEditorAbout_h_
#define _ModelEditorAbout_h_

#include "gswindow/gswindow.h"

class ModelEditorAbout : public gswin::gswindow
{
public:
	ModelEditorAbout (const int &x, const int &y, const int &w, const int &h);
	virtual ~ModelEditorAbout ();

	virtual void onDestroy ();
};

#endif
