#include <gsgfx/gsvideolist.h>

namespace gsgfx
{
	gsvideolist::gsvideolist ()
	{
	}

	gsvideolist::~gsvideolist ()
	{
	}

	gsutil::gsqueue <gsgfx::gsvideolist::gsvideo> gsvideolist::getVideoList ()
	{
		gsutil::gsqueue <gsgfx::gsvideolist::gsvideo> list;

#ifdef WIN32
		int cMonitor = GetSystemMetrics (SM_CMONITORS);

		DEVMODE dv;
		dv.dmSize = sizeof (DEVMODE);
		while (EnumDisplaySettings (NULL, ENUM_CURRENT_SETTINGS, &dv))
		{
			gsvideo v;
			v.m_iWidth = dv.dmPelsWidth;
			v.m_iHeight = dv.dmPelsHeight;
			v.m_iFreq = dv.dmDisplayFrequency;
			v.m_iBpp = dv.dmBitsPerPel;

			list.add (v);
		}

#endif

		return list;
	}
};
