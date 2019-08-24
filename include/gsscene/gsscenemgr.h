#ifndef _gsscenemgr_h_
#define _gsscenemgr_h_

#include <gsgfx/gsrenderer.h>

#include <gsscene/gscameranode.h>
#include <gsscene/gslightnode.h>
#include <gsscene/gsscenenode.h>
#include <gsscene/gsterrainnode.h>
#include <gsscene/gstextnode.h>

namespace gsscene
{
	class GS gsscenemgr
	{
	public:
		gsscenemgr ();
		~gsscenemgr ();

		void addNode (gsscene::gsscenenode *n);
		void removeNode (gsscene::gsscenenode *n);
		void clear ();

		void draw (gsgfx::gsrenderer *renderer);

	private:
		void occlude ();
		void sort ();
		void binify ();

		gsgeom::gscamera *findFirstCamera ();

		gsutil::gsqueue <gsscene::gsscenenode*> m_background;
		gsutil::gsqueue <gsscene::gsscenenode*> m_default;
		gsutil::gsqueue <gsscene::gsscenenode*> m_transparent;
		gsutil::gsqueue <gsscene::gsscenenode*> m_gui;

		//
		gsutil::gsqueue <gsscene::gsscenenode*> m_renderList;
		gsutil::gsqueue <gsscene::gsscenenode*> m_visibleList;
	};
};

#endif
