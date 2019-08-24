#include <gsutil/gsassert.h>

int main (int argc, char *argv[])
{
	int x = 0;
	gsAssert (0, __FILE__, __LINE__);
	return 0;
}