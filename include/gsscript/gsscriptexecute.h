#ifndef _gsscriptexecute_h_
#define _gsscriptexecute_h_

#include "gsutil/gsqueue.h"
#include "gsscript/gsscript.h"

namespace gsscr
{
	//script virtual machine!
	class GS gsscriptexecute
	{
	public:
		gsscriptexecute ();
		~gsscriptexecute ();

		int addScript (gsscript *s);
		void removeScript (const int &s);
		void removeScript (gsscript *s);

		void run (gsscript *s);
		void run (const int &s);

	private:
		gsutil::gsqueue <gsscript*> m_script;
	};
};

#endif
