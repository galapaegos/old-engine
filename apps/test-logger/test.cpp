#include <gsutil/gslogger.h>

void func ()
{
	FEN ("Entering func");
	FEX ("Exiting func");
}

int main (int argc, char *argv[])
{
	gsutil::gslogger *g = new gsutil::gslogger;
	gsutil::gslogger::set (g);

	g->openLog ("log.html", gsutil::gslogger::LOG_OVERWRITE, gsutil::gslogger::LEVEL_FIVE);

	func ();

	g->closeLog ();

	delete g;

	return 0;
}