#ifndef _gsguiedit_h_
#define _gsguiedit_h_

#include <gsutil/gsstring.h>

namespace gs
{
	class GS gsguiwidget
	{
	public:
		gsguiwidget (const int &x, const int &y, const int &w, const int &h, const gsutil::gsstring &title);
		~gsguiwidget ();

		int getX () { return m_iX; }
		int getY () { return m_iY; }
		int getWidth () { return m_iWidth; }
		int getHeight () { return m_iHeight; }

	private:
		int m_iX, m_iY, m_iWidth, m_iHeight;
	};
};

#endif
