#ifndef _gsvec4_h_
#define _gsvec4_h_

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "gstypes.h"

namespace gsgeom
{
		template <class Type>
	class GS gsvec4
	{
	public:
		gsvec4 (const float &fx, const float &fy, const float &fz, const float &fw)
		{
			m_Val[0] = fx;
			m_Val[1] = fy;
			m_Val[2] = fz;
			m_Val[3] = fw;
		}

		gsvec4 ()
		{
			m_Val[0] = 0;
			m_Val[1] = 0;
			m_Val[2] = 0;
			m_Val[3] = 0;
		}

		~gsvec4 ()
		{
		}

		inline float distance () { return sqrt (m_Val[0]*m_Val[0] + m_Val[1]*m_Val[1] + m_Val[2]*m_Val[2] + m_Val[3]*m_Val[3]); }

		const Type &operator[] (const int index) const
		{
			return m_Val[index];
		}

		Type &operator[] (const int index)
		{
			return m_Val[index];
		}

		gsvec4<Type> operator= (const gsvec4<Type> &v)
		{
			for (int x = 0; x < 3; x++)
				m_Val[x] = v.m_Val[x];

			return (*this);
		}

		friend gsvec4<Type> operator+ (const gsvec4<Type> &v1, const gsvec4<Type> &v2)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v1[x] + v2[x];

			return temp;
		}

		friend gsvec4<Type> operator- (const gsvec4<Type> &v1, const gsvec4<Type> &v2)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v1[x] - v2[x];

			return temp;
		}

		friend gsvec4<Type> operator* (const gsvec4<Type> &v1, const gsvec4<Type> &v2)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v1[x] * v2[x];

			return temp;
		}

		friend gsvec4<Type> operator/ (const gsvec4<Type> &v1, const gsvec4<Type> &v2)
		{
			gsvec4<Type> temp;

			if ((v2.x != 0) && (v2.y != 0) && (v2.z != 0))
			{
				for (int x = 0; x < 3; x++)
					temp[x] = v1[x] / v2[x];
			}

			return temp;
		}

		friend gsvec4<Type> operator+= (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v[x] + f;

			return temp;
		}

		friend gsvec4<Type> operator-= (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v[x] - f;

			return temp;
		}

		friend gsvec4<Type> operator*= (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v[x] * f;

			return temp;
		}

		friend gsvec4<Type> operator/= (const gsvec4<Type> &v, const Type f)
		{
			gsvec4<Type> temp;

			if (f != 0)
			{
				for (int x = 0; x < 3; x++)
					temp[x] = v[x] / f;
			}

			return temp;
		}

		friend gsvec4<Type> operator+ (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v[x] + f;

			return temp;
		}

		friend gsvec4<Type> operator- (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v[x] - f;

			return temp;
		}

		friend gsvec4<Type> operator* (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			for (int x = 0; x < 3; x++)
				temp[x] = v[x] * f;

			return temp;
		}

		friend gsvec4<Type> operator/ (const gsvec4<Type> &v, const float f)
		{
			gsvec4<Type> temp;

			if (f != 0)
			{
				for (int x = 0; x < 3; x++)
				temp[x] = v[x] / f;
			}

			return temp;
		}

		friend bool operator == (const gsvec4<Type> &v1, const gsvec4<Type> &v2)
		{
			if ((v1.m_Val[0] == v2.m_Val[0]) && 
				(v1.m_Val[1] == v2.m_Val[1]) && 
				(v1.m_Val[2] == v2.m_Val[2]))
				return true;
			else
				return false;
		}

	private:
		Type m_Val[4];
	};

	typedef gsvec4<double> gsvec4d;
	typedef gsvec4<float> gsvec4f;
	typedef gsvec4<int> gsvec4i;
	typedef gsvec4<unsigned char> gsvec4uc;
};

#endif

