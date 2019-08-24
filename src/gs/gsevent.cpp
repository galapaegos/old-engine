#include <gs/gsevent.h>

namespace gs
{
	gsevent::gsevent ()
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
	}

	gsevent::gsevent (GSEVENT e, void *val)
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
		setEvent (e, val);
	}

	gsevent::gsevent (GSEVENT e, int val)
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
		setEvent (e, val);
	}

	gsevent::gsevent (GSEVENT e, float val)
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
		setEvent (e, val);
	}

	gsevent::gsevent (GSEVENT e, const char *val)
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
		setEvent (e, val);
	}

	gsevent::gsevent (GSEVENT e, const gsutil::gsstring &val)
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
		setEvent (e, val);
	}

	gsevent::~gsevent ()
	{
		this->m_fVal = 0.f;
		this->m_iEvent = 0;
		this->m_iEvent = 0;
		this->m_pValue = NULL;
	}

	void gsevent::print ()
	{
	}
};
