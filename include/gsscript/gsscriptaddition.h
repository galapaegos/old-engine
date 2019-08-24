#ifndef _gsscriptaddition_h_
#define _gsscriptaddition_h_

#include <gsscript/gsscriptinstruction.h>

namespace gsscr
{
	class gsscriptaddition : public gsscr::gsscriptinstruction
	{
	public:
		gsscriptaddition (const int &op, gsscriptinstruction *next) : gsscriptinstruction (op, next)
		{
			m_iOpCode = op;
			m_pNext = next;
		}

		//constructor has parameters, and doesn't require dependence first
		gsscriptaddition (const int &op, gsscriptinstruction *next, gsutil::gsqueue <gsscriptobjecttoken*> args) : gsscriptinstruction (op, next, args)
		{
			m_iOpCode = op;
			m_pNext = next;
			m_Args = args;
		}

		//constructor has parameters and a dependence that must be handled first
		gsscriptaddition (const int &op, gsscriptinstruction *next, gsscriptobjecttoken *arg, gsscriptinstruction *dependence): gsscriptinstruction (op, next, arg, dependence)
		{
			m_iOpCode = op;
			m_pNext = next;
			m_Args.add (arg);
			m_pDependence = dependence;
		}

 		virtual ~gsscriptaddition ()
		{
		}

		void process ()
		{
			//Type val = m_pDependence->process ();

			//return arg->getValue () + val;
		}
	};
};

#endif
