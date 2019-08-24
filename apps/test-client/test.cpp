#include "gsnet/gsclient.h"

int main (int argc, char *argv[])
{
	gsnet::gstcp tcp;

	tcp.create ();
	tcp.connect ("127.0.0.1", 54321);

	int sent = tcp.send ("hi");
	printf ("sent %i\n", sent);
	gsutil::gsstring re = tcp.receive ();

	printf ("Received message: %s\n", re.str ());

	tcp.destroy ();

	return 0;
}
