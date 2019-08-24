#ifndef _gscolor_h_
#define _gscolor_h_

#include <gstypes.h>

namespace gsgeom
{
	class GS gscolor
	{
	public:
		gscolor ()
		{
			m_Color[0] = 0.f;
			m_Color[1] = 0.f;
			m_Color[2] = 0.f;
			m_Color[3] = 0.f;
		}

		gscolor (const float &r, const float &g, const float &b) 
		{
			m_Color[0] = r;
			m_Color[1] = g;
			m_Color[2] = b;
			m_Color[3] = 0.f;
		}

		gscolor (const float &r, const float &g, const float &b, const float &a)
		{
			m_Color[0] = r;
			m_Color[1] = g;
			m_Color[2] = b;
			m_Color[3] = a;
		}

		~gscolor () {}

		const float &operator[] (const int &index) const
		{
			return m_Color[index];
		}

		float &operator[] (const int &index)
		{
			return m_Color[index];
		}

		void set (const float &fr, const float &fg, const float &fb, const float &fa)
		{
			m_Color[0] = fr;
			m_Color[1] = fg;
			m_Color[2] = fb;
			m_Color[3] = fa;
		}

		float getR () const { return m_Color[0]; }
		float getG () const { return m_Color[1]; }
		float getB () const { return m_Color[2]; }
		float getA () const { return m_Color[3]; }
		
		gscolor &operator= (const gscolor &v)
		{
			m_Color[0] = v.m_Color[0];
			m_Color[1] = v.m_Color[1];
			m_Color[2] = v.m_Color[2];
			m_Color[3] = v.m_Color[3];

			return (*this);
		}

	private:
		float m_Color[4];
	};
};

#endif

