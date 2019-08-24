#include "test.h"

class Multitexture : public gswin::gswindow
{
public:
	Multitexture () : gswin::gswindow (0, "gs", "gsmultitexture test", gswin::gsWINDOW_OVERLAPPEDWINDOW, -1, 0, 0, 800, 600)
	{
		m_kernel = new gs::gskernel;
		m_kernel->init (this, getWidth (), getHeight ());

		gsgeom::gsscene *s = new gsgeom::gsscene;
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

		gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
		i->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
		i->m_vIndices.add (0);
		i->m_vIndices.add (1);
		i->m_vIndices.add (2);
		gi->m_vIndices.add (i);

		gsimage::gsbmp *b1 = new gsimage::gsbmp;
		b1->load ("plasma.bmp");
		gi->m_Textures.add (b1);
		gsimage::gsbmp *b2 = new gsimage::gsbmp;
		b2->load ("water.bmp");
		gi->m_Textures.add (b2);
		gsimage::gsbmp *b3 = new gsimage::gsbmp;
		b3->load ("rocky.bmp");
		gi->m_Textures.add (b3);
		s->m_Geometry = gi;
		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (800, 600, 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (0, 10, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		s->m_Camera = c;

		m_kernel->addEvent (gs::gsevent (GS_ADD_SCENE, s));
	}

	~Multitexture ()
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
	Multitexture *l = new Multitexture;

	l->handle ();

	return 0;
}
