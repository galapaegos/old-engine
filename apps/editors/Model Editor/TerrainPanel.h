#ifndef _TerrainPanel_h_
#define _TerrainPanel_h_

#include <gsgeom/gsscene.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gslistbox.h>
#include <gswindow/gstabpanel.h>

#include "data.h"

class TerrainPanel : public gswin::gstabpanel
{
public:
	TerrainPanel (data *d, gswin::gswidget *parent);
	~TerrainPanel ();

private:

};

#endif
