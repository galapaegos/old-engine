#include <windows.h>
#include <commctrl.h>

#include "ModelEditor.h"
#include "ModelEditorConfig.h"

int main (int argc, char *argv[])
{
	INITCOMMONCONTROLSEX cc;
	cc.dwSize = sizeof (INITCOMMONCONTROLSEX);
	cc.dwICC = ICC_TAB_CLASSES|ICC_PROGRESS_CLASS;
	if (!InitCommonControlsEx (&cc))
		MessageBox (NULL, "unable to init common controls", "msg", MB_OK);

	ModelEditorConfig *p = new ModelEditorConfig ("ModelEditor.xml");
	ModelEditorConfig::set (p);

	ModelEditorConfig::get ()->loadConfig ();

	int frameWidth = GetSystemMetrics (SM_CXSIZEFRAME)*2;
	int frameHeight = GetSystemMetrics (SM_CYCAPTION) + GetSystemMetrics (SM_CYMENU) + GetSystemMetrics (SM_CYSIZEFRAME)*2;
	ModelEditor mw (800 + frameWidth, 600 + frameHeight);
	
	mw.handle ();

	ModelEditorConfig::get ()->saveConfig ();

	return 0;
}