#ifndef _stubrender_h_
#define _stubrender_h_

#include <windows.h>
#include "gstypes.h"
#include "gsgfx/video/gsrenderer.h"
#include "gsgfx/video/gsscene.h"
#include "galapaegos/gskernel.h"
#include "galapaegos/gstexture.h"
#include "galapaegos/gsresourcemgr.h"

namespace gsgfx
{
	class GS stubrender : public gsrenderer
	{
	public:
		stubrender ();
		~stubrender ();

		virtual void create (void *pWnd, int width, int height);
		virtual void reset ();
		virtual void destroy ();

		virtual void beginframe ();
		virtual void endframe ();

		virtual void render (gsscene *s);

		virtual void makeCurrent ();
		
		virtual void setProjection (float temp[]);
		virtual void setView (float temp[]);
	};
};

#endif

