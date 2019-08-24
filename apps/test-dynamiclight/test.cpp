#include <string.h>
#include "test.h"

class DynamicLight : public gswin::gswindow
{
public:
	DynamicLight () : gswin::gswindow (0, "gs", "gsdynamiclight test", gswin::gsWINDOW_OVERLAPPEDWINDOW, 0, 0, 800, 600)
	{
		m_kernel = new gs::gskernel;
		m_kernel->init (this, getWidth (), getHeight ());

		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		//bottom
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 3));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));

		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));

		gsgeom::gsgeometryinfo::IndexType *bi = new gsgeom::gsgeometryinfo::IndexType;
		bi->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		bi->m_vIndices.add (0);
		bi->m_vIndices.add (1);
		bi->m_vIndices.add (2);
		bi->m_vIndices.add (1);
		bi->m_vIndices.add (2);
		bi->m_vIndices.add (3);
		gi->m_vIndices.add (bi);

		//left side?
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 3, 0));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));

		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));

		gsgeom::gsgeometryinfo::IndexType *li = new gsgeom::gsgeometryinfo::IndexType;
		li->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		li->m_vIndices.add (4);
		li->m_vIndices.add (5);
		li->m_vIndices.add (6);
		li->m_vIndices.add (5);
		li->m_vIndices.add (6);
		li->m_vIndices.add (7);
		gi->m_vIndices.add (li);

		//right side?
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 3));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));

		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		s->m_Geometry = gi;

		gsgeom::gsgeometryinfo::IndexType *ri = new gsgeom::gsgeometryinfo::IndexType;
		ri->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		ri->m_vIndices.add (8);
		ri->m_vIndices.add (9);
		ri->m_vIndices.add (10);
		ri->m_vIndices.add (9);
		ri->m_vIndices.add (10);
		ri->m_vIndices.add (11);
		gi->m_vIndices.add (ri);

		m_pLight = new gsgeom::gslight;
		m_pLight->setPos (gsgeom::gsvec3f (0, 5, 0));
		m_pLight->setColor (gsgeom::gscolor (1.f, 1.f, 1.f, 1.f));
		m_pLight->setType (gsgeom::gslight::LIGHT_POINT);
		s->m_vLight.add (m_pLight);

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (800, 600, 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (5, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		s->m_Camera = c;

		m_kernel->addEvent (gsevent (GS_ADD_SCENE, s));

		m_fInc = 0.f;
	}

	~DynamicLight ()
	{
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();

			float rotx = sinf (m_fInc);
			float rotz = cosf (m_fInc);
			m_pLight->setPos (gsgeom::gsvec3f (2.f + 1.f*rotx, 2.f, 2.f + 1.f*rotz));

			if (m_fInc > 360.f)
				m_fInc = 0.f;
			else
				m_fInc += 0.001f;
		}
	}

private:
	gs::gskernel *m_kernel;
	gsgeom::gslight *m_pLight;

	float m_fInc;
};

int main (int argc, char *argv[])
{
	DynamicLight *l = new DynamicLight;

	l->handle ();

	return 0;
}
