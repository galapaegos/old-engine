#ifndef _gslogger_h_
#define _gslogger_h_

#include <stdarg.h>
#include <stdio.h>

#include <gsutil/gssingleton.h>
#include <gsutil/gstimer.h>
#include <gstypes.h>

namespace gsutil
{
#ifdef WIN32
#ifdef _DEBUG
#define LOGOPEN(x)\
	gsutil::gslogger *g = new gsutil::gslogger;\
	gsutil::gslogger::set (g);\
	g->openLog (x);
#define LOGCLOSE\
	gsutil::gslogger *g = gsutil::gslogger::get ();\
	g->closeLog ();
#define LOGFEN(x)\
	gsutil::gslogger::get ()->enterFunction (x, __FILE__, __LINE__);
#define LOGFEX(x)\
	gsutil::gslogger::get ()->exitFunction (x, __FILE__, __LINE__);
#else
#define FEN
#define FEX
#endif
#endif
	class GS gslogger : public gssingleton <gslogger>
	{
		
	public:
		gslogger ();
		~gslogger ();
		
		enum LogTypes
		{
			/** Append log file */
			LOG_APPEND = 1,
			/** Overwrite log file */
			LOG_OVERWRITE,
		};
		
		enum LogLevel
		{
			/** log level 1 - ie Errors, or equivalent 00001 */
			LEVEL_ONE = 1, 
			/** log level 2 - ie Problems but recovered using default values (also prints 1) 00011 */
			LEVEL_TWO = 3,
			/** log level 3 - ie Prints enter/exit of functions (also prints 1 and 2) 00111 */ 
			LEVEL_THREE = 7, 
			/** log level 4 - ie prints intermediate values (also prints 1 and 2) 01011 */
			LEVEL_FOUR = 11,
			/** log level 5 - ie prints everything! (prints 1-4) 11111 */
			LEVEL_FIVE = 31,
		};
		
		void openLog (const char *pFile, LogTypes type);
		void openLog (const char *pFile, LogTypes type, LogLevel level);
		void closeLog ();
		
		void enterFunction (const char *pFunctionName, const char *pFile, const int iLine);
		void exitFunction (const char *pFunctionName, const char *pFile, const int iLine);
		
		void writeDate ();
		void writeLog (const char *pMessage, ...);
		void writeLog (LogLevel level, const char *pMessage, ...);
		void writeTime ();
		
	private:
		FILE *m_pFile;
		char m_strFileName[256];
		int m_iIndent;
		int m_iLogLevel;
	};
};

#endif
