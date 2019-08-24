#ifndef _gsscriptobject_h_
#define _gsscriptobject_h_

#include "gsgeom/gsobject.h"

namespace gsscr
{
	class gsscriptobject : public gsgeom::gsobject
	{
	public:
		gsscriptobject (int opcode);
		gsscriptobject (int opcode, gsgeom::gsobject *o, int sizeObj);
 		~gsscriptobject ();

	private:
		int m_iOp;
		gsgeom::gsobject *m_pData;
	};
};

#endif
