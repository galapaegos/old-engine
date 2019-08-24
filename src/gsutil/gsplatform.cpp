#include <gsutil/gsplatform.h>

namespace gsutil
{
	//list of helper functions for the os
	gsutil::gsstring getCWD ()
	{
		gsutil::gsstring cwd;
#ifdef WIN32

#else
#endif

		return cwd;
	}

	void changeCWD (const gsutil::gsstring &dir)
	{
	}

	void makeDir (const gsutil::gsstring &dir)
	{
	}

	void copyDir (const gsutil::gsstring &dir)
	{
	}

	void moveDir (const gsutil::gsstring &dir)
	{
	}

	void remDir (const gsutil::gsstring &dir, const bool &force)
	{
	}

	void copyFile (const gsutil::gsstring &file)
	{
#ifdef WIN32
		//CopyFile (file1, file2, yes/no);
#else
#endif
	}

	void moveFile (const gsutil::gsstring &file)
	{
	}

	void remFile (const gsutil::gsstring &file)
	{
	}

	gsutil::gsstring getHome ()
	{
		gsutil::gsstring home;

		return home;
	}

	gsplatform::gsplatform ()
	{
	}
	
	gsplatform::~gsplatform ()
	{
	}

	void gsplatform::detectPlatform ()
	{
	}
};
