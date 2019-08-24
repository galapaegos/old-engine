#ifndef _gsgroup_h_
#define _gsgroup_h_

#include "gscontrol.h"

namespace gswin
{
	class gsgroup : public gscontrol
	{
	public:
		gsgroup (gswidget *parent, long style, const int &id, const int x=0, const int y=0, const int w=0, const int h=0);
		virtual ~gsgroup ();

	private:
	};
};

#endif
