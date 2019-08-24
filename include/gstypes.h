#ifndef _gstypes_h_
#define _gstypes_h_

#ifndef NULL
#define NULL 0
#endif

#ifdef WIN32
#define GS __declspec (dllexport)
#else
#define GS
#endif

#endif
