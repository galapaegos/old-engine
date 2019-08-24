#ifndef _GenerateTiles_h_
#define _GenerateTiles_h_

#include <gsgeom/gsgeometryinfo.h>
#include <gsgeom/gsscene.h>

#include <gswindow/gsbutton.h>
#include <gswindow/gsdescription.h>
#include <gswindow/gstextbox.h>
#include <gswindow/gswindow.h>

#include "../TileConfig.h"

class GenerateTiles : public gswin::gswindow
{
public:
	GenerateTiles (const int &x, const int &y, const int &w, const int &h);
	virtual ~GenerateTiles ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);

private:
	gswin::gstextbox *m_pWidth, *m_pHeight;
	gswin::gsbutton *m_pOk, *m_pCancel;
};

#endif
