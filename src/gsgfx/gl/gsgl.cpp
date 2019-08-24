#include "gsgfx/gl/gsgl.h"

namespace gsgfx
{
	gsgl::gsgl ()
	{
	}

	gsgl::~gsgl ()
	{
		m_TexMgr.clear ();
	}

	void gsgl::create (gswin::gswindow *w)
	{
		gsAssert (w);

		m_pWindow = w;
#ifdef WIN32
		m_hWnd = (HWND)w->getHandle ();
		m_hDC = GetDC (m_hWnd);

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

		if (!SetPixelFormat (m_hDC, pixelformat, &m_pfd))
			MessageBox (m_hWnd, "Unable to set pixel format", "error", MB_OK);

		m_hGLRC = wglCreateContext (m_hDC);
		if (!m_hGLRC)
			MessageBox (m_hWnd, "Unable to create context", "error", MB_OK);
			//m_Log.writeLog ("unable to create context\n");
		wglMakeCurrent (m_hDC, m_hGLRC);

		glViewport (0, 0, m_pWindow->getAreaWidth (), m_pWindow->getAreaHeight ());

		glDisable (GL_LIGHTING);

		//build extension list!
		gsext::initExtensions ();

		gsutil::gsstring ext = gsext::getExtensions ();
		gsutil::gsstring arb = gsext::getARBExtensions ();

		m_Font = glGenLists (96);
		HFONT hFont = CreateFont (14, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
			ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
			FF_DONTCARE|DEFAULT_PITCH, "Arial");

		if (!hFont)
			m_Font = 0;
		else
		{
			SelectObject (m_hDC, hFont);
			wglUseFontBitmaps (m_hDC, 32, 96, m_Font);
		}
#else
		gswin::gswindow *w = (gswin::gswindow*)ptr;
		m_Window = XtWindow (w->getHandle ());
		m_display = w->getDisplay ();

		if (!m_Window || !m_display)
			printf ("Either !m_Window or !m_display\n");

		static int attribs[] = { GLX_RGBA, GLX_DOUBLEBUFFER, None };

		printf ("picking visual\n");
		XVisualInfo *vi;
		vi = glXChooseVisual (m_display, DefaultScreen (m_display), attribs);

		if (!vi)
		{
			printf ("!vi\n");
			return;
		}
		else
			printf ("Visual seems fine\n");

		printf ("checking version\n");
		int glxMajor = 0, glxMinor = 0;
		//glXQueryVersion (XtDisplay (m_display), &glxMajor, &glxMinor);
		glXQueryVersion (m_display, &glxMajor, &glxMinor);
		printf ("glX Version: %d.%d\n", glxMajor, glxMinor);

		printf ("creating context\n");
		m_glxC = glXCreateContext (m_display, vi, 0, GL_TRUE);
		if (!m_glxC)
			printf ("!m_glxC\n");
		else
			printf ("contexted created fine\n");

		printf ("init extensions\n");
		gsext::initExtensions ();
#endif
	}

	void gsgl::reset ()
	{
	}

	void gsgl::destroy ()
	{
#ifdef WIN32
		if (m_hGLRC)
		{
			makeCurrent ();
			wglDeleteContext (m_hGLRC);
		}

		if (m_hDC)
			ReleaseDC (m_hWnd, m_hDC);
#endif
	}

	void gsgl::beginframe (const gsgeom::gscolor &color)
	{
		makeCurrent ();

		glClearColor (color[0], color[1], color[2], color[3]);
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	}

	void gsgl::endframe ()
	{
#ifdef WIN32
		SwapBuffers (m_hDC);
#else
		//if (!XtIsWidget (m_Window))
		//	printf ("m_glWindow is not a window\n");
		//else
			glXSwapBuffers(m_display, m_Window);
#endif
	}

	void gsgl::render (gsgeom::gsgeometrybuffer *buffer)
	{
		int type = 0;
		gsutil::gsarray <unsigned int> *ind = buffer->getIndex (&type);
		unsigned int size = 0;
		gsutil::gsarray <gsgeom::gsvec3f> *verts = buffer->getVerts ();
		gsutil::gsarray <gsgeom::gsvec3f> *norms = buffer->getNorms ();
		gsutil::gsarray <gsgeom::gsvec2f> *coords = buffer->getCoords ();
		gsutil::gsarray <gsgeom::gscolor> *colors = buffer->getColors ();

		glColor3f (1, 1, 1);

		switch (type)
		{
		case gsgeom::gsgeometrybuffer::GS_POINT:
			{
				if (colors)
				{
					glEnableClientState (GL_COLOR_ARRAY);
					glColorPointer (4, GL_FLOAT, 0, &(*colors)[0]);
				}

				if (norms)
				{
					glEnableClientState (GL_NORMAL_ARRAY);
					glNormalPointer (GL_FLOAT, 0, &(*norms)[0]);
				}

				if (coords)
				{
					glEnableClientState (GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer (2, GL_FLOAT, 0, &(*coords)[0]);
				}

				if (verts)
				{
					glEnableClientState (GL_VERTEX_ARRAY);
					glVertexPointer (3, GL_FLOAT, 0, &(*verts)[0]);
				}

				glDrawElements (GL_POINTS, ind->getSize (), GL_UNSIGNED_INT, &(*ind)[0]);

				if (colors)
					glDisableClientState (GL_COLOR_ARRAY);

				if (norms)
					glDisableClientState (GL_NORMAL_ARRAY);

				if (coords)
					glDisableClientState (GL_TEXTURE_COORD_ARRAY);

				if (verts)
					glDisableClientState (GL_VERTEX_ARRAY);
			}
			break;

		//draw lines
		case gsgeom::gsgeometrybuffer::GS_LINE:
			{
				if (colors)
				{
					glEnableClientState (GL_COLOR_ARRAY);
					glColorPointer (4, GL_FLOAT, 0, &(*colors)[0]);
				}

				if (norms)
				{
					glEnableClientState (GL_NORMAL_ARRAY);
					glNormalPointer (GL_FLOAT, 0, &(*norms)[0]);
				}

				if (coords)
				{
					glEnableClientState (GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer (2, GL_FLOAT, 0, &(*coords)[0]);
				}

				if (verts)
				{
					glEnableClientState (GL_VERTEX_ARRAY);
					glVertexPointer (3, GL_FLOAT, 0, &(*verts)[0]);
				}

				glDrawElements (GL_LINES, ind->getSize (), GL_UNSIGNED_INT, &(*ind)[0]);

				if (colors)
					glDisableClientState (GL_COLOR_ARRAY);

				if (norms)
					glDisableClientState (GL_NORMAL_ARRAY);

				if (coords)
					glDisableClientState (GL_TEXTURE_COORD_ARRAY);

				if (verts)
					glDisableClientState (GL_VERTEX_ARRAY);
			}
			break;

		//draw triangles
		case gsgeom::gsgeometrybuffer::GS_TRIANGLE:
			{
				if (colors)
				{
					glEnableClientState (GL_COLOR_ARRAY);
					glColorPointer (4, GL_FLOAT, 0, &(*colors)[0]);
				}

				if (norms)
				{
					glEnableClientState (GL_NORMAL_ARRAY);
					glNormalPointer (GL_FLOAT, 0, &(*norms)[0]);
				}

				if (coords)
				{
					glEnableClientState (GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer (2, GL_FLOAT, 0, &(*coords)[0]);
				}

				if (verts)
				{
					glEnableClientState (GL_VERTEX_ARRAY);
					glVertexPointer (3, GL_FLOAT, 0, &(*verts)[0]);
				}

				glDrawElements (GL_TRIANGLES, ind->getSize (), GL_UNSIGNED_INT, &(*ind)[0]);

				if (colors)
					glDisableClientState (GL_COLOR_ARRAY);

				if (norms)
					glDisableClientState (GL_NORMAL_ARRAY);

				if (coords)
					glDisableClientState (GL_TEXTURE_COORD_ARRAY);

				if (verts)
					glDisableClientState (GL_VERTEX_ARRAY);
			}
			break;

		//draw triangle strips
		case gsgeom::gsgeometrybuffer::GS_TRIANGLESTRIPS:
			{
				if (colors)
				{
					glEnableClientState (GL_COLOR_ARRAY);
					glColorPointer (4, GL_FLOAT, 0, &(*colors)[0]);
				}

				if (norms)
				{
					glEnableClientState (GL_NORMAL_ARRAY);
					glNormalPointer (GL_FLOAT, 0, &(*norms)[0]);
				}

				if (coords)
				{
					glEnableClientState (GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer (2, GL_FLOAT, 0, &(*coords)[0]);
				}

				if (verts)
				{
					glEnableClientState (GL_VERTEX_ARRAY);
					glVertexPointer (3, GL_FLOAT, 0, &(*verts)[0]);
				}

				glDrawElements (GL_TRIANGLE_STRIP, ind->getSize (), GL_UNSIGNED_INT, &(*ind)[0]);

				if (colors)
					glDisableClientState (GL_COLOR_ARRAY);

				if (norms)
					glDisableClientState (GL_NORMAL_ARRAY);

				if (coords)
					glDisableClientState (GL_TEXTURE_COORD_ARRAY);

				if (verts)
					glDisableClientState (GL_VERTEX_ARRAY);
			}
			break;

		//draw squares
		case gsgeom::gsgeometrybuffer::GS_SQUARE:
			{
				if (colors)
				{
					glEnableClientState (GL_COLOR_ARRAY);
					glColorPointer (4, GL_FLOAT, 0, &(*colors)[0]);
				}

				if (norms)
				{
					glEnableClientState (GL_NORMAL_ARRAY);
					glNormalPointer (GL_FLOAT, 0, &(*norms)[0]);
				}

				if (coords)
				{
					glEnableClientState (GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer (2, GL_FLOAT, 0, &(*coords)[0]);
				}

				if (verts)
				{
					glEnableClientState (GL_VERTEX_ARRAY);
					glVertexPointer (3, GL_FLOAT, 0, &(*verts)[0]);
				}

				glDrawElements (GL_QUADS, ind->getSize (), GL_UNSIGNED_INT, &(*ind)[0]);

				if (colors)
					glDisableClientState (GL_COLOR_ARRAY);

				if (norms)
					glDisableClientState (GL_NORMAL_ARRAY);

				if (coords)
					glDisableClientState (GL_TEXTURE_COORD_ARRAY);

				if (verts)
					glDisableClientState (GL_VERTEX_ARRAY);
			}
			break;

		case gsgeom::gsgeometrybuffer::GS_FAN:
			{
				if (colors)
				{
					glEnableClientState (GL_COLOR_ARRAY);
					glColorPointer (4, GL_FLOAT, 0, &(*colors)[0]);
				}

				if (norms)
				{
					glEnableClientState (GL_NORMAL_ARRAY);
					glNormalPointer (GL_FLOAT, 0, &(*norms)[0]);
				}

				if (coords)
				{
					glEnableClientState (GL_TEXTURE_COORD_ARRAY);
					glTexCoordPointer (2, GL_FLOAT, 0, &(*coords)[0]);
				}

				if (verts)
				{
					glEnableClientState (GL_VERTEX_ARRAY);
					glVertexPointer (3, GL_FLOAT, 0, &(*verts)[0]);
				}

				glDrawElements (GL_TRIANGLE_FAN, ind->getSize (), GL_UNSIGNED_INT, &(*ind)[0]);

				if (colors)
					glDisableClientState (GL_COLOR_ARRAY);

				if (norms)
					glDisableClientState (GL_NORMAL_ARRAY);

				if (coords)
					glDisableClientState (GL_TEXTURE_COORD_ARRAY);

				if (verts)
					glDisableClientState (GL_VERTEX_ARRAY);
			}
			break;
		}
	}

	void gsgl::setMaterial (gsgeom::gsmaterial *m)
	{
		glMaterialfv (GL_FRONT, GL_AMBIENT, &m->getAmbient ()[0]);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, &m->getDiffuse ()[0]);
		glMaterialfv (GL_FRONT, GL_EMISSION, &m->getEmissive ()[0]);
		glMaterialfv (GL_FRONT, GL_SPECULAR, &m->getSpecular ()[0]);
		glMateriali (GL_FRONT, GL_SHININESS, m->getPower ());

		gsscene::gsmaterialset *cur = reinterpret_cast <gsscene::gsmaterialset*> (m);
		
		if (cur)
		{
			for (unsigned int x = 0; x < cur->getNumTextures (); x++)
			{
				int stage = 0;
				gsgeom::gstextureinfo texInfo;
				gsimage::gstexture tex;
				
				cur->getTexture (x, &stage, &tex, &texInfo);

				m_TexMgr.setTexture (&tex, &texInfo);
			}
		}
	}

	void gsgl::enableMaterial (gsgeom::gsmaterial *m)
	{
		gsscene::gsmaterialset *cur = reinterpret_cast <gsscene::gsmaterialset*> (m);
		
		if (cur)
		{
			for (unsigned int x = 0; x < cur->getNumTextures (); x++)
			{
				int stage = 0;
				gsgeom::gstextureinfo texInfo;
				gsimage::gstexture tex;
				
				cur->getTexture (x, &stage, &tex, &texInfo);

				m_TexMgr.enableTexture (stage, &tex);
			}
		}
	}

	void gsgl::cycleMaterial (gsgeom::gsmaterial *pOld, gsgeom::gsmaterial *pNew)
	{
	}

	void gsgl::disableMaterial (gsgeom::gsmaterial *m)
	{
		gsscene::gsmaterialset *cur = reinterpret_cast <gsscene::gsmaterialset*> (m);
		
		if (cur)
		{
			for (unsigned int x = 0; x < cur->getNumTextures (); x++)
			{
				int stage = 0;
				gsgeom::gstextureinfo texInfo;
				gsimage::gstexture tex;
				
				cur->getTexture (x, &stage, &tex, &texInfo);

				m_TexMgr.disableTexture (stage, &tex);
			}
		}
	}

	void gsgl::setShader (gsgeom::gsshader *s)
	{
	}

	void gsgl::enableShader (gsgeom::gsshader *s, gsutil::gsqueue <gsgeom::gsshadervariable*> *l)
	{
	}

	void gsgl::disableShader (gsgeom::gsshader *s)
	{
	}

	void gsgl::enableLight (const unsigned int &index, gsgeom::gslight *l)
	{
		if (index == 0)
			glEnable (GL_LIGHTING);

		glEnable (GL_LIGHT0 + index);
		
		glLightfv (GL_LIGHT0 + index, GL_AMBIENT, &l->getAmbient ()[0]);
		glLightfv (GL_LIGHT0 + index, GL_DIFFUSE, &l->getDiffuse ()[0]);
		GLfloat pos[4];
		pos[0] = l->getPos ()[0];
		pos[1] = l->getPos ()[1];
		pos[2] = l->getPos ()[2];
		pos[3] = 1.f;
		glLightfv (GL_LIGHT0 + index, GL_POSITION, pos);
	}

	void gsgl::disableLight (const unsigned int &index)
	{
		glDisable (GL_LIGHT0 + index);

		if (index == 0)
			glDisable (GL_LIGHTING);
	}

	void gsgl::setTexture (gsimage::gstexture *t, gsgeom::gstextureinfo *texInfo)
	{
		gsAssert (t);

		m_TexMgr.setTexture (t, texInfo);
	}

	void gsgl::enableTexture (const unsigned int &index, gsimage::gstexture *t)
	{
		m_TexMgr.enableTexture (index, t);
	}

	void gsgl::disableTexture (const unsigned int &index, gsimage::gstexture *t)
	{
		m_TexMgr.disableTexture (index, t);
	}

	void gsgl::drawText (const gsgeom::gsvec3f &pos, const gsgeom::gscolor &col, const gsutil::gsstring &text)
	{
		if (m_Font == 0)
			return;

		glColor4f (col.getR (), col.getG (), col.getB (), col.getA ());
		glRasterPos3f (pos[0], pos[1], pos[2]);

		glPushAttrib (GL_LIST_BIT);
		glListBase (m_Font - 32);
		glCallLists (text.size (), GL_UNSIGNED_BYTE, text.str ());
		glPopAttrib ();
	}

	void gsgl::makeCurrent ()
	{
#ifdef WIN32
		wglMakeCurrent (m_hDC, m_hGLRC);
#else
		if (!glXMakeCurrent (m_display, m_Window, m_glxC))
		{
			printf ("Unable to make current\n");
		}
#endif
	}

	void gsgl::setProjection (const gsgeom::gsmatrix &proj)
	{
		gsgeom::gsmatrix m = proj;

		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		glLoadTransposeMatrixf (m.getMatrix ());
	}

	void gsgl::setView (const gsgeom::gsmatrix &view)
	{
		gsgeom::gsmatrix m = view;

		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity ();
		glLoadTransposeMatrixf (m.getMatrix ());
	}

	void gsgl::process (gsgeom::gsstate *buffer)
	{
		if (buffer->getLineSettings ())
		{
			if (buffer->getLineWidth () > 1.f)
				glLineWidth (buffer->getLineWidth ());
		}

		if (buffer->getCulling ())
		{
			glEnable (GL_CULL_FACE);
			switch (buffer->getCullFace ())
			{
			case gsgeom::gsgeometrybuffer::CULL_FRONT:
				glCullFace (GL_FRONT);
				break;

			case gsgeom::gsgeometrybuffer::CULL_BACK:
				glCullFace (GL_BACK);
				break;

			case gsgeom::gsgeometrybuffer::CULL_FRONT_AND_BACK:
				glCullFace (GL_FRONT_AND_BACK);
				break;
			}
		}

		if (buffer->getDepthTest ())
		{
			glEnable (GL_DEPTH_TEST);

			glClearDepth (buffer->getDepthValue ());

			switch (buffer->getDepthFunc ())
			{
			case gsgeom::gsgeometrybuffer::DEPTH_ALWAYS:
				glDepthFunc (GL_ALWAYS);
				break;

			case gsgeom::gsgeometrybuffer::DEPTH_EQUAL:
				glDepthFunc (GL_EQUAL);
				break;

			case gsgeom::gsgeometrybuffer::DEPTH_GEQUAL:
				glDepthFunc (GL_GEQUAL);
				break;

			case gsgeom::gsgeometrybuffer::DEPTH_GREATER:
				glDepthFunc (GL_GREATER);
				break;

			case gsgeom::gsgeometrybuffer::DEPTH_LEQUAL:
				glDepthFunc (GL_LEQUAL);
				break;

			case gsgeom::gsgeometrybuffer::DEPTH_LESS:
				glDepthFunc (GL_LESS);
				break;
				
			case gsgeom::gsgeometrybuffer::DEPTH_NEVER:
				glDepthFunc (GL_NEVER);
				break;

			case gsgeom::gsgeometrybuffer::DEPTH_NOTEQUAL:
				glDepthFunc (GL_NOTEQUAL);
				break;
			}
		}

		if (buffer->getAlphaTest ())
		{
			glEnable (GL_ALPHA_TEST);

			switch (buffer->getAlphaFunc ())
			{
			case gsgeom::gsgeometrybuffer::ALPHA_ALWAYS:
				glAlphaFunc (GL_ALWAYS, buffer->getAlphaFuncRef ());
				break;

			case gsgeom::gsgeometrybuffer::ALPHA_EQUAL:
				glAlphaFunc (GL_EQUAL, buffer->getAlphaFuncRef ());
				break;

			case gsgeom::gsgeometrybuffer::ALPHA_GEQUAL:
				glAlphaFunc (GL_GEQUAL, buffer->getAlphaFuncRef ());
				break;

			case gsgeom::gsgeometrybuffer::ALPHA_GREATER:
				glAlphaFunc (GL_GREATER, buffer->getAlphaFuncRef ());
				break;

			case gsgeom::gsgeometrybuffer::ALPHA_LEQUAL:
				glAlphaFunc (GL_LEQUAL, buffer->getAlphaFuncRef ());
				break;

			case gsgeom::gsgeometrybuffer::ALPHA_LESS:
				glAlphaFunc (GL_LESS, buffer->getAlphaFuncRef ());
				break;
				
			case gsgeom::gsgeometrybuffer::ALPHA_NEVER:
				glAlphaFunc (GL_NEVER, buffer->getAlphaFuncRef ());
				break;

			case gsgeom::gsgeometrybuffer::ALPHA_NOTEQUAL:
				glAlphaFunc (GL_NOTEQUAL, buffer->getAlphaFuncRef ());
				break;
			}
		}

		if (buffer->getStencilTest ())
		{
			int s = buffer->getStencilTestSeparate ();

			if (s == gsgeom::gsgeometrybuffer::STENCIL_BACK)
			{
				//glStencilFunc (e->getStencilFunc (s), ,);
			}
		}

		if (buffer->getBlend ())
		{
			glEnable (GL_BLEND);

			switch (buffer->getBlendEquation ())
			{
			case gsgeom::gsgeometrybuffer::BLEND_FUNC_ADD:
				glBlendEquation (GL_FUNC_ADD);
				break;

			case gsgeom::gsgeometrybuffer::BLEND_FUNC_REVERSE_SUBTRACT:
				glBlendEquation (GL_FUNC_REVERSE_SUBTRACT);
				break;

			case gsgeom::gsgeometrybuffer::BLEND_FUNC_SUBTRACT:
				glBlendEquation (GL_FUNC_SUBTRACT);
				break;

			case gsgeom::gsgeometrybuffer::BLEND_MAX:
				glBlendEquation (GL_MAX);
				break;

			case gsgeom::gsgeometrybuffer::BLEND_MIN:
				glBlendEquation (GL_MIN);
				break;
			}

			glBlendFuncSeparate (buffer->getBlendFunc (gsgeom::gsgeometrybuffer::BLEND_COLOR, buffer->gsgeom::gsgeometrybuffer::BLEND_SRC),
				buffer->getBlendFunc (gsgeom::gsgeometrybuffer::BLEND_COLOR, gsgeom::gsgeometrybuffer::BLEND_DST),
				buffer->getBlendFunc (gsgeom::gsgeometrybuffer::BLEND_ALPHA, gsgeom::gsgeometrybuffer::BLEND_SRC),
				buffer->getBlendFunc (gsgeom::gsgeometrybuffer::BLEND_ALPHA, gsgeom::gsgeometrybuffer::BLEND_DST));
		}
	}

	void gsgl::unprocess (gsgeom::gsgeometrybuffer *buffer)
	{
		if (buffer->getLineSettings ())
		{
			glLineWidth (1.f);
		}

		if (buffer->getCulling ())
			glDisable (GL_CULL_FACE);

		if (buffer->getDepthTest ())
			glDisable (GL_DEPTH_TEST);

		//if (buffer->getStencilTest ())
		//	glDisable (GL_STENCIL_TEST);

		if (buffer->getBlend ())
			glDisable (GL_BLEND);
	}
};
