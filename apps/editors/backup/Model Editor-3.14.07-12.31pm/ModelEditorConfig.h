#ifndef _ModelEditorConfig_h_
#define _ModelEditorConfig_h_

#include "galapaegos/gskernel.h"
#include "gsutil/gssingleton.h"
#include "gsutil/gssystem.h"
#include "gsutil/gsXMLParser.h"
#include "gswindow/gswindow.h"

class ModelEditorConfig : public gsutil::gssingleton <ModelEditorConfig>
{
public:
	ModelEditorConfig (const gsutil::gsstring &pConfig);
	~ModelEditorConfig ();

	void loadConfig ();
	void saveConfig ();

	struct WindowConfig
	{
		int x, y, w, h;
		gsutil::gsstring winName;
	};

	WindowConfig *getWindow (const gsutil::gsstring &windowName);
	void setWindow (const WindowConfig &config);

	gsutil::gsXMLParser *getParser () { return m_pParser; }

	gs::gskernel *m_pKernel;
	gsgeom::gsscene *m_pCurrentScene;
	gswin::gswindow *m_pMainWindow;
	gsgeom::gscamera *m_pMainCamera;

	//picked
	gsgeom::gsvec3i Index;

	int desktopWidth, desktopHeight;

private:
	gsutil::gsXMLParser *m_pParser;
	gsutil::gsqueue <WindowConfig*> m_Config;

	gsutil::gsstring m_strConfig;
};

#endif
