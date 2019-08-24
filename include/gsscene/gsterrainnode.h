#ifndef _gsterrainnode_h_
#define _gsterrainnode_h_

#include <gsscene/gsscenenode.h>

namespace gsscene
{
	class GS gsterrainnode : public gsscene::gsscenenode
	{
	public:
		gsterrainnode ();
		gsterrainnode (const unsigned int &width, const unsigned int &height);
		virtual ~gsterrainnode ();

	protected:
	};
};

#endif
