#include "main.h"

#include <gsutil/gsarray.h>

#include <gswindow/gsbox.h>
#include <gswindow/gstextbox.h>

#include <gsgfx/gl/glenums.h>
#include <gsgfx/gl/gsext.h>

class window : public gswin::gswindow
{
public:
	window () : gswindow (0, "window", "Test", 0, 0, 0, 800, 600)
	{
		gswin::gsbox *b = new gswin::gsbox (gswin::gsVERTICAL, this);
		b->add (new gswin::gstextbox (this, "Please email the generated textfile back to bhittle@osc.edu"));

		gsutil::gsarray <PIXELFORMATDESCRIPTOR> pfl;
		HDC hdc = GetDC (getHandle ());
		int index = 1;
		bool cont = true;
		while (cont)
		{
			PIXELFORMATDESCRIPTOR pfd;
			if (!DescribePixelFormat (hdc, index, sizeof (PIXELFORMATDESCRIPTOR), &pfd))
				cont = false;
			else
			{
				pfl.add (pfd);
				index ++;
			}
		}

		PIXELFORMATDESCRIPTOR pf;
		DescribePixelFormat (hdc, 1, sizeof (PIXELFORMATDESCRIPTOR), &pf);
		SetPixelFormat (hdc, 1, &pf);

		HGLRC hglrc = wglCreateContext (hdc);
		wglMakeCurrent (hdc, hglrc);

		if (glGetString (GL_RENDERER) != 0)
		{
			gsutil::gsstring card = (char*)glGetString (GL_RENDERER);
			gsutil::gsstring file = card.substring (0, card.find ('/')).str ();
			file += ".txt";
			FILE *f = fopen (file.str (), "w+");

			if (f)
			{
				gsutil::gsstring vendor = (char*)glGetString (GL_VENDOR);
				gsutil::gsstring version = (char*)glGetString (GL_VERSION);
	
				gsutil::gsstring ext = (char*)glGetString (GL_EXTENSIONS);
				//gsutil::gsstring arb = (char*)glGetExtensionsStringARB ();
				//gsutil::gsstring EXT = (char*)glGetExtensionsStringEXT ();

				fprintf (f, "Vendor: %s\n", vendor.str ());
				fprintf (f, "Renderer: %s\n", card.str ());
				fprintf (f, "Version: %s\n", version.str ());
				fprintf (f, "Extensions:\n");
				while (ext.size () > 0)
				{
					fprintf (f, "\t%s\n", ext.substring (0, ext.find (' ')));
					ext.remove (0, ext.find (' ') + 1);
				}

				fprintf (f, "\n\nTable of possible pixel formats:\n");
				fprintf (f, " ________________________________ \n");
				fprintf (f, "/ Bits | Depth | Stencil | Accum \\\n");

				for (unsigned int x = 0; x < pfl.getSize (); x++)
				{
					char tmp[100];
					itoa (pfl[x].cColorBits, tmp, 10);
					gsutil::gsstring bits = tmp;
					while (bits.size () < 4)
					{
						gsutil::gsstring temp;
						temp += " ";
						temp += bits;
						bits = temp;
					}

					itoa (pfl[x].cDepthBits, tmp, 10);
					gsutil::gsstring depth = tmp;
					while (depth.size () < 5)
					{
						gsutil::gsstring temp;
						temp += " ";
						temp += depth;
						depth = temp;
					}

					itoa (pfl[x].cStencilBits, tmp, 10);
					gsutil::gsstring stencil = tmp;
					while (stencil.size () < 7)
					{
						gsutil::gsstring temp;
						temp += " ";
						temp += stencil;
						stencil = temp;
					}

					itoa (pfl[x].cAccumBits, tmp, 10);
					gsutil::gsstring accum = tmp;
					while (accum.size () < 5)
					{
						gsutil::gsstring temp;
						temp += " ";
						temp += accum;
						accum = temp;
					}

					fprintf (f, "| %s | %s | %s | %s |\n", bits.str (), depth.str (), stencil.str (), accum.str ());
				}

				fprintf (f, "\\      |       |         |       /\n");
				fprintf (f, " ________________________________ \n");

				gsutil::gsarray <gsutil::gsstring> specList, arbList, extList, cantDo;
				fprintf (f, "\n\nTrying all opengl functions:\n");
				fprintf (f, "OpenGL 1.2\n");
				lookup ("glBlendColor", &specList, &cantDo);
				lookup ("glBlendEquation", &specList, &cantDo);
				lookup ("glDrawRangeElements", &specList, &cantDo);
				lookup ("glColorTable", &specList, &cantDo);
				lookup ("glColorTableParameterfv", &specList, &cantDo);
				lookup ("glColorTableParameteriv", &specList, &cantDo);
				lookup ("glCopyColorTable", &specList, &cantDo);
				lookup ("glGetColorTable", &specList, &cantDo);
				lookup ("glGetColorTableParameterfv", &specList, &cantDo);
				lookup ("glGetColorTableParameteriv", &specList, &cantDo);
				lookup ("glColorSubTable", &specList, &cantDo);
				lookup ("glCopyColorSubTable", &specList, &cantDo);
				lookup ("glConvolutionFilter1D", &specList, &cantDo);
				lookup ("glConvolutionFilter2D", &specList, &cantDo);
				lookup ("glConvolutionParameterf", &specList, &cantDo);
				lookup ("glConvolutionParameterfv", &specList, &cantDo);
				lookup ("glConvolutionParameteri", &specList, &cantDo);
				lookup ("glConvolutionParameteriv", &specList, &cantDo);
				lookup ("glCopyConvolutionFilter1D", &specList, &cantDo);
				lookup ("glCopyConvolutionFilter2D", &specList, &cantDo);
				lookup ("glGetConvolutionFilter", &specList, &cantDo);
				lookup ("glGetConvolutionParameterfv", &specList, &cantDo);
				lookup ("glGetConvolutionParameteriv", &specList, &cantDo);
				lookup ("glGetSeparableFilter", &specList, &cantDo);
				lookup ("glSeparableFilter2D", &specList, &cantDo);
				lookup ("glGetHistogram", &specList, &cantDo);
				lookup ("glGetHistogramParameterfv", &specList, &cantDo);
				lookup ("glGetHistogramParameteriv", &specList, &cantDo);
				lookup ("glGetMinmax", &specList, &cantDo);
				lookup ("glGetMinmaxParameterfv", &specList, &cantDo);
				lookup ("glGetMinmaxParameteriv", &specList, &cantDo);
				lookup ("glHistogram", &specList, &cantDo);
				lookup ("glMinmax", &specList, &cantDo);
				lookup ("glResetHistogram", &specList, &cantDo);
				lookup ("glResetMinmax", &specList, &cantDo);
				lookup ("glTexImage3D", &specList, &cantDo);
				lookup ("glTexSubImage3D", &specList, &cantDo);
				lookup ("glCopyTexSubImage3D", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				fprintf (f, "\nOpenGL 1.3\n");
				lookup ("glActiveTexture", &specList, &cantDo);
				lookup ("glClientActiveTexture", &specList, &cantDo);
				lookup ("glMultiTexCoord1d", &specList, &cantDo);
				lookup ("glMultiTexCoord1dv", &specList, &cantDo);
				lookup ("glMultiTexCoord1f", &specList, &cantDo);
				lookup ("glMultiTexCoord1fv", &specList, &cantDo);
				lookup ("glMultiTexCoord1i", &specList, &cantDo);
				lookup ("glMultiTexCoord1iv", &specList, &cantDo);
				lookup ("glMultiTexCoord1s", &specList, &cantDo);
				lookup ("glMultiTexCoord1sv", &specList, &cantDo);
				lookup ("glMultiTexCoord2d", &specList, &cantDo);
				lookup ("glMultiTexCoord2dv", &specList, &cantDo);
				lookup ("glMultiTexCoord2f", &specList, &cantDo);
				lookup ("glMultiTexCoord2fv", &specList, &cantDo);
				lookup ("glMultiTexCoord2i", &specList, &cantDo);
				lookup ("glMultiTexCoord2iv", &specList, &cantDo);
				lookup ("glMultiTexCoord2s", &specList, &cantDo);
				lookup ("glMultiTexCoord2sv", &specList, &cantDo);
				lookup ("glMultiTexCoord3d", &specList, &cantDo);
				lookup ("glMultiTexCoord3dv", &specList, &cantDo);
				lookup ("glMultiTexCoord3f", &specList, &cantDo);
				lookup ("glMultiTexCoord3fv", &specList, &cantDo);
				lookup ("glMultiTexCoord3i", &specList, &cantDo);
				lookup ("glMultiTexCoord3iv", &specList, &cantDo);
				lookup ("glMultiTexCoord3s", &specList, &cantDo);
				lookup ("glMultiTexCoord3sv", &specList, &cantDo);
				lookup ("glMultiTexCoord4d", &specList, &cantDo);
				lookup ("glMultiTexCoord4dv", &specList, &cantDo);
				lookup ("glMultiTexCoord4f", &specList, &cantDo);
				lookup ("glMultiTexCoord4fv", &specList, &cantDo);
				lookup ("glMultiTexCoord4i", &specList, &cantDo);
				lookup ("glMultiTexCoord4iv", &specList, &cantDo);
				lookup ("glMultiTexCoord4s", &specList, &cantDo);
				lookup ("glMultiTexCoord4sv", &specList, &cantDo);
				lookup ("glLoadTransposeMatrixf", &specList, &cantDo);
				lookup ("glLoadTransposeMatrixd", &specList, &cantDo);
				lookup ("glMultTransposeMatrixf", &specList, &cantDo);
				lookup ("glMultTransposeMatrixd", &specList, &cantDo);
				lookup ("glSampleCoverage", &specList, &cantDo);
				lookup ("glCompressedTexImage3D", &specList, &cantDo);
				lookup ("glCompressedTexImage2D", &specList, &cantDo);
				lookup ("glCompressedTexImage1D", &specList, &cantDo);
				lookup ("glCompressedTexSubImage3D", &specList, &cantDo);
				lookup ("glCompressedTexSubImage2D", &specList, &cantDo);
				lookup ("glCompressedTexSubImage1D", &specList, &cantDo);
				lookup ("glGetCompressedTexImage", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				fprintf (f, "\nOpenGL 1.4\n");
				lookup ("glBlendFuncSeparate", &specList, &cantDo);
				lookup ("glFogCoordf", &specList, &cantDo);
				lookup ("glFogCoordfv", &specList, &cantDo);
				lookup ("glFogCoordd", &specList, &cantDo);
				lookup ("glFogCoorddv", &specList, &cantDo);
				lookup ("glFogCoordPointer", &specList, &cantDo);
				lookup ("glMultiDrawArrays", &specList, &cantDo);
				lookup ("glMultiDrawElements", &specList, &cantDo);
				lookup ("glPointParameterf", &specList, &cantDo);
				lookup ("glPointParameterfv", &specList, &cantDo);
				lookup ("glPointParameteri", &specList, &cantDo);
				lookup ("glPointParameteriv", &specList, &cantDo);
				lookup ("glSecondaryColor3b", &specList, &cantDo);
				lookup ("glSecondaryColor3bv", &specList, &cantDo);
				lookup ("glSecondaryColor3d", &specList, &cantDo);
				lookup ("glSecondaryColor3dv", &specList, &cantDo);
				lookup ("glSecondaryColor3f", &specList, &cantDo);
				lookup ("glSecondaryColor3fv", &specList, &cantDo);
				lookup ("glSecondaryColor3i", &specList, &cantDo);
				lookup ("glSecondaryColor3iv", &specList, &cantDo);
				lookup ("glSecondaryColor3s", &specList, &cantDo);
				lookup ("glSecondaryColor3sv", &specList, &cantDo);
				lookup ("glSecondaryColor3ub", &specList, &cantDo);
				lookup ("glSecondaryColor3ubv", &specList, &cantDo);
				lookup ("glSecondaryColor3ui", &specList, &cantDo);
				lookup ("glSecondaryColor3uiv", &specList, &cantDo);
				lookup ("glSecondaryColor3us", &specList, &cantDo);
				lookup ("glSecondaryColor3usv", &specList, &cantDo);
				lookup ("glSecondaryColorPointer", &specList, &cantDo);
				lookup ("glWindowPos2d", &specList, &cantDo);
				lookup ("glWindowPos2dv", &specList, &cantDo);
				lookup ("glWindowPos2f", &specList, &cantDo);
				lookup ("glWindowPos2fv", &specList, &cantDo);
				lookup ("glWindowPos2i", &specList, &cantDo);
				lookup ("glWindowPos2iv", &specList, &cantDo);
				lookup ("glWindowPos2s", &specList, &cantDo);
				lookup ("glWindowPos2sv", &specList, &cantDo);
				lookup ("glWindowPos3d", &specList, &cantDo);
				lookup ("glWindowPos3dv", &specList, &cantDo);
				lookup ("glWindowPos3f", &specList, &cantDo);
				lookup ("glWindowPos3fv", &specList, &cantDo);
				lookup ("glWindowPos3i", &specList, &cantDo);
				lookup ("glWindowPos3iv", &specList, &cantDo);
				lookup ("glWindowPos3s", &specList, &cantDo);
				lookup ("glWindowPos3sv", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				fprintf (f, "\nOpenGL 1.5\n");
				lookup ("glGenQueries", &specList, &cantDo);
				lookup ("glDeleteQueries", &specList, &cantDo);
				lookup ("glIsQuery", &specList, &cantDo);
				lookup ("glBeginQuery", &specList, &cantDo);
				lookup ("glEndQuery", &specList, &cantDo);
				lookup ("glGetQueryiv", &specList, &cantDo);
				lookup ("glGetQueryObjectiv", &specList, &cantDo);
				lookup ("glGetQueryObjectuiv", &specList, &cantDo);
				lookup ("glBindBuffer", &specList, &cantDo);
				lookup ("glDeleteBuffers", &specList, &cantDo);
				lookup ("glGenBuffers", &specList, &cantDo);
				lookup ("glIsBuffer", &specList, &cantDo);
				lookup ("glBufferData", &specList, &cantDo);
				lookup ("glBufferSubData", &specList, &cantDo);
				lookup ("glGetBufferSubData", &specList, &cantDo);
				lookup ("glMapBuffer", &specList, &cantDo);
				lookup ("glUnmapBuffer", &specList, &cantDo);
				lookup ("glGetBufferParameteriv", &specList, &cantDo);
				lookup ("glGetBufferPointerv", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				fprintf (f, "\nOpenGL 2.0\n");
				lookup ("glBlendEquationSeparate", &specList, &cantDo);
				lookup ("glDrawBuffers", &specList, &cantDo);
				lookup ("glStencilOpSeparate", &specList, &cantDo);
				lookup ("glStencilFuncSeparate", &specList, &cantDo);
				lookup ("glStencilMaskSeparate", &specList, &cantDo);
				lookup ("glAttachShader", &specList, &cantDo);
				lookup ("glBindAttribLocation", &specList, &cantDo);
				lookup ("glCompileShader", &specList, &cantDo);
				lookup ("glCreateProgram", &specList, &cantDo);
				lookup ("glCreateShader", &specList, &cantDo);
				lookup ("glDeleteProgram", &specList, &cantDo);
				lookup ("glDeleteShader", &specList, &cantDo);
				lookup ("glDetachShader", &specList, &cantDo);
				lookup ("glDisableVertexAttribArray", &specList, &cantDo);
				lookup ("glEnableVertexAttribArray", &specList, &cantDo);
				lookup ("glGetActiveAttrib", &specList, &cantDo);
				lookup ("glGetActiveUniform", &specList, &cantDo);
				lookup ("glGetAttachedShaders", &specList, &cantDo);
				lookup ("glGetAttribLocation", &specList, &cantDo);
				lookup ("glGetProgramiv", &specList, &cantDo);
				lookup ("glGetProgramInfoLog", &specList, &cantDo);
				lookup ("glGetShaderiv", &specList, &cantDo);
				lookup ("glGetShaderInfoLog", &specList, &cantDo);
				lookup ("glGetShaderSource", &specList, &cantDo);
				lookup ("glGetUniformLocation", &specList, &cantDo);
				lookup ("glGetUniformfv", &specList, &cantDo);
				lookup ("glGetUniformiv", &specList, &cantDo);
				lookup ("glGetVertexAttribdv", &specList, &cantDo);
				lookup ("glGetVertexAttribfv", &specList, &cantDo);
				lookup ("glGetVertexAttribiv", &specList, &cantDo);
				lookup ("glGetVertexAttribPointerv", &specList, &cantDo);
				lookup ("glIsProgram", &specList, &cantDo);
				lookup ("glIsShader", &specList, &cantDo);
				lookup ("glLinkProgram", &specList, &cantDo);
				lookup ("glShaderSource", &specList, &cantDo);
				lookup ("glUseProgram", &specList, &cantDo);
				lookup ("glUniform1f", &specList, &cantDo);
				lookup ("glUniform2f", &specList, &cantDo);
				lookup ("glUniform3f", &specList, &cantDo);
				lookup ("glUniform4f", &specList, &cantDo);
				lookup ("glUniform1i", &specList, &cantDo);
				lookup ("glUniform2i", &specList, &cantDo);
				lookup ("glUniform3i", &specList, &cantDo);
				lookup ("glUniform4i", &specList, &cantDo);
				lookup ("glUniform1fv", &specList, &cantDo);
				lookup ("glUniform2fv", &specList, &cantDo);
				lookup ("glUniform3fv", &specList, &cantDo);
				lookup ("glUniform4fv", &specList, &cantDo);
				lookup ("glUniform1iv", &specList, &cantDo);
				lookup ("glUniform2iv", &specList, &cantDo);
				lookup ("glUniform3iv", &specList, &cantDo);
				lookup ("glUniform4iv", &specList, &cantDo);
				lookup ("glUniformMatrix2fv", &specList, &cantDo);
				lookup ("glUniformMatrix3fv", &specList, &cantDo);
				lookup ("glUniformMatrix4fv", &specList, &cantDo);
				lookup ("glValidateProgram", &specList, &cantDo);
				lookup ("glVertexAttrib1d", &specList, &cantDo);
				lookup ("glVertexAttrib1dv", &specList, &cantDo);
				lookup ("glVertexAttrib1f", &specList, &cantDo);
				lookup ("glVertexAttrib1fv", &specList, &cantDo);
				lookup ("glVertexAttrib1s", &specList, &cantDo);
				lookup ("glVertexAttrib1sv", &specList, &cantDo);
				lookup ("glVertexAttrib2d", &specList, &cantDo);
				lookup ("glVertexAttrib2dv", &specList, &cantDo);
				lookup ("glVertexAttrib2f", &specList, &cantDo);
				lookup ("glVertexAttrib2fv", &specList, &cantDo);
				lookup ("glVertexAttrib2s", &specList, &cantDo);
				lookup ("glVertexAttrib2sv", &specList, &cantDo);
				lookup ("glVertexAttrib3d", &specList, &cantDo);
				lookup ("glVertexAttrib3dv", &specList, &cantDo);
				lookup ("glVertexAttrib3f", &specList, &cantDo);
				lookup ("glVertexAttrib3fv", &specList, &cantDo);
				lookup ("glVertexAttrib3s", &specList, &cantDo);
				lookup ("glVertexAttrib3sv", &specList, &cantDo);
				lookup ("glVertexAttrib4Nbv", &specList, &cantDo);
				lookup ("glVertexAttrib4Niv", &specList, &cantDo);
				lookup ("glVertexAttrib4Nsv", &specList, &cantDo);
				lookup ("glVertexAttrib4Nub", &specList, &cantDo);
				lookup ("glVertexAttrib4Nubv", &specList, &cantDo);
				lookup ("glVertexAttrib4Nuiv", &specList, &cantDo);
				lookup ("glVertexAttrib4Nusv", &specList, &cantDo);
				lookup ("glVertexAttrib4bv", &specList, &cantDo);
				lookup ("glVertexAttrib4d", &specList, &cantDo);
				lookup ("glVertexAttrib4dv", &specList, &cantDo);
				lookup ("glVertexAttrib4f", &specList, &cantDo);
				lookup ("glVertexAttrib4fv", &specList, &cantDo);
				lookup ("glVertexAttrib4iv", &specList, &cantDo);
				lookup ("glVertexAttrib4s", &specList, &cantDo);
				lookup ("glVertexAttrib4sv", &specList, &cantDo);
				lookup ("glVertexAttrib4ubv", &specList, &cantDo);
				lookup ("glVertexAttrib4uiv", &specList, &cantDo);
				lookup ("glVertexAttrib4usv", &specList, &cantDo);
				lookup ("glVertexAttribPointer", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				fprintf (f, "\n\nARB extensions:\n");

				//WGL_ARB_buffer_region
				fprintf (f, "\nWGL_ARB_buffer_region\n");
				lookup ("wglCreateBufferRegionARB", &specList, &cantDo);
				lookup ("wglDeleteBufferRegionARB", &specList, &cantDo);
				lookup ("wglSaveBufferRegionARB", &specList, &cantDo);
				lookup ("wglRestoreBufferRegionARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_multisample
				fprintf (f, "\nGL_ARB_multisample\n");
				lookup ("glSampleCoverageARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//WGL_extensions_string
				fprintf (f, "\nWGL_ARB_extensions_string\n");
				lookup ("wglGetExtensionsStringARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//WGL_pixel_format
				fprintf (f, "\nWGL_ARB_pixel_format\n");
				lookup ("wglGetPixelFormatAttribivARB", &specList, &cantDo);
				lookup ("wglGetPixelFormatAttribfvARB", &specList, &cantDo);
				lookup ("wglChoosePixelFormatARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//WGL_make_current_read
				fprintf (f, "\nWGL_ARB_make_current_read\n");
				lookup ("wglMakeContextCurrentARB", &specList, &cantDo);
				lookup ("wglGetCurrentReadDCARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//WGL_ARB_pbuffer
				fprintf (f, "\nWGL_ARB_pbuffer\n");
				lookup ("wglCreatePbufferARB", &specList, &cantDo);
				lookup ("wglDestroyPbufferARB", &specList, &cantDo);
				lookup ("wglSetPbufferAttribARB", &specList, &cantDo);
				lookup ("wglQueryPbufferARB", &specList, &cantDo);
				lookup ("wglBindTexImageARB", &specList, &cantDo);
				lookup ("wglReleaseTexImageARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_compressed_texture
				fprintf (f, "\nGL_ARB_pixel_format\n");
				lookup ("glCompressedTexImage3DARB", &specList, &cantDo);
				lookup ("glCompressedTexImage2DARB", &specList, &cantDo);
				lookup ("glCompressedTexImage1DARB", &specList, &cantDo);
				lookup ("glCompressedTexSubImage3DARB", &specList, &cantDo);
				lookup ("glCompressedTexSubImage2DARB", &specList, &cantDo);
				lookup ("glCompressedTexSubImage1DARB", &specList, &cantDo);
				lookup ("glGetCompressedTexImageARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_point_parameters
				fprintf (f, "\nGL_ARB_point_parameters\n");
				lookup ("glPointParameterfARB", &specList, &cantDo);
				lookup ("glPointParameterfvARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_vertex_blend
				fprintf (f, "\nGL_ARB_vertex_blend\n");
				lookup ("glWeightbvARB", &specList, &cantDo);
				lookup ("glWeightubvARB", &specList, &cantDo);
				lookup ("glWeightsvARB", &specList, &cantDo);
				lookup ("glWeightusvARB", &specList, &cantDo);
				lookup ("glWeightivARB", &specList, &cantDo);
				lookup ("glWeightuivARB", &specList, &cantDo);
				lookup ("glWeightfvARB", &specList, &cantDo);
				lookup ("glWeightdvARB", &specList, &cantDo);
				lookup ("glWeightPointerARB", &specList, &cantDo);
				lookup ("glVertexBlendARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_palette_matrix
				fprintf (f, "\nGL_ARB_palette_matrix\n");
				lookup ("glCurrentPaletteMatrixARB", &specList, &cantDo);
				lookup ("glMatrixIndexubvARB", &specList, &cantDo);
				lookup ("glMatrixIndexusvARB", &specList, &cantDo);
				lookup ("glMatrixIndexuivARB", &specList, &cantDo);
				lookup ("glMatrixIndexPointerARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_render_texture
				//bool (APIENTRY* BindTexImageARB) (HPBUFFERARB, int);
				//bool (APIENTRY* ReleaseTexImageARB) (HPBUFFERARB, int);
				//bool (APIENTRY* SetPbufferAttribARB) (HPBUFFERARB, const int *);

				//GL_ARB_window_pos
				fprintf (f, "\nGL_ARB_window_pos\n");
				lookup ("glWindowPos2dARB", &specList, &cantDo);
				lookup ("glWindowPos2fARB", &specList, &cantDo);
				lookup ("glWindowPos2iARB", &specList, &cantDo);
				lookup ("glWindowPos2sARB", &specList, &cantDo);
				lookup ("glWindowPos2dvARB", &specList, &cantDo);
				lookup ("glWindowPos2fvARB", &specList, &cantDo);
				lookup ("glWindowPos2ivARB", &specList, &cantDo);
				lookup ("glWindowPos2svARB", &specList, &cantDo);
				lookup ("glWindowPos3dARB", &specList, &cantDo);
				lookup ("glWindowPos3fARB", &specList, &cantDo);
				lookup ("glWindowPos3iARB", &specList, &cantDo);
				lookup ("glWindowPos3sARB", &specList, &cantDo);
				lookup ("glWindowPos3dvARB", &specList, &cantDo);
				lookup ("glWindowPos3fvARB", &specList, &cantDo);
				lookup ("glWindowPos3ivARB", &specList, &cantDo);
				lookup ("glWindowPos3svARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_vertex_program
				fprintf (f, "\nGL_ARB_vertex_program\n");
				lookup ("glVertexAttrib1sARB", &specList, &cantDo);
				lookup ("glVertexAttrib1fARB", &specList, &cantDo);
				lookup ("glVertexAttrib1dARB", &specList, &cantDo);
				lookup ("glVertexAttrib2sARB", &specList, &cantDo);
				lookup ("glVertexAttrib2fARB", &specList, &cantDo);
				lookup ("glVertexAttrib2dARB", &specList, &cantDo);
				lookup ("glVertexAttrib3sARB", &specList, &cantDo);
				lookup ("glVertexAttrib3fARB", &specList, &cantDo);
				lookup ("glVertexAttrib3dARB", &specList, &cantDo);
				lookup ("glVertexAttrib4sARB", &specList, &cantDo);
				lookup ("glVertexAttrib4fARB", &specList, &cantDo);
				lookup ("glVertexAttrib4dARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NubARB", &specList, &cantDo);
				lookup ("glVertexAttrib1svARB", &specList, &cantDo);
				lookup ("glVertexAttrib1fvARB", &specList, &cantDo);
				lookup ("glVertexAttrib1dvARB", &specList, &cantDo);
				lookup ("glVertexAttrib2svARB", &specList, &cantDo);
				lookup ("glVertexAttrib2fvARB", &specList, &cantDo);
				lookup ("glVertexAttrib2dvARB", &specList, &cantDo);
				lookup ("glVertexAttrib3svARB", &specList, &cantDo);
				lookup ("glVertexAttrib3fvARB", &specList, &cantDo);
				lookup ("glVertexAttrib3dvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4bvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4svARB", &specList, &cantDo);
				lookup ("glVertexAttrib4ivARB", &specList, &cantDo);
				lookup ("glVertexAttrib4ubvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4usvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4uivARB", &specList, &cantDo);
				lookup ("glVertexAttrib4fARB", &specList, &cantDo);
				lookup ("glVertexAttrib4dARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NbvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NsvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NivARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NubvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NusvARB", &specList, &cantDo);
				lookup ("glVertexAttrib4NuivARB", &specList, &cantDo);
				lookup ("glVertexAttribPointerARB", &specList, &cantDo);
				lookup ("glEnableVertexAttribArrayARB", &specList, &cantDo);
				lookup ("glDisableVertexAttribArrayARB", &specList, &cantDo);
				lookup ("glProgramStringARB", &specList, &cantDo);
				lookup ("glBindProgramARB", &specList, &cantDo);
				lookup ("glDeleteProgramsARB", &specList, &cantDo);
				lookup ("glGenProgramsARB", &specList, &cantDo);
				lookup ("glProgramEnvParameter4dARB", &specList, &cantDo);
				lookup ("glProgramEnvParameter4dvARB", &specList, &cantDo);
				lookup ("glProgramEnvParameter4fARB", &specList, &cantDo);
				lookup ("glProgramEnvParameter4fvARB", &specList, &cantDo);
				lookup ("glProgramLocalParameter4dARB", &specList, &cantDo);
				lookup ("glProgramLocalParameter4dvARB", &specList, &cantDo);
				lookup ("glProgramLocalParameter4fARB", &specList, &cantDo);
				lookup ("glProgramLocalParameter4fvARB", &specList, &cantDo);
				lookup ("glGetProgramEnvParameterdvARB", &specList, &cantDo);
				lookup ("glGetProgramEnvParameterfvARB", &specList, &cantDo);
				lookup ("glGetProgramLocalParameterdvARB", &specList, &cantDo);
				lookup ("glGetProgramLocalParameterfvARB", &specList, &cantDo);
				lookup ("glGetProgramivARB", &specList, &cantDo);
				lookup ("glGetProgramStringARB", &specList, &cantDo);
				lookup ("glGetVertexAttribdvARB", &specList, &cantDo);
				lookup ("glGetVertexAttribfvARB", &specList, &cantDo);
				lookup ("glGetVertexAttribivARB", &specList, &cantDo);
				lookup ("glGetVertexAttribPointervARB", &specList, &cantDo);
				lookup ("glIsProgramARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_fragment_program

				//GL_ARB_vertex_buffer_object
				fprintf (f, "\nGL_ARB_vertex_buffer_object\n");
				lookup ("glBindBufferARB", &specList, &cantDo);
				lookup ("glDeleteBuffersARB", &specList, &cantDo);
				lookup ("glGenBuffersARB", &specList, &cantDo);
				lookup ("glIsBufferARB", &specList, &cantDo);
				lookup ("glBufferDataARB", &specList, &cantDo);
				lookup ("glBufferSubDataARB", &specList, &cantDo);
				lookup ("glGetBufferSubDataARB", &specList, &cantDo);
				lookup ("glMapBufferARB", &specList, &cantDo);
				lookup ("glUnmapBufferARB", &specList, &cantDo);
				lookup ("glGetBufferParameterivARB", &specList, &cantDo);
				lookup ("glGetBufferPointervARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_occlusion_query
				fprintf (f, "\nGL_ARB_occlusion_query\n");
				lookup ("glGenQueriesARB", &specList, &cantDo);
				lookup ("glDeleteQueriesARB", &specList, &cantDo);
				lookup ("glIsQueryARB", &specList, &cantDo);
				lookup ("glBeginQueryARB", &specList, &cantDo);
				lookup ("glEndQueryARB", &specList, &cantDo);
				lookup ("glGetQueryivARB", &specList, &cantDo);
				lookup ("glGetQueryObjectivARB", &specList, &cantDo);
				lookup ("glGetQueryObjectuivARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_shader_objects
				fprintf (f, "\nGL_ARB_shader_objects\n");
				lookup ("glDeleteObjectARB", &specList, &cantDo);
				lookup ("glGetHandleARB", &specList, &cantDo);
				lookup ("glDetachObjectARB", &specList, &cantDo);
				lookup ("glCreateShaderObjectARB", &specList, &cantDo);
				lookup ("glShaderSourceARB", &specList, &cantDo);
				lookup ("glCompileShaderARB", &specList, &cantDo);
				lookup ("glCreateProgramObjectARB", &specList, &cantDo);
				lookup ("glAttachObjectARB", &specList, &cantDo);
				lookup ("glLinkProgramARB", &specList, &cantDo);
				lookup ("glUseProgramObjectARB", &specList, &cantDo);
				lookup ("glValidateProgramARB", &specList, &cantDo);
				lookup ("glUniform1fARB", &specList, &cantDo);
				lookup ("glUniform2fARB", &specList, &cantDo);
				lookup ("glUniform3fARB", &specList, &cantDo);
				lookup ("glUniform4fARB", &specList, &cantDo);
				lookup ("glUniform1iARB", &specList, &cantDo);
				lookup ("glUniform2iARB", &specList, &cantDo);
				lookup ("glUniform3iARB", &specList, &cantDo);
				lookup ("glUniform4iARB", &specList, &cantDo);
				lookup ("glUniform1fvARB", &specList, &cantDo);
				lookup ("glUniform2fvARB", &specList, &cantDo);
				lookup ("glUniform3fvARB", &specList, &cantDo);
				lookup ("glUniform4fvARB", &specList, &cantDo);
				lookup ("glUniform1ivARB", &specList, &cantDo);
				lookup ("glUniform2ivARB", &specList, &cantDo);
				lookup ("glUniform3ivARB", &specList, &cantDo);
				lookup ("glUniform4ivARB", &specList, &cantDo);
				lookup ("glUniformMatrix2fvARB", &specList, &cantDo);
				lookup ("glUniformMatrix3fvARB", &specList, &cantDo);
				lookup ("glUniformMatrix4fvARB", &specList, &cantDo);
				lookup ("glGetObjectParameterfvARB", &specList, &cantDo);
				lookup ("glGetObjectParameterivARB", &specList, &cantDo);
				lookup ("glGetInfoLogARB", &specList, &cantDo);
				lookup ("glGetAttachedObjectsARB", &specList, &cantDo);
				lookup ("glGetUniformLocationARB", &specList, &cantDo);
				lookup ("glGetActiveUniformARB", &specList, &cantDo);
				lookup ("glGetUniformfvARB", &specList, &cantDo);
				lookup ("glGetUniformivARB", &specList, &cantDo);
				lookup ("glGetShaderSourceARB", &specList, &cantDo);
				
				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_vertex_shader
				fprintf (f, "\nGL_ARB_vertex_shader\n");
				lookup ("glBindAttribLocationARB", &specList, &cantDo);
				lookup ("glGetActiveAttribARB", &specList, &cantDo);
				lookup ("glGetAttribLocationARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_draw_buffers
				fprintf (f, "\nGL_ARB_draw_buffers\n");
				lookup ("glDrawBuffersARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//GL_ARB_color_buffer_float
				fprintf (f, "\nGL_ARB_color_buffer_float\n");
				lookup ("glClampColorARB", &specList, &cantDo);

				fprintf (f, "Supported:\n");
				for (unsigned int i = 0; i < specList.getSize (); i++)
					fprintf (f, "\t%s\n", specList[i].str ());
				specList.clear ();
				fprintf (f, "Unsupported:\n");
				for (unsigned int i = 0; i < cantDo.getSize (); i++)
					fprintf (f, "\t%s\n", cantDo[i].str ());
				cantDo.clear ();

				//fprintf (f, "\n\nEXT extensions:\n");

				fclose (f);
			}
		}

		wglMakeCurrent (NULL, NULL);
		wglDeleteContext (hglrc);
	}
	virtual ~window () {}

	void lookup (const gsutil::gsstring &func, gsutil::gsarray <gsutil::gsstring> *can, gsutil::gsarray <gsutil::gsstring> *not)
	{
		void *e = wglGetProcAddress (func.str ());
		if (!e)
			not->add (func);
		else
			can->add (func);
	}

private:
};

int main (int argc, char *argv[])
{
	window *w = new window;

	w->handle ();

	return 0;
}
