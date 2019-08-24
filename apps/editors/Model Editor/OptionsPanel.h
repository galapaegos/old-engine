#ifndef _OptionsPanel_h_
#define _OptionsPanel_h_

#include <gsgeom/gsscene.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gslistbox.h>
#include <gswindow/gstabpanel.h>

#include "data.h"

class OptionsPanel : public gswin::gstabpanel
{
public:
	OptionsPanel (data *d, gswin::gswidget *parent);
	~OptionsPanel ();

private:

};

#endif
