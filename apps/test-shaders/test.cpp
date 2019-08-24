#include "test.h"

class Test : public gswin::gswindow
{
public:
	Test () : gswin::gswindow (0, "gs", "gsshader test", gswin::gsWINDOW_OVERLAPPEDWINDOW, 0, 0, 0, 800, 600)
	{
		m_bRotate = false;

		pKernel.setMgr (&pMgr);

		pMgr.addNode (&pCam);

		pCam.setProjection (getAreaWidth (), getAreaHeight (), 45.f, 0.1f, 300.f);
		pCam.setView (gsgeom::gsvec3f (0, 2, 2), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));

		pCam.addNode (&pNode);

		//add shaders here
		gsgeom::gsshader *s = new gsgeom::gsshader;
		s->load ("vert.txt", "frag.txt");

		//pNode.setMaterial (&);

		gsutil::gsarray <gsgeom::gsvec3f> verts;
		verts.add (gsgeom::gsvec3f (0, 0, 0));
		verts.add (gsgeom::gsvec3f (0, 0, 1));
		verts.add (gsgeom::gsvec3f (1, 0, 1));
		verts.add (gsgeom::gsvec3f (1, 0, 0));
		pNode.setVerts (&verts);

		gsutil::gsarray <gsgeom::gsvec3f> norms;
		norms.add (gsgeom::gsvec3f (0, 1, 0));
		norms.add (gsgeom::gsvec3f (0, 1, 0));
		norms.add (gsgeom::gsvec3f (0, 1, 0));
		norms.add (gsgeom::gsvec3f (0, 1, 0));
		pNode.setNorms (&norms);

		gsutil::gsarray <unsigned int> ind;
		ind.add (0);
		ind.add (1);
		ind.add (2);
		ind.add (2);
		ind.add (3);
		ind.add (0);
		pNode.setIndices (&ind);

		pKernel.init (this);
	}

	~Test ()
	{
	}

	void onMouseMove (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		int x = LOWORD (lParam);
		int y = HIWORD (lParam);

		if (m_bRotate)
		{
			float difx = (float)(x - oldx)*0.05f;
			float dify = (float)(y - oldy)*0.05f;

			gsgeom::gscamera *c = m_pScene->m_Camera;

			//x direction
			c->pitch (dify);

			//y direction
			c->yaw (difx);
		}

		oldx = x;
		oldy = y;
	}

	void onMouseWheel (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		gsgeom::gscamera *c = m_pScene->m_Camera;
		short w = HIWORD (wp);

		float dx = -w/120.f;

		c->moveForward (dx*1.5f);
	}

	void onMouseRightDown (void *wParam, void *lParam)
	{
		m_bRotate = true;
	}

	void onMouseRightUp (void *wParam, void *lParam)
	{
		m_bRotate = false;
	}

private:
	gs::gskernel pKernel;
	gsscene::gsscenemgr pMgr;
	gsscene::gscameranode pCam;
	gsscene::gsscenenode pNode;

	int oldx, oldy;
	bool m_bRotate;
};

class Shader : public gswin::gsapp
{
public:
	Shader () : gswin::gsapp ()
	{
	}

	virtual ~Shader ()
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

MAINAPPW32 (Shader);
