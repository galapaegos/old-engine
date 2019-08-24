#ifndef _GenerateTerrain_h_
#define _GenerateTerrain_h_

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gsdescription.h>
#include <gswindow/gshbox.h>
#include <gswindow/gstabpanel.h>
#include <gswindow/gstextbox.h>
#include <gswindow/gsvbox.h>

class GeneratePanel : public gswin::gstabpanel
{
public:
	GeneratePanel (const unsigned long &exStyle, const gsutil::gsstring &c, 
		const gsutil::gsstring &t, const unsigned long &style, gswidget *parent);
	~GeneratePanel ();

	virtual void onCommand (void *wParam, void *lParam);

private:
	gswin::gsbutton *m_pOk;
	gswin::gstextbox *m_pX, *m_pY, *m_pZ;
	gswin::gstextbox *m_pW, *m_pH;
};


#endif
