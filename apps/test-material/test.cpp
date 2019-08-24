#include "test.h"

class Test : public gswin::gswindow
{
public:
	Test () : gswin::gswindow ()
	{
		pKernel.setMgr (&pSceneMgr);

		pCam.setProjection (getAreaWidth (), getAreaHeight (), 45.f, 1.f, 300.f);
		pCam.setView (gsgeom::gsvec3f (0, 2, 2), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		pSceneMgr.addNode (&pCam);
		pCam.addNode (&pNode);

		pNode.setMaterial (&pMat);

		pMat.setDiffuse (gsgeom::gscolor (0, 1, 0, 1));

		pVerts = new gsutil::gsarray <gsgeom::gsvec3f>;
		pVerts->add (gsgeom::gsvec3f (0, 0, 0));
		pVerts->add (gsgeom::gsvec3f (1, 0, 0));
		pVerts->add (gsgeom::gsvec3f (1, 0, 1));
		pVerts->add (gsgeom::gsvec3f (0, 0, 1));
		pNode.setVerts (pVerts);

		pNorms = new gsutil::gsarray <gsgeom::gsvec3f>;
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNode.setNorms (pNorms);

		pInd = new gsutil::gsarray <unsigned int>;
		pInd->add (0);
		pInd->add (1);
		pInd->add (2);
		pInd->add (2);
		pInd->add (3);
		pInd->add (0);
		pNode.setIndex (pInd, gsgeom::gsgeometrybuffer::GS_TRIANGLE);

		pKernel.init (this);
	}

	virtual ~Test ()
	{
		pKernel.shutdown ();

		delete pVerts;
		delete pInd;
	}

private:
	gsscene::gsscenemgr pSceneMgr;
	gs::gskernel pKernel;

	//nodes for cleaning up
	gsscene::gscameranode pCam;
	gsscene::gsscenenode pNode;
	gsscene::gsmaterialset pMat;
	gsscene::gslightnode pLight;
	gsutil::gsarray <gsgeom::gsvec3f> *pVerts;
	gsutil::gsarray <gsgeom::gsvec3f> *pNorms;
	gsutil::gsarray <unsigned int> *pInd;
};

class material : public gswin::gsapp
{
public:
	material () : gswin::gsapp ()
	{
	}

	virtual ~material ()
	{
	}

	void onInit ()
	{
		m_pWindow = new Test ();
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
	Test *m_pWindow;
};

MAINAPPW32 (material);
