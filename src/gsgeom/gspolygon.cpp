#include <gsgeom/gspolygon.h>

namespace gsgeom
{
	gspolygon::gspolygon ()
	{
	}

	gspolygon::~gspolygon ()
	{
	}

	void gspolygon::add (const gsgeom::gsvec3f &v)
	{
		m_vPoints.add (v);
	}

	void gspolygon::add (const gsgeom::gsvec2i &e)
	{
		m_vEdges.add (e);
	}

	void gspolygon::clear ()
	{
		m_vPoints.clear ();
		m_vEdges.clear ();
		m_vIndices.clear ();
	}

	void gspolygon::get (gsutil::gsarray <gsgeom::gsvec3f> &points)
	{
		//copying in from polygon
		points.clear ();

		for (unsigned int x = 0; x < m_vPoints.getSize (); x++)
			points.add (m_vPoints[x]);
	}

	void gspolygon::get (gsutil::gsarray <gsgeom::gsvec2i> &edges)
	{
		edges.clear ();

		for (unsigned int x = 0; x < m_vEdges.getSize (); x++)
			edges.add (m_vEdges[x]);
	}

	void gspolygon::get (gsutil::gsarray <unsigned int> &indices)
	{
		indices.clear ();

		for (unsigned int x = 0; m_vIndices.getSize (); x++)
			indices.add (m_vIndices[x]);
	}

	void gspolygon::process ()
	{
		//given the list of edges, we generate a face list
	}
};
