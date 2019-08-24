#include <stdio.h>

#include "gsgeom/gsvec2.h"
#include "gsgeom/gsvec3.h"
#include "gsgeom/gsvec4.h"
#include "gsutil/gslogger.h"

using namespace gsgeom;

int main (int argc, char *argv[])
{
	gsutil::gslogger *l = new gsutil::gslogger ();
	l->openLog ("math.txt", gsutil::gslogger::LOG_OVERWRITE);
	{
		l->writeLog ("/---------------------------------------\\\n");
		l->writeLog ("=       Unit testing gsvec2\n");
		l->writeLog ("\\---------------------------------------/\n");
		gsvec2f v1(1, 2);
		gsvec2f v2;
		v2[0] = 5;
		v2[1] = 6;
		l->writeLog ("v1: <%f, %f>; v2: <%f, %f>\n", v1[0], v1[1], v2.getX (), v2.getY ());

		gsvec2f add = v1 + v2;
		l->writeLog ("v1 + v2 = <%f, %f>\n", add[0], add[1]);

		gsvec2f sub = v1 - v2;
		l->writeLog ("v1 - v2 = <%f, %f>\n", sub[0], sub[1]);

		gsvec2f mul = v1 * v2;
		l->writeLog ("v1 * v2 = <%f, %f>\n", mul[0], mul[1]);

		gsvec2f div = v1 / v2;
		l->writeLog ("v1 / v2 = <%f, %f>\n", div[0], div[1]);

		gsvec2f eq = v1;
		l->writeLog ("v1 = <%f, %f>\n", eq[0], eq[1]);

		add += v1;
		l->writeLog ("add += v1: <%f, %f>\n", add[0], add[1]);

		sub -= v1;
		l->writeLog ("add += v1: <%f, %f>\n", sub[0], sub[1]);

		mul *= v1;
		l->writeLog ("mul += v1: <%f, %f>\n", mul[0], mul[1]);

		div /= v1;
		l->writeLog ("div += v1: <%f, %f>\n", div[0], div[1]);

		if (v1 == v2)
			l->writeLog ("v1 <%f, %f> == v2 <%f, %f>\n", v1[0], v1[1], v2[0], v2[1]);
		else
			l->writeLog ("v1 <%f, %f> != v2 <%f, %f>\n", v1[0], v1[1], v2[0], v2[1]);

		add = v1 + 5.0f;
		l->writeLog ("v1 + 5 = <%f, %f>\n", add[0], add[1]);

		sub = v1 - 5.0f;
		l->writeLog ("v1 - 5 = <%f, %f>\n", sub[0], sub[1]);

		mul = v1 * 5.0f;
		l->writeLog ("v1 * 5 = <%f, %f>\n", mul[0], mul[1]);

		div = v1 / 5.0f;
		l->writeLog ("v1 / 5 = <%f, %f>\n", div[0], div[1]);

		add += 5.0f;
		l->writeLog ("add + 5 = <%f, %f>\n", add[0], add[1]);

		sub -= 5.0f;
		l->writeLog ("sub - 5 = <%f, %f>\n", sub[0], sub[1]);

		mul *= 5.0f;
		l->writeLog ("mul * 5 = <%f, %f>\n", mul[0], mul[1]);

		div /= 5.0f;
		l->writeLog ("div / 5 = <%f, %f>\n", div[0], div[1]);
	}

	{
		l->writeLog ("/---------------------------------------\\\n");
		l->writeLog ("=       Unit testing gsvec3\n");
		l->writeLog ("\\---------------------------------------/\n");
		gsvec3f v1(1, 2, 3);
		gsvec3f v2;
		v2[0] = 5;
		v2[1] = 6;
		v2[2] = 7;
		l->writeLog ("v1: <%f, %f, %f>; v2: <%f, %f, %f>\n", v1[0], v1[1], v1[2], v2.getX (), v2.getY (), v2.getZ ());

		gsvec3f add = v1 + v2;
		l->writeLog ("v1 + v2 = <%f, %f, %f>\n", add[0], add[1], add[2]);

		gsvec3f sub = v1 - v2;
		l->writeLog ("v1 - v2 = <%f, %f, %f>\n", sub[0], sub[1], sub[2]);

		gsvec3f mul = v1 * v2;
		l->writeLog ("v1 * v2 = <%f, %f, %f>\n", mul[0], mul[1], mul[2]);

		gsvec3f div = v1 / v2;
		l->writeLog ("v1 / v2 = <%f, %f, %f>\n", div[0], div[1], div[2]);

		gsvec3f eq = v1;
		l->writeLog ("v1 = <%f, %f, %f>\n", eq[0], eq[1], eq[2]);

		add += v1;
		l->writeLog ("add += v1: <%f, %f, %f>\n", add[0], add[1], add[2]);

		sub -= v1;
		l->writeLog ("add += v1: <%f, %f, %f>\n", sub[0], sub[1], sub[2]);

		mul *= v1;
		l->writeLog ("mul += v1: <%f, %f, %f>\n", mul[0], mul[1], mul[2]);

		div /= v1;
		l->writeLog ("div += v1: <%f, %f, %f>\n", div[0], div[1], div[2]);

		if (v1 == v2)
			l->writeLog ("v1 <%f, %f, %f> == v2 <%f, %f, %f>\n", v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
		else
			l->writeLog ("v1 <%f, %f, %f> != v2 <%f, %f, %f>\n", v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);

		add = v1 + 5.0f;
		l->writeLog ("v1 + 5 = <%f, %f, %f>\n", add[0], add[1], add[2]);

		sub = v1 - 5.0f;
		l->writeLog ("v1 - 5 = <%f, %f, %f>\n", sub[0], sub[1], sub[2]);

		mul = v1 * 5.0f;
		l->writeLog ("v1 * 5 = <%f, %f, %f>\n", mul[0], mul[1], mul[2]);

		div = v1 / 5.0f;
		l->writeLog ("v1 / 5 = <%f, %f, %f>\n", div[0], div[1], div[2]);

		add += 5.0f;
		l->writeLog ("add + 5 = <%f, %f, %f>\n", add[0], add[1], add[2]);

		sub -= 5.0f;
		l->writeLog ("sub - 5 = <%f, %f, %f>\n", sub[0], sub[1], sub[2]);

		mul *= 5.0f;
		l->writeLog ("mul * 5 = <%f, %f, %f>\n", mul[0], mul[1], mul[2]);

		div /= 5.0f;
		l->writeLog ("div / 5 = <%f, %f, %f>\n", div[0], div[1], div[2]);

		float len = v1.length ();
		l->writeLog ("length of v1 = %f\n", len);

		float dist = v1.distance (v2);
		l->writeLog ("distance from v1 to v2 = %f\n", dist);

		float dot = v1.dot (v2);
		l->writeLog ("v1 . v2 = %f\n", dot);

		gsvec3f cross = v1.cross (v2);
		l->writeLog ("v1 x v2 = <%f, %f, %f>\n", cross[0], cross[1], cross[2]);

		v1.normalize ();
		l->writeLog ("|v1| = <%f, %f, %f>\n", v1[0], v1[1], v1[2]);
	}

	
	delete l;

	return 0;
}
