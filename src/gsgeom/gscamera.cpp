#include "gsgeom/gscamera.h"

namespace gsgeom
{
	gscamera::gscamera () : gsobject ()
	{
	}

	gscamera::~gscamera ()
	{
	}

	void gscamera::setOrthogonal (const int &w, const int &h, const float &near, const float &far)
	{
		m_iWidth = w;
		m_iHeight = h;

		m_fNear = near;
		m_fFar = far;

		/*
		2/w  0    0           0
		0    2/h  0           0
		0    0    1/(zf-zn)   0
		0    0    zn/(zn-zf)  1
		*/

		m_mProj = gsmatrix (2.f/(float)m_iWidth,	0.0f,					0.0f,						0,
							0.0f,					2.f/(float)m_iHeight,	0.0f,						0,
							0.0f,					0.0f,					1.f/(m_fFar - m_fNear),		0,
							0.0f,					0.0f,					m_fNear/(m_fNear - m_fFar),	1.0f);
	}

	void gscamera::setProjection (const int &iwidth, const int &iheight, const float &fov, const float &fnear, const float &ffar)
	{
		m_fNear = fnear;
		m_fFar = ffar;

		m_iWidth = iwidth;
		m_iHeight = iheight;

		m_fAspect = (float)iwidth/(float)iheight;
		m_fFOV = fov;

		float f = 1.f/((float)tanf ((((float)M_PI/180.f)*fov)/2));
		m_mProj = gsmatrix (f/m_fAspect,	0,	0,										0,
							0,				f,	0,										0,
							0,				0,	(m_fNear + m_fFar)/(m_fNear - m_fFar),	2*m_fNear*m_fFar/(m_fNear - m_fFar),
							0,				0,	-1,										0);
	}

	void gscamera::setView (const gsvec3f &pos, const gsvec3f &look, const gsvec3f &up)
	{
		m_vPos = pos;
		m_vLook = look;
		gsvec3f world = up;

		m_vN = pos - look;
		m_vN.normalize ();

		m_vU = world.cross (m_vN);
		m_vU.normalize ();

		m_vV = m_vN.cross (m_vU);

		m_mView = gsmatrix (m_vU[0],	m_vU[1],	m_vU[2],	-m_vU.dot (m_vPos),
							m_vV[0],	m_vV[1],	m_vV[2],	-m_vV.dot (m_vPos),
							m_vN[0],	m_vN[1],	m_vN[2],	-m_vN.dot (m_vPos),
							0,			0,			0,			1);
	}

	gsray gscamera::getPicked (const float &fx, const float &fy) const
	{
		gsvec4f v;
		v[0] = 2*fx/(float)m_iWidth - 1;
		v[1] = 2*fy/(float)m_iHeight - 1;
		v[2] = 2*0 - 1;
		v[3] = 1.f;

		gsmatrix l = m_mProj*m_mView;
		gsmatrix i = l.inverse ();

		gsvec4f d;
		d = i*v;
		gsvec3f p, dir, dv;
		dv.set (d[0], d[1], d[2]);
		p.set (m_vPos.getX (), m_vPos.getY (), m_vPos.getZ ());
		dir = p - dv;
		dir.normalize ();

		return gsray (p, dir);
	}

	void gscamera::moveForward (const float &fmove)
	{
		m_vPos = m_vPos + m_vN*fmove;
		
		m_mView = gsmatrix (m_vU[0],	m_vU[1],	m_vU[2],	-m_vU.dot (m_vPos),
							m_vV[0],	m_vV[1],	m_vV[2],	-m_vV.dot (m_vPos),
							m_vN[0],	m_vN[1],	m_vN[2],	-m_vN.dot (m_vPos),
							0,			0,			0,			1);
	}

	void gscamera::moveLeft (const float &fleft)
	{
		m_vPos = m_vPos + m_vU*fleft;
		
		m_mView = gsmatrix (m_vU[0],	m_vU[1],	m_vU[2],	-m_vU.dot (m_vPos),
							m_vV[0],	m_vV[1],	m_vV[2],	-m_vV.dot (m_vPos),
							m_vN[0],	m_vN[1],	m_vN[2],	-m_vN.dot (m_vPos),
							0,			0,			0,			1);
	}

	void gscamera::moveUp (const float &fup)
	{
		m_vPos = m_vPos + m_vV*fup;
		
		m_mView = gsmatrix (m_vU[0],	m_vU[1],	m_vU[2],	-m_vU.dot (m_vPos),
							m_vV[0],	m_vV[1],	m_vV[2],	-m_vV.dot (m_vPos),
							m_vN[0],	m_vN[1],	m_vN[2],	-m_vN.dot (m_vPos),
							0,			0,			0,			1);
	}

	void gscamera::yaw (const float &fangle)
	{
		float cs = (float)cos ((3.14159265/180)*fangle);
		float sn = (float)sin ((3.14159265/180)*fangle);
		
		gsvec3f u = m_vU;
		gsvec3f n = m_vN;
		
		m_vU = gsvec3f (cs*u[0] - sn*n[0], cs*u[1] - sn*n[1], cs*u[2] - sn*n[2]);
		m_vN = gsvec3f (sn*u[0] + cs*n[0], sn*u[1] + cs*n[1], sn*u[2] + cs*n[2]);
		
		m_mView = gsmatrix ((float)m_vU[0], (float)m_vU[1], (float)m_vU[2], -m_vPos.dot (m_vU),
							(float)m_vV[0], (float)m_vV[1], (float)m_vV[2], -m_vPos.dot (m_vV),
							(float)m_vN[0], (float)m_vN[1], (float)m_vN[2], -m_vPos.dot (m_vN),
							0.0f, 0.0f, 0.0f, 1.0f);
	}

	void gscamera::pitch (const float &fangle)
	{
		float cs = (float)cos ((3.14159265/180)*fangle);
		float sn = (float)sin ((3.14159265/180)*fangle);
		
		gsvec3f n = m_vN;
		gsvec3f v = m_vV;
		
		m_vN = gsvec3f (cs*n[0] - sn*v[0], cs*n[1] - sn*v[1], cs*n[2] - sn*v[2]);
		m_vV = gsvec3f (sn*n[0] + cs*v[0], sn*n[1] + cs*v[1], sn*n[2] + cs*v[2]);
		
		m_mView = gsmatrix ((float)m_vU[0], (float)m_vU[1], (float)m_vU[2], -m_vPos.dot (m_vU),
							(float)m_vV[0], (float)m_vV[1], (float)m_vV[2], -m_vPos.dot (m_vV),
							(float)m_vN[0], (float)m_vN[1], (float)m_vN[2], -m_vPos.dot (m_vN),
							0.0f, 0.0f, 0.0f, 1.0f);
	}

	void gscamera::roll (const float &fangle)
	{
		float cs = (float)cos ((3.14159265/180)*fangle);
		float sn = (float)sin ((3.14159265/180)*fangle);
		
		gsvec3f u = m_vU;
		gsvec3f v = m_vV;
		
		m_vU = gsvec3f (cs*u[0] - sn*v[0], cs*u[1] - sn*v[1], cs*u[2] - sn*v[2]);
		m_vV = gsvec3f (sn*u[0] + cs*v[0], sn*u[1] + cs*v[1], sn*u[2] + cs*v[2]);
		
		m_mView = gsmatrix ((float)m_vU[0], (float)m_vU[1], (float)m_vU[2], -m_vPos.dot (m_vU),
							(float)m_vV[0], (float)m_vV[1], (float)m_vV[2], -m_vPos.dot (m_vV),
							(float)m_vN[0], (float)m_vN[1], (float)m_vN[2], -m_vPos.dot (m_vN),
							0.0f, 0.0f, 0.0f, 1.0f);
	}
}
