#include <gswindow/gswindow.h>
#include <gsscript/gsscriptexecute.h>
#include <gsscript/gsscriptaddition.h>

class MainWindow : public gswin::gswindow
{
public:
	MainWindow () : gswin::gswindow ()
	{
		gsscr::gsscript script;
		gsscr::gsscriptobjecttoken o;
		script.pWalker = new gsscr::gsscriptwalker (new gsscr::gsscriptaddition (1, NULL));
		vm.addScript (&script);
		vm.run (0);
	}

	~MainWindow ()
	{
	}

private:
	gsscr::gsscriptexecute vm;
};

int main (int argc, char *argv[])
{
	MainWindow *m = new MainWindow ();
	m->handle ();
	delete m;
	return 0;
}
