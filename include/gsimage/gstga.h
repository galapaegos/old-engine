#ifndef _gstga_h_
#define _gstga_h_

#include "gstexture.h"

namespace gsimage
{
	class GS gstga : public gstexture
	{
		struct TgaHeader
		{
			//intro
			unsigned char idLength, colorMapType, imageType;
			unsigned char colorMapSpec[5];
			unsigned char imageSpec[10];

			//tga file footer, transitions between old and new format
			long extAreaOffset, devDirOffset;
		};

		void processColorMapped (const int &colorType, char *colorMap, unsigned char *imageData);
		void processTrue (const int &colorType, char *colorMap, unsigned char *imageData);
		void processBlackWhite (const int &colorType, char *colorMap, unsigned char *imageData);

		void processRLEColorMapped (const int &colorType, char *colorMap, unsigned char *imageData);
		void processRLETrue (const int &colorType, char *colorMap, unsigned char *imageData);
		void processRLEBlackWhite (const int &colorType, char *colorMap, unsigned char *imageData);

	public:
		gstga ();
		virtual ~gstga ();

		virtual void load (const gsutil::gsstring &pFilename);
		virtual void unload ();

		TgaHeader m_header;
	};
};

/*
GLubyte		TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0}; // Uncompressed TGA Header
GLubyte		TGAcompare[12];					// Used To Compare TGA Header
GLubyte		header[6];						// First 6 Useful Bytes From The Header
GLuint		bytesPerPixel;					// Holds Number Of Bytes Per Pixel Used In The TGA File
GLuint		imageSize;						// Used To Store The Image Size When Setting Aside Ram
GLuint		temp;							// Temporary Variable
GLuint		type=GL_RGBA;					// Set The Default GL Mode To RBGA (32 BPP)

FILE *file = fopen(filename, "rb");			// Open The TGA File

if(	file==NULL ||							// Does File Even Exist?
	fread(TGAcompare,1,sizeof(TGAcompare),file)!=sizeof(TGAcompare) ||	// Are There 12 Bytes To Read?
	memcmp(TGAheader,TGAcompare,sizeof(TGAheader))!=0 ||	// Does The Header Match What We Want?
	fread(header,1,sizeof(header),file)!=sizeof(header))	// If So Read Next 6 Header Bytes
{
	if (file == NULL)						// Does The File Even Exist? *Added Jim Strong*
		return FALSE;						// Return False
	else									// Otherwise
	{
		fclose(file);						// If Anything Failed, Close The File
		return FALSE;						// Return False
	}
}

texture->width  = header[1] * 256 + header[0];	// Determine The TGA Width	(highbyte*256+lowbyte)
texture->height = header[3] * 256 + header[2];	// Determine The TGA Height	(highbyte*256+lowbyte)

if(	texture->width	<=0 ||					// Is The Width Less Than Or Equal To Zero
	texture->height	<=0 ||					// Is The Height Less Than Or Equal To Zero
	(header[4]!=24 && header[4]!=32))		// Is The TGA 24 or 32 Bit?
{
	fclose(file);							// If Anything Failed, Close The File
	return FALSE;							// Return False
}

texture->bpp	= header[4];				// Grab The TGA's Bits Per Pixel (24 or 32)
bytesPerPixel	= texture->bpp/8;			// Divide By 8 To Get The Bytes Per Pixel
imageSize		= texture->width*texture->height*bytesPerPixel;	// Calculate The Memory Required For The TGA Data

texture->imageData=(GLubyte *)malloc(imageSize);	// Reserve Memory To Hold The TGA Data

if(	texture->imageData==NULL ||				// Does The Storage Memory Exist?
	fread(texture->imageData, 1, imageSize, file)!=imageSize)	// Does The Image Size Match The Memory Reserved?
{
	if(texture->imageData!=NULL)			// Was Image Data Loaded
		free(texture->imageData);			// If So, Release The Image Data

	fclose(file);							// Close The File
	return FALSE;							// Return False
}

for(GLuint i=0; i<int(imageSize); i+=bytesPerPixel)		// Loop Through The Image Data
{											// Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
	temp=texture->imageData[i];				// Temporarily Store The Value At Image Data 'i'
	texture->imageData[i] = texture->imageData[i + 2];	// Set The 1st Byte To The Value Of The 3rd Byte
	texture->imageData[i + 2] = temp;		// Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
}

fclose (file);
*/

#endif
