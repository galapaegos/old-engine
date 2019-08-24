#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <gsgfx/gl/gsext.h>

#include <gsimage/gsbmp.h>
#include <gsimage/gstexture.h>

#include <gswindow/gsapp.h>
#include <gswindow/gswindow.h>

using namespace gsext;

class cubemap : public gswin::gswindow
{
public:
	cubemap ()
	{
		init ();
	}

	virtual ~cubemap ()
	{
		glDeleteTextures (6, &cubeMap[0]);
		DeleteDC (m_hDC);
		wglDeleteContext (m_hGLRC);
	}

	void onPaint ()
	{
		wglMakeCurrent (m_hDC, m_hGLRC);

		glClearColor (0.f, 1.f, 1.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		//glEnable (GL_LIGHTING);
		//glEnable (GL_LIGHT0);

		//GLfloat amb[] = { 0.3f, 0.3f, 0.3f, 1.0f };
		//glLightfv (GL_LIGHT0, GL_AMBIENT, amb);
		//GLfloat dif[] = { 0.f, 1.f, 1.f, 1.f };
		//glLightfv (GL_LIGHT0, GL_DIFFUSE, dif);
		//GLfloat pos[] = { 0.f, 2.f, 0.f, 1.f };
		//glLightfv (GL_LIGHT0, GL_POSITION, pos);

		float ambi[] = { 0.2f, 0.2f, 0.2f, 1.f };
		glMaterialfv (GL_FRONT, GL_AMBIENT, ambi);
		float diff[] = { 0.3f, 0.3f, 0.3f, 1.f } ;
		glMaterialfv (GL_FRONT, GL_DIFFUSE, diff);
		float emi[] = { 1, 1, 1, 1 };
		//glMaterialfv (GL_FRONT, GL_EMISSION, emi);
		float spec[] = { 1, 1, 1, 1 };
		//glMaterialfv (GL_FRONT, GL_SPECULAR, spec);
		int power = 1;
		//glMateriali (GL_FRONT, GL_SHININESS, power);

		glViewport (0, 0, getAreaWidth (), getAreaHeight ());
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluPerspective (45.f, getAreaWidth ()/getAreaHeight (), 0.1f, 300.f);

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		gluLookAt (0, 2, 2, 0, 0, 0, 0, 1, 0);

		glColor3f (1, 1, 1);

		glBegin (GL_QUADS);

		glNormal3f (0, 1, 0);
		glVertex3f (0, 0, 0);

		glNormal3f (0, 1, 0);
		glVertex3f (1, 0, 0);

		glNormal3f (0, 1, 0);
		glVertex3f (1, 0, 1);

		glNormal3f (0, 1, 0);
		glVertex3f (0, 0, 1);

		glEnd ();

		//glDisable (GL_LIGHT0);
		//glDisable (GL_LIGHTING);

		SwapBuffers (m_hDC);
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

		//glEnable (GL_LIGHT0);
		//glDisable (GL_LIGHT0);
	}

private:
	HDC m_hDC;
	HGLRC m_hGLRC;
	PIXELFORMATDESCRIPTOR m_pfd;

	unsigned int cubeMap[6];

	gsimage::gstexture *negx, *negy, *negz, *posx, *posy, *posz;
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
		m_pWindow = new cubemap ();
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
	cubemap *m_pWindow;
};

MAINAPPW32 (material);
