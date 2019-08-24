#include <string.h>
#include "test.h"

class Test : public gswin::gswindow
{
public:
	Test () : gswin::gswindow ()
	{
		gsscene::gsscenemgr *pSceneMgr = new gsscene::gsscenemgr;
		pKernel.setMgr (pSceneMgr);

		gsscene::gscameranode *pCam = new gsscene::gscameranode;
		pCam->setProjection (getAreaWidth (), getAreaHeight (), 45.f, 0.1f, 300.f);
		pCam->setView (gsgeom::gsvec3f (0, 2, 2), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));

		pSceneMgr->addNode (pCam);

		gsscene::gsscenenode *pNode = new gsscene::gsscenenode ();
		pCam->addNode (pNode);

		gsimage::gsbmp *tex = new gsimage::gsbmp ();
		tex->load ("plasma.bmp");

		gsscene::gsmaterialset *m = new gsscene::gsmaterialset ();
		gsgeom::gstextureinfo texInfo;
		m->addTexture (0, tex, &texInfo);
		pNode->setMaterial (m);

		gsutil::gsarray <gsgeom::gsvec3f> *pVerts = new gsutil::gsarray <gsgeom::gsvec3f>;
		pVerts->add (gsgeom::gsvec3f (0, 0, 0));
		pVerts->add (gsgeom::gsvec3f (1, 0, 0));
		pVerts->add (gsgeom::gsvec3f (1, 0, 1));
		pVerts->add (gsgeom::gsvec3f (0, 0, 1));
		pNode->setVerts (pVerts);

		gsutil::gsarray <gsgeom::gsvec3f> *pNorms = new gsutil::gsarray <gsgeom::gsvec3f>;
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNorms->add (gsgeom::gsvec3f (0, 1, 0));
		pNode->setNorms (pNorms);

		gsutil::gsarray <gsgeom::gscolor> *pColors = new gsutil::gsarray <gsgeom::gscolor>;
		pColors->add (gsgeom::gscolor (0, 1, 0, 1));
		pColors->add (gsgeom::gscolor (0, 1, 0, 1));
		pColors->add (gsgeom::gscolor (0, 1, 0, 1));
		pColors->add (gsgeom::gscolor (0, 1, 0, 1));
		pNode->setColors (pColors);

		gsutil::gsarray <unsigned int> *pInd = new gsutil::gsarray <unsigned int>;
		pInd->add (0);
		pInd->add (1);
		pInd->add (2);
		pInd->add (2);
		pInd->add (3);
		pInd->add (0);
		pNode->setIndex (pInd, gsgeom::gsgeometrybuffer::GS_TRIANGLE);

		pKernel.init (this);
	}

	virtual ~Test ()
	{
		pKernel.shutdown ();
	}

private:
	gsscene::gsscenemgr pSceneMgr;
	gs::gskernel pKernel;

	//nodes for cleaning up
};

class texture : public gswin::gsapp
{
public:
	texture () : gswin::gsapp ()
	{
	}

	virtual ~texture ()
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

MAINAPPW32 (texture);
