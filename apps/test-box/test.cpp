#include "test.h"

#include <shellapi.h>

//#define TEST1 0
#define TEST2 1

class window : public gswin::gswindow
{
public:
	window () : gswindow (0, "window", "test-box", gswin::gsWINDOW_OVERLAPPEDWINDOW, 0, 0, 250, 400)
	{
#ifdef TEST1
		gswin::gsvbox *v = new gswin::gsvbox (this);
		gswin::gshbox *h4 = new gswin::gshbox (this);
		v->add (h4);
		gswin::gshbox *v1 = new gswin::gshbox (this);
		v->add (v1);
		gswin::gsvbox *h1 = new gswin::gsvbox (this);
		h1->add (new gswin::gsbutton (this, "v1 button1"));
		h1->add (new gswin::gsbutton (this, "v1 button2"));
		h1->add (new gswin::gsbutton (this, "v1 button3"));
		h1->add (new gswin::gsbutton (this, "v1 button4"));
		v1->add (h1);
		gswin::gsvbox *h3 = new gswin::gsvbox (this);
		v1->add (h3);
		gswin::gsvbox *h2 = new gswin::gsvbox (this);
		h2->add (new gswin::gsbutton (this, "v1 button1"));
		h2->add (new gswin::gsbutton (this, "v1 button2"));
		h2->add (new gswin::gsbutton (this, "v1 button3"));
		h2->add (new gswin::gsbutton (this, "v1 button4"));
		v1->add (h2);
#endif

#ifdef TEST2
		gswin::gsbox *a = new gswin::gsbox (gswin::gsVERTICAL, this);
		gswin::gsbox *b = new gswin::gsbox (gswin::gsHORIZONTAL, this);
		b->add (new gswin::gsbutton (this, "test1"), gswin::gsEXPAND);
		b->add (new gswin::gsbutton (this, "test2"), gswin::gsEXPAND);
		a->add (b);
		gswin::gsbox *c = new gswin::gsbox (gswin::gsHORIZONTAL, this);
		c->add (new gswin::gsbutton (this, "test3"), gswin::gsEXPAND);
		c->add (new gswin::gsbutton (this, "test4"), gswin::gsEXPAND);
		a->add (c);
#endif
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
	w->show ();

	w->handle ();

	return 0;
}
