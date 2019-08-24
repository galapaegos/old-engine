#ifndef _gsassert_h_
#define _gsassert_h_

#ifdef WIN32
#include <stdio.h>
#include <windows.h>
#ifdef _DEBUG
#define gsAssert(x)\
	if (!x)\
	{\
		char s[500];\
		sprintf (s, "In file %s on line %i!\n", __FILE__, __LINE__);\
		OutputDebugString (s);\
		DebugBreak ();\
	}
#else
#define gsAssert (x, char *str, int line)
#endif
#endif

#endif
