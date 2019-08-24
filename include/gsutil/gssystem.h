#ifndef _gssystem_h_
#define _gssystem_h_

#ifdef WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif

#include "gsutil/gsarray.h"
#include "gsutil/gsqueue.h"
#include "gsutil/gsstring.h"

namespace gsutil
{
	namespace gssystem
	{
		void GS getDirectoryList (const gsutil::gsstring &directory, const gsutil::gsstring &ext, gsutil::gsarray <gsutil::gsstring> &items);
		unsigned int GS getDirectorySize (const gsutil::gsstring &directory, const gsutil::gsstring &ext);
		gsutil::gsstring GS getCurrentDirectory ();
	};
};

#endif
