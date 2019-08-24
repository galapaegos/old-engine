#ifndef _gsvideoinfo_h_
#define _gsvideoinfo_h_

#include <gsutil/gsstring.h>

typedef struct
{
	gsutil::gsstring m_Driver;

	//OpenGL version
	gsutil::gsstring m_openGLVersion;

	bool useVBOs;
	bool useVBOARBs;

	bool useVertexProgram;
	bool useVertexProgramARB;

	bool useFragmentProgram;
	bool useFragmentProgramARB;
} GraphicsDrivers;

GraphicsDrivers[200];

#endif
