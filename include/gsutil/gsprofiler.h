#ifndef _gsprofiler_h_
#define _gsprofiler_h_

#include <gsutil/gsstring.h>
#include <gsutil/gstimer.h>

namespace gsutil
{
	class GS gsprofiler
	{
	public:
		gsprofiler ();
		~gsprofiler ();

		void start ();
		void stop ();

		gsutil::gsstring process ();

	private:
		gsutil::gstimer m_Timer;

		float m_fStart, m_fStop;
	};
};

#endif
