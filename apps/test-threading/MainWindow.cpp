#include "MainWindow.h"

Main::Main ()
{
	thread = new gsutil::gsthread;
	thread->setCallback (_handle, this);
	thread->start ();

	mutex = new gsutil::gsmutex;

	run = 1;
}

Main::~Main ()
{
	thread->stop ();
}

void Main::addEvent (event e)
{
	mutex->lock ();
	m_list.push_back (e);
	mutex->unlock ();
}

void Main::handle ()
{
	while (run != 0)
	{
		for (unsigned int x = 0; x < m_list.size (); x++)
		{
			mutex->lock ();
			event e = m_list[0];
			m_list.erase (m_list.begin ());
			mutex->unlock ();

			//blah
		}
	}
}
