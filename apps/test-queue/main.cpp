#include <stdio.h>
#include "gsgeom/gsvec3.h"
#include "gsutil/gsqueue.h"

using namespace gsgeom;
using namespace gsutil;

int main (int argc, char *argv[])
{
	gsqueue<gsvec3f*> q;
	q.add (new gsvec3f (0, 1, 2));
	gsvec3f *b = q[0];

	gsqueue <gsvec3f> r;
	gsvec3f d (0, 1, 2);
	r.add (d);
	r.add (gsvec3f (0, 1, 2));
	gsvec3f c = r[0];

	return 0;
}
