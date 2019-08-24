#ifndef _gsscriptobjectdata_h_
#define _gsscriptobjectdata_h_

#include <gsscript/gsscriptobject.h>

namespace gsscr
{
	class gsscriptobjectdata : public gs::gsscriptobject
	{
	public:
		gsscriptobjectdata (int opcode);
		gsscriptobjectdata (int opcode, gsgeom::gsobject *o, int sizeObj);
 		~gsscriptobjectdata ();

	private:
		int m_iOp;
		gsgeom::gsobject *m_pData;
	};
};

#endif
