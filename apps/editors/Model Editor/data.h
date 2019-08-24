#ifndef _data_h_
#define _data_h_

#include <gsgeom/gsscene.h>

class data
{
public:
	data ();
	~data ();

	//pure access to the graphics and menu scenes, but call m_pKernel->addEvent (GS_ADD_SCENE, getRoot ()); somewhere in init!
	gsgeom::gsscene *m_pRootGraphics;
	gsgeom::gsscene *m_pRootMenu;

	gsgeom::gsscene *m_pSelection;

	gsgeom::gscamera *m_pCamera;

	gsgeom::gsscene *getRoot () { return m_pRoot; }

	void lock ();
	void unlock ();

private:
	void cleanup ();

	gsgeom::gsscene *m_pRoot;
};

#endif
