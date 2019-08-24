#ifndef _gslightnode_h_
#define _gslightnode_h_

#include <gsgeom/gslight.h>
#include <gsscene/gsscenenode.h>

namespace gsscene
{
	class GS gslightnode : public gsscene::gsscenenode
	{
	public:
		gslightnode ();
		virtual ~gslightnode ();

		void add (gsgeom::gslight *l);

		void remove (gsgeom::gslight *l);
		void remove (const unsigned int &index);

		virtual void preRender (gsgfx::gsrenderer *renderer);
		virtual void postRender (gsgfx::gsrenderer *renderer);

	private:
		gsutil::gsqueue <gsgeom::gslight*> m_Lights;
	};
};

#endif
