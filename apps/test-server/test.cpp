#include "gsnet/gsserver.h"

int main (int argc, char *argv[])
{
	gsnet::gstcp tcp;

	tcp.create ();
	tcp.bind ("127.0.0.1", 54321);

	return 0;
}
