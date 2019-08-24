#ifndef _MainWindow_h_
#define _MainWindow_h_

#include <galapaegos/gskernel.h>

#include <gswindow/gswindow.h>

class MainWindow : public gswin::gswindow
{
public:
	MainWindow ();
	virtual ~MainWindow ();

	virtual void onKeyDown (void *wParam, void *lParam);

private:
	gs::gskernel *m_pKernel;

	//main scene:
	gsgeom::gsscene *m_pScene;
	gsgeom::gsscene *m_pUnits;
	gsgeom::gscamera *m_pCamera;
};

#endif