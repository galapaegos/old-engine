#include "gsutil/gstimer.h"

namespace gsutil
{
	gstimer::gstimer ()
	{
#ifdef WIN32
		performance_timer		= false;
		performance_start		= 0;
		performance_elapsed		= 0;

		res						= 0;
		freq					= 0;

		timer_start				= 0;
		timer_elapsed			= 0;

		if (!QueryPerformanceFrequency ((LARGE_INTEGER*) &freq))
		{
			performance_timer	= false;
			timer_start			= timeGetTime ();
			res					= 1.0f/1000.0f;
			freq				= 1000;
			timer_elapsed		= timer_start;
		}
		else
		{
			QueryPerformanceCounter ((LARGE_INTEGER*) performance_start);

			performance_timer	= true;
			res					= (1.0f/freq);
			performance_elapsed = performance_start;
		}
#else
		gettimeofday (&m_timeval, NULL);
#endif
	}

	gstimer::~gstimer ()
	{
	}

	float gstimer::getTime ()
	{
#ifdef WIN32
		if (performance_timer == true)
		{
			__int64 time;
			QueryPerformanceCounter ((LARGE_INTEGER*)&time);
			return ((float)(time - performance_start)*res)*1000.f;
		}
		else
			return ((float)(timeGetTime () - timer_start)*res)*1000.f;
#else
		timeval t;
		gettimeofday (&t, NULL);

		return (float)1.f/1000.f*((t.tv_sec - m_timeval.tv_sec) + (t.tv_usec - m_timeval.tv_usec));
		//return 0.f;
#endif
	}
};
