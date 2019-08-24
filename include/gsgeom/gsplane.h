#ifndef _plane_h_
#define _plane_h_

#include "gsvec3.h"
#include "gsvec4.h"

namespace gsgeom
{
	class GS gsplane
	{
	public:
		gsplane () {}
		gsplane (const float &d, const gsvec3f &n) 
		{ 
			m_vNormal = n;
			m_fDist = d;
			//m_vPoint = n*d;
		}
		gsplane (const float &fx, const float &fy, const float &fz, const float &fd)
		{
			m_vNormal.set (fx, fy, fz);
			m_fDist = fd;
		}
		~gsplane () {}

		float getDistance () { return m_fDist; }
		gsvec3f getNormal () { return m_vNormal; }
		gsvec3f getPoint () { return m_vNormal; }
		void setDistance (const float &d) 
		{ 
			m_fDist = d;
			//m_vPoint = m_vNormal*d;
		}
		void setNormal (const gsvec3f &n) 
		{ 
			m_vNormal = n;
			//m_vPoint = (n*m_fDist);
		}

	private:
		// uses the plane equation, point on the plane, distance from origin.
		gsvec3f m_vPoint;
		gsvec3f m_vNormal;
		float m_fDist;
	};
};

#endif

