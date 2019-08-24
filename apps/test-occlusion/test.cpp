#include <string.h>
#include "test.h"

class Animation : public gswin::gswindow
{
public:
	Animation () : gswin::gswindow (0, "gs", "gsanimation test", 0, 0, 0, 800, 600)
	{
		m_kernel = new gskernel;
		m_kernel->init (this, getWidth (), getHeight ());
	}

	~Animation ()
	{
		delete m_kernel;
	}

	void handle ()
	{
		while (m_iRun == 1)
		{
			gswin::gswindow::handle ();
			m_kernel->execute ();
		}
	}

private:
	gskernel *m_kernel;
};

int main (int argc, char *argv[])
{
	Animation *a = new Animation;

	a->handle ();

	return 0;
}
