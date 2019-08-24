#include <gsimage/gstexture.h>

namespace gsimage
{
	gstexture::gstexture () : m_iWidth (0), m_iHeight (0), m_iBits (0), m_pData (NULL)
	{
	}

	gstexture::~gstexture ()
	{
		if (m_pData)
			delete [] m_pData;
	}

	void gstexture::load (const gsutil::gsstring &str)
	{
	}

	void gstexture::unload ()
	{
	}

	unsigned char *gstexture::getData ()
	{
		return m_pData;
	}

	void gstexture::set (const int &w, const int &h, const int &b)
	{
		m_iWidth = w; m_iHeight = h; m_iBits = b;
		if (m_pData)
			delete [] m_pData;
		m_pData = new unsigned char[m_iWidth*m_iHeight*m_iBits];
	}

	const int gstexture::getWidth ()
	{
		return m_iWidth;
	}

	const int gstexture::getHeight ()
	{
		return m_iHeight;
	}

	const int gstexture::getBit ()
	{
		return m_iBits;
	}

	void gstexture::setPixel (const int &x, const int &h, char *data)
	{
		switch (m_iBits)
		{
		case 1:
			{
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 0] = data[0];
			}
			break;

		case 2:
			{
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 0] = data[0];
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 1] = data[1];
			}
			break;

		case 3:
			{
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 0] = data[0];
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 1] = data[1];
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 2] = data[2];
			}
			break;

		case 4:
			{
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 0] = data[0];
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 1] = data[1];
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 2] = data[2];
				m_pData[x*m_iBits*m_iWidth + m_iBits*m_iHeight + 3] = data[3];
			}
			break;
		}
	}

	gsutil::gsstring gstexture::getName ()
	{
		return m_strName;
	}
};
