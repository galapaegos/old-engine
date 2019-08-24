#include "test.h"

class TestGB : public gswin::gswindow
{
public:
	TestGB () : gswin::gswindow ()
	{
		pKernel.setMgr (&pSceneMgr);

		pCam.setOrthographic (getAreaWidth (), getAreaHeight (), -1.f, 1.f);
		pCam.setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		pSceneMgr.addNode (&pCam);

		pText1.setColour (gsgeom::gscolor (0, 1, 0));
		pText1.setPosition (gsgeom::gsvec3f (10, 10, 0.3));
		pText1.setString ("Long text to be displayed!");
		pCam.addNode (&pText1);

		pText2.setColour (gsgeom::gscolor (1, 0, 0));
		pText2.setPosition (gsgeom::gsvec3f (200, 200, 0.2));
		pText2.setString ("gs4ever!");
		pCam.addNode (&pText2);

		pText3.setColour (gsgeom::gscolor (0, 0, 1));
		pText3.setPosition (gsgeom::gsvec3f (50, 300, 0.1));
		pText3.setString ("Hahahaha...");
		pCam.addNode (&pText3);

		pKernel.init (this);
	}

	virtual ~TestGB ()
	{
		pKernel.shutdown ();
	}

private:
	gsscene::gsscenemgr pSceneMgr;
	gs::gskernel pKernel;

	//nodes for cleaning up
	gsscene::gscameranode pCam;
	gsscene::gstextnode pText1, pText2, pText3;
};

class geometrybuffer : public gswin::gsapp
{
public:
	geometrybuffer () : gswin::gsapp ()
	{
	}

	virtual ~geometrybuffer ()
	{
	}

	void onInit ()
	{
		m_pWindow = new TestGB ();
	}

	void onHandle ()
	{
		m_pWindow->handle ();
	}

	void onClose ()
	{
		delete m_pWindow;
	}

private:
	TestGB *m_pWindow;
};

MAINAPPW32 (geometrybuffer);
