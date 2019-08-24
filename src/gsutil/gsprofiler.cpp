#include <gsutil/gsprofiler.h>

namespace gsutil
{
	gsprofiler::gsprofiler ()
	{
	}

	gsprofiler::~gsprofiler ()
	{
	}

	void gsprofiler::start ()
	{
		m_fStart = m_Timer.getTime ();
	}

	void gsprofiler::stop ()
	{
		m_fStop = m_Timer.getTime ();
	}

	gsutil::gsstring gsprofiler::process ()
	{
		gsutil::gsstring profile;
		profile += "|======================================|\n";
		profile += "| Profiled data:" + gsutil::gsstring (m_fStop - m_fStart) + "\n";
		profile += "|======================================|\n";

		return profile;
	}
};
