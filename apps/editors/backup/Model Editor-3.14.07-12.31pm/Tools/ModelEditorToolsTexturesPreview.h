#ifndef _ModelEditorToolsTexturesPreview_h_
#define _ModelEditorToolsTexturesPreview_h_

#include "gswindow/gswindow.h"

#include "../ModelEditorConfig.h"

class ModelEditorToolsTexturesPreview : public gswin::gswindow
{
public:
	ModelEditorToolsTexturesPreview (unsigned long exStyle, const gsutil::gsstring &className, const gsutil::gsstring &windowTitle,
		unsigned long style, const int &x, const int &y, const int &w, const int &h);
	~ModelEditorToolsTexturesPreview ();

	virtual void onClose ();
	virtual void onPaint ();

private:
	HBITMAP m_hBitmap;
};

#endif
