#ifndef _TileTabControl_h_
#define _TileTabControl_h_

#include <gswindow/gsbox.h>
#include <gswindow/gswindow.h>
#include <gswindow/gstabctl.h>

class TileTabControl : public gswin::gswindow
{
public:
	TileTabControl (const unsigned long &exStyle, const gsutil::gsstring &c, 
		const gsutil::gsstring &t, const unsigned long &style, const int &x, const int &y,
		const int &w, const int &h);
	virtual ~TileTabControl ();

	virtual void onNotify (void *wParam, void *lParam);

private:
	gswin::gstabctl *m_pTabCtl;
};

#endif
