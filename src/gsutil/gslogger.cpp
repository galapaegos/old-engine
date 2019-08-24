#include "gsutil/gslogger.h"

namespace gsutil
{
	gslogger::gslogger ()
	{
		m_iIndent = 0;
		m_iLogLevel = 0;
	}

	gslogger::~gslogger ()
	{
	}

	void gslogger::openLog (const char *pFile, gslogger::LogTypes type)
	{
		if (type & LOG_APPEND)
		{
			m_pFile = fopen (pFile, "a+");
			fseek (m_pFile, 0, SEEK_END);
		}
		else if (type & LOG_OVERWRITE)
			m_pFile = fopen (pFile, "w+");
		
		writeLog ("/=============================================================================================\\\n");
		writeLog ("=           Starting logging for the engine: ");
		writeDate ();
		writeTime ();
		writeLog ("\n");
		writeLog ("\\=============================================================================================/\n");
	}

	void gslogger::openLog (const char *pFile, gslogger::LogTypes type, LogLevel level)
	{
		m_iLogLevel = level;
		
		if (type & LOG_APPEND)
		{
			m_pFile = fopen (pFile, "a+");
			fseek (m_pFile, 0, SEEK_END);
		}else if (type & LOG_OVERWRITE)
			m_pFile = fopen (pFile, "w+");
		
		writeLog ("/=============================================================================================\\\n");
		writeLog ("=           Starting logging for the engine: ");
		writeDate ();
		writeTime ();
		writeLog ("\n");
		writeLog ("=           Using loglevel: %i\n", m_iLogLevel);
		writeLog ("\\=============================================================================================/\n");
	}

	void gslogger::closeLog ()
	{
		writeLog ("/=============================================================================================\\\n");
		writeLog ("=           Stopping logging for the engine: ");
		writeDate ();
		writeTime ();
		writeLog ("\n");
		writeLog ("\\=============================================================================================/\n");
		
		fclose (m_pFile);
	}

	void gslogger::enterFunction (const char *pFunctionName, const char *pFile, const int iLine)
	{
		if ((LEVEL_THREE == (m_iLogLevel & LEVEL_THREE)) || (LEVEL_FIVE == (m_iLogLevel & LEVEL_FIVE)))
		{
			writeLog ("Entered %s in %s on %i\n", pFunctionName, pFile, iLine);
			
			m_iIndent += 1;
		}
	}

	void gslogger::exitFunction (const char *pFunctionName, const char *pFile, const int iLine)
	{
		if ((LEVEL_THREE == (m_iLogLevel & LEVEL_THREE)) || (LEVEL_FIVE == (m_iLogLevel & LEVEL_FIVE)))
		{
			m_iIndent -= 1;
				
			writeLog ("Exiting %s in %s on %i\n", pFunctionName, pFile, iLine);
		}
	}

	void gslogger::writeDate ()
	{
#ifdef WIN32
		SYSTEMTIME time;

		GetLocalTime (&time);
		
		for (int x = 0; x < m_iIndent; x++)
				writeLog (" ");

		writeLog ("%i.%i.%i ", time.wMonth, time.wDay, time.wYear);
#endif
	}

	void gslogger::writeLog (const char *pMessage, ...)
	{
		char buffer[2048];
		va_list list;

		va_start (list, pMessage);

#ifdef WIN32
		_vsnprintf (buffer, sizeof (buffer), pMessage, list);
#else
		vsnprintf (buffer, sizeof (buffer), pMessage, list);
#endif

		va_end (list);
		
		for (int x = 0; x < m_iIndent; x++)
			fprintf (m_pFile, " ");

		fprintf (m_pFile, "%s", buffer);
	}

	void gslogger::writeLog (LogLevel level, const char *pMessage, ...)
	{
		if (level == (m_iLogLevel & level))
		{
			char buffer[2048];
			va_list list;

			va_start (list, pMessage);

#ifdef WIN32
			_vsnprintf (buffer, sizeof (buffer), pMessage, list);
#else
			vsnprintf (buffer, sizeof (buffer), pMessage, list);
#endif

			va_end (list);
			
			for (int x = 0; x < m_iIndent; x++)
				fprintf (m_pFile, " ");

			fprintf (m_pFile, "%s", buffer);
		}
	}

	void gslogger::writeTime ()
	{
#ifdef WIN32
		SYSTEMTIME time;

		GetLocalTime (&time);
		
		for (int x = 0; x < m_iIndent; x++)
			writeLog (" ");

		writeLog ("%i:%i:%i ", time.wHour, time.wMinute, time.wMilliseconds);	
#endif
	}
};
