#include <gsutil/gsrle.h>

int main (int argc, char *argv[])
{
	unsigned char *ptr = NULL;
	unsigned char *ptr2 = NULL;

	unsigned long written = 0;
	unsigned long read = 0;
	{
		unsigned char *src = new unsigned char[100];
		memset (src, 0, 100);

		unsigned char *dst = NULL;
		written = gsutil::gsrle::saveRLE (&dst, src, 100);

		printf ("written:%i\n", written);

		ptr = dst;
	}

	{
		unsigned char *dst = NULL;
		read = gsutil::gsrle::loadRLE (ptr, written, &dst);

		printf ("read:%i\n", read);

		ptr2 = dst;
	}

	return 0;
}
