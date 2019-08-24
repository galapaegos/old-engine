#include <string.h>
#include "test.h"

class MultiLight : public gswin::gswindow
{
public:
	MultiLight () : gswin::gswindow (0, "gs", "gsmultilight test", 0, 0, 0, 800, 600)
	{
		m_kernel = new gskernel;
		m_kernel->init (this, getWidth (), getHeight ());

		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		//bottom
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 3));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));

		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 1, 0));

		//left side?
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 3, 0));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));

		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));
		gi->m_vNormals.add (gsgeom::gsvec3f (0, 0, 1));

		//right side?
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 3, 3));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 1));

		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vNormals.add (gsgeom::gsvec3f (1, 0, 0));
		s->m_Geometry = gi;

		gsgeom::gslight *l1 = new gsgeom::gslight;
		l1->setPos (gsgeom::gsvec3f (5, 10, 5));
		l1->setColor (gsgeom::gscolor (1, 0, 0, 1));
		l1->setType (gsgeom::gslight::LIGHT_POINT);
		s->m_vLight.add (l1);

		gsgeom::gslight *l2 = new gsgeom::gslight;
		l2->setPos (gsgeom::gsvec3f (10, 5, 5));
		l2->setColor (gsgeom::gscolor (0, 1, 0, 1));
		l2->setType (gsgeom::gslight::LIGHT_POINT);
		s->m_vLight.add (l2);

		gsgeom::gslight *l3 = new gsgeom::gslight;
		l3->setPos (gsgeom::gsvec3f (5, 5, 10));
		l3->setColor (gsgeom::gscolor (0, 0, 1, 1));
		l3->setType (gsgeom::gslight::LIGHT_POINT);
		s->m_vLight.add (l3);

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (800, 600, 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (5, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		s->m_Camera = c;

		m_kernel->addEvent (gsevent (GS_ADD_SCENE, s));
	}

	~MultiLight ()
	{
		delete m_kernel;
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswin::gswindow::handle ();
		}
	}

private:
	gskernel *m_kernel;
};

int main (int argc, char *argv[])
{
	MultiLight *m = new MultiLight;

	m->handle ();

	return 0;
}
