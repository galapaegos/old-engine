#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <gsgeom/gscamera.h>

#include <gsgfx/gl/gsext.h>

#include <gsimage/gsbmp.h>
#include <gsimage/gstexture.h>

#include <gswindow/gswindow.h>

using namespace gsext;

class patch : public gswin::gswindow
{
public:
	patch ()
	{
		width = 16;
		height = 16;
		chunkSize = 16;

		init ();

		m_pCamera = new gsgeom::gscamera;
		m_pCamera->setProjection (getWidth (), getHeight (), 45.f, 1.f, 800.f);
		m_pCamera->setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
	}

	virtual ~patch ()
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

		glViewport (0, 0, getAreaWidth (), getAreaHeight ());
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		glMultMatrixf (m_pCamera->getProjection ().getMatrix ());

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		glMultMatrixf (m_pCamera->getView ().getMatrix ());

		glColor3f (1, 1, 1);
		glBegin (GL_QUADS);

		for (unsigned int w = 0; w < width; w+=chunkSize)
		{
			for (unsigned int h = 0; h < height; h+=chunkSize)
			{
				//glBegin (GL_QUADS);

				for (unsigned int t = 0; t < chunkSize - 1; t++)
				{
					for (unsigned int u = 0; u < chunkSize - 1; u++)
					{
						gsgeom::gsvec3f p1 = mList[t*chunkSize + u];
						gsgeom::gsvec3f p2 = mList[t*chunkSize + chunkSize + u];
						gsgeom::gsvec3f p3 = mList[t*chunkSize + chunkSize + u + 1];
						gsgeom::gsvec3f p4 = mList[t*chunkSize + u + 1];

						glVertex3f (p1[0], p1[1], p1[2]);
						glVertex3f (p2[0], p2[1], p2[2]);
						glVertex3f (p3[0], p3[1], p3[2]);
						glVertex3f (p4[0], p4[1], p4[2]);
					}
				}

				//glEnd ();
			}
		}

		glEnd ();

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

		glDisable (GL_LIGHTING);

		for (unsigned int w = 0; w < width; w+=chunkSize)
		{
			for (unsigned int h = 0; h < height; h+=chunkSize)
			{
				for (unsigned int x = 0; x < chunkSize; x++)
				{
					for (unsigned int y = 0; y < chunkSize; y++)
					{
						mList.add (gsgeom::gsvec3f ((float)w*chunkSize + x, 0.f, (float)h*chunkSize + y));
					}
				}
			}
		}
	}

	void onMouseMove (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		int x = LOWORD (lParam);
		int y = HIWORD (lParam);

		if (m_bRotate)
		{
			float difx = (float)(x - oldx)*0.05f;
			float dify = (float)(y - oldy)*0.05f;

			gsgeom::gscamera *c = m_pCamera;

			//x direction
			c->pitch (dify);

			//y direction
			c->yaw (difx);
		}

		oldx = x;
		oldy = y;
	}

	void onMouseWheel (void *wParam, void *lParam)
	{
		WPARAM wp = (WPARAM)wParam;
		LPARAM lp = (LPARAM)lParam;

		gsgeom::gscamera *c = m_pCamera;
		short w = HIWORD (wp);

		float dx = -w/120.f;

		c->moveForward (dx*0.5f);
	}

	void onMouseRightDown (void *wParam, void *lParam)
	{
		m_bRotate = true;
	}

	void onMouseRightUp (void *wParam, void *lParam)
	{
		m_bRotate = false;
	}

private:
	void checkError ()
	{
		GLenum e = glGetError ();
		if (e != GL_NO_ERROR)
		{
			if (e == GL_INVALID_ENUM)
				printf ("An unacceptable value is specified for an enumerated argument.  The offending command	is ignored, and	has no other side effect than to set the error flag.\n");
			else if (e == GL_INVALID_VALUE)
				printf ("A numeric argument is out of range.  The offending command is ignored, and	has no other side effect than to set the error flag.\n");
			else if (e == GL_INVALID_OPERATION)
				printf ("The specified operation is not allowed	in the current state. The offending command is ignored, and has no other side effect than to set the error flag.\n");
			else if (e == GL_STACK_OVERFLOW)
				printf ("This command would cause a stack overflow.	 The offending command	is ignored, and	has no other side effect than to set the error flag.\n");
			else if (e == GL_STACK_UNDERFLOW)
				printf ("This command would cause a stack underflow.  The offending command is ignored, and has	no other side effect than to set the error flag.\n");
			else if (e == GL_OUT_OF_MEMORY)
				printf ("GL_OUT_OF_MEMORY\n");
			else
				printf ("unknown error\n");
		}
	}

	HDC m_hDC;
	HGLRC m_hGLRC;
	PIXELFORMATDESCRIPTOR m_pfd;

	int oldx, oldy;
	bool m_bRotate;

	int width, height, chunkSize;

	unsigned int cubeMap[6];

	gsimage::gstexture *negx, *negy, *negz, *posx, *posy, *posz;

	gsgeom::gscamera *m_pCamera;
	gsutil::gsqueue <gsgeom::gsvec3f> mList;
};

int main (int argc, char *argv[])
{
	patch c;
	c.handle ();
	return 0;
}
