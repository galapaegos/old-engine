#ifndef _CreatePanel_h_
#define _CreatePanel_h_

#include <gsgeom/gsscene.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gsdescription.h>
#include <gswindow/gstabpanel.h>
#include <gswindow/gstextbox.h>

#include "data.h"

enum
{
	BUTTON_TRIANGLE,
	BUTTON_SQUARE,
	BUTTON_CUBE,
	BUTTON_SPHERE,

	SCALE,
	TRANSLATEX,
	TRANSLATEY,
	TRANSLATEZ,
	ROTATEX,
	ROTATEY,
	ROTATEZ
};

class CreatePanel : public gswin::gstabpanel
{
public:
	CreatePanel (data *d, gswin::gswidget *parent);
	~CreatePanel ();

	virtual void onCommand (void *wParam, void *lParam);
private:
	data *m_pData;
};

#endif
