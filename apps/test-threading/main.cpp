#include "MainWindow.h"

int main (int argc, char *argv[])
{
	Main *m = new Main;

	while (1)
		m->addEvent (event ());

	delete m;

	return 0;
}