#include "test.h"

class Picking : public gswin::gswindow
{
public:
	Picking () : gswin::gswindow (0, "gs", "picking test", gswin::gsWINDOW_OVERLAPPEDWINDOW, 0, 0, 1200, 800)
	{
		m_bRotate = false;

		//gswin::gsgroup *t = new gswin::gsgroup (this, 0, -1, 0, 0, getAreaWidth (), 30);
		gswin::gsbox *b = new gswin::gsbox (gswin::gsHORIZONTAL, this);
		b->add (new gswin::gsbutton (this, "N", 1, 0, 0, 0, 25, 25));
		b->add (new gswin::gsbutton (this, "O", 1, 0, 0, 0, 25, 25));
		b->add (new gswin::gsbutton (this, "S", 1, 0, 0, 0, 25, 25));
		b->add (25);
		b->add (new gswin::gsbutton (this, "C", 1, 0, 0, 0, 25, 25));
		b->add (new gswin::gsbutton (this, "|\\", 1, 0, 0, 0, 25, 25));
		b->add (25);
		b->add (new gswin::gsbutton (this, "T", 1, 0, 0, 0, 25, 25));
		b->add (new gswin::gsbutton (this, "R", 1, 0, 0, 0, 25, 25));
		b->add (new gswin::gsbutton (this, "S", 1, 0, 0, 0, 25, 25));
		gswin::gsgroup *g = new gswin::gsgroup (this, 0, -1, 0, b->getHeight () + 2, getAreaWidth () - 250, getAreaHeight () - b->getHeight () + 2);

		m_kernel = new gs::gskernel;
		m_kernel->init (g->getHandle (), getAreaWidth () - 250, getAreaHeight () - b->getHeight () + 2);

		m_pScene = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (5, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, 5));

		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 0.5));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 0.5));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 0.5));
		
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));

		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));

		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		gi->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));

		gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
		it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		it->m_vIndices.add (0);
		it->m_vIndices.add (1);
		it->m_vIndices.add (2);
		gi->m_vIndices.add (it);

		gsgeom::gstextureinfo *bi1 = new gsgeom::gstextureinfo;
		bi1->add (gsgeom::gstextureinfo::ENVIRONMENT_MODE, gsgeom::gstextureinfo::MODE_COMBINE);
		bi1->add (gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB, gsgeom::gstextureinfo::MODE_REPLACE);
		gi->m_BlendTypes.add (bi1);

		gsgeom::gstextureinfo *bi2 = new gsgeom::gstextureinfo;
		bi2->add (gsgeom::gstextureinfo::ENVIRONMENT_MODE, gsgeom::gstextureinfo::MODE_COMBINE);
		bi2->add (gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB, gsgeom::gstextureinfo::MODE_INTERPOLATE);
		bi2->add (gsgeom::gstextureinfo::ARG_SOURCE0_RGB, gsgeom::gstextureinfo::ARG_TEXTURE);
		bi2->add (gsgeom::gstextureinfo::ARG_OPERAND0_RGB, gsgeom::gstextureinfo::ARG_SRC_COLOR);
		bi2->add (gsgeom::gstextureinfo::ARG_SOURCE1_RGB, gsgeom::gstextureinfo::ARG_PREVIOUS);
		bi2->add (gsgeom::gstextureinfo::ARG_OPERAND1_RGB, gsgeom::gstextureinfo::ARG_SRC_COLOR);
		bi2->add (gsgeom::gstextureinfo::ARG_SOURCE2_RGB, gsgeom::gstextureinfo::ARG_PRIMARY_COLOR);
		bi2->add (gsgeom::gstextureinfo::ARG_OPERAND2_RGB, gsgeom::gstextureinfo::ARG_SRC_ALPHA);
		gi->m_BlendTypes.add (bi2);

		gsimage::gstga *alphaMap = new gsimage::gstga;
		alphaMap->load ("alphaMap.tga");
		gi->m_Textures.add (alphaMap);
		gsimage::gsbmp *b2 = new gsimage::gsbmp;
		b2->load ("rocky.bmp");
		gi->m_Textures.add (b2);

		m_pScene->m_Geometry = gi;

		//picking, should be updated every mouse move call
		m_pPicking = new gsgeom::gsscene;

		//geometry
		m_pPicking->m_Geometry = new gsgeom::gsgeometryinfo;
		m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (-1, 0, -1));
		m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (1, 0, -1));
		m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (1, 0, 1));
		m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (-1, 0, 1));
		m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
		m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
		m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 1));
		m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));
		gsimage::gstga *t = new gsimage::gstga;
		t->load ("ring.tga");
		m_pPicking->m_Geometry->m_Textures.add (t);

		//index
		gsgeom::gsgeometryinfo::IndexType *pit = new gsgeom::gsgeometryinfo::IndexType;
		pit->indexType = gsgeom::gsgeometryinfo::GS_SQUARE;
		pit->m_vIndices.add (0);
		pit->m_vIndices.add (1);
		pit->m_vIndices.add (2);
		pit->m_vIndices.add (3);
		m_pPicking->m_Geometry->m_vIndices.add (pit);

		//effects
		//gsgeom::gseffect *pe = new gsgeom::gseffect;
		//pe->setAlphaTest (true);
		//pe->setAlphaFunc (gsgeom::gseffect::ALPHA_GREATER, 0.5f);
		//m_pPicking->m_pEffect = pe;
		m_pScene->m_ChildNodes.add (m_pPicking);

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (getAreaWidth () - 250, getAreaHeight () - b->getHeight () + 2, 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		m_pScene->m_Camera = c;

		m_kernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pScene));
		//m_kernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pPicking));
	}

	~Picking ()
	{
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

		RECT r;
		GetClientRect (getHandle (), &r);

		POINT p;
		GetCursorPos (&p);
		ScreenToClient (getHandle (), &p);

		gsgeom::gsray ray = m_pScene->m_Camera->getPicked ((float)p.x, (float)((r.bottom - r.top) - p.y));
		//gsgeom::gsray ray = m_pScene->m_Camera->getPicked (getWidth ()/2, getHeight ()/2);

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
		else if (gscol::gscollision::isRayIntersect (ray, m_pScene))
		{
			gsgeom::gsvec3f point = gscol::gscollision::RayIntersectPoint (ray, m_pScene);
			printf ("ray intersected! <%i, %i> | dir<%f, %f, %f>\n", x, y, ray.getDir ().getX (), ray.getDir ().getY (), ray.getDir ().getZ ());

			m_pPicking->m_Geometry->m_vPoints[0] = gsgeom::gsvec3f (point[0] - 0.25f, point[1] + 0.01f, point[2] - 0.25f);
			m_pPicking->m_Geometry->m_vPoints[1] = gsgeom::gsvec3f (point[0] + 0.25f, point[1] + 0.01f, point[2] - 0.25f);
			m_pPicking->m_Geometry->m_vPoints[2] = gsgeom::gsvec3f (point[0] + 0.25f, point[1] + 0.01f, point[2] + 0.25f);
			m_pPicking->m_Geometry->m_vPoints[3] = gsgeom::gsvec3f (point[0] - 0.25f, point[1] + 0.01f, point[2] + 0.25f);
		}
		else
		{
			m_pPicking->m_Geometry->m_vPoints[0] = gsgeom::gsvec3f (0, 0, 0);
			m_pPicking->m_Geometry->m_vPoints[1] = gsgeom::gsvec3f (0, 0, 0);
			m_pPicking->m_Geometry->m_vPoints[2] = gsgeom::gsvec3f (0, 0, 0);
			m_pPicking->m_Geometry->m_vPoints[3] = gsgeom::gsvec3f (0, 0, 0);
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
	gs::gskernel *m_kernel;
	gsgeom::gsscene *m_pScene, *m_pPicking;

	int oldx, oldy;
	bool m_bRotate;
};

int main (int argc, char *argv[])
{
	Picking *l = new Picking;

	l->handle ();

	return 0;
}
