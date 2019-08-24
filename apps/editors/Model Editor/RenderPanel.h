#ifndef _RenderPanel_h_
#define _RenderPanel_h_

#include <gsgeom/gsscene.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gslistbox.h>
#include <gswindow/gstabpanel.h>

#include "data.h"

class RenderPanel : public gswin::gstabpanel
{
public:
	RenderPanel (data *d, gswin::gswidget *parent);
	~RenderPanel ();

private:

};

#endif
