#include "ModelEditorToolsTexturesPreview.h"

ModelEditorToolsTexturesPreview::ModelEditorToolsTexturesPreview (unsigned long exStyle, const gsutil::gsstring &className, const gsutil::gsstring &windowTitle, unsigned long style, const int &x, const int &y, const int &w, const int &h) : gswin::gswindow (exStyle, className, windowTitle, style, x, y, w, h)
{
	m_hBitmap = (HBITMAP)LoadImage (getInst (), getTitle ().str (), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	HDC hDest = GetDC (getHandle ());
	HDC hdc = CreateCompatibleDC (NULL);
	SelectObject (hdc, m_hBitmap);

	BITMAP bmp;
	GetObject (m_hBitmap, sizeof (BITMAP), &bmp);

	int dskW = ModelEditorConfig::get ()->desktopWidth;
	int dskH = ModelEditorConfig::get ()->desktopHeight;
	resize (dskW/2 - bmp.bmWidth/2, dskH/2 - bmp.bmHeight/2, bmp.bmWidth, bmp.bmHeight);

	DeleteDC (hdc);

	SendMessage (getHandle (), WM_PAINT, 0, 0);
}

ModelEditorToolsTexturesPreview::~ModelEditorToolsTexturesPreview ()
{
}

void ModelEditorToolsTexturesPreview::onPaint ()
{
	PAINTSTRUCT ps;
	BeginPaint (getHandle (), &ps);

	HDC hDest = GetDC (getHandle ());
	HDC hdc = CreateCompatibleDC (NULL);
	SelectObject (hdc, m_hBitmap);

	BITMAP bmp;
	GetObject (m_hBitmap, sizeof (BITMAP), &bmp);
	BitBlt (hDest, 0, 0, bmp.bmWidth, bmp.bmHeight, hdc, 0, 0, SRCCOPY);
	DeleteDC (hdc);

	EndPaint (getHandle (), &ps);
}

void ModelEditorToolsTexturesPreview::onClose ()
{
	DestroyWindow (getHandle ());
	UnregisterClass (getClass ().str (), getInst ());
	delete this;
}
