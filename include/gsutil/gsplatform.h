#ifndef _gsplatform_h_
#define _gsplatform_h_

#include <gsutil/gsstring.h>

namespace gsutil
{
	//list of helper functions for the os
	GS gsutil::gsstring getCWD ();

	GS void changeCWD (const gsutil::gsstring &dir);
	GS void makeDir (const gsutil::gsstring &dir);
	GS void copyDir (const gsutil::gsstring &dir);
	GS void moveDir (const gsutil::gsstring &dir);
	GS void remDir (const gsutil::gsstring &dir, const bool &force=false);

	GS void copyFile (const gsutil::gsstring &file);
	GS void moveFile (const gsutil::gsstring &file);
	GS void remFile (const gsutil::gsstring &file);

	GS gsutil::gsstring getHome ();

	// this class determines the platform
	class gsplatform
	{
	public:
		gsplatform ();
		~gsplatform ();

		void detectPlatform ();
	};
};

#endif
