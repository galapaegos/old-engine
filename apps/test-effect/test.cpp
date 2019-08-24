#include "test.h"

class Effect : public gswin::gswindow
{
public:
	Effect () : gswin::gswindow (0, "gs", "gseffect test", 0, 0, 0, 800, 600)
	{
		m_kernel = new gs::gskernel;
		m_kernel->init (this, getWidth (), getHeight ());

		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 1));

		gi->m_vColors.add (gsgeom::gscolor (1, 0, 0, 0.5));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 0.5));
		gi->m_vColors.add (gsgeom::gscolor (0, 0, 1, 0.5));
		s->m_Geometry = gi;
		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (800, 600, 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		s->m_Camera = c;

		m_kernel->addEvent (gs::gsevent (GS_ADD_SCENE, s));
	}

	~Effect ()
	{
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();
		}
	}

private:
	gs::gskernel *m_kernel;
};

int main (int argc, char *argv[])
{
	Effect *l = new Effect;

	l->handle ();

	return 0;
}
