#ifndef _ShadingPanel_h_
#define _ShadingPanel_h_

#include <gsgeom/gsscene.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gscombobox.h>
#include <gswindow/gsdescription.h>
#include <gswindow/gslistbox.h>
#include <gswindow/gstabpanel.h>

#include "data.h"

class ShadingPanel : public gswin::gstabpanel
{
public:
	ShadingPanel (data *d, gswin::gswidget *parent);
	~ShadingPanel ();

private:

};

#endif
