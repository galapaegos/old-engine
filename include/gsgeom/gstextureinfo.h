#ifndef _gstextureinfo_h_
#define _gstextureinfo_h_

#include <gsgeom/gscolor.h>

#include <gsutil/gsarray.h>
#include <gsutil/gsstring.h>

namespace gsgeom
{
	class GS gstextureinfo
	{
		struct Texture_Arg
		{
			int m_iPname;
			int m_iParam;
			gsgeom::gscolor m_vColor;
			float m_fValue;
		};
	public:
		//multitexture modes
		enum TEXTURE_ENVIRONMENT
		{
			ENVIRONMENT_MODE,
			ENVIRONMENT_COLOR,
			ENVIRONMENT_COMBINE_RGB,
			ENVIRONMENT_COMBINE_ALPHA,

			MODE_REPLACE,
			MODE_MODULATE,
			MODE_DECAL,
			MODE_BLEND,
			MODE_ADD,
			MODE_COMBINE,
			MODE_ADDSIGNED,
			MODE_INTERPOLATE,
			MODE_SUBTRACT,
			MODE_DOT3RGB,
			MODE_DOT3RGBA,

			ARG_SOURCE0_RGB,
			ARG_SOURCE1_RGB,
			ARG_SOURCE2_RGB,
			ARG_SOURCE0_ALPHA,
			ARG_SOURCE1_ALPHA,
			ARG_SOURCE2_ALPHA,

			ARG_OPERAND0_RGB,
			ARG_OPERAND1_RGB,
			ARG_OPERAND2_RGB,
			ARG_OPERAND0_ALPHA,
			ARG_OPERAND1_ALPHA,
			ARG_OPERAND2_ALPHA,
			ARG_RGB_SCALE,
			ARG_ALPHA_SCALE,

			ARG_SRC_COLOR,
			ARG_ONE_MINUS_SRC_COLOR,
			ARG_SRC_ALPHA,
			ARG_ONE_MINUS_SRC_ALPHA,
			ARG_PRIMARY_COLOR,
			ARG_PREVIOUS,
			ARG_CONSTANT,
			ARG_TEXTURE,
			ARG_TEXTURE0,
			ARG_TEXTURE1,
			ARG_TEXTURE2,
			ARG_TEXTURE3,
			ARG_TEXTURE4,
			ARG_TEXTURE5,
			ARG_TEXTURE6,
			ARG_TEXTURE7,
		};

		gstextureinfo () {}
		~gstextureinfo () {}
		
		void add (const int &pname, const int &param)
		{
			Texture_Arg *ta = new Texture_Arg;
			ta->m_iParam = param;
			ta->m_iPname = pname;

			m_argList.add (ta);
		}

		void add (const int &pname, const gsgeom::gscolor &color)
		{
			Texture_Arg *ta = new Texture_Arg;
			ta->m_iPname = pname;
			ta->m_vColor = color;

			m_argList.add (ta);
		}

		void add (const int &pname, const float &scale)
		{
			Texture_Arg *ta = new Texture_Arg;
			ta->m_iPname = pname;
			ta->m_fValue = scale;

			m_argList.add (ta);
		}

		unsigned int getSize () { return m_argList.getSize (); }
		void getVariable (const int &index, int *pname, int *param)
		{
			if (index < 0 || index >= (int)m_argList.getSize ())
				return;

			*pname = m_argList[index]->m_iPname;
			*param = m_argList[index]->m_iParam;
		}

		void getVariable (const int &index, int *pname, gsgeom::gscolor *c)
		{
			if (index < 0 || index >= (int)m_argList.getSize ())
				return;

			*pname = m_argList[index]->m_iPname;
			*c = m_argList[index]->m_vColor;
		}

		void getVariable (const int &index, int *pname, float *scale)
		{
			if (index < 0 || index >= (int)m_argList.getSize ())
				return;

			*pname = m_argList[index]->m_iPname;
			*scale = m_argList[index]->m_fValue;
		}

	private:
		gsutil::gsqueue <Texture_Arg*> m_argList;
	};
};

#endif
