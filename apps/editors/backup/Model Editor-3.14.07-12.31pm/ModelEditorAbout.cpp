#include "ModelEditorAbout.h"

ModelEditorAbout::ModelEditorAbout (const int &x, const int &y, const int &w, const int &h) : 
	gswin::gswindow (0, "ModelEditorAbout", "About", WS_OVERLAPPEDWINDOW, x, y, w, h)
{
}

ModelEditorAbout::~ModelEditorAbout ()
{
}

void ModelEditorAbout::onDestroy ()
{
	delete this;
}
