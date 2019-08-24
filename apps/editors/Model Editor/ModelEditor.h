#ifndef _ModelEditor_h_
#define _ModelEditor_h_

#define _WIN32_WINNT 0x0400

#include <galapaegos/gskernel.h>

#include <gsphyzics/gscollision.h>

#include <gswindow/gsbox.h>
#include <gswindow/gsgroup.h>
#include <gswindow/gstabctl.h>
#include <gswindow/gswindow.h>

#include "data.h"

#include "CreatePanel.h"
#include "EditPanel.h"
#include "OptionsPanel.h"
#include "RenderPanel.h"
#include "ShadingPanel.h"
#include "TerrainPanel.h"

enum
{
	GL_PARENT,

	PROJECT_NEW,
	PROJECT_OPEN,
	PROJECT_SAVE,

	MANIPULATE_CAMERA,
	MANIPULATE_SELECT,

	TRANSFORM_TRANSLATE,
	TRANSFORM_ROTATE,
	TRANSFORM_SCALE
};

class ModelEditor : public gswin::gswindow
{
public:
	ModelEditor ();
	virtual ~ModelEditor ();

	virtual void onClose ();
	virtual void onNotify (void *wParam, void *lParam);
	virtual void onCommand (void *wParam, void *lParam);

	virtual void onMouseLeftDown (void *wParam, void *lParam);
	virtual void onMouseLeftUp (void *wParam, void *lParam);

	virtual void onMouseMiddleDown (void *wParam, void *lParam);
	virtual void onMouseMiddleUp (void *wParam, void *lParam);

	virtual void onMouseRightDown (void *wParam, void *lParam);
	virtual void onMouseRightUp (void *wParam, void *lParam);

	virtual void onMouseWheel (void *wParam, void *lParam);
	virtual void onMouseMove (void *wParam, void *lParam);

private:
	gs::gskernel *m_pKernel;
	gswin::gstabctl *m_pTabs;

	data *m_pData;

	bool m_bLeftButton, m_bMiddleButton, m_bRightButton;
	gsgeom::gsvec3f m_scale;
	int oldx, oldy;

	gsgeom::gsscene *m_pCurrentScene;
	gsgeom::gsvec3i m_selected;

	enum CURRENT_MODE
	{
		CAMERA,
		SELECTION,
		TRANSLATE,
		ROTATE,
		SCALE
	};
	//selection
	unsigned int m_currentMode;
};

#endif
