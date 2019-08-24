#ifndef _gspbuffer_h_
#define _gspbuffer_h_

#include <gsgfx/gl/gsext.h>

namespace gsext
{
	class gspbuffer
	{
	public:
#ifdef WIN32
		gspbuffer (HDC hdc, const int &w, const int &h);
#else
		gspbuffer () {}
#endif
		~gspbuffer ();

		void makeCurrent ();
		int getId () { return m_TextureId; }

		void *getData ();

	private:
		int m_iWidth, m_iHeight;
#ifdef WIN32
		HPBUFFERARB m_pBuffer;
		HDC	m_pBufferDC;
		HGLRC m_pBufferRC;
#endif
		unsigned int m_TextureId;
	};
};

#endif
