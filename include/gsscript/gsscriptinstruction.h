#ifndef _gsscriptinstruction_h_
#define _gsscriptinstruction_h_

#include <gsutil/gsqueue.h>
#include <gsscript/gsscriptobjecttoken.h>

namespace gsscr
{
	// default instruction is a noop.  Using the args/dependence parameters, the stackwalker will create the instruction
	// process will then handle the dependence first (and return a value).  Then handle the specific operation next.
	class GS gsscriptinstruction
	{
	public:
		//default constructor, has no parameters passed
		gsscriptinstruction (const int &op, gsscriptinstruction *next) : m_iOpCode (op), m_pNext (next)
		{
		}

		//constructor has parameters, and doesn't require dependence first
		gsscriptinstruction (const int &op, gsscriptinstruction *next, gsutil::gsqueue <gsscriptobjecttoken*> args) : m_iOpCode (op), m_Args (args), m_pNext (next)
		{
		}

		//constructor has parameters and a dependence that must be handled first
		gsscriptinstruction (const int &op, gsscriptinstruction *next, gsscriptobjecttoken *arg, gsscriptinstruction *dependence): m_iOpCode (op), m_pDependence (dependence), m_pNext (next)
		{
			m_Args.add (arg);
		}

		virtual ~gsscriptinstruction ()
		{
		}

		int getOpCode () { return m_iOpCode; }

		//All the 'real' values are stored elsewhere!
		//Text is processed via gsscriptobjecttoken
		void process () { }
		gsscriptinstruction *next ()
		{
			return m_pNext;
		}

	protected:
		gsscriptobjecttoken *m_pToken;

		//required to be resolved before this instruction will be executed.
		gsscriptinstruction *m_pDependence, *m_pNext;

		gsutil::gsqueue <gsscriptobjecttoken*> m_Args;

		int m_iOpCode;
	};
};

#endif
