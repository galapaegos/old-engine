#ifndef _TexturePreview_h_
#define _TexturePreview_h_

#include "gswindow/gswindow.h"

class TexturePreview : public gswin::gswindow
{
public:
	TexturePreview (unsigned long exStyle, const gsutil::gsstring &className, const gsutil::gsstring &windowTitle,
		unsigned long style, const int &x, const int &y, const int &w, const int &h);
	~TexturePreview ();

	virtual void onClose ();
	virtual void onPaint ();

private:
	HBITMAP m_hBitmap;
};

#endif
