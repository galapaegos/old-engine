#ifndef _gsbmp_h_
#define _gsbmp_h_

#include <string.h>
#include "gstexture.h"
#include "gsutil/gslogger.h"

namespace gsimage
{
	class GS gsbmp : public gstexture
	{
#ifdef WIN32
		#pragma pack(push,bitmap_data,1)
//#else
//		#define __PACKED_ATTR __attribute__ ((__packed(1)__))
#endif
		struct bmpHeader
		{
			unsigned short				type;
			unsigned int				size;
			unsigned short				reserved1;
			unsigned short				reserved2;
			unsigned int				offset;
			unsigned int				infoHeaderSize;
			int							width;
			int							height;
			unsigned short				planes;
			unsigned short				bitcount;
			unsigned int				compression;
			unsigned int				sizeimage;
			int							xpixels;
			int							ypixels;
			unsigned int				clrused;
			unsigned int				important;
#ifndef WIN32
		} __attribute__ ((__packed__));
#else
		};
#endif

//#ifdef __PACKED_ATTR
//		} __PACKED_ATTR;
//#else
//		};
//#endif

#ifdef WIN32
		#pragma pack(pop,bitmap_data)
//#else
//		#undef __PACKED_ATTR
#endif

	public:
		gsbmp ();
		virtual ~gsbmp ();

		virtual void load (const gsutil::gsstring &pFilename);
		virtual void unload ();

	private:
		void convertRGB ();

		bmpHeader	m_bh;
	};
};

#endif

