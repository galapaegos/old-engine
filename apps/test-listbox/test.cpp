#include "test.h"

class test : public gswin::gswindow
{
public:
	test () : gswindow (0, "test", "test window", WS_OVERLAPPEDWINDOW, 50, 50, 500, 500)
	{
	}

	virtual ~test () {}

	virtual void onClose ()
	{
		delete this;
	}
};

class window : public gswin::gswindow
{
public:
	window () : gswindow (0, "window", "Test Listbox", 0, 0, 0, 800, 600)
	{
		list = new gswin::gslistbox (this, "", WS_CHILD|LBS_NOTIFY|LBS_HASSTRINGS, 5, 5, 200, 200);
		add (list);

		list->add ("item 1");
		list->add ("item 2");

		but = new gswin::gsbutton (this, "refresh", BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE, 5, 215, 25, 25);
		add (but);
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

		if ((HIWORD (wp) == LBN_DBLCLK) && (HWND)lp == list->getHandle ())
		{
			test *t = new test;
			t->show ();
		}

		if ((HWND)lp == but->getHandle ())
		{
			list->clear ();

			list->add ("item 1");
			list->add ("item 2");
		}
	}

private:
	gswin::gslistbox *list;
	gswin::gsbutton *but;
};

int main (int argc, char *argv[])
{
	window *w = new window;
	w->show ();

	w->handle ();

	return 0;
}
