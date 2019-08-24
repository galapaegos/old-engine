#ifndef _EditPanel_h_
#define _EditPanel_h_

#include <gsgeom/gsscene.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gslistbox.h>
#include <gswindow/gstabpanel.h>

#include "data.h"

class EditPanel : public gswin::gstabpanel
{
public:
	EditPanel (data *d, gswin::gswidget *parent);
	~EditPanel ();

private:

};

#endif
