#ifndef _gsscript_h_
#define _gsscript_h_

#include "gsutil/gsqueue.h"
#include "gsscript/gsscriptwalker.h"

namespace gsscr
{
	class GS gsscript
	{
	public:
		gsscript ();
		virtual ~gsscript ();

		void run ();

		gsscriptwalker *pWalker;
	};
};

#endif

