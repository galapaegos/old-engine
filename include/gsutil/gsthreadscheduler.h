#ifndef _gsthreadscheduler_h_
#define _gsthreadscheduler_h_

#include <gsutil/gsmutex.h>
#include <gsutil/gsqueue.h>
#include <gsutil/gsthread.h>

namespace gsutil
{
	class gsthreadscheduler
	{
	public:
		gsthreadscheduler ();
		~gsthreadscheduler ();

		void add (gsutil::gsthread *pThread, const int &cpuPercent=100, const int &cpu=1);
		void remove (gsutil::gsthread *pThread);

		void manage ();

	private:
		typedef struct
		{
			int iCpu;
			int iPercent;
			gsutil::gsthread *pThread;
		} gsThreadInfo;

		gsutil::gsqueue <gsThreadInfo> threadList;
		gsutil::gsmutex mMutex;

		gsutil::gsqueue <gsThreadInfo> executionOrder;

		//SetProcessAffinityMask
		//SetThreadAffinityMask
		//GetProcessAffinityMask
		//SetThreadIdealProcessor
	};
};

#endif
