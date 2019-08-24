#include "test.h"

class terrainHeightmap : public gswin::gswindow
{
public:
	terrainHeightmap (const int &x, const int &y, const int &w, const int &h) : gswin::gswindow (0, "class", "Test", gswin::gsWINDOW_OVERLAPPEDWINDOW, 0, x, y, w, h) 
	{
		kern = new gskernel;

		kern->init (this, w, h);

		printf ("Initializing scene...\n");
		m_pScene = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		m_pScene->m_Geometry = gi;
		gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
		gi->m_vIndices.add (i);
		gsgeom::gscamera *c = new gsgeom::gscamera;
		m_pScene->m_Camera = c;

		printf ("Configuring blending...\n");
		gsgeom::gseffect *e = new gsgeom::gseffect;
		e->setDepthTest (true);
		e->setDepthFunc (gsgeom::gseffect::DEPTH_LEQUAL);
		m_pScene->m_pEffect = e;

		printf ("Configuring camera...\n");
		c->setProjection (w, h, 45.f, 0.01f, 800.f);
		c->setView (gsgeom::gsvec3f (0, 0, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));

		printf ("Loading heightmap...\n");
		gsimage::gsbmp *b = new gsimage::gsbmp ();
		b->load ("heightmap.bmp");

		if (b->getWidth () > 0 && b->getHeight () > 0)
		{
			printf ("Setting index type...\n");
			i->indexType = gsgeom::gsgeometryinfo::GS_SQUARE;

			printf ("Creating points, normals, and colors...\n");
			unsigned char *ptr = b->getData ();

			unsigned int tw = b->getWidth ();
			unsigned int th = b->getHeight ();
			for (unsigned int x = 0; x < tw; x++)
			{
				for (unsigned int z = 0; z < th; z++)
				{
					//gi->m_vPoints.add (gsgeom::gsvec3f ((x/(float)b->getWidth ()), (ptr[x*b->getWidth () + z]/255.f), (z/(float)b->getHeight ())));
					gi->m_vPoints.add (gsgeom::gsvec3f (x, (ptr[sizeof (unsigned char)*3*(x*tw + z)]/255.f)*10.f, z));

					//printf ("<%f,%f,%f>\n", (float)x, ptr[x*b->getWidth () + z]/255.f, (float)z);
					//printf ("%i\n", sizeof (unsigned char)*3*(x*tw + z));
					
					gsgeom::gsvec3f v (x, ptr[sizeof (unsigned char)*3*(x*tw + z)], z);
					v.normalize ();

					gi->m_vNormals.add (v);

					unsigned int index = sizeof (unsigned char)*3*(x*tw + z);

					if (ptr[index]/255.f < 0.3f)
						gi->m_vColors.add (gsgeom::gscolor (ptr[index]/255.f, 1 - ptr[index]/255.f, ptr[index]/255.f));
					else if (ptr[index]/255.f < 0.5f)
						gi->m_vColors.add (gsgeom::gscolor (1 - ptr[index]/255.f, ptr[index]/255.f, 0));
					else if (ptr[index]/255.f < 0.8f)
						gi->m_vColors.add (gsgeom::gscolor (ptr[index]/255.f, ptr[index]/255.f, 1 - ptr[index]/255.f));
					else
						gi->m_vColors.add (gsgeom::gscolor (1, 1, 1));

					//gi->m_vColors.add (gsgeom::gscolor (x/(float)b->getWidth (), ptr[x*b->getWidth () + z]/255.f, z/(float)b->getHeight ()));
					//gi->m_vColors.add (gsgeom::gscolor (ptr[sizeof (unsigned char)*3*(x*tw + z)]/255.f, ptr[sizeof (unsigned char)*3*(x*tw + z)]/255.f, ptr[sizeof (unsigned char)*3*(x*tw + z)]/255.f));
				}
			}

			printf ("Setting indices...\n");
			for (unsigned int c = 0; c < tw - 1; c++)
			{
				for (unsigned int d = 0; d < th - 1; d++)
				{
					int w = tw;
					int h = th;
					i->m_vIndices.add (c*w + d);
					i->m_vIndices.add (c*w + h + d);
					i->m_vIndices.add (c*w + h + d + 1);
					i->m_vIndices.add (c*w + d + 1);

					//printf ("%i %i %i %i\n", c*w + d, c*w + h +d, c*w + h + d + 1, c*w + d + 1);
				}
			}
		}

		printf ("Addings scene to be rendered...\n");
		kern->addEvent (gs::gsevent (GS_ADD_SCENE, m_pScene));
	}
	~terrainHeightmap ()
	{
		kern->shutdown ();
		delete kern;
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswin::gswindow::handle ();
		}
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

		c->moveForward (dx*0.5f);
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
	gskernel *kern;
	gsgeom::gsscene *m_pScene;

	int oldx, oldy;
	bool m_bRotate;
};

int main (int argc, char *argv[])
{
	int aw = GetSystemMetrics (SM_CXSCREEN);
	int ah = GetSystemMetrics (SM_CYSCREEN);

	terrainHeightmap w (aw/2 - 1280/2, ah/2 - 1024/2, 1280, 1024);

	w.handle ();

	return 0;
}

