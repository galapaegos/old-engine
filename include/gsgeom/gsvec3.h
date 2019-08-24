#ifndef _gsvec3_h_
#define _gsvec3_h_

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "gstypes.h"

namespace gsgeom
{
	template <class Type>
	class GS gsvec3
	{
	public:
		gsvec3 (const Type &x, const Type &y, const Type &z)
		{
			m_Val[0] = x;
			m_Val[1] = y;
			m_Val[2] = z;
		}

		gsvec3 ()
		{
			for (int x = 0; x < 3; x++)
				m_Val[x] = 0;
		}
		~gsvec3 () 
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

		Type length () 
		{ 
			return sqrt (m_Val[0]*m_Val[0] + 
						 m_Val[1]*m_Val[1] + 
						 m_Val[2]*m_Val[2]); 
		}

		Type distance (gsvec3<Type> v) 
		{ 
			return sqrt ((getX () - v.getX ())*(getX () - v.getX ()) +
						 (getY () - v.getY ())*(getY () - v.getY ()) +
						 (getZ () - v.getZ ())*(getZ () - v.getZ ()));
		}

		void normalize ()
		{
			Type len = length ();

			if (len != 0)
			{
				m_Val[0] /= len;
				m_Val[1] /= len;
				m_Val[2] /= len;
			}
		}

		void set (const Type &x, const Type &y, const Type &z)
		{
			m_Val[0] = x;
			m_Val[1] = y;
			m_Val[2] = z;
		}

		gsvec3 cross (gsvec3 v)
		{
			gsvec3 temp;

			temp[0] = m_Val[1]*v[2] - m_Val[2]*v[1];
			temp[1] = m_Val[2]*v[0] - m_Val[0]*v[2];
			temp[2] = m_Val[0]*v[1] - m_Val[1]*v[0];

			return temp;
		}

		Type dot (const gsvec3<Type> &v)
		{ 
			return (m_Val[0]*v[0] + 
					m_Val[1]*v[1] + 
					m_Val[2]*v[2]); 
		}
		
		gsvec3<Type> operator= (const gsvec3<Type> &v)
		{
			m_Val[0] = v[0];
			m_Val[1] = v[1];
			m_Val[2] = v[2];

			return (*this);
		}

		friend gsvec3<Type> operator+ (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			gsvec3<Type> temp;

			temp[0] = v1[0] + v2[0];
			temp[1] = v1[1] + v2[1];
			temp[2] = v1[2] + v2[2];

			return temp;
		}

		gsvec3<Type> operator+= (const gsvec3<Type> &v)
		{
			gsvec3<Type> temp;

			temp[0] = m_Val[0] + v[0];
			temp[1] = m_Val[1] + v[1];
			temp[2] = m_Val[2] + v[2];

			return temp;
		}

		friend gsvec3<Type> operator- (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			gsvec3<Type> temp;

			temp[0] = v1[0] - v2[0];
			temp[1] = v1[1] - v2[1];
			temp[2] = v1[2] - v2[2];

			return temp;
		}

		gsvec3<Type> operator-= (const gsvec3<Type> &v)
		{
			gsvec3<Type> temp;

			temp[0] = m_Val[0] - v[0];
			temp[1] = m_Val[1] - v[1];
			temp[2] = m_Val[2] - v[2];

			return temp;
		}

		friend gsvec3<Type> operator* (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			gsvec3<Type> temp;

			temp[0] = v1[0] * v2[0];
			temp[1] = v1[1] * v2[1];
			temp[2] = v1[2] * v2[2];

			return temp;
		}

		gsvec3<Type> operator*= (const gsvec3<Type> &v)
		{
			gsvec3<Type> temp;

			temp[0] = m_Val[0] * v[0];
			temp[1] = m_Val[1] * v[1];
			temp[2] = m_Val[2] * v[2];

			return temp;
		}

		friend gsvec3<Type> operator/ (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			gsvec3<Type> temp;

			if ((v2[0] != 0) && (v2[1] != 0) && (v2[2] != 0))
			{
				temp[0] = v1[0] / v2[0];
				temp[1] = v1[1] / v2[1];
				temp[2] = v1[2] / v2[2];
			}

			return temp;
		}

		gsvec3<Type> operator/= (const gsvec3<Type> &v)
		{
			gsvec3<Type> temp;

			if ((v[0] != 0) && (v[1] != 0) && (v[2] != 0))
			{
				temp[0] = m_Val[0] / v[0];
				temp[1] = m_Val[1] / v[1];
				temp[2] = m_Val[2] / v[2];
			}

			return temp;
		}

		friend gsvec3<Type> operator+ (const gsvec3<Type> &v, const float f)
		{
			gsvec3<Type> temp;

			temp[0] = v[0] + f;
			temp[1] = v[1] + f;
			temp[2] = v[2] + f;

			return temp;
		}

		gsvec3<Type> operator+= (const float f)
		{
			gsvec3<Type> temp;

			temp[0] = m_Val[0] + f;
			temp[1] = m_Val[1] + f;
			temp[2] = m_Val[2] + f;

			return temp;
		}

		friend gsvec3<Type> operator- (const gsvec3<Type> &v, const float f)
		{
			gsvec3<Type> temp;

			temp[0] = v[0] - f;
			temp[1] = v[1] - f;
			temp[2] = v[2] - f;

			return temp;
		}

		gsvec3<Type> operator-= (const float f)
		{
			gsvec3<Type> temp;

			temp[0] = m_Val[0] - f;
			temp[1] = m_Val[1] - f;
			temp[2] = m_Val[2] - f;

			return temp;
		}

		friend gsvec3<Type> operator* (const gsvec3<Type> &v, const float f)
		{
			gsvec3<Type> temp;

			temp[0] = v[0] * f;
			temp[1] = v[1] * f;
			temp[2] = v[2] * f;

			return temp;
		}

		friend gsvec3<Type> operator* (const float f, const gsvec3<Type> &v)
		{
			gsvec3<Type> temp;

			temp[0] = v[0] * f;
			temp[1] = v[1] * f;
			temp[2] = v[2] * f;

			return temp;
		}

		gsvec3<Type> operator*= (const float f)
		{
			gsvec3<Type> temp;

			temp[0] = m_Val[0] * f;
			temp[1] = m_Val[1] * f;
			temp[2] = m_Val[2] * f;

			return temp;
		}

		friend gsvec3<Type> operator/ (const gsvec3<Type> &v, const float f)
		{
			gsvec3<Type> temp;

			if (f != 0)
			{
				temp[0] = v[0] / f;
				temp[1] = v[1] / f;
				temp[2] = v[2] / f;
			}

			return temp;
		}

		gsvec3<Type> operator/= (const float f)
		{
			gsvec3<Type> temp;

			if (f == 0)
				return temp;

			temp[0] = m_Val[0] / f;
			temp[1] = m_Val[1] / f;
			temp[2] = m_Val[2] / f;

			return temp;
		}

		friend bool operator == (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			if ((v1[0] == v2[0]) && 
				(v1[1] == v2[1]) && 
				(v1[2] == v2[2]))
				return true;
			else
				return false;
		}

		friend bool operator < (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			if (v1[0] < v2[0] && v1[1] < v2[1] && v1[2] < v2[2])
				return true;
			else
				return false;
		}

		friend bool operator <= (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			if (v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2])
				return true;
			else
				return false;
		}

		friend bool operator > (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			if (v1[0] > v2[0] && v1[1] > v2[1] && v1[2] > v2[2])
				return true;
			else
				return false;
		}

		friend bool operator >= (const gsvec3<Type> &v1, const gsvec3<Type> &v2)
		{
			if (v1[0] >= v2[0] && v1[1] >= v2[1] && v1[2] >= v2[2])
				return true;
			else
				return false;
		}

		Type getX () const { return m_Val[0]; }
		Type getY () const { return m_Val[1]; }
		Type getZ () const { return m_Val[2]; }

	protected:
		Type m_Val[3];
	};

	typedef gsvec3<double> gsvec3d;
	typedef gsvec3<float> gsvec3f;
	typedef gsvec3<int> gsvec3i;
};

#endif

