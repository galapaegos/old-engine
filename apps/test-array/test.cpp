#include <stdio.h>
#include <stdlib.h>

#include <gsgeom/gsvector.h>
#include <gsutil/gsarray.h>

void func (gsutil::gsarray <gsgeom::gsvec3f> *ptr)
{
	gsgeom::gsvec3f d = (*ptr)[0];
	for (unsigned int x = 0; x < ptr->getSize (); x++)
	{
		printf ("v: %f,%f,%f\n", d[0], d[1], d[2]);
		d += sizeof (gsgeom::gsvec3f);
	}
}

int main (int argc, char *argv[])
{
	gsutil::gsarray <gsgeom::gsvec3f> _arrayVec;

	_arrayVec.add (gsgeom::gsvec3f (0, 1, 2));
	_arrayVec.add (gsgeom::gsvec3f (0, 1, 2));
	_arrayVec.add (gsgeom::gsvec3f (0, 1, 2));
	_arrayVec.add (gsgeom::gsvec3f (0, 1, 2));

	func (&_arrayVec);

	return 0;
}