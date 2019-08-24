#include <gsutil/gsthreadscheduler.h>

namespace gsutil
{
	gsthreadscheduler::gsthreadscheduler ()
	{
	}

	gsthreadscheduler::~gsthreadscheduler ()
	{
	}

	void gsthreadscheduler::add (gsutil::gsthread *pThread, const int &cpuPercent, const int &cpu)
	{
		gsThreadInfo ti;
		ti.iCpu = cpu;
		ti.iPercent = cpuPercent;
		ti.pThread = pThread;

		threadList.add (ti);
	}

	void gsthreadscheduler::remove (gsutil::gsthread *pThread)
	{
		for (unsigned int x = 0; x < threadList.getSize (); x++)
		{
			if (pThread == threadList[x].pThread)
			{
				threadList.erase (x);
				break;
			}
		}
	}

	void gsthreadscheduler::manage ()
	{
		mMutex.lock ();
		//basically, per cpu basis loop through the current list and execute all threads for duration, 
		//then send them to the back of the list
		//
		//prolly need another datastructure to hold threads to denote cpu!
		mMutex.unlock ();
	}
};
