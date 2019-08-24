#ifndef _gsstate_h_
#define _gsstate_h_

#include <gsgeom/gscolor.h>

namespace gsgeom
{
	class gsstate
	{
	public:
		gsstate ();
		~gsstate ();

		//line settings
		void setLineSettings (const bool &line);
		bool getLineSettings ();
		void setLineWidth (const float &width);
		float getLineWidth ();
		void setLineStipple (const int &factor, const unsigned short &pattern);
		int getLineStippleFactor ();
		unsigned short getLineStipplePattern ();

		//cull settings
		enum CULL_TYPE
		{
			CULL_FRONT,
			CULL_BACK,
			CULL_FRONT_AND_BACK
		};
		
		void setCulling (const bool &cull);
		bool getCulling ();
		void setCullFace (const CULL_TYPE &ct);
		int getCullFace ();

		//depth settings
		enum DEPTH_FUNC
		{
			DEPTH_NEVER,
			DEPTH_ALWAYS,
			DEPTH_LESS,
			DEPTH_LEQUAL,
			DEPTH_EQUAL,
			DEPTH_GEQUAL,
			DEPTH_GREATER,
			DEPTH_NOTEQUAL
		};
		
		void setDepthTest (const bool &depthTest);
		bool getDepthTest ();
		void setDepthValue (const float &clear);
		float getDepthValue ();
		void setDepthFunc (const DEPTH_FUNC &fc);
		int getDepthFunc ();

		//alpha test settings
		enum ALPHA_FUNC
		{
			ALPHA_NEVER,
			ALPHA_ALWAYS,
			ALPHA_LESS,
			ALPHA_LEQUAL,
			ALPHA_EQUAL,
			ALPHA_GEQUAL,
			ALPHA_GREATER,
			ALPHA_NOTEQUAL
		};
		
		void setAlphaTest (const bool &alphaTest);
		bool getAlphaTest ();
		void setAlphaFunc (const ALPHA_FUNC &af, const float &ref);
		int getAlphaFunc ();
		float getAlphaFuncRef ();

		//stencil settings
		enum STENCIL_SEPARATER
		{
			STENCIL_FRONT,
			STENCIL_BACK,
			STENCIL_FRONT_AND_BACK
		};
		
		enum STENCIL_FUNC
		{
			STENCIL_NEVER,
			STENCIL_ALWAYS,
			STENCIL_LESS,
			STENCIL_LEQUAL,
			STENCIL_EQUAL,
			STENCIL_GEQUAL,
			STENCIL_GREATER,
			STENCIL_NOTEQUAL
		};
		
		enum STENCIL_OP
		{
			STENCIL_KEEP,
			STENCIL_ZERO,
			STENCIL_REPLACE,
			STENCIL_INCR,
			STENCIL_DECR,
			STENCIL_INVERT,
			STENCIL_INCR_WRAP,
			STENCIL_DECR_WRAP
		};
		
		void setStencilTest (const bool &stencilTest);
		void setStencilTest (const STENCIL_SEPARATER &ss, const bool &stencilTest);
		bool getStencilTest ();
		int getStencilTestSeparate ();
		void setStencilFunc (const STENCIL_FUNC &sc);
		void setStencilFunc (const STENCIL_SEPARATER &ss, const STENCIL_FUNC &sc);
		int getStencilFunc (const STENCIL_SEPARATER &ss = STENCIL_FRONT_AND_BACK);
		void setStencilOp (const STENCIL_OP &so);
		int getStencilOp ();
		void setStencilOp (const STENCIL_SEPARATER &ss, const STENCIL_OP &so);
		int getStencilOp (const STENCIL_SEPARATER &ss);

		//blend settings
		enum BLEND_EQUATION
		{
			BLEND_FUNC_ADD,
			BLEND_FUNC_SUBTRACT,
			BLEND_FUNC_REVERSE_SUBTRACT,
			BLEND_MIN,
			BLEND_MAX
		};
		enum BLEND_FUNC
		{
			BLEND_ZERO,
			BLEND_ONE,
			BLEND_SRC_COLOR,
			BLEND_ONE_MINUS_SRC_COLOR,
			BLEND_DST_COLOR,
			BLEND_ONE_MINUS_DST_COLOR,
			BLEND_SRC_ALPHA,
			BLEND_ONE_MINUS_SRC_ALPHA,
			BLEND_DST_ALPHA,
			BLEND_ONE_MINUS_DST_ALPHA,
			BLEND_CONSTANT_COLOR,
			BLEND_ONE_MINUS_CONSTANT_COLOR,
			BLEND_CONSTANT_ALPHA,
			BLEND_ONE_MINUS_CONSTANT_ALPHA,
			BLEND_SRC_ALPHA_SATURATE
		};

		enum BLEND_TYPE
		{
			BLEND_SRC,
			BLEND_DST
		};
		
		enum BLEND_POS
		{
			BLEND_COLOR,
			BLEND_ALPHA
		};
		
		void setBlend (const bool &blend);
		bool getBlend ();
		void setBlendEquation (const BLEND_EQUATION &be);
		int getBlendEquation ();
		void setBlendColor (const gsgeom::gscolor &c);
		void setBlendFunc (const BLEND_POS &bp, const BLEND_TYPE &bt, const BLEND_FUNC &bf);
		void setBlendFunc (const BLEND_FUNC &src, const BLEND_FUNC &dest);
		void setBlendFunc (const BLEND_FUNC &colorSrc, const BLEND_FUNC &colorDst, const BLEND_FUNC &alphaSrc, const BLEND_FUNC &alphaDst);
		int getBlendFunc (const BLEND_POS &bp, const BLEND_TYPE &bt);

	private:
		bool m_bLine;
		float m_fLineWidth;
		int m_iLineFactor;
		unsigned short m_usLinePattern;

		bool m_bCull;
		CULL_TYPE m_CullType;

		bool m_bDepthTest;
		float m_fDepthClear;
		DEPTH_FUNC m_DepthFunc;

		bool m_bAlphaTest;
		ALPHA_FUNC m_AlphaFunc;
		float m_fRefValue;

		bool m_bStencilTest;
		STENCIL_SEPARATER m_StencilSeparate; //front, back, front & back
		STENCIL_FUNC m_StencilFuncFront, m_StencilFuncBack;
		STENCIL_OP m_StencilOpFront, m_StencilOpBack;

		bool m_bBlend;
		BLEND_EQUATION m_BlendEq;
		gsgeom::gscolor m_BlendColor;
		BLEND_FUNC m_AlphaFuncSrc, m_AlphaFuncDst;
		BLEND_FUNC m_ColorFuncSrc, m_ColorFuncDst;
	};
};

#endif
