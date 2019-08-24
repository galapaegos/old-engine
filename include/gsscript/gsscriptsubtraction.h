#ifndef _gsscriptobjectglobal_h_
#define _gsscriptobjectglobal_h_

#include <gsscript/gsobject.h>

namespace gsscr
{
	class gsscriptobjectglobal : public gs::gsscriptobject
	{
	public:
		gsscriptobjectglobal (int opcode);
		gsscriptobjectglobal (int opcode, gsgeom::gsobject *o, int sizeObj);
 		~gsscriptobjectglobal ();

	private:
		int m_iOp;
		gsgeom::gsobject *m_pData;
	};
};

#endif
