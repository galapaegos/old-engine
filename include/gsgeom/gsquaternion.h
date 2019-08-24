#ifndef _gsquaternion_h_
#define _gsquaternion_h_

#include "gsmatrix.h"

namespace gsgeom
{
	class GS gsquaternion
	{
	public:
		gsquaternion () { x = 0.f; y = 0.f; z = 0.f; w = 0.f; }
		~gsquaternion () {}

		void conjugate ()
		{
			x = -x;
			y = -y;
			z = -z;
		}

		gsquaternion inverse ()
		{
			gsquaternion q = (*this);
			q.conjugate ();

			//float fnorm = norm ();

			q[0] /= norm ();
			q[1] /= norm ();
			q[2] /= norm ();
			q[3] /= norm ();

			return q;
		}

		float mod () const 
		{
			float fnorm = norm ();

			return sqrtf (fnorm);
		}

		float norm () const
		{
			return (w*w + x*x + y*y + z*z);
		}

		gsmatrix transformation ()
		{
			gsmatrix m;

			m (1, 1) = 1 - 2*y*y - 2*z*z;
			m (1, 2) = 2*x*y + 2*w*z;
			m (1, 3) = 2*x*z - 2*w*y;
			
			m (2, 1) = 2*x*y - 2*w*z;
			m (2, 2) = 1 - 2*x*x - 2*z*z;
			m (2, 3) = 2*y*z + 2*w*x;

			m (3, 1) = 2*x*z + 2*w*y;
			m (3, 2) = 2*y*z - 2*w*x;
			m (3, 3) = 1 - 2*x*x - 2*y*y;

			return m;
		}

		float &operator[] (int index)
		{
			switch (index)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			}

			return w;
		}

		const float &operator[] (int index) const
		{
			switch (index)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			}

			return w;
		}

		gsquaternion operator+ (const gsquaternion &q)
		{
			gsquaternion t;

			t.x = x + q[0];
			t.y = y + q[1];
			t.z = z + q[2];
			
			t.w = w + q[3];

			return t;
		}

		gsquaternion operator- (const gsquaternion &q)
		{
			gsquaternion t;

			t.x = x - q[0];
			t.y = y - q[1];
			t.z = z - q[2];
			
			t.w = q[3] - w;

			return t;
		}

		gsquaternion operator* (const gsquaternion &q)
		{
			gsquaternion t;

			t.w = w*q[3] - x*q[0] - y*q[1] - z*q[2];
			t.x = w*q[0] + x*q[3] + y*q[2] - z*q[1];
			t.y = w*q[1] - x*q[2] + y*q[3] - z*q[0];
			t.z = w*q[2] - x*q[1] - y*q[0] - z*q[3];

			return t;
		}

		//gsquaternion operator/ (const gsquaternion &q)
		//{
		//	gsquaternion t = q;
		//	t.conjugate ();

		//	t[0] /= q.norm ();
		//	t[1] /= q.norm ();
		//	t[2] /= q.norm ();
		//	t[3] /= q.norm ();

		//	return q*(*this);
		//}

	private:
		float w, x, y, z;
	};
};

#endif

