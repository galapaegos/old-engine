#ifndef _gsmutex_h_
#define _gsmutex_h_

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

#include "gstypes.h"

namespace gsutil
{
	class GS gsmutex
	{
	public:
		gsmutex ()
		{
#ifdef WIN32
			InitializeCriticalSection (&m_cs);
#else
			m_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif
		}

		~gsmutex ()
		{
#ifdef WIN32
			DeleteCriticalSection (&m_cs);
#endif
		}
		
		//TODO: make this work!?!?!
		int tryLock ()
		{
#if defined WIN32
			// no trylock in this version of windows
			return true;
#if defined _WIN32_WINNT >= 0x500
			return TryEnterCriticalSection (&m_cs);
#endif
#else
			return true;
#endif
		}

		void lock ()
		{
#ifdef WIN32
			EnterCriticalSection (&m_cs);
#else
			pthread_mutex_lock (&m_mutex);
#endif
		}
		
		void unlock ()
		{
#ifdef WIN32
			LeaveCriticalSection (&m_cs);
#else
			pthread_mutex_unlock (&m_mutex);
#endif
		}

	private:
#ifdef WIN32
		CRITICAL_SECTION m_cs;
#else
		pthread_mutex_t m_mutex;
#endif
	};
};

#endif

