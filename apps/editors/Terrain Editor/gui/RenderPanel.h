#ifndef _RenderPanel_h_
#define _RenderPanel_h_

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gscheckbox.h>
#include <gswindow/gstabpanel.h>

class RenderPanel : public gswin::gstabpanel
{
public:
	RenderPanel (const unsigned long &exStyle, const gsutil::gsstring &c, const gsutil::gsstring &t, const unsigned long &style, gswidget *parent);
	~RenderPanel ();

	virtual void onCommand (void *wParam, void *lParam);

private:
};

#endif
