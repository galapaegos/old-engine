#ifndef _gsclient_h_
#define _gsclient_h_

#include "gsnet/gstcp.h"
#include "gsnet/gsudp.h"

namespace gsnet
{
	class GS gsclient
	{
	public:
		gsclient (const gsutil::gsstring &ip, const int &port);
		~gsclient ();

		bool verify ();

	private:
		gstcp *m_pTcp;
	};
};

#endif

