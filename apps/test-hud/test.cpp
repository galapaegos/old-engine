#include "test.h"

class Hud : public gswin::gswindow
{
public:
	Hud () : gswindow (0, "hud", "Test HUD", 0, 0, 0, 800, 600)
	{
		m_kernel = new gs::gskernel;
		m_kernel->init (getHandle (), getWidth (), getHeight ());

		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (1, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 1));

		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		gi->m_vColors.add (gsgeom::gscolor (0, 1, 0, 1));
		s->m_Geometry = gi;

		gsgeom::gscamera *c = new gsgeom::gscamera;
		c->setProjection (getWidth (), getHeight (), 45.f, 1.f, 300.f);
		c->setView (gsgeom::gsvec3f (5, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
		s->m_Camera = c;

		gsgeom::gsscene *hud = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gihud = new gsgeom::gsgeometryinfo;
		gihud->m_vPoints.add (gsgeom::gsvec3f (10, 10, -0.2));
		gihud->m_vPoints.add (gsgeom::gsvec3f (10, 400, -0.2));
		gihud->m_vPoints.add (gsgeom::gsvec3f (400, 10, -0.2));

		gihud->m_vColors.add (gsgeom::gscolor (0, 0, 1, 0.5));
		gihud->m_vColors.add (gsgeom::gscolor (0, 0, 1, 0.5));
		gihud->m_vColors.add (gsgeom::gscolor (0, 0, 1, 0.5));
		hud->m_Geometry = gihud;

		gsgeom::gstextinfo *ti = new gsgeom::gstextinfo;
		ti->m_Position.set (10.f, 10.f, -0.1f);
		ti->m_Text = "New text and stuff";
		hud->m_vTextList.add (ti);

		gsgeom::gscamera *hudcam = new gsgeom::gscamera;
		hudcam->setOrthogonal (0, getWidth (), 0, getHeight (), 0.1f, 300.f);
		hud->m_Camera = hudcam;

		s->m_ChildNodes.add (hud);

		m_kernel->addEvent (gsevent (GS_ADD_SCENE, s));
	}
	~Hud ()
	{
		delete m_kernel;
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();
		}
	}

	void onClose ()
	{
		m_iRun = 0;
		m_kernel->addEvent (gsevent (GS_QUIT, NULL));
	}

	void onKeyDown (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		switch (wp)
		{
		case VK_ESCAPE:
			m_kernel->addEvent (gsevent (GS_QUIT, NULL));
			break;
		}
	}

private:
	gs::gskernel *m_kernel;
};

int main (int argc, char *argv[])
{
	Hud *l = new Hud;

	l->handle ();

	return 0;
}
