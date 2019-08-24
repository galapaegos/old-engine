#include <gsscene/gsscenemgr.h>

namespace gsscene
{
	gsscenemgr::gsscenemgr ()
	{
	}

	gsscenemgr::~gsscenemgr ()
	{
	}

	void gsscenemgr::addNode (gsscene::gsscenenode *n)
	{
		gsAssert (n);

		m_renderList.add (n);
	}

	void gsscenemgr::removeNode (gsscene::gsscenenode *n)
	{
		gsAssert (n);

		unsigned int loc = 0;
		for (loc = 0; loc < m_renderList.getSize (); loc++)
		{
			if (m_renderList[loc] == n)
				break;
		}

		if (loc >= m_renderList.getSize ())
			return;

		m_renderList.erase (loc);
		delete n;
	}

	void gsscenemgr::clear ()
	{
	}

	void gsscenemgr::draw (gsgfx::gsrenderer *renderer)
	{
		gsAssert (renderer);

		occlude ();

		sort ();

		binify ();

		//debug section
		if (m_background.getSize () == 0 && m_default.getSize () == 0 && m_transparent.getSize () == 0 && m_gui.getSize () == 0)
		{
			for (unsigned int x = 0; x < m_renderList.getSize (); x ++)
				m_visibleList[x]->preRender (renderer);

			for (unsigned int y = 0; y < m_renderList.getSize (); y ++)
				m_visibleList[y]->render (renderer);

			for (unsigned int z = 0; z < m_renderList.getSize (); z ++)
				m_visibleList[z]->postRender (renderer);
		}
		else
		{
			//pre render
			for (unsigned int a = 0; a < m_renderList.getSize (); a ++)
				m_background[a]->preRender (renderer);

			for (unsigned int d = 0; d < m_renderList.getSize (); d ++)
				m_default[d]->preRender (renderer);

			for (unsigned int g = 0; g < m_renderList.getSize (); g ++)
				m_transparent[g]->preRender (renderer);

			for (unsigned int j = 0; j < m_renderList.getSize (); j ++)
				m_gui[j]->preRender (renderer);

			//render
			for (unsigned int b = 0; b < m_renderList.getSize (); b ++)
				m_background[b]->render (renderer);

			for (unsigned int e = 0; e < m_renderList.getSize (); e ++)
				m_default[e]->render (renderer);

			for (unsigned int h = 0; h < m_renderList.getSize (); h ++)
				m_transparent[h]->render (renderer);

			for (unsigned int k = 0; k < m_renderList.getSize (); k ++)
				m_gui[k]->render (renderer);

			//post render
			for (unsigned int c = 0; c < m_renderList.getSize (); c ++)
				m_background[c]->postRender (renderer);

			for (unsigned int f = 0; f < m_renderList.getSize (); f ++)
				m_default[f]->postRender (renderer);

			for (unsigned int i = 0; i < m_renderList.getSize (); i ++)
				m_transparent[i]->postRender (renderer);

			for (unsigned int l = 0; l < m_renderList.getSize (); l ++)
				m_gui[l]->postRender (renderer);
		}
	}

	void gsscenemgr::occlude ()
	{
		m_visibleList.clear ();

		gsgeom::gscamera *c = findFirstCamera ();

		//no testing for visibility
		if (!c)
		{
			//copy renderList to visibleList!
			for (unsigned int x = 0; x < m_renderList.getSize (); x++)
				m_visibleList.add (m_renderList[x]);
			return;
		}

		gsgeom::gsfrustum f;
		f.set (c->getProjection (), c->getView ());

		for (unsigned int x = 0; x < m_renderList.getSize (); x++)
		{
			gsscene::gsscenenode *s = m_renderList[x];
			gsgeom::gsbbox bb = s->getBoundingBox ();

			if (!f.occlude (bb.getMin (), bb.getMax ()))
				m_visibleList.add (s);
		}
	}

	void gsscenemgr::sort ()
	{
		gsgeom::gscamera *c = findFirstCamera ();

		//no sorting
		if (!c)
			return;

		//need to sort by materials!
	}

	void gsscenemgr::binify ()
	{
		//determine type, then place into appropriate bins from the visibleList
	}

	gsgeom::gscamera *gsscenemgr::findFirstCamera ()
	{
		//find first camera node!
		for (unsigned int x = 0; x < m_renderList.getSize (); x++)
		{
			gscameranode *c = dynamic_cast <gscameranode*> (m_renderList[x]);
			if (c)
			{
				if (c->getType () == gsscene::gscameranode::CAMERA_MAIN)
					return c->getCamera ();
			}
		}

		return NULL;
	}
};
