#ifndef _PaintTexturePanel_h_
#define _PaintTexturePanel_h_

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gscombobox.h>
#include <gswindow/gsdescription.h>
#include <gswindow/gshbox.h>
#include <gswindow/gslistbox.h>
#include <gswindow/gstabctl.h>
#include <gswindow/gstabpanel.h>
#include <gswindow/gsvbox.h>
#include <gswindow/gswindow.h>

class PaintTexturePanel : public gswin::gstabpanel
{
public:
	PaintTexturePanel (const unsigned long &exStyle, const gsutil::gsstring &c, 
		const gsutil::gsstring &t, const unsigned long &style, gswidget *parent);
	virtual ~PaintTexturePanel ();

private:
};

#endif
