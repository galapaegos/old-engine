#ifndef _ModelEditorHud_h_
#define _ModelEditorHud_h_

#include "gsgeom/gsscene.h"

class ModelEditorHud
{
public:
	ModelEditorHud (const int &x, const int &y, const int &w, const int &h);
	~ModelEditorHud ();

private:
	gsgeom::gsscene *m_pHud;
};

#endif
