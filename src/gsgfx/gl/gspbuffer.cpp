#include <gsgfx/gl/gspbuffer.h>

namespace gsext
{
	gspbuffer::gspbuffer (HDC hdc, const int &w, const int &h)
	{
#ifdef WIN32
		int at[] =
		{
			WGL_SUPPORT_OPENGL_ARB, TRUE,
			WGL_DRAW_TO_PBUFFER_ARB, TRUE,
			WGL_BIND_TO_TEXTURE_RGBA_ARB, TRUE,
			WGL_RED_BITS_ARB, 8,
			WGL_GREEN_BITS_ARB, 8,
			WGL_BLUE_BITS_ARB, 8,
			WGL_ALPHA_BITS_ARB, 8,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_DOUBLE_BUFFER_ARB, TRUE,
			0
		};

		unsigned int count = 0;
		int pixelFormat;
		wglChoosePixelFormatARB (hdc, (const int*)at, NULL, 1, &pixelFormat, &count);

		int pAttrib [] = 
		{
			WGL_TEXTURE_FORMAT_ARB, WGL_TEXTURE_RGBA_ARB,
			WGL_TEXTURE_TARGET_ARB, WGL_TEXTURE_2D_ARB,
			WGL_MIPMAP_TEXTURE_ARB, 0,
			WGL_PBUFFER_LARGEST_ARB, 0,
			0
		};

		m_pBuffer = wglCreatePbufferARB (hdc, pixelFormat, w, h, (const int*)pAttrib);
		m_pBufferDC = wglGetPbufferDCARB (m_pBuffer);
		m_pBufferRC = wglCreateContext (m_pBufferDC);

		glGenTextures (1, &m_TextureId);
		glBindTexture (GL_TEXTURE_2D, m_TextureId);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
#endif
	}

	gspbuffer::~gspbuffer ()
	{
	}

	void gspbuffer::makeCurrent ()
	{
	}

	void *gspbuffer::getData ()
	{
		unsigned char *tmp = new unsigned char [m_iWidth*m_iHeight*4];

		glReadPixels (0, 0, m_iWidth, m_iHeight, 4, GL_UNSIGNED_BYTE, tmp);

		return tmp;
	}
};
