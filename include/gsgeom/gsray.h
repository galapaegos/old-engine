#ifndef _gsray_h_
#define _gsray_h_

#include "gsvec3.h"
#include "gsvec4.h"

namespace gsgeom
{
	class GS gsray
	{
	public:
		gsray () {}
		gsray (const gsvec3f &pos, const gsvec3f &dir) : m_vPos (pos), m_vDir (dir) {}
		gsray (const gsvec4f &pos, const gsvec3f &dir)
		{
			m_vPos.set (pos[0], pos[1], pos[2]);
			m_vDir = dir;
		}
		gsray (const gsvec3f &pos, const gsvec4f &dir)
		{
			m_vPos = pos;
			m_vDir.set (dir[0], dir[1], dir[2]);
			//m_vDir.normalize ();
		}
		~gsray () {}

		gsray operator= (const gsray &v)
		{
			m_vPos = v.m_vPos;
			m_vDir = v.m_vDir;

			return (*this);
		}

		gsvec3f getPos () const { return m_vPos; }
		gsvec3f getDir () const { return m_vDir; }

	private:
		gsvec3f m_vPos;
		gsvec3f m_vDir;
	};
};

#endif

