#ifndef _gstimer_h_
#define _gstimer_h_

#include "gstypes.h"
#ifdef WIN32
 #include <windows.h>
#else
 #include <sys/time.h>
#endif

namespace gsutil
{
	class GS gstimer
	{
	public:
		gstimer ();
		~gstimer ();

		float getTime ();
#ifdef WIN32
		bool isPerformance () { return performance_timer; }
#endif

	private:
#ifdef WIN32
		__int64			freq;
		float			res;
		unsigned long	timer_start;
		unsigned long	timer_elapsed;

		bool			performance_timer;
		__int64			performance_start;
		__int64			performance_elapsed;
#else
		timeval m_timeval;
		timer_t m_start;
#endif
	};
};

#endif
