#include <stdio.h>

#include "gsutil/gsstring.h"
#include "gsutil/gslogger.h"

int main (int argc, char *argv[])
{
	gsutil::gslogger *l = new gsutil::gslogger;
	l->openLog ("string.txt", gsutil::gslogger::LOG_OVERWRITE);
	gsutil::gsstring m_str;
	gsutil::gsstring m_str2;
	m_str = "test";
	m_str2 = " more";
	l->writeLog ("m_str: %s\n", m_str.str ());
	l->writeLog ("m_str2: %s\n", m_str2.str ());
	gsutil::gsstring temp = m_str + m_str2;
	l->writeLog ("temp: %s\n", temp.str ());
	l->writeLog ("find space: %i\n", temp.find (" "));
	temp += " stuff";
	l->writeLog ("temp: %s\n", temp.str ());
	temp += m_str2;
	l->writeLog ("temp: %s\n", temp.str ());
	temp.remove (0);
	l->writeLog ("temp: %s\n", temp.str ());
	temp.remove ("more");
	l->writeLog ("temp: %s\n", temp.str ());
	temp.remove (1, 3);
	l->writeLog ("temp: %s\n", temp.str ());
	gsutil::gsstring sub = temp.substring (2, 4);
	l->writeLog ("sub: %s\n", sub.str ());
	gsutil::gsstring sub2 = sub.substring (1, 2);
	l->writeLog ("sub2: %s\n", sub2.str ());
	l->closeLog ();
	delete l;
	return 0;
}

