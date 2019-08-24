#include "gsutil/gsthread.h"

namespace gsutil
{
	gsthread::gsthread ()
	{
	}

	gsthread::~gsthread ()
	{
	}

	void gsthread::start ()
	{
#ifdef WIN32
		m_Thread = (HANDLE)_beginthreadex (NULL, 0, m_Function, m_Argument, CREATE_SUSPENDED, &m_Id);

		if (!m_Thread)
			return;

		if (ResumeThread (m_Thread) == -1)
			MessageBox (NULL, "ResumeThread is -1", "error", MB_OK);
#else
		int response = pthread_create (&m_Thread, NULL, (void*(*)(void*))m_Function, m_Argument);
#endif
	}

	void gsthread::stop ()
	{
#ifdef WIN32
		WaitForSingleObject (m_Thread, INFINITE);

		CloseHandle (m_Thread);
#else
		pthread_join (m_Thread, NULL);
#endif
	}
};
