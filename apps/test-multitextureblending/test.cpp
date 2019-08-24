#include "test.h"

class Multitexture : public gswin::gswindow
{
public:
	Multitexture () : gswin::gswindow (0, "gs", "gsmultitexture blending test", 0, 0, 0, 640, 480)
	{
		m_bRotate = false;

		m_kernel = new gs::gskernel;
		m_kernel->init (this, getWidth (), getHeight ());

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
		//bi1->add (gsgeom::gstextureinfo::ENVIRONMENT_MODE, gsgeom::gstextureinfo::MODE_COMBINE);
		//bi1->add (gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB, gsgeom::gstextureinfo::MODE_REPLACE);
		//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
		//glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
		//glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE);
		bi1->add (gsgeom::gstextureinfo::ENVIRONMENT_MODE, gsgeom::gstextureinfo::MODE_COMBINE);
		bi1->add (gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB, gsgeom::gstextureinfo::MODE_REPLACE);
		bi1->add (gsgeom::gstextureinfo::ARG_SOURCE0_RGB, gsgeom::gstextureinfo::ARG_TEXTURE);
		gi->m_BlendTypes.add (bi1);

		gsgeom::gstextureinfo *bi2 = new gsgeom::gstextureinfo;
		//bi2->add (gsgeom::gstextureinfo::ENVIRONMENT_MODE, gsgeom::gstextureinfo::MODE_COMBINE);
		//bi2->add (gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB, gsgeom::gstextureinfo::MODE_INTERPOLATE);
		//bi2->add (gsgeom::gstextureinfo::ARG_SOURCE0_RGB, gsgeom::gstextureinfo::ARG_TEXTURE);
		//bi2->add (gsgeom::gstextureinfo::ARG_OPERAND0_RGB, gsgeom::gstextureinfo::ARG_SRC_COLOR);
		//bi2->add (gsgeom::gstextureinfo::ARG_SOURCE1_RGB, gsgeom::gstextureinfo::ARG_PREVIOUS);
		//bi2->add (gsgeom::gstextureinfo::ARG_OPERAND1_RGB, gsgeom::gstextureinfo::ARG_SRC_COLOR);
		//bi2->add (gsgeom::gstextureinfo::ARG_SOURCE2_RGB, gsgeom::gstextureinfo::ARG_PRIMARY_COLOR);
		//bi2->add (gsgeom::gstextureinfo::ARG_OPERAND2_RGB, gsgeom::gstextureinfo::ARG_SRC_ALPHA);
		//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
		//glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_DOT3_RGB);
		//glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_PREVIOUS);
		//glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE);
		bi2->add (gsgeom::gstextureinfo::ENVIRONMENT_MODE, gsgeom::gstextureinfo::MODE_COMBINE);
		bi2->add (gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB, gsgeom::gstextureinfo::MODE_DOT3RGB);
		bi2->add (gsgeom::gstextureinfo::ARG_SOURCE0_RGB, gsgeom::gstextureinfo::ARG_PREVIOUS);
		bi2->add (gsgeom::gstextureinfo::ARG_SOURCE1_RGB, gsgeom::gstextureinfo::ARG_TEXTURE);
		gi->m_BlendTypes.add (bi2);

		gsimage::gstga *alphaMap = new gsimage::gstga;
		alphaMap->load ("alphaMap.tga");
		gi->m_Textures.add (alphaMap);
		gsimage::gsbmp *b2 = new gsimage::gsbmp;
		b2->load ("rocky.bmp");
		gi->m_Textures.add (b2);

		m_pScene->m_Geometry = gi;

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (getWidth (), getHeight (), 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (0, 5, 5), 
					gsgeom::gsvec3f (0, 0, 0), 
					gsgeom::gsvec3f (0, 1, 0));
		m_pScene->m_Camera = c;

		m_kernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pScene));
	}

	~Multitexture ()
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

		if (m_bRotate)
		{
			float difx = (float)(x - oldx)*0.05f;
			float dify = (float)(y - oldy)*0.05f;

			m_kernel->m_pRenderMutex->lock ();
			gsgeom::gscamera *c = m_pScene->m_Camera;

			//x direction
			c->pitch (dify);

			//y direction
			c->yaw (difx);

			m_kernel->m_pRenderMutex->unlock ();
		}

		oldx = x;
		oldy = y;
	}
	
	void onMouseWheel (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		m_kernel->m_pRenderMutex->lock ();

		gsgeom::gscamera *c = m_pScene->m_Camera;
		short w = HIWORD (wp);

		float dx = -w/120.f;

		c->moveForward (dx*1.5f);

		m_kernel->m_pRenderMutex->unlock ();
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
	gsgeom::gsscene *m_pScene;

	int oldx, oldy;
	bool m_bRotate;
};

int main (int argc, char *argv[])
{
	Multitexture *l = new Multitexture;

	l->handle ();

	return 0;
}
