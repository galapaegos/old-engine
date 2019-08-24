#include "gsimage/gsbmp.h"

namespace gsimage
{
	gsbmp::gsbmp () : gstexture ()
	{
		memset (&m_bh, 0, sizeof (bmpHeader));
		m_iWidth = 0;
		m_iHeight = 0;
		m_iBits = 0;
	}

	gsbmp::~gsbmp ()
	{
	}

	void gsbmp::load (const gsutil::gsstring &pFilename)
	{
		m_strName = pFilename;

		FILE *f = fopen (m_strName.str (), "rb");
		if (f == NULL)
		{
			printf ("gsbmp::load () Unable to load file:%s\n", pFilename.str ());
			return;
		}

		fread (&m_bh, sizeof (bmpHeader), 1, f);

		if (m_bh.type != 0x4d42)
		{
			printf ("gsbmp::load () m_bh.type != 0x4d42\n");
			return;
		}

		m_iWidth = m_bh.width;
		m_iHeight = m_bh.height;
		m_iBits = m_bh.bitcount/8;

		m_pData = new unsigned char [m_iWidth*m_iHeight*(unsigned int)(m_bh.bitcount/8.0)];

		if (m_bh.compression != 0L) //BI_RGB
			return;

		if (m_bh.bitcount != 24)
			return;

		fseek (f, m_bh.offset, SEEK_SET);

		//int num_to_read = m_iWidth*m_iHeight*(unsigned int)(m_bh.bitcount/8.0);

		//int read = (int)fread (m_pData, m_iWidth*m_iHeight*(unsigned int)(m_bh.bitcount/8.0), 1, f);
		fread (m_pData, m_iWidth*m_iHeight*(unsigned int)(m_bh.bitcount/8.0), 1, f);

		//unsigned int stride = m_iWidth*m_iBits;
		//while ((stride % 4) != 0)
		//	stride ++;

		//unsigned int bpl = m_iWidth*m_iBits;
		//unsigned int padding = bmp_stride - bpl;

		//// Loop over all the scan lines (all the rows of pixels in the image)
		//for(int y = 0; y < m_iHeight; y++)
		//{
		//	// Get the "current" line pointer
		//	uchar *LinePtr = getLinePtr(y);

		//	// Read the precise number of bytes that the scan line requires into the bitmap
		//	if(!fread(LinePtr, bytesPerLine, 1, bmp_file))
		//	{
		//		fclose(bmp_file);
		//			return false;
		//	}

		//	// Skip over any padding bytes.
		//	if(fseek(bmp_file, padding, SEEK_CUR))
		//	{
		//		fclose(bmp_file);
		//			return false;
		//	}
	
		//} // end of for (int y = 0; y < bmp_infoheader.biHeight; y++)

		fclose (f);

		convertRGB ();
	}

	void gsbmp::unload ()
	{
	}

	void gsbmp::convertRGB ()
	{
		if (m_iWidth == 0 || m_iHeight == 0)
			return;

		unsigned char *temp = m_pData;
		m_pData = new unsigned char [m_iWidth * m_iHeight * 3];
		memset (m_pData, 0, m_iWidth*m_iHeight*3);

		int padding = 0;
		int scanlinebytes = m_iWidth *3;

		while ((scanlinebytes + padding) % 4 != 0)
			padding ++;

		int psw = scanlinebytes + padding;

		long bufpos = 0;
		long newpos = 0;

		for (int y = 0; y < m_iHeight; y++)
		{
			for (int x = 0; x < 3*m_iWidth; x+=3)
			{
				newpos = y*3*m_iWidth + x;
				bufpos = y*psw + x;

				m_pData[newpos + 0] = temp[bufpos + 2];
				m_pData[newpos + 1] = temp[bufpos + 1];
				m_pData[newpos + 2] = temp[bufpos + 0];
			}
		}

		delete [] temp;
	}
}
