#ifndef _gsevent_h_
#define _gsevent_h_

#ifdef WIN32
#include <windows.h>
#endif

#include <gs/gsevents.h>
#include <gsgeom/gsobject.h>
#include <gsutil/gsstring.h>

namespace gs
{
	// I'm defining events as something that needs to be done pronto.
	//Check out the gsevents.h file for the defines, basically 'rendering'
	//is a MUST, so it is going to be an event handled by the kernel
	class GS gsevent
	{
	public:
		gsevent ();
		gsevent (GSEVENT e, void *val);
		gsevent (GSEVENT e, int val);
		gsevent (GSEVENT e, float val);
		gsevent (GSEVENT e, const char *val);
		gsevent (GSEVENT e, const gsutil::gsstring &val);
		~gsevent ();

		void print ();

		inline void setEvent (GSEVENT e, void *val) { m_iEvent = e; m_pValue = val; }
		inline void setEvent (GSEVENT e, int val) { m_iEvent = e; m_iVal = val; }
		inline void setEvent (GSEVENT e, float val) { m_iEvent = e; m_fVal = val; }
		inline void setEvent (GSEVENT e, const char *val) { m_iEvent = e; m_strVal = val; }
		inline void setEvent (GSEVENT e, const gsutil::gsstring &s) { m_iEvent = e; m_strVal = s.str (); }
		inline int getEvent () { return m_iEvent; }
		inline void *getValue () { return m_pValue; }
		inline float getFloatValue () { return m_fVal; }
		inline int getIntValue () { return m_iVal; }
		inline const char *getCharValue () { return m_strVal.str (); }

		gsevent &operator= (const gsevent &e)
		{
			m_iEvent = e.m_iEvent;
			m_fVal = e.m_fVal;
			m_iVal = e.m_iVal;
			m_pValue = e.m_pValue;
			m_strVal = e.m_strVal;

			return (*this);
		}

	private:
		int m_iEvent;

		void *m_pValue;
		int m_iVal;
		float m_fVal;
		gsutil::gsstring m_strVal;
	};

};

#endif

