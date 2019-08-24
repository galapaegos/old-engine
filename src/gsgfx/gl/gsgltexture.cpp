#include <gsgfx/gl/gsgltexture.h>

namespace gsgfx
{
	gsgltexture::gsgltexture () : m_pTexture (NULL), m_iId (0), m_pTexInfo (NULL)
	{
	}

	gsgltexture::~gsgltexture ()
	{
		glDeleteTextures (1, &m_iId);
	}

	void gsgltexture::load ()
	{
		glEnable (GL_TEXTURE_2D);

		glGenTextures (1, &m_iId);

		glBindTexture (GL_TEXTURE_2D, m_iId);

		switch (m_pTexture->getBit ())
		{
		case 1:
			glTexImage2D (GL_TEXTURE_2D, 0, 1, m_pTexture->getWidth (), m_pTexture->getHeight (), 0, GL_LUMINANCE, 
				GL_UNSIGNED_BYTE, m_pTexture->getData ());
			break;

		case 2:
			glTexImage2D (GL_TEXTURE_2D, 0, 2, m_pTexture->getWidth (), m_pTexture->getHeight (), 0, GL_LUMINANCE_ALPHA, 
				GL_UNSIGNED_BYTE, m_pTexture->getData ());
			break;

		case 3:
			glTexImage2D (GL_TEXTURE_2D, 0, 3, m_pTexture->getWidth (), m_pTexture->getHeight (), 0, GL_RGB, 
				GL_UNSIGNED_BYTE, m_pTexture->getData ());
			break;

		case 4:
			glTexImage2D (GL_TEXTURE_2D, 0, 4, m_pTexture->getWidth (), m_pTexture->getHeight (), 0, GL_RGBA, 
				GL_UNSIGNED_BYTE, m_pTexture->getData ());
			break;
		}

		process ();
	}

	void gsgltexture::bind ()
	{
		glEnable (GL_TEXTURE_2D);
		glBindTexture (GL_TEXTURE_2D, m_iId);
	}

	void gsgltexture::unbind ()
	{
		glBindTexture (GL_TEXTURE_2D, 0);
		glDisable (GL_TEXTURE_2D);
	}

	void gsgltexture::process ()
	{
		switch (m_pTexture->getFilterType ())
		{
		case gsimage::LINEAR_FILTER:
			{
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			}
			break;

		case gsimage::NEAREST_FILTER:
			{
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			}
			break;
		}

		switch (m_pTexture->getWrapType ())
		{
		case gsimage::CLAMP_WRAP:
			{
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			}
			break;

		case gsimage::REPEAT_WRAP:
			{
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			}
			break;
		}
	}
};
