#include "gsgeom/gsfrustum.h"

namespace gsgeom
{
	gsfrustum::gsfrustum ()
	{

	}

	gsfrustum::~gsfrustum ()
	{
	}

	void gsfrustum::set (const gsgeom::gsmatrix &proj, const gsgeom::gsmatrix &view)
	{
		gsgeom::gsmatrix clip = view*proj;
		float dist = 0;

		//right
		gsvec4f tempr = gsvec4<float> (clip (1, 4) - clip (1, 1),
									   clip (2, 4) - clip (1, 2),
									   clip (3, 4) - clip (1, 3),
									   clip (4, 4) - clip (1, 4));
		dist = tempr.distance ();
		tempr /= dist;
		r = gsplane (tempr[0], tempr[1], tempr[2], tempr[3]);

		//left
		gsvec4f templ = gsvec4<float> (clip (1, 4) + clip (1, 1),
									   clip (2, 4) + clip (1, 2),
									   clip (3, 4) + clip (1, 3),
									   clip (4, 4) + clip (1, 4));
		dist = templ.distance ();
		templ /= dist;
		l = gsplane (templ[0], templ[1], templ[2], templ[3]);

		//top
		gsvec4f tempt = gsvec4<float> (clip (1, 4) - clip (2, 1),
									   clip (2, 4) - clip (2, 2),
									   clip (3, 4) - clip (2, 3),
									   clip (4, 4) - clip (2, 4));
		dist = tempt.distance ();
		tempt /= dist;
		t = gsplane (tempt[0], tempt[1], tempt[2], tempt[3]);

		//bottom
		gsvec4f tempb = gsvec4<float> (clip (1, 4) + clip (2, 1),
									   clip (2, 4) + clip (2, 2),
									   clip (3, 4) + clip (2, 3),
									   clip (4, 4) + clip (2, 4));
		dist = tempb.distance ();
		tempb /= dist;
		b = gsplane (tempb[0], tempb[1], tempb[2], tempb[3]);

		//far
		gsvec4f tempf = gsvec4<float> (clip (1, 4) - clip (3, 1),
									   clip (2, 4) - clip (3, 2),
									   clip (3, 4) - clip (3, 3),
									   clip (4, 4) - clip (3, 4));
		dist = tempf.distance ();
		tempf /= dist;
		f = gsplane (tempf[0], tempf[1], tempf[2], tempf[3]);

		//near
		gsvec4f tempn = gsvec4<float> (clip (1, 4) + clip (3, 1),
									   clip (2, 4) + clip (3, 2),
									   clip (3, 4) + clip (3, 3),
									   clip (4, 4) + clip (3, 4));
		dist = tempn.distance ();
		tempn /= dist;
		n = gsplane (tempn[0], tempn[1], tempn[2], tempn[3]);
	}

	bool gsfrustum::occlude (const gsgeom::gsvec3f vMin, const gsgeom::gsvec3f vMax)
	{
		gsgeom::gsvec3f min = vMin;
		gsgeom::gsvec3f max = vMax;

		//right side
		if (r.getNormal ()[0]*min[0] + r.getNormal ()[1]*min[1] + r.getNormal ()[2]*min[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*max[0] + r.getNormal ()[1]*min[1] + r.getNormal ()[2]*min[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*min[0] + r.getNormal ()[1]*max[1] + r.getNormal ()[2]*min[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*max[0] + r.getNormal ()[1]*max[1] + r.getNormal ()[2]*min[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*min[0] + r.getNormal ()[1]*min[1] + r.getNormal ()[2]*max[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*max[0] + r.getNormal ()[1]*min[1] + r.getNormal ()[2]*max[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*min[0] + r.getNormal ()[1]*max[1] + r.getNormal ()[2]*max[2] + r.getDistance () <= 0)
			return true;
		if (r.getNormal ()[0]*max[0] + r.getNormal ()[1]*max[1] + r.getNormal ()[2]*max[2] + r.getDistance () <= 0)
			return true;

		//left side
		if (l.getNormal ()[0]*min[0] + l.getNormal ()[1]*min[1] + l.getNormal ()[2]*min[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*max[0] + l.getNormal ()[1]*min[1] + l.getNormal ()[2]*min[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*min[0] + l.getNormal ()[1]*max[1] + l.getNormal ()[2]*min[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*max[0] + l.getNormal ()[1]*max[1] + l.getNormal ()[2]*min[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*min[0] + l.getNormal ()[1]*min[1] + l.getNormal ()[2]*max[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*max[0] + l.getNormal ()[1]*min[1] + l.getNormal ()[2]*max[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*min[0] + l.getNormal ()[1]*max[1] + l.getNormal ()[2]*max[2] + l.getDistance () <= 0)
			return true;
		if (l.getNormal ()[0]*max[0] + l.getNormal ()[1]*max[1] + l.getNormal ()[2]*max[2] + l.getDistance () <= 0)
			return true;

		//top
		if (t.getNormal ()[0]*min[0] + t.getNormal ()[1]*min[1] + t.getNormal ()[2]*min[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*max[0] + t.getNormal ()[1]*min[1] + t.getNormal ()[2]*min[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*min[0] + t.getNormal ()[1]*max[1] + t.getNormal ()[2]*min[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*max[0] + t.getNormal ()[1]*max[1] + t.getNormal ()[2]*min[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*min[0] + t.getNormal ()[1]*min[1] + t.getNormal ()[2]*max[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*max[0] + t.getNormal ()[1]*min[1] + t.getNormal ()[2]*max[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*min[0] + t.getNormal ()[1]*max[1] + t.getNormal ()[2]*max[2] + t.getDistance () <= 0)
			return true;
		if (t.getNormal ()[0]*max[0] + t.getNormal ()[1]*max[1] + t.getNormal ()[2]*max[2] + t.getDistance () <= 0)
			return true;

		//bottom side
		if (b.getNormal ()[0]*min[0] + b.getNormal ()[1]*min[1] + b.getNormal ()[2]*min[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*max[0] + b.getNormal ()[1]*min[1] + b.getNormal ()[2]*min[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*min[0] + b.getNormal ()[1]*max[1] + b.getNormal ()[2]*min[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*max[0] + b.getNormal ()[1]*max[1] + b.getNormal ()[2]*min[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*min[0] + b.getNormal ()[1]*min[1] + b.getNormal ()[2]*max[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*max[0] + b.getNormal ()[1]*min[1] + b.getNormal ()[2]*max[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*min[0] + b.getNormal ()[1]*max[1] + b.getNormal ()[2]*max[2] + b.getDistance () <= 0)
			return true;
		if (b.getNormal ()[0]*max[0] + b.getNormal ()[1]*max[1] + b.getNormal ()[2]*max[2] + b.getDistance () <= 0)
			return true;

		//near
		if (n.getNormal ()[0]*min[0] + n.getNormal ()[1]*min[1] + n.getNormal ()[2]*min[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*max[0] + n.getNormal ()[1]*min[1] + n.getNormal ()[2]*min[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*min[0] + n.getNormal ()[1]*max[1] + n.getNormal ()[2]*min[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*max[0] + n.getNormal ()[1]*max[1] + n.getNormal ()[2]*min[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*min[0] + n.getNormal ()[1]*min[1] + n.getNormal ()[2]*max[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*max[0] + n.getNormal ()[1]*min[1] + n.getNormal ()[2]*max[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*min[0] + n.getNormal ()[1]*max[1] + n.getNormal ()[2]*max[2] + n.getDistance () <= 0)
			return true;
		if (n.getNormal ()[0]*max[0] + n.getNormal ()[1]*max[1] + n.getNormal ()[2]*max[2] + n.getDistance () <= 0)
			return true;

		//far
		if (f.getNormal ()[0]*min[0] + f.getNormal ()[1]*min[1] + f.getNormal ()[2]*min[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*max[0] + f.getNormal ()[1]*min[1] + f.getNormal ()[2]*min[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*min[0] + f.getNormal ()[1]*max[1] + f.getNormal ()[2]*min[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*max[0] + f.getNormal ()[1]*max[1] + f.getNormal ()[2]*min[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*min[0] + f.getNormal ()[1]*min[1] + f.getNormal ()[2]*max[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*max[0] + f.getNormal ()[1]*min[1] + f.getNormal ()[2]*max[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*min[0] + f.getNormal ()[1]*max[1] + f.getNormal ()[2]*max[2] + f.getDistance () <= 0)
			return true;
		if (f.getNormal ()[0]*max[0] + f.getNormal ()[1]*max[1] + f.getNormal ()[2]*max[2] + f.getDistance () <= 0)
			return true;

		return false;
	}
};
