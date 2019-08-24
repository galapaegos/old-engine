#include <gsgfx/gl/gsshaderprogram.h>

namespace gsgfx
{
	gsshaderprogram::gsshaderprogram ()
	{
		context = glCreateProgramObjectARB ();
		vertexShader = glCreateShaderObjectARB (GL_VERTEX_SHADER_ARB);
		pixelShader = glCreateShaderObjectARB (GL_FRAGMENT_SHADER_ARB);
	}

	gsshaderprogram::~gsshaderprogram ()
	{
		glDeleteObjectARB (vertexShader);
		glDeleteObjectARB (pixelShader);
		glDeleteObjectARB (context);
	}

	void printInfoLog(const gsutil::gsstring &program, GLhandleARB obj)
	{
		int infologLength = 0;
		int charsWritten  = 0;
		GLcharARB *infoLog;

		glGetObjectParameterivARB(obj, GL_OBJECT_INFO_LOG_LENGTH_ARB,
											&infologLength);

		if (infologLength > 0)
		{
			infoLog = (GLcharARB*)malloc(infologLength);
			if (infoLog == NULL)
			{
				printf("ERROR: Could not allocate InfoLog buffer\n");
				exit(1);
			}

			printf ("-------------------------\n");
			printf ("%s:\n", program);
			glGetInfoLogARB(obj, infologLength, &charsWritten, infoLog);
			printf ("InfoLog:\n%s\n\n", infoLog);
			free(infoLog);
		}
	}

	void gsshaderprogram::load (gsgeom::gsshader *pProgram)
	{
		m_pShader = pProgram;
		int status = 0;
		char *pvert = const_cast <char*> (pProgram->getVertexProgram ().str ());
		char *pfrag = const_cast <char*> (pProgram->getFragmentProgram ().str ());
		glShaderSourceARB (vertexShader, 1, (const char**)&pvert, NULL);
		glCompileShaderARB (vertexShader);
		glGetObjectParameterivARB (vertexShader, GL_OBJECT_COMPILE_STATUS_ARB, &status);
		if (!status)
		{
			//gsutil::gslogger::get ().writeLog ("Unable to compile vertex shader\n");
			printInfoLog ("vertex", vertexShader);
		}
		glAttachObjectARB (context, vertexShader);
		glShaderSourceARB (pixelShader, 1, (const char**)&pfrag, NULL);
		glCompileShaderARB (pixelShader);
		status = 0;
		glGetObjectParameterivARB (pixelShader, GL_OBJECT_COMPILE_STATUS_ARB, &status);
		if (!status)
		{
			//gsutil::gslogger::get ().writeLog ("Unable to compile pixel shader\n");
			printInfoLog ("fragment", pixelShader);
		}
		glAttachObjectARB (context, pixelShader);

		int linked = 0;
		glLinkProgramARB (context);
		glGetObjectParameterivARB (context, GL_OBJECT_LINK_STATUS_ARB, &linked);
		if (!linked)
		{
			//gsutil::gslogger::get ().writeLog ("Unable to link program\n");
			printInfoLog ("context", context);
		}
	}

	void gsshaderprogram::unload ()
	{
	}

	void gsshaderprogram::enable ()
	{
		m_bEnabled = true;
		glUseProgramObjectARB (context);
	}

	void gsshaderprogram::disable ()
	{
		m_bEnabled = false;
		glUseProgramObjectARB (0);
	}

	void gsshaderprogram::passVariable (gsgeom::gsshadervariable *v)
	{
		v->setId (glGetUniformLocationARB (context, v->getName ().str ()));

		if (v->getType () == "float")
			glUniform1f (v->getId (), (float)atof (v->getValue ().str ()));
		else if (v->getType () == "int")
			glUniform1i (v->getId (), atoi (v->getValue ().str ()));
	}
};