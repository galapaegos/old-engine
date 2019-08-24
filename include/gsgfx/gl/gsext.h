#ifndef _gsext_h_
#define _gsext_h_

#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#ifndef WIN32
#include <GL/glx.h>
#endif
#include "glenums.h"

#include <gsutil/gsstring.h>

namespace gsext
{
	typedef struct
	{
		void (APIENTRY* BlendColor) (GLclampf, GLclampf, GLclampf, GLclampf);
		void (APIENTRY* BlendEquation) (GLenum);
		void (APIENTRY* DrawRangeElements) (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
		void (APIENTRY* ColorTable) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
		void (APIENTRY* ColorTableParameterfv) (GLenum, GLenum, const GLfloat *);
		void (APIENTRY* ColorTableParameteriv) (GLenum, GLenum, const GLint *);
		void (APIENTRY* CopyColorTable) (GLenum, GLenum, GLint, GLint, GLsizei);
		void (APIENTRY* GetColorTable) (GLenum, GLenum, GLenum, GLvoid *);
		void (APIENTRY* GetColorTableParameterfv) (GLenum, GLenum, GLfloat *);
		void (APIENTRY* GetColorTableParameteriv) (GLenum, GLenum, GLint *);
		void (APIENTRY* ColorSubTable) (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
		void (APIENTRY* CopyColorSubTable) (GLenum, GLsizei, GLint, GLint, GLsizei);
		void (APIENTRY* ConvolutionFilter1D) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
		void (APIENTRY* ConvolutionFilter2D) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
		void (APIENTRY* ConvolutionParameterf) (GLenum, GLenum, GLfloat);
		void (APIENTRY* ConvolutionParameterfv) (GLenum, GLenum, const GLfloat *);
		void (APIENTRY* ConvolutionParameteri) (GLenum, GLenum, GLint);
		void (APIENTRY* ConvolutionParameteriv) (GLenum, GLenum, const GLint *);
		void (APIENTRY* CopyConvolutionFilter1D) (GLenum, GLenum, GLint, GLint, GLsizei);
		void (APIENTRY* CopyConvolutionFilter2D) (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
		void (APIENTRY* GetConvolutionFilter) (GLenum, GLenum, GLenum, GLvoid *);
		void (APIENTRY* GetConvolutionParameterfv) (GLenum, GLenum, GLfloat *);
		void (APIENTRY* GetConvolutionParameteriv) (GLenum, GLenum, GLint *);
		void (APIENTRY* GetSeparableFilter) (GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *);
		void (APIENTRY* SeparableFilter2D) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *);
		void (APIENTRY* GetHistogram) (GLenum, GLboolean, GLenum, GLenum, GLvoid *);
		void (APIENTRY* GetHistogramParameterfv) (GLenum, GLenum, GLfloat *);
		void (APIENTRY* GetHistogramParameteriv) (GLenum, GLenum, GLint *);
		void (APIENTRY* GetMinmax) (GLenum, GLboolean, GLenum, GLenum, GLvoid *);
		void (APIENTRY* GetMinmaxParameterfv) (GLenum, GLenum, GLfloat *);
		void (APIENTRY* GetMinmaxParameteriv) (GLenum, GLenum, GLint *);
		void (APIENTRY* Histogram) (GLenum, GLsizei, GLenum, GLboolean);
		void (APIENTRY* Minmax) (GLenum, GLenum, GLboolean);
		void (APIENTRY* ResetHistogram) (GLenum);
		void (APIENTRY* ResetMinmax) (GLenum);
		void (APIENTRY* TexImage3D) (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
		void (APIENTRY* TexSubImage3D) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
		void (APIENTRY* CopyTexSubImage3D) (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	} gsext12;

	typedef struct
	{
		void (APIENTRY* ActiveTexture) (GLenum);
		void (APIENTRY* ClientActiveTexture) (GLenum);
		void (APIENTRY* MultiTexCoord1d) (GLenum, GLdouble);
		void (APIENTRY* MultiTexCoord1dv) (GLenum, const GLdouble *);
		void (APIENTRY* MultiTexCoord1f) (GLenum, GLfloat);
		void (APIENTRY* MultiTexCoord1fv) (GLenum, const GLfloat *);
		void (APIENTRY* MultiTexCoord1i) (GLenum, GLint);
		void (APIENTRY* MultiTexCoord1iv) (GLenum, const GLint *);
		void (APIENTRY* MultiTexCoord1s) (GLenum, GLshort);
		void (APIENTRY* MultiTexCoord1sv) (GLenum, const GLshort *);
		void (APIENTRY* MultiTexCoord2d) (GLenum, GLdouble, GLdouble);
		void (APIENTRY* MultiTexCoord2dv) (GLenum, const GLdouble *);
		void (APIENTRY* MultiTexCoord2f) (GLenum, GLfloat, GLfloat);
		void (APIENTRY* MultiTexCoord2fv) (GLenum, const GLfloat *);
		void (APIENTRY* MultiTexCoord2i) (GLenum, GLint, GLint);
		void (APIENTRY* MultiTexCoord2iv) (GLenum, const GLint *);
		void (APIENTRY* MultiTexCoord2s) (GLenum, GLshort, GLshort);
		void (APIENTRY* MultiTexCoord2sv) (GLenum, const GLshort *);
		void (APIENTRY* MultiTexCoord3d) (GLenum, GLdouble, GLdouble, GLdouble);
		void (APIENTRY* MultiTexCoord3dv) (GLenum, const GLdouble *);
		void (APIENTRY* MultiTexCoord3f) (GLenum, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* MultiTexCoord3fv) (GLenum, const GLfloat *);
		void (APIENTRY* MultiTexCoord3i) (GLenum, GLint, GLint, GLint);
		void (APIENTRY* MultiTexCoord3iv) (GLenum, const GLint *);
		void (APIENTRY* MultiTexCoord3s) (GLenum, GLshort, GLshort, GLshort);
		void (APIENTRY* MultiTexCoord3sv) (GLenum, const GLshort *);
		void (APIENTRY* MultiTexCoord4d) (GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
		void (APIENTRY* MultiTexCoord4dv) (GLenum, const GLdouble *);
		void (APIENTRY* MultiTexCoord4f) (GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* MultiTexCoord4fv) (GLenum, const GLfloat *);
		void (APIENTRY* MultiTexCoord4i) (GLenum, GLint, GLint, GLint, GLint);
		void (APIENTRY* MultiTexCoord4iv) (GLenum, const GLint *);
		void (APIENTRY* MultiTexCoord4s) (GLenum, GLshort, GLshort, GLshort, GLshort);
		void (APIENTRY* MultiTexCoord4sv) (GLenum, const GLshort *);
		void (APIENTRY* LoadTransposeMatrixf) (const GLfloat *);
		void (APIENTRY* LoadTransposeMatrixd) (const GLdouble *);
		void (APIENTRY* MultTransposeMatrixf) (const GLfloat *);
		void (APIENTRY* MultTransposeMatrixd) (const GLdouble *);
		void (APIENTRY* SampleCoverage) (GLclampf, GLboolean);
		void (APIENTRY* CompressedTexImage3D) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
		void (APIENTRY* CompressedTexImage2D) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
		void (APIENTRY* CompressedTexImage1D) (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
		void (APIENTRY* CompressedTexSubImage3D) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
		void (APIENTRY* CompressedTexSubImage2D) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
		void (APIENTRY* CompressedTexSubImage1D) (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
		void (APIENTRY* GetCompressedTexImage) (GLenum, GLint, GLvoid *);
	} gsext13;

	typedef struct
	{
		void (APIENTRY* BlendFuncSeparate) (GLenum, GLenum, GLenum, GLenum);
		void (APIENTRY* FogCoordf) (GLfloat);
		void (APIENTRY* FogCoordfv) (const GLfloat *);
		void (APIENTRY* FogCoordd) (GLdouble);
		void (APIENTRY* FogCoorddv) (const GLdouble *);
		void (APIENTRY* FogCoordPointer) (GLenum, GLsizei, const GLvoid *);
		void (APIENTRY* MultiDrawArrays) (GLenum, GLint *, GLsizei *, GLsizei);
		void (APIENTRY* MultiDrawElements) (GLenum, const GLsizei *, GLenum, const GLvoid* *, GLsizei);
		void (APIENTRY* PointParameterf) (GLenum, GLfloat);
		void (APIENTRY* PointParameterfv) (GLenum, const GLfloat *);
		void (APIENTRY* PointParameteri) (GLenum, GLint);
		void (APIENTRY* PointParameteriv) (GLenum, const GLint *);
		void (APIENTRY* SecondaryColor3b) (GLbyte, GLbyte, GLbyte);
		void (APIENTRY* SecondaryColor3bv) (const GLbyte *);
		void (APIENTRY* SecondaryColor3d) (GLdouble, GLdouble, GLdouble);
		void (APIENTRY* SecondaryColor3dv) (const GLdouble *);
		void (APIENTRY* SecondaryColor3f) (GLfloat, GLfloat, GLfloat);
		void (APIENTRY* SecondaryColor3fv) (const GLfloat *);
		void (APIENTRY* SecondaryColor3i) (GLint, GLint, GLint);
		void (APIENTRY* SecondaryColor3iv) (const GLint *);
		void (APIENTRY* SecondaryColor3s) (GLshort, GLshort, GLshort);
		void (APIENTRY* SecondaryColor3sv) (const GLshort *);
		void (APIENTRY* SecondaryColor3ub) (GLubyte, GLubyte, GLubyte);
		void (APIENTRY* SecondaryColor3ubv) (const GLubyte *);
		void (APIENTRY* SecondaryColor3ui) (GLuint, GLuint, GLuint);
		void (APIENTRY* SecondaryColor3uiv) (const GLuint *);
		void (APIENTRY* SecondaryColor3us) (GLushort, GLushort, GLushort);
		void (APIENTRY* SecondaryColor3usv) (const GLushort *);
		void (APIENTRY* SecondaryColorPointer) (GLint, GLenum, GLsizei, const GLvoid *);
		void (APIENTRY* WindowPos2d) (GLdouble, GLdouble);
		void (APIENTRY* WindowPos2dv) (const GLdouble *);
		void (APIENTRY* WindowPos2f) (GLfloat, GLfloat);
		void (APIENTRY* WindowPos2fv) (const GLfloat *);
		void (APIENTRY* WindowPos2i) (GLint, GLint);
		void (APIENTRY* WindowPos2iv) (const GLint *);
		void (APIENTRY* WindowPos2s) (GLshort, GLshort);
		void (APIENTRY* WindowPos2sv) (const GLshort *);
		void (APIENTRY* WindowPos3d) (GLdouble, GLdouble, GLdouble);
		void (APIENTRY* WindowPos3dv) (const GLdouble *);
		void (APIENTRY* WindowPos3f) (GLfloat, GLfloat, GLfloat);
		void (APIENTRY* WindowPos3fv) (const GLfloat *);
		void (APIENTRY* WindowPos3i) (GLint, GLint, GLint);
		void (APIENTRY* WindowPos3iv) (const GLint *);
		void (APIENTRY* WindowPos3s) (GLshort, GLshort, GLshort);
		void (APIENTRY* WindowPos3sv) (const GLshort *);
	} gsext14;

	typedef struct
	{
		void (APIENTRY* GenQueries) (GLsizei, GLuint *);
		void (APIENTRY* DeleteQueries) (GLsizei, const GLuint *);
		bool (APIENTRY *IsQuery) (GLuint);
		void (APIENTRY* BeginQuery) (GLenum, GLuint);
		void (APIENTRY* EndQuery) (GLenum);
		void (APIENTRY* GetQueryiv) (GLenum, GLenum, GLint *);
		void (APIENTRY* GetQueryObjectiv) (GLuint, GLenum, GLint *);
		void (APIENTRY* GetQueryObjectuiv) (GLuint, GLenum, GLuint *);
		void (APIENTRY* BindBuffer) (GLenum, GLuint);
		void (APIENTRY* DeleteBuffers) (GLsizei, const GLuint *);
		void (APIENTRY* GenBuffers) (GLsizei, GLuint *);
		bool (APIENTRY *IsBuffer) (GLuint);
		void (APIENTRY* BufferData) (GLenum, GLsizei*, const GLvoid *, GLenum);
		void (APIENTRY* BufferSubData) (GLenum, GLint*, GLsizei*, const GLvoid *);
		void (APIENTRY* GetBufferSubData) (GLenum, GLint*, GLsizei*, GLvoid *);
		void* (APIENTRY *MapBuffer) (GLenum, GLenum);
		bool (APIENTRY *UnmapBuffer) (GLenum);
		void (APIENTRY* GetBufferParameteriv) (GLenum, GLenum, GLint *);
		void (APIENTRY* GetBufferPointerv) (GLenum, GLenum, GLvoid* *);
	} gsext15;

	typedef struct
	{
		void (APIENTRY* BlendEquationSeparate) (GLenum, GLenum);
		void (APIENTRY* DrawBuffers) (GLsizei, const GLenum *);
		void (APIENTRY* StencilOpSeparate) (GLenum, GLenum, GLenum, GLenum);
		void (APIENTRY* StencilFuncSeparate) (GLenum, GLenum, GLint, GLuint);
		void (APIENTRY* StencilMaskSeparate) (GLenum, GLuint);
		void (APIENTRY* AttachShader) (GLuint, GLuint);
		void (APIENTRY* BindAttribLocation) (GLuint, GLuint, const GLchar *);
		void (APIENTRY* CompileShader) (GLuint);
		unsigned int (APIENTRY *CreateProgram) (void);
		unsigned int (APIENTRY *CreateShader) (GLenum);
		void (APIENTRY* DeleteProgram) (GLuint);
		void (APIENTRY* DeleteShader) (GLuint);
		void (APIENTRY* DetachShader) (GLuint, GLuint);
		void (APIENTRY* DisableVertexAttribArray) (GLuint);
		void (APIENTRY* EnableVertexAttribArray) (GLuint);
		void (APIENTRY* GetActiveAttrib) (GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
		void (APIENTRY* GetActiveUniform) (GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
		void (APIENTRY* GetAttachedShaders) (GLuint, GLsizei, GLsizei *, GLuint *);
		int (APIENTRY *GetAttribLocation) (GLuint, const GLchar *);
		void (APIENTRY* GetProgramiv) (GLuint, GLenum, GLint *);
		void (APIENTRY* GetProgramInfoLog) (GLuint, GLsizei, GLsizei *, GLchar *);
		void (APIENTRY* GetShaderiv) (GLuint, GLenum, GLint *);
		void (APIENTRY* GetShaderInfoLog) (GLuint, GLsizei, GLsizei *, GLchar *);
		void (APIENTRY* GetShaderSource) (GLuint, GLsizei, GLsizei *, GLchar *);
		int (APIENTRY *GetUniformLocation) (GLuint, const GLchar *);
		void (APIENTRY* GetUniformfv) (GLuint, GLint, GLfloat *);
		void (APIENTRY* GetUniformiv) (GLuint, GLint, GLint *);
		void (APIENTRY* GetVertexAttribdv) (GLuint, GLenum, GLdouble *);
		void (APIENTRY* GetVertexAttribfv) (GLuint, GLenum, GLfloat *);
		void (APIENTRY* GetVertexAttribiv) (GLuint, GLenum, GLint *);
		void (APIENTRY* GetVertexAttribPointerv) (GLuint, GLenum, GLvoid* *);
		bool (APIENTRY *IsProgram) (GLuint);
		bool (APIENTRY *IsShader) (GLuint);
		void (APIENTRY* LinkProgram) (GLuint);
		void (APIENTRY* ShaderSource) (GLuint, GLsizei, const GLchar* *, const GLint *);
		void (APIENTRY* UseProgram) (GLuint);
		void (APIENTRY* Uniform1f) (GLint, GLfloat);
		void (APIENTRY* Uniform2f) (GLint, GLfloat, GLfloat);
		void (APIENTRY* Uniform3f) (GLint, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* Uniform4f) (GLint, GLfloat, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* Uniform1i) (GLint, GLint);
		void (APIENTRY* Uniform2i) (GLint, GLint, GLint);
		void (APIENTRY* Uniform3i) (GLint, GLint, GLint, GLint);
		void (APIENTRY* Uniform4i) (GLint, GLint, GLint, GLint, GLint);
		void (APIENTRY* Uniform1fv) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform2fv) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform3fv) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform4fv) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform1iv) (GLint, GLsizei, const GLint *);
		void (APIENTRY* Uniform2iv) (GLint, GLsizei, const GLint *);
		void (APIENTRY* Uniform3iv) (GLint, GLsizei, const GLint *);
		void (APIENTRY* Uniform4iv) (GLint, GLsizei, const GLint *);
		void (APIENTRY* UniformMatrix2fv) (GLint, GLsizei, GLboolean, const GLfloat *);
		void (APIENTRY* UniformMatrix3fv) (GLint, GLsizei, GLboolean, const GLfloat *);
		void (APIENTRY* UniformMatrix4fv) (GLint, GLsizei, GLboolean, const GLfloat *);
		void (APIENTRY* ValidateProgram) (GLuint);
		void (APIENTRY* VertexAttrib1d) (GLuint, GLdouble);
		void (APIENTRY* VertexAttrib1dv) (GLuint, const GLdouble *);
		void (APIENTRY* VertexAttrib1f) (GLuint, GLfloat);
		void (APIENTRY* VertexAttrib1fv) (GLuint, const GLfloat *);
		void (APIENTRY* VertexAttrib1s) (GLuint, GLshort);
		void (APIENTRY* VertexAttrib1sv) (GLuint, const GLshort *);
		void (APIENTRY* VertexAttrib2d) (GLuint, GLdouble, GLdouble);
		void (APIENTRY* VertexAttrib2dv) (GLuint, const GLdouble *);
		void (APIENTRY* VertexAttrib2f) (GLuint, GLfloat, GLfloat);
		void (APIENTRY* VertexAttrib2fv) (GLuint, const GLfloat *);
		void (APIENTRY* VertexAttrib2s) (GLuint, GLshort, GLshort);
		void (APIENTRY* VertexAttrib2sv) (GLuint, const GLshort *);
		void (APIENTRY* VertexAttrib3d) (GLuint, GLdouble, GLdouble, GLdouble);
		void (APIENTRY* VertexAttrib3dv) (GLuint, const GLdouble *);
		void (APIENTRY* VertexAttrib3f) (GLuint, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* VertexAttrib3fv) (GLuint, const GLfloat *);
		void (APIENTRY* VertexAttrib3s) (GLuint, GLshort, GLshort, GLshort);
		void (APIENTRY* VertexAttrib3sv) (GLuint, const GLshort *);
		void (APIENTRY* VertexAttrib4Nbv) (GLuint, const GLbyte *);
		void (APIENTRY* VertexAttrib4Niv) (GLuint, const GLint *);
		void (APIENTRY* VertexAttrib4Nsv) (GLuint, const GLshort *);
		void (APIENTRY* VertexAttrib4Nub) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
		void (APIENTRY* VertexAttrib4Nubv) (GLuint, const GLubyte *);
		void (APIENTRY* VertexAttrib4Nuiv) (GLuint, const GLuint *);
		void (APIENTRY* VertexAttrib4Nusv) (GLuint, const GLushort *);
		void (APIENTRY* VertexAttrib4bv) (GLuint, const GLbyte *);
		void (APIENTRY* VertexAttrib4d) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
		void (APIENTRY* VertexAttrib4dv) (GLuint, const GLdouble *);
		void (APIENTRY* VertexAttrib4f) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* VertexAttrib4fv) (GLuint, const GLfloat *);
		void (APIENTRY* VertexAttrib4iv) (GLuint, const GLint *);
		void (APIENTRY* VertexAttrib4s) (GLuint, GLshort, GLshort, GLshort, GLshort);
		void (APIENTRY* VertexAttrib4sv) (GLuint, const GLshort *);
		void (APIENTRY* VertexAttrib4ubv) (GLuint, const GLubyte *);
		void (APIENTRY* VertexAttrib4uiv) (GLuint, const GLuint *);
		void (APIENTRY* VertexAttrib4usv) (GLuint, const GLushort *);
		void (APIENTRY* VertexAttribPointer) (GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
	} gsext20;

	typedef struct
	{
#ifdef WIN32
		//WGL_ARB_buffer_region
		HANDLE (APIENTRY* CreateBufferRegionARB) (HDC, int, unsigned int);
		void (APIENTRY* DeleteBufferRegionARB) (HANDLE);
		bool (APIENTRY* SaveBufferRegionARB) (HANDLE, int, int, int, int);
		bool (APIENTRY* RestoreBufferRegionARB) (HANDLE, int, int, int, int, int, int);
#endif

		//GL_ARB_multisample
		void (APIENTRY* SampleCoverageARB) (float, bool);

		//GL_ARB_texture_cube_map

#ifdef WIN32
		//WGL_extensions_string
		const char *(APIENTRY* GetExtensionsStringARB) (HDC);
#endif

#ifdef WIN32
		//WGL_pixel_format
		bool (APIENTRY* GetPixelFormatAttribivARB) (HDC, int, int, GLuint, const int *, int *);
		bool (APIENTRY* GetPixelFormatAttribfvARB) (HDC, int, int, GLuint, const int *, float *);
		bool (APIENTRY* ChoosePixelFormatARB) (HDC, const int *, const float *, GLuint, int *, GLuint *);
#endif

#ifdef WIN32
		//WGL_make_current_read
		bool (APIENTRY* MakeContextCurrentARB) (HDC, HDC, HGLRC);
		HDC (APIENTRY* GetCurrentReadDCARB) ();
#endif

#ifdef WIN32
		//WGL_ARB_pbuffer
		HPBUFFERARB (APIENTRY* wCreatePbufferARB) (HDC, int, int, int, const int*);
		HDC (APIENTRY* wGetPbufferDCARB) (HPBUFFERARB);
		bool (APIENTRY* wReleasePbufferDCARB) (HPBUFFERARB, int);
		bool (APIENTRY* wDestroyPbufferARB) (HPBUFFERARB);
		bool (APIENTRY* wQueryPbufferARB) (HPBUFFERARB, int, int*);
#endif

		//GL_ARB_compressed_texture
		void (APIENTRY* CompressedTexImage3DARB) (GLenum, int, GLenum, GLsizei width, GLsizei, GLsizei, int, GLsizei, const void *);
		void (APIENTRY* CompressedTexImage2DARB) (GLenum, int, GLenum, GLsizei width, GLsizei, int, GLsizei, const void *);
		void (APIENTRY* CompressedTexImage1DARB) (GLenum, int, GLenum, GLsizei, int, GLsizei, const void *);
		void (APIENTRY* CompressedTexSubImage3DARB) (GLenum, int, int, int, int, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *);
		void (APIENTRY* CompressedTexSubImage2DARB) (GLenum, int, int, int, GLsizei, GLsizei, GLenum, GLsizei, const void *);
		void (APIENTRY* CompressedTexSubImage1DARB) (GLenum, int, int, GLsizei, GLenum, GLsizei, const void *);
		void (APIENTRY* GetCompressedTexImageARB) (GLenum, int, void *);

		//GL_ARB_point_parameters
		void (APIENTRY* PointParameterfARB) (GLenum, float);
		void (APIENTRY* PointParameterfvARB) (GLenum, float *);

		//GL_ARB_vertex_blend
		void (APIENTRY* WeightbvARB) (int, char*);
		void (APIENTRY* WeightubvARB) (int, unsigned char*);
		void (APIENTRY* WeightsvARB) (int, short*);
		void (APIENTRY* WeightusvARB) (int, unsigned short*);
		void (APIENTRY* WeightivARB) (int, int*);
		void (APIENTRY* WeightuivARB) (int, unsigned int*);
		void (APIENTRY* WeightfvARB) (int, float*);
		void (APIENTRY* WeightdvARB) (int, double*);
		void (APIENTRY* WeightPointerARB) (int, GLenum, GLsizei, void *);
		void (APIENTRY* VertexBlendARB) (int);

		//GL_ARB_palette_matrix
		void (APIENTRY* CurrentPaletteMatrixARB) (int);
		void (APIENTRY* MatrixIndexubvARB) (int, unsigned char *);
		void (APIENTRY* MatrixIndexusvARB) (int, unsigned short *);
		void (APIENTRY* MatrixIndexuivARB) (int, unsigned int *);
		void (APIENTRY* MatrixIndexPointerARB) (int, GLenum, GLsizei, void *);

#ifdef WIN32
		//GL_ARB_render_texture
		bool (APIENTRY* wBindTexImageARB) (HPBUFFERARB, int);
		bool (APIENTRY* wReleaseTexImageARB) (HPBUFFERARB, int);
		bool (APIENTRY* wSetPbufferAttribARB) (HPBUFFERARB, const int *);
#endif

		//GL_ARB_window_pos
		void (APIENTRY* WindowPos2dARB) (double x, double y);
		void (APIENTRY* WindowPos2fARB) (float x, float y);
		void (APIENTRY* WindowPos2iARB) (int x, int y);
		void (APIENTRY* WindowPos2sARB) (short x, short y);
		void (APIENTRY* WindowPos2dvARB) (const double *p);
		void (APIENTRY* WindowPos2fvARB) (const float *p);
		void (APIENTRY* WindowPos2ivARB) (const int *p);
		void (APIENTRY* WindowPos2svARB) (const short *p);
		void (APIENTRY* WindowPos3dARB) (double x, double y, double z);
		void (APIENTRY* WindowPos3fARB) (float x, float y, float z);
		void (APIENTRY* WindowPos3iARB) (int x, int y, int z);
		void (APIENTRY* WindowPos3sARB) (short x, short y, short z);
		void (APIENTRY* WindowPos3dvARB) (const double *p);
		void (APIENTRY* WindowPos3fvARB) (const float *p);
		void (APIENTRY* WindowPos3ivARB) (const int *p);
		void (APIENTRY* WindowPos3svARB) (const short *p);

		//GL_ARB_vertex_program
		void (APIENTRY* VertexAttrib1sARB) (GLuint, short);
		void (APIENTRY* VertexAttrib1fARB) (GLuint, float);
		void (APIENTRY* VertexAttrib1dARB) (GLuint, double);
		void (APIENTRY* VertexAttrib2sARB) (GLuint, short, short);
		void (APIENTRY* VertexAttrib2fARB) (GLuint, float, float);
		void (APIENTRY* VertexAttrib2dARB) (GLuint, double, double);
		void (APIENTRY* VertexAttrib3sARB) (GLuint, short, short, short);
		void (APIENTRY* VertexAttrib3fARB) (GLuint, float, float, float);
		void (APIENTRY* VertexAttrib3dARB) (GLuint, double, double, double);
		void (APIENTRY* VertexAttrib4sARB) (GLuint, short, short, short, short);
		void (APIENTRY* VertexAttrib4fARB) (GLuint, float, float, float, float);
		void (APIENTRY* VertexAttrib4dARB) (GLuint, double, double, double, double);
		void (APIENTRY* VertexAttrib4NubARB) (GLuint, unsigned char, unsigned char, unsigned char, unsigned char);
		void (APIENTRY* VertexAttrib1svARB) (GLuint, const short *);
		void (APIENTRY* VertexAttrib1fvARB) (GLuint, const float *);
		void (APIENTRY* VertexAttrib1dvARB) (GLuint, const double *);
		void (APIENTRY* VertexAttrib2svARB) (GLuint, const short *);
		void (APIENTRY* VertexAttrib2fvARB) (GLuint, const float *);
		void (APIENTRY* VertexAttrib2dvARB) (GLuint, const double *);
		void (APIENTRY* VertexAttrib3svARB) (GLuint, const short *);
		void (APIENTRY* VertexAttrib3fvARB) (GLuint, const float *);
		void (APIENTRY* VertexAttrib3dvARB) (GLuint, const double *);
		void (APIENTRY* VertexAttrib4bvARB) (GLuint, const char *);
		void (APIENTRY* VertexAttrib4svARB) (GLuint, const short *);
		void (APIENTRY* VertexAttrib4ivARB) (GLuint, const int *);
		void (APIENTRY* VertexAttrib4ubvARB) (GLuint, const unsigned char *);
		void (APIENTRY* VertexAttrib4usvARB) (GLuint, const unsigned short *);
		void (APIENTRY* VertexAttrib4uivARB) (GLuint, const GLuint *);
		void (APIENTRY* VertexAttrib4fvARB) (GLuint, const float *);
		void (APIENTRY* VertexAttrib4dvARB) (GLuint, const double *);
		void (APIENTRY* VertexAttrib4NbvARB) (GLuint, const char *);
		void (APIENTRY* VertexAttrib4NsvARB) (GLuint, const short *);
		void (APIENTRY* VertexAttrib4NivARB) (GLuint, const int *);
		void (APIENTRY* VertexAttrib4NubvARB) (GLuint, const unsigned char *);
		void (APIENTRY* VertexAttrib4NusvARB) (GLuint, const unsigned short *);
		void (APIENTRY* VertexAttrib4NuivARB) (GLuint, const GLuint *);
		void (APIENTRY* VertexAttribPointerARB) (GLuint, int, GLenum, bool, GLsizei, const void *);
		void (APIENTRY* EnableVertexAttribArrayARB) (GLuint);
		void (APIENTRY* DisableVertexAttribArrayARB) (GLuint);
		void (APIENTRY* ProgramStringARB) (GLenum, GLenum, GLsizei, const void *);
		void (APIENTRY* BindProgramARB) (GLenum, GLuint);
		void (APIENTRY* DeleteProgramsARB) (GLsizei, const GLuint *);
		void (APIENTRY* GenProgramsARB) (GLsizei, GLuint *);
		void (APIENTRY* ProgramEnvParameter4dARB) (GLenum, GLuint, double, double, double, double);
		void (APIENTRY* ProgramEnvParameter4dvARB) (GLenum, GLuint, const double *);
		void (APIENTRY* ProgramEnvParameter4fARB) (GLenum, GLuint, float, float, float, float);
		void (APIENTRY* ProgramEnvParameter4fvARB) (GLenum, GLuint, const float *);
		void (APIENTRY* ProgramLocalParameter4dARB) (GLenum, GLuint, double, double, double, double);
		void (APIENTRY* ProgramLocalParameter4dvARB) (GLenum, GLuint, const double *);
		void (APIENTRY* ProgramLocalParameter4fARB) (GLenum, GLuint, float, float, float, float);
		void (APIENTRY* ProgramLocalParameter4fvARB) (GLenum, GLuint, const float *);
		void (APIENTRY* GetProgramEnvParameterdvARB) (GLenum, GLuint, double *);
		void (APIENTRY* GetProgramEnvParameterfvARB) (GLenum, GLuint, float *);
		void (APIENTRY* GetProgramLocalParameterdvARB) (GLenum, GLuint, double *);
		void (APIENTRY* GetProgramLocalParameterfvARB) (GLenum, GLuint, float *);
		void (APIENTRY* GetProgramivARB) (GLenum, GLenum, int *);
		void (APIENTRY* GetProgramStringARB) (GLenum, GLenum, void *);
		void (APIENTRY* GetVertexAttribdvARB) (GLuint, GLenum, double *);
		void (APIENTRY* GetVertexAttribfvARB) (GLuint, GLenum, float *);
		void (APIENTRY* GetVertexAttribivARB) (GLuint, GLenum, int *);
		void (APIENTRY* GetVertexAttribPointervARB) (GLuint, GLenum, void **);
		bool (APIENTRY* IsProgramARB) (GLuint);

		//GL_ARB_fragment_program

		//GL_ARB_vertex_buffer_object
		void (APIENTRY* BindBufferARB) (GLenum, GLuint);
		void (APIENTRY* DeleteBuffersARB) (GLsizei, const GLuint *);
		void (APIENTRY* GenBuffersARB) (GLsizei, GLuint *);
		bool (APIENTRY* IsBufferARB) (GLuint);
		void (APIENTRY* BufferDataARB) (GLenum, GLsizei*, const void *, GLenum);
		void (APIENTRY* BufferSubDataARB) (GLenum, GLint*, GLsizei*, const void *);
		void (APIENTRY* GetBufferSubDataARB) (GLenum, GLint*, GLsizei*, void *);
		void *(APIENTRY* MapBufferARB) (GLenum, GLenum);
		bool (APIENTRY* UnmapBufferARB) (GLenum);
		void (APIENTRY* GetBufferParameterivARB) (GLenum, GLenum, int *);
		void (APIENTRY* GetBufferPointervARB) (GLenum, GLenum, void **);

		//GL_ARB_occlusion_query
		void (APIENTRY* GenQueriesARB) (GLsizei n, GLuint *ids);
		void (APIENTRY* DeleteQueriesARB) (GLsizei n, const GLuint *ids);
		bool (APIENTRY* IsQueryARB) (GLuint id);
		void (APIENTRY* BeginQueryARB) (GLenum target, GLuint id);
		void (APIENTRY* EndQueryARB) (GLenum target);
		void (APIENTRY* GetQueryivARB) (GLenum target, GLenum pname, int *params);
		void (APIENTRY* GetQueryObjectivARB) (GLuint id, GLenum pname, int *params);
		void (APIENTRY* GetQueryObjectuivARB) (GLuint id, GLenum pname, GLuint *params);

		//GL_ARB_shader_objects
		void (APIENTRY* DeleteObjectARB) (GLhandleARB);
		GLhandleARB (APIENTRY* GetHandleARB) (GLenum);
		void (APIENTRY* DetachObjectARB) (GLhandleARB, GLhandleARB);
		GLhandleARB (APIENTRY* CreateShaderObjectARB) (GLenum);
		void (APIENTRY* ShaderSourceARB) (GLhandleARB, GLsizei, const GLcharARB* *, const GLint *);
		void (APIENTRY* CompileShaderARB) (GLhandleARB);
		GLhandleARB (APIENTRY* CreateProgramObjectARB) (void);
		void (APIENTRY* AttachObjectARB) (GLhandleARB, GLhandleARB);
		void (APIENTRY* LinkProgramARB) (GLhandleARB);
		void (APIENTRY* UseProgramObjectARB) (GLhandleARB);
		void (APIENTRY* ValidateProgramARB) (GLhandleARB);
		void (APIENTRY* Uniform1fARB) (GLint, GLfloat);
		void (APIENTRY* Uniform2fARB) (GLint, GLfloat, GLfloat);
		void (APIENTRY* Uniform3fARB) (GLint, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* Uniform4fARB) (GLint, GLfloat, GLfloat, GLfloat, GLfloat);
		void (APIENTRY* Uniform1iARB) (GLint, GLint);
		void (APIENTRY* Uniform2iARB) (GLint, GLint, GLint);
		void (APIENTRY* Uniform3iARB) (GLint, GLint, GLint, GLint);
		void (APIENTRY* Uniform4iARB) (GLint, GLint, GLint, GLint, GLint);
		void (APIENTRY* Uniform1fvARB) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform2fvARB) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform3fvARB) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform4fvARB) (GLint, GLsizei, const GLfloat *);
		void (APIENTRY* Uniform1ivARB) (GLint, GLsizei, const GLint *);
		void (APIENTRY* Uniform2ivARB) (GLint, GLsizei, const GLint *);
		void (APIENTRY* Uniform3ivARB) (GLint, GLsizei, const GLint *);
		void (APIENTRY* Uniform4ivARB) (GLint, GLsizei, const GLint *);
		void (APIENTRY* UniformMatrix2fvARB) (GLint, GLsizei, GLboolean, const GLfloat *);
		void (APIENTRY* UniformMatrix3fvARB) (GLint, GLsizei, GLboolean, const GLfloat *);
		void (APIENTRY* UniformMatrix4fvARB) (GLint, GLsizei, GLboolean, const GLfloat *);
		void (APIENTRY* GetObjectParameterfvARB) (GLhandleARB, GLenum, GLfloat *);
		void (APIENTRY* GetObjectParameterivARB) (GLhandleARB, GLenum, GLint *);
		void (APIENTRY* GetInfoLogARB) (GLhandleARB, GLsizei, GLsizei *, GLcharARB *);
		void (APIENTRY* GetAttachedObjectsARB) (GLhandleARB, GLsizei, GLsizei *, GLhandleARB *);
		GLint (APIENTRY* GetUniformLocationARB) (GLhandleARB, const GLcharARB *);
		void (APIENTRY* GetActiveUniformARB) (GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *);
		void (APIENTRY* GetUniformfvARB) (GLhandleARB, GLint, GLfloat *);
		void (APIENTRY* GetUniformivARB) (GLhandleARB, GLint, GLint *);
		void (APIENTRY* GetShaderSourceARB) (GLhandleARB, GLsizei, GLsizei *, GLcharARB *);

		//GL_ARB_vertex_shader
		void (APIENTRY* BindAttribLocationARB) (GLhandleARB, GLuint, const GLcharARB *);
		void (APIENTRY* GetActiveAttribARB) (GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *);
		int	(APIENTRY* GetAttribLocationARB) (GLhandleARB, const GLcharARB *);

		//GL_ARB_draw_buffers
		void (APIENTRY* DrawBuffersARB) (GLsizei, const GLenum *);

		//GL_ARB_color_buffer_float
		void (APIENTRY* ClampColorARB) (GLenum target, GLenum clamp);

		//GL_ARB_texture_rectangle
		//GL_ARB_color_buffer_float
		//WGL_ARB_pixel_format_float
		//GLX_ARB_fbconfig_float
		//GL_ARB_half_float_pixel
		//GL_ARB_texture_float
		//GL_ARB_pixel_buffer_object 
	} gsextarb;

	typedef struct
	{
		//GL_EXT_blend_color
		void (APIENTRY* BlendColorEXT) (GLclampf, GLclampf, GLclampf, GLclampf);

		//GL_EXT_polygon_offset
		void (APIENTRY* PolygonOffsetEXT) (float, float);

		//GL_EXT_texture3d
		void (APIENTRY* TexImage3DEXT) (GLenum, int, GLenum, GLsizei, GLsizei, GLsizei, int, GLenum, GLenum, const void*);

		//GL_EXT_texture_filter4
		//void TexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const float* weights);
		//void GetTexFilterFuncSGIS(GLenum target, GLenum filter, float* weights);

		//GL_EXT_subtexture
		void (APIENTRY* TexSubImage1DEXT) (GLenum, int, int, GLsizei, GLenum, GLenum, const void*);
		void (APIENTRY* TexSubImage2DEXT) (GLenum, int, int, int, GLsizei, GLsizei, GLenum, GLenum, const void*);
		void (APIENTRY* TexSubImage3DEXT) (GLenum, int, int, int, int, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void*);

		//GL_EXT_copy_texture
		void CopyTexImage1DEXT(GLenum target,int level,GLenum internalformat,int x,int y,GLsizei width,int border);
		void CopyTexImage2DEXT(GLenum target,int level,GLenum internalformat,int x,int y,GLsizei width,GLsizei height,int border);
		void CopyTexSubImage1DEXT(GLenum target,int level,int xoffset,int x,int y,GLsizei width);
		void CopyTexSubImage2DEXT(GLenum target,int level,int xoffset,int yoffset,int x,int y,GLsizei width,GLsizei height);
		void CopyTexSubImage3DEXT(GLenum target,int level,int xoffset,int yoffset,int zoffset,int x,int y,GLsizei width,GLsizei height);

		//GL_EXT_histogram

		//GL_EXT_convolution
		void ConvolutionFilter1DEXT(GLenum target,GLenum internalformat,GLsizei width,GLenum format,GLenum type,const void* image);
		void ConvolutionFilter2DEXT(GLenum target,GLenum internalformat,GLsizei width,GLsizei height,GLenum format,GLenum type,const void* image);
		void CopyConvolutionFilter1DEXT(GLenum target,GLenum internalformat,int x,int y,GLsizei width);
		void CopyConvolutionFilter2DEXT(GLenum target,GLenum internalformat,int x,int y,GLsizei width,GLsizei height);
		void GetConvolutionFilterEXT(GLenum target,GLenum format,GLenum type,void* image);
		void SeparableFilter2DEXT(GLenum target,GLenum internalformat,GLsizei width,GLsizei height,GLenum format,GLenum type,const void* row,const void* column);
		void GetSeparableFilterEXT(GLenum target,GLenum format,GLenum type,void* row,void* column,void* span);
		void ConvolutionParameteriEXT(GLenum target,GLenum pname,int param);
		void ConvolutionParameterivEXT(GLenum target,GLenum pname,const int* params);
		void ConvolutionParameterfEXT(GLenum target,GLenum pname,float param);
		void ConvolutionParameterfvEXT(GLenum target,GLenum pname,const float* params);
		void GetConvolutionParameterivEXT(GLenum target,GLenum pname,int* params);
		void GetConvolutionParameterfvEXT(GLenum target,GLenum pname,float* params);
		
		//GL_EXT_color_table

		//GL_SGIS_pixel_texture
		//void PixelTexGenParameter{if}SGIS(GLenum pname, T param);
		//void GetPixelTexGenParameter{if}vSGIS(GLenum pname, T params);

		//GL_SGIX_pixel_texture
		void PixelTexGenSGIX(GLenum mode);

		//GL_SGIS_texture4d
		void TexImage4DSGIS(GLenum target,int level,GLenum internalformat,GLsizei width,GLsizei height,GLsizei depth,GLsizei extent,int border,GLenum format,GLenum type,const void* pixels);
		void TexSubImage4DSGIS(GLenum target,int level,int xoffset,int yoffset,int zoffset,int woffset,GLsizei width,GLsizei height,GLsizei depth,GLsizei extent,GLenum format,GLenum type,const void* pixels);

		//GL_EXT_texture_object
		void GenTexturesEXT(GLsizei n,GLuint* textures);
		void DeleteTexturesEXT(GLsizei n,const GLuint* textures);
		void BindTextureEXT(GLenum target,GLuint texture);
		void PrioritizeTexturesEXT(GLsizei n,const GLuint* textures,const GLclampf* priorities);
		bool AreTexturesResidentEXT(GLsizei n,const GLuint* textures,bool* residences);
		bool IsTextureEXT(GLuint texture);

		//GL_SGIS_detail_texture

		//GL_SGIS_sharpen_texture

		//GL_EXT_vertex_array
		void ArrayElementEXT(int i);
		void DrawArraysEXT(GLenum mode,int first,GLsizei count);
		void VertexPointerEXT(int size,GLenum type,GLsizei stride,GLsizei count,const void* pointer);
		void NormalPointerEXT(GLenum type,GLsizei stride,GLsizei count,const void* pointer);
		void ColorPointerEXT(int size,GLenum type,GLsizei stride,GLsizei count,const void* pointer);
		void IndexPointerEXT(GLenum type,GLsizei stride,GLsizei count,const void* pointer);
		void TexCoordPointerEXT(int size,GLenum type,GLsizei stride,GLsizei count,const void* pointer);
		void EdgeFlagPointerEXT(GLsizei stride,GLsizei count,const bool* pointer);
		void GetPointervEXT(GLenum pname,void** params);

		//GL_EXT_blend_minmax
		void BlendEquationEXT(GLenum mode);

		//GLX_SGI_swap_control
		int XSwapIntervalSGI(int interval);

		//GLX_SGI_video_sync
#ifdef USE_X
		int XGetVideoSyncSGI(GLuint *count);
		int XWaitVideoSyncSGI(int divisor, int remainder, unsigned int *count);
#endif

		//GLX_SGI_make_current_read
#ifdef USE_X
		bool XMakeCurrentReadSGI(Display*,GLXDrawable,GLXDrawable,GLXContext);
		GLXDrawable XGetCurrentReadDrawableSGI(void);
#endif

		//GLX_SGIX_video_source
#ifdef USE_X
		typedef XID GLXVideoSourceSGIX;
		GLXVideoSourceSGIX XCreateGLXVideoSourceSGIX(Display *display,int screen,VLServer server,VLPath path,int nodeClass,VLNode drainNode);
		void XDestroyGLXVideoSourceSGIX(Display *dpy,GLXVideoSourceSGIX glxvideosource);
#endif

		//GLX_EXT_import_context
#ifdef USE_X
		Display *XGetCurrentDisplayEXT();
		int XQueryContextInfoEXT(Display *dpy, GLXContext context, int attribute,int *value);
		GLXContextID XGetContextIDEXT(const GLXContext context);
		GLXContext XImportContextEXT(Display *dpy, GLXContextID contextID);
		void XFreeContextEXT(Display *dpy, GLXContext context);
#endif

		//GLX_SGIX_fbconfig
#ifdef USE_X
		int XGetFBConfigAttribSGIX(Display *dpy,GLXFBConfigSGIX config,int attribute,int *value);
		GLXFBConfigSGIX *XChooseFBConfigSGIX(Display *dpy,int screen,const int *attrib_list,int *nelements);
		GLXPixmap XCreateGLXPixmapWithConfigSGIX(Display *dpy,GLXFBConfig config,Pixmap pixmap);
		GLXContext XCreateContextWithConfigSGIX(Display *dpy,GLXFBConfig config,int render_type,GLXContext share_list,Bool direct);
		XVisualInfo *XGetVisualFromFBConfigSGIX(Display *dpy,GLXFBConfig config);
		GLXFBConfigSGIX XGetFBConfigFromVisualSGIX(Display *dpy,XVisualInfo *vis);
#endif

		//GLX_SGIX_pbuffer
#ifdef USE_X
		GLXPbuffer XCreateGLXPbufferSGIX(Display *dpy,GLXFBConfig config,unsigned int width,unsigned int height,int *attrib_list);
		void XDestroyGLXPbufferSGIX(Display *dpy,GLXPbuffer pbuf);
		void XQueryGLXPbufferSGIX(Display *dpy,GLXPbuffer pbuf,int attribute,unsigned int *value);
		void XSelectEventSGIX(Display *dpy,GLXDrawable drawable,unsigned long mask);
		void XGetSelectedEventSGIX(Display *dpy,GLXDrawable drawable,unsigned long *mask);
#endif

		//GL_SGIX_sprite
		void SpriteParameteriSGIX(GLenum pname, int param);
		void SpriteParameterfSGIX(GLenum pname, float param);
		void SpriteParameterivSGIX(GLenum pname, int* params);
		void SpriteParameterfvSGIX(GLenum pname, float* params);

		//GL_SGIX_texture_multi_buffer

		//GL_EXT_point_parameters
		void glPointParameterfEXT ( GLenum pname, GLfloat param );
		void glPointParameterfvEXT ( GLenum pname, GLfloat *params );

		//GL_SGIX_instruments
		void InstrumentsBufferSGIX(GLsizei size, int *buf);
		void StartInstrumentsSGIX(void);
		void StopInstrumentsSGIX(int marker);
		void ReadInstrumentsSGIX(int marker);
		int PollInstrumentsSGIX(int *markerp);
		int GetInstrumentsSGIX(void);

		//GL_SGIX_framezoom
		void FrameZoomSGIX(GLint factor);

		//GL_SGIX_tag_sample_buffer
		void TagSampleBufferSGIX(void);

		//GL_SGIX_reference_plane
		void glReferencePlaneSGIX(const GLdouble *equation);

		//GL_SGIX_flush_raster
		void FlushRasterSGIX(void);

		//GLX_SGI_cushion
#ifdef USE_X
		void glXCushionSGI(Display *dpy, Window window, float cushion);
#endif

		//GL_SGIS_fog_func
		void FogFuncSGIS(GLsizei n, const float* points);
		void GetFogFuncSGIS(float *points);

		//GL_EXT_color_subtable
		void ColorSubTableEXT (GLenum target,GLsizei start,GLsizei count,GLenum format,GLenum type,const void *data);
		void CopyColorSubTableEXT (GLenum target,GLsizei start,int x,int y,GLsizei width);

		//GL_EXT_paletted_texture
		void (APIENTRY *ColorTableEXT)(GLenum,GLenum,GLsizei,GLenum,GLenum,const void *);
		void (APIENTRY *GetColorTableEXT)(GLenum,GLenum,GLenum,void *);
		void (APIENTRY *GetColorTableParameterivEXT)(GLenum target,GLenum,int *);
		void (APIENTRY *GetColorTableParameterfvEXT)(GLenum target,GLenum,float *);

		//GL_SGIX_list_priority
		//GL_SGIX_ir_instrument1
		//GLX_SGIX_video_resize
		//GL_SGIX_texture_lod_bias
		//GLU_SGI_filter4_parameters
		//GLX_SGIX_dm_buffer
		//GL_SGIX_shadow_ambient
		//GLX_SGIX_swap_group
		//GLX_SGIX_swap_barrier
		//GL_EXT_index_texture
		//GL_EXT_index_material
		//GL_EXT_index_func
		//GL_EXT_index_array_formats
		//GL_EXT_compiled_vertex_array
		//GL_EXT_cull_vertex
		//GLU_EXT_nurbs_tessellator
		//GL_SGIX_ycrcb
		//GL_EXT_fragment_lighting
		//GL_IBM_rasterpos_clip
		//GL_HP_texture_lighting
		//GL_EXT_draw_range_elements
		//GL_WIN_phong_shading
		//GL_WIN_specular_fog
		//GLX_SGIS_color_range
		//GL_SGIS_color_range
		//GL_EXT_light_texture
		//GL_SGIX_blend_alpha_minmax
		//GL_EXT_scene_marker
		//GLX_EXT_scene_marker
		//GL_SGIX_pixel_texture_bits
		//GL_EXT_bgra
		//GL_SGIX_async
		//GL_SGIX_async_pixel
		//GL_SGIX_async_histogram
		//GL_INTEL_texture_scissor
		//GL_INTEL_parallel_arrays
		//GL_HP_occlusion_test
		//GL_EXT_pixel_transform
		//GL_EXT_pixel_transform_color_table
		//GL_EXT_shared_texture_palette
		//GLX_SGIS_blended_overlay
		//GL_EXT_separate_specular_color
		//GL_EXT_secondary_color
		//GL_EXT_texture_env
		//GL_EXT_texture_perturb_normal
		//GL_EXT_multi_draw_arrays
		//GL_SUN_multi_draw_arrays
		//GL_EXT_fog_coord
		//GL_REND_screen_coordinates
		//GL_EXT_coordinate_frame
		//GL_EXT_texture_env_combine
		//GL_APPLE_specular_vector
		//GL_APPLE_transform_hint
		//GL_SUNX_constant_data
		//GL_SUN_global_alpha
		//GL_SUN_triangle_list
		//GL_SUN_vertex
		//WGL_EXT_display_color_table
		//WGL_EXT_extensions_string
		//WGL_EXT_make_current_read
		//WGL_EXT_pixel_format
		//WGL_EXT_pbuffer
		//WGL_EXT_swap_control
		//GL_EXT_blend_func_separate
		//GL_INGR_color_clamp
		//GL_INGR_interlace_read
		//GL_EXT_stencil_wrap
		//WGL_EXT_depth_float
		//GL_EXT_422_pixels
		//GL_NV_texgen_reflection
		//GL_SGIX_texture_range
		//GL_SUN_convolution_border_modes
		//GLX_SUN_get_transparent_index
		//GL_EXT_texture_env_add
		//GL_EXT_texture_lod_bias
		//GL_EXT_texture_filter_anisotropic
		//GL_EXT_vertex_weighting
		//GL_NV_light_max_exponent
		//GL_NV_vertex_array_range
		//GL_NV_register_combiners
		//GL_NV_fog_distance
		//GL_NV_texgen_emboss
		//GL_NV_blend_square
		//GL_NV_texture_env_combine4
		//GL_MESA_resize_buffers
		//GL_MESA_window_pos
		//GL_EXT_texture_compression_s3tc
		//GL_IBM_cull_vertex
		//GL_IBM_multimode_draw_arrays
		//GL_IBM_vertex_array_lists
		//GL_3DFX_texture_compression_FXT1
		//GL_3DFX_multisample
		//GL_3DFX_tbuffer
		//WGL_EXT_multisample
		//GL_EXT_multisample
		//GL_SGIX_vertex_preclip
		//GL_SGIX_vertex_preclip_hint
		//GL_SGIX_resample
		//GL_SGIS_texture_color_mask
		//GLX_MESA_copy_sub_buffer
		//GLX_MESA_pixmap_colormap
		//GLX_MESA_release_buffers
		//GLX_MESA_set_3dfx_mode
		//GL_EXT_texture_env_dot3
		//GL_ATI_texture_mirror_once
		//GL_NV_fence
		//GL_IBM_static_data
		//GL_IBM_texture_mirrored_repeat
		//GL_NV_evaluators
		//GL_NV_packed_depth_stencil
		//GL_NV_register_combiners2
		//GL_NV_texture_compression_vtc
		//GL_NV_texture_rectangle
		//GL_NV_texture_shader
		//GL_NV_texture_shader2
		//GL_NV_vertex_array_range2
		//GL_NV_vertex_program
		//GLX_SGIX_visual_select_group
		//GL_SGIX_texture_coordinate_clamp
		//GLX_OML_swap_method
		//GLX_OML_sync_control
		//GL_OML_interlace
		//GL_OML_subsample
		//GL_OML_resample
		//WGL_OML_sync_control
		//GL_NV_copy_depth_to_color
		//GL_ATI_envmap_bumpmap
		//GL_ATI_fragment_shader
		//GL_ATI_pn_triangles
		//GL_ATI_vertex_array_object
		//GL_EXT_vertex_shader
		//GL_ATI_vertex_streams
		//WGL_I3D_digital_video_control
		//WGL_I3D_gamma
		//WGL_I3D_genlock
		//WGL_I3D_image_buffer
		//WGL_I3D_swap_frame_lock
		//WGL_I3D_swap_frame_usage
		//GL_ATI_element_array
		//GL_SUN_mesh_array
		//GL_SUN_slice_accum
		//GL_NV_multisample_filter_hint
		//GL_NV_depth_clamp
		//GL_NV_occlusion_query
		//GL_NV_point_sprite
		//WGL_NV_render_depth_texture
		//WGL_NV_render_texture_rectangle
		//GL_NV_texture_shader3
		//GL_NV_vertex_program1_1
		//GL_EXT_shadow_funcs
		//GL_EXT_stencil_two_side
		//GL_ATI_text_fragment_shader
		//GL_APPLE_client_storage
		//GL_APPLE_element_array
		//GL_APPLE_fence
		//GL_APPLE_vertex_array_object
		//GL_APPLE_vertex_array_range
		//GL_APPLE_ycbcr_422
		//GL_S3_s3tc
		//GL_ATI_draw_buffers
		//WGL_ATI_pixel_format_float
		//GL_ATI_texture_env_combine3
		//GL_ATI_texture_float
		//GL_NV_float_buffer
		//WGL_NV_float_buffer
		//GL_NV_fragment_program
		//GL_NV_half_float
		//GL_NV_pixel_data_range
		//GL_NV_primitive_restart
		//GL_NV_texture_expand_normal
		//GL_NV_vertex_program2
		//GL_ATI_map_object_buffer
		//GL_ATI_separate_stencil
		//GL_ATI_vertex_attrib_array_object
		//GL_OES_byte_coordinates
		//GL_OES_fixed_point
		//GL_OES_single_precision
		//GL_OES_compressed_paletted_texture
		//GL_OES_read_format
		//GL_OES_query_matrix
		//GL_EXT_depth_bounds_test
		//GL_EXT_texture_mirror_clamp
		//GL_EXT_blend_equation_separate
		//GL_MESA_pack_invert
		//GL_MESA_ycbcr_texture
		//GL_EXT_pixel_buffer_object
		//GL_NV_fragment_program_option
		//GL_NV_fragment_program2
		//GL_NV_vertex_program2_option
		//GL_NV_vertex_program3
		//GLX_SGIX_hyperpipe
		//GLX_MESA_agp_offset
		//GL_EXT_texture_compression_dxt1

		//GL_EXT_framebuffer_object
		bool (APIENTRY* IsRenderbufferEXT) (GLuint);
		void (APIENTRY* BindRenderbufferEXT) (GLenum, GLuint);
		void (APIENTRY* DeleteRenderbuffersEXT) (GLsizei, const GLuint *);
		void (APIENTRY* GenRenderbuffersEXT) (GLsizei, GLuint *);
		void (APIENTRY* RenderbufferStorageEXT) (GLenum, GLenum, GLsizei, GLsizei);
		void (APIENTRY* GetRenderbufferParameterivEXT) (GLenum, GLenum, int *);
		bool (APIENTRY* IsFramebufferEXT) (GLuint);
		void (APIENTRY* BindFramebufferEXT) (GLenum, GLuint);
		void (APIENTRY* DeleteFramebuffersEXT) (GLsizei, const GLuint *);
		void (APIENTRY* GenFramebuffersEXT) (GLsizei, GLuint *);
		GLenum (APIENTRY* CheckFramebufferStatusEXT) (GLenum);
		void (APIENTRY* FramebufferTexture1DEXT) (GLenum, GLenum, GLenum, GLuint, int);
		void (APIENTRY* FramebufferTexture2DEXT) (GLenum, GLenum, GLenum, GLuint, int);
		void (APIENTRY* FramebufferTexture3DEXT) (GLenum, GLenum, GLenum, GLuint, int, int);
		void (APIENTRY* FramebufferRenderbufferEXT) (GLenum, GLenum, GLenum, GLuint);
		void (APIENTRY* GetFramebufferAttachmentParameterivEXT) (GLenum, GLenum, GLenum, int *);
		void (APIENTRY* GenerateMipmapEXT) (GLenum);

		//GL_GREMEDY_string_marker
		//GL_EXT_packed_depth_stencil
		//WGL_3DL_stereo_control
		//GL_EXT_stencil_clear_tag
		//GL_EXT_texture_sRGB
		//GL_EXT_framebuffer_blit
		//GL_EXT_framebuffer_multisample
		//GL_MESAX_texture_stack 
	} gsextext;

	extern gsext12 _ext12;
	extern gsext13 _ext13;
	extern gsext14 _ext14;
	extern gsext15 _ext15;
	extern gsext20 _ext20;
	extern gsextarb _extarb;
	extern gsextext _extext;

	inline gsext12 *get12 () { return &_ext12; }
	inline gsext13 *get13 () { return &_ext13; }
	inline gsext14 *get14 () { return &_ext14; }
	inline gsext15 *get15 () { return &_ext15; }
	inline gsext20 *get20 () { return &_ext20; }
	inline gsextarb *getarb () { return &_extarb; }
	inline gsextext *getext () { return &_extext; }

	void initExtensions ();

	gsutil::gsstring getExtensions ();
	gsutil::gsstring getARBExtensions ();
	gsutil::gsstring getEXTExtensions ();

	/*1.2.1 extension*/
	#define glBlendColor (get12 ()->BlendColor)
	#define glBlendEquation (get12 ()->BlendEquation)
	#define glDrawRangeElements (get12 ()->DrawRangeElements)
	#define glColorTable (get12 ()->ColorTable)
	#define glColorTableParameterfv (get12 ()->ColorTableParameterfv)
	#define glColorTableParameteriv (get12 ()->ColorTableParameteriv)
	#define glCopyColorTable (get12 ()->CopyColorTable)
	#define glGetColorTable (get12 ()->GetColorTable)
	#define glGetColorTableParameterfv (get12 ()->GetColorTableParameterfv)
	#define glGetColorTableParameteriv (get12 ()->GetColorTableParameteriv)
	#define glColorSubTable (get12 ()->ColorSubTable)
	#define glCopyColorSubTable (get12 ()->CopyColorSubTable)
	#define glConvolutionFilter1D (get12 ()->ConvolutionFilter1D)
	#define glConvolutionFilter2D (get12 ()->ConvolutionFilter2D)
	#define glConvolutionParameterf (get12 ()->ConvolutionParameterf)
	#define glConvolutionParameterfv (get12 ()->ConvolutionParameterfv)
	#define glConvolutionParameteri (get12 ()->ConvolutionParameteri)
	#define glConvolutionParameteriv (get12 ()->ConvolutionParameteriv)
	#define glCopyConvolutionFilter1D (get12 ()->CopyConvolutionFilter1D)
	#define glCopyConvolutionFilter2D (get12 ()->CopyConvolutionFilter2D)
	#define glGetConvolutionFilter (get12 ()->GetConvolutionFilter)
	#define glGetConvolutionParameterfv (get12 ()->GetConvolutionParameterfv)
	#define glGetConvolutionParameteriv (get12 ()->GetConvolutionParameteriv)
	#define glGetSeparableFilter (get12 ()->GetSeparableFilter)
	#define glSeparableFilter2D (get12 ()->SeparableFilter2D)
	#define glGetHistogram (get12 ()->GetHistogram)
	#define glGetHistogramParameterfv (get12 ()->GetHistogramParameterfv)
	#define glGetHistogramParameteriv (get12 ()->GetHistogramParameteriv)
	#define glGetMinmax (get12 ()->GetMinmax)
	#define glGetMinmaxParameterfv (get12 ()->GetMinmaxParameterfv)
	#define glGetMinmaxParameteriv (get12 ()->GetMinmaxParameteriv)
	#define glHistogram (get12 ()->Histogram)
	#define glMinmax (get12 ()->Minmax)
	#define glResetHistogram (get12 ()->ResetHistogram)
	#define glResetMinmax (get12 ()->ResetMinmax)
	#define glTexImage3D (get12 ()->TexImage3D)
	#define glTexSubImage3D (get12 ()->TexSubImage3D)
	#define glCopyTexSubImage3D (get12 ()->CopyTexSubImage3D)

	/*1.3 extensions*/
	#define glActiveTexture (get13 ()->ActiveTexture)
	#define glClientActiveTexture (get13 ()->ClientActiveTexture)
	#define glMultiTexCoord1d (get13 ()->MultiTexCoord1d)
	#define glMultiTexCoord1dv (get13 ()->MultiTexCoord1dv)
	#define glMultiTexCoord1f (get13 ()->MultiTexCoord1f)
	#define glMultiTexCoord1fv (get13 ()->MultiTexCoord1fv)
	#define glMultiTexCoord1i (get13 ()->MultiTexCoord1i)
	#define glMultiTexCoord1iv (get13 ()->MultiTexCoord1iv)
	#define glMultiTexCoord1s (get13 ()->MultiTexCoord1s)
	#define glMultiTexCoord1sv (get13 ()->MultiTexCoord1sv)
	#define glMultiTexCoord2d (get13 ()->MultiTexCoord2d)
	#define glMultiTexCoord2dv (get13 ()->MultiTexCoord2dv)
	#define glMultiTexCoord2f (get13 ()->MultiTexCoord2f)
	#define glMultiTexCoord2fv (get13 ()->MultiTexCoord2fv)
	#define glMultiTexCoord2i (get13 ()->MultiTexCoord2i)
	#define glMultiTexCoord2iv (get13 ()->MultiTexCoord2iv)
	#define glMultiTexCoord2s (get13 ()->MultiTexCoord2s)
	#define glMultiTexCoord2sv (get13 ()->MultiTexCoord2sv)
	#define glMultiTexCoord3d (get13 ()->MultiTexCoord3d)
	#define glMultiTexCoord3dv (get13 ()->MultiTexCoord3dv)
	#define glMultiTexCoord3f (get13 ()->MultiTexCoord3f)
	#define glMultiTexCoord3fv (get13 ()->MultiTexCoord3fv)
	#define glMultiTexCoord3i (get13 ()->MultiTexCoord3i)
	#define glMultiTexCoord3iv (get13 ()->MultiTexCoord3iv)
	#define glMultiTexCoord3s (get13 ()->MultiTexCoord3s)
	#define glMultiTexCoord3sv (get13 ()->MultiTexCoord3sv)
	#define glMultiTexCoord4d (get13 ()->MultiTexCoord4d)
	#define glMultiTexCoord4dv (get13 ()->MultiTexCoord4dv)
	#define glMultiTexCoord4f (get13 ()->MultiTexCoord4f)
	#define glMultiTexCoord4fv (get13 ()->MultiTexCoord4fv)
	#define glMultiTexCoord4i (get13 ()->MultiTexCoord4i)
	#define glMultiTexCoord4iv (get13 ()->MultiTexCoord4iv)
	#define glMultiTexCoord4s (get13 ()->MultiTexCoord4s)
	#define glMultiTexCoord4sv (get13 ()->MultiTexCoord4sv)
	#define glLoadTransposeMatrixf (get13 ()->LoadTransposeMatrixf)
	#define glLoadTransposeMatrixd (get13 ()->LoadTransposeMatrixd)
	#define glMultTransposeMatrixf (get13 ()->MultTransposeMatrixf)
	#define glMultTransposeMatrixd (get13 ()->MultTransposeMatrixd)
	#define glSampleCoverage (get13 ()->SampleCoverage)
	#define glCompressedTexImage3D (get13 ()->CompressedTexImage3D)
	#define glCompressedTexImage2D (get13 ()->CompressedTexImage2D)
	#define glCompressedTexImage1D (get13 ()->CompressedTexImage1D)
	#define glCompressedTexSubImage3D (get13 ()->CompressedTexSubImage3D)
	#define glCompressedTexSubImage2D (get13 ()->CompressedTexSubImage2D)
	#define glCompressedTexSubImage1D (get13 ()->CompressedTexSubImage1D)
	#define glGetCompressedTexImage (get13 ()->GetCompressedTexImage)

	/*1.4 extensions*/
	#define glBlendFuncSeparate (get14 ()->BlendFuncSeparate)
	#define glFogCoordf (get14 ()->FogCoordf)
	#define glFogCoordfv (get14 ()->FogCoordfv)
	#define glFogCoordd (get14 ()->FogCoordd)
	#define glFogCoorddv (get14 ()->FogCoorddv)
	#define glFogCoordPointer (get14 ()->FogCoordPointer)
	#define glMultiDrawArrays (get14 ()->MultiDrawArrays)
	#define glMultiDrawElements (get14 ()->MultiDrawElements)
	#define glPointParameterf (get14 ()->PointParameterf)
	#define glPointParameterfv (get14 ()->PointParameterfv)
	#define glPointParameteri (get14 ()->PointParameteri)
	#define glPointParameteriv (get14 ()->PointParameteriv)
	#define glSecondaryColor3b (get14 ()->SecondaryColor3b)
	#define glSecondaryColor3bv (get14 ()->SecondaryColor3bv)
	#define glSecondaryColor3d (get14 ()->SecondaryColor3d)
	#define glSecondaryColor3dv (get14 ()->SecondaryColor3dv)
	#define glSecondaryColor3f (get14 ()->SecondaryColor3f)
	#define glSecondaryColor3fv (get14 ()->SecondaryColor3fv)
	#define glSecondaryColor3i (get14 ()->SecondaryColor3i)
	#define glSecondaryColor3iv (get14 ()->SecondaryColor3iv)
	#define glSecondaryColor3s (get14 ()->SecondaryColor3s)
	#define glSecondaryColor3sv (get14 ()->SecondaryColor3sv)
	#define glSecondaryColor3ub (get14 ()->SecondaryColor3ub)
	#define glSecondaryColor3ubv (get14 ()->SecondaryColor3ubv)
	#define glSecondaryColor3ui (get14 ()->SecondaryColor3ui)
	#define glSecondaryColor3uiv (get14 ()->SecondaryColor3uiv)
	#define glSecondaryColor3us (get14 ()->SecondaryColor3us)
	#define glSecondaryColor3usv (get14 ()->SecondaryColor3usv)
	#define glSecondaryColorPointer (get14 ()->SecondaryColorPointer)
	#define glWindowPos2d (get14 ()->WindowPos2d)
	#define glWindowPos2dv (get14 ()->WindowPos2dv)
	#define glWindowPos2f (get14 ()->WindowPos2f)
	#define glWindowPos2fv (get14 ()->WindowPos2fv)
	#define glWindowPos2i (get14 ()->WindowPos2i)
	#define glWindowPos2iv (get14 ()->WindowPos2iv)
	#define glWindowPos2s (get14 ()->WindowPos2s)
	#define glWindowPos2sv (get14 ()->WindowPos2sv)
	#define glWindowPos3d (get14 ()->WindowPos3d)
	#define glWindowPos3dv (get14 ()->WindowPos3dv)
	#define glWindowPos3f (get14 ()->WindowPos3f)
	#define glWindowPos3fv (get14 ()->WindowPos3fv)
	#define glWindowPos3i (get14 ()->WindowPos3i)
	#define glWindowPos3iv (get14 ()->WindowPos3iv)
	#define glWindowPos3s (get14 ()->WindowPos3s)
	#define glWindowPos3sv (get14 ()->WindowPos3sv)

	/* 1.5 extentions*/
	#define glGenQueries (get15 ()->GenQueries)
	#define glDeleteQueries (get15 ()->DeleteQueries)
	#define glIsQuery (get15 ()->IsQuery)
	#define glBeginQuery (get15 ()->BeginQuery)
	#define glEndQuery (get15 ()->EndQuery)
	#define glGetQueryiv (get15 ()->GetQueryiv)
	#define glGetQueryObjectiv (get15 ()->GetQueryObjectiv)
	#define glGetQueryObjectuiv (get15 ()->GetQueryObjectuiv)
	#define glBindBuffer (get15 ()->BindBuffer)
	#define glDeleteBuffers (get15 ()->DeleteBuffers)
	#define glGenBuffers (get15 ()->GenBuffers)
	#define glIsBuffer (get15 ()->IsBuffer)
	#define glBufferData (get15 ()->BufferData)
	#define glBufferSubData (get15 ()->BufferSubData)
	#define glGetBufferSubData (get15 ()->GetBufferSubData)
	#define glMapBuffer (get15 ()->MapBuffer)
	#define glUnmapBuffer (get15 ()->UnmapBuffer)
	#define glGetBufferParameteriv (get15 ()->GetBufferParameteriv)
	#define glGetBufferPointerv (get15 ()->GetBufferPointerv)

	/*2.0 extensions*/
	#define glBlendEquationSeparate (get20 ()->BlendEquationSeparate)
	#define glDrawBuffers (get20 ()->DrawBuffers)
	#define glStencilOpSeparate  (get20 ()->StencilOpSeparate)
	#define glStencilFuncSeparate (get20 ()->StencilFuncSeparate)
	#define glStencilMaskSeparate (get20 ()->StencilMaskSeparate)
	#define glAttachShader (get20 ()->AttachShader)
	#define glBindAttribLocation (get20 ()->BindAttribLocation)
	#define glCompileShader (get20 ()->CompileShader)
	#define glCreateProgram (get20 ()->CreateProgram)
	#define glCreateShader (get20 ()->CreateShader)
	#define glDeleteProgram (get20 ()->DeleteProgram)
	#define glDeleteShader (get20 ()->DeleteShader)
	#define glDetachShader (get20 ()->DetachShader)
	#define glDisableVertexAttribArray (get20 ()->DisableVertexAttribArray)
	#define glEnableVertexAttribArray (get20 ()->EnableVertexAttribArray)
	#define glGetActiveAttrib (get20 ()->GetActiveAttrib)
	#define glGetActiveUniform (get20 ()->GetActiveUniform)
	#define glGetAttachedShaders (get20 ()->GetAttachedShaders)
	#define glGetAttribLocation (get20 ()->GetAttribLocation)
	#define glGetProgramiv (get20 ()->GetProgramiv)
	#define glGetProgramInfoLog (get20 ()->GetProgramInfoLog)
	#define glGetShaderiv (get20 ()->GetShaderiv)
	#define glGetShaderInfoLog (get20 ()->GetShaderInfoLog)
	#define glGetShaderSource (get20 ()->GetShaderSource)
	#define glGetUniformLocation (get20 ()->GetUniformLocation)
	#define glGetUniformfv (get20 ()->GetUniformfv)
	#define glGetUniformiv (get20 ()->GetUniformiv)
	#define glGetVertexAttribdv (get20 ()->GetVertexAttribdv)
	#define glGetVertexAttribfv (get20 ()->GetVertexAttribfv)
	#define glGetVertexAttribiv (get20 ()->GetVertexAttribiv)
	#define glGetVertexAttribPointerv (get20 ()->GetVertexAttribPointerv)
	#define glIsProgram (get20 ()->IsProgram)
	#define glIsShader (get20 ()->IsShader)
	#define glLinkProgram (get20 ()->LinkProgram)
	#define glShaderSource (get20 ()->ShaderSource)
	#define glUseProgram (get20 ()->UseProgram)
	#define glUniform1f (get20 ()->Uniform1f)
	#define glUniform2f (get20 ()->Uniform2f)
	#define glUniform3f (get20 ()->Uniform3f)
	#define glUniform4f (get20 ()->Uniform4f)
	#define glUniform1i (get20 ()->Uniform1i)
	#define glUniform2i (get20 ()->Uniform2i)
	#define glUniform3i (get20 ()->Uniform3i)
	#define glUniform4i (get20 ()->Uniform4i)
	#define glUniform1fv (get20 ()->Uniform1fv)
	#define glUniform2fv (get20 ()->Uniform2fv)
	#define glUniform3fv (get20 ()->Uniform3fv)
	#define glUniform4fv (get20 ()->Uniform4fv)
	#define glUniform1iv (get20 ()->Uniform1iv)
	#define glUniform2iv (get20 ()->Uniform2iv)
	#define glUniform3iv (get20 ()->Uniform3iv)
	#define glUniform4iv (get20 ()->Uniform4iv)
	#define glUniformMatrix2fv (get20 ()->UniformMatrix2fv)
	#define glUniformMatrix3fv (get20 ()->UniformMatrix3fv)
	#define glUniformMatrix4fv (get20 ()->UniformMatrix4fv)
	#define glValidateProgram (get20 ()->ValidateProgram)
	#define glVertexAttrib1d (get20 ()->VertexAttrib1d)
	#define glVertexAttrib1dv (get20 ()->VertexAttrib1dv)
	#define glVertexAttrib1f (get20 ()->VertexAttrib1f)
	#define glVertexAttrib1fv (get20 ()->VertexAttrib1fv)
	#define glVertexAttrib1s (get20 ()->VertexAttrib1s)
	#define glVertexAttrib1sv (get20 ()->VertexAttrib1sv)
	#define glVertexAttrib2d (get20 ()->VertexAttrib2d)
	#define glVertexAttrib2dv (get20 ()->VertexAttrib2dv)
	#define glVertexAttrib2f (get20 ()->VertexAttrib2f)
	#define glVertexAttrib2fv (get20 ()->VertexAttrib2fv)
	#define glVertexAttrib2s (get20 ()->VertexAttrib2s)
	#define glVertexAttrib2sv (get20 ()->VertexAttrib2sv)
	#define glVertexAttrib3d (get20 ()->VertexAttrib3d)
	#define glVertexAttrib3dv (get20 ()->VertexAttrib3dv)
	#define glVertexAttrib3f (get20 ()->VertexAttrib3f)
	#define glVertexAttrib3fv (get20 ()->VertexAttrib3fv)
	#define glVertexAttrib3s (get20 ()->VertexAttrib3s)
	#define glVertexAttrib3sv (get20 ()->VertexAttrib3sv)
	#define glVertexAttrib4Nbv (get20 ()->VertexAttrib4Nbv)
	#define glVertexAttrib4Niv (get20 ()->VertexAttrib4Niv)
	#define glVertexAttrib4Nsv (get20 ()->VertexAttrib4Nsv)
	#define glVertexAttrib4Nub (get20 ()->VertexAttrib4Nub)
	#define glVertexAttrib4Nubv (get20 ()->VertexAttrib4Nubv)
	#define glVertexAttrib4Nuiv (get20 ()->VertexAttrib4Nuiv)
	#define glVertexAttrib4Nusv (get20 ()->VertexAttrib4Nusv)
	#define glVertexAttrib4bv (get20 ()->VertexAttrib4bv)
	#define glVertexAttrib4d (get20 ()->VertexAttrib4d)
	#define glVertexAttrib4dv (get20 ()->VertexAttrib4dv)
	#define glVertexAttrib4f (get20 ()->VertexAttrib4f)
	#define glVertexAttrib4fv (get20 ()->VertexAttrib4fv)
	#define glVertexAttrib4iv (get20 ()->VertexAttrib4iv)
	#define glVertexAttrib4s (get20 ()->VertexAttrib4s)
	#define glVertexAttrib4sv (get20 ()->VertexAttrib4sv)
	#define glVertexAttrib4ubv (get20 ()->VertexAttrib4ubv)
	#define glVertexAttrib4uiv (get20 ()->VertexAttrib4uiv)
	#define glVertexAttrib4usv (get20 ()->VertexAttrib4usv)
	#define glVertexAttribPointer (get20 ()->VertexAttribPointer)

	/*ARB extensions*/
	//WGL_ARB_buffer_region
#ifdef WIN32
	#define wglCreateBufferRegionARB (getarb ()->CreateBufferRegionARB)
	#define wglDeleteBufferRegionARB (getarb ()->DeleteBufferRegionARB)
	#define wglSaveBufferRegionARB (getarb ()->SaveBufferRegionARB)
	#define wglRestoreBufferRegionARB (getarb ()->RestoreBufferRegionARB)
#endif

	//GL_ARB_multisample
	#define glSampleCoverageARB (getarb ()->SampleCoverageARB)

	//WGL_extensions_string
#ifdef WIN32
	#define wglGetExtensionsStringARB (getarb ()->GetExtensionsStringARB)
#endif

	//WGL_pixel_format
#ifdef WIN32
	#define wglGetPixelFormatAttribivARB (getarb ()->GetPixelFormatAttribivARB)
	#define wglGetPixelFormatAttribfvARB (getarb ()->GetPixelFormatAttribfvARB)
	#define wglChoosePixelFormatARB (getarb ()->ChoosePixelFormatARB)
#endif

	//WGL_make_current_read
#ifdef WIN32
	#define wglMakeContextCurrentARB (getarb ()->MakeContextCurrentARB)
	#define wglGetCurrentReadDCARB (getarb ()->GetCurrentReadDCARB)
#endif

	//WGL_ARB_pbuffer
#ifdef WIN32
	#define wglCreatePbufferARB (getarb ()->wCreatePbufferARB)
	#define wglDestroyPbufferARB (getarb ()->wDestroyPbufferARB)
	#define wglGetPbufferDCARB (getarb ()->wGetPbufferDCARB)
	#define wglQueryPbufferARB (getarb ()->wQueryPbufferARB)
	#define wglBindTexImageARB (getarb ()->wBindTexImageARB)
	#define wglReleaseTexImageARB (getarb ()->wReleaseTexImageARB)
	#define wglSetPbufferAttribARB (getarb ()->wSetPbufferAttribARB)
#endif

	//GL_ARB_compressed_texture
	#define glCompressedTexImage3DARB (getarb ()->CompressedTexImage3DARB)
	#define glCompressedTexImage2DARB (getarb ()->CompressedTexImage2DARB)
	#define glCompressedTexImage1DARB (getarb ()->CompressedTexImage1DARB)
	#define glCompressedTexSubImage3DARB (getarb ()->CompressedTexSubImage3DARB)
	#define glCompressedTexSubImage2DARB (getarb ()->CompressedTexSubImage2DARB)
	#define glCompressedTexSubImage1DARB (getarb ()->CompressedTexSubImage1DARB)
	#define glGetCompressedTexImageARB (getarb ()->GetCompressedTexImageARB)

	//GL_ARB_point_parameters
	#define glPointParameterfARB (getarb ()->PointParameterfARB)
	#define glPointParameterfvARB (getarb ()->PointParameterfvARB)

	//GL_ARB_vertex_blend
	#define glWeightbvARB (getarb ()->WeightbvARB)
	#define glWeightubvARB (getarb ()->WeightubvARB)
	#define glWeightsvARB (getarb ()->WeightsvARB)
	#define glWeightusvARB (getarb ()->WeightusvARB)
	#define glWeightivARB (getarb ()->WeightivARB)
	#define glWeightuivARB (getarb ()->WeightuivARB)
	#define glWeightfvARB (getarb ()->WeightfvARB)
	#define glWeightdvARB (getarb ()->WeightdvARB)
	#define glWeightPointerARB (getarb ()->WeightPointerARB)
	#define glVertexBlendARB (getarb ()->VertexBlendARB)

	//GL_ARB_palette_matrix
	#define glCurrentPaletteMatrixARB (getarb ()->CurrentPaletteMatrixARB)
	#define glMatrixIndexubvARB (getarb ()->MatrixIndexubvARB)
	#define glMatrixIndexusvARB (getarb ()->MatrixIndexusvARB)
	#define glMatrixIndexuivARB (getarb ()->MatrixIndexuivARB)
	#define glMatrixIndexPointerARB (getarb ()->MatrixIndexPointerARB)

	//GL_ARB_render_texture
	#define wglBindTexImageARB (getarb ()->wBindTexImageARB)
	#define wglReleaseTexImageARB (getarb ()->wReleaseTexImageARB)
	#define wglSetPbufferAttribARB (getarb ()->wSetPbufferAttribARB)

	//GL_ARB_window_pos
	#define glWindowPos2dARB (getarb ()->WindowPos2dARB)
	#define glWindowPos2fARB (getarb ()->WindowPos2fARB)
	#define glWindowPos2iARB (getarb ()->WindowPos2iARB)
	#define glWindowPos2sARB (getarb ()->WindowPos2sARB)
	#define glWindowPos2dvARB (getarb ()->WindowPos2dvARB)
	#define glWindowPos2fvARB (getarb ()->WindowPos2fvARB)
	#define glWindowPos2ivARB (getarb ()->WindowPos2ivARB)
	#define glWindowPos2svARB (getarb ()->WindowPos2svARB)
	#define glWindowPos3dARB (getarb ()->WindowPos3dARB)
	#define glWindowPos3fARB (getarb ()->WindowPos3fARB)
	#define glWindowPos3iARB (getarb ()->WindowPos3iARB)
	#define glWindowPos3sARB (getarb ()->WindowPos3sARB)
	#define glWindowPos3dvARB (getarb ()->WindowPos3dvARB)
	#define glWindowPos3fvARB (getarb ()->WindowPos3fvARB)
	#define glWindowPos3ivARB (getarb ()->WindowPos3ivARB)
	#define glWindowPos3svARB (getarb ()->WindowPos3svARB)

	//GL_ARB_vertex_program
	#define glVertexAttrib1sARB (getarb ()->VertexAttrib1sARB)
	#define glVertexAttrib1fARB (getarb ()->VertexAttrib1fARB)
	#define glVertexAttrib1dARB (getarb ()->VertexAttrib1dARB)
	#define glVertexAttrib2sARB (getarb ()->VertexAttrib2sARB)
	#define glVertexAttrib2fARB (getarb ()->VertexAttrib2fARB)
	#define glVertexAttrib2dARB (getarb ()->VertexAttrib2dARB)
	#define glVertexAttrib3sARB (getarb ()->VertexAttrib3sARB)
	#define glVertexAttrib3fARB (getarb ()->VertexAttrib3fARB)
	#define glVertexAttrib3dARB (getarb ()->VertexAttrib3dARB)
	#define glVertexAttrib4sARB (getarb ()->VertexAttrib4sARB)
	#define glVertexAttrib4fARB (getarb ()->VertexAttrib4fARB)
	#define glVertexAttrib4dARB (getarb ()->VertexAttrib4dARB)
	#define glVertexAttrib4NubARB (getarb ()->VertexAttrib4NubARB)
	#define glVertexAttrib1svARB (getarb ()->VertexAttrib1svARB)
	#define glVertexAttrib1fvARB (getarb ()->VertexAttrib1fvARB)
	#define glVertexAttrib1dvARB (getarb ()->VertexAttrib1dvARB)
	#define glVertexAttrib2svARB (getarb ()->VertexAttrib2svARB)
	#define glVertexAttrib2fvARB (getarb ()->VertexAttrib2fvARB)
	#define glVertexAttrib2dvARB (getarb ()->VertexAttrib2dvARB)
	#define glVertexAttrib3svARB (getarb ()->VertexAttrib3svARB)
	#define glVertexAttrib3fvARB (getarb ()->VertexAttrib3fvARB)
	#define glVertexAttrib3dvARB (getarb ()->VertexAttrib3dvARB)
	#define glVertexAttrib4bvARB (getarb ()->VertexAttrib4bvARB)
	#define glVertexAttrib4svARB (getarb ()->VertexAttrib4svARB)
	#define glVertexAttrib4ivARB (getarb ()->VertexAttrib4ivARB)
	#define glVertexAttrib4ubvARB (getarb ()->VertexAttrib4ubvARB)
	#define glVertexAttrib4usvARB (getarb ()->VertexAttrib4usvARB)
	#define glVertexAttrib4uivARB (getarb ()->VertexAttrib4uivARB)
	#define glVertexAttrib4fvARB (getarb ()->VertexAttrib4fvARB)
	#define glVertexAttrib4dvARB (getarb ()->VertexAttrib4dvARB)
	#define glVertexAttrib4NbvARB (getarb ()->VertexAttrib4NbvARB)
	#define glVertexAttrib4NsvARB (getarb ()->VertexAttrib4NsvARB)
	#define glVertexAttrib4NivARB (getarb ()->VertexAttrib4NivARB)
	#define glVertexAttrib4NubvARB (getarb ()->VertexAttrib4NubvARB)
	#define glVertexAttrib4NusvARB (getarb ()->VertexAttrib4NusvARB)
	#define glVertexAttrib4NuivARB (getarb ()->VertexAttrib4NuivARB)
	#define glVertexAttribPointerARB (getarb ()->VertexAttribPointerARB)
	#define glEnableVertexAttribArrayARB (getarb ()->EnableVertexAttribArrayARB)
	#define glDisableVertexAttribArrayARB (getarb ()->DisableVertexAttribArrayARB)
	#define glProgramStringARB (getarb ()->ProgramStringARB)
	#define glBindProgramARB (getarb ()->BindProgramARB)
	#define glDeleteProgramsARB (getarb ()->DeleteProgramsARB)
	#define glGenProgramsARB (getarb ()->GenProgramsARB)
	#define glProgramEnvParameter4dARB (getarb ()->ProgramEnvParameter4dARB)
	#define glProgramEnvParameter4dvARB (getarb ()->ProgramEnvParameter4dvARB)
	#define glProgramEnvParameter4fARB (getarb ()->ProgramEnvParameter4fARB)
	#define glProgramEnvParameter4fvARB (getarb ()->ProgramEnvParameter4fvARB)
	#define glProgramLocalParameter4dARB (getarb ()->ProgramLocalParameter4dARB)
	#define glProgramLocalParameter4dvARB (getarb ()->ProgramLocalParameter4dvARB)
	#define glProgramLocalParameter4fARB (getarb ()->ProgramLocalParameter4fARB)
	#define glProgramLocalParameter4fvARB (getarb ()->ProgramLocalParameter4fvARB)
	#define glGetProgramEnvParameterdvARB (getarb ()->GetProgramEnvParameterdvARB)
	#define glGetProgramEnvParameterfvARB (getarb ()->GetProgramEnvParameterfvARB)
	#define glGetProgramLocalParameterdvARB (getarb ()->GetProgramLocalParameterdvARB)
	#define glGetProgramLocalParameterfvARB (getarb ()->GetProgramLocalParameterfvARB)
	#define glGetProgramivARB (getarb ()->GetProgramivARB)
	#define glGetProgramStringARB (getarb ()->GetProgramStringARB)
	#define glGetVertexAttribdvARB (getarb ()->GetVertexAttribdvARB)
	#define glGetVertexAttribfvARB (getarb ()->GetVertexAttribfvARB)
	#define glGetVertexAttribivARB (getarb ()->GetVertexAttribivARB)
	#define glGetVertexAttribPointervARB (getarb ()->GetVertexAttribPointervARB)
	#define glIsProgramARB (getarb ()->IsProgramARB)

	//GL_ARB_fragment_program

	//GL_ARB_vertex_buffer_object
	#define glBindBufferARB (getarb ()->BindBufferARB)
	#define glDeleteBuffersARB (getarb ()->DeleteBuffersARB)
	#define glGenBuffersARB (getarb ()->GenBuffersARB)
	#define glIsBufferARB (getarb ()->IsBufferARB)
	#define glBufferDataARB (getarb ()->BufferDataARB)
	#define glBufferSubDataARB (getarb ()->BufferSubDataARB)
	#define glGetBufferSubDataARB (getarb ()->GetBufferSubDataARB)
	#define glMapBufferARB (getarb ()->MapBufferARB)
	#define glUnmapBufferARB (getarb ()->UnmapBufferARB)
	#define glGetBufferParameterivARB (getarb ()->GetBufferParameterivARB)
	#define glGetBufferPointervARB (getarb ()->GetBufferPointervARB)

	//GL_ARB_occlusion_query
	#define glGenQueriesARB (getarb ()->GenQueriesARB)
	#define glDeleteQueriesARB (getarb ()->DeleteQueriesARB)
	#define glIsQueryARB (getarb ()->IsQueryARB)
	#define glBeginQueryARB (getarb ()->BeginQueryARB)
	#define glEndQueryARB (getarb ()->EndQueryARB)
	#define glGetQueryivARB (getarb ()->GetQueryivARB)
	#define glGetQueryObjectivARB (getarb ()->GetQueryObjectivARB)
	#define glGetQueryObjectuivARB (getarb ()->GetQueryObjectuivARB)

	//GL_ARB_shader_objects
	#define glDeleteObjectARB (getarb ()->DeleteObjectARB)
	#define glGetHandleARB (getarb ()->GetHandleARB)
	#define glDetachObjectARB (getarb ()->DetachObjectARB)
	#define glCreateShaderObjectARB (getarb ()->CreateShaderObjectARB)
	#define glShaderSourceARB (getarb ()->ShaderSourceARB)
	#define glCompileShaderARB (getarb ()->CompileShaderARB)
	#define glCreateProgramObjectARB (getarb ()->CreateProgramObjectARB)
	#define glAttachObjectARB (getarb ()->AttachObjectARB)
	#define glLinkProgramARB (getarb ()->LinkProgramARB)
	#define glUseProgramObjectARB (getarb ()->UseProgramObjectARB)
	#define glValidateProgramARB (getarb ()->ValidateProgramARB)
	#define glUniform1fARB (getarb ()->Uniform1fARB)
	#define glUniform2fARB (getarb ()->Uniform2fARB)
	#define glUniform3fARB (getarb ()->Uniform3fARB)
	#define glUniform4fARB (getarb ()->Uniform4fARB)
	#define glUniform1iARB (getarb ()->Uniform1iARB)
	#define glUniform2iARB (getarb ()->Uniform2iARB)
	#define glUniform3iARB (getarb ()->Uniform3iARB)
	#define glUniform4iARB (getarb ()->Uniform4iARB)
	#define glUniform1fvARB (getarb ()->Uniform1fvARB)
	#define glUniform2fvARB (getarb ()->Uniform2fvARB)
	#define glUniform3fvARB (getarb ()->Uniform3fvARB)
	#define glUniform4fvARB (getarb ()->Uniform4fvARB)
	#define glUniform1ivARB (getarb ()->Uniform1ivARB)
	#define glUniform2ivARB (getarb ()->Uniform2ivARB)
	#define glUniform3ivARB (getarb ()->Uniform3ivARB)
	#define glUniform4ivARB (getarb ()->Uniform4ivARB)
	#define glUniformMatrix2fvARB (getarb ()->UniformMatrix2fvARB)
	#define glUniformMatrix3fvARB (getarb ()->UniformMatrix3fvARB)
	#define glUniformMatrix4fvARB (getarb ()->UniformMatrix4fvARB)
	#define glGetObjectParameterfvARB (getarb ()->GetObjectParameterfvARB)
	#define glGetObjectParameterivARB (getarb ()->GetObjectParameterivARB)
	#define glGetInfoLogARB (getarb ()->GetInfoLogARB)
	#define glGetAttachedObjectsARB (getarb ()->GetAttachedObjectsARB)
	#define glGetUniformLocationARB (getarb ()->GetUniformLocationARB)
	#define glGetActiveUniformARB (getarb ()->GetActiveUniformARB) 
	#define glGetUniformfvARB (getarb ()->GetUniformfvARB)
	#define glGetUniformivARB (getarb ()->GetUniformivARB)
	#define glGetShaderSourceARB (getarb ()->GetShaderSourceARB)

	//GL_ARB_vertex_shader
	#define glBindAttribLocationARB (getarb ()->BindAttribLocationARB)
	#define glGetActiveAttribARB (getarb ()->GetActiveAttribARB)
	#define glGetAttribLocationARB (getarb ()->GetAttribLocationARB)

	//GL_ARB_draw_buffers
	#define glDrawBuffersARB (getarb ()->DrawBuffersARB)

	//GL_ARB_color_buffer_float
	#define glClampColorARB (getarb ()->ClampColorARB)

	//GL_EXT_blend_color
	#define glBlendColorEXT (getext ()->BlendColorEXT)

	//GL_EXT_polygon_offset
	#define glPolygonOffsetEXT (getext ()->PolygonOffsetEXT)

	//GL_EXT_texture3d
	#define glTexImage3DEXT (getext ()->TexImage3DEXT)

	//GL_EXT_texture_filter4
	//#define TexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const float* weights);
	//#define GetTexFilterFuncSGIS(GLenum target, GLenum filter, float* weights);

	//GL_EXT_subtexture
	#define glTexSubImage1DEXT (getext ()->TexSubImage1DEXT)
	#define glTexSubImage2DEXT (getext ()->TexSubImage2DEXT)
	#define glTexSubImage3DEXT (getext ()->TexSubImage3DEXT)

	//GL_EXT_copy_texture
	#define glCopyTexImage1DEXT (getext ()->CopyTexImage1DEXT)
	#define glCopyTexImage2DEXT (getext ()->CopyTexImage2DEXT)
	#define glCopyTexSubImage1DEXT (getext ()->CopyTexSubImage1DEXT)
	#define glCopyTexSubImage2DEXT (getext ()->CopyTexSubImage2DEXT)
	#define glCopyTexSubImage3DEXT (getext ()->CopyTexSubImage3DEXT)

	//GL_EXT_histogram

	//GL_EXT_convolution
	#define glConvolutionFilter1DEXT (getext ()->ConvolutionFilter1DEXT)
	#define glConvolutionFilter2DEXT (getext ()->ConvolutionFilter2DEXT)
	#define glCopyConvolutionFilter1DEXT (getext ()->CopyConvolutionFilter1DEXT)
	#define glCopyConvolutionFilter2DEXT (getext ()->CopyConvolutionFilter2DEXT)
	#define glGetConvolutionFilterEXT (getext ()->GetConvolutionFilterEXT)
	#define glSeparableFilter2DEXT (getext ()->SeparableFilter2DEXT)
	#define glGetSeparableFilterEXT (getext ()->GetSeparableFilterEXT)
	#define glConvolutionParameteriEXT (getext ()->ConvolutionParameteriEXT)
	#define glConvolutionParameterivEXT (getext ()->ConvolutionParameterivEXT)
	#define glConvolutionParameterfEXT (getext ()->ConvolutionParameterfEXT)
	#define glConvolutionParameterfvEXT (getext ()->ConvolutionParameterfvEXT)
	#define glGetConvolutionParameterivEXT (getext ()->GetConvolutionParameterivEXT)
	#define glGetConvolutionParameterfvEXT (getext ()->GetConvolutionParameterfvEXT)
	
	//GL_EXT_color_table

	//GL_SGIS_pixel_texture
	//#define PixelTexGenParameter{if}SGIS(GLenum pname, T param);
	//#define GetPixelTexGenParameter{if}vSGIS(GLenum pname, T params);

	//GL_SGIX_pixel_texture
	#define glPixelTexGenSGIX (getext ()->PixelTexGenSGIX)

	//GL_SGIS_texture4d
	#define glTexImage4DSGIS (getext ()->TexImage4DSGIS)
	#define glTexSubImage4DSGIS (getext ()->TexSubImage4DSGIS)

	//GL_EXT_texture_object
	#define glGenTexturesEXT (getext ()->GenTexturesEXT)
	#define glDeleteTexturesEXT (getext ()->DeleteTexturesEXT)
	#define glBindTextureEXT (getext ()->BindTextureEXT)
	#define glPrioritizeTexturesEXT (getext ()->PrioritizeTexturesEXT)
	#define glAreTexturesResidentEXT (getext ()->AreTexturesResidentEXT)
	#define glIsTextureEXT (getext ()->IsTextureEXT)

	//GL_SGIS_detail_texture

	//GL_SGIS_sharpen_texture

	//GL_EXT_vertex_array
	#define glArrayElementEXT (getext ()->ArrayElementEXT)
	#define glDrawArraysEXT (getext ()->DrawArraysEXT)
	#define glVertexPointerEXT (getext ()->VertexPointerEXT)
	#define glNormalPointerEXT (getext ()->NormalPointerEXT)
	#define glColorPointerEXT (getext ()->ColorPointerEXT)
	#define glIndexPointerEXT (getext ()->IndexPointerEXT)
	#define glTexCoordPointerEXT (getext ()->TexCoordPointerEXT)
	#define glEdgeFlagPointerEXT (getext ()->EdgeFlagPointerEXT)
	#define glGetPointervEXT (getext ()->GetPointervEXT)

	//GL_EXT_blend_minmax
	#define glBlendEquationEXT (getext ()->BlendEquationEXT)

	//GLX_SGI_swap_control
#ifdef USE_X
	#define glXSwapIntervalSGI (getext ()->XSwapIntervalSGI)
#endif

	//GLX_SGI_video_sync
#ifdef USE_X
	#define glXGetVideoSyncSGI (getext ()->XGetVideoSyncSGI)
	#define glXWaitVideoSyncSGI (getext ()->XWaitVideoSyncSGI)
#endif

	//GLX_SGI_make_current_read
#ifdef USE_X
	#define glXMakeCurrentReadSGI (getext ()->XMakeCurrentReadSGI)
	#define glXGetCurrentReadDrawableSGI (getext ()->XGetCurrentReadDrawableSGI)
#endif

	//GLX_SGIX_video_source
#ifdef USE_X
	typedef XID GLXVideoSourceSGIX;
	#define glXCreateGLXVideoSourceSGIX (getext ()->XCreateGLXVideoSourceSGIX)
	#define glXDestroyGLXVideoSourceSGIX (getext ()->XDestroyGLXVideoSourceSGIX)
#endif

	//GLX_EXT_import_context
#ifdef USE_X
	#define glXGetCurrentDisplayEXT (getext ()->XGetCurrentDisplayEXT)
	#define glXQueryContextInfoEXT (getext ()->XQueryContextInfoEXT)
	#define glXGetContextIDEXT (getext ()->XGetContextIDEXT)
	#define glXImportContextEXT (getext ()->XImportContextEXT)
	#define glXFreeContextEXT (getext ()->XFreeContextEXT)
#endif

	//GLX_SGIX_fbconfig
#ifdef USE_X
	#define glXGetFBConfigAttribSGIX (getext ()->XGetFBConfigAttribSGIX)
	#define glXChooseFBConfigSGIX (getext ()->XChooseFBConfigSGIX)
	#define glXCreateGLXPixmapWithConfigSGIX (getext ()->XCreateGLXPixmapWithConfigSGIX)
	#define glXCreateContextWithConfigSGIX (getext ()->XCreateContextWithConfigSGIX)
	#define glXGetVisualFromFBConfigSGIX (getext ()->XGetVisualFromFBConfigSGIX)
	#define glXGetFBConfigFromVisualSGIX (getext ()->XGetFBConfigFromVisualSGIX)
#endif

	//GLX_SGIX_pbuffer
#ifdef USE_X
	#define glXCreateGLXPbufferSGIX (getext ()->XCreateGLXPbufferSGIX)
	#define glXDestroyGLXPbufferSGIX (getext ()->XDestroyGLXPbufferSGIX)
	#define glXQueryGLXPbufferSGIX (getext ()->XQueryGLXPbufferSGIX)
	#define glXSelectEventSGIX (getext ()->XSelectEventSGIX)
	#define glXGetSelectedEventSGIX (getext ()->XGetSelectedEventSGIX)
#endif

	//GL_SGIX_sprite
	#define glSpriteParameteriSGIX (getext ()->SpriteParameteriSGIX)
	#define glSpriteParameterfSGIX (getext ()->SpriteParameterfSGIX)
	#define glSpriteParameterivSGIX (getext ()->SpriteParameterivSGIX)
	#define glSpriteParameterfvSGIX (getext ()->SpriteParameterfvSGIX)

	//GL_SGIX_texture_multi_buffer

	//GL_EXT_point_parameters
	#define glPointParameterfEXT (getext ()->PointParameterfEXT)
	#define glPointParameterfvEXT (getext ()->PointParameterfvEXT)

	//GL_SGIX_instruments
	#define InstrumentsBufferSGIX (getext ()->InstrumentsBufferSGIX)
	#define StartInstrumentsSGIX (getext ()->StartInstrumentsSGIX)
	#define StopInstrumentsSGIX (getext ()->StopInstrumentsSGIX)
	#define ReadInstrumentsSGIX (getext ()->ReadInstrumentsSGIX)
	#define PollInstrumentsSGIX (getext ()->PollInstrumentsSGIX)
	#define GetInstrumentsSGIX (getext ()->GetInstrumentsSGIX)

	//GL_SGIX_framezoom
	#define glFrameZoomSGIX (getext ()->FrameZoomSGIX)

	//GL_SGIX_tag_sample_buffer
	#define glTagSampleBufferSGIX (getext ()->TagSampleBufferSGIX)

	//GL_SGIX_reference_plane
	#define glReferencePlaneSGIX (getext ()->ReferencePlaneSGIX)

	//GL_SGIX_flush_raster
	#define glFlushRasterSGIX (getext ()->FlushRasterSGIX)

	//GLX_SGI_cushion
#ifdef USE_X
	#define glXCushionSGI (getext ()->XCushionSGI)
#endif

	//GL_SGIS_fog_func
	#define glFogFuncSGIS (getext ()->FogFuncSGIS)
	#define glGetFogFuncSGIS (getext ()->GetFogFuncSGIS)

	//GL_EXT_color_subtable
	#define glColorSubTableEXT (getext ()->ColorSubTableEXT)
	#define glCopyColorSubTableEXT (getext ()->CopyColorSubTableEXT)

	//GL_EXT_paletted_texture
	#define glColorTableEXT (getext ()->ColorTableEXT)
	#define glGetColorTableEXT (getext ()->GetColorTableEXT)
	#define glGetColorTableParameterivEXT (getext ()->GetColorTableParameterivEXT)
	#define glGetColorTableParameterfvEXT (getext ()->GetColorTableParameterfvEXT)

	//GL_EXT_framebuffer_object
	#define glIsRenderbufferEXT (getext ()->IsRenderbufferEXT)
	#define glBindRenderbufferEXT (getext ()->BindRenderbufferEXT)
	#define glDeleteRenderbuffersEXT (getext ()->DeleteRenderbuffersEXT)
	#define glGenRenderbuffersEXT (getext ()->GenRenderbuffersEXT)
	#define glRenderbufferStorageEXT (getext ()->RenderbufferStorageEXT)
	#define glGetRenderbufferParameterivEXT (getext ()->GetRenderbufferParameterivEXT)
	#define glIsFramebufferEXT (getext ()->IsFramebufferEXT)
	#define glBindFramebufferEXT (getext ()->BindFramebufferEXT)
	#define glDeleteFramebuffersEXT (getext ()->DeleteFramebuffersEXT)
	#define glGenFramebuffersEXT (getext ()->GenFramebuffersEXT)
	#define glCheckFramebufferStatusEXT (getext ()->CheckFramebufferStatusEXT)
	#define glFramebufferTexture1DEXT (getext ()->FramebufferTexture1DEXT)
	#define glFramebufferTexture2DEXT (getext ()->FramebufferTexture2DEXT)
	#define glFramebufferTexture3DEXT (getext ()->FramebufferTexture3DEXT)
	#define glFramebufferRenderbufferEXT (getext ()->FramebufferRenderbufferEXT)
	#define glGetFramebufferAttachmentParameterivEXT (getext ()->GetFramebufferAttachmentParameterivEXT)
	#define glGenerateMipmapEXT (getext ()->GenerateMipmapEXT)
};

#endif
