#ifndef _gsppm_h_
#define _gsppm_h_

#include "gstexture.h"

namespace gsimage
{
	class GS gsppm : public gstexture
	{
	public:
		gsppm ();
		virtual ~gsppm ();

		virtual void load (const gsutil::gsstring &pFilename);
		virtual void unload ();
	};
};

#endif

