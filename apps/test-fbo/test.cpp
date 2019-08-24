#include "test.h"

using namespace gsext;

#define CHECK_FRAMEBUFFER_STATUS()								\
{																\
	GLenum status;												\
	status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);	\
	switch(status) {											\
		  case GL_FRAMEBUFFER_COMPLETE_EXT:						\
		  break;												\
		  case GL_FRAMEBUFFER_UNSUPPORTED_EXT:					\
		  /* choose different formats */						\
		  break;												\
		  default:												\
		  /* programming error; will fail on all hardware */	\
		  printf ("error:%s\n", gluErrorString (status));		\
	}															\
}

class FBO : public gswin::gswindow
{
public:
	FBO () : gswin::gswindow (0, "gs", "gsfrustum test", gswin::gsWINDOW_OVERLAPPEDWINDOW, -1, 0, 0, 800, 600)
	{
		init ();

		width = height = 256;
		firstRender = true;
	}

	~FBO ()
	{
	}

	void init ()
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
	}

	void fboInit ()
	{
		//fbo object
		glGenFramebuffersEXT (1, &fbo);
		glBindFramebufferEXT (GL_FRAMEBUFFER_EXT, fbo);

		//depth buffer
		glGenRenderbuffersEXT (1, &depthbuffer);
		glBindRenderbufferEXT (GL_RENDERBUFFER_EXT, depthbuffer);
		glRenderbufferStorageEXT (GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, width, height);

		//texture
		glGenTextures (1, &img);
		glBindTexture (GL_TEXTURE_2D, img);
		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA,  width, height, 0, GL_RGBA, GL_FLOAT, NULL);
		glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		//attach to fbo
		glFramebufferRenderbufferEXT (GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depthbuffer);
		glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, img, 0);

		//check status
		GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
		if(status != GL_FRAMEBUFFER_COMPLETE_EXT)
			exit(1);
	
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);	// Unbind the FBO for now

		GLint maxbuffers;
		glGetIntegerv (GL_MAX_COLOR_ATTACHMENTS_EXT, &maxbuffers);

		printf ("maxbuffers:%i\n", maxbuffers);
	}

	void onPaint ()
	{
		wglMakeCurrent (m_hDC, m_hGLRC);
		if (firstRender)
		{
			firstRender = false;
			fboInit ();
		}

		//render to texture
		glBindFramebufferEXT (GL_FRAMEBUFFER_EXT, fbo);
		glPushAttrib (GL_VIEWPORT_BIT);

		glClearColor (0.f, 1.f, 0.f, 0.5f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glViewport (0, 0, width, height);
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluPerspective (45.f, width/height, 0.1f, 300.f);

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		gluLookAt (5, 5, 5, 0, 0, 0, 0, 1, 0);

		glBegin (GL_TRIANGLES);
		glColor3f (1, 0, 0);
		glVertex3f (0, 0, 0);
		glColor3f (0, 1, 0);
		glVertex3f (1, 0, 0);
		glColor3f (0, 0, 1);
		glVertex3f (0, 0, 1);
		glEnd ();

		glPopAttrib();
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

		//normal rendering
		glClearColor (0.f, 1.f, 1.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glViewport (0, 0, getAreaWidth (), getAreaHeight ());
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluPerspective (45.f, getAreaWidth ()/getAreaHeight (), 0.1f, 300.f);

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		gluLookAt (0, 5, 5, 0, 0, 0, 0, 1, 0);

		glColor4f (1, 1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, img);
		glEnable (GL_TEXTURE_2D);
		glBegin (GL_QUADS);
		glTexCoord2f (0, 0);
		glVertex3f (-3, 0, -3);
		glTexCoord2f (1, 0);
		glVertex3f (3, 0, -3);
		glTexCoord2f (1, 1);
		glVertex3f (3, 0, 3);
		glTexCoord2f (0, 1);
		glVertex3f (-3, 0, 3);
		glEnd ();
		glDisable (GL_TEXTURE_2D);

		SwapBuffers (m_hDC);
	}

private:
	int oldx, oldy;
	bool m_bRotate, firstRender;

	GLuint fbo, img, depthbuffer;

	HDC m_hDC;
	HGLRC m_hGLRC;
	PIXELFORMATDESCRIPTOR m_pfd;

	int width, height;
};

class material : public gswin::gsapp
{
public:
	material () : gswin::gsapp ()
	{
	}

	virtual ~material ()
	{
	}

	void onInit ()
	{
		m_pWindow = new FBO ();
	}

	void onHandle ()
	{
		m_pWindow->handle ();
	}

	void onClose ()
	{
		delete m_pWindow;
	}

private:
	FBO *m_pWindow;
};

MAINAPPW32 (material);
