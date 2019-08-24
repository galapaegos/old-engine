#ifndef _gsscenenode_h_
#define _gsscenenode_h_

#include <gsgeom/gsbbox.h>
#include <gsgeom/gsbox.h>
#include <gsgeom/gscamera.h>
#include <gsgeom/gsgeometrybuffer.h>
#include <gsgeom/gslight.h>
#include <gsgeom/gsmaterial.h>
#include <gsgeom/gsmatrix.h>
#include <gsgeom/gsobject.h>
#include <gsgeom/gsvector.h>

#include <gsgfx/gsrenderer.h>

#include <gsscene/gsmaterialset.h>

#include <gsutil/gslogger.h>
#include <gsutil/gsqueue.h>
#include <gsutil/gsmutex.h>

namespace gsscene
{
	class GS gsscenenode : public gsgeom::gsgeometrybuffer
	{
	public:
		gsscenenode ();
		virtual ~gsscenenode ();

		enum RENDER_TARGET
		{
			RENDER_NORMAL = 1,
			RENDER_POSTPROCESS,
			RENDER_PREPROCESS
		};

		virtual void preRender (gsgfx::gsrenderer *renderer);
		virtual void render (gsgfx::gsrenderer *renderer);
		virtual void postRender (gsgfx::gsrenderer *renderer);

		virtual void addNode (gsscenenode *node);
		virtual void removeNode (gsscenenode *node);

		virtual void setMaterial (gsscene::gsmaterialset *m);

		virtual gsscenenode *getParent ();
		virtual void setParent (gsscenenode *node);

	protected:
		gsutil::gsstring m_strName;
		unsigned int m_RenderTarget;

		gsgeom::gsmatrix m_pTransform;

		gsscene::gsmaterialset *m_Material;

		gsutil::gsqueue <gsgeom::gslight*> m_vLight;
		gsutil::gsqueue <gsscene::gsscenenode*> m_vChildNodes;

		gsscenenode *m_pParent;
	};
};

#endif
