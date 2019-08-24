#include "gsscript/gsscriptobject.h"

namespace gsscr
{
	gsscriptobject::gsscriptobject (int opcode)
	{
		m_iOp = opcode;
	}

	gsscriptobject::gsscriptobject (int opcode, gsobject *o, int sizeObj)
	{
		m_iOp = opcode;
	}

	gsscriptobject::~gsscriptobject ()
	{
	}
};
