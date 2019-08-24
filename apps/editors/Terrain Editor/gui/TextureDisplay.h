#ifndef _TextureDisplay_h_
#define _TextureDisplay_h_

#include <gsimage/gsbmp.h>

#include <gswindow/gsbutton.h>
#include <gswindow/gswindow.h>
#include <gswindow/gslistbox.h>

#include <gsutil/gssystem.h>

#include "../TerrainConfig.h"

class TextureDisplay : public gswin::gswindow
{
public:
	TextureDisplay (const int &x, const int &y, const int &w, const int &h);
	~TextureDisplay ();

	virtual void onCommand (void *wParam, void *lParam);

private:
	gswin::gslistbox *m_pList;

	gswin::gsbutton *m_pOk, *m_pCancel;
};

#endif
