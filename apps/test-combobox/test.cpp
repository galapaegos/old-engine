#include "test.h"

#include <shellapi.h>

class window : public gswin::gswindow
{
public:
	window () : gswindow (0, "window", "Test", 0, 0, 0, 800, 600)
	{
		SetWindowLong (getHandle (), GCL_HBRBACKGROUND, (COLOR_APPWORKSPACE));

		gswin::gsvbox *v = new gswin::gsvbox (this);
		gswin::gshbox *h1 = new gswin::gshbox (this);
		gswin::gscombobox *c1 = new gswin::gscombobox (this, "CheckBox", gswin::gsCOMBOBOX_DROPDOWNLIST);
		c1->add ("test1");
		c1->add ("test2");
		c1->add ("test3");
		c1->add ("test4");
		h1->add (c1);
		v->add (h1);
		gswin::gshbox *h2 = new gswin::gshbox (this);
		v->add (h2);
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
};

int main (int argc, char *argv[])
{
	window *w = new window;

	w->handle ();

	return 0;
}
