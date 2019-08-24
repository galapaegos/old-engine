#ifndef _gsgeometrychunk_h_
#define _gsgeometrychunk_h_

#include <gsutil/gsarray.h>
#include <gsutil/gsassert.h>
#include <gsutil/gsmutex.h>

#include <gsgeom/gsbbox.h>
#include <gsgeom/gscamera.h>
#include <gsgeom/gscolor.h>
#include <gsgeom/gsfrustum.h>
#include <gsgeom/gslight.h>
#include <gsgeom/gsmatrix.h>
#include <gsgeom/gsmaterial.h>
#include <gsgeom/gsobject.h>
#include <gsgeom/gsshader.h>
#include <gsgeom/gsshadervariable.h>
#include <gsgeom/gstextureinfo.h>
#include <gsgeom/gsvector.h>

namespace gsgeom
{
	class GS gsgeometrychunk
	{
	public:
		gsgeometrychunk ();
		~gsgeometrychunk ();

		enum VECTOR_TYPE
		{
			GS_POINT = 1,
			GS_LINE,
			GS_LINESTRIPS,
			GS_LINELOOP,
			GS_TRIANGLE,
			GS_TRIANGLESTRIPS,
			GS_SQUARE,
			GS_SQUARESTRIPS,
			GS_FAN
		};
		bool visible (const gsgeom::gscamera *);

		void wireframe (const bool &);

		gsutil::gsarray <gsgeom::gsvec3f> *getVerts ();
		gsutil::gsarray <gsgeom::gsvec3f> *getNorms ();
		gsutil::gsarray <gsgeom::gscolor> *getColors ();

		//grabs first texture stage coordinates
		gsutil::gsarray <gsgeom::gsvec2f> *getCoords ();
		//grab specific stage of coordinates
		gsutil::gsarray <gsgeom::gsvec2f> *getCoords (const unsigned int &stage);
		//combines all texture stages
		gsutil::gsarray <gsgeom::gsvec2f> *getCoordsCombined ();

		gsutil::gsarray <unsigned int> *getIndex (const unsigned int &index);
		gsutil::gsarray <unsigned int> *getIndex (int *geomType);
		gsutil::gsarray <unsigned int> *getIndex ();

		void setVerts (gsutil::gsarray <gsgeom::gsvec3f> *ptr);
		void setNorms (gsutil::gsarray <gsgeom::gsvec3f> *ptr);
		void setColors (gsutil::gsarray <gsgeom::gscolor> *ptr);
		void setCoords (gsutil::gsarray <gsgeom::gsvec2f> *ptr);
		void setCoords (gsutil::gsarray <gsgeom::gsvec2f> *ptr, const unsigned int &stage);
		void setIndex (gsutil::gsarray <unsigned int> *ptr, const unsigned int &geomType);

		void setDirtyVert (const bool &b) { m_bDirty[0] = b; }
		void setDirtyNorm (const bool &b) { m_bDirty[1] = b; }
		void setDirtyColors (const bool &b) { m_bDirty[2] = b; }
		void setDirtyCoord (const bool &b) { m_bDirty[3] = b; }

		bool isVertDirty () { return m_bDirty[0]; }
		bool isNormDirty () { return m_bDirty[1]; }
		bool isColorDirty () { return m_bDirty[2]; }
		bool isCoordDirty () { return m_bDirty[3]; }

		gsgeom::gsbbox getBoundingBox () { return m_boundingBox; }

		void setUniqueId (const unsigned int &id);
		unsigned int getUniqueId ();

		unsigned int getType ();
		void setType (const unsigned int &type);
		void process ();

		enum PROCESS_TYPE
		{
			//all pointers are arrays
			SEPARATE,

			//combines the texture coords into a single array
			SEPARATE_COMBINED,

			//Interleaves all data with the points
			INTERLEAVED
		};

	protected:
		void precomputeBB ();

		float m_fDistance;

		bool m_bDirty[4], m_bWireframe;

		gsgeom::gsbbox m_boundingBox;

		//description of objects
		gsutil::gsarray <gsgeom::gsvec3f> *m_vVerts;
		gsutil::gsarray <gsgeom::gsvec3f> *m_vNormals;
		gsutil::gsarray <gsgeom::gscolor> *m_vColors;

		// temporary structure to hold texture coordinates per stage
		class TexCoordIndex
		{
		public:
			TexCoordIndex () : pCoords (NULL), m_iStage (0) {}
			~TexCoordIndex () {}

			gsutil::gsarray <gsgeom::gsvec2f> *pCoords;
			unsigned int m_iStage;
		};

		gsutil::gsqueue <TexCoordIndex*> m_vCoords;

		// temporary structure to hold the index list including geometry type
		class IndexType
		{
		public:
			IndexType () : m_iGeomType (0), pIndex (NULL) {}
			~IndexType () {}

			gsutil::gsarray <unsigned int> *pIndex;
			unsigned int m_iGeomType;
		};

		gsutil::gsqueue <IndexType*> m_vIndices;
		gsutil::gsqueue <IndexType*> m_vWireframe;

		//used from within the rendering driver
		unsigned int m_iUniqueId;

		unsigned int m_iType;
	};
};

#endif
