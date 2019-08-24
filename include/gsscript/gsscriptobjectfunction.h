#ifndef _gsscriptobjectfunction_h_
#define _gsscriptobjectfunction_h_

#include <gsscript/gsscriptobject.h>

namespace gsscr
{
	class gsscriptobjectfunction : public gs::gsscriptobject
	{
	public:
		gsscriptobjectfunction (int opcode);
		gsscriptobjectfunction (int opcode, gsgeom::gsobject *o, int sizeObj);
 		~gsscriptobjectfunction ();

	private:
		int m_iOp;
		gsgeom::gsobject *m_pData;
	};
};

#endif
