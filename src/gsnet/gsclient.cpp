#include "gsnet/gsclient.h"

namespace gsnet
{
	gsclient::gsclient (const gsutil::gsstring &ip, const int &port)
	{
		m_pTcp = new gstcp;
		m_pTcp->create ();
		m_pTcp->connect (ip, port);
	}

	gsclient::~gsclient ()
	{
		m_pTcp->destroy ();
		delete m_pTcp;
	}

	bool gsclient::verify ()
	{
		//check to ensure versioning is correct

		return true;
	}
};

