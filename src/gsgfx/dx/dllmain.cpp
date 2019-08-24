#include <windows.h>
#include <gsgfx/dx/gsd3d.h>

gsgfx::gsd3d *cur = NULL;

#ifdef WIN32
extern "C" __declspec (dllexport) void *create ()
{
	return cur;
}
#else
extern "C" void *create ()
{
	return new gsgfx::gsd3d ();
}
#endif

#ifdef WIN32
BOOL APIENTRY DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			cur = new gsgfx::gsd3d ();
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
	cur = new gsgfx::gsd3d ();
}

extern void _fini ()
{
	printf ("_fini\n");
	delete cur;
}
#endif
