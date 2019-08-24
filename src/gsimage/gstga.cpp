#include "gsimage/gstga.h"

namespace gsimage
{
	gstga::gstga ()
	{
		memset (&m_header, 0, sizeof (TgaHeader));
	}

	gstga::~gstga ()
	{
	}

	void gstga::load (const gsutil::gsstring &pFilename)
	{
		FILE *f = fopen (pFilename.str (), "r+");
		if (!f)
			return;

		//read id length
		fread (&m_header.idLength, sizeof (unsigned char), 1, f);

		//read color map
		fread (&m_header.colorMapType, sizeof (unsigned char), 1, f);

		//read image type
		fread (&m_header.imageType, sizeof (unsigned char), 1, f);

		//read color map specification
		// 2 bytes first entry index
		// 2 bytes color map length
		// 1 byte color map entry size
		fread (&m_header.colorMapSpec, sizeof (unsigned char)*5, 1, f);

		//short colorMapEntryIndex = m_header.colorMapSpec[0];
		short colorMapLength = m_header.colorMapSpec[2];
		unsigned char colorMapEntrySize = m_header.colorMapSpec[4];

		//read image spec,
		// 2 bytes - x image
		// 2 bytes - y image
		// 2 bytes - width
		// 2 bytes - height
		// 1 byte - pixel depth
		// 1 byte - image descriptor
		//  7 - unused
		//  6 - unused
		//  5 - image origin
		//  4 - image origin
		//  3 - alpha channel bits
		//  2 - "
		//  1 - "
		//  0 - "
		fread (&m_header.imageSpec, sizeof (unsigned char)*10, 1, f);

		//unsigned short x = m_header.imageSpec[0];
		//unsigned short y = m_header.imageSpec[2];
		unsigned short w = m_header.imageSpec[4];
		unsigned short h = m_header.imageSpec[6];
		unsigned char bpp = m_header.imageSpec[8]/8;

		m_iWidth = w;
		m_iHeight = h;
		m_iBits = bpp;

		// image
		char *imageId = NULL;
		if (m_header.idLength)
		{
			imageId = new char [m_header.idLength + 1];
			fread (&imageId, m_header.idLength*sizeof (unsigned char), 1, f);
		}

		// read color map data
		char *colorMapData = NULL;
		if (colorMapLength > 0)
		{
			colorMapData = new char [colorMapLength*colorMapEntrySize + 1];
			fread (&colorMapData, colorMapLength, 1, f);
		}

		// read image data
		unsigned char *imageData = NULL;
		if (w*h > 0)
		{
			int total = w*h*bpp;
			imageData = new unsigned char [total];
			int countRead = (int)fread (imageData, 1, total, f);
			printf ("countRead:%i\n", countRead);
		}

		switch (m_header.imageType)
		{
		case 0: //no data
			break;

		case 1:
			processColorMapped (m_header.colorMapType, colorMapData, imageData);
			break;

		case 2:
			processTrue (m_header.colorMapType, colorMapData, imageData);
			break;

		case 3:
			processBlackWhite (m_header.colorMapType, colorMapData, imageData);
			break;

		case 9:
			processRLEColorMapped (m_header.colorMapType, colorMapData, imageData);
			break;

		case 10:
			processRLETrue (m_header.colorMapType, colorMapData, imageData);
			break;

		case 11:
			processRLEBlackWhite (m_header.colorMapType, colorMapData, imageData);
			break;
		}

		free (colorMapData);
		free (imageData);
	}

	void gstga::unload ()
	{
	}

	void gstga::processColorMapped (const int &colorType, char *colorMap, unsigned char *imageData)
	{
		if (colorType == 0)
		{
			printf ("colorType == 0 processColorMapped\n");
		}
		else if (colorType == 1)
		{
		}
	}

	void gstga::processTrue (const int &colorType, char *colorMap, unsigned char *imageData)
	{
		if (colorType == 0)
		{
			m_pData = new unsigned char [m_iWidth*m_iHeight*m_iBits];
			memset (m_pData, 0, m_iWidth*m_iHeight*m_iBits);
			//memcpy (m_pData, imageData, m_iWidth*m_iHeight*m_iBits);

			//The bits are in BGR order, so we need to swap them around here
			unsigned char *ptr = m_pData;
			unsigned char *from = imageData;
			for (int x = 0; x < m_iWidth; x++)
			{
				for (int y = 0; y < m_iHeight; y++)
				{
					ptr[0] = from[2];
					ptr[1] = from[1];
					ptr[2] = from[0];
					ptr[3] = from[3];
					ptr += 4;
					from += 4;
				}
			}
		}
		else if (colorType == 1)
		{
		}
	}

	void gstga::processBlackWhite (const int &colorType, char *colorMap, unsigned char *imageData)
	{
		if (colorType == 0)
		{
			printf ( "colorType == 0 processBlackWhite\n");
			m_pData = new unsigned char [m_iWidth*m_iHeight*m_iBits];
			memset (m_pData, 0, m_iWidth*m_iHeight*m_iBits);

			memcpy (m_pData, imageData, m_iWidth*m_iHeight*m_iBits);
		}
		else if (colorType == 1)
		{
		}
	}

	void gstga::processRLEColorMapped (const int &colorType, char *colorMap, unsigned char *imageData)
	{
		if (colorType == 0)
		{
		}
		else if (colorType == 1)
		{
		}
	}

	void gstga::processRLETrue (const int &colorType, char *colorMap, unsigned char *imageData)
	{
		if (colorType == 0)
		{
		}
		else if (colorType == 1)
		{
		}
	}

	void gstga::processRLEBlackWhite (const int &colorType, char *colorMap, unsigned char *imageData)
	{
		if (colorType == 0)
		{
		}
		else if (colorType == 1)
		{
		}
	}
};
