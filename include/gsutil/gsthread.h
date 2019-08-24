#ifndef _gsthread_h_
#define _gsthread_h_

#include "gstypes.h"
#ifdef WIN32
 #include <windows.h>
 #include <process.h>
#else
 #define CALLBACK
#include <pthread.h>
#endif

namespace gsutil
{
	class GS gsthread
	{
		typedef unsigned int (CALLBACK *FUNC)(void*);
	public:
		gsthread ();
		~gsthread ();

		void start ();
		void stop ();

#ifdef WIN32
		HANDLE getHandle () { return m_Thread; }
#else
		pthread_t getHandle () { return m_Thread; }
#endif

		void setCallback (FUNC fc, void *arg) { m_Function = fc; m_Argument = arg; }

	private:
#ifdef WIN32
		HANDLE m_Thread;
		UINT m_Id;
#else
		pthread_t m_Thread;
#endif
		FUNC m_Function;
		void *m_Argument;
	};
};

#endif
