#include <gsutil/gslogger.h>
#include <gsutil/gsprofiler.h>

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

	gsutil::gsprofiler p;
	p.start ();
	Sleep (1000);
	p.stop ();
	g->writeLog (p.process ().str ());

	g->closeLog ();

	delete g;

	return 0;
}