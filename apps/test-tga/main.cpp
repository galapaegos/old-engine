#include <stdio.h>

#include "gsimage/gstga.h"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf ("test-tga.exe [image.tga]\n");
		return -1;
	}

	gsimage::gstga *t = new gsimage::gstga;
	t->load (argv[1]);

	return 0;
}

