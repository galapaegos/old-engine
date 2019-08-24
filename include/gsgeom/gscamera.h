#ifndef _gscamera_h_
#define _gscamera_h_

#include <gsgeom/gsmatrix.h>
#include <gsgeom/gsobject.h>
#include <gsgeom/gsray.h>

namespace gsgeom
{
	class GS gscamera : public gsobject
	{
	public:
		gscamera ();
		~gscamera ();

		void setProjection (const int &iwidth, const int &iheight, const float &fov, const float &fnear, const float &ffar);
		void setOrthogonal (const int &w, const int &h, const float &near, const float &far);
		void setView (const gsvec3f &pos, const gsvec3f &look, const gsvec3f &up);

		gsmatrix getProjection () const { return m_mProj; }
		gsmatrix getView () const { return m_mView; }

		gsray getPicked (const float &fx, const float &fy) const;
		
		void moveForward (const float &fmove);
		void moveLeft (const float &fleft);
		void moveUp (const float &fup);
		
		void yaw (const float &fangle);
		void pitch (const float &fangle);
		void roll (const float &fangle);		

		int getWidth () const { return m_iWidth; }
		int getHeight () const { return m_iHeight; }

	protected:
		gsmatrix m_mView;
		gsmatrix m_mProj;

		gsvec3f m_vPos;

	private:
		gsvec3f m_vLook;
		
		gsvec3f m_vN;
		gsvec3f m_vV;
		gsvec3f m_vU;

		int m_iWidth;
		int m_iHeight;

		float m_fNear;
		float m_fFar;

		float m_fFOV;
		float m_fAspect;
	};
}

#endif

