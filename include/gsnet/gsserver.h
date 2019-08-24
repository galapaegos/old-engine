#ifndef _gsserver_h_
#define _gsserver_h_

#include "gsnet/gstcp.h"
#include "gsnet/gsudp.h"

namespace gsnet
{
	struct gsconnected
	{
		gsutil::gsstring strClient;
		//SOCKET iSocket;
	};

	class GS gsserver
	{
	public:
		gsserver (const int &port);
		~gsserver ();

		void loop ();

	private:
		gsutil::gsqueue<gsconnected> m_connected;

		gstcp *m_pTcp;
	};
};

#endif

