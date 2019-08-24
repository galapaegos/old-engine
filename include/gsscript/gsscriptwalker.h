#ifndef _gsscriptwalker_h_
#define _gsscriptwalker_h_

#include <gsscript/gsscriptinstruction.h>

namespace gsscr
{
	class gsscriptwalker
	{
	public:
		gsscriptwalker (gsscriptinstruction *instr)
		{
			pBegin = instr;
		}

		~gsscriptwalker () {}

		void run ()
		{
			gsscriptinstruction *start = pBegin;

			while (start != NULL)
			{
				start->process ();
				start = start->next ();
			}
		}

		gsscriptinstruction *pBegin;
	};
};

#endif
