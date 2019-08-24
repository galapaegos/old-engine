#ifndef _WorldEditor_h_
#define _WorldEditor_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsmenu.h"
#include "gswindow/gswindow.h"

class WorldEditor : public gswin::gswindow
{
public:
	WorldEditor (const int &w, const int &h);
	~WorldEditor ();

	//virtual void onComm

	virtual void handle ();

private:
	gs::gskernel *m_pKernel;
	gswin::gsmenu *m_pMainMenu;
};

#endif
