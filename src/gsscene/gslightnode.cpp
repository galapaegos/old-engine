#include <gsscene/gslightnode.h>

namespace gsscene
{
	gslightnode::gslightnode ()
	{
	}

	gslightnode::~gslightnode ()
	{
	}

	void gslightnode::add (gsgeom::gslight *l)
	{
		gsAssert (l);

		m_Lights.add (l);
	}

	void gslightnode::remove (gsgeom::gslight *l)
	{
		gsAssert (l);

		for (unsigned int x = 0; x < m_Lights.getSize (); x++)
		{
			if (m_Lights[x] == l)
			{
				m_Lights.erase (x);
				break;
			}
		}
	}

	void gslightnode::remove (const unsigned int &index)
	{
		m_Lights.erase (index);
	}

	void gslightnode::preRender (gsgfx::gsrenderer *renderer)
	{
		for (unsigned int x = 0; x < m_Lights.getSize (); x++)
			renderer->enableLight (x, m_Lights[x]);
	}

	void gslightnode::postRender (gsgfx::gsrenderer *renderer)
	{
		for (unsigned int x = 0; x < m_Lights.getSize (); x++)
			renderer->disableLight (x);
	}
};
