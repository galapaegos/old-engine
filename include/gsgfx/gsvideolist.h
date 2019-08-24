#ifndef _gsvideolist_h_
#define _gsvideolist_h_

#ifdef WIN32
#include <windows.h>
#endif

#include <gsutil/gsstring.h>
#include <gsutil/gsqueue.h>

namespace gsgfx
{
	class gsvideolist
	{
	public:
		gsvideolist ();
		~gsvideolist ();

		typedef struct
		{
			unsigned int m_iWidth, m_iHeight, m_iFreq, m_iBpp;
		} gsvideo;

		gsutil::gsqueue <gsgfx::gsvideolist::gsvideo> getVideoList ();

	private:
		gsutil::gsqueue <gsgfx::gsvideolist::gsvideo> m_videoList;
	};
};

#endif
