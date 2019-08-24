#ifndef _gskernel_h_
#define _gskernel_h_

#ifdef WIN32
#include <windows.h>
#else
#define WINAPI
#include <Xm/Xm.h>
#endif


#include <stdlib.h>

#include <gs/gsevent.h>
#include <gs/gsresourcemgr.h>
#include <gs/gstask.h>

#include <gsgeom/gscamera.h>
#include <gsgeom/gsfrustum.h>

#include <gsgfx/gsrenderer.h>

#include <gsphyzics/gscollision.h>

#include <gsutil/gslibrary.h>
#include <gsutil/gslogger.h>
#include <gsutil/gsmutex.h>
#include <gsutil/gsqueue.h>
#include <gsutil/gssingleton.h>
#include <gsutil/gstimer.h>
#include <gsutil/gsthread.h>

namespace gs
{
	class GS gskernel
	{
	public:
		gskernel ();
		~gskernel ();

		void init (gswin::gswindow *w);
		void shutdown ();

		unsigned int thrEvent ();

		unsigned int thrRender ();

	protected:
		void executeEvent (gs::gsevent e);

	private:
		static unsigned int CALLBACK _render (void *ptr)
		{ return ((gskernel*)ptr)->thrRender (); }

		static unsigned int CALLBACK _event (void *ptr)
		{ return ((gskernel*)ptr)->thrEvent (); }

		//render thread
		gsutil::gsthread _renderThread;
		gsutil::gslibrary _renderLib;
		gsgfx::gsrenderer *m_pRenderer;

		//event thread
		gsutil::gsthread _eventThread;
		gsutil::gsqueue <gs::gsevent> m_EventList;

		gswin::gswindow *m_pWindow;

		unsigned int m_iRenderRun, m_iEventRun;

		typedef void* (WINAPI *INIT)();
	};

};

#endif

