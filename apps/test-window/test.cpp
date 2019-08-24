#include "test.h"

class Test : public gswin::gsapp
{
public:
	Test () : m_Window ()
	{
		pKernel.init (&m_Window);
	}

	virtual ~Test ()
	{
		pKernel.shutdown ();
	}

	void onHandle ()
	{
		m_Window.handle ();
	}

private:
	gswin::gswindow m_Window;
	gs::gskernel pKernel;
};

MAINAPPW32 (Test);
