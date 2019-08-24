#ifndef _gstask_h_
#define _gstask_h_

#include "gsgeom/gsobject.h"

namespace gs
{
	// A task will be something done after with less priority compared with the events
	//I need to start preloading the level in which the player is approaching.  A task
	//will be handled 'along-side' the events, but events will have priority.  Events
	//themselves will have some priority over others, such as rendering will be the 
	//number one event handled if its ever placed in the queue.  Updating is semi-
	//important, so it *will* get handled, but (probably) after a render call.
	class GS gstask
	{
	public:
		gstask ();
		~gstask ();

		void print ();

	private:
		int m_iTask;
	};
};

#endif

