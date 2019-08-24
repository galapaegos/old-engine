#include "test.h"

class glwindow : public gswin::gswindow
{
public:
	glwindow (const int &w, const int &h) : gswin::gswindow (0, "class", "Test", 0, 0, 0, 0, w, h) 
	{
		kern = new gskernel;

		kern->init (this, w, h);

		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gscamera *c = new gsgeom::gscamera;
		s->m_Camera = c;
		kern->addEvent (gs::gsevent (GS_ADD_SCENE, s));
	}
	~glwindow ()
	{
		delete kern;
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswin::gswindow::handle ();
			kern->execute ();
		}
	}

private:
	gskernel *kern;
};

int main (int argc, char *argv[])
{
	glwindow *w = new glwindow (800, 600);

	w->handle ();

	return 0;
}

