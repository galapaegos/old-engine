#ifndef _MainWindow_h_
#define _MainWindow_h_

#include <vector>
#include "gsutil/gsmutex.h"
#include "gsutil/gsthread.h"

class event
{
public:
	event () {}
	~event () {}

	event operator= (event e)
	{
		return event ();
	}
};

class Main
{
public:
	Main ();
	~Main ();

	void init ();
	void handle ();

	void addEvent (event e);

private:
	gsutil::gsthread *thread;
	gsutil::gsmutex *mutex;

	int run;
	std::vector <event> m_list;

	static unsigned int CALLBACK _handle (void *arg)
	{ ((Main*)arg)->handle (); return 0; }
};

#endif