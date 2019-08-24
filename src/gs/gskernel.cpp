#include <gs/gskernel.h>

namespace gs
{
	gskernel::gskernel ()
	{
		m_iRenderRun = 0;
		m_iEventRun = 0;
	}

	gskernel::~gskernel ()
	{
	}

	void gskernel::init (gswin::gswindow *w)
	{
		gsAssert (w);

		m_pWindow = w;

		//_renderLib.load ("libgl.dll");
		_renderLib.load ("libdx9.dll");

		_renderThread.setCallback (_render, this);
		_renderThread.start ();

		_eventThread.setCallback (_event, this);
		_eventThread.start ();
	}

	void gskernel::shutdown ()
	{
		m_iRenderRun = 0;
		_renderThread.stop ();

		m_iEventRun = 0;
		_eventThread.stop ();
		
		_renderLib.unload ();
	}

	unsigned int gskernel::thrEvent ()
	{
		m_iEventRun = 1;

		while (m_iEventRun != 0)
		{
			if (m_EventList.getSize () > 0)
			{
				gs::gsevent e = m_EventList[0];
				m_EventList.erase (0);

				executeEvent (e);
			}
			else
				Sleep (0);
		}
	
		return 0;
	}

	unsigned int gskernel::thrRender ()
	{
		INIT render_init = (INIT)_renderLib.getProc ("create");

		if (render_init)
		{
			m_pRenderer = (gsgfx::gsrenderer*)render_init ();

			m_pRenderer->create (m_pWindow);

			m_iRenderRun = 1;

			while (m_iRenderRun != 0)
			{
				//render stuff!
				m_pRenderer->beginframe (gsgeom::gscolor (0, 1, 1, 1));

				//_sceneMgr->draw (m_pRenderer);

				m_pRenderer->endframe ();
			}

			m_pRenderer->destroy ();
			m_pRenderer = NULL;
		}

		return 0;
	}

	void gskernel::executeEvent (gs::gsevent e)
	{
	}
};
