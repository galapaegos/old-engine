#ifndef _gscameranode_h_
#define _gscameranode_h_

#include <gsgeom/gscamera.h>

#include <gsscene/gsscenenode.h>

namespace gsscene
{
	class GS gscameranode : public gsscenenode
	{
	public:
		gscameranode ();
		virtual ~gscameranode ();

		enum CAMERA_TYPE
		{
			CAMERA_MAIN=1,
			CAMERA_LIGHT,
			CAMERA_OFFSCREEN
		};

		gsgeom::gscamera *getCamera ();

		void setType (const unsigned int &type);
		unsigned int getType ();

		void setOrthographic (const int &iWidth, const int &iHeight, const float &fNear, const float &fFar);
		void setProjection (const int &width, const int &height, const float &angle, const float &near, const float &far);
		void setView (const gsgeom::gsvec3f &pos, const gsgeom::gsvec3f &org, const gsgeom::gsvec3f &world);

		void render (gsgfx::gsrenderer *renderer);

	protected:
		gsgeom::gscamera *m_pCamera;

		unsigned int m_iType;
	};
};

#endif
