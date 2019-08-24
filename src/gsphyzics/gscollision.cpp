#include "gsphyzics/gscollision.h"

namespace gscol
{
	/*
	//Line intersection - Lines form boundaries for polygons, check and see if ray passes inside
	bool isRayLineIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		printf ("Implement:%s, %i\n", __FILE__, __LINE__);
		return false;
	}

	bool isRayLineIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		printf ("Implement:%s, %i\n", __FILE__, __LINE__);
		return false;
	}

	gsgeom::gsvec3f RayLineIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return point;
	}

	gsgeom::gsvec3f RayLineIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return point;
	}

	gsgeom::gsvec3i RayLineIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return index;
	}

	gsgeom::gsvec3i RayLineIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return index;
	}

	//Triangle intersection
	bool isRayTriangleIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		gsgeom::gsray ray = r;

		//this isn't multiples of 3, we'll just bail
		if (s->m_Geometry->m_vPoints.getSize () % 3 != 0)
			return false;

		for (unsigned int y = 0; y < s->m_Geometry->m_vPoints.getSize (); y += 3)
		{
			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[y + 0];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[y + 1];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[y + 2];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);

			float a = t.dot (h);
			if (a > -0.00001 && a < 0.00001)
				continue;
			
			float f = 1/a;

			gsgeom::gsvec3f s = ray.getPos () - p1;
			float v = f*(s.dot (h));
			if (v < 0.f || v > 1.f)
				continue;
				
			gsgeom::gsvec3f q = s.cross (t);
			float w = f*(ray.getDir ().dot (q));
			if (w < 0.f || (w + v) > 1.f)
				continue;
			
			return true;
		}
		
		return false;
	}

	bool isRayTriangleIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;

		for (unsigned int y = 0; y < i->m_vIndices.getSize (); y += 3)
		{
			int index1 = i->m_vIndices[y + 0];
			int index2 = i->m_vIndices[y + 1];
			int index3 = i->m_vIndices[y + 2];

			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[index1];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[index2];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[index3];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);

			float a = t.dot (h);
			if (a > -0.00001 && a < 0.00001)
				continue;
			
			float f = 1/a;

			gsgeom::gsvec3f s = ray.getPos () - p1;
			float v = f*(s.dot (h));
			if (v < 0.f || v > 1.f)
				continue;
				
			gsgeom::gsvec3f q = s.cross (t);
			float w = f*(ray.getDir ().dot (q));
			if (w < 0.f || (w + v) > 1.f)
				continue;
			
			return true;
			//float t = (((1 - v - w)*p1 + v*p2 + w*p3)/r.getDir ());
		}

		return false;
	}

	gsgeom::gsvec3f RayTriangleIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		//this isn't multiples of 3, we'll just bail
		if (s->m_Geometry->m_vPoints.getSize () % 3 != 0)
			return point;

		for (unsigned int y = 0; y < s->m_Geometry->m_vPoints.getSize (); y += 3)
		{
			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[y + 0];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[y + 1];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[y + 2];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);

			float a = t.dot (h);
			if (a > -0.00001 && a < 0.00001)
				continue;
			
			float f = 1/a;

			gsgeom::gsvec3f s = ray.getPos () - p1;
			float v = f*(s.dot (h));
			if (v < 0.f || v > 1.f)
				continue;
				
			gsgeom::gsvec3f q = s.cross (t);
			float w = f*(ray.getDir ().dot (q));
			if (w < 0.f || (w + v) > 1.f)
				continue;
			
			gsgeom::gsvec3f b = ((p1)*(1 - v - w) + (p2)*v + (p3)*w);
			return b;
		}

		return point;
	}

	gsgeom::gsvec3f RayTriangleIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		for (unsigned int y = 0; y < i->m_vIndices.getSize (); y += 3)
		{
			int index1 = i->m_vIndices[y + 0];
			int index2 = i->m_vIndices[y + 1];
			int index3 = i->m_vIndices[y + 2];

			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[index1];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[index2];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[index3];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);
			
			float a = t.dot (h);
			if (a > -0.00001 && a < 0.00001)
				continue;
			
			float f = 1/a;
			
			gsgeom::gsvec3f s = ray.getPos () - p1;
			float v = f*(s.dot (h));
			if (v < 0.f || v > 1.f)
				continue;
				
			gsgeom::gsvec3f q = s.cross (t);
			float w = f*(ray.getDir ().dot (q));
			if (w < 0.f || (w + v) > 1.f)
				continue;
			
			gsgeom::gsvec3f b = ((p1)*(1 - v - w) + (p2)*v + (p3)*w);
			//float z = ray.getPos ().distance (b);
			//point = ray.getPos () + ray.getDir () * z;
			return b;
		}

		return point;
	}

	gsgeom::gsvec3i RayTriangleIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		//this isn't multiples of 3, we'll just bail
		if (s->m_Geometry->m_vPoints.getSize () % 3 != 0)
			return index;

		for (unsigned int y = 0; y < s->m_Geometry->m_vPoints.getSize (); y += 3)
		{
			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[y + 0];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[y + 1];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[y + 2];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);

			float a = t.dot (h);
			if (a > -0.00001 && a < 0.00001)
				continue;
			
			float f = 1/a;

			gsgeom::gsvec3f s = ray.getPos () - p1;
			float v = f*(s.dot (h));
			if (v < 0.f || v > 1.f)
				continue;
				
			gsgeom::gsvec3f q = s.cross (t);
			float w = f*(ray.getDir ().dot (q));
			if (w < 0.f || (w + v) > 1.f)
				continue;
			
			index.set (y + 0, y + 1, y + 3);

			return index;
		}

		return index;
	}

	gsgeom::gsvec3i RayTriangleIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		for (unsigned int y = 0; y < i->m_vIndices.getSize (); y += 3)
		{
			int index1 = i->m_vIndices[y + 0];
			int index2 = i->m_vIndices[y + 1];
			int index3 = i->m_vIndices[y + 2];

			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[index1];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[index2];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[index3];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);
			
			float a = t.dot (h);
			if (a > -0.00001 && a < 0.00001)
				continue;
			
			float f = 1/a;
			
			gsgeom::gsvec3f s = ray.getPos () - p1;
			float v = f*(s.dot (h));
			if (v < 0.f || v > 1.f)
				continue;
				
			gsgeom::gsvec3f q = s.cross (t);
			float w = f*(ray.getDir ().dot (q));
			if (w < 0.f || (w + v) > 1.f)
				continue;

			index.set (index1, index2, index3);

			return index;
		}

		return index;
	}

	//Quad intersection
	bool isRayQuadIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s)
	{
		printf ("Implement:%s, %i\n", __FILE__, __LINE__);
		return false;
	}

	bool isRayQuadIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;

		for (unsigned int j = 0; j < i->m_vIndices.getSize (); j += 4)
		{
			int index1 = i->m_vIndices[j + 0];
			int index2 = i->m_vIndices[j + 1];
			int index3 = i->m_vIndices[j + 2];
			int index4 = i->m_vIndices[j + 3];

			gsgeom::gsvec3f p1 = s->m_Geometry->m_vPoints[index1];
			gsgeom::gsvec3f p2 = s->m_Geometry->m_vPoints[index2];
			gsgeom::gsvec3f p3 = s->m_Geometry->m_vPoints[index3];
			gsgeom::gsvec3f p4 = s->m_Geometry->m_vPoints[index4];

			gsgeom::gsvec3f t = p2 - p1;
			gsgeom::gsvec3f u = p3 - p1;

			gsgeom::gsvec3f v = p4 - p3;
			gsgeom::gsvec3f w = p1 - p3;
			
			gsgeom::gsvec3f h = ray.getDir ().cross (u);
			gsgeom::gsvec3f i = ray.getDir ().cross (w);

			float a = t.dot (h);
			float b = v.dot (i);
			if ((a > -0.00001 && a < 0.00001) || (b > -0.00001 && b < 0.00001))
				continue;
			
			float f = 1/a;
			float g = 1/b;

			gsgeom::gsvec3f q = ray.getPos () - p1;
			gsgeom::gsvec3f r = ray.getPos () - p3;
			float c = f*(q.dot (h));
			float d = g*(r.dot (i));
			if ((c < 0.f || c > 1.f) || (d < 0.f || d > 1.f))
				continue;
				
			gsgeom::gsvec3f n = q.cross (t);
			gsgeom::gsvec3f o = r.cross (u);
			float y = f*(ray.getDir ().dot (q));
			float z = g*(ray.getDir ().dot (r));
			if ((y < 0.f || (y + c) > 1.f) || (z < 0.f || (z + d) > 1.f))
				continue;
			
			return true;
			//float t = (((1 - v - w)*p1 + v*p2 + w*p3)/r.getDir ());
		}

		return false;
	}

	gsgeom::gsvec3f RayQuadIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return point;
	}

	gsgeom::gsvec3f RayQuadIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return point;
	}

	gsgeom::gsvec3i RayQuadIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		return index;
	}

	gsgeom::gsvec3i RayQuadIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s, const gsgeom::gsgeometryinfo::IndexType *i)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		printf ("Implement:%s, %i\n", __FILE__, __LINE__);

		return index;
	}

	//Intersection calls
	bool gscollision::isRayIntersect (const gsgeom::gsray &r, const gsgeom::gsgeometrychunk *s)
	{
		gsgeom::gsray ray = r;

		//assuming that all scenes have an index buffer
		for (unsigned int x = 0; x < s->m_Geometry->m_vIndices.getSize (); x++)
		{
			switch (s->m_Geometry->m_vIndices[x]->indexType)
			{
			case gsgeom::gsgeometryinfo::GS_TRIANGLE:
				{
					if (s->m_Geometry->m_vIndices[x]->m_vIndices.getSize () > 0)
					{
						if (isRayTriangleIntersect (r, s, s->m_Geometry->m_vIndices[x]))
							return true;
					}
					else
					{
						if (isRayTriangleIntersect (r, s))
							return true;
					}
				}
				break;

			case gsgeom::gsgeometryinfo::GS_SQUARE:
				{
					if (s->m_Geometry->m_vIndices[x]->m_vIndices.getSize () > 0)
					{
						if (isRayQuadIntersect (r, s, s->m_Geometry->m_vIndices[x]))
							return true;
					}
					else
					{
						if (isRayQuadIntersect (r, s))
							return true;
					}
				}
				break;
			}
		}

		for (unsigned int y = 0; y < s->m_ChildNodes.getSize (); y++)
		{
			if (isRayIntersect (r, s->m_ChildNodes[y]))
				return true;
		}

		return false;
	}

	gsgeom::gsscene *gscollision::RayIntersectScene (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		gsgeom::gsray ray = r;

		for (unsigned int x = 0; x < s->m_Geometry->m_vIndices.getSize (); x++)
		{
			if (gscol::gscollision::isRayIntersect (r, s))
				return const_cast <gsgeom::gsscene*> (s);
		}

		for (unsigned int y = 0; y < s->m_ChildNodes.getSize (); y++)
		{
			if (gscollision::isRayIntersect (r, s->m_ChildNodes[y]))
				return RayIntersectScene (r, s->m_ChildNodes[y]);
		}

		return NULL;
	}

	gsgeom::gsvec3f gscollision::RayIntersectPoint (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3f point;

		//assuming that all scenes have an index buffer
		for (unsigned int x = 0; x < s->m_Geometry->m_vIndices.getSize (); x++)
		{
			switch (s->m_Geometry->m_vIndices[x]->indexType)
			{
			case gsgeom::gsgeometryinfo::GS_TRIANGLE:
				{
					if (s->m_Geometry->m_vIndices[x]->m_vIndices.getSize () > 0)
						return RayTriangleIntersectPoint (r, s, s->m_Geometry->m_vIndices[x]);
					else
						return RayTriangleIntersectPoint (r, s);
				}
				break;

			case gsgeom::gsgeometryinfo::GS_SQUARE:
				{
					if (s->m_Geometry->m_vIndices[x]->m_vIndices.getSize () > 0)
						return RayQuadIntersectPoint (r, s, s->m_Geometry->m_vIndices[x]);
					else
						return RayQuadIntersectPoint (r, s);
				}
				break;
			}
		}

		for (unsigned int y = 0; y < s->m_ChildNodes.getSize (); y++)
		{
			if (isRayIntersect (r, s->m_ChildNodes[y]))
				return RayIntersectPoint (r, s->m_ChildNodes[y]);
		}

		return point;
	}

	gsgeom::gsvec3i gscollision::RayIntersectIndex (const gsgeom::gsray &r, const gsgeom::gsgeometrybuffer *s)
	{
		gsgeom::gsray ray = r;
		gsgeom::gsvec3i index (-1, -1, -1);

		//assuming that all scenes have an index buffer
		for (unsigned int x = 0; x < s->m_Geometry->m_vIndices.getSize (); x++)
		{
			switch (s->m_Geometry->m_vIndices[x]->indexType)
			{
			case gsgeom::gsgeometryinfo::GS_TRIANGLE:
				{
					if (s->m_Geometry->m_vIndices[x]->m_vIndices.getSize () > 0)
					{
						index = RayTriangleIntersectIndex (r, s, s->m_Geometry->m_vIndices[x]);
						if (index[0] != -1 && index[1] != -1 && index[2] != -1)
							return index;
					}
					else
					{
						index = RayTriangleIntersectIndex (r, s);
						if (index[0] != -1 && index[1] != -1 && index[2] != -1)
							return index;
					}
				}
				break;

			case gsgeom::gsgeometryinfo::GS_SQUARE:
				{
					if (s->m_Geometry->m_vIndices[x]->m_vIndices.getSize () > 0)
					{
						index = RayQuadIntersectIndex (r, s, s->m_Geometry->m_vIndices[x]);
						if (index[0] != -1 && index[1] != -1 && index[2] != -1)
							return index;
					}
					else
					{
						index = RayQuadIntersectIndex (r, s);
						if (index[0] != -1 && index[1] != -1 && index[2] != -1)
							return index;
					}
				}
				break;
			}
		}

		for (unsigned int y = 0; y < s->m_ChildNodes.getSize (); y++)
		{
			if (isRayIntersect (r, s->m_ChildNodes[y]))
			{
				index = RayIntersectIndex (r, s->m_ChildNodes[y]);
				if (index[0] != -1 && index[1] != -1 && index[2] != -1)
					return index;
			}
		}

		return index;
	}
	*/
};
