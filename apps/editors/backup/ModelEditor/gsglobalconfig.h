#ifndef _gsglobalconfig_h_
#define _gsglobalconfig_h_

#include <windows.h>
#include "gsutil/gssingleton.h"
#include "gsutil/gsqueue.h"
#include "gsutil/gsXMLParser.h"
#include "gsvfs/gsfilesystem.h"
#include "galapaegos/gssceneloader.h"
#include "gsgeom/gsscene.h"

namespace gs
{
	class gsglobalconfig : public gsutil::gssingleton<gsglobalconfig>
	{
	public:
		gsglobalconfig ();
		~gsglobalconfig ();

		void loadConfig ();
		void saveConfig ();

		// this will get and set the distance from the camera to the object
		//that is about to be created
		void setPrimDist (float dis) { m_fPrimDist = dis; }
		float getPrimDist () { return m_fPrimDist; }

		void addPrimitive (gsgeom::gsscene *s) { m_PrimitiveList.add (s); }
		gsgeom::gsscene *getPrimitive (int index) { return m_PrimitiveList[index]; }

		void setSelected (gsgeom::gsscene *s) { m_pSelectedScene = s; }
		gsgeom::gsscene *getSelected () { return m_pSelectedScene; }

	private:
		float m_fPrimDist;
		gsXMLParser *m_pConfigDocument;
		gsqueue <gsgeom::gsscene *> m_PrimitiveList;

		gsgeom::gsscene *m_pSelectedScene;
	};
};

#endif