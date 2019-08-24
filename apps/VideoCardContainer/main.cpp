#include <stdio.h>

int main (int argc, char *argv[])
{
	gsutil::gsstring dir = "../docs/card\ information/";

	gsutil::gsarray <gsutil::gsstring> items;
	gsutil::gssystem::getDirectoryList (dir, "txt", items);

	for (unsigned int x = 0; x < items.getSize (); x++)
	{

	}

	return 0;
}