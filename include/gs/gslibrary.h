#ifndef _gslibrary_h_
#define _gslibrary_h_

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include "gsutil/gsstring.h"

namespace gs
{
	class gslibrary
	{
	public:
		gslibrary ();
		~gslibrary ();

		void load (const gsutil::gsstring &pLibrary);
		void unload ();

		void *getProc (const gsutil::gsstring &pFunc);
	private:
#ifdef WIN32
		HMODULE m_hModule;
#else
		void *m_hModule;
#endif
		gsutil::gsstring m_strLibrary;
	};
};

#endif

