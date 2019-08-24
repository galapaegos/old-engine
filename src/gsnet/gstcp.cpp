#include "gsnet/gstcp.h"

namespace gsnet
{
	gstcp::gstcp ()
	{
#ifdef WIN32
		WSADATA wsaData;
		int iResult = WSAStartup( MAKEWORD(2,2), &wsaData );
		if ( iResult != NO_ERROR )
			printf("Error at WSAStartup()\n");
#endif
	}

	gstcp::~gstcp ()
	{
#ifdef WIN32
		WSACleanup ();
#endif
	}

	void gstcp::create ()
	{
#ifdef WIN32
		m_localSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
#else
		m_localSocket = socket (PF_INET, SOCK_STREAM, 0);
#endif
	
#ifdef WIN32	
		if (m_localSocket == INVALID_SOCKET)
		{
			printError ();
			WSACleanup ();
			return;	
		}
#endif
	}

	void gstcp::destroy ()
	{
#ifdef WIN32
		if (closesocket (m_localSocket) == SOCKET_ERROR)
			printError ();
#else
		close (m_localSocket);
#endif
	}

	void gstcp::connect (const gsutil::gsstring &ip, const int &port)
	{
#ifdef WIN32
		sockaddr_in clientService;

		clientService.sin_family = AF_INET;
		clientService.sin_addr.s_addr = inet_addr (ip.str ());
		clientService.sin_port = port;

		if (::connect (m_localSocket, (const sockaddr*)&clientService, sizeof (clientService)) != 0)
			printError ();
#else
		sockaddr_in clientService;

		clientService.sin_family = AF_INET;
		clientService.sin_addr.s_addr = inet_addr (ip.str ());
		clientService.sin_port = port;

		::connect (m_localSocket, (sockaddr*)&clientService, sizeof (clientService));
#endif

	}

	void gstcp::bind (const gsutil::gsstring &ip, const int &port)
	{
		//hostent *host = gethostbyname (ip.str ());
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr (ip.str ());
		addr.sin_port = port;

		if (::bind (m_localSocket, (const sockaddr*)&addr, sizeof (addr)) != 0)
			printError ();
	}

	void gstcp::listen ()
	{
		if (::listen (m_localSocket, SOMAXCONN) != 0)
			printError ();
	}

	SOCKET gstcp::accept ()
	{
		SOCKET s = ::accept (m_localSocket, NULL, NULL);
#ifdef WIN32
		if (s == INVALID_SOCKET)
			printError ();
#endif

		return s;
	}

	int gstcp::send (const gsutil::gsstring &s, SOCKET t)
	{
		return ::send (t, s.str (), s.size (), 0);
	}

	int gstcp::send (const gsutil::gsstring &s)
	{
		return send (s, m_localSocket);
	}

	gsutil::gsstring gstcp::receive (SOCKET t)
	{
		gsutil::gsstring buf;

		char temp[64] = "";
		int rec = recv (t, temp, 64, 0);
		buf += temp;

		printf ("temp:%s, %i\n", temp, rec);
		
		return buf;
	}

	gsutil::gsstring gstcp::receive ()
	{
		return receive (m_localSocket);
	}

	void gstcp::printError ()
	{
#ifdef WIN32
		int error = WSAGetLastError ();

		switch (error)
		{
			case WSAEINTR:
				{
					printf ("Interrupted function call.\nA blocking operation was interrupted by a call to WSACancelBlockingCall.\n");
				}
				break;

			case WSAEACCES:
				{
					printf ("Permission denied.\nAn attempt was made to access a socket in a way forbidden by its access permissions. An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST).\nAnother possible reason for the WSAEACCES error is that when the bind function is called (on Windows NT 4 SP4 or later), another application, service, or kernel mode driver is bound to the same address with exclusive access. Such exclusive access is a new feature of Windows NT 4 SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option.\n");
				}
				break;

			case WSAEFAULT:
				{
					printf ("Bad address.\nThe system detected an invalid pointer address in attempting to use a pointer argument of a call. This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small. For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr).\n");
				}
				break;

			case WSAEINVAL:
				{
					printf ("Invalid argument.\nSome invalid argument was supplied (for example, specifying an invalid level to the setsockopt function). In some instances, it also refers to the current state of the socket—for instance, calling accept on a socket that is not listening.\n");
				}
				break;

			case WSAEMFILE:
				{
					printf ("Too many open files.\n	Too many open sockets. Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread.\n");
				}
				break;

			case WSAEWOULDBLOCK:
				{
					printf ("Resource temporarily unavailable.\nThis error is returned from operations on nonblocking sockets that cannot be completed immediately, for example recv when no data is queued to be read from the socket. It is a nonfatal error, and the operation should be retried later. It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, since some time must elapse for the connection to be established.\n");
				}
				break;

			case WSAEINPROGRESS:
				{
					printf ("Operation now in progress.\nA blocking operation is currently executing. Windows Sockets only allows a single blocking operation—per- task or thread—to be outstanding, and if any other function call is made (whether or not it references that or any other socket) the function fails with the WSAEINPROGRESS error.\n");
				}
				break;

			case WSAEALREADY:
				{
					printf ("Operation already in progress.\nAn operation was attempted on a nonblocking socket with an operation already in progress—that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request (WSAAsyncGetXbyY) that has already been canceled or completed.\n");
				}
				break;

			case WSAENOTSOCK:
				{
					printf ("Socket operation on nonsocket.\nAn operation was attempted on something that is not a socket. Either the socket handle parameter did not reference a valid socket, or for select, a member of an fd_set was not valid.\n");
				}
				break;

			case WSAEDESTADDRREQ:
				{
					printf ("Destination address required.\nA required address was omitted from an operation on a socket. For example, this error is returned if sendto is called with the remote address of ADDR_ANY.\n");
				}
				break;

			case WSAEMSGSIZE:
				{
					printf ("Message too long.\nA message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.\n");
				}
				break;

			case WSAEPROTOTYPE:
				{
					printf ("Protocol wrong type for socket.\nA protocol was specified in the socket function call that does not support the semantics of the socket type requested. For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.\n");
				}
				break;

			case WSAENOPROTOOPT:
				{
					printf ("Bad protocol option.\nAn unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.\n");
				}
				break;

			case WSAEPROTONOSUPPORT:
				{
					printf ("Protocol not supported.\nThe requested protocol has not been configured into the system, or no implementation for it exists. For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol.\n");
				}
				break;

			case WSAESOCKTNOSUPPORT:
				{
					printf ("Socket type not supported.\nThe support for the specified socket type does not exist in this address family. For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.\n");
				}
				break;

			case WSAEOPNOTSUPP:
				{
					printf ("Operation not supported.\nThe attempted operation is not supported for the type of object referenced. Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.\n");
				}
				break;

			case WSAEPFNOSUPPORT:
				{
					printf ("Protocol family not supported.\nThe protocol family has not been configured into the system or no implementation for it exists. This message has a slightly different meaning from WSAEAFNOSUPPORT. However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT.\n");
				}
				break;

			case WSAEAFNOSUPPORT:
				{
					printf ("Address family not supported by protocol family.\nAn address incompatible with the requested protocol was used. All sockets are created with an associated address family (that is, AF_INET for Internet Protocols) and a generic protocol type (that is, SOCK_STREAM). This error is returned if an incorrect protocol is explicitly requested in the socket call, or if an address of the wrong family is used for a socket, for example, in sendto.\n");
				}
				break;

			case WSAEADDRINUSE:
				{
					printf ("Address already in use.\nTypically, only one usage of each socket address (protocol/IP address/port) is permitted. This error occurs if an application attempts to bind a socket to an IP address/port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing. For server applications that need to bind multiple sockets to the same port number, consider using setsockopt (SO_REUSEADDR). Client applications usually need not call bind at all— connect chooses an unused port automatically. When bind is called with a wildcard address (involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed. This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf.\n");
				}
				break;

			case WSAEADDRNOTAVAIL:
				{
					printf ("Cannot assign requested address.\nThe requested address is not valid in its context. This normally results from an attempt to bind to an address that is not valid for the local computer. This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port is not valid for a remote computer (for example, address or port 0).\n");
				}
				break;

			case WSAENETDOWN:
				{
					printf ("Network is down.\nA socket operation encountered a dead network. This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself.\n");
				}
				break;

			case WSAENETUNREACH:
				{
					printf ("Network is unreachable.\nA socket operation was attempted to an unreachable network. This usually means the local software knows no route to reach the remote host.\n");
				}
				break;

			case WSAENETRESET:
				{
					printf ("Network dropped connection on reset.\nThe connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.\n");
				}
				break;

			case WSAECONNABORTED:
				{
					printf ("Software caused connection abort.\nAn established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.\n");
				}
				break;

			case WSAECONNRESET:
				{
					printf ("Connection reset by peer.\nAn existing connection was forcibly closed by the remote host. This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close (see setsockopt for more information on the SO_LINGER option on the remote socket). This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.\n");
				}
				break;

			case WSAENOBUFS:
				{
					printf ("No buffer space available.\nAn operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.\n");
				}
				break;

			case WSAEISCONN:
				{
					printf ("Socket is already connected.\nA connect request was made on an already-connected socket. Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket (for SOCK_STREAM sockets, the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence.\n");
				}
				break;

			case WSAENOTCONN:
				{
					printf ("Socket is not connected.\nA request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied. Any other type of operation might also return this error—for example, setsockopt setting SO_KEEPALIVE if the connection has been reset.\n");
				}
				break;

			case WSAESHUTDOWN:
				{
					printf ("Cannot send after socket shutdown.\nA request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued.\n");
				}
				break;

			case WSAETIMEDOUT:
				{
					printf ("Connection timed out.\nA connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond.\n");
				}
				break;

			case WSAECONNREFUSED:
				{
					printf ("Connection refused.\nNo connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host—that is, one with no server application running.\n");
				}
				break;

			case WSAEHOSTDOWN:
				{
					printf ("Host is down.\nA socket operation failed because the destination host is down. A socket operation encountered a dead host. Networking activity on the local host has not been initiated. These conditions are more likely to be indicated by the error WSAETIMEDOUT.\n");
				}
				break;

			case WSAEHOSTUNREACH:
				{
					printf ("No route to host.\nA socket operation was attempted to an unreachable host. See WSAENETUNREACH.\n");
				}
				break;

			case WSAEPROCLIM:
				{
					printf ("Too many processes.\nA Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously.WSAStartup may fail with this error if the limit has been reached.\n");
				}
				break;

			case WSASYSNOTREADY:
				{
					printf ("Network subsystem is unavailable.\nThis error is returned by WSAStartup if the Windows Sockets implementation cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Users should check:\n\t* That the appropriate Windows Sockets DLL file is in the current path.\n\t* That they are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded.\n\t* The Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly.\n");
				}
				break;

			case WSAVERNOTSUPPORTED:
				{
					printf ("Winsock.dll version out of range.\nThe current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. Check that no old Windows Sockets DLL files are being accessed.\n");
				}
				break;

			case WSANOTINITIALISED:
				{
					printf ("Successful WSAStartup not yet performed.\nEither the application has not called WSAStartup or WSAStartup failed. The application may be accessing a socket that the current active task does not own (that is, trying to share a socket between tasks), or WSACleanup has been called too many times.\n");
				}
				break;

			case WSAEDISCON:
				{
					printf ("Graceful shutdown in progress.\nReturned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence.\n");
				}
				break;

			case WSATYPE_NOT_FOUND:
				{
					printf ("Class type not found.\nThe specified class was not found.\n");
				}
				break;

			case WSAHOST_NOT_FOUND:
				{
					printf ("Host not found.\nNo such host is known. The name is not an official host name or alias, or it cannot be found in the database(s) being queried. This error may also be returned for protocol and service queries, and means that the specified name could not be found in the relevant database.\n");
				}
				break;

			case WSATRY_AGAIN:
				{
					printf ("Nonauthoritative host not found.\nThis is usually a temporary error during host name resolution and means that the local server did not receive a response from an authoritative server. A retry at some time later may be successful.\n");
				}
				break;

			case WSANO_RECOVERY:
				{
					printf ("This is a nonrecoverable error.\nThis indicates that some sort of nonrecoverable error occurred during a database lookup. This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) could not be found, or a DNS request was returned by the server with a severe error.\n");
				}
				break;

			case WSANO_DATA:
				{
					printf ("Valid name, no data record of requested type.\nThe requested name is valid and was found in the database, but it does not have the correct associated data being resolved for. The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName) which uses the DNS (Domain Name Server). An MX record is returned but no A record—indicating the host itself exists, but is not directly reachable.\n");
				}
				break;

			case WSA_INVALID_HANDLE:
				{
					printf ("Specified event object handle is invalid.\nAn application attempts to use an event object, but the specified handle is not valid.\n");
				}
				break;

			case WSA_INVALID_PARAMETER:
				{
					printf ("One or more parameters are invalid.\nAn application used a Windows Sockets function which directly maps to a Windows function. The Windows function is indicating a problem with one or more parameters.\n");
				}
				break;

			case WSA_IO_INCOMPLETE:
				{
					printf ("Overlapped I/O event object not in signaled state.\nThe application has tried to determine the status of an overlapped operation which is not yet completed. Applications that use WSAGetOverlappedResult (with the fWait flag set to FALSE) in a polling mode to determine when an overlapped operation has completed, get this error code until the operation is complete.\n");
				}
				break;

			case WSA_IO_PENDING:
				{
					printf ("Overlapped operations will complete later.\nThe application has initiated an overlapped operation that cannot be completed immediately. A completion indication will be given later when the operation has been completed.\n");
				}
				break;

			case WSA_NOT_ENOUGH_MEMORY:
				{
					printf ("Insufficient memory available.\nAn application used a Windows Sockets function that directly maps to a Windows function. The Windows function is indicating a lack of required memory resources.\n");
				}
				break;

			case WSA_OPERATION_ABORTED:
				{
					printf ("Overlapped operation aborted.\nAn overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl.\n");
				}
				break;

			case WSASYSCALLFAILURE:
				{
					printf ("System call failure.\nGeneric error code, returned under various conditions.\nReturned when a system call that should never fail does fail. For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol/namespace catalogs.\nReturned when a provider does not return SUCCESS and does not provide an extended error code. Can indicate a service provider implementation error.\n");
				}
				break;
		}
#else
#endif
	}
};

