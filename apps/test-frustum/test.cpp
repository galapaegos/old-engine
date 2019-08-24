#include "test.h"

class Frustum : public gswin::gswindow
{
public:
	Frustum () : gswin::gswindow (0, "gs", "gsfrustum test", gswin::gsWINDOW_OVERLAPPEDWINDOW, -1, 0, 0, 800, 600)
	{
		init ();

		float   proj[16];
		float   modl[16];
		float   clip[16];
		float   t;

		gluPerspective (45.f, 800.f/600.f, 1.f, 300.f);
		gluLookAt (0, 10, 5, 0, 0, 0, 0, 1, 0);

		// Get the current PROJECTION matrix from OpenGL
		glGetFloatv( GL_PROJECTION_MATRIX, proj );

		// Get the current MODELVIEW matrix from OpenGL
		glGetFloatv( GL_MODELVIEW_MATRIX, modl );

		// Combine the two matrices (multiply projection by modelview
		clip[ 0] = modl[ 0] * proj[ 0] + modl[ 1] * proj[ 4] + modl[ 2] * proj[ 8] + modl[ 3] * proj[12];
		clip[ 1] = modl[ 0] * proj[ 1] + modl[ 1] * proj[ 5] + modl[ 2] * proj[ 9] + modl[ 3] * proj[13];
		clip[ 2] = modl[ 0] * proj[ 2] + modl[ 1] * proj[ 6] + modl[ 2] * proj[10] + modl[ 3] * proj[14];
		clip[ 3] = modl[ 0] * proj[ 3] + modl[ 1] * proj[ 7] + modl[ 2] * proj[11] + modl[ 3] * proj[15];

		clip[ 4] = modl[ 4] * proj[ 0] + modl[ 5] * proj[ 4] + modl[ 6] * proj[ 8] + modl[ 7] * proj[12];
		clip[ 5] = modl[ 4] * proj[ 1] + modl[ 5] * proj[ 5] + modl[ 6] * proj[ 9] + modl[ 7] * proj[13];
		clip[ 6] = modl[ 4] * proj[ 2] + modl[ 5] * proj[ 6] + modl[ 6] * proj[10] + modl[ 7] * proj[14];
		clip[ 7] = modl[ 4] * proj[ 3] + modl[ 5] * proj[ 7] + modl[ 6] * proj[11] + modl[ 7] * proj[15];

		clip[ 8] = modl[ 8] * proj[ 0] + modl[ 9] * proj[ 4] + modl[10] * proj[ 8] + modl[11] * proj[12];
		clip[ 9] = modl[ 8] * proj[ 1] + modl[ 9] * proj[ 5] + modl[10] * proj[ 9] + modl[11] * proj[13];
		clip[10] = modl[ 8] * proj[ 2] + modl[ 9] * proj[ 6] + modl[10] * proj[10] + modl[11] * proj[14];
		clip[11] = modl[ 8] * proj[ 3] + modl[ 9] * proj[ 7] + modl[10] * proj[11] + modl[11] * proj[15];

		clip[12] = modl[12] * proj[ 0] + modl[13] * proj[ 4] + modl[14] * proj[ 8] + modl[15] * proj[12];
		clip[13] = modl[12] * proj[ 1] + modl[13] * proj[ 5] + modl[14] * proj[ 9] + modl[15] * proj[13];
		clip[14] = modl[12] * proj[ 2] + modl[13] * proj[ 6] + modl[14] * proj[10] + modl[15] * proj[14];
		clip[15] = modl[12] * proj[ 3] + modl[13] * proj[ 7] + modl[14] * proj[11] + modl[15] * proj[15];

		// Extract the numbers for the RIGHT plane
		frustum[0][0] = clip[ 3] - clip[ 0];
		frustum[0][1] = clip[ 7] - clip[ 4];
		frustum[0][2] = clip[11] - clip[ 8];
		frustum[0][3] = clip[15] - clip[12];

		//* Normalize the result
		t = sqrt( frustum[0][0] * frustum[0][0] + frustum[0][1] * frustum[0][1] + frustum[0][2] * frustum[0][2] );
		frustum[0][0] /= t;
		frustum[0][1] /= t;
		frustum[0][2] /= t;
		frustum[0][3] /= t;

		// Extract the numbers for the LEFT plane
		frustum[1][0] = clip[ 3] + clip[ 0];
		frustum[1][1] = clip[ 7] + clip[ 4];
		frustum[1][2] = clip[11] + clip[ 8];
		frustum[1][3] = clip[15] + clip[12];

		// Normalize the result
		t = sqrt( frustum[1][0] * frustum[1][0] + frustum[1][1] * frustum[1][1] + frustum[1][2] * frustum[1][2] );
		frustum[1][0] /= t;
		frustum[1][1] /= t;
		frustum[1][2] /= t;
		frustum[1][3] /= t;

		// Extract the BOTTOM plane
		frustum[2][0] = clip[ 3] + clip[ 1];
		frustum[2][1] = clip[ 7] + clip[ 5];
		frustum[2][2] = clip[11] + clip[ 9];
		frustum[2][3] = clip[15] + clip[13];

		// Normalize the result
		t = sqrt( frustum[2][0] * frustum[2][0] + frustum[2][1] * frustum[2][1] + frustum[2][2] * frustum[2][2] );
		frustum[2][0] /= t;
		frustum[2][1] /= t;
		frustum[2][2] /= t;
		frustum[2][3] /= t;

		// Extract the TOP plane
		frustum[3][0] = clip[ 3] - clip[ 1];
		frustum[3][1] = clip[ 7] - clip[ 5];
		frustum[3][2] = clip[11] - clip[ 9];
		frustum[3][3] = clip[15] - clip[13];

		// Normalize the result
		t = sqrt( frustum[3][0] * frustum[3][0] + frustum[3][1] * frustum[3][1] + frustum[3][2] * frustum[3][2] );
		frustum[3][0] /= t;
		frustum[3][1] /= t;
		frustum[3][2] /= t;
		frustum[3][3] /= t;

		// Extract the FAR plane
		frustum[4][0] = clip[ 3] - clip[ 2];
		frustum[4][1] = clip[ 7] - clip[ 6];
		frustum[4][2] = clip[11] - clip[10];
		frustum[4][3] = clip[15] - clip[14];

		// Normalize the result
		t = sqrt( frustum[4][0] * frustum[4][0] + frustum[4][1] * frustum[4][1] + frustum[4][2] * frustum[4][2] );
		frustum[4][0] /= t;
		frustum[4][1] /= t;
		frustum[4][2] /= t;
		frustum[4][3] /= t;

		// Extract the NEAR plane
		frustum[5][0] = clip[ 3] + clip[ 2];
		frustum[5][1] = clip[ 7] + clip[ 6];
		frustum[5][2] = clip[11] + clip[10];
		frustum[5][3] = clip[15] + clip[14];

		// Normalize the result
		t = sqrt( frustum[5][0] * frustum[5][0] + frustum[5][1] * frustum[5][1] + frustum[5][2] * frustum[5][2] );
		frustum[5][0] /= t;
		frustum[5][1] /= t;
		frustum[5][2] /= t;
		frustum[5][3] /= t;

		for (unsigned int x = 0; x < 6; x++)
		{
			printf ("frustum[%i] %f %f %f %f\n", x, frustum[x][0], frustum[x][1], frustum[x][2], frustum[x][3]);
		}
	}

	~Frustum ()
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

		glDisable (GL_LIGHTING);
	}

	void onPaint ()
	{
		wglMakeCurrent (m_hDC, m_hGLRC);

		glClearColor (0.f, 1.f, 1.f, 1.f);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glViewport (0, 0, getAreaWidth (), getAreaHeight ());
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		gluPerspective (45.f, getAreaWidth ()/getAreaHeight (), 0.1f, 300.f);

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		gluLookAt (5, 5, 5, 0, 0, 0, 0, 1, 0);

		glBegin (GL_LINES);
		//glColor3f (1, 0, 0);
		//glVertex3f (pn.getNormal ().getX ()*pn.getDistance (), pn.getNormal ().getY ()*pn.getDistance (), pn.getNormal ().getZ ()*pn.getDistance ());
		//glVertex3f (pn.getNormal ().getX ()*pn.getDistance () + pn.getNormal ().getX ()*5.f, 
		//			pn.getNormal ().getY ()*pn.getDistance () + pn.getNormal ().getY ()*5.f, 
		//			pn.getNormal ().getZ ()*pn.getDistance () + pn.getNormal ().getZ ()*5.f);
		//glColor3f (0, 1, 0);
		//glVertex3f (pb.getNormal ().getX ()*pb.getDistance (), pb.getNormal ().getY ()*pb.getDistance (), pb.getNormal ().getZ ()*pb.getDistance ());
		//glVertex3f (pb.getNormal ().getX ()*pb.getDistance () + pb.getNormal ().getX ()*5.f, 
		//			pb.getNormal ().getY ()*pb.getDistance () + pb.getNormal ().getY ()*5.f, 
		//			pb.getNormal ().getZ ()*pb.getDistance () + pb.getNormal ().getZ ()*5.f);
		//glColor3f (0, 0, 1);
		//glVertex3f (pl.getNormal ().getX ()*pl.getDistance (), pl.getNormal ().getY ()*pl.getDistance (), pl.getNormal ().getZ ()*pl.getDistance ());
		//glVertex3f (pl.getNormal ().getX ()*pl.getDistance () + pl.getNormal ().getX ()*5.f, 
		//			pl.getNormal ().getY ()*pl.getDistance () + pl.getNormal ().getY ()*5.f, 
		//			pl.getNormal ().getZ ()*pl.getDistance () + pl.getNormal ().getZ ()*5.f);
		//glColor3f (1, 1, 1);
		//glVertex3f (pr.getNormal ().getX ()*pr.getDistance (), pr.getNormal ().getY ()*pr.getDistance (), pr.getNormal ().getZ ()*pr.getDistance ());
		//glVertex3f (pr.getNormal ().getX ()*pr.getDistance () + pr.getNormal ().getX ()*5.f, 
		//			pr.getNormal ().getY ()*pr.getDistance () + pr.getNormal ().getY ()*5.f, 
		//			pr.getNormal ().getZ ()*pr.getDistance () + pr.getNormal ().getZ ()*5.f);
		//glColor3f (0, 0, 0);
		//glVertex3f (pt.getNormal ().getX ()*pt.getDistance (), pt.getNormal ().getY ()*pt.getDistance (), pt.getNormal ().getZ ()*pt.getDistance ());
		//glVertex3f (pt.getNormal ().getX ()*pt.getDistance () + pt.getNormal ().getX ()*5.f, 
		//			pt.getNormal ().getY ()*pt.getDistance () + pt.getNormal ().getY ()*5.f, 
		//			pt.getNormal ().getZ ()*pt.getDistance () + pt.getNormal ().getZ ()*5.f);
		//glColor3f (1, 1, 0);
		//glVertex3f (pf.getNormal ().getX ()*pf.getDistance (), pf.getNormal ().getY ()*pf.getDistance (), pf.getNormal ().getZ ()*pf.getDistance ());
		//glVertex3f (pf.getNormal ().getX ()*pf.getDistance () + pf.getNormal ().getX ()*5.f, 
		//			pf.getNormal ().getY ()*pf.getDistance () + pf.getNormal ().getY ()*5.f, 
		//			pf.getNormal ().getZ ()*pf.getDistance () + pf.getNormal ().getZ ()*5.f);
		glEnd ();

		SwapBuffers (m_hDC);
	}

private:
	float frustum[6][4];

	int oldx, oldy;
	bool m_bRotate;

	HDC m_hDC;
	HGLRC m_hGLRC;
	PIXELFORMATDESCRIPTOR m_pfd;
};

int main (int argc, char *argv[])
{
	Frustum *f = new Frustum;

	f->handle ();

	return 0;
}
