#include <string.h>
#include "test.h"

class HDR : public gswin::gswindow
{
public:
	HDR () : gswin::gswindow (0, "gs", "gsanimation test", 0, 0, 0, 800, 600)
	{
		m_kernel = new gskernel;
		m_kernel->init (this, getWidth (), getHeight ());
	}

	~HDR ()
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
	HDR h;

	h.handle ();

	return 0;
}
