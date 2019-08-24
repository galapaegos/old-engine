#ifdef WIN32
#include <windows.h>
#endif

#include "gsgfx/gl/gsgl.h"

gsgfx::gsgl *cur = NULL;

#ifdef WIN32
extern "C" __declspec (dllexport) void *create ()
{
	return cur;
}
#else
extern "C" void *create ()
{
	return new gsgfx::gsgl ();
}
#endif

#ifdef WIN32
BOOL APIENTRY DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			cur = new gsgfx::gsgl ();
			break;

		case DLL_PROCESS_DETACH:
			delete cur;
			break;
	}
	return TRUE;
}
#else
extern void _init ()
{
	printf ("_init\n");
	cur = new gsgfx::gsgl ();
}

extern void _fini ()
{
	printf ("_fini\n");
	delete cur;
}
#endif
