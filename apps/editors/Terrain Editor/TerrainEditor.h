#ifndef _TerrainEditor_h_
#define _TerrainEditor_h_

#include <galapaegos/gskernel.h>
#include <gsutil/gsXMLParser.h>
#include <gswindow/gsmenu.h>

#include "gui/TileTabControl.h"
#include "TerrainConfig.h"

class TerrainEditor : public gswin::gswindow
{
public:
	TerrainEditor (const int &w, const int &h);
	virtual ~TerrainEditor ();

	virtual void onClose ();
	virtual void onCommand (void *wParam, void *lParam);
	virtual void onDestroy ();
	virtual void handle ();

	virtual void onKeyDown (void *wParam, void *lParam);

	virtual void onMouseMove (void *wParam, void *lParam);
	virtual void onMouseWheel (void *wParam, void *lParam);
	virtual void onMouseLeftDown (void *wParam, void *lParam);
	virtual void onMouseMiddleDown (void *wParam, void *lParam);
	virtual void onMouseRightDown (void *wParam, void *lParam);
	virtual void onMouseLeftUp (void *wParam, void *lParam);
	virtual void onMouseMiddleUp (void *wParam, void *lParam);
	virtual void onMouseRightUp (void *wParam, void *lParam);

private:
	gs::gskernel *m_pKernel;
	gsgeom::gsscene *m_pTopLevel, *m_pCurrentScene, *m_pPicking;

	TileTabControl *ToolsWindow;

	//mouse stuff
	int oldx, oldy;
	bool m_bLeftDown, m_bRightDown, m_bSelected;
	bool m_bLower, m_bRaise;
};

#endif
