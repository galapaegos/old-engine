#include <gsscene/gsscenenode.h>

namespace gsscene
{
	gsscenenode::gsscenenode () : m_pParent (NULL), m_Material (NULL), m_RenderTarget (RENDER_NORMAL)
	{
	}

	gsscenenode::~gsscenenode ()
	{
	}

	void gsscenenode::preRender (gsgfx::gsrenderer *renderer)
	{
		for (unsigned int x = 0; x < m_vChildNodes.getSize (); x++)
			m_vChildNodes[x]->preRender (renderer);
	}

	void gsscenenode::render (gsgfx::gsrenderer *renderer)
	{
		//setup (renderer);

		if (m_Material)
			renderer->setMaterial (m_Material);

		if (m_Material)
			renderer->enableMaterial (m_Material);

		if (m_vVerts && m_vVerts->getSize () > 0 && m_vIndices.getSize ())
			renderer->render (this);

		for (unsigned int x = 0; x < m_vChildNodes.getSize (); x++)
			m_vChildNodes[x]->render (renderer);

		if (m_Material)
			renderer->disableMaterial (m_Material);
	}

	void gsscenenode::postRender (gsgfx::gsrenderer *renderer)
	{
		for (unsigned int x = 0; x < m_vChildNodes.getSize (); x++)
			m_vChildNodes[x]->postRender (renderer);
	}

	void gsscenenode::addNode (gsscene::gsscenenode *node)
	{
		gsAssert (node);

		m_vChildNodes.add (node);
	}

	void gsscenenode::removeNode (gsscene::gsscenenode *node)
	{
		gsAssert (node);
	}

	void gsscenenode::setMaterial (gsscene::gsmaterialset *m)
	{
		gsAssert (m);
		m_Material = m;
	}

	gsscene::gsscenenode *gsscenenode::getParent ()
	{
		return m_pParent;
	}

	void gsscenenode::setParent (gsscene::gsscenenode *node)
	{
		gsAssert (node);
		m_pParent = node;
	}
};
