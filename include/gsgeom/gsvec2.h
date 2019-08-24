#ifndef _gsvec2_h_
#define _gsvec2_h_

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "gstypes.h"

namespace gsgeom
{
	template <class Type>
	class GS gsvec2
	{
	public:
		gsvec2 (const Type &fx, const Type &fy)
		{
			m_Val[0] = fx;
			m_Val[1] = fy;
		}

		gsvec2 ()
		{
			m_Val[0] = 0;
			m_Val[1] = 0;
		}

		~gsvec2 ()
		{
		}

		const Type &operator[] (const int index) const
		{
			return m_Val[index];
		}

		Type &operator[] (const int index)
		{
			return m_Val[index];
		}

		void set (const float &fx, const float &fy)
		{
			m_Val[0] = fx;
			m_Val[1] = fy;
		}

		gsvec2<Type> operator= (const gsvec2<Type> &v)
		{
			m_Val[0] = v[0];
			m_Val[1] = v[1];

			return (*this);
		}

		friend gsvec2<Type> operator+ (const gsvec2<Type> &v1, const gsvec2<Type> &v2)
		{
			gsvec2<Type> temp;

			temp[0] = v1[0] + v2[0];
			temp[1] = v1[1] + v2[1];

			return temp;
		}

		gsvec2<Type> operator+= (const gsvec2<Type> &v)
		{
			gsvec2<Type> temp;

			temp[0] = m_Val[0] + v[0];
			temp[1] = m_Val[1] + v[1];

			return temp;
		}

		friend gsvec2<Type> operator- (const gsvec2<Type> &v1, const gsvec2<Type> &v2)
		{
			gsvec2<Type> temp;

			temp[0] = v1[0] - v2[0];
			temp[1] = v1[1] - v2[1];

			return temp;
		}

		gsvec2<Type> operator-= (const gsvec2<Type> &v)
		{
			gsvec2<Type> temp;

			temp[0] = m_Val[0] - v[0];
			temp[1] = m_Val[1] - v[1];

			return temp;
		}

		friend gsvec2<Type> operator* (const gsvec2<Type> &v1, const gsvec2<Type> &v2)
		{
			gsvec2<Type> temp;

			temp[0] = v1[0] * v2[0];
			temp[1] = v1[1] * v2[1];

			return temp;
		}

		gsvec2<Type> operator*= (const gsvec2<Type> &v)
		{
			gsvec2<Type> temp;

			temp[0] = m_Val[0] * v[0];
			temp[1] = m_Val[1] * v[1];

			return temp;
		}

		friend gsvec2<Type> operator/ (const gsvec2<Type> &v1, const gsvec2<Type> &v2)
		{
			gsvec2<Type> temp;

			if ((v2[0] != 0) && (v2[1] != 0))
			{
				temp[0] = v1[0] / v2[0];
				temp[1] = v1[1] / v2[1];
			}

			return temp;
		}

		gsvec2<Type> operator/= (const gsvec2<Type> &v)
		{
			gsvec2<Type> temp;

			if ((v[0] != 0) && (v[1] != 0))
			{
				temp[0] = m_Val[0] / v[0];
				temp[1] = m_Val[1] / v[1];
			}

			return temp;
		}

		friend gsvec2<Type> operator+ (const gsvec2<Type> &v, const Type f)
		{
			gsvec2<Type> temp;

			temp[0] = v[0] + f;
			temp[1] = v[1] + f;

			return temp;
		}

		gsvec2<Type> operator+= (const Type f)
		{
			gsvec2<Type> temp;

			temp[0] = m_Val[0] + f;
			temp[1] = m_Val[1] + f;

			return temp;
		}

		friend gsvec2<Type> operator- (const gsvec2<Type> &v, const Type f)
		{
			gsvec2<Type> temp;

			temp[0] = v[0] - f;
			temp[1] = v[1] - f;

			return temp;
		}

		gsvec2<Type> operator-= (const Type f)
		{
			gsvec2<Type> temp;

			temp[0] = m_Val[0] - f;
			temp[1] = m_Val[1] - f;

			return temp;
		}

		friend gsvec2<Type> operator* (const gsvec2<Type> &v, const Type f)
		{
			gsvec2<Type> temp;

			temp[0] = v[0] * f;
			temp[1] = v[1] * f;

			return temp;
		}

		gsvec2<Type> operator*= (const float f)
		{
			gsvec2<Type> temp;

			temp[0] = m_Val[0] * f;
			temp[1] = m_Val[1] * f;

			return temp;
		}

		friend gsvec2<Type> operator/ (const gsvec2<Type> &v, const Type f)
		{
			gsvec2<Type> temp;

			if (f != 0)
			{
				temp[0] = v[0] / f;
				temp[1] = v[1] / f;
			}

			return temp;
		}

		gsvec2<Type> operator/= (const float f)
		{
			gsvec2<Type> temp;

			if (f != 0)
			{
				temp[0] = m_Val[0] / f;
				temp[1] = m_Val[1] / f;
			}

			return temp;
		}

		friend bool operator == (const gsvec2<Type> &v1, const gsvec2<Type> &v2)
		{
			if ((v1.m_Val[0] == v2.m_Val[0]) && 
				(v1.m_Val[1] == v2.m_Val[1]))
				return true;
			else
				return false;
		}
	
		Type getX () const { return m_Val[0]; }
		Type getY () const { return m_Val[1]; }
	private:
		Type m_Val[2];
	};

	typedef gsvec2<double> gsvec2d;
	typedef gsvec2<float> gsvec2f;
	typedef gsvec2<int> gsvec2i;
};

#endif

