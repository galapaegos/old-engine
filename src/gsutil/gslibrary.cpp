#include "gsutil/gslibrary.h"

namespace gsutil
{
	gslibrary::gslibrary ()
	{
		m_hModule = NULL;
	}

	gslibrary::~gslibrary ()
	{
		if (m_hModule)
#ifdef WIN32
			FreeLibrary (m_hModule);
#else
		dlclose (m_hModule);
#endif
	}

	void gslibrary::load (const gsutil::gsstring &pLibrary)
	{
#ifdef WIN32
		m_hModule = LoadLibrary (pLibrary.str ());
#else
		m_hModule = dlopen (pLibrary.str (), RTLD_GLOBAL|RTLD_LAZY);
		if (!m_hModule)
			printf ("Unable to load library %s, returned error: %s\n", pLibrary.str (), dlerror ());
#endif
		m_strLibrary = pLibrary;
	}

	void gslibrary::unload ()
	{
#ifdef WIN32
		if (m_hModule)
			FreeLibrary (m_hModule);
#else
		dlclose (m_hModule);
#endif
	}

	void *gslibrary::getProc (const gsutil::gsstring &pFunc)
	{
#ifdef WIN32
		return GetProcAddress (m_hModule, pFunc.str ());
#else
		if (!m_hModule)
			printf ("library handle is null\n");

		return dlsym (m_hModule, pFunc.str ());
#endif
	}
};
