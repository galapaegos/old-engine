#ifndef _gsmatrix_h_
#define _gsmatrix_h_

#include <stdio.h>
#include "gsgeom/gsvec3.h"
#include "gsgeom/gsvec4.h"

namespace gsgeom
{
	class GS gsmatrix
	{
	public:
		gsmatrix () { identity (); }
		gsmatrix (const float _a1, const float _a2, const float _a3, const float _a4,
				  const float _b1, const float _b2, const float _b3, const float _b4,
				  const float _c1, const float _c2, const float _c3, const float _c4,
				  const float _d1, const float _d2, const float _d3, const float _d4)
		{
			_11 = _a1; _12 = _a2; _13 = _a3; _14 = _a4;
			_21 = _b1; _22 = _b2; _23 = _b3; _24 = _b4;
			_31 = _c1; _32 = _c2; _33 = _c3; _34 = _c4;
			_41 = _d1; _42 = _d2; _43 = _d3; _44 = _d4;
		}

		~gsmatrix () { }
		
		float *getMatrix ()
		{
			float *temp = new float[16];
			temp[0] =  _11; temp[1] =  _12; temp[2] =  _13; temp[3] =  _14;
			temp[4] =  _21; temp[5] =  _22; temp[6] =  _23; temp[7] =  _24;
			temp[8] =  _31; temp[9] =  _32; temp[10] = _33; temp[11] =  _34;
			temp[12] =  _41; temp[13] =  _42; temp[14] = _43; temp[15] =  _44;
			
			return temp;
		}

		float det ()
		{
			return (_11*_22*_33*_44 + _11*_23*_34*_42 + _11*_24*_32*_43 +
					_12*_21*_34*_43 + _12*_23*_31*_44 + _12*_24*_33*_41 +
					_13*_21*_32*_44 + _13*_22*_34*_41 + _13*_24*_31*_42 +
					_14*_21*_33*_42 + _14*_22*_31*_43 + _14*_23*_32*_41 -
					_11*_22*_34*_43 - _11*_23*_32*_44 - _11*_24*_33*_42 -
					_12*_21*_33*_44 - _12*_23*_34*_41 - _12*_24*_31*_43 -
					_13*_21*_34*_42 - _13*_22*_31*_44 - _13*_24*_32*_41 -
					_14*_21*_32*_43 - _14*_22*_33*_41 - _14*_23*_31*_42);
		}

		void identity ()
		{
			_11 = 1.0f; _12 = 0.0f; _13 = 0.0f; _14 = 0.0f;
			_21 = 0.0f; _22 = 1.0f; _23 = 0.0f; _24 = 0.0f;
			_31 = 0.0f; _32 = 0.0f; _33 = 1.0f; _34 = 0.0f;
			_41 = 0.0f; _42 = 0.0f; _43 = 0.0f; _44 = 1.0f;
		}

		gsmatrix inverse ()
		{
			float fdeterminate = det ();
			gsmatrix inv;

			if (fdeterminate != 0)
			{
				float fdet = 1.f/fdeterminate;

				float b11 = _22*_33*_44 + _23*_34*_42 + _24*_32*_43 - _22*_34*_43 - _23*_32*_44 - _24*_33*_42;
				float b12 = _12*_34*_43 + _13*_32*_44 + _14*_33*_42 - _12*_33*_44 - _13*_34*_42 - _14*_32*_43;
				float b13 = _12*_23*_44 + _13*_24*_42 + _14*_22*_43 - _12*_24*_43 - _13*_22*_44 - _14*_23*_42;
				float b14 = _12*_24*_33 + _13*_22*_34 + _14*_23*_32 - _12*_23*_34 - _13*_24*_32 - _14*_22*_33;
				float b21 = _21*_34*_43 + _23*_31*_44 + _24*_33*_41 - _21*_33*_44 - _23*_34*_41 - _24*_31*_43;
				float b22 = _11*_33*_44 + _13*_34*_41 + _14*_31*_43 - _11*_34*_43 - _13*_31*_44 - _14*_33*_41;
				float b23 = _11*_24*_43 + _13*_21*_44 + _14*_23*_41 - _11*_23*_44 - _13*_24*_41 - _14*_21*_43;
				float b24 = _11*_23*_34 + _13*_24*_31 + _14*_21*_33 - _11*_24*_33 - _13*_21*_34 - _14*_23*_31;
				float b31 = _21*_32*_44 + _22*_34*_41 + _24*_31*_42 - _21*_34*_42 - _22*_31*_44 - _24*_32*_41;
				float b32 = _11*_34*_42 + _12*_31*_44 + _14*_32*_41 - _11*_32*_44 - _12*_34*_41 - _14*_31*_42;
				float b33 = _11*_22*_44 + _12*_24*_41 + _14*_21*_42 - _11*_24*_42 - _12*_21*_44 - _14*_22*_41;
				float b34 = _11*_24*_32 + _12*_21*_34 + _14*_22*_31 - _11*_22*_34 - _12*_24*_31 - _14*_21*_32;
				float b41 = _21*_33*_42 + _22*_31*_43 + _23*_32*_41 - _21*_32*_43 - _22*_33*_41 - _23*_31*_42;
				float b42 = _11*_32*_43 + _12*_33*_41 + _13*_31*_42 - _11*_33*_42 - _12*_31*_43 - _13*_32*_41;
				float b43 = _11*_23*_42 + _12*_21*_43 + _13*_22*_41 - _11*_22*_43 - _12*_23*_41 - _13*_21*_42;
				float b44 = _11*_22*_33 + _12*_23*_31 + _13*_21*_32 - _11*_23*_32 - _12*_21*_33 - _13*_22*_31;

				inv = gsmatrix (b11*fdet, b12*fdet, b13*fdet, b14*fdet, b21*fdet, b22*fdet, b23*fdet, b24*fdet, 
					b31*fdet, b32*fdet, b33*fdet, b34*fdet, b41*fdet, b42*fdet, b43*fdet, b44*fdet);
			}
				
			return inv;
		}

		void rotX (const float fAngle)
		{
			identity ();

			float rads = (fAngle/180.f)*3.14159f;

			_22 = cosf (rads); _23 = -sinf (rads);
			_32 = sinf (rads); _33 = cosf (rads);
		}

		void rotY (const float fAngle)
		{
			identity ();

			float rads = (fAngle/180.f)*3.14159f;

			_11 = cosf (rads); _31 = sinf (rads);
			_31 = -sinf (rads); _33 = cosf (rads);
		}

		void rotZ (const float fAngle)
		{
			identity ();

			float rads = (fAngle/180.f)*3.14159f;

			_11 = cosf (rads); _12 = -sinf (rads);
			_21 = sinf (rads); _22 = cosf (rads);
		}

		void rot (const float &fx, const float &fy, const float &fz)
		{
			gsmatrix x, y, z;
			x.rotX (fx);
			y.rotY (fy);
			z.rotZ (fz);

			(*this) = x*y*z;
		}

		void scale (gsvec3f vScale)
		{
			gsmatrix temp;

			temp (1, 1) = vScale.getX ();
			temp (2, 2) = vScale.getY ();
			temp (3, 3) = vScale.getZ ();

			(*this) = (*this) * temp;
		}

		void scale (const float f)
		{
			gsmatrix temp;

			temp (1, 1) = f;
			temp (2, 2) = f;
			temp (3, 3) = f;

			(*this) = (*this) * temp;
		}

		void translate (gsvec3f vPos)
		{
			gsmatrix temp;

			temp._41 = vPos.getX ();
			temp._42 = vPos.getY ();
			temp._43 = vPos.getZ ();

			(*this) = (*this) * temp;
		}

		void transpose ()
		{
			float temp;

			temp = _21; _21 = _12; _12 = temp;

			temp = _31; _31 = _13; _13 = temp;
			temp = _32; _32 = _23; _23 = temp;

			temp = _41;	_41 = _14; _14 = temp;
			temp = _42;	_42 = _24; _24 = temp;
			temp = _43;	_43 = _34; _34 = temp;
		}

		/* overloaded operators */
		float &operator() (int i, int j)
		{
			switch (i)
			{
			case 0:
				switch (j) { case 0: return _11; case 1: return _12; case 2: return _13; case 3: return _14; }
			case 1:
				switch (j) { case 0: return _21; case 1: return _22; case 2: return _23; case 3: return _24; }
			case 2:
				switch (j) { case 0: return _31; case 1: return _32; case 2: return _33; case 3: return _34; }
			case 3:
				switch (j) { case 0: return _41; case 1: return _42; case 2: return _43; case 3: return _44; }
			}

			return _44;
		}
		const float &operator() (int i, int j) const
		{
			switch (i)
			{
			case 0:
				switch (j) { case 0: return _11; case 1: return _12; case 2: return _13; case 3: return _14; }
			case 1:
				switch (j) { case 0: return _21; case 1: return _22; case 2: return _23; case 3: return _24; }
			case 2:
				switch (j) { case 0: return _31; case 1: return _32; case 2: return _33; case 3: return _34; }
			case 3:
				switch (j) { case 0: return _41; case 1: return _42; case 2: return _43; case 3: return _44; }
			}

			return _44;
		}

		gsmatrix operator= (const gsmatrix &m)
		{
			_11 = m._11; _12 = m._12; _13 = m._13; _14 = m._14;
			_21 = m._21; _22 = m._22; _23 = m._23; _24 = m._24;
			_31 = m._31; _32 = m._32; _33 = m._33; _34 = m._34;
			_41 = m._41; _42 = m._42; _43 = m._43; _44 = m._44;

			return (*this);
		}

		inline friend gsmatrix operator+ (const gsmatrix &m1, const gsmatrix &m2)
		{
			gsmatrix t;

			t._11 = m1._11 + m2._11; t._12 = m1._12 + m2._12; t._13 = m1._13 + m2._13; t._14 = m1._14 + m2._14;
			t._21 = m1._21 + m2._21; t._22 = m1._22 + m2._22; t._23 = m1._23 + m2._23; t._24 = m1._24 + m2._24;
			t._31 = m1._31 + m2._31; t._32 = m1._23 + m2._32; t._33 = m1._33 + m2._33; t._34 = m1._34 + m2._34;
			t._41 = m1._41 + m2._41; t._42 = m1._24 + m2._42; t._43 = m1._43 + m2._43; t._44 = m1._44 + m2._44;

			return t;
		}

		inline friend gsmatrix operator- (const gsmatrix &m1, const gsmatrix &m2)
		{
			gsmatrix t;

			t._11 = m1._11 - m2._11; t._12 = m1._12 - m2._12; t._13 = m1._13 - m2._13; t._14 = m1._14 - m2._14;
			t._21 = m1._21 - m2._21; t._22 = m1._22 - m2._22; t._23 = m1._23 - m2._23; t._24 = m1._24 - m2._24;
			t._31 = m1._31 - m2._31; t._32 = m1._23 - m2._32; t._33 = m1._33 - m2._33; t._34 = m1._34 - m2._34;
			t._41 = m1._41 - m2._41; t._42 = m1._24 - m2._42; t._43 = m1._43 - m2._43; t._44 = m1._44 - m2._44;

			return t;
		}

		inline friend gsmatrix operator* (const gsmatrix &m1, const gsmatrix &m2)
		{
			gsmatrix t;

			t = gsmatrix (m1._11*m2._11 + m1._12*m2._21 + m1._13*m2._31 + m1._14*m2._41,
						  m1._11*m2._12 + m1._12*m2._22 + m1._13*m2._32 + m1._14*m2._42,
						  m1._11*m2._13 + m1._12*m2._23 + m1._13*m2._33 + m1._14*m2._43,
						  m1._11*m2._14 + m1._12*m2._24 + m1._13*m2._34 + m1._14*m2._44,
						  
						  m1._21*m2._11 + m1._22*m2._21 + m1._23*m2._31 + m1._24*m2._41,
						  m1._21*m2._12 + m1._22*m2._22 + m1._23*m2._32 + m1._24*m2._42,
						  m1._21*m2._13 + m1._22*m2._23 + m1._23*m2._33 + m1._24*m2._43,
						  m1._21*m2._14 + m1._22*m2._24 + m1._23*m2._34 + m1._24*m2._44,
						  
						  m1._31*m2._11 + m1._32*m2._21 + m1._33*m2._31 + m1._34*m2._41,
						  m1._31*m2._12 + m1._32*m2._22 + m1._33*m2._32 + m1._34*m2._42,
						  m1._31*m2._13 + m1._32*m2._23 + m1._33*m2._33 + m1._34*m2._43,
						  m1._31*m2._14 + m1._32*m2._24 + m1._33*m2._34 + m1._34*m2._44,
						  
						  m1._41*m2._11 + m1._42*m2._21 + m1._43*m2._31 + m1._44*m2._41,
						  m1._41*m2._12 + m1._42*m2._22 + m1._43*m2._32 + m1._44*m2._42,
						  m1._41*m2._13 + m1._42*m2._23 + m1._43*m2._33 + m1._44*m2._43,
						  m1._41*m2._14 + m1._42*m2._24 + m1._43*m2._34 + m1._44*m2._44);

			return t;
		}

		inline friend gsvec3f operator* (const gsmatrix &m, const gsvec3f &v)
		{
			gsvec3f t;

			t[0] = m._11*v[0] + m._12*v[1] + m._13*v[2] + m._41;
			t[1] = m._21*v[0] + m._22*v[1] + m._23*v[2] + m._42;
			t[2] = m._31*v[0] + m._32*v[1] + m._33*v[2] + m._43;
			//float w = m._41*v[0] + m._42*v[1] + m._43*v[2] + m._44*v[3];

			//making w 1!
			//if (w != 0)
			//{
			//	t[0] /= w;
			//	t[1] /= w;
			//	t[2] /= w;
			//}

			return t;
		}

		inline friend gsvec4f operator* (const gsmatrix &m, const gsvec4f &v)
		{
			gsvec4f t;

			t[0] = m._11*v[0] + m._12*v[1] + m._13*v[2] + m._14*v[3];
			t[1] = m._21*v[0] + m._22*v[1] + m._23*v[2] + m._24*v[3];
			t[2] = m._31*v[0] + m._32*v[1] + m._33*v[2] + m._34*v[3];
			t[3] = m._41*v[0] + m._42*v[1] + m._43*v[2] + m._44*v[3];

			return t;
		}

		inline friend gsvec3f operator* (const gsvec3f &v, const gsmatrix &m)
		{
			gsvec3f t;

			t[0] = m._11*v[0] + m._21*v[0] + m._31*v[0] + m._41*v[0];
			t[1] = m._12*v[1] + m._22*v[1] + m._32*v[1] + m._42*v[1];
			t[2] = m._13*v[2] + m._23*v[2] + m._33*v[2] + m._43*v[2];
			//float w = m._41*v[3] + m._42*v[3] + m._43*v[3] + m._44*v[3];

			return t;
		}

		inline friend gsvec4f operator* (const gsvec4f &v, const gsmatrix &m)
		{
			gsvec4f t;

			t[0] = m._11*v[0] + m._21*v[0] + m._31*v[0] + m._41*v[0];
			t[1] = m._12*v[1] + m._22*v[1] + m._32*v[1] + m._42*v[1];
			t[2] = m._13*v[2] + m._23*v[2] + m._33*v[2] + m._43*v[2];
			t[3] = m._14*v[3] + m._24*v[3] + m._43*v[3] + m._44*v[3];

			return t;
		}

		//friend matrix 

	private:
		float _11, _12, _13, _14,
			  _21, _22, _23, _24,
			  _31, _32, _33, _34,
			  _41, _42, _43, _44;
	};
};

#endif

