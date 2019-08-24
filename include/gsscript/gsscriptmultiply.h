#ifndef _gsscriptmultiply_h_
#define _gsscriptmultiply_h_

#include <gsscript/gsobject.h>

namespace gsscr
{
	class gsscriptmultiply : public gs::gsscriptobject
	{
	public:
		gsscriptmultiply (const int &op) : m_iOpCode (op)
		{
		}

		//constructor has parameters, and doesn't require dependence first
		gsscriptmultiply (const int &op, gsutil::gsqueue <gsscriptobjecttoken*> args) : m_iOpCode (op), m_Args (args)
		{
		}

		//constructor has parameters and a dependence that must be handled first
		gsscriptmultiply (const int &op, gsscriptobjecttoken *arg, gsscriptinstruction *dependence): m_iOpCode (op), m_Args (args), m_pDependence (dependence)
		{
		}

 		virtual ~gsscriptmultiply ()
		{
		}

		Type process ()
		{
			Type val = m_pDependence->process ();

			return arg->getValue () * val;
		}
	};
};

#endif
