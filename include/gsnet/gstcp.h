#ifndef _gstcp_h_
#define _gstcp_h_

#ifdef WIN32
#include <winsock2.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef int SOCKET;
#endif

#include "gsutil/gsstring.h"

namespace gsnet
{
	class GS gstcp
	{
	public:
		gstcp ();
		~gstcp ();

		void create ();
		void destroy ();

		void connect (const gsutil::gsstring &ip, const int &port);
		void bind (const gsutil::gsstring &ip, const int &port);

		void listen ();
		SOCKET accept ();

		int send (const gsutil::gsstring &s, SOCKET t);
		int send (const gsutil::gsstring &s);
		gsutil::gsstring receive (SOCKET t);
		gsutil::gsstring receive ();

		void printError ();

		SOCKET getSock () { return m_localSocket; }

	private:
		SOCKET m_localSocket;
	};
};

#endif

