#ifndef _gspng_h_
#define _gspng_h_

#include "gstexture.h"

namespace gsimage
{
	class GS gspng : public gstexture
	{
	public:
		gspng ();
		virtual ~gspng ();

		virtual void load (const gsutil::gsstring &pFilename);
		virtual void unload ();
	};
};

#endif

