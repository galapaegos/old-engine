#include "test.h"

#include <shellapi.h>

class window : public gswin::gswindow
{
public:
	window () : gswindow (0, "window", "Test", 0, 0, 0, 800, 600)
	{
		m_pCheckBox = new gswin::gscheckbox (this, "CheckBox");
		add (m_pCheckBox);
	}

	virtual ~window () {}

	virtual void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();
		}
	}

	virtual void onCommand (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;
	}

private:
	gswin::gscheckbox *m_pCheckBox;
};

int main (int argc, char *argv[])
{
	window *w = new window;

	w->handle ();

	return 0;
}
