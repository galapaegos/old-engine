#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <gsgfx/gl/gsext.h>

#include <gswindow/gswindow.h>

using namespace gsext;

class fbo : public gswin::gswindow
{
public:
	fbo ()
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

		//making fbo
		glGenFramebuffersEXT (1, &m_mainFrame);
		glBindFramebufferEXT (GL_FRAMEBUFFER_EXT, m_mainFrame);

		glGenRenderbuffersEXT (1, &m_depthRenderBuffer);
		glBindRenderbufferEXT (GL_RENDERBUFFER_EXT, m_depthRenderBuffer);
		glRenderbufferStorageEXT (GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, 512, 512);

		glGenTextures (1, &m_TextureId);
		glBindTexture (GL_TEXTURE_2D, m_TextureId);
		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glFramebufferTexture2DEXT (GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, m_TextureId, 0);
		glFramebufferRenderbufferEXT (GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, m_depthRenderBuffer);

		GLenum status = glCheckFramebufferStatusEXT (GL_FRAMEBUFFER_EXT);

		switch (status)
		{
		case GL_FRAMEBUFFER_COMPLETE_EXT:
			break;

		case GL_FRAMEBUFFER_UNSUPPORTED_EXT:
			printf ("FBO's not supported\n");
			exit (0);
			break;

		default:
			exit (-1);
		}

		glBindFramebufferEXT (GL_FRAMEBUFFER_EXT, 0);
	}

	~fbo ()
	{
	}

	void onPaint ()
	{
		//fbo
		glBindFramebufferEXT (GL_FRAMEBUFFER_EXT, m_mainFrame);

		glClearColor (0.f, 1.f, 0.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		drawPBuffer ();

		glBindFramebufferEXT (GL_FRAMEBUFFER_EXT, 0);

		//main context
		wglMakeCurrent (m_hDC, m_hGLRC);

		glClearColor (0.f, 0.f, 1.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glBindTexture (GL_TEXTURE_2D, m_TextureId);
		glEnable (GL_TEXTURE_2D);
		draw ();
		glDisable (GL_TEXTURE_2D);

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
	unsigned int m_TextureId, m_mainFrame, m_depthRenderBuffer;
};

int main (int argc, char *argv[])
{
	fbo *f = new fbo;
	f->show ();
	f->handle ();
	delete f;
	return 0;
}
