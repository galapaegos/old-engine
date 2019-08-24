#include "gsgfx/gl/gsext.h"

#ifdef WIN32
#define GETPROC(x) wglGetProcAddress(x)
#else
#define GETPROC(x) glXGetProcAddress((const unsigned char*)x)
#endif

namespace gsext
{
	static void APIENTRY InitBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
	{
		void *ext = (void*)GETPROC ("glBlendColor");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBlendColor = (void (APIENTRY*) (GLclampf, GLclampf, GLclampf, GLclampf))ext;
		glBlendColor (red, green, blue, alpha);
	}

	static void APIENTRY InitBlendEquation (GLenum eq)
	{
		void *ext = (void*)GETPROC ("glBlendEquation");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBlendEquation = (void (APIENTRY *)(GLenum))ext;
		glBlendEquation (eq);
	}

	static void APIENTRY InitDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
	{
		void *ext = (void*)GETPROC ("glDrawRangeElements");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDrawRangeElements = (void (APIENTRY*) (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *))ext;
		glDrawRangeElements (mode, start, end, count, type, indices);
	}

	static void APIENTRY InitColorTable (GLenum l, GLenum m, GLsizei s, GLenum t, GLenum u, const GLvoid *v)
	{
		void *ext = (void*)GETPROC ("glColorTable");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glColorTable = (void (APIENTRY* ) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))ext;
		glColorTable (l, m, s, t, u, v);
	}

	static void APIENTRY InitColorTableParameterfv (GLenum a, GLenum b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glColorTableParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glColorTableParameterfv = (void (APIENTRY* ) (GLenum, GLenum, const GLfloat *))ext;
		glColorTableParameterfv (a, b, c);
	}

	static void APIENTRY InitColorTableParameteriv (GLenum a, GLenum b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glColorTableParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glColorTableParameteriv = (void (APIENTRY* ) (GLenum, GLenum, const GLint *))ext;
		glColorTableParameteriv (a, b, c);
	}

	static void APIENTRY InitCopyColorTable (GLenum a, GLenum b, GLint c, GLint d, GLsizei e)
	{
		void *ext = (void*)GETPROC ("glCopyColorTable");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCopyColorTable = (void (APIENTRY* ) (GLenum, GLenum, GLint, GLint, GLsizei))ext;
		glCopyColorTable (a, b, c, d, e);
	}

	static void APIENTRY InitGetColorTable (GLenum a, GLenum b, GLenum c, GLvoid *d)
	{
		void *ext = (void*)GETPROC ("glGetColorTable");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetColorTable = (void (APIENTRY* ) (GLenum, GLenum, GLenum, GLvoid *))ext;
		glGetColorTable (a, b, c, d);
	}

	static void APIENTRY InitGetColorTableParameterfv (GLenum a, GLenum b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetColorTableParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetColorTableParameterfv = (void (APIENTRY* ) (GLenum, GLenum, GLfloat *))ext;
		glGetColorTableParameterfv (a, b, c);
	}

	static void APIENTRY InitGetColorTableParameteriv (GLenum a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetColorTableParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetColorTableParameteriv = (void (APIENTRY* ) (GLenum, GLenum, GLint *))ext;
		glGetColorTableParameteriv (a, b, c);
	}

	static void APIENTRY InitColorSubTable (GLenum a, GLsizei b, GLsizei c, GLenum d, GLenum e, const GLvoid *f)
	{
		void *ext = (void*)GETPROC ("glColorSubTable");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glColorSubTable = (void (APIENTRY* ) (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))ext;
		glColorSubTable (a, b, c, d, e, f);
	}

	static void APIENTRY InitCopyColorSubTable (GLenum a, GLsizei b, GLint c, GLint d, GLsizei e)
	{
		void *ext = (void*)GETPROC ("glCopyColorSubTable");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCopyColorSubTable = (void (APIENTRY* ) (GLenum, GLsizei, GLint, GLint, GLsizei))ext;
		glCopyColorSubTable (a, b, c, d, e);
	}

	static void APIENTRY InitConvolutionFilter1D (GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const GLvoid *f)
	{
		void *ext = (void*)GETPROC ("glConvolutionFilter1D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glConvolutionFilter1D = (void (APIENTRY* ) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))ext;
		glConvolutionFilter1D (a, b, c, d, e, f);
	}

	static void APIENTRY InitConvolutionFilter2D (GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g)
	{
		void *ext = (void*)GETPROC ("glConvolutionFilter2D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glConvolutionFilter2D = (void (APIENTRY* ) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))ext;
		glConvolutionFilter2D (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitConvolutionParameterf (GLenum a, GLenum b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glConvolutionParameterf");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glConvolutionParameterf = (void (APIENTRY* ) (GLenum, GLenum, GLfloat))ext;
		glConvolutionParameterf (a, b, c);
	}

	static void APIENTRY InitConvolutionParameterfv (GLenum a, GLenum b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glConvolutionParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glConvolutionParameterfv = (void (APIENTRY* ) (GLenum, GLenum, const GLfloat *))ext;
		glConvolutionParameterfv (a, b, c);
	}

	static void APIENTRY InitConvolutionParameteri (GLenum a, GLenum b, GLint c)
	{
		void *ext = (void*)GETPROC ("glConvolutionParameteri");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glConvolutionParameteri = (void (APIENTRY* ) (GLenum, GLenum, GLint))ext;
		glConvolutionParameteri (a, b, c);
	}

	static void APIENTRY InitConvolutionParameteriv (GLenum a, GLenum b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glConvolutionParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glConvolutionParameteriv = (void (APIENTRY* ) (GLenum, GLenum, const GLint *))ext;
		glConvolutionParameteriv (a, b, c);
	}

	static void APIENTRY InitCopyConvolutionFilter1D (GLenum a, GLenum b, GLint c, GLint d, GLsizei e)
	{
		void *ext = (void*)GETPROC ("glCopyConvolutionFilter1D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCopyConvolutionFilter1D = (void (APIENTRY* ) (GLenum, GLenum, GLint, GLint, GLsizei))ext;
		glCopyConvolutionFilter1D (a, b, c, d, e);
	}

	static void APIENTRY InitCopyConvolutionFilter2D (GLenum a, GLenum b, GLint c, GLint d, GLsizei e, GLsizei f)
	{
		void *ext = (void*)GETPROC ("glCopyConvolutionFilter2D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCopyConvolutionFilter2D = (void (APIENTRY* ) (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei))ext;
		glCopyConvolutionFilter2D (a, b, c, d, e, f);
	}

	static void APIENTRY InitGetConvolutionFilter (GLenum a, GLenum b, GLenum c, GLvoid *d)
	{
		void *ext = (void*)GETPROC ("glGetConvolutionFilter");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetConvolutionFilter = (void (APIENTRY* ) (GLenum, GLenum, GLenum, GLvoid *))ext;
		glGetConvolutionFilter (a, b, c, d);
	}

	static void APIENTRY InitGetConvolutionParameterfv (GLenum a, GLenum b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetConvolutionParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetConvolutionParameterfv = (void (APIENTRY* ) (GLenum, GLenum, GLfloat *))ext;
		glGetConvolutionParameterfv (a, b, c);
	}

	static void APIENTRY InitGetConvolutionParameteriv (GLenum a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetConvolutionParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetConvolutionParameteriv = (void (APIENTRY* ) (GLenum, GLenum, GLint *))ext;
		glGetConvolutionParameteriv (a, b, c);
	}

	static void APIENTRY InitGetSeparableFilter (GLenum a, GLenum b, GLenum c, GLvoid *d, GLvoid *e, GLvoid *f)
	{
		void *ext = (void*)GETPROC ("glGetSeparableFilter");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetSeparableFilter = (void (APIENTRY* ) (GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *))ext;
		glGetSeparableFilter (a, b, c, d, e, f);
	}

	static void APIENTRY InitSeparableFilter2D (GLenum a, GLenum b, GLsizei c, GLsizei d, GLenum e, GLenum f, const GLvoid *g, const GLvoid *h)
	{
		void *ext = (void*)GETPROC ("glSeparableFilter2D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSeparableFilter2D = (void (APIENTRY* ) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *))ext;
		glSeparableFilter2D (a, b, c, d, e, f, g, h);
	}

	static void APIENTRY InitGetHistogram (GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e)
	{
		void *ext = (void*)GETPROC ("glGetHistogram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetHistogram = (void (APIENTRY* ) (GLenum, GLboolean, GLenum, GLenum, GLvoid *))ext;
		glGetHistogram (a, b, c, d, e);
	}

	static void APIENTRY InitGetHistogramParameterfv (GLenum a, GLenum b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetHistogramParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetHistogramParameterfv = (void (APIENTRY* ) (GLenum, GLenum, GLfloat *))ext;
		glGetHistogramParameterfv (a, b, c);
	}

	static void APIENTRY InitGetHistogramParameteriv (GLenum a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetHistogramParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetHistogramParameteriv = (void (APIENTRY* ) (GLenum, GLenum, GLint *))ext;
		glGetHistogramParameteriv (a, b, c);
	}

	static void APIENTRY InitGetMinmax (GLenum a, GLboolean b, GLenum c, GLenum d, GLvoid *e)
	{
		void *ext = (void*)GETPROC ("glGetMinmax");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetMinmax = (void (APIENTRY* ) (GLenum, GLboolean, GLenum, GLenum, GLvoid *))ext;
		glGetMinmax (a, b, c, d, e);
	}

	static void APIENTRY InitGetMinmaxParameterfv (GLenum a, GLenum b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetMinmaxParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetMinmaxParameterfv = (void (APIENTRY* ) (GLenum, GLenum, GLfloat *))ext;
		glGetMinmaxParameterfv (a, b, c);
	}

	static void APIENTRY InitGetMinmaxParameteriv (GLenum a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetMinmaxParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetMinmaxParameteriv = (void (APIENTRY* ) (GLenum, GLenum, GLint *))ext;
		glGetMinmaxParameteriv (a, b, c);
	}

	static void APIENTRY InitHistogram (GLenum a, GLsizei b, GLenum c, GLboolean d)
	{
		void *ext = (void*)GETPROC ("glHistogram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glHistogram = (void (APIENTRY* ) (GLenum, GLsizei, GLenum, GLboolean))ext;
		glHistogram (a, b, c, d);
	}

	static void APIENTRY InitMinmax (GLenum a, GLenum b, GLboolean c)
	{
		void *ext = (void*)GETPROC ("glMinmax");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMinmax = (void (APIENTRY* ) (GLenum, GLenum, GLboolean))ext;
		glMinmax (a, b, c);
	}

	static void APIENTRY InitResetHistogram (GLenum a)
	{
		void *ext = (void*)GETPROC ("glResetHistogram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glResetHistogram = (void (APIENTRY* ) (GLenum))ext;
		glResetHistogram (a);
	}

	static void APIENTRY InitResetMinmax (GLenum a)
	{
		void *ext = (void*)GETPROC ("glResetMinmax");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glResetMinmax = (void (APIENTRY* ) (GLenum))ext;
		glResetMinmax (a);
	}

	static void APIENTRY InitTexImage3D (GLenum a, GLint b, GLint c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLenum h, GLenum i, const GLvoid *j)
	{
		void *ext = (void*)GETPROC ("glTexImage3D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glTexImage3D = (void (APIENTRY* ) (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))ext;
		glTexImage3D (a, b, c, d, e, f, g, h, i, j);
	}

	static void APIENTRY InitTexSubImage3D (GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLenum j, const GLvoid *k)
	{
		void *ext = (void*)GETPROC ("glTexSubImage3D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glTexSubImage3D = (void (APIENTRY* ) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))ext;
		glTexSubImage3D (a, b, c, d, e, f, g, h, i, j, k);
	}

	static void APIENTRY InitCopyTexSubImage3D (GLenum a, GLint b, GLint c, GLint d, GLint e, GLint f, GLint g, GLsizei h, GLsizei i)
	{
		void *ext = (void*)GETPROC ("glCopyTexSubImage3D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCopyTexSubImage3D = (void (APIENTRY* ) (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))ext;
		glCopyTexSubImage3D (a, b, c, d, e, f, g, h, i);
	}

	gsext12 _ext12 = 
	{
		InitBlendColor,
		InitBlendEquation,
		InitDrawRangeElements,
		InitColorTable,
		InitColorTableParameterfv,
		InitColorTableParameteriv,
		InitCopyColorTable,
		InitGetColorTable,
		InitGetColorTableParameterfv,
		InitGetColorTableParameteriv,
		InitColorSubTable,
		InitCopyColorSubTable,
		InitConvolutionFilter1D,
		InitConvolutionFilter2D,
		InitConvolutionParameterf,
		InitConvolutionParameterfv,
		InitConvolutionParameteri,
		InitConvolutionParameteriv,
		InitCopyConvolutionFilter1D,
		InitCopyConvolutionFilter2D,
		InitGetConvolutionFilter,
		InitGetConvolutionParameterfv,
		InitGetConvolutionParameteriv,
		InitGetSeparableFilter,
		InitSeparableFilter2D,
		InitGetHistogram,
		InitGetHistogramParameterfv,
		InitGetHistogramParameteriv,
		InitGetMinmax,
		InitGetMinmaxParameterfv,
		InitGetMinmaxParameteriv,
		InitHistogram,
		InitMinmax,
		InitResetHistogram,
		InitResetMinmax,
		InitTexImage3D,
		InitTexSubImage3D,
		InitCopyTexSubImage3D
	};

	static void APIENTRY InitActiveTexture (GLenum a)
	{
		void *ext = (void*)GETPROC ("glActiveTexture");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glActiveTexture = (void (APIENTRY* ) (GLenum))ext;
		glActiveTexture (a);
	}

	static void APIENTRY InitClientActiveTexture (GLenum a)
	{
		void *ext = (void*)GETPROC ("glClientActiveTexture");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glClientActiveTexture = (void (APIENTRY* ) (GLenum))ext;
		glClientActiveTexture (a);
	}

	static void APIENTRY InitMultiTexCoord1d (GLenum a, GLdouble b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1d = (void (APIENTRY* ) (GLenum, GLdouble))ext;
		glMultiTexCoord1d (a, b);
	}

	static void APIENTRY InitMultiTexCoord1dv (GLenum a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1dv = (void (APIENTRY* ) (GLenum, const GLdouble*))ext;
		glMultiTexCoord1dv (a, b);
	}

	static void APIENTRY InitMultiTexCoord1f (GLenum a, GLfloat b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1f = (void (APIENTRY* ) (GLenum, GLfloat))ext;
		glMultiTexCoord1f (a, b);
	}

	static void APIENTRY InitMultiTexCoord1fv (GLenum a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1fv = (void (APIENTRY* ) (GLenum, const GLfloat*))ext;
		glMultiTexCoord1fv (a, b);
	}

	static void APIENTRY InitMultiTexCoord1i (GLenum a, GLint b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1i = (void (APIENTRY* ) (GLenum, GLint))ext;
		glMultiTexCoord1i (a, b);
	}

	static void APIENTRY InitMultiTexCoord1iv (GLenum a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1iv = (void (APIENTRY* ) (GLenum, const GLint *))ext;
		glMultiTexCoord1iv (a, b);
	}

	static void APIENTRY InitMultiTexCoord1s (GLenum a, GLshort b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1s = (void (APIENTRY* ) (GLenum, GLshort))ext;
		glMultiTexCoord1s (a, b);
	}

	static void APIENTRY InitMultiTexCoord1sv (GLenum a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord1sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord1sv = (void (APIENTRY* ) (GLenum, const GLshort *))ext;
		glMultiTexCoord1sv (a, b);
	}

	static void APIENTRY InitMultiTexCoord2d (GLenum a, GLdouble b, GLdouble c)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2d = (void (APIENTRY* ) (GLenum, GLdouble, GLdouble))ext;
		glMultiTexCoord2d (a, b, c);
	}

	static void APIENTRY InitMultiTexCoord2dv (GLenum a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2dv = (void (APIENTRY* ) (GLenum, const GLdouble*))ext;
		glMultiTexCoord2dv (a, b);
	}

	static void APIENTRY InitMultiTexCoord2f (GLenum a, GLfloat b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2f = (void (APIENTRY* ) (GLenum, GLfloat, GLfloat))ext;
		glMultiTexCoord2f (a, b, c);
	}

	static void APIENTRY InitMultiTexCoord2fv (GLenum a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2fv = (void (APIENTRY* ) (GLenum, const GLfloat*))ext;
		glMultiTexCoord2fv (a, b);
	}

	static void APIENTRY InitMultiTexCoord2i (GLenum a, GLint b, GLint c)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2i = (void (APIENTRY* ) (GLenum, GLint, GLint))ext;
		glMultiTexCoord2i (a, b, c);
	}

	static void APIENTRY InitMultiTexCoord2iv (GLenum a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2iv = (void (APIENTRY* ) (GLenum, const GLint *))ext;
		glMultiTexCoord2iv (a, b);
	}

	static void APIENTRY InitMultiTexCoord2s (GLenum a, GLshort b, GLshort c)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2s = (void (APIENTRY* ) (GLenum, GLshort, GLshort))ext;
		glMultiTexCoord2s (a, b, c);
	}

	static void APIENTRY InitMultiTexCoord2sv (GLenum a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord2sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord2sv = (void (APIENTRY* ) (GLenum, const GLshort*))ext;
		glMultiTexCoord2sv (a, b);
	}

	static void APIENTRY InitMultiTexCoord3d (GLenum a, GLdouble b, GLdouble c, GLdouble d)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3d = (void (APIENTRY* ) (GLenum, GLdouble, GLdouble, GLdouble))ext;
		glMultiTexCoord3d (a, b, c, d);
	}

	static void APIENTRY InitMultiTexCoord3dv (GLenum a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3dv = (void (APIENTRY* ) (GLenum, const GLdouble*))ext;
		glMultiTexCoord3dv (a, b);
	}

	static void APIENTRY InitMultiTexCoord3f (GLenum a, GLfloat b, GLfloat c, GLfloat d)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3f = (void (APIENTRY* ) (GLenum, GLfloat, GLfloat, GLfloat))ext;
		glMultiTexCoord3f (a, b, c, d);
	}

	static void APIENTRY InitMultiTexCoord3fv (GLenum a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3fv = (void (APIENTRY* ) (GLenum, const GLfloat*))ext;
		glMultiTexCoord3fv (a, b);
	}

	static void APIENTRY InitMultiTexCoord3i (GLenum a, GLint b, GLint c, GLint d)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3i = (void (APIENTRY* ) (GLenum, GLint, GLint, GLint))ext;
		glMultiTexCoord3i (a, b, c, d);
	}

	static void APIENTRY InitMultiTexCoord3iv (GLenum a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3iv = (void (APIENTRY* ) (GLenum, const GLint*))ext;
		glMultiTexCoord3iv (a, b);
	}

	static void APIENTRY InitMultiTexCoord3s (GLenum a, GLshort b, GLshort c, GLshort d)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3s = (void (APIENTRY* ) (GLenum, GLshort, GLshort, GLshort))ext;
		glMultiTexCoord3s (a, b, c, d);
	}

	static void APIENTRY InitMultiTexCoord3sv (GLenum a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord3sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord3sv = (void (APIENTRY* ) (GLenum, const GLshort*))ext;
		glMultiTexCoord3sv (a, b);
	}

	static void APIENTRY InitMultiTexCoord4d (GLenum a, GLdouble b, GLdouble c, GLdouble d, GLdouble e)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4d = (void (APIENTRY* ) (GLenum, GLdouble, GLdouble, GLdouble, GLdouble))ext;
		glMultiTexCoord4d (a, b, c, d, e);
	}

	static void APIENTRY InitMultiTexCoord4dv (GLenum a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4dv = (void (APIENTRY* ) (GLenum, const GLdouble*))ext;
		glMultiTexCoord4dv (a, b);
	}

	static void APIENTRY InitMultiTexCoord4f (GLenum a, GLfloat b, GLfloat c, GLfloat d, GLfloat e)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4f = (void (APIENTRY* ) (GLenum, GLfloat, GLfloat, GLfloat, GLfloat))ext;
		glMultiTexCoord4f (a, b, c, d, e);
	}

	static void APIENTRY InitMultiTexCoord4fv (GLenum a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4fv = (void (APIENTRY* ) (GLenum, const GLfloat*))ext;
		glMultiTexCoord4fv (a, b);
	}

	static void APIENTRY InitMultiTexCoord4i (GLenum a, GLint b, GLint c, GLint d, GLint e)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4i = (void (APIENTRY* ) (GLenum, GLint, GLint, GLint, GLint))ext;
		glMultiTexCoord4i (a, b, c, d, e);
	}

	static void APIENTRY InitMultiTexCoord4iv (GLenum a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4iv = (void (APIENTRY* ) (GLenum, const GLint *))ext;
		glMultiTexCoord4iv (a, b);
	}

	static void APIENTRY InitMultiTexCoord4s (GLenum a, GLshort b, GLshort c, GLshort d, GLshort e)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4s = (void (APIENTRY* ) (GLenum, GLshort, GLshort, GLshort, GLshort))ext;
		glMultiTexCoord4s (a, b, c, d, e);
	}

	static void APIENTRY InitMultiTexCoord4sv (GLenum a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glMultiTexCoord4sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiTexCoord4sv = (void (APIENTRY* ) (GLenum, const GLshort*))ext;
		glMultiTexCoord4sv (a, b);
	}

	static void APIENTRY InitLoadTransposeMatrixf (const GLfloat *a)
	{
		void *ext = (void*)GETPROC ("glLoadTransposeMatrixf");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glLoadTransposeMatrixf = (void (APIENTRY* ) (const GLfloat*))ext;
		glLoadTransposeMatrixf (a);
	}

	static void APIENTRY InitLoadTransposeMatrixd (const GLdouble *a)
	{
		void *ext = (void*)GETPROC ("glLoadTransposeMatrixd");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glLoadTransposeMatrixd = (void (APIENTRY* ) (const GLdouble*))ext;
		glLoadTransposeMatrixd (a);
	}

	static void APIENTRY InitMultTransposeMatrixf (const GLfloat *a)
	{
		void *ext = (void*)GETPROC ("glMultTransposeMatrixf");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultTransposeMatrixf = (void (APIENTRY* ) (const GLfloat*))ext;
		glMultTransposeMatrixf (a);
	}

	static void APIENTRY InitMultTransposeMatrixd (const GLdouble *a)
	{
		void *ext = (void*)GETPROC ("glMultTransposeMatrixd");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultTransposeMatrixd = (void (APIENTRY* ) (const GLdouble*))ext;
		glMultTransposeMatrixd (a);
	}

	static void APIENTRY InitSampleCoverage (GLclampf a, GLboolean b)
	{
		void *ext = (void*)GETPROC ("glSampleCoverage");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSampleCoverage = (void (APIENTRY* ) (GLclampf, GLboolean))ext;
		glSampleCoverage (a, b);
	}

	static void APIENTRY InitCompressedTexImage3D (GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLsizei f, GLint g, GLsizei h, const GLvoid *i)
	{
		void *ext = (void*)GETPROC ("glCompressedTexImage3D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompressedTexImage3D = (void (APIENTRY* ) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*))ext;
		glCompressedTexImage3D (a, b, c, d, e, f, g, h, i);
	}

	static void APIENTRY InitCompressedTexImage2D (GLenum a, GLint b, GLenum c, GLsizei d, GLsizei e, GLint f, GLsizei g, const GLvoid *h)
	{
		void *ext = (void*)GETPROC ("glCompressedTexImage2D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompressedTexImage2D = (void (APIENTRY* ) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*))ext;
		glCompressedTexImage2D (a, b, c, d, e, f, g, h);
	}

	static void APIENTRY InitCompressedTexImage1D (GLenum a, GLint b, GLenum c, GLsizei d, GLint e, GLsizei f, const GLvoid *g)
	{
		void *ext = (void*)GETPROC ("glCompressedTexImage1D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompressedTexImage1D = (void (APIENTRY* ) (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid*))ext;
		glCompressedTexImage1D (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitCompressedTexSubImage3D (GLenum a, GLint b, GLint c, GLint d, GLint e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLsizei j, const GLvoid *k)
	{
		void *ext = (void*)GETPROC ("glCompressedTexSubImage3D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompressedTexSubImage3D = (void (APIENTRY* ) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*))ext;
		glCompressedTexSubImage3D (a, b, c, d, e, f, g, h, i, j, k);
	}

	static void APIENTRY InitCompressedTexSubImage2D (GLenum a, GLint b, GLint c, GLint d, GLsizei e, GLsizei f, GLenum g, GLsizei h, const GLvoid *i)
	{
		void *ext = (void*)GETPROC ("glCompressedTexSubImage2D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompressedTexSubImage2D = (void (APIENTRY* ) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*))ext;
		glCompressedTexSubImage2D (a, b, c, d, e, f, g, h, i);
	}

	static void APIENTRY InitCompressedTexSubImage1D (GLenum a, GLint b, GLint c, GLsizei d, GLenum e, GLsizei f, const GLvoid *g)
	{
		void *ext = (void*)GETPROC ("glCompressedTexSubImage1D");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompressedTexSubImage1D = (void (APIENTRY* ) (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid*))ext;
		glCompressedTexSubImage1D (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitGetCompressedTexImage (GLenum a, GLint b, GLvoid *c)
	{
		void *ext = (void*)GETPROC ("glGetCompressedTexImage");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetCompressedTexImage = (void (APIENTRY* ) (GLenum, GLint, GLvoid*))ext;
		glGetCompressedTexImage (a, b, c);
	}

	gsext13 _ext13 =
	{
		InitActiveTexture,
		InitClientActiveTexture,
		InitMultiTexCoord1d,
		InitMultiTexCoord1dv,
		InitMultiTexCoord1f,
		InitMultiTexCoord1fv,
		InitMultiTexCoord1i,
		InitMultiTexCoord1iv,
		InitMultiTexCoord1s,
		InitMultiTexCoord1sv,
		InitMultiTexCoord2d,
		InitMultiTexCoord2dv,
		InitMultiTexCoord2f,
		InitMultiTexCoord2fv,
		InitMultiTexCoord2i,
		InitMultiTexCoord2iv,
		InitMultiTexCoord2s,
		InitMultiTexCoord2sv,
		InitMultiTexCoord3d,
		InitMultiTexCoord3dv,
		InitMultiTexCoord3f,
		InitMultiTexCoord3fv,
		InitMultiTexCoord3i,
		InitMultiTexCoord3iv,
		InitMultiTexCoord3s,
		InitMultiTexCoord3sv,
		InitMultiTexCoord4d,
		InitMultiTexCoord4dv,
		InitMultiTexCoord4f,
		InitMultiTexCoord4fv,
		InitMultiTexCoord4i,
		InitMultiTexCoord4iv,
		InitMultiTexCoord4s,
		InitMultiTexCoord4sv,
		InitLoadTransposeMatrixf,
		InitLoadTransposeMatrixd,
		InitMultTransposeMatrixf,
		InitMultTransposeMatrixd,
		InitSampleCoverage,
		InitCompressedTexImage3D,
		InitCompressedTexImage2D,
		InitCompressedTexImage1D,
		InitCompressedTexSubImage3D,
		InitCompressedTexSubImage2D,
		InitCompressedTexSubImage1D,
		InitGetCompressedTexImage
	};

	static void APIENTRY InitBlendFuncSeparate (GLenum a, GLenum b, GLenum c, GLenum d)
	{
		void *ext = (void*)GETPROC ("glBlendFuncSeparate");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBlendFuncSeparate = (void (APIENTRY* ) (GLenum, GLenum, GLenum, GLenum))ext;
		glBlendFuncSeparate (a, b, c, d);
	}

	static void APIENTRY InitFogCoordf (GLfloat a)
	{
		void *ext = (void*)GETPROC ("glFogCoordf");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glFogCoordf = (void (APIENTRY* ) (GLfloat))ext;
		glFogCoordf (a);
	}

	static void APIENTRY InitFogCoordfv (const GLfloat *a)
	{
		void *ext = (void*)GETPROC ("glFogCoordfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glFogCoordfv = (void (APIENTRY* ) (const GLfloat*))ext;
		glFogCoordfv (a);
	}

	static void APIENTRY InitFogCoordd (GLdouble a)
	{
		void *ext = (void*)GETPROC ("glFogCoordd");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glFogCoordd = (void (APIENTRY* ) (GLdouble))ext;
		glFogCoordd (a);
	}

	static void APIENTRY InitFogCoorddv (const GLdouble *a)
	{
		void *ext = (void*)GETPROC ("glFogCoorddv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glFogCoorddv = (void (APIENTRY* ) (const GLdouble *))ext;
		glFogCoorddv (a);
	}

	static void APIENTRY InitFogCoordPointer (GLenum a, GLsizei b, const GLvoid *c)
	{
		void *ext = (void*)GETPROC ("glFogCoordPointer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glFogCoordPointer = (void (APIENTRY* ) (GLenum, GLsizei, const GLvoid*))ext;
		glFogCoordPointer (a, b, c);
	}

	static void APIENTRY InitMultiDrawArrays (GLenum a, GLint *b, GLsizei *c, GLsizei d)
	{
		void *ext = (void*)GETPROC ("glMultiDrawArrays");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiDrawArrays = (void (APIENTRY* ) (GLenum, GLint*, GLsizei*, GLsizei))ext;
		glMultiDrawArrays (a, b, c, d);
	}

	static void APIENTRY InitMultiDrawElements (GLenum a, const GLsizei *b, GLenum c, const GLvoid* *d, GLsizei e)
	{
		void *ext = (void*)GETPROC ("glMultiDrawElements");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glMultiDrawElements = (void (APIENTRY* ) (GLenum, const GLsizei*, GLenum, const GLvoid**, GLsizei))ext;
		glMultiDrawElements (a, b, c, d, e);
	}

	static void APIENTRY InitPointParameterf (GLenum a, GLfloat b)
	{
		void *ext = (void*)GETPROC ("glPointParameterf");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glPointParameterf = (void (APIENTRY* ) (GLenum, GLfloat))ext;
		glPointParameterf (a, b);
	}

	static void APIENTRY InitPointParameterfv (GLenum a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glPointParameterfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glPointParameterfv = (void (APIENTRY* ) (GLenum, const GLfloat*))ext;
		glPointParameterfv (a, b);
	}

	static void APIENTRY InitPointParameteri (GLenum a, GLint b)
	{
		void *ext = (void*)GETPROC ("glPointParameteri");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glPointParameteri = (void (APIENTRY* ) (GLenum, GLint))ext;
		glPointParameteri (a, b);
	}

	static void APIENTRY InitPointParameteriv (GLenum a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glPointParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glPointParameteriv = (void (APIENTRY* ) (GLenum, const GLint*))ext;
		glPointParameteriv (a, b);
	}

	static void APIENTRY InitSecondaryColor3b (GLbyte a, GLbyte b, GLbyte c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3b");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3b = (void (APIENTRY* ) (GLbyte, GLbyte, GLbyte))ext;
		glSecondaryColor3b (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3bv (const GLbyte *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3bv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3bv = (void (APIENTRY* ) (const GLbyte*))ext;
		glSecondaryColor3bv (a);
	}

	static void APIENTRY InitSecondaryColor3d (GLdouble a, GLdouble b, GLdouble c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3d = (void (APIENTRY* ) (GLdouble, GLdouble, GLdouble))ext;
		glSecondaryColor3d (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3dv (const GLdouble *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3dv = (void (APIENTRY* ) (const GLdouble*))ext;
		glSecondaryColor3dv (a);
	}

	static void APIENTRY InitSecondaryColor3f (GLfloat a, GLfloat b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3f = (void (APIENTRY* ) (GLfloat, GLfloat, GLfloat))ext;
		glSecondaryColor3f (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3fv (const GLfloat *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3fv = (void (APIENTRY* ) (const GLfloat*))ext;
		glSecondaryColor3fv (a);
	}

	static void APIENTRY InitSecondaryColor3i (GLint a, GLint b, GLint c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3i = (void (APIENTRY* ) (GLint, GLint, GLint))ext;
		glSecondaryColor3i (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3iv (const GLint *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3iv = (void (APIENTRY* ) (const GLint*))ext;
		glSecondaryColor3iv (a);
	}

	static void APIENTRY InitSecondaryColor3s (GLshort a, GLshort b, GLshort c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3s = (void (APIENTRY* ) (GLshort, GLshort, GLshort))ext;
		glSecondaryColor3s (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3sv (const GLshort *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3sv = (void (APIENTRY* ) (const GLshort*))ext;
		glSecondaryColor3sv (a);
	}

	static void APIENTRY InitSecondaryColor3ub (GLubyte a, GLubyte b, GLubyte c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3ub");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3ub = (void (APIENTRY* ) (GLubyte, GLubyte, GLubyte))ext;
		glSecondaryColor3ub (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3ubv (const GLubyte *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3ubv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3ubv = (void (APIENTRY* ) (const GLubyte*))ext;
		glSecondaryColor3ubv (a);
	}

	static void APIENTRY InitSecondaryColor3ui (GLuint a, GLuint b, GLuint c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3ui");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3ui = (void (APIENTRY* ) (GLuint, GLuint, GLuint))ext;
		glSecondaryColor3ui (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3uiv (const GLuint *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3uiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3uiv = (void (APIENTRY* ) (const GLuint *))ext;
		glSecondaryColor3uiv (a);
	}

	static void APIENTRY InitSecondaryColor3us (GLushort a, GLushort b, GLushort c)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3us");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3us = (void (APIENTRY* ) (GLushort, GLushort, GLushort))ext;
		glSecondaryColor3us (a, b, c);
	}

	static void APIENTRY InitSecondaryColor3usv (const GLushort *a)
	{
		void *ext = (void*)GETPROC ("glSecondaryColor3usv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColor3usv = (void (APIENTRY* ) (const GLushort *))ext;
		glSecondaryColor3usv (a);
	}

	static void APIENTRY InitSecondaryColorPointer (GLint a, GLenum b, GLsizei c, const GLvoid *d)
	{
		void *ext = (void*)GETPROC ("glSecondaryColorPointer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glSecondaryColorPointer = (void (APIENTRY* ) (GLint, GLenum, GLsizei, const GLvoid*))ext;
		glSecondaryColorPointer (a, b, c, d);
	}

	static void APIENTRY InitWindowPos2d (GLdouble a, GLdouble b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2d = (void (APIENTRY* ) (GLdouble, GLdouble))ext;
		glWindowPos2d (a, b);
	}

	static void APIENTRY InitWindowPos2dv (const GLdouble *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2dv = (void (APIENTRY* ) (const GLdouble *))ext;
		glWindowPos2dv (a);
	}

	static void APIENTRY InitWindowPos2f (GLfloat a, GLfloat b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2f = (void (APIENTRY* ) (GLfloat, GLfloat))ext;
		glWindowPos2f (a, b);
	}

	static void APIENTRY InitWindowPos2fv (const GLfloat *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2fv = (void (APIENTRY* ) (const GLfloat *))ext;
		glWindowPos2fv (a);
	}

	static void APIENTRY InitWindowPos2i (GLint a, GLint b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2i = (void (APIENTRY* ) (GLint, GLint))ext;
		glWindowPos2i (a, b);
	}

	static void APIENTRY InitWindowPos2iv (const GLint *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2iv = (void (APIENTRY* ) (const GLint *))ext;
		glWindowPos2iv (a);
	}

	static void APIENTRY InitWindowPos2s (GLshort a, GLshort b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2s = (void (APIENTRY* ) (GLshort, GLshort))ext;
		glWindowPos2s (a, b);
	}

	static void APIENTRY InitWindowPos2sv (const GLshort *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos2sv = (void (APIENTRY* ) (const GLshort *))ext;
		glWindowPos2sv (a);
	}

	static void APIENTRY InitWindowPos3d (GLdouble a, GLdouble b, GLdouble c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3d = (void (APIENTRY* ) (GLdouble, GLdouble, GLdouble))ext;
		glWindowPos3d (a, b, c);
	}

	static void APIENTRY InitWindowPos3dv (const GLdouble *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3dv = (void (APIENTRY* ) (const GLdouble *))ext;
		glWindowPos3dv (a);
	}

	static void APIENTRY InitWindowPos3f (GLfloat a, GLfloat b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3f = (void (APIENTRY* ) (GLfloat, GLfloat, GLfloat))ext;
		glWindowPos3f (a, b, c);
	}

	static void APIENTRY InitWindowPos3fv (const GLfloat *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3fv = (void (APIENTRY* ) (const GLfloat *))ext;
		glWindowPos3fv (a);
	}

	static void APIENTRY InitWindowPos3i (GLint a, GLint b, GLint c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3i = (void (APIENTRY* ) (GLint, GLint, GLint))ext;
		glWindowPos3i (a, b, c);
	}

	static void APIENTRY InitWindowPos3iv (const GLint *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3iv = (void (APIENTRY* ) (const GLint*))ext;
		glWindowPos3iv (a);
	}

	static void APIENTRY InitWindowPos3s (GLshort a, GLshort b, GLshort c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3s = (void (APIENTRY* ) (GLshort, GLshort, GLshort))ext;
		glWindowPos3s (a, b, c);
	}

	static void APIENTRY InitWindowPos3sv (const GLshort *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glWindowPos3sv = (void (APIENTRY* ) (const GLshort *))ext;
		glWindowPos3sv (a);
	}

	gsext14 _ext14 = 
	{
		InitBlendFuncSeparate,
		InitFogCoordf,
		InitFogCoordfv,
		InitFogCoordd,
		InitFogCoorddv,
		InitFogCoordPointer,
		InitMultiDrawArrays,
		InitMultiDrawElements,
		InitPointParameterf,
		InitPointParameterfv,
		InitPointParameteri,
		InitPointParameteriv,
		InitSecondaryColor3b,
		InitSecondaryColor3bv,
		InitSecondaryColor3d,
		InitSecondaryColor3dv,
		InitSecondaryColor3f,
		InitSecondaryColor3fv,
		InitSecondaryColor3i,
		InitSecondaryColor3iv,
		InitSecondaryColor3s,
		InitSecondaryColor3sv,
		InitSecondaryColor3ub,
		InitSecondaryColor3ubv,
		InitSecondaryColor3ui,
		InitSecondaryColor3uiv,
		InitSecondaryColor3us,
		InitSecondaryColor3usv,
		InitSecondaryColorPointer,
		InitWindowPos2d,
		InitWindowPos2dv,
		InitWindowPos2f,
		InitWindowPos2fv,
		InitWindowPos2i,
		InitWindowPos2iv,
		InitWindowPos2s,
		InitWindowPos2sv,
		InitWindowPos3d,
		InitWindowPos3dv,
		InitWindowPos3f,
		InitWindowPos3fv,
		InitWindowPos3i,
		InitWindowPos3iv,
		InitWindowPos3s,
		InitWindowPos3sv
	};

	static void APIENTRY InitGenQueries (GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenQueries");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGenQueries = (void (APIENTRY* ) (GLsizei, GLuint*))ext;
		glGenQueries (a, b);
	}

	static void APIENTRY InitDeleteQueries (GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteQueries");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDeleteQueries = (void (APIENTRY* ) (GLsizei, const GLuint *))ext;
		glDeleteQueries (a, b);
	}

	static bool APIENTRY InitIsQuery (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsQuery");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		glIsQuery = (bool (APIENTRY* ) (GLuint))ext;
		return glIsQuery (a);
	}

	static void APIENTRY InitBeginQuery (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBeginQuery");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBeginQuery = (void (APIENTRY* ) (GLenum, GLuint))ext;
		glBeginQuery (a, b);
	}

	static void APIENTRY InitEndQuery (GLenum a)
	{
		void *ext = (void*)GETPROC ("glEndQuery");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glEndQuery = (void (APIENTRY* ) (GLenum))ext;
		glEndQuery (a);
	}

	static void APIENTRY InitGetQueryiv (GLenum a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetQueryiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetQueryiv = (void (APIENTRY* ) (GLenum, GLenum, GLint*))ext;
		glGetQueryiv (a, b, c);
	}

	static void APIENTRY InitGetQueryObjectiv (GLuint a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetQueryObjectiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetQueryObjectiv = (void (APIENTRY* ) (GLuint, GLenum, GLint*))ext;
		glGetQueryObjectiv (a, b, c);
	}

	static void APIENTRY InitGetQueryObjectuiv (GLuint a, GLenum b, GLuint *c)
	{
		void *ext = (void*)GETPROC ("glGetQueryObjectuiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetQueryObjectuiv = (void (APIENTRY* ) (GLuint, GLenum, GLuint*))ext;
		glGetQueryObjectuiv (a, b, c);
	}

	static void APIENTRY InitBindBuffer (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBindBuffer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBindBuffer = (void (APIENTRY* ) (GLenum, GLuint))ext;
		glBindBuffer (a, b);
	}

	static void APIENTRY InitDeleteBuffers (GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteBuffers");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDeleteBuffers = (void (APIENTRY* ) (GLsizei, const GLuint *))ext;
		glDeleteBuffers (a, b);
	}

	static void APIENTRY InitGenBuffers (GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenBuffers");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGenBuffers = (void (APIENTRY* ) (GLsizei, GLuint*))ext;
		glGenBuffers (a, b);
	}

	static bool APIENTRY InitIsBuffer (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsBuffer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		glIsBuffer = (bool (APIENTRY* ) (GLuint))ext;
		return glIsBuffer (a);
	}

	static void APIENTRY InitBufferData (GLenum a, GLsizei* b, const GLvoid *c, GLenum d)
	{
		void *ext = (void*)GETPROC ("glBufferData");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBufferData = (void (APIENTRY* ) (GLenum, GLsizei*, const GLvoid*, GLenum))ext;
		glBufferData (a, b, c, d);
	}

	static void APIENTRY InitBufferSubData (GLenum a, GLint* b, GLsizei* c, const GLvoid *d)
	{
		void *ext = (void*)GETPROC ("glBufferSubData");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBufferSubData = (void (APIENTRY* ) (GLenum, GLint*, GLsizei*, const GLvoid*))ext;
		glBufferSubData (a, b, c, d);
	}

	static void APIENTRY InitGetBufferSubData (GLenum a, GLint* b, GLsizei* c, GLvoid *d)
	{
		void *ext = (void*)GETPROC ("glGetBufferSubData");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetBufferSubData = (void (APIENTRY* ) (GLenum, GLint*, GLsizei*, GLvoid*))ext;
		glGetBufferSubData (a, b, c, d);
	}

	static void* APIENTRY InitMapBuffer (GLenum a, GLenum b)
	{
		void *ext = (void*)GETPROC ("glMapBuffer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return NULL;
		}

		glMapBuffer = (void* (APIENTRY* ) (GLenum, GLenum))ext;
		return glMapBuffer (a, b);
	}

	static bool APIENTRY InitUnmapBuffer (GLenum a)
	{
		void *ext = (void*)GETPROC ("glUnmapBuffer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		glUnmapBuffer = (bool (APIENTRY* ) (GLenum))ext;
		return glUnmapBuffer (a);
	}

	static void APIENTRY InitGetBufferParameteriv (GLenum a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetBufferParameteriv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetBufferParameteriv = (void (APIENTRY* ) (GLenum, GLenum, GLint*))ext;
		glGetBufferParameteriv (a, b, c);
	}

	static void APIENTRY InitGetBufferPointerv (GLenum a, GLenum b, GLvoid* *c)
	{
		void *ext = (void*)GETPROC ("glGetBufferPointerv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetBufferPointerv = (void (APIENTRY* ) (GLenum, GLenum, GLvoid**))ext;
		glGetBufferPointerv (a, b, c);
	}

	gsext15 _ext15 = 
	{
		InitGenQueries,
		InitDeleteQueries,
		InitIsQuery,
		InitBeginQuery,
		InitEndQuery,
		InitGetQueryiv,
		InitGetQueryObjectiv,
		InitGetQueryObjectuiv,
		InitBindBuffer,
		InitDeleteBuffers,
		InitGenBuffers,
		InitIsBuffer,
		InitBufferData,
		InitBufferSubData,
		InitGetBufferSubData,
		InitMapBuffer,
		InitUnmapBuffer,
		InitGetBufferParameteriv,
		InitGetBufferPointerv
	};

	static void APIENTRY InitBlendEquationSeparate (GLenum a, GLenum b)
	{
		void *ext = (void*)GETPROC ("glBlendEquationSeparate");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBlendEquationSeparate = (void (APIENTRY* ) (GLenum, GLenum))ext;
		glBlendEquationSeparate (a, b);
	}

	static void APIENTRY InitDrawBuffers (GLsizei a, const GLenum *b)
	{
		void *ext = (void*)GETPROC ("glDrawBuffers");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDrawBuffers = (void (APIENTRY* ) (GLsizei, const GLenum*))ext;
		glDrawBuffers (a, b);
	}

	static void APIENTRY InitStencilOpSeparate (GLenum a, GLenum b, GLenum c, GLenum d)
	{
		void *ext = (void*)GETPROC ("glStencilOpSeparate");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glStencilOpSeparate = (void (APIENTRY* ) (GLenum, GLenum, GLenum, GLenum))ext;
		glStencilOpSeparate (a, b, c, d);
	}

	static void APIENTRY InitStencilFuncSeparate (GLenum a, GLenum b, GLint c, GLuint d)
	{
		void *ext = (void*)GETPROC ("glStencilFuncSeparate");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glStencilFuncSeparate = (void (APIENTRY* ) (GLenum, GLenum, GLint, GLuint))ext;
		glStencilFuncSeparate (a, b, c, d);
	}

	static void APIENTRY InitStencilMaskSeparate (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glStencilMaskSeparate");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glStencilMaskSeparate = (void (APIENTRY* ) (GLenum, GLuint))ext;
		glStencilMaskSeparate (a, b);
	}

	static void APIENTRY InitAttachShader (GLuint a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glAttachShader");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glAttachShader = (void (APIENTRY* ) (GLuint, GLuint))ext;
		glAttachShader (a, b);
	}

	static void APIENTRY InitBindAttribLocation (GLuint a, GLuint b, const GLchar *c)
	{
		void *ext = (void*)GETPROC ("glBindAttribLocation");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBindAttribLocation = (void (APIENTRY* ) (GLuint, GLuint, const GLchar*))ext;
		glBindAttribLocation (a, b, c);
	}

	static void APIENTRY InitCompileShader (GLuint a)
	{
		void *ext = (void*)GETPROC ("glCompileShader");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompileShader = (void (APIENTRY* ) (GLuint))ext;
		glCompileShader (a);
	}

	static unsigned int APIENTRY InitCreateProgram (void)
	{
		void *ext = (void*)GETPROC ("glCreateProgram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return 0;
		}

		glCreateProgram = (unsigned int (APIENTRY* ) (void))ext;
		return glCreateProgram ();
	}

	static unsigned int APIENTRY InitCreateShader (GLenum a)
	{
		void *ext = (void*)GETPROC ("glCreateShader");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return 0;
		}

		glCreateShader = (unsigned int (APIENTRY* ) (GLenum))ext;
		return glCreateShader (a);
	}

	static void APIENTRY InitDeleteProgram (GLuint a)
	{
		void *ext = (void*)GETPROC ("glDeleteProgram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDeleteProgram = (void (APIENTRY* ) (GLuint))ext;
		glDeleteProgram (a);
	}

	static void APIENTRY InitDeleteShader (GLuint a)
	{
		void *ext = (void*)GETPROC ("glDeleteShader");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDeleteShader = (void (APIENTRY* ) (GLuint))ext;
		glDeleteShader (a);
	}

	static void APIENTRY InitDetachShader (GLuint a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glDetachShader");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDetachShader = (void (APIENTRY* ) (GLuint, GLuint))ext;
		glDetachShader (a, b);
	}

	static void APIENTRY InitDisableVertexAttribArray (GLuint a)
	{
		void *ext = (void*)GETPROC ("glDisableVertexAttribArray");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDisableVertexAttribArray = (void (APIENTRY* ) (GLuint))ext;
		glDisableVertexAttribArray (a);
	}

	static void APIENTRY InitEnableVertexAttribArray (GLuint a)
	{
		void *ext = (void*)GETPROC ("glEnableVertexAttribArray");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glEnableVertexAttribArray = (void (APIENTRY* ) (GLuint))ext;
		glEnableVertexAttribArray (a);
	}

	static void APIENTRY InitGetActiveAttrib (GLuint a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLchar *g)
	{
		void *ext = (void*)GETPROC ("glGetActiveAttrib");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetActiveAttrib = (void (APIENTRY* ) (GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*))ext;
		glGetActiveAttrib (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitGetActiveUniform (GLuint a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLchar *g)
	{
		void *ext = (void*)GETPROC ("glGetActiveUniform");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetActiveUniform = (void (APIENTRY* ) (GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*))ext;
		glGetActiveUniform (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitGetAttachedShaders (GLuint a , GLsizei b, GLsizei *c, GLuint *d)
	{
		void *ext = (void*)GETPROC ("glGetAttachedShaders");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetAttachedShaders = (void (APIENTRY* ) (GLuint, GLsizei, GLsizei*, GLuint*))ext;
		glGetAttachedShaders (a, b, c, d);
	}

	static int APIENTRY InitGetAttribLocation (GLuint a, const GLchar *b)
	{
		void *ext = (void*)GETPROC ("glGetAttribLocation");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return 0;
		}

		glGetAttribLocation = (int (APIENTRY* ) (GLuint, const GLchar *))ext;
		return glGetAttribLocation (a, b);
	}

	static void APIENTRY InitGetProgramiv (GLuint a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetProgramiv = (void (APIENTRY* ) (GLuint, GLenum, GLint*))ext;
		glGetProgramiv (a, b, c);
	}

	static void APIENTRY InitGetProgramInfoLog (GLuint a, GLsizei b, GLsizei *c, GLchar *d)
	{
		void *ext = (void*)GETPROC ("glGetProgramInfoLog");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetProgramInfoLog = (void (APIENTRY* ) (GLuint, GLsizei, GLsizei*, GLchar*))ext;
		glGetProgramInfoLog (a, b, c, d);
	}

	static void APIENTRY InitGetShaderiv (GLuint a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetShaderiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetShaderiv = (void (APIENTRY* ) (GLuint, GLenum, GLint*))ext;
		glGetShaderiv (a, b, c);
	}

	static void APIENTRY InitGetShaderInfoLog (GLuint a, GLsizei b, GLsizei *c, GLchar *d)
	{
		void *ext = (void*)GETPROC ("glGetShaderInfoLog");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetShaderInfoLog = (void (APIENTRY* ) (GLuint, GLsizei, GLsizei*, GLchar*))ext;
		glGetShaderInfoLog (a, b, c, d);
	}

	static void APIENTRY InitGetShaderSource (GLuint a, GLsizei b, GLsizei *c, GLchar *d)
	{
		void *ext = (void*)GETPROC ("glGetShaderSource");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetShaderSource = (void (APIENTRY* ) (GLuint, GLsizei, GLsizei*, GLchar*))ext;
		glGetShaderSource (a, b, c, d);
	}

	static int APIENTRY InitGetUniformLocation (GLuint a, const GLchar *b)
	{
		void *ext = (void*)GETPROC ("glGetUniformLocation");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return 0;
		}

		glGetUniformLocation = (int (APIENTRY* ) (GLuint, const GLchar*))ext;
		return glGetUniformLocation (a, b);
	}

	static void APIENTRY InitGetUniformfv (GLuint a, GLint b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetUniformfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetUniformfv = (void (APIENTRY* ) (GLuint, GLint, GLfloat*))ext;
		glGetUniformfv (a, b, c);
	}

	static void APIENTRY InitGetUniformiv (GLuint a, GLint b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetUniformiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetUniformiv = (void (APIENTRY* ) (GLuint, GLint, GLint*))ext;
		glGetUniformiv (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribdv (GLuint a, GLenum b, GLdouble *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribdv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetVertexAttribdv = (void (APIENTRY* ) (GLuint, GLenum, GLdouble*))ext;
		glGetVertexAttribdv (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribfv (GLuint a, GLenum b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribfv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetVertexAttribfv = (void (APIENTRY* ) (GLuint, GLenum, GLfloat*))ext;
		glGetVertexAttribfv (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribiv (GLuint a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetVertexAttribiv = (void (APIENTRY* ) (GLuint, GLenum, GLint*))ext;
		glGetVertexAttribiv (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribPointerv (GLuint a, GLenum b, GLvoid* *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribPointerv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetVertexAttribPointerv = (void (APIENTRY* ) (GLuint, GLenum, GLvoid**))ext;
		glGetVertexAttribPointerv (a, b, c);
	}

	static bool APIENTRY InitIsProgram (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsProgram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		glIsProgram = (bool (APIENTRY* ) (GLuint))ext;
		return glIsProgram (a);
	}

	static bool APIENTRY InitIsShader (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsShader");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		glIsShader = (bool (APIENTRY* ) (GLuint))ext;
		return glIsShader (a);
	}

	static void APIENTRY InitLinkProgram (GLuint a)
	{
		void *ext = (void*)GETPROC ("glLinkProgram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glLinkProgram = (void (APIENTRY* ) (GLuint))ext;
		glLinkProgram (a);
	}

	static void APIENTRY InitShaderSource (GLuint a, GLsizei b, const GLchar* *c, const GLint *d)
	{
		void *ext = (void*)GETPROC ("glShaderSource");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glShaderSource = (void (APIENTRY* ) (GLuint, GLsizei, const GLchar**, const GLint*))ext;
		glShaderSource (a, b, c, d);
	}

	static void APIENTRY InitUseProgram (GLuint a)
	{
		void *ext = (void*)GETPROC ("glUseProgram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUseProgram = (void (APIENTRY* ) (GLuint))ext;
		glUseProgram (a);
	}

	static void APIENTRY InitUniform1f (GLint a, GLfloat b)
	{
		void *ext = (void*)GETPROC ("glUniform1f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1f = (void (APIENTRY* ) (GLint, GLfloat))ext;
		glUniform1f (a, b);
	}

	static void APIENTRY InitUniform2f (GLint a, GLfloat b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glUniform2f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2f = (void (APIENTRY* ) (GLint, GLfloat, GLfloat))ext;
		glUniform2f (a, b, c);
	}

	static void APIENTRY InitUniform3f (GLint a, GLfloat b, GLfloat c, GLfloat d)
	{
		void *ext = (void*)GETPROC ("glUniform3f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3f = (void (APIENTRY* ) (GLint, GLfloat, GLfloat, GLfloat))ext;
		glUniform3f (a, b, c, d);
	}

	static void APIENTRY InitUniform4f (GLint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e)
	{
		void *ext = (void*)GETPROC ("glUniform4f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4f = (void (APIENTRY* ) (GLint, GLfloat, GLfloat, GLfloat, GLfloat))ext;
		glUniform4f (a, b, c, d, e);
	}

	static void APIENTRY InitUniform1i (GLint a, GLint b)
	{
		void *ext = (void*)GETPROC ("glUniform1i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1i = (void (APIENTRY* ) (GLint, GLint))ext;
		glUniform1i (a, b);
	}

	static void APIENTRY InitUniform2i (GLint a, GLint b, GLint c)
	{
		void *ext = (void*)GETPROC ("glUniform2i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2i = (void (APIENTRY* ) (GLint, GLint, GLint))ext;
		glUniform2i (a, b, c);
	}

	static void APIENTRY InitUniform3i (GLint a, GLint b, GLint c, GLint d)
	{
		void *ext = (void*)GETPROC ("glUniform3i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3i = (void (APIENTRY* ) (GLint, GLint, GLint, GLint))ext;
		glUniform3i (a, b,c, d);
	}

	static void APIENTRY InitUniform4i (GLint a, GLint b, GLint c, GLint d, GLint e)
	{
		void *ext = (void*)GETPROC ("glUniform4i");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4i = (void (APIENTRY* ) (GLint, GLint, GLint, GLint, GLint))ext;
		glUniform4i (a, b, c, d, e);
	}

	static void APIENTRY InitUniform1fv (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform1fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1fv = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform1fv (a, b, c);
	}

	static void APIENTRY InitUniform2fv (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform2fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2fv = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform2fv (a, b, c);
	}

	static void APIENTRY InitUniform3fv (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform3fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3fv = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform3fv (a, b, c);
	}

	static void APIENTRY InitUniform4fv (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform4fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4fv = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform4fv (a, b, c);
	}

	static void APIENTRY InitUniform1iv (GLint a, GLsizei b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glUniform1iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1iv = (void (APIENTRY* ) (GLint, GLsizei, const GLint*))ext;
		glUniform1iv (a, b, c);
	}

	static void APIENTRY InitUniform2iv (GLint a, GLsizei b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glUniform2iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2iv = (void (APIENTRY* ) (GLint, GLsizei, const GLint*))ext;
		glUniform2iv (a, b, c);
	}

	static void APIENTRY InitUniform3iv (GLint a, GLsizei b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glUniform3iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3iv = (void (APIENTRY* ) (GLint, GLsizei, const GLint*))ext;
		glUniform3iv (a, b, c);
	}

	static void APIENTRY InitUniform4iv (GLint a, GLsizei b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glUniform4iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4iv = (void (APIENTRY* ) (GLint, GLsizei, const GLint*))ext;
		glUniform4iv (a, b, c);
	}

	static void APIENTRY InitUniformMatrix2fv (GLint a, GLsizei b, GLboolean c, const GLfloat *d)
	{
		void *ext = (void*)GETPROC ("glUniformMatrix2fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniformMatrix2fv = (void (APIENTRY* ) (GLint, GLsizei, GLboolean, const GLfloat*))ext;
		glUniformMatrix2fv (a, b, c, d);
	}

	static void APIENTRY InitUniformMatrix3fv (GLint a, GLsizei b, GLboolean c, const GLfloat *d)
	{
		void *ext = (void*)GETPROC ("glUniformMatrix3fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniformMatrix3fv = (void (APIENTRY* ) (GLint, GLsizei, GLboolean, const GLfloat*))ext;
		glUniformMatrix3fv (a, b, c, d);
	}

	static void APIENTRY InitUniformMatrix4fv (GLint a, GLsizei b, GLboolean c, const GLfloat *d)
	{
		void *ext = (void*)GETPROC ("glUniformMatrix4fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniformMatrix4fv = (void (APIENTRY* ) (GLint, GLsizei, GLboolean, const GLfloat*))ext;
		glUniformMatrix4fv (a, b, c, d);
	}

	static void APIENTRY InitValidateProgram (GLuint a)
	{
		void *ext = (void*)GETPROC ("glValidateProgram");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glValidateProgram = (void (APIENTRY* ) (GLuint))ext;
		glValidateProgram (a);
	}

	static void APIENTRY InitVertexAttrib1d (GLuint a, GLdouble b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib1d = (void (APIENTRY* ) (GLuint, GLdouble))ext;
		glVertexAttrib1d (a, b);
	}

	static void APIENTRY InitVertexAttrib1dv (GLuint a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib1dv = (void (APIENTRY* ) (GLuint, const GLdouble*))ext;
		glVertexAttrib1dv (a, b);
	}

	static void APIENTRY InitVertexAttrib1f (GLuint a, GLfloat b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib1f = (void (APIENTRY* ) (GLuint, GLfloat))ext;
		glVertexAttrib1f (a, b);
	}

	static void APIENTRY InitVertexAttrib1fv (GLuint a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib1fv = (void (APIENTRY* ) (GLuint, const GLfloat*))ext;
		glVertexAttrib1fv (a, b);
	}

	static void APIENTRY InitVertexAttrib1s (GLuint a, GLshort b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib1s = (void (APIENTRY* ) (GLuint, GLshort))ext;
		glVertexAttrib1s (a, b);
	}

	static void APIENTRY InitVertexAttrib1sv (GLuint a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib1sv = (void (APIENTRY* ) (GLuint, const GLshort*))ext;
		glVertexAttrib1sv (a, b);
	}

	static void APIENTRY InitVertexAttrib2d (GLuint a, GLdouble b, GLdouble c)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib2d = (void (APIENTRY* ) (GLuint, GLdouble, GLdouble))ext;
		glVertexAttrib2d (a, b, c);
	}

	static void APIENTRY InitVertexAttrib2dv (GLuint a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib2dv = (void (APIENTRY* ) (GLuint, const GLdouble*))ext;
		glVertexAttrib2dv (a, b);
	}

	static void APIENTRY InitVertexAttrib2f (GLuint a, GLfloat b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib2f = (void (APIENTRY* ) (GLuint, GLfloat, GLfloat))ext;
		glVertexAttrib2f (a, b, c);
	}

	static void APIENTRY InitVertexAttrib2fv (GLuint a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib2fv = (void (APIENTRY* ) (GLuint, const GLfloat*))ext;
		glVertexAttrib2fv (a, b);
	}

	static void APIENTRY InitVertexAttrib2s (GLuint a, GLshort b, GLshort c)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib2s = (void (APIENTRY* ) (GLuint, GLshort, GLshort))ext;
		glVertexAttrib2s (a, b, c);
	}

	static void APIENTRY InitVertexAttrib2sv (GLuint a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib2sv = (void (APIENTRY* ) (GLuint, const GLshort*))ext;
		glVertexAttrib2sv (a, b);
	}

	static void APIENTRY InitVertexAttrib3d (GLuint a, GLdouble b, GLdouble c, GLdouble d)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib3d = (void (APIENTRY* ) (GLuint, GLdouble, GLdouble, GLdouble))ext;
		glVertexAttrib3d (a, b, c, d);
	}

	static void APIENTRY InitVertexAttrib3dv (GLuint a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib3dv = (void (APIENTRY* ) (GLuint, const GLdouble*))ext;
		glVertexAttrib3dv (a, b);
	}

	static void APIENTRY InitVertexAttrib3f (GLuint a, GLfloat b, GLfloat c, GLfloat d)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib3f = (void (APIENTRY* ) (GLuint, GLfloat, GLfloat, GLfloat))ext;
		glVertexAttrib3f (a, b, c, d);
	}

	static void APIENTRY InitVertexAttrib3fv (GLuint a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib3fv = (void (APIENTRY* ) (GLuint, const GLfloat*))ext;
		glVertexAttrib3fv (a, b);
	}

	static void APIENTRY InitVertexAttrib3s (GLuint a, GLshort b, GLshort c, GLshort d)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib3s = (void (APIENTRY* ) (GLuint, GLshort, GLshort, GLshort))ext;
		glVertexAttrib3s (a, b, c, d);
	}

	static void APIENTRY InitVertexAttrib3sv (GLuint a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib3sv = (void (APIENTRY* ) (GLuint, const GLshort*))ext;
		glVertexAttrib3sv (a, b);
	}

	static void APIENTRY InitVertexAttrib4Nbv (GLuint a, const GLbyte *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Nbv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Nbv = (void (APIENTRY* ) (GLuint, const GLbyte*))ext;
		glVertexAttrib4Nbv (a, b);
	}

	static void APIENTRY InitVertexAttrib4Niv (GLuint a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Niv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Niv = (void (APIENTRY* ) (GLuint, const GLint*))ext;
		glVertexAttrib4Niv (a, b);
	}

	static void APIENTRY InitVertexAttrib4Nsv (GLuint a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Nsv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Nsv = (void (APIENTRY* ) (GLuint, const GLshort*))ext;
		glVertexAttrib4Nsv (a, b);
	}

	static void APIENTRY InitVertexAttrib4Nub (GLuint a, GLubyte b, GLubyte c, GLubyte d, GLubyte e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Nub");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Nub = (void (APIENTRY* ) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte))ext;
		glVertexAttrib4Nub (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4Nubv (GLuint a, const GLubyte *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Nubv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Nubv = (void (APIENTRY* ) (GLuint, const GLubyte*))ext;
		glVertexAttrib4Nubv (a, b);
	}

	static void APIENTRY InitVertexAttrib4Nuiv (GLuint a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Nuiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Nuiv = (void (APIENTRY* ) (GLuint, const GLuint*))ext;
		glVertexAttrib4Nuiv (a, b);
	}

	static void APIENTRY InitVertexAttrib4Nusv (GLuint a, const GLushort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4Nusv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4Nusv = (void (APIENTRY* ) (GLuint, const GLushort*))ext;
		glVertexAttrib4Nusv (a, b);
	}

	static void APIENTRY InitVertexAttrib4bv (GLuint a, const GLbyte *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4bv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4bv = (void (APIENTRY* ) (GLuint, const GLbyte*))ext;
		glVertexAttrib4bv (a, b);
	}

	static void APIENTRY InitVertexAttrib4d (GLuint a, GLdouble b, GLdouble c, GLdouble d, GLdouble e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4d");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4d = (void (APIENTRY* ) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble))ext;
		glVertexAttrib4d (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4dv (GLuint a, const GLdouble *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4dv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4dv = (void (APIENTRY* ) (GLuint, const GLdouble*))ext;
		glVertexAttrib4dv (a, b);
	}

	static void APIENTRY InitVertexAttrib4f (GLuint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4f");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4f = (void (APIENTRY* ) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat))ext;
		glVertexAttrib4f (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4fv (GLuint a, const GLfloat *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4fv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4fv = (void (APIENTRY* ) (GLuint, const GLfloat*))ext;
		glVertexAttrib4fv (a, b);
	}

	static void APIENTRY InitVertexAttrib4iv (GLuint a, const GLint *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4iv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4iv = (void (APIENTRY* ) (GLuint, const GLint*))ext;
		glVertexAttrib4iv (a, b);
	}

	static void APIENTRY InitVertexAttrib4s (GLuint a, GLshort b, GLshort c, GLshort d, GLshort e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4s");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4s = (void (APIENTRY* ) (GLuint, GLshort, GLshort, GLshort, GLshort))ext;
		glVertexAttrib4s (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4sv (GLuint a, const GLshort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4sv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4sv = (void (APIENTRY* ) (GLuint, const GLshort*))ext;
		glVertexAttrib4sv (a, b);
	}

	static void APIENTRY InitVertexAttrib4ubv (GLuint a, const GLubyte *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4ubv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4ubv = (void (APIENTRY* ) (GLuint, const GLubyte*))ext;
		glVertexAttrib4ubv (a, b);
	}

	static void APIENTRY InitVertexAttrib4uiv (GLuint a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4uiv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4uiv = (void (APIENTRY* ) (GLuint, const GLuint*))ext;
		glVertexAttrib4uiv (a, b);
	}

	static void APIENTRY InitVertexAttrib4usv (GLuint a, const GLushort *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4usv");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttrib4usv = (void (APIENTRY* ) (GLuint, const GLushort*))ext;
		glVertexAttrib4usv (a, b);
	}

	static void APIENTRY InitVertexAttribPointer (GLuint a, GLint b, GLenum c, GLboolean d, GLsizei e, const GLvoid *f)
	{
		void *ext = (void*)GETPROC ("glVertexAttribPointer");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glVertexAttribPointer = (void (APIENTRY* ) (GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*))ext;
		glVertexAttribPointer (a, b, c, d, e, f);
	}

	gsext20 _ext20 =
	{
		InitBlendEquationSeparate,
		InitDrawBuffers,
		InitStencilOpSeparate,
		InitStencilFuncSeparate,
		InitStencilMaskSeparate,
		InitAttachShader,
		InitBindAttribLocation,
		InitCompileShader,
		InitCreateProgram,
		InitCreateShader,
		InitDeleteProgram,
		InitDeleteShader,
		InitDetachShader,
		InitDisableVertexAttribArray,
		InitEnableVertexAttribArray,
		InitGetActiveAttrib,
		InitGetActiveUniform,
		InitGetAttachedShaders,
		InitGetAttribLocation,
		InitGetProgramiv,
		InitGetProgramInfoLog,
		InitGetShaderiv,
		InitGetShaderInfoLog,
		InitGetShaderSource,
		InitGetUniformLocation,
		InitGetUniformfv,
		InitGetUniformiv,
		InitGetVertexAttribdv,
		InitGetVertexAttribfv,
		InitGetVertexAttribiv,
		InitGetVertexAttribPointerv,
		InitIsProgram,
		InitIsShader,
		InitLinkProgram,
		InitShaderSource,
		InitUseProgram,
		InitUniform1f,
		InitUniform2f,
		InitUniform3f,
		InitUniform4f,
		InitUniform1i,
		InitUniform2i,
		InitUniform3i,
		InitUniform4i,
		InitUniform1fv,
		InitUniform2fv,
		InitUniform3fv,
		InitUniform4fv,
		InitUniform1iv,
		InitUniform2iv,
		InitUniform3iv,
		InitUniform4iv,
		InitUniformMatrix2fv,
		InitUniformMatrix3fv,
		InitUniformMatrix4fv,
		InitValidateProgram,
		InitVertexAttrib1d,
		InitVertexAttrib1dv,
		InitVertexAttrib1f,
		InitVertexAttrib1fv,
		InitVertexAttrib1s,
		InitVertexAttrib1sv,
		InitVertexAttrib2d,
		InitVertexAttrib2dv,
		InitVertexAttrib2f,
		InitVertexAttrib2fv,
		InitVertexAttrib2s,
		InitVertexAttrib2sv,
		InitVertexAttrib3d,
		InitVertexAttrib3dv,
		InitVertexAttrib3f,
		InitVertexAttrib3fv,
		InitVertexAttrib3s,
		InitVertexAttrib3sv,
		InitVertexAttrib4Nbv,
		InitVertexAttrib4Niv,
		InitVertexAttrib4Nsv,
		InitVertexAttrib4Nub,
		InitVertexAttrib4Nubv,
		InitVertexAttrib4Nuiv,
		InitVertexAttrib4Nusv,
		InitVertexAttrib4bv,
		InitVertexAttrib4d,
		InitVertexAttrib4dv,
		InitVertexAttrib4f,
		InitVertexAttrib4fv,
		InitVertexAttrib4iv,
		InitVertexAttrib4s,
		InitVertexAttrib4sv,
		InitVertexAttrib4ubv,
		InitVertexAttrib4uiv,
		InitVertexAttrib4usv,
		InitVertexAttribPointer,
	};

#ifdef WIN32
	//WGL_ARB_buffer_region
	static HANDLE APIENTRY InitCreateBufferRegionARB (HDC a, int b, unsigned int c)
	{
		void *ext = (void*)GETPROC ("wglCreateBufferRegionARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return NULL;
		}

		wglCreateBufferRegionARB = (HANDLE (APIENTRY* ) (HDC, int, unsigned int))ext;
		return wglCreateBufferRegionARB (a, b, c);
	}

	static void APIENTRY InitDeleteBufferRegionARB (HANDLE a)
	{
		void *ext = (void*)GETPROC ("wglDeleteBufferRegionARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		wglDeleteBufferRegionARB = (void (APIENTRY* ) (HANDLE))ext;
		wglDeleteBufferRegionARB (a);
	}

	static bool APIENTRY InitSaveBufferRegionARB (HANDLE a, int b, int c, int d, int e)
	{
		void *ext = (void*)GETPROC ("wglSaveBufferRegionARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		wglSaveBufferRegionARB = (bool (APIENTRY* ) (HANDLE, int, int, int, int))ext;
		return wglSaveBufferRegionARB (a, b, c, d, e);
	}

	static bool APIENTRY InitRestoreBufferRegionARB (HANDLE a, int b, int c, int d, int e, int f, int g)
	{
		void *ext = (void*)GETPROC ("wglRestoreBufferRegionARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		wglRestoreBufferRegionARB = (bool (APIENTRY* ) (HANDLE, int, int, int, int, int, int))ext;
		return wglRestoreBufferRegionARB (a, b, c, d, e, f, g);
	}
#endif

	//GL_ARB_multisample
	static void APIENTRY InitSampleCoverageARB (float a, bool b)
	{
		void *ext = (void*)GETPROC ("glSampleCoverageARB");

		if (!ext)
			return;

		glSampleCoverageARB = (void (APIENTRY*) (float, bool))ext;
		glSampleCoverageARB (a, b);
	}

#ifdef WIN32
	//WGL_extensions_string
	static const char * APIENTRY InitGetExtensionsStringARB (HDC a)
	{
		void *ext = (void*)GETPROC ("wglGetExtensionsStringARB");

		if (!ext)
			return NULL;

		wglGetExtensionsStringARB = (const char* (APIENTRY*) (HDC))ext;
		return wglGetExtensionsStringARB (a);
	}
#endif

#ifdef WIN32
	//WGL_pixel_format
	static bool APIENTRY InitGetPixelFormatAttribivARB (HDC a, int b, int c, GLuint d, const int *e, int *f)
	{
		void *ext = (void*)GETPROC ("wglGetPixelFormatAttribivARB");

		if (!ext)
			return false;

		wglGetPixelFormatAttribivARB = (bool (APIENTRY*) (HDC, int, int, GLuint, const int*, int*))ext;
		return wglGetPixelFormatAttribivARB (a, b, c, d, e, f);
	}

	static bool APIENTRY InitGetPixelFormatAttribfvARB (HDC a, int b, int c, GLuint d, const int *e, float *f)
	{
		void *ext = (void*)GETPROC ("wglGetPixelFormatAttribfvARB");

		if (!ext)
			return false;

		wglGetPixelFormatAttribfvARB = (bool (APIENTRY*) (HDC, int, int, GLuint, const int*, float*))ext;
		return wglGetPixelFormatAttribfvARB (a, b, c, d, e, f);
	}

	static bool APIENTRY InitChoosePixelFormatARB (HDC a, const int *b, const float *c, GLuint d, int *e, GLuint *f)
	{
		void *ext = (void*)GETPROC ("wglChoosePixelFormatARB");

		if (!ext)
			return false;

		wglChoosePixelFormatARB = (bool (APIENTRY*) (HDC, const int*, const float*, GLuint, int*, GLuint*))ext;
		return wglChoosePixelFormatARB (a, b, c, d, e, f);
	}
#endif

#ifdef WIN32
	//WGL_make_current_read
	static bool APIENTRY InitMakeContextCurrentARB (HDC a, HDC b, HGLRC c)
	{
		void *ext = (void*)GETPROC ("wglMakeContextCurrentARB");

		if (!ext)
			return false;

		wglMakeContextCurrentARB = (bool (APIENTRY*) (HDC, HDC, HGLRC))ext;
		return wglMakeContextCurrentARB (a, b, c);
	}

	static HDC APIENTRY InitGetCurrentReadDCARB ()
	{
		void *ext = (void*)GETPROC ("wglGetCurrentReadDCARB");

		if (!ext)
			return NULL;

		wglGetCurrentReadDCARB = (HDC (APIENTRY*) (void))ext;
		return wglGetCurrentReadDCARB ();
	}
#endif

#ifdef WIN32
	//WGL_ARB_pbuffer
	static HPBUFFERARB APIENTRY InitwCreatePbufferARB (HDC a, int b, int c, int d, const int*e)
	{
		void *ext = (void*)GETPROC ("wglCreatePbufferARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return NULL;
		}

		wglCreatePbufferARB = (HPBUFFERARB (APIENTRY* ) (HDC, int, int, int, const int*))ext;
		return wglCreatePbufferARB (a, b, c, d, e);
	}
	
	static HDC APIENTRY InitwGetPbufferDCARB (HPBUFFERARB a)
	{
		void *ext = (void*)GETPROC ("wglGetPbufferDCARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		wglGetPbufferDCARB = (HDC (APIENTRY* ) (HPBUFFERARB))ext;
		return wglGetPbufferDCARB (a);
	}

	static bool APIENTRY InitwReleasePbufferDCARB (HPBUFFERARB a, int b)
	{
		void *ext = (void*)GETPROC ("wglReleaseTexImageARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		wglReleaseTexImageARB = (bool (APIENTRY* ) (HPBUFFERARB, int))ext;
		return wglReleaseTexImageARB (a, b);
	}

	static bool APIENTRY InitwDestroyPbufferARB (HPBUFFERARB a)
	{
		void *ext = (void*)GETPROC ("wglDestroyPbufferARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		wglDestroyPbufferARB = (bool (APIENTRY* ) (HPBUFFERARB))ext;
		return wglDestroyPbufferARB (a);
	}

	static bool APIENTRY InitwQueryPbufferARB (HPBUFFERARB a, int b, int *c)
	{
		void *ext = (void*)GETPROC ("wglQueryPbufferARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return false;
		}

		wglQueryPbufferARB = (bool (APIENTRY* ) (HPBUFFERARB, int, int*))ext;
		return wglQueryPbufferARB (a, b, c);
	}
#endif

	//GL_ARB_compressed_texture
	static void APIENTRY InitCompressedTexImage3DARB (GLenum a, int b, GLenum c, GLsizei d, GLsizei e, GLsizei f, int g, GLsizei h, const void *i)
	{
		void *ext = (void*)GETPROC ("glCompressedTexImage3DARB");

		if (!ext)
			return;

		glCompressedTexImage3DARB = (void (APIENTRY*) (GLenum, int, GLenum, GLsizei, GLsizei, GLsizei, int, GLsizei, const void*))ext;
		glCompressedTexImage3DARB (a, b, c, d, e, f, g, h, i);
	}

	static void APIENTRY InitCompressedTexImage2DARB (GLenum a, int b, GLenum c, GLsizei d, GLsizei e, int f, GLsizei g, const void *h)
	{
		void *ext = (void*)GETPROC ("glCompressedTexImage2DARB");

		if (!ext)
			return;

		glCompressedTexImage2DARB = (void (APIENTRY*) (GLenum, int, GLenum, GLsizei, GLsizei, int, GLsizei, const void*))ext;
		glCompressedTexImage2DARB (a, b, c, d, e, f, g, h);
	}

	static void APIENTRY InitCompressedTexImage1DARB (GLenum a, int b, GLenum c, GLsizei d, int e, GLsizei f, const void *g)
	{
		void *ext = (void*)GETPROC ("glCompressedTexImage1DARB");

		if (!ext)
			return;

		glCompressedTexImage1DARB = (void (APIENTRY*) (GLenum, int, GLenum, GLsizei, int, GLsizei, const void*))ext;
		glCompressedTexImage1DARB (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitCompressedTexSubImage3DARB (GLenum a, int b, int c, int d, int e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLsizei j, const void *k)
	{
		void *ext = (void*)GETPROC ("glCompressedTexSubImage3DARB");

		if (!ext)
			return;

		glCompressedTexSubImage3DARB = (void (APIENTRY*) (GLenum, int, int, int, int, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))ext;
		glCompressedTexSubImage3DARB (a, b, c, d, e, f, g, h, i, j, k);
	}

	static void APIENTRY InitCompressedTexSubImage2DARB (GLenum a, int b, int c, int d, GLsizei e, GLsizei f, GLenum g, GLsizei h, const void *i)
	{
		void *ext = (void*)GETPROC ("glCompressedTexSubImage2DARB");

		if (!ext)
			return;

		glCompressedTexSubImage2DARB = (void (APIENTRY*) (GLenum, int, int, int, GLsizei, GLsizei, GLenum, GLsizei, const void *))ext;
		glCompressedTexSubImage2DARB (a, b, c, d, e, f, g, h, i);
	}

	static void APIENTRY InitCompressedTexSubImage1DARB (GLenum a, int b, int c, GLsizei d, GLenum e, GLsizei f, const void *g)
	{
		void *ext = (void*)GETPROC ("glCompressedTexSubImage1DARB");

		if (!ext)
			return;

		glCompressedTexSubImage1DARB = (void (APIENTRY*) (GLenum, int, int, GLsizei, GLenum, GLsizei, const void*))ext;
		glCompressedTexSubImage1DARB (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitGetCompressedTexImageARB (GLenum a, int b, void *c)
	{
		void *ext = (void*)GETPROC ("glGetComopressedTexImageARB");

		if (!ext)
			return;

		glGetCompressedTexImageARB = (void (APIENTRY*) (GLenum, int, void*))ext;
		glGetCompressedTexImageARB (a, b, c);
	}

	//GL_ARB_point_parameters
	static void APIENTRY InitPointParameterfARB (GLenum a, float b)
	{
		void *ext = (void*)GETPROC ("glPointParameterfARB");

		if (!ext)
			return;

		glPointParameterfARB = (void (APIENTRY*) (GLenum, float))ext;
		glPointParameterfARB (a, b);
	}

	static void APIENTRY InitPointParameterfvARB (GLenum a, float *b)
	{
		void *ext = (void*)GETPROC ("glPointParameterfvARB");

		if (!ext)
			return;

		glPointParameterfvARB = (void (APIENTRY*) (GLenum, float*))ext;
		glPointParameterfvARB (a, b);
	}

	//GL_ARB_vertex_blend
	static void APIENTRY InitWeightbvARB (int a, char *b)
	{
		void *ext = (void*)GETPROC ("glWeightbvARB");

		if (!ext)
			return;

		glWeightbvARB = (void (APIENTRY*) (int, char*))ext;
		glWeightbvARB (a, b);
	}

	static void APIENTRY InitWeightubvARB (int a, unsigned char *b)
	{
		void *ext = (void*)GETPROC ("glWeightubvARB");

		if (!ext)
			return;

		glWeightubvARB = (void (APIENTRY*) (int, unsigned char*))ext;
		glWeightubvARB (a, b);
	}

	static void APIENTRY InitWeightsvARB (int a, short *b)
	{
		void *ext = (void*)GETPROC ("glWeightsvARB");

		if (!ext)
			return;

		glWeightsvARB = (void (APIENTRY*) (int, short*))ext;
		glWeightsvARB (a, b);
	}

	static void APIENTRY InitWeightusvARB (int a, unsigned short *b)
	{
		void *ext = (void*)GETPROC ("glWeightusvARB");

		if (!ext)
			return;

		glWeightusvARB = (void (APIENTRY*) (int, unsigned short*))ext;
		glWeightusvARB (a, b);
	}

	static void APIENTRY InitWeightivARB (int a, int *b)
	{
		void *ext = (void*)GETPROC ("glWeightivARB");

		if (!ext)
			return;

		glWeightivARB = (void (APIENTRY*) (int, int*))ext;
		glWeightivARB (a, b);
	}

	static void APIENTRY InitWeightuivARB (int a, unsigned int *b)
	{
		void *ext = (void*)GETPROC ("glWeightuivARB");

		if (!ext)
			return;

		glWeightuivARB = (void (APIENTRY*) (int, unsigned int*))ext;
		glWeightuivARB (a, b);
	}

	static void APIENTRY InitWeightfvARB (int a, float *b)
	{
		void *ext = (void*)GETPROC ("glWeightfvARB");

		if (!ext)
			return;

		glWeightfvARB = (void (APIENTRY*) (int, float*))ext;
		glWeightfvARB (a, b);
	}

	static void APIENTRY InitWeightdvARB (int a, double *b)
	{
		void *ext = (void*)GETPROC ("glWeightdvARB");

		if (!ext)
			return;

		glWeightdvARB = (void (APIENTRY*) (int, double*))ext;
		glWeightdvARB (a, b);
	}

	static void APIENTRY InitWeightPointerARB (int a, GLenum b, GLsizei c, void *d)
	{
		void *ext = (void*)GETPROC ("glWeightPointerARB");

		if (!ext)
			return;

		glWeightPointerARB = (void (APIENTRY*) (int, GLenum, GLsizei, void*))ext;
		glWeightPointerARB (a, b, c, d);
	}

	static void APIENTRY InitVertexBlendARB (int a)
	{
		void *ext = (void*)GETPROC ("glVertexBlendARB");

		if (!ext)
			return;

		glVertexBlendARB = (void (APIENTRY*) (int))ext;
		glVertexBlendARB (a);
	}

	//GL_ARB_palette_matrix
	static void APIENTRY InitCurrentPaletteMatrixARB (int a)
	{
		void *ext = (void*)GETPROC ("glCurrentPaletteMatrixARB");

		if (!ext)
			return;

		glCurrentPaletteMatrixARB = (void (APIENTRY*) (int))ext;
		glCurrentPaletteMatrixARB (a);
	}

	static void APIENTRY InitMatrixIndexubvARB (int a, unsigned char *b)
	{
		void *ext = (void*)GETPROC ("glMatrixIndexubvARB");

		if (!ext)
			return;

		glMatrixIndexubvARB = (void (APIENTRY*) (int, unsigned char*))ext;
		glMatrixIndexubvARB (a, b);
	}

	static void APIENTRY InitMatrixIndexusvARB (int a, unsigned short *b)
	{
		void *ext = (void*)GETPROC ("glMatrixIndexusvARB");

		if (!ext)
			return;

		glMatrixIndexusvARB = (void (APIENTRY*) (int, unsigned short*))ext;
		glMatrixIndexusvARB (a, b);
	}

	static void APIENTRY InitMatrixIndexuivARB (int a, unsigned int *b)
	{
		void *ext = (void*)GETPROC ("glMatrixIndexuivARB");

		if (!ext)
			return;

		glMatrixIndexuivARB = (void (APIENTRY*) (int, unsigned int*))ext;
		glMatrixIndexuivARB (a, b);
	}

	static void APIENTRY InitMatrixIndexPointerARB (int a, GLenum b, GLsizei c, void *d)
	{
		void *ext = (void*)GETPROC ("glMatrixIndexPointerARB");

		if (!ext)
			return;

		glMatrixIndexPointerARB = (void (APIENTRY*) (int, GLenum, GLsizei, void*))ext;
		glMatrixIndexPointerARB (a, b, c, d);
	}

#ifdef WIN32
	//GL_ARB_render_texture
	static bool APIENTRY InitwBindTexImageARB (HPBUFFERARB a, int b)
	{
		void *ext = (void*)GETPROC ("wglBindTexImageARB");

		if (!ext)
			return false;

		wglBindTexImageARB = (bool (APIENTRY*) (HPBUFFERARB, int))ext;
		return wglBindTexImageARB (a, b);
	}

	static bool APIENTRY InitwReleaseTexImageARB (HPBUFFERARB a, int b)
	{
		void *ext = (void*)GETPROC ("wglReleaseTexImageARB");

		if (!ext)
			return false;

		wglReleaseTexImageARB = (bool (APIENTRY*) (HPBUFFERARB, int))ext;
		return wglReleaseTexImageARB (a, b);
	}

	static bool APIENTRY InitwSetPbufferAttribARB (HPBUFFERARB a, const int *b)
	{
		void *ext = (void*)GETPROC ("wglSetPbufferAttribARB");

		if (!ext)
			return false;

		wglSetPbufferAttribARB = (bool (APIENTRY*) (HPBUFFERARB, const int*))ext;
		return wglSetPbufferAttribARB (a, b);
	}
#endif

	//GL_ARB_window_pos
	static void APIENTRY InitWindowPos2dARB (double a, double b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2dARB");

		if (!ext)
			return;

		glWindowPos2dARB = (void (APIENTRY*) (double, double))ext;
		glWindowPos2dARB (a, b);
	}

	static void APIENTRY InitWindowPos2fARB (float a, float b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2fARB");

		if (!ext)
			return;

		glWindowPos2fARB = (void (APIENTRY*) (float, float))ext;
		glWindowPos2fARB (a, b);
	}

	static void APIENTRY InitWindowPos2iARB (int a, int b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2iARB");

		if (!ext)
			return;

		glWindowPos2iARB = (void (APIENTRY*) (int, int))ext;
		glWindowPos2iARB (a, b);
	}

	static void APIENTRY InitWindowPos2sARB (short a, short b)
	{
		void *ext = (void*)GETPROC ("glWindowPos2sARB");

		if (!ext)
			return;

		glWindowPos2sARB = (void (APIENTRY*) (short, short))ext;
		glWindowPos2sARB (a, b);
	}

	static void APIENTRY InitWindowPos2dvARB (const double *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2dvARB");

		if (!ext)
			return;

		glWindowPos2dvARB = (void (APIENTRY*) (const double*))ext;
		glWindowPos2dvARB (a);
	}

	static void APIENTRY InitWindowPos2fvARB (const float *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2fvARB");

		if (!ext)
			return;

		glWindowPos2fvARB = (void (APIENTRY*) (const float*))ext;
		glWindowPos2fvARB (a);
	}

	static void APIENTRY InitWindowPos2ivARB (const int *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2ivARB");

		if (!ext)
			return;

		glWindowPos2ivARB = (void (APIENTRY*) (const int*))ext;
		glWindowPos2ivARB (a);
	}

	static void APIENTRY InitWindowPos2svARB (const short *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos2svARB");

		if (!ext)
			return;

		glWindowPos2svARB = (void (APIENTRY*) (const short*))ext;
		glWindowPos2svARB (a);
	}

	static void APIENTRY InitWindowPos3dARB (double a, double b, double c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3dARB");

		if (!ext)
			return;

		glWindowPos3dARB = (void (APIENTRY*) (double, double, double))ext;
		glWindowPos3dARB (a, b, c);
	}

	static void APIENTRY InitWindowPos3fARB (float a, float b, float c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3fARB");

		if (!ext)
			return;

		glWindowPos3fARB = (void (APIENTRY*) (float, float, float))ext;
		glWindowPos3fARB (a, b, c);
	}

	static void APIENTRY InitWindowPos3iARB (int a, int b, int c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3iARB");

		if (!ext)
			return;

		glWindowPos3iARB = (void (APIENTRY*) (int, int, int))ext;
		glWindowPos3iARB (a, b, c);
	}

	static void APIENTRY InitWindowPos3sARB (short a, short b, short c)
	{
		void *ext = (void*)GETPROC ("glWindowPos3sARB");

		if (!ext)
			return;

		glWindowPos3sARB = (void (APIENTRY*) (short, short, short))ext;
		glWindowPos3sARB (a, b, c);
	}

	static void APIENTRY InitWindowPos3dvARB (const double *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3dvARB");

		if (!ext)
			return;

		glWindowPos3dvARB = (void (APIENTRY*) (const double*))ext;
		glWindowPos3dvARB (a);
	}

	static void APIENTRY InitWindowPos3fvARB (const float *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3fvARB");

		if (!ext)
			return;

		glWindowPos3fvARB = (void (APIENTRY*) (const float*))ext;
		glWindowPos3fvARB (a);
	}

	static void APIENTRY InitWindowPos3ivARB (const int *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3ivARB");

		if (!ext)
			return;

		glWindowPos3ivARB = (void (APIENTRY*) (const int*))ext;
		glWindowPos3ivARB (a);
	}

	static void APIENTRY InitWindowPos3svARB (const short *a)
	{
		void *ext = (void*)GETPROC ("glWindowPos3svARB");

		if (!ext)
			return;

		glWindowPos3svARB = (void (APIENTRY*) (const short*))ext;
		glWindowPos3svARB (a);
	}

	//GL_ARB_vertex_program
	static void APIENTRY InitVertexAttrib1sARB (GLuint a, short b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1sARB");

		if (!ext)
			return;

		glVertexAttrib1sARB = (void (APIENTRY*) (GLuint, short))ext;
		glVertexAttrib1sARB (a, b);
	}

	static void APIENTRY InitVertexAttrib1fARB (GLuint a, float b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1fARB");

		if (!ext)
			return;

		glVertexAttrib1fARB = (void (APIENTRY*) (GLuint, float))ext;
		glVertexAttrib1fARB (a, b);
	}

	static void APIENTRY InitVertexAttrib1dARB (GLuint a, double b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1dARB");

		if (!ext)
			return;

		glVertexAttrib1dARB = (void (APIENTRY*) (GLuint, double))ext;
		glVertexAttrib1dARB (a, b);
	}

	static void APIENTRY InitVertexAttrib2sARB (GLuint a, short b, short c)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2sARB");

		if (!ext)
			return;

		glVertexAttrib2sARB = (void (APIENTRY*) (GLuint, short, short))ext;
		glVertexAttrib2sARB (a, b, c);
	}

	static void APIENTRY InitVertexAttrib2fARB (GLuint a, float b, float c)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2fARB");

		if (!ext)
			return;

		glVertexAttrib2fARB = (void (APIENTRY*) (GLuint, float, float))ext;
		glVertexAttrib2fARB (a, b, c);
	}

	static void APIENTRY InitVertexAttrib2dARB (GLuint a, double b, double c)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2dARB");

		if (!ext)
			return;

		glVertexAttrib2dARB = (void (APIENTRY*) (GLuint, double, double))ext;
		glVertexAttrib2dARB (a, b, c);
	}

	static void APIENTRY InitVertexAttrib3sARB (GLuint a, short b, short c, short d)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3sARB");

		if (!ext)
			return;

		glVertexAttrib3sARB = (void (APIENTRY*) (GLuint, short, short, short))ext;
		glVertexAttrib3sARB (a, b, c, d);
	}

	static void APIENTRY InitVertexAttrib3fARB (GLuint a, float b, float c, float d)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3fARB");

		if (!ext)
			return;

		glVertexAttrib3fARB = (void (APIENTRY*) (GLuint, float, float, float))ext;
		glVertexAttrib3fARB (a, b, c, d);
	}

	static void APIENTRY InitVertexAttrib3dARB (GLuint a, double b, double c, double d)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3dARB");

		if (!ext)
			return;

		glVertexAttrib3dARB = (void (APIENTRY*) (GLuint, double, double, double))ext;
		glVertexAttrib3dARB (a, b, c, d);
	}

	static void APIENTRY InitVertexAttrib4sARB (GLuint a, short b, short c, short d, short e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4sARB");

		if (!ext)
			return;

		glVertexAttrib4sARB = (void (APIENTRY*) (GLuint, short, short, short, short))ext;
		glVertexAttrib4sARB (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4fARB (GLuint a, float b, float c, float d, float e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4fARB");

		if (!ext)
			return;

		glVertexAttrib4fARB = (void (APIENTRY*) (GLuint, float, float, float, float))ext;
		glVertexAttrib4fARB (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4dARB (GLuint a, double b, double c, double d, double e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4dARB");

		if (!ext)
			return;

		glVertexAttrib4dARB = (void (APIENTRY*) (GLuint, double, double, double, double))ext;
		glVertexAttrib4dARB (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib4NubARB (GLuint a, unsigned char b, unsigned char c, unsigned char d, unsigned char e)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NubARB");

		if (!ext)
			return;

		glVertexAttrib4NubARB = (void (APIENTRY*) (GLuint, unsigned char, unsigned char, unsigned char, unsigned char))ext;
		glVertexAttrib4NubARB (a, b, c, d, e);
	}

	static void APIENTRY InitVertexAttrib1svARB (GLuint a, const short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1svARB");

		if (!ext)
			return;

		glVertexAttrib1svARB = (void (APIENTRY*) (GLuint, const short*))ext;
		glVertexAttrib1svARB (a, b);
	}

	static void APIENTRY InitVertexAttrib1fvARB (GLuint a, const float *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1fvARB");

		if (!ext)
			return;

		glVertexAttrib1fvARB = (void (APIENTRY*) (GLuint, const float*))ext;
		glVertexAttrib1fvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib1dvARB (GLuint a, const double *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib1dvARB");

		if (!ext)
			return;

		glVertexAttrib1dvARB = (void (APIENTRY*) (GLuint, const double*))ext;
		glVertexAttrib1dvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib2svARB (GLuint a, const short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2svARB");

		if (!ext)
			return;

		glVertexAttrib2svARB = (void (APIENTRY*) (GLuint, const short*))ext;
		glVertexAttrib2svARB (a, b);
	}

	static void APIENTRY InitVertexAttrib2fvARB (GLuint a, const float *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2fvARB");

		if (!ext)
			return;

		glVertexAttrib2fvARB = (void (APIENTRY*) (GLuint, const float*))ext;
		glVertexAttrib2fvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib2dvARB (GLuint a, const double *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib2dvARB");

		if (!ext)
			return;

		glVertexAttrib2dvARB = (void (APIENTRY*) (GLuint, const double*))ext;
		glVertexAttrib2dvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib3svARB (GLuint a, const short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3svARB");

		if (!ext)
			return;

		glVertexAttrib3svARB = (void (APIENTRY*) (GLuint, const short*))ext;
		glVertexAttrib3svARB (a, b);
	}

	static void APIENTRY InitVertexAttrib3fvARB (GLuint a, const float *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3fvARB");

		if (!ext)
			return;

		glVertexAttrib3fvARB = (void (APIENTRY*) (GLuint, const float*))ext;
		glVertexAttrib3fvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib3dvARB (GLuint a, const double *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib3dvARB");

		if (!ext)
			return;

		glVertexAttrib3dvARB = (void (APIENTRY*) (GLuint, const double*))ext;
		glVertexAttrib3dvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4bvARB (GLuint a, const char *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4bvARB");

		if (!ext)
			return;

		glVertexAttrib4bvARB = (void (APIENTRY*) (GLuint, const char*))ext;
		glVertexAttrib4bvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4svARB (GLuint a, const short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4svARB");

		if (!ext)
			return;

		glVertexAttrib4svARB = (void (APIENTRY*) (GLuint, const short*))ext;
		glVertexAttrib4svARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4ivARB (GLuint a, const int *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4ivARB");

		if (!ext)
			return;

		glVertexAttrib4ivARB = (void (APIENTRY*) (GLuint, const int*))ext;
		glVertexAttrib4ivARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4ubvARB (GLuint a, const unsigned char *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4ubvARB");

		if (!ext)
			return;

		glVertexAttrib4ubvARB = (void (APIENTRY*) (GLuint, const unsigned char*))ext;
		glVertexAttrib4ubvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4usvARB (GLuint a, const unsigned short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4usvARB");

		if (!ext)
			return;

		glVertexAttrib4usvARB = (void (APIENTRY*) (GLuint, const unsigned short*))ext;
		glVertexAttrib4usvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4uivARB (GLuint a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4uivARB");

		if (!ext)
			return;

		glVertexAttrib4uivARB = (void (APIENTRY*) (GLuint, const GLuint*))ext;
		glVertexAttrib4uivARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4fvARB (GLuint a, const float *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4fvARB");

		if (!ext)
			return;

		glVertexAttrib4fvARB = (void (APIENTRY*) (GLuint, const float*))ext;
		glVertexAttrib4fvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4dvARB (GLuint a, const double *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4dvARB");

		if (!ext)
			return;

		glVertexAttrib4dvARB = (void (APIENTRY*) (GLuint, const double*))ext;
		glVertexAttrib4dvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4NbvARB (GLuint a, const char *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NbvARB");

		if (!ext)
			return;

		glVertexAttrib4NbvARB = (void (APIENTRY*) (GLuint, const char*))ext;
		glVertexAttrib4NbvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4NsvARB (GLuint a, const short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NsvARB");

		if (!ext)
			return;

		glVertexAttrib4NsvARB = (void (APIENTRY*) (GLuint, const short*))ext;
		glVertexAttrib4NsvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4NivARB (GLuint a, const int *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NivARB");

		if (!ext)
			return;

		glVertexAttrib4NivARB = (void (APIENTRY*) (GLuint, const int*))ext;
		glVertexAttrib4NivARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4NubvARB (GLuint a, const unsigned char *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NubvARB");

		if (!ext)
			return;

		glVertexAttrib4NubvARB = (void (APIENTRY*) (GLuint, const unsigned char*))ext;
		glVertexAttrib4NubvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4NusvARB (GLuint a, const unsigned short *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NusvARB");

		if (!ext)
			return;

		glVertexAttrib4NusvARB = (void (APIENTRY*) (GLuint, const unsigned short*))ext;
		glVertexAttrib4NusvARB (a, b);
	}

	static void APIENTRY InitVertexAttrib4NuivARB (GLuint a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glVertexAttrib4NuivARB");

		if (!ext)
			return;

		glVertexAttrib4NuivARB = (void (APIENTRY*) (GLuint, const GLuint*))ext;
		glVertexAttrib4NuivARB (a, b);
	}

	static void APIENTRY InitVertexAttribPointerARB (GLuint a, int b, GLenum c, bool d, GLsizei e, const void *f)
	{
		void *ext = (void*)GETPROC ("glVertexAttribPointerARB");

		if (!ext)
			return;

		glVertexAttribPointerARB = (void (APIENTRY*) (GLuint, int, GLenum, bool, GLsizei, const void*))ext;
		glVertexAttribPointerARB (a, b, c, d, e, f);
	}

	static void APIENTRY InitEnableVertexAttribArrayARB (GLuint a)
	{
		void *ext = (void*)GETPROC ("glEnableVertexAttribArrayARB");

		if (!ext)
			return;

		glEnableVertexAttribArrayARB = (void (APIENTRY*) (GLuint))ext;
		glEnableVertexAttribArrayARB (a);
	}

	static void APIENTRY InitDisableVertexAttribArrayARB (GLuint a)
	{
		void *ext = (void*)GETPROC ("glDisableVertexAttribArrayARB");

		if (!ext)
			return;

		glDisableVertexAttribArrayARB = (void (APIENTRY*) (GLuint))ext;
		glDisableVertexAttribArrayARB (a);
	}

	static void APIENTRY InitProgramStringARB (GLenum a, GLenum b, GLsizei c, const void *d)
	{
		void *ext = (void*)GETPROC ("glProgramStringARB");

		if (!ext)
			return;

		glProgramStringARB = (void (APIENTRY*) (GLenum, GLenum, GLsizei, const void*))ext;
		glProgramStringARB (a, b, c, d);
	}

	static void APIENTRY InitBindProgramARB (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBindProgramARB");

		if (!ext)
			return;

		glBindProgramARB = (void (APIENTRY*) (GLenum, GLuint))ext;
		glBindProgramARB (a, b);
	}

	static void APIENTRY InitDeleteProgramsARB (GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteProgramsARB");

		if (!ext)
			return;

		glDeleteProgramsARB = (void (APIENTRY*) (GLsizei, const GLuint*))ext;
		glDeleteProgramsARB (a, b);
	}

	static void APIENTRY InitGenProgramsARB (GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenProgramsARB");

		if (!ext)
			return;

		glGenProgramsARB = (void (APIENTRY*) (GLsizei, GLuint*))ext;
		glGenProgramsARB (a, b);
	}

	static void APIENTRY InitProgramEnvParameter4dARB (GLenum a, GLuint b, double c, double d, double e, double f)
	{
		void *ext = (void*)GETPROC ("glProgramEnvParameter4dARB");

		if (!ext)
			return;

		glProgramEnvParameter4dARB = (void (APIENTRY*) (GLenum, GLuint, double, double, double, double))ext;
		glProgramEnvParameter4dARB (a, b, c, d, e, f);
	}

	static void APIENTRY InitProgramEnvParameter4dvARB (GLenum a, GLuint b, const double *c)
	{
		void *ext = (void*)GETPROC ("glProgramEnvParameter4dvARB");

		if (!ext)
			return;

		glProgramEnvParameter4dvARB = (void (APIENTRY*) (GLenum, GLuint, const double*))ext;
		glProgramEnvParameter4dvARB (a, b, c);
	}

	static void APIENTRY InitProgramEnvParameter4fARB (GLenum a, GLuint b, float c, float d, float e, float f)
	{
		void *ext = (void*)GETPROC ("glProgramEnvParameter4fARB");

		if (!ext)
			return;

		glProgramEnvParameter4fARB = (void (APIENTRY*) (GLenum, GLuint, float, float, float, float))ext;
		glProgramEnvParameter4fARB (a, b, c, d, e, f);
	}

	static void APIENTRY InitProgramEnvParameter4fvARB (GLenum a, GLuint b, const float *c)
	{
		void *ext = (void*)GETPROC ("glProgramEnvParameter4fvARB");

		if (!ext)
			return;

		glProgramEnvParameter4fvARB = (void (APIENTRY*) (GLenum, GLuint, const float*))ext;
		glProgramEnvParameter4fvARB (a, b, c);
	}

	static void APIENTRY InitProgramLocalParameter4dARB (GLenum a, GLuint b, double c, double d, double e, double f)
	{
		void *ext = (void*)GETPROC ("glProgramLocalParameter4dARB");

		if (!ext)
			return;

		glProgramLocalParameter4dARB = (void (APIENTRY*) (GLenum, GLuint, double, double, double, double))ext;
		glProgramLocalParameter4dARB (a, b, c, d, e, f);
	}

	static void APIENTRY InitProgramLocalParameter4dvARB (GLenum a, GLuint b, const double *c)
	{
		void *ext = (void*)GETPROC ("glProgramLocalParameter4dvARB");

		if (!ext)
			return;

		glProgramLocalParameter4dvARB = (void (APIENTRY*) (GLenum, GLuint, const double*))ext;
		glProgramLocalParameter4dvARB (a, b, c);
	}

	static void APIENTRY InitProgramLocalParameter4fARB (GLenum a, GLuint b, float c, float d, float e, float f)
	{
		void *ext = (void*)GETPROC ("glProgramLocalParameter4fARB");

		if (!ext)
			return;

		glProgramLocalParameter4fARB = (void (APIENTRY*) (GLenum, GLuint, float, float, float, float))ext;
		glProgramLocalParameter4fARB (a, b, c, d, e, f);
	}

	static void APIENTRY InitProgramLocalParameter4fvARB (GLenum a, GLuint b, const float *c)
	{
		void *ext = (void*)GETPROC ("glProgramLocalParameter4fvARB");

		if (!ext)
			return;

		glProgramLocalParameter4fvARB = (void (APIENTRY*) (GLenum, GLuint, const float*))ext;
		glProgramLocalParameter4fvARB (a, b, c);
	}

	static void APIENTRY InitGetProgramEnvParameterdvARB (GLenum a, GLuint b, double *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramEnvParameterdvARB");

		if (!ext)
			return;

		glGetProgramEnvParameterdvARB = (void (APIENTRY*) (GLenum, GLuint, double*))ext;
		glGetProgramEnvParameterdvARB (a, b, c);
	}

	static void APIENTRY InitGetProgramEnvParameterfvARB (GLenum a, GLuint b, float *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramEnvParameterfvARB");

		if (!ext)
			return;

		glGetProgramEnvParameterfvARB = (void (APIENTRY*) (GLenum, GLuint, float*))ext;
		glGetProgramEnvParameterfvARB (a, b, c);
	}

	static void APIENTRY InitGetProgramLocalParameterdvARB (GLenum a, GLuint b, double *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramLocalParameterdvARB");

		if (!ext)
			return;

		glGetProgramLocalParameterdvARB = (void (APIENTRY*) (GLenum, GLuint, double*))ext;
		glGetProgramLocalParameterdvARB (a, b, c);
	}

	static void APIENTRY InitGetProgramLocalParameterfvARB (GLenum a, GLuint b, float *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramLocalParameterfvARB");

		if (!ext)
			return;

		glGetProgramLocalParameterfvARB = (void (APIENTRY*) (GLenum, GLuint, float*))ext;
		glGetProgramLocalParameterfvARB (a, b, c);
	}

	static void APIENTRY InitGetProgramivARB (GLenum a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramivARB");

		if (!ext)
			return;

		glGetProgramivARB = (void (APIENTRY*) (GLenum, GLenum, int*))ext;
		glGetProgramivARB (a, b, c);
	}

	static void APIENTRY InitGetProgramStringARB (GLenum a, GLenum b, void *c)
	{
		void *ext = (void*)GETPROC ("glGetProgramStringARB");

		if (!ext)
			return;

		glGetProgramStringARB = (void (APIENTRY*) (GLenum, GLenum, void*))ext;
		glGetProgramStringARB (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribdvARB (GLuint a, GLenum b, double *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribdvARB");

		if (!ext)
			return;

		glGetVertexAttribdvARB = (void (APIENTRY*) (GLuint, GLenum, double*))ext;
		glGetVertexAttribdvARB (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribfvARB (GLuint a, GLenum b, float *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribfvARB");

		if (!ext)
			return;

		glGetVertexAttribfvARB = (void (APIENTRY*) (GLuint, GLenum, float*))ext;
		glGetVertexAttribfvARB (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribivARB (GLuint a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribivARB");

		if (!ext)
			return;

		glGetVertexAttribivARB = (void (APIENTRY*) (GLuint, GLenum, int*))ext;
		glGetVertexAttribivARB (a, b, c);
	}

	static void APIENTRY InitGetVertexAttribPointervARB (GLuint a, GLenum b, void **c)
	{
		void *ext = (void*)GETPROC ("glGetVertexAttribPointervARB");

		if (!ext)
			return;

		glGetVertexAttribPointervARB = (void (APIENTRY*) (GLuint, GLenum, void**))ext;
		glGetVertexAttribPointervARB (a, b, c);
	}

	static bool APIENTRY InitIsProgramARB (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsProgramARB");

		if (!ext)
			return false;

		glIsProgramARB = (bool (APIENTRY*) (GLuint))ext;
		return glIsProgramARB (a);
	}

	//GL_ARB_fragment_program

	//GL_ARB_vertex_buffer_object
	static void APIENTRY InitBindBufferARB (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBindBufferARB");

		if (!ext)
			return;

		glBindBufferARB = (void (APIENTRY*) (GLenum, GLuint))ext;
		glBindBufferARB (a, b);
	}

	static void APIENTRY InitDeleteBuffersARB(GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteBuffersARB");

		if (!ext)
			return;

		glDeleteBuffersARB = (void (APIENTRY*) (GLsizei, const GLuint*))ext;
		glDeleteBuffersARB (a, b);
	}

	static void APIENTRY InitGenBuffersARB(GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenBuffersARB");

		if (!ext)
			return;

		glGenBuffersARB = (void (APIENTRY*) (GLsizei, GLuint*))ext;
		glGenBuffersARB (a, b);
	}

	static bool APIENTRY InitIsBufferARB(GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsBufferARB");

		if (!ext)
			return false;

		glIsBufferARB = (bool (APIENTRY*) (GLuint))ext;
		return glIsBufferARB (a);
	}

	static void APIENTRY InitBufferDataARB(GLenum a, GLsizei *b, const void *c, GLenum d)
	{
		void *ext = (void*)GETPROC ("glBufferDataARB");

		if (!ext)
			return;

		glBufferDataARB = (void (APIENTRY*) (GLenum, GLsizei *, const void*, GLenum))ext;
		glBufferDataARB (a, b, c, d);
	}

	static void APIENTRY InitBufferSubDataARB(GLenum a, GLint* b, GLsizei* c, const void *d)
	{
		void *ext = (void*)GETPROC ("glBufferSubDataARB");

		if (!ext)
			return;

		glBufferSubDataARB = (void (APIENTRY*) (GLenum, GLint*, GLsizei*, const void*))ext;
		glBufferSubDataARB (a, b, c, d);
	}

	static void APIENTRY InitGetBufferSubDataARB(GLenum a, GLint *b, GLsizei *c, void *d)
	{
		void *ext = (void*)GETPROC ("glGetBufferSubDataARB");

		if (!ext)
			return;

		glGetBufferSubDataARB = (void (APIENTRY*) (GLenum, GLint*, GLsizei*, void*))ext;
		glGetBufferSubDataARB (a, b, c, d);
	}

	static void* APIENTRY InitMapBufferARB(GLenum a, GLenum b)
	{
		void *ext = (void*)GETPROC ("glMapBufferARB");

		if (!ext)
			return NULL;

		glMapBufferARB = (void* (APIENTRY*) (GLenum, GLenum))ext;
		return glMapBufferARB (a, b);
	}

	static bool APIENTRY InitUnmapBufferARB(GLenum a)
	{
		void *ext = (void*)GETPROC ("glUnmapBufferARB");

		if (!ext)
			return false;

		glUnmapBufferARB = (bool (APIENTRY*) (GLenum))ext;
		return glUnmapBufferARB (a);
	}

	static void APIENTRY InitGetBufferParameterivARB(GLenum a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetBufferParameterivARB");

		if (!ext)
			return;

		glGetBufferParameterivARB = (void (APIENTRY*) (GLenum, GLenum, int*))ext;
		glGetBufferParameterivARB (a, b, c);
	}

	static void APIENTRY InitGetBufferPointervARB(GLenum a, GLenum b, void **c)
	{
		void *ext = (void*)GETPROC ("glGetBufferPointervARB");

		if (!ext)
			return;

		glGetBufferPointervARB = (void (APIENTRY*) (GLenum, GLenum, void**))ext;
		glGetBufferPointervARB (a, b, c);
	}

	//GL_ARB_occlusion_query
	static void APIENTRY InitGenQueriesARB(GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenQueriesARB");

		if (!ext)
			return;

		glGenQueriesARB = (void (APIENTRY*) (GLsizei, GLuint*))ext;
		glGenQueriesARB (a, b);
	}

	static void APIENTRY InitDeleteQueriesARB(GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteQueriesARB");

		if (!ext)
			return;

		glDeleteQueriesARB = (void (APIENTRY*) (GLsizei, const GLuint*))ext;
		glDeleteQueriesARB (a, b);
	}

	static bool APIENTRY InitIsQueryARB(GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsQueryARB");

		if (!ext)
			return false;

		glIsQueryARB = (bool (APIENTRY*) (GLuint))ext;
		return glIsQueryARB (a);
	}

	static void APIENTRY InitBeginQueryARB(GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBeginQueryARB");

		if (!ext)
			return;

		glBeginQueryARB = (void (APIENTRY*) (GLenum, GLuint))ext;
		glBeginQueryARB (a, b);
	}

	static void APIENTRY InitEndQueryARB(GLenum a)
	{
		void *ext = (void*)GETPROC ("glEndQueryARB");

		if (!ext)
			return;

		glEndQueryARB = (void (APIENTRY*) (GLenum))ext;
		glEndQueryARB (a);
	}

	static void APIENTRY InitGetQueryivARB (GLenum a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetQueryivARB");

		if (!ext)
			return;

		glGetQueryivARB = (void (APIENTRY*) (GLenum, GLenum, int*))ext;
		glGetQueryivARB (a, b, c);
	}

	static void APIENTRY InitGetQueryObjectivARB (GLuint a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetQueryObjectivARB");

		if (!ext)
			return;

		glGetQueryObjectivARB = (void (APIENTRY*) (GLuint, GLenum, int*))ext;
		glGetQueryObjectivARB (a, b, c);
	}

	static void APIENTRY InitGetQueryObjectuivARB(GLuint a, GLenum b, GLuint *c)
	{
		void *ext = (void*)GETPROC ("glGetQueryObjectuivARB");

		if (!ext)
			return;

		glGetQueryObjectuivARB = (void (APIENTRY*) (GLuint, GLenum, GLuint*))ext;
		glGetQueryObjectuivARB (a, b, c);
	}

	//GL_ARB_shader_objects
	static void APIENTRY InitDeleteObjectARB (GLhandleARB a)
	{
		void *ext = (void*)GETPROC ("glDeleteObjectARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDeleteObjectARB = (void (APIENTRY* ) (GLhandleARB))ext;
		glDeleteObjectARB (a);
	}

	static GLhandleARB APIENTRY InitGetHandleARB (GLenum a)
	{
		void *ext = (void*)GETPROC ("glGetHandleARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return NULL;
		}

		glGetHandleARB = (GLhandleARB (APIENTRY* ) (GLenum))ext;
		return glGetHandleARB (a);
	}

	static void APIENTRY InitDetachObjectARB (GLhandleARB a, GLhandleARB b)
	{
		void *ext = (void*)GETPROC ("glDetachObjectARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glDetachObjectARB = (void (APIENTRY* ) (GLhandleARB, GLhandleARB))ext;
		glDetachObjectARB (a, b);
	}

	static GLhandleARB APIENTRY InitCreateShaderObjectARB (GLenum a)
	{
		void *ext = (void*)GETPROC ("glCreateShaderObjectARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return NULL;
		}

		glCreateShaderObjectARB = (GLhandleARB (APIENTRY* ) (GLenum))ext;
		return glCreateShaderObjectARB (a);
	}

	static void APIENTRY InitShaderSourceARB (GLhandleARB a, GLsizei b, const GLcharARB* *c, const GLint *d)
	{
		void *ext = (void*)GETPROC ("glShaderSourceARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glShaderSourceARB = (void (APIENTRY* ) (GLhandleARB, GLsizei,  const GLcharARB* *, const GLint *))ext;
		glShaderSourceARB (a, b, c, d);
	}

	static void APIENTRY InitCompileShaderARB (GLhandleARB a)
	{
		void *ext = (void*)GETPROC ("glCompileShaderARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glCompileShaderARB = (void (APIENTRY* ) (GLhandleARB))ext;
		glCompileShaderARB (a);
	}

	static GLhandleARB APIENTRY InitCreateProgramObjectARB (void)
	{
		void *ext = (void*)GETPROC ("glCreateProgramObjectARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return NULL;
		}

		glCreateProgramObjectARB = (GLhandleARB (APIENTRY* ) (void))ext;
		return glCreateProgramObjectARB ();
	}

	static void APIENTRY InitAttachObjectARB (GLhandleARB a, GLhandleARB b)
	{
		void *ext = (void*)GETPROC ("glAttachObjectARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glAttachObjectARB = (void (APIENTRY* ) (GLhandleARB, GLhandleARB))ext;
		glAttachObjectARB (a, b);
	}

	static void APIENTRY InitLinkProgramARB (GLhandleARB a)
	{
		void *ext = (void*)GETPROC ("glLinkProgramARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glLinkProgramARB = (void (APIENTRY* ) (GLhandleARB))ext;
		glLinkProgramARB (a);
	}

	static void APIENTRY InitUseProgramObjectARB (GLhandleARB a)
	{
		void *ext = (void*)GETPROC ("glUseProgramObjectARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUseProgramObjectARB = (void (APIENTRY* ) (GLhandleARB))ext;
		glUseProgramObjectARB (a);
	}

	static void APIENTRY InitValidateProgramARB (GLhandleARB a)
	{
		void *ext = (void*)GETPROC ("glValidateProgramARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glValidateProgramARB = (void (APIENTRY* ) (GLhandleARB))ext;
		glValidateProgramARB (a);
	}

	static void APIENTRY InitUniform1fARB (GLint a, GLfloat b)
	{
		void *ext = (void*)GETPROC ("glUniform1fARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1fARB = (void (APIENTRY* ) (GLint, GLfloat))ext;
		glUniform1fARB (a, b);
	}

	static void APIENTRY InitUniform2fARB (GLint a, GLfloat b, GLfloat c)
	{
		void *ext = (void*)GETPROC ("glUniform2fARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2fARB = (void (APIENTRY* ) (GLint, GLfloat, GLfloat))ext;
		glUniform2fARB (a, b, c);
	}

	static void APIENTRY InitUniform3fARB (GLint a, GLfloat b, GLfloat c, GLfloat d)
	{
		void *ext = (void*)GETPROC ("glUniform3fARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3fARB = (void (APIENTRY* ) (GLint, GLfloat, GLfloat, GLfloat))ext;
		glUniform3fARB (a, b, c, d);
	}

	static void APIENTRY InitUniform4fARB (GLint a, GLfloat b, GLfloat c, GLfloat d, GLfloat e)
	{
		void *ext = (void*)GETPROC ("glUniform4fARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4fARB = (void (APIENTRY* ) (GLint, GLfloat, GLfloat, GLfloat, GLfloat))ext;
		glUniform4fARB (a, b, c, d, e);
	}

	static void APIENTRY InitUniform1iARB (GLint a, GLint b)
	{
		void *ext = (void*)GETPROC ("glUniform1iARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1iARB = (void (APIENTRY* ) (GLint, GLint))ext;
		glUniform1iARB (a, b);
	}

	static void APIENTRY InitUniform2iARB (GLint a, GLint b, GLint c)
	{
		void *ext = (void*)GETPROC ("glUniform2iARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2iARB = (void (APIENTRY* ) (GLint, GLint, GLint))ext;
		glUniform2iARB (a, b, c);
	}

	static void APIENTRY InitUniform3iARB (GLint a, GLint b, GLint c, GLint d)
	{
		void *ext = (void*)GETPROC ("glUniform3iARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3iARB = (void (APIENTRY* ) (GLint, GLint, GLint, GLint))ext;
		glUniform3iARB (a, b, c, d);
	}

	static void APIENTRY InitUniform4iARB (GLint a, GLint b, GLint c, GLint d, GLint e)
	{
		void *ext = (void*)GETPROC ("glUniform4iARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4iARB = (void (APIENTRY* ) (GLint, GLint, GLint, GLint, GLint))ext;
		glUniform4iARB (a, b, c, d, e);
	}

	static void APIENTRY InitUniform1fvARB (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform1fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1fvARB = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform1fvARB (a, b, c);
	}

	static void APIENTRY InitUniform2fvARB (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform2fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2fvARB = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform2fvARB (a, b, c);
	}

	static void APIENTRY InitUniform3fvARB (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform3fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3fvARB = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform3fvARB (a, b, c);
	}

	static void APIENTRY InitUniform4fvARB (GLint a, GLsizei b, const GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glUniform4fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4fvARB = (void (APIENTRY* ) (GLint, GLsizei, const GLfloat*))ext;
		glUniform4fvARB (a, b, c);
	}

	static void APIENTRY InitUniform1ivARB (GLint a, GLsizei b, const GLint *c)
	{
		void *ext = (void*)GETPROC ("glUniform1ivARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform1ivARB = (void (APIENTRY* ) (GLint, GLsizei, const GLint*))ext;
		glUniform1ivARB (a, b, c);
	}

	static void APIENTRY InitUniform2ivARB (GLint a, GLsizei b, const GLint *c)
		{
		void *ext = (void*)GETPROC ("glUniform2ivARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform2ivARB = (void (APIENTRY* ) (GLint, GLsizei, const GLint*))ext;
		glUniform2ivARB (a, b, c);
	}

	static void APIENTRY InitUniform3ivARB (GLint a, GLsizei b, const GLint *c)
		{
		void *ext = (void*)GETPROC ("glUniform3ivARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform3ivARB = (void (APIENTRY* ) (GLint, GLsizei, const GLint *))ext;
		glUniform3ivARB (a, b, c);
	}

	static void APIENTRY InitUniform4ivARB (GLint a, GLsizei b, const GLint *c)
		{
		void *ext = (void*)GETPROC ("glUniform4ivARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniform4ivARB = (void (APIENTRY* ) (GLint, GLsizei, const GLint *))ext;
		glUniform4ivARB (a, b, c);
	}

	static void APIENTRY InitUniformMatrix2fvARB (GLint a, GLsizei b, GLboolean c, const GLfloat *d)
		{
		void *ext = (void*)GETPROC ("glUniformMatrix2fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniformMatrix2fvARB = (void (APIENTRY* ) (GLint, GLsizei, GLboolean, const GLfloat *))ext;
		glUniformMatrix2fvARB (a, b, c, d);
	}

	static void APIENTRY InitUniformMatrix3fvARB (GLint a, GLsizei b, GLboolean c, const GLfloat *d)
	{
		void *ext = (void*)GETPROC ("glUniformMatrix3fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniformMatrix3fvARB = (void (APIENTRY* ) (GLint, GLsizei, GLboolean, const GLfloat *))ext;
		glUniformMatrix3fvARB (a, b, c, d);
	}

	static void APIENTRY InitUniformMatrix4fvARB (GLint a, GLsizei b, GLboolean c, const GLfloat *d)
	{
		void *ext = (void*)GETPROC ("glUniformMatrix4fvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glUniformMatrix4fvARB = (void (APIENTRY* ) (GLint, GLsizei, GLboolean, const GLfloat *))ext;
		glUniformMatrix4fvARB (a, b, c, d);
	}

	static void APIENTRY InitGetObjectParameterfvARB (GLhandleARB a, GLenum b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetObjectParameterfvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetObjectParameterfvARB = (void (APIENTRY* ) (GLhandleARB, GLenum, GLfloat *))ext;
		glGetObjectParameterfvARB (a, b, c);
	}

	static void APIENTRY InitGetObjectParameterivARB (GLhandleARB a, GLenum b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetObjectParameterivARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetObjectParameterivARB = (void (APIENTRY* ) (GLhandleARB, GLenum, GLint *))ext;
		glGetObjectParameterivARB (a, b, c);
	}

	static void APIENTRY InitGetInfoLogARB (GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d)
	{
		void *ext = (void*)GETPROC ("glGetInfoLogARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetInfoLogARB = (void (APIENTRY* ) (GLhandleARB, GLsizei, GLsizei*, GLcharARB*))ext;
		glGetInfoLogARB (a, b, c, d);
	}

	static void APIENTRY InitGetAttachedObjectsARB (GLhandleARB a, GLsizei b, GLsizei *c, GLhandleARB *d)
	{
		void *ext = (void*)GETPROC ("glGetAttachedObjectsARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetAttachedObjectsARB = (void (APIENTRY* ) (GLhandleARB, GLsizei, GLsizei*, GLhandleARB*))ext;
		glGetAttachedObjectsARB (a, b, c, d);
	}

	static GLint APIENTRY InitGetUniformLocationARB (GLhandleARB a, const GLcharARB *b)
	{
		void *ext = (void*)GETPROC ("glGetUniformLocationARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return 0;
		}

		glGetUniformLocationARB = (GLint (APIENTRY* ) (GLhandleARB, const GLcharARB*))ext;
		return glGetUniformLocationARB (a, b);
	}

	static void APIENTRY InitGetActiveUniformARB (GLhandleARB a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLcharARB *g)
	{
		void *ext = (void*)GETPROC ("glGetActiveUniformARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetActiveUniformARB = (void (APIENTRY* ) (GLhandleARB, GLuint, GLsizei, GLsizei*, GLint*, GLenum *, GLcharARB*))ext;
		glGetActiveUniformARB (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitGetUniformfvARB (GLhandleARB a, GLint b, GLfloat *c)
	{
		void *ext = (void*)GETPROC ("glGetUniformfvARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetUniformfvARB = (void (APIENTRY* ) (GLhandleARB, GLint,  GLfloat *))ext;
		glGetUniformfvARB (a, b, c);
	}

	static void APIENTRY InitGetUniformivARB (GLhandleARB a, GLint b, GLint *c)
	{
		void *ext = (void*)GETPROC ("glGetUniformivARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetUniformivARB = (void (APIENTRY* ) (GLhandleARB, GLint, GLint*))ext;
		glGetUniformivARB (a, b, c);
	}

	static void APIENTRY InitGetShaderSourceARB (GLhandleARB a, GLsizei b, GLsizei *c, GLcharARB *d)
	{
		void *ext = (void*)GETPROC ("glGetShaderSourceARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetShaderSourceARB = (void (APIENTRY* ) (GLhandleARB, GLsizei, GLsizei*, GLcharARB*))ext;
		glGetShaderSourceARB (a, b, c, d);
	}

	//GL_ARB_vertex_shader
	static void APIENTRY InitBindAttribLocationARB (GLhandleARB a, GLuint b, const GLcharARB *c)
	{
		void *ext = (void*)GETPROC ("glBindAttribLocationARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glBindAttribLocationARB = (void (APIENTRY* ) (GLhandleARB, GLuint,  const GLcharARB*))ext;
		glBindAttribLocationARB (a, b, c);
	}

	static void APIENTRY InitGetActiveAttribARB (GLhandleARB a, GLuint b, GLsizei c, GLsizei *d, GLint *e, GLenum *f, GLcharARB *g)
	{
		void *ext = (void*)GETPROC ("glGetActiveAttribARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return;
		}

		glGetActiveAttribARB = (void (APIENTRY* ) (GLhandleARB, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLcharARB*))ext;
		glGetActiveAttribARB (a, b, c, d, e, f, g);
	}

	static int	APIENTRY InitGetAttribLocationARB (GLhandleARB a, const GLcharARB *b)
	{
		void *ext = (void*)GETPROC ("glGetAttribLocationARB");

		if (ext == NULL)
		{
			FILE *f = fopen ("ext-errors.txt", "w+");
			fprintf (f, "File: %s on line %i\n", __FILE__, __LINE__);
			fclose (f);
			return 0;
		}

		glGetAttribLocationARB = (int (APIENTRY* ) (GLhandleARB, const GLcharARB*))ext;
		return glGetAttribLocationARB (a, b);
	}

	//GL_ARB_draw_buffers
	static void APIENTRY InitDrawBuffersARB (GLsizei a, const GLenum *b)
	{
		void *ext = (void*)GETPROC ("glDrawBuffersARB");

		if (!ext)
			return;

		glDrawBuffersARB = (void (APIENTRY*) (GLsizei, const GLenum*))ext;
		glDrawBuffersARB (a, b);
	}

	//GL_ARB_texture_rectangle

	//GL_ARB_color_buffer_float
	static void APIENTRY InitClampColorARB (GLenum a, GLenum b)
	{
		void *ext = (void*)GETPROC ("glClampColorARB");

		if (!ext)
			return;

		glClampColorARB = (void (APIENTRY*) (GLenum, GLenum))ext;
		glClampColorARB (a, b);
	}

	//WGL_ARB_pixel_format_float
	//GLX_ARB_fbconfig_float
	//GL_ARB_half_float_pixel
	//GL_ARB_texture_float
	//GL_ARB_pixel_buffer_object 

	gsextarb _extarb = 
	{
#ifdef WIN32
		//WGL_ARB_buffer_region
		InitCreateBufferRegionARB,
		InitDeleteBufferRegionARB,
		InitSaveBufferRegionARB,
		InitRestoreBufferRegionARB,
#endif

		//GL_ARB_multisample
		InitSampleCoverageARB,

#ifdef WIN32
		//WGL_extensions_string
		InitGetExtensionsStringARB,
#endif

#ifdef WIN32
		//WGL_pixel_format
		InitGetPixelFormatAttribivARB,
		InitGetPixelFormatAttribfvARB,
		InitChoosePixelFormatARB,
#endif

#ifdef WIN32
		//WGL_make_current_read
		InitMakeContextCurrentARB,
		InitGetCurrentReadDCARB,
#endif

#ifdef WIN32
		//WGL_ARB_pbuffer
		InitwCreatePbufferARB,
		InitwGetPbufferDCARB,
		InitwReleasePbufferDCARB,
		InitwDestroyPbufferARB,
		InitwQueryPbufferARB,
#endif

		//GL_ARB_compressed_texture
		InitCompressedTexImage3DARB,
		InitCompressedTexImage2DARB,
		InitCompressedTexImage1DARB,
		InitCompressedTexSubImage3DARB,
		InitCompressedTexSubImage2DARB,
		InitCompressedTexSubImage1DARB,
		InitGetCompressedTexImageARB,

		//GL_ARB_point_parameters
		InitPointParameterfARB,
		InitPointParameterfvARB,

		//GL_ARB_vertex_blend
		InitWeightbvARB,
		InitWeightubvARB,
		InitWeightsvARB,
		InitWeightusvARB,
		InitWeightivARB,
		InitWeightuivARB,
		InitWeightfvARB,
		InitWeightdvARB,
		InitWeightPointerARB,
		InitVertexBlendARB,

		//GL_ARB_palette_matrix
		InitCurrentPaletteMatrixARB,
		InitMatrixIndexubvARB,
		InitMatrixIndexusvARB,
		InitMatrixIndexuivARB,
		InitMatrixIndexPointerARB,

#ifdef WIN32
		//GL_ARB_render_texture
		InitwBindTexImageARB,
		InitwReleaseTexImageARB,
		InitwSetPbufferAttribARB,
#endif

		//GL_ARB_window_pos
		InitWindowPos2dARB,
		InitWindowPos2fARB,
		InitWindowPos2iARB,
		InitWindowPos2sARB,
		InitWindowPos2dvARB,
		InitWindowPos2fvARB,
		InitWindowPos2ivARB,
		InitWindowPos2svARB,
		InitWindowPos3dARB,
		InitWindowPos3fARB,
		InitWindowPos3iARB,
		InitWindowPos3sARB,
		InitWindowPos3dvARB,
		InitWindowPos3fvARB,
		InitWindowPos3ivARB,
		InitWindowPos3svARB,

		//GL_ARB_vertex_program
		InitVertexAttrib1sARB,
		InitVertexAttrib1fARB,
		InitVertexAttrib1dARB,
		InitVertexAttrib2sARB,
		InitVertexAttrib2fARB,
		InitVertexAttrib2dARB,
		InitVertexAttrib3sARB,
		InitVertexAttrib3fARB,
		InitVertexAttrib3dARB,
		InitVertexAttrib4sARB,
		InitVertexAttrib4fARB,
		InitVertexAttrib4dARB,
		InitVertexAttrib4NubARB,
		InitVertexAttrib1svARB,
		InitVertexAttrib1fvARB,
		InitVertexAttrib1dvARB,
		InitVertexAttrib2svARB,
		InitVertexAttrib2fvARB,
		InitVertexAttrib2dvARB,
		InitVertexAttrib3svARB,
		InitVertexAttrib3fvARB,
		InitVertexAttrib3dvARB,
		InitVertexAttrib4bvARB,
		InitVertexAttrib4svARB,
		InitVertexAttrib4ivARB,
		InitVertexAttrib4ubvARB,
		InitVertexAttrib4usvARB,
		InitVertexAttrib4uivARB,
		InitVertexAttrib4fvARB,
		InitVertexAttrib4dvARB,
		InitVertexAttrib4NbvARB,
		InitVertexAttrib4NsvARB,
		InitVertexAttrib4NivARB,
		InitVertexAttrib4NubvARB,
		InitVertexAttrib4NusvARB,
		InitVertexAttrib4NuivARB,
		InitVertexAttribPointerARB,
		InitEnableVertexAttribArrayARB,
		InitDisableVertexAttribArrayARB,
		InitProgramStringARB,
		InitBindProgramARB,
		InitDeleteProgramsARB,
		InitGenProgramsARB,
		InitProgramEnvParameter4dARB,
		InitProgramEnvParameter4dvARB,
		InitProgramEnvParameter4fARB,
		InitProgramEnvParameter4fvARB,
		InitProgramLocalParameter4dARB,
		InitProgramLocalParameter4dvARB,
		InitProgramLocalParameter4fARB,
		InitProgramLocalParameter4fvARB,
		InitGetProgramEnvParameterdvARB,
		InitGetProgramEnvParameterfvARB,
		InitGetProgramLocalParameterdvARB,
		InitGetProgramLocalParameterfvARB,
		InitGetProgramivARB,
		InitGetProgramStringARB,
		InitGetVertexAttribdvARB,
		InitGetVertexAttribfvARB,
		InitGetVertexAttribivARB,
		InitGetVertexAttribPointervARB,
		InitIsProgramARB,

		//GL_ARB_fragment_program

		//GL_ARB_vertex_buffer_object
		InitBindBufferARB,
		InitDeleteBuffersARB,
		InitGenBuffersARB,
		InitIsBufferARB,
		InitBufferDataARB,
		InitBufferSubDataARB,
		InitGetBufferSubDataARB,
		InitMapBufferARB,
		InitUnmapBufferARB,
		InitGetBufferParameterivARB,
		InitGetBufferPointervARB,

		//GL_ARB_occlusion_query
		InitGenQueriesARB,
		InitDeleteQueriesARB,
		InitIsQueryARB,
		InitBeginQueryARB,
		InitEndQueryARB,
		InitGetQueryivARB,
		InitGetQueryObjectivARB,
		InitGetQueryObjectuivARB,

		//GL_ARB_shader_objects
		InitDeleteObjectARB,
		InitGetHandleARB,
		InitDetachObjectARB,
		InitCreateShaderObjectARB,
		InitShaderSourceARB,
		InitCompileShaderARB,
		InitCreateProgramObjectARB,
		InitAttachObjectARB,
		InitLinkProgramARB,
		InitUseProgramObjectARB,
		InitValidateProgramARB,
		InitUniform1fARB,
		InitUniform2fARB,
		InitUniform3fARB,
		InitUniform4fARB,
		InitUniform1iARB,
		InitUniform2iARB,
		InitUniform3iARB,
		InitUniform4iARB,
		InitUniform1fvARB,
		InitUniform2fvARB,
		InitUniform3fvARB,
		InitUniform4fvARB,
		InitUniform1ivARB,
		InitUniform2ivARB,
		InitUniform3ivARB,
		InitUniform4ivARB,
		InitUniformMatrix2fvARB,
		InitUniformMatrix3fvARB,
		InitUniformMatrix4fvARB,
		InitGetObjectParameterfvARB,
		InitGetObjectParameterivARB,
		InitGetInfoLogARB,
		InitGetAttachedObjectsARB,
		InitGetUniformLocationARB,
		InitGetActiveUniformARB,
		InitGetUniformfvARB,
		InitGetUniformivARB,
		InitGetShaderSourceARB,

		//GL_ARB_vertex_shader
		InitBindAttribLocationARB,
		InitGetActiveAttribARB,
		InitGetAttribLocationARB,

		//GL_ARB_draw_buffers
		InitDrawBuffersARB,

		//GL_ARB_texture_rectangle

		//GL_ARB_color_buffer_float
		InitClampColorARB

		//WGL_ARB_pixel_format_float
		//GLX_ARB_fbconfig_float
		//GL_ARB_half_float_pixel
		//GL_ARB_texture_float
		//GL_ARB_pixel_buffer_object 
	};

	//GL_EXT_blend_color
	static void APIENTRY InitBlendColorEXT (GLclampf a, GLclampf b, GLclampf c, GLclampf d)
	{
		void *ext = (void*)GETPROC ("glBlendColorEXT");

		if (!ext)
			return;

		glBlendColorEXT = (void (APIENTRY*) (GLclampf, GLclampf, GLclampf, GLclampf))ext;
		glBlendColorEXT (a, b, c, d);
	}

	//GL_EXT_polygon_offset
	static void APIENTRY InitPolygonOffsetEXT (float a, float b)
	{
		void *ext = (void*)GETPROC ("glPolygonOffsetEXT");

		if (!ext)
			return;

		glPolygonOffsetEXT = (void (APIENTRY*) (float, float))ext;
		glPolygonOffsetEXT (a, b);
	}

	//GL_EXT_texture3d
	static void APIENTRY InitTexImage3DEXT (GLenum a, int b, GLenum c, GLsizei d, GLsizei e, GLsizei f, int g, GLenum h, GLenum i, const void* j)
	{
		void *ext = (void*)GETPROC ("glTexImage3DEXT");

		if (!ext)
			return;

		glTexImage3DEXT = (void (APIENTRY*) (GLenum, int, GLenum, GLsizei, GLsizei, GLsizei, int, GLenum, GLenum, const void *))ext;
		glTexImage3DEXT (a, b, c, d, e, f, g, h, i, j);
	}

	//GL_EXT_texture_filter4
	//void TexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const float* weights);
	//void GetTexFilterFuncSGIS(GLenum target, GLenum filter, float* weights);

	//GL_EXT_subtexture
	static void APIENTRY InitTexSubImage1DEXT (GLenum a, int b, int c, GLsizei d, GLenum e, GLenum f, const void *g)
	{
		void *ext = (void*)GETPROC ("glTexSubImage1DEXT");

		if (!ext)
			return;

		glTexSubImage1DEXT = (void (APIENTRY*) (GLenum, int, int, GLsizei, GLenum, GLenum, const void *))ext;
		glTexSubImage1DEXT (a, b, c, d, e, f, g);
	}

	static void APIENTRY InitTexSubImage2DEXT (GLenum a, int b, int c, int d, GLsizei e, GLsizei f, GLenum g, GLenum h, const void *i)
	{
		void *ext = (void*)GETPROC ("glTexSubImage2DEXT");

		if (!ext)
			return;

		glTexSubImage2DEXT = (void (APIENTRY*) (GLenum, int, int, int, GLsizei, GLsizei, GLenum, GLenum, const void *))ext;
		glTexSubImage2DEXT (a, b, c, d, e, f, g, h, i);
	}

	static void APIENTRY InitTexSubImage3DEXT (GLenum a, int b, int c, int d, int e, GLsizei f, GLsizei g, GLsizei h, GLenum i, GLenum j, const void *k)
	{
		void *ext = (void*)GETPROC ("glTexSubImage3DEXT");

		if (!ext)
			return;

		glTexSubImage3DEXT = (void (APIENTRY*) (GLenum, int, int, int, int, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))ext;
		glTexSubImage3DEXT (a, b, c, d, e, f, g, h, i, j, k);
	}

	//GL_EXT_paletted_texture
	static void APIENTRY InitColorTableEXT (GLenum a, GLenum b, GLsizei c, GLenum d, GLenum e, const void *f)
	{
		void *ext = (void*)GETPROC ("glColorTableEXT");

		if (!ext)
			return;

		glColorTableEXT = (void (APIENTRY*) (GLenum, GLenum, GLsizei, GLenum, GLenum, const void *))ext;
		glColorTableEXT (a, b, c, d, e, f);
	}

	static void APIENTRY InitGetColorTableEXT (GLenum a, GLenum b, GLenum c, void *d)
	{
		void *ext = (void*)GETPROC ("glGetColorTableEXT");

		if (!ext)
			return;

		glGetColorTableEXT = (void (APIENTRY*) (GLenum, GLenum, GLenum, void *))ext;
		glGetColorTableEXT (a, b, c, d);
	}

	static void APIENTRY InitGetColorTableParameterivEXT (GLenum a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetColorTableParameterivEXT");

		if (!ext)
			return;

		glGetColorTableParameterivEXT = (void (APIENTRY*) (GLenum, GLenum, int *))ext;
		glGetColorTableParameterivEXT (a, b, c);
	}

	static void APIENTRY InitGetColorTableParameterfvEXT (GLenum a, GLenum b, float *c)
	{
		void *ext = (void*)GETPROC ("glGetColorTableParameterfvEXT");

		if (!ext)
			return;

		glGetColorTableParameterfvEXT = (void (APIENTRY*) (GLenum, GLenum, float *))ext;
		glGetColorTableParameterfvEXT (a, b, c);
	}

	static bool APIENTRY InitIsRenderbufferEXT (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsRenderbufferEXT");

		if (!ext)
			return false;

		glIsRenderbufferEXT = (bool (APIENTRY*) (GLuint))ext;
		return glIsRenderbufferEXT (a);
	}

	static void APIENTRY InitBindRenderbufferEXT (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBindRenderbufferEXT");

		if (!ext)
			return;

		glBindRenderbufferEXT = (void (APIENTRY*) (GLenum, GLuint))ext;
		glBindRenderbufferEXT (a, b);
	}

	static void APIENTRY InitDeleteRenderbuffersEXT (GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteRenderbuffersEXT");

		if (!ext)
			return;

		glDeleteRenderbuffersEXT = (void (APIENTRY*) (GLsizei, const GLuint*))ext;
		glDeleteRenderbuffersEXT (a, b);
	}

	static void APIENTRY InitGenRenderbuffersEXT (GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenRenderbuffersEXT");

		if (!ext)
			return;

		glGenRenderbuffersEXT = (void (APIENTRY*) (GLsizei, GLuint*))ext;
		return glGenRenderbuffersEXT (a, b);
	}

	static void APIENTRY InitRenderbufferStorageEXT (GLenum a, GLenum b, GLsizei c, GLsizei d)
	{
		void *ext = (void*)GETPROC ("glRenderbufferStorageEXT");

		if (!ext)
			return;

		glRenderbufferStorageEXT = (void (APIENTRY*) (GLenum, GLenum, GLsizei, GLsizei))ext;
		return glRenderbufferStorageEXT (a, b, c, d);
	}

	static void APIENTRY InitGetRenderbufferParameterivEXT (GLenum a, GLenum b, int *c)
	{
		void *ext = (void*)GETPROC ("glGetRenderbufferParameterivEXT");

		if (!ext)
			return;

		glGetRenderbufferParameterivEXT = (void (APIENTRY*) (GLenum, GLenum, int*))ext;
		return glGetRenderbufferParameterivEXT (a, b, c);
	}

	static bool APIENTRY InitIsFramebufferEXT (GLuint a)
	{
		void *ext = (void*)GETPROC ("glIsFramebufferEXT");

		if (!ext)
			return false;

		glIsFramebufferEXT = (bool (APIENTRY*) (GLuint))ext;
		return glIsFramebufferEXT (a);
	}

	static void APIENTRY InitBindFramebufferEXT (GLenum a, GLuint b)
	{
		void *ext = (void*)GETPROC ("glBindFramebufferEXT");

		if (!ext)
			return;

		glBindFramebufferEXT = (void (APIENTRY*) (GLenum, GLuint))ext;
		glBindFramebufferEXT (a, b);
	}

	static void APIENTRY InitDeleteFramebuffersEXT (GLsizei a, const GLuint *b)
	{
		void *ext = (void*)GETPROC ("glDeleteFramebuffersEXT");

		if (!ext)
			return;

		glDeleteFramebuffersEXT = (void (APIENTRY*) (GLsizei, const GLuint*))ext;
		glDeleteFramebuffersEXT (a, b);
	}

	static void APIENTRY InitGenFramebuffersEXT (GLsizei a, GLuint *b)
	{
		void *ext = (void*)GETPROC ("glGenFramebuffersEXT");

		if (!ext)
			return;

		glGenFramebuffersEXT = (void (APIENTRY*) (GLsizei, GLuint*))ext;
		glGenFramebuffersEXT (a, b);
	}

	static GLenum APIENTRY InitCheckFramebufferStatusEXT (GLenum a)
	{
		void *ext = (void*)GETPROC ("glCheckFramebufferStatusEXT");

		if (!ext)
			return 0;

		glCheckFramebufferStatusEXT = (GLenum (APIENTRY*) (GLenum))ext;
		return glCheckFramebufferStatusEXT (a);
	}

	static void APIENTRY InitFramebufferTexture1DEXT (GLenum a, GLenum b, GLenum c, GLuint d, int e)
	{
		void *ext = (void*)GETPROC ("glFramebufferTexture1DEXT");

		if (!ext)
			return;

		glFramebufferTexture1DEXT = (void (APIENTRY*) (GLenum, GLenum, GLenum, GLuint, int))ext;
		glFramebufferTexture1DEXT (a, b, c, d, e);
	}

	static void APIENTRY InitFramebufferTexture2DEXT (GLenum a, GLenum b, GLenum c, GLuint d, int e)
	{
		void *ext = (void*)GETPROC ("glFramebufferTexture2DEXT");

		if (!ext)
			return;

		glFramebufferTexture2DEXT = (void (APIENTRY*) (GLenum, GLenum, GLenum, GLuint, int))ext;
		glFramebufferTexture2DEXT (a, b, c, d, e);
	}

	static void APIENTRY InitFramebufferTexture3DEXT (GLenum a, GLenum b, GLenum c, GLuint d, int e, int f)
	{
		void *ext = (void*)GETPROC ("glFramebufferTexture3DEXT");

		if (!ext)
			return;

		glFramebufferTexture3DEXT = (void (APIENTRY*) (GLenum, GLenum, GLenum, GLuint, int, int))ext;
		glFramebufferTexture3DEXT (a, b, c, d, e, f);
	}

	static void APIENTRY InitFramebufferRenderbufferEXT (GLenum a, GLenum b, GLenum c, GLuint d)
	{
		void *ext = (void*)GETPROC ("glFramebufferRenderbufferEXT");

		if (!ext)
			return;

		glFramebufferRenderbufferEXT = (void (APIENTRY*) (GLenum, GLenum, GLenum, GLuint))ext;
		glFramebufferRenderbufferEXT (a, b, c, d);
	}

	static void APIENTRY InitGetFramebufferAttachmentParameterivEXT (GLenum a, GLenum b, GLenum c, int *d)
	{
		void *ext = (void*)GETPROC ("glGetFramebufferAttachmentParameterivEXT");

		if (!ext)
			return;

		glGetFramebufferAttachmentParameterivEXT = (void (APIENTRY*) (GLenum, GLenum, GLenum, int*))ext;
		glGetFramebufferAttachmentParameterivEXT (a, b, c, d);
	}

	static void APIENTRY InitGenerateMipmapEXT (GLenum a)
	{
		void *ext = (void*)GETPROC ("glGenerateMipmapEXT");

		if (!ext)
			return;

		glGenerateMipmapEXT = (void (APIENTRY*) (GLenum))ext;
		glGenerateMipmapEXT (a);
	}

	gsextext _extext =
	{
		//GL_EXT_blend_color
		InitBlendColorEXT,

		//GL_EXT_polygon_offset
		InitPolygonOffsetEXT,

		//GL_EXT_texture3d
		InitTexImage3DEXT,

		//GL_EXT_texture_filter4
		//void TexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const float* weights);
		//void GetTexFilterFuncSGIS(GLenum target, GLenum filter, float* weights);

		//GL_EXT_subtexture
		InitTexSubImage1DEXT,
		InitTexSubImage2DEXT,
		InitTexSubImage3DEXT,

		//GL_EXT_paletted_texture
		InitColorTableEXT,
		InitGetColorTableEXT,
		InitGetColorTableParameterivEXT,
		InitGetColorTableParameterfvEXT,

		//GL_EXT_framebuffer_object
		InitIsRenderbufferEXT,
		InitBindRenderbufferEXT,
		InitDeleteRenderbuffersEXT,
		InitGenRenderbuffersEXT,
		InitRenderbufferStorageEXT,
		InitGetRenderbufferParameterivEXT,
		InitIsFramebufferEXT,
		InitBindFramebufferEXT,
		InitDeleteFramebuffersEXT,
		InitGenFramebuffersEXT,
		InitCheckFramebufferStatusEXT,
		InitFramebufferTexture1DEXT,
		InitFramebufferTexture2DEXT,
		InitFramebufferTexture3DEXT,
		InitFramebufferRenderbufferEXT,
		InitGetFramebufferAttachmentParameterivEXT,
		InitGenerateMipmapEXT,
	};

	gsutil::gsstring ext;
	gsutil::gsstring ARBext;
	gsutil::gsstring EXText;

	void initExtensions ()
	{
		//gsutil::gsstring vendor = (char*)glGetString (GL_VENDOR);
		//gsutil::gsstring renderer = (char*)glGetString (GL_RENDERER);
		//gsutil::gsstring version = (char*)glGetString (GL_VERSION);
		//ext = (char*)glGetString (GL_EXTENSIONS);

		//Extracting all the extensions and defining the appropriate extensions.
		//We will also keep what extensions are defined for our renderer, so it can
		//appropriate the right function calls

		//ARBext = wglGetExtensionsStringARB (hdc);

		//EXText = glGetEx
	}

	gsutil::gsstring getExtensions ()
	{
		return ext;
	}

	gsutil::gsstring getARBExtensions ()
	{
		return ARBext;
	}

	gsutil::gsstring getEXTExtensions ()
	{
		return EXText;
	}
};
