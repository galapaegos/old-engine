#include <gsgeom/gsgeometrychunk.h>

namespace gsgeom
{
	gsgeometrychunk::gsgeometrychunk ()
	{
		m_fDistance = 0.f;

		m_bWireframe = false;

		m_bDirty[0] = false;
		m_bDirty[1] = false;
		m_bDirty[2] = false;
		m_bDirty[3] = false;

		m_vVerts = NULL;
		m_vNormals = NULL;
		m_vColors = NULL;

		m_iUniqueId = 0;
		m_iType = SEPARATE_COMBINED;
	}

	gsgeometrychunk::~gsgeometrychunk ()
	{
		m_vVerts = NULL;
		m_vNormals = NULL;
		m_vColors = NULL;

		while (m_vCoords.getSize () > 0)
		{
			TexCoordIndex *t = m_vCoords[0];
			m_vCoords.erase (0);
			delete t;
		}

		while (m_vIndices.getSize () > 0)
		{
			IndexType *it = m_vIndices[0];
			m_vIndices.erase (0);
			delete it;
		}

		while (m_vWireframe.getSize () > 0)
		{
			IndexType *it = m_vWireframe[0];
			m_vWireframe.erase (0);
			delete it;
		}
	}

	bool gsgeometrychunk::visible (const gsgeom::gscamera *pCamera)
	{
		gsAssert (pCamera);

		gsgeom::gsfrustum f;
		f.set (pCamera->getProjection (), pCamera->getView ());
		bool occ = f.occlude (m_boundingBox.getMin (), m_boundingBox.getMax ());
		return occ;
	}

	void gsgeometrychunk::wireframe (const bool &wireframe)
	{
		if (m_bWireframe)
		{
			m_bWireframe = false;

			while (m_vWireframe.getSize () > 0)
			{
				IndexType *it = m_vWireframe[0];
				m_vWireframe.erase (0);
				delete it->pIndex;
			}
		}
		else
		{
			m_bWireframe = true;

			for (unsigned int x = 0; x < m_vIndices.getSize (); x++)
			{
			}
		}
	}

	gsutil::gsarray <gsgeom::gsvec3f> *gsgeometrychunk::getVerts ()
	{
		return m_vVerts;
	}

	gsutil::gsarray <gsgeom::gsvec3f> *gsgeometrychunk::getNorms ()
	{
		return m_vNormals;
	}

	gsutil::gsarray <gsgeom::gscolor> *gsgeometrychunk::getColors ()
	{
		return m_vColors;
	}

	gsutil::gsarray <unsigned int> *gsgeometrychunk::getIndex (const unsigned int &index)
	{
		return m_vIndices[index]->pIndex;
	}

	gsutil::gsarray <unsigned int> *gsgeometrychunk::getIndex (int *geomType)
	{
		//returning based on distance from camera
		//for now, just returning index in position [0]

		if (m_bWireframe)
		{
			*geomType = GS_LINE;
			return m_vWireframe[0]->pIndex;
		}
		else
		{
			*geomType = m_vIndices[0]->m_iGeomType;
			return m_vIndices[0]->pIndex;
		}
	}

	gsutil::gsarray <gsgeom::gsvec2f> *gsgeometrychunk::getCoords ()
	{
		if (!m_vCoords.getSize ())
			return NULL;

		return m_vCoords[0]->pCoords;
	}

	gsutil::gsarray <gsgeom::gsvec2f> *gsgeometrychunk::getCoords (const unsigned int &stage)
	{
		for (unsigned int x = 0; x < m_vCoords.getSize (); x++)
		{
			if (stage == x)
				return m_vCoords[x]->pCoords;
		}

		return NULL;
	}

	gsutil::gsarray <gsgeom::gsvec2f> *gsgeometrychunk::getCoordsCombined ()
	{
		process ();

		//returning null for now, need to rethink the way this happens
		return NULL;
	}

	gsutil::gsarray <unsigned int> *gsgeometrychunk::getIndex ()
	{
		if (m_bWireframe)
			return m_vWireframe[0]->pIndex;
		else
			return m_vIndices[0]->pIndex;
	}

	void gsgeometrychunk::setVerts (gsutil::gsarray <gsgeom::gsvec3f> *ptr)
	{
		gsAssert (ptr);

		m_bDirty[0] = true;
		m_vVerts = ptr;

		precomputeBB ();
	}

	void gsgeometrychunk::setNorms (gsutil::gsarray <gsgeom::gsvec3f> *ptr)
	{
		gsAssert (ptr);

		m_bDirty[1] = true;
		m_vNormals = ptr;
	}

	void gsgeometrychunk::setColors (gsutil::gsarray <gsgeom::gscolor> *ptr)
	{
		gsAssert (ptr);

		m_bDirty[2] = true;
		m_vColors = ptr;
	}

	void gsgeometrychunk::setCoords (gsutil::gsarray <gsgeom::gsvec2f> *ptr)
	{
		gsAssert (ptr);

		m_bDirty[3] = true;

		TexCoordIndex *t = new TexCoordIndex;
		
		if (m_vCoords.getSize () == 0)
		{
			t->m_iStage = m_vCoords.getSize ();
			t->pCoords = ptr;
			m_vCoords.add (t);
		}
		else if (m_vCoords.getSize () >= 1)
		{
			TexCoordIndex *old = m_vCoords[0];

			if (old->pCoords == ptr)
				return;

			m_vCoords[0]->pCoords = ptr;

			delete old;
		}
	}

	void gsgeometrychunk::setCoords (gsutil::gsarray <gsgeom::gsvec2f> *ptr, const unsigned int &stage)
	{
		gsAssert (ptr);

		//determine if we already have this size
	}

	void gsgeometrychunk::setIndex (gsutil::gsarray <unsigned int> *ptr, const unsigned int &geomType)
	{
		gsAssert (ptr);

		IndexType *it = new IndexType;
		it->m_iGeomType = geomType;
		it->pIndex = ptr;

		m_vIndices.add (it);
	}

	//------------------------------------------------------
	//private functions:
	//------------------------------------------------------
	void gsgeometrychunk::precomputeBB ()
	{
		gsAssert (m_vVerts);

		gsgeom::gsvec3f _min = (*m_vVerts)[0], _max = (*m_vVerts)[0];
		for (unsigned int x = 0; x < m_vVerts->getSize ();x ++)
		{
			if ((*m_vVerts)[x].getX () < _min.getX ())
				_min[0] = (*m_vVerts)[x].getX ();
			if ((*m_vVerts)[x].getY () < _min.getY ())
				_min[1] = (*m_vVerts)[x].getY ();
			if ((*m_vVerts)[x].getZ () < _min.getZ ())
				_min[2] = (*m_vVerts)[x].getZ ();

			if ((*m_vVerts)[x].getX () > _max.getX ())
				_max[0] = (*m_vVerts)[x].getX ();
			if ((*m_vVerts)[x].getY () > _max.getY ())
				_max[1] = (*m_vVerts)[x].getY ();
			if ((*m_vVerts)[x].getZ () > _max.getZ ())
				_max[2] = (*m_vVerts)[x].getZ ();
		}

		m_boundingBox.set (_min, _max);
	}

	void gsgeometrychunk::setUniqueId (const unsigned int &id)
	{
		m_iUniqueId = id;
	}

	unsigned int gsgeometrychunk::getUniqueId ()
	{
		return m_iUniqueId;
	}

	unsigned int gsgeometrychunk::getType ()
	{
		return m_iType;
	}

	void gsgeometrychunk::setType (const unsigned int &type)
	{
		m_iType = type;
	}

	void gsgeometrychunk::process ()
	{
		if (isVertDirty () && isNormDirty () && isColorDirty () && isCoordDirty ())
			return;

		//combine depending on the type
		switch (m_iType)
		{
		case SEPARATE:
			break;

		case SEPARATE_COMBINED:
			{
			}
			break;

		case INTERLEAVED:
			{
			}
			break;
		}
	}
};
