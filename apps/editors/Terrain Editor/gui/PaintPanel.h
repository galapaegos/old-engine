#ifndef _PaintPanel_h_
#define _PaintPanel_h_

#include "PaintTexturePanel.h"

class PaintPanel : public gswin::gstabpanel
{
public:
	PaintPanel (const unsigned long &exStyle, const gsutil::gsstring &c, 
		const gsutil::gsstring &t, const unsigned long &style, gswidget *parent);
	virtual ~PaintPanel ();

	virtual void onNotify (void *wParam, void *lParam);

private:
	gswin::gstabctl *m_pTabCtrl;
};


#endif
