#include "gsscript/gsscriptexecute.h"

namespace gsscr
{
	gsscriptexecute::gsscriptexecute ()
	{
	}

	gsscriptexecute::~gsscriptexecute ()
	{
	}

	int gsscriptexecute::addScript (gsscript *s)
	{
		m_script.add (s);
		return m_script.getSize () - 1;
	}

	void gsscriptexecute::removeScript (const int &s)
	{
		gsscript *script = m_script[s];
		m_script.erase (s);
		delete script;
	}

	void gsscriptexecute::removeScript (gsscript *s)
	{
	}

	void gsscriptexecute::run (gsscript *s)
	{
		//parse the tokens
		//add script to list
		//call execute on the script
	}

	void gsscriptexecute::run (const int &s)
	{
		m_script[s]->run ();
	}
};
