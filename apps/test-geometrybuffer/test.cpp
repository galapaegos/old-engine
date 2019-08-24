#include "test.h"

class Test : public gswin::gswindow
{
public:
	Test () : gswin::gswindow (0, "gs", "gsmultitexture test", gswin::gsWINDOW_OVERLAPPEDWINDOW, -1, 0, 0, 800, 600)
	{
		m_Cam.setProjection (getAreaWidth (), getAreaHeight (), 45.f, 0.1f, 300.f);
		m_Cam.setView (gsgeom::gsvec3f (0, 3, 3), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));

		verts = new gsutil::gsarray <gsgeom::gsvec3f>;
		verts->add (gsgeom::gsvec3f (0, 0, 0));
		verts->add (gsgeom::gsvec3f (1, 0, 0));
		verts->add (gsgeom::gsvec3f (1, 0, 1));
		verts->add (gsgeom::gsvec3f (0, 0, 1));
		m_Scene.setVerts (verts);

		ind = new gsutil::gsarray <unsigned int>;
		ind->add (0);
		ind->add (1);
		ind->add (2);
		ind->add (2);
		ind->add (3);
		ind->add (0);
		m_Scene.setIndex (ind, gsgeom::gsgeometrybuffer::GS_TRIANGLE);

		m_Cam.addNode (&m_Scene);

		m_Mgr.addNode (&m_Cam);

		m_Kernel.setMgr (&m_Mgr);

		m_Kernel.init (this);

		//norms.add (gsgeom::gsvec3f (0, 0, 0));
		//norms.add (gsgeom::gsvec3f (0, 0, 0));
		//norms.add (gsgeom::gsvec3f (0, 0, 0));
		//norms.add (gsgeom::gsvec3f (0, 0, 0));
	}

	~Test ()
	{
	}

	void onClose ()
	{
		m_Kernel.shutdown ();
		gswin::gswindow::onClose ();
	}

private:
	gs::gskernel m_Kernel;

	gsscene::gsscenemgr m_Mgr;
	gsscene::gscameranode m_Cam;
	gsscene::gsscenenode m_Scene;

	gsutil::gsarray <gsgeom::gsvec3f> *verts;
	gsutil::gsarray <unsigned int> *ind;
};

class geometrybuffer : public gswin::gsapp
{
public:
	geometrybuffer () {}
	~geometrybuffer () {}

	void onInit ()
	{
		m_pWindow = new Test;
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

MAINAPPW32 (geometrybuffer);
