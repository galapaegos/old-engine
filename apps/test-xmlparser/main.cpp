#include <stdio.h>

#include "gsutil/gsstring.h"
#include "gsutil/gslogger.h"
#include "gsutil/gsXMLParser.h"

int main (int argc, char *argv[])
{
	gsutil::gsXMLParser p;
	p.loadFile ("model.xml");
	p.print ();

	gsutil::gsXMLElement *root = p.getRoot ();

	gsutil::gsstring f = p.find ("/config/primitives");
	printf ("/config/primitives:%s\n", f.str ());

	f = p.find ("/config");
	printf ("/config:%s\n", f.str ());

	p.saveFile ("test-out.xml");

	return 0;
}
