#include "WorldEditor.h"

WorldEditor::WorldEditor (const int &w, const int &h) : 
	gswin::gswindow (0, "modeleditor", "Model Editor v0.1", 0, 0, 0, w, h)
{
	m_pKernel = new gs::gskernel;
	m_pKernel->init (getHandle (), w, h);
}

WorldEditor::~WorldEditor ()
{
	delete m_pKernel;
}

void WorldEditor::handle ()
{
	while (m_iRun == 1)
		gswin::gswindow::handle ();
}
