#ifndef _TriangulatePanel_h_
#define _TriangulatePanel_h_

#include <gsgeom/gssceneutil.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsbutton.h>
#include <gswindow/gscheckbox.h>
#include <gswindow/gsdescription.h>
#include <gswindow/gshbox.h>
#include <gswindow/gstabpanel.h>
#include <gswindow/gstextbox.h>
#include <gswindow/gsvbox.h>

class TriangulatePanel : public gswin::gstabpanel
{
public:
	TriangulatePanel (const unsigned long &exStyle, const gsutil::gsstring &c, const gsutil::gsstring &t, const unsigned long &style, gswidget *parent);
	~TriangulatePanel ();

	virtual void onCommand (void *wParam, void *lParam);

	void subdivideSmooth (gsgeom::gsscene *s, const int &levels);

private:
	gswin::gsbutton *m_pOk;
	gswin::gstextbox *m_pIterations;
};

#endif
