#ifndef _ModifyPanel_h_
#define _ModifyPanel_h_

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gscheckbox.h>
#include <gswindow/gshbox.h>
#include <gswindow/gstabpanel.h>
#include <gswindow/gsvbox.h>

class ModifyPanel : public gswin::gstabpanel
{
public:
	ModifyPanel (const unsigned long &exStyle, const gsutil::gsstring &c, const gsutil::gsstring &t, const unsigned long &style, gswidget *parent);
	virtual ~ModifyPanel ();

	virtual void onCommand (void *wParam, void *lParam);

private:
	gswin::gsbutton *m_pFlatten, *m_pRaise;
};


#endif
