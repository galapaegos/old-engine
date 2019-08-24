#include "TerrainEditor.h"

int main (int argc, char *argv[])
{
	INITCOMMONCONTROLSEX cmnctl;
	cmnctl.dwSize = sizeof (INITCOMMONCONTROLSEX);
	cmnctl.dwICC = ICC_TAB_CLASSES|ICC_PROGRESS_CLASS;
	InitCommonControlsEx (&cmnctl);

	TerrainConfig c("TerrainEditor.xml");
	TerrainConfig::set (&c);

	c.loadConfig ();

	TerrainEditor tw (800, 600);
	
	tw.handle ();

	c.saveConfig ();

	return 0;
}