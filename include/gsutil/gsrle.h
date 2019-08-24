#ifndef _gsrle_h_
#define _gsrle_h_

#include "gsstring.h"

namespace gsutil
{
	namespace gsrle
	{
		unsigned long GS loadRLE (const unsigned char *src, const unsigned long &srcSize, unsigned char **dst);
		unsigned long GS saveRLE (unsigned char **dst, const unsigned char *src, const unsigned long &srcSize);
	};
}

#endif
