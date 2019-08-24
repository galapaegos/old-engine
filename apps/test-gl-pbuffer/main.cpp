#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <gsgfx/gl/gsext.h>

#include <gswindow/gswindow.h>

using namespace gsext;

class pbuffer : public gswin::gswindow
{
public:
	pbuffer ()
	{
		m_hDC = GetDC (getHandle ());

		int pixelformat;
		memset (&m_pfd, 0, sizeof (PIXELFORMATDESCRIPTOR));
		m_pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		m_pfd.nVersion = 1;

		m_pfd.dwFlags		= PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER; 
		m_pfd.dwLayerMask	= PFD_MAIN_PLANE;
		m_pfd.iPixelType	= PFD_TYPE_RGBA;
		m_pfd.cAccumBits	= 64;
		m_pfd.cColorBits	= 32;
		m_pfd.cDepthBits	= 32;
		m_pfd.cStencilBits	= 8;

		pixelformat = ChoosePixelFormat (m_hDC, &m_pfd);

		SetPixelFormat (m_hDC, pixelformat, &m_pfd);

		m_hGLRC = wglCreateContext (m_hDC);
		wglMakeCurrent (m_hDC, m_hGLRC);

		glViewport (0, 0, getAreaWidth (), getAreaHeight ());

		glDisable (GL_LIGHTING);

		//making pbuffer
		int at[] =
		{
			WGL_SUPPORT_OPENGL_ARB, TRUE,
			WGL_DRAW_TO_PBUFFER_ARB, TRUE,
			WGL_BIND_TO_TEXTURE_RGBA_ARB, TRUE,
			WGL_RED_BITS_ARB, 8,
			WGL_GREEN_BITS_ARB, 8,
			WGL_BLUE_BITS_ARB, 8,
			WGL_ALPHA_BITS_ARB, 8,
			WGL_DEPTH_BITS_ARB, 16,
			WGL_DOUBLE_BUFFER_ARB, TRUE,
			0
		};

		unsigned int count = 0;
		int pixelFormat;
		if (!wglChoosePixelFormatARB (wglGetCurrentDC (), (const int*)at, NULL, 1, &pixelFormat, &count))
			printf ("unable to choose a pixel format\n");

		int pAttrib [] = 
		{
			WGL_TEXTURE_FORMAT_ARB, WGL_TEXTURE_RGBA_ARB,
			WGL_TEXTURE_TARGET_ARB, WGL_TEXTURE_2D_ARB,
			WGL_MIPMAP_TEXTURE_ARB, 0,
			WGL_PBUFFER_LARGEST_ARB, 0,
			0
		};

		m_pBuffer = wglCreatePbufferARB (wglGetCurrentDC (), pixelFormat, 512, 512, (const int*)pAttrib);
		m_pBufferDC = wglGetPbufferDCARB (m_pBuffer);
		m_pBufferRC = wglCreateContext (m_pBufferDC);

		glGenTextures(1, &m_TextureId);
		glBindTexture(GL_TEXTURE_2D, m_TextureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glEnable (GL_TEXTURE_2D);
	}

	~pbuffer ()
	{
		if (m_pBufferRC)
			wglDeleteContext (m_pBufferRC);

		wglDestroyPbufferARB (m_pBuffer);

		wglDeleteContext (m_hGLRC);
	}

	void onPaint ()
	{
		wglMakeCurrent (m_pBufferDC, m_pBufferRC);
		glClearColor (0.f, 1.f, 0.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		drawPBuffer ();

		SwapBuffers (m_pBufferDC);

		wglMakeCurrent (m_hDC, m_hGLRC);

		glClearColor (0.f, 0.f, 1.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glBindTexture (GL_TEXTURE_2D, m_TextureId);
		wglBindTexImageARB (m_pBuffer, WGL_FRONT_LEFT_ARB);
		draw ();
		wglReleaseTexImageARB (m_pBuffer, WGL_FRONT_LEFT_ARB);

		SwapBuffers (m_hDC);
	}

	void drawPBuffer ()
	{
		glViewport (0, 0, 512, 512);

		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluPerspective (45.f, 1, 0.1f, 300.f);

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		gluLookAt (0, 5, 5, 0, 0, 0, 0, 1, 0);

		glColor3f (1, 1, 1);
		glBegin (GL_TRIANGLES);
		glVertex3f (-1, 0, -1);
		glVertex3f (1, 0, -1);
		glVertex3f (-1, 0, 1);
		glEnd ();
	}

	void draw ()
	{
		glViewport (0, 0, getAreaWidth (), getAreaHeight ());
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluPerspective (45.f, getAreaWidth ()/getAreaHeight (), 0.1f, 300.f);

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		gluLookAt (0, 5, 5, 0, 0, 0, 0, 1, 0);

		glBegin (GL_QUADS);
		glColor3f (1, 1, 1);
		glTexCoord2f (1, 0);
		glVertex3f (-1, 0, -1);
		glColor3f (1, 1, 1);
		glTexCoord2f (0, 1);
		glVertex3f (1, 0, -1);
		glColor3f (1, 1, 1);
		glTexCoord2f (1, 1);
		glVertex3f (1, 0, 1);
		glColor3f (1, 1, 1);
		glTexCoord2f (1, 1);
		glVertex3f (-1, 0, 1);
		glEnd ();
	}

private:
	HDC m_hDC;
	HGLRC m_hGLRC;
	PIXELFORMATDESCRIPTOR m_pfd;

	int m_iWidth, m_iHeight;
	HPBUFFERARB m_pBuffer;
	HDC	m_pBufferDC;
	HGLRC m_pBufferRC;
	unsigned int m_TextureId;
};

int main (int argc, char *argv[])
{
	pbuffer *p = new pbuffer;
	p->show ();
	p->handle ();
	delete p;
	return 0;
}
