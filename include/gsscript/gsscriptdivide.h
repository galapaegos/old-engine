#ifndef _gsscriptdivide_h_
#define _gsscriptdivide_h_

#include <gsscript/gsobject.h>

namespace gsscr
{
	class gsscriptdivide : public gs::gsscriptobject
	{
	public:
		gsscriptdivide (const int &op) : m_iOpCode (op)
		{
		}

		//constructor has parameters, and doesn't require dependence first
		gsscriptdivide (const int &op, gsutil::gsqueue <gsscriptobjecttoken*> args) : m_iOpCode (op), m_Args (args)
		{
		}

		//constructor has parameters and a dependence that must be handled first
		gsscriptdivide (const int &op, gsscriptobjecttoken *arg, gsscriptinstruction *dependence): m_iOpCode (op), m_Args (args), m_pDependence (dependence)
		{
		}

 		virtual ~gsscriptdivide ()
		{
		}

		Type process ()
		{
			Type val = m_pDependence->process ();

			//can't divide by zero!
			if (val == 0)
				return 0;

			return arg->getValue () / val;
		}
	};
};

#endif
