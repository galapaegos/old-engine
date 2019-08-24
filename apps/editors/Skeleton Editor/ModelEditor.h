#ifndef _ModelEditor_h_
#define _ModelEditor_h_

#include "galapaegos/gskernel.h"
#include "gswindow/gsmenu.h"

class ModelEditor : public gswin::gswindow
{
public:
	ModelEditor (const int &w, const int &h);
	~ModelEditor ();

	//virtual void onComm

	virtual void handle ();

private:
	gs::gskernel *m_pKernel;
	gswin::gsmenu *m_pMainMenu;
};

#endif
