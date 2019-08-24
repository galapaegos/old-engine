#include <gsgeom/gsstate.h>

namespace gsgeom
{
	gsstate::gsstate ()
	{
		m_bLine = false;
		m_fLineWidth = 1.f;

		m_bCull = false;
		m_CullType = CULL_FRONT;

		m_bDepthTest = false;
		m_fDepthClear = 1.f;
		m_DepthFunc = DEPTH_LEQUAL;

		m_bAlphaTest = false;
		m_AlphaFunc = ALPHA_LEQUAL;
		m_fRefValue = 1.f;

		m_bStencilTest = false;
		m_StencilSeparate = STENCIL_FRONT_AND_BACK;
		m_StencilFuncFront = STENCIL_LEQUAL;
		m_StencilFuncBack = STENCIL_LEQUAL;
		m_StencilOpFront = STENCIL_KEEP;
		m_StencilOpBack = STENCIL_KEEP;

		m_bBlend = false;
		m_BlendEq = BLEND_FUNC_ADD;
		m_BlendColor = gsgeom::gscolor (0.f, 0.f, 0.f, 0.1f);
		m_AlphaFuncSrc = BLEND_SRC_ALPHA;
		m_AlphaFuncDst = BLEND_ONE_MINUS_SRC_ALPHA;
		m_ColorFuncSrc = BLEND_SRC_COLOR;
		m_ColorFuncDst = BLEND_DST_COLOR;
	}

	gsstate::~gsstate ()
	{
	}

	void gsstate::setLineSettings (const bool &line)
	{
		m_bLine = line;
	}

	bool gsstate::getLineSettings ()
	{
		return m_bLine;
	}

	void gsstate::setLineWidth (const float &width)
	{
		m_fLineWidth = width;
	}
	
	float gsstate::getLineWidth ()
	{
		return m_fLineWidth;
	}

	void gsstate::setLineStipple (const int &factor, const unsigned short &pattern)
	{
		m_iLineFactor = factor;
		m_usLinePattern = pattern;
	}

	int gsstate::getLineStippleFactor ()
	{
		return m_iLineFactor;
	}

	unsigned short gsstate::getLineStipplePattern ()
	{
		return m_usLinePattern;
	}

	void gsstate::setCulling (const bool &cull)
	{
		m_bCull = cull;
	}

	bool gsstate::getCulling ()
	{
		return m_bCull;
	}

	void gsstate::setCullFace (const CULL_TYPE &ct)
	{
		m_CullType = ct;
	}

	int gsstate::getCullFace ()
	{
		return m_CullType;
	}

	void gsstate::setDepthTest (const bool &depthTest)
	{
		m_bDepthTest = depthTest;
	}

	bool gsstate::getDepthTest ()
	{
		return m_bDepthTest;
	}

	void gsstate::setDepthValue (const float &clear)
	{
		m_fDepthClear = clear;
	}

	float gsstate::getDepthValue ()
	{
		return m_fDepthClear;
	}

	void gsstate::setDepthFunc (const DEPTH_FUNC &fc)
	{
		m_DepthFunc = fc;
	}

	int gsstate::getDepthFunc ()
	{
		return m_DepthFunc;
	}

	void gsstate::setAlphaTest (const bool &alphaTest)
	{
		m_bAlphaTest = alphaTest;
	}

	bool gsstate::getAlphaTest ()
	{
		return m_bAlphaTest;
	}

	void gsstate::setAlphaFunc (const ALPHA_FUNC &af, const float &ref)
	{
		m_AlphaFunc = af;
		m_fRefValue = ref;
	}

	int gsstate::getAlphaFunc ()
	{
		return m_AlphaFunc;
	}

	float gsstate::getAlphaFuncRef ()
	{
		return m_fRefValue;
	}

	void gsstate::setStencilTest (const bool &stencilTest)
	{
		m_bStencilTest = stencilTest;
		m_StencilSeparate = STENCIL_FRONT_AND_BACK;
	}

	void gsstate::setStencilTest (const STENCIL_SEPARATER &ss, const bool &stencilTest)
	{
		m_bStencilTest = stencilTest;
		m_StencilSeparate = ss;
	}

	bool gsstate::getStencilTest ()
	{
		return m_bStencilTest;
	}

	int gsstate::getStencilTestSeparate ()
	{
		return m_StencilSeparate;
	}

	void gsstate::setStencilFunc (const STENCIL_FUNC &sc)
	{
		m_StencilFuncFront = sc;
		m_StencilFuncBack = sc;
	}

	void gsstate::setStencilFunc (const STENCIL_SEPARATER &ss, const STENCIL_FUNC &sc)
	{
		if (ss == STENCIL_FRONT)
			m_StencilFuncFront = sc;
		if (ss == STENCIL_BACK)
			m_StencilFuncBack = sc;
	}

	int gsstate::getStencilFunc (const STENCIL_SEPARATER &ss)
	{
		switch (ss)
		{
		case STENCIL_FRONT:
			return m_StencilFuncFront;

		case STENCIL_BACK:
			return m_StencilFuncBack;
		
		default:
			return m_StencilFuncFront;
		}
	}
	
	void gsstate::setStencilOp (const STENCIL_OP &so)
	{
		m_StencilOpFront = so;
		m_StencilOpBack = so;
	}

	int gsstate::getStencilOp ()
	{
		return m_StencilOpFront;
	}
	
	void gsstate::setStencilOp (const STENCIL_SEPARATER &ss, const STENCIL_OP &so)
	{
		if (ss == STENCIL_FRONT)
			m_StencilOpFront = so;
		
		if (ss == STENCIL_BACK)
			m_StencilOpBack = so;
	}
	
	int gsstate::getStencilOp (const STENCIL_SEPARATER &ss)
	{
		if (ss == STENCIL_FRONT)
			return m_StencilOpFront;
		else
			return m_StencilOpBack;
	}

	void gsstate::setBlend (const bool &blend)
	{
		m_bBlend = blend;
	}

	bool gsstate::getBlend ()
	{
		return m_bBlend;
	}

	void gsstate::setBlendEquation (const BLEND_EQUATION &be)
	{
		m_BlendEq = be;
	}

	int gsstate::getBlendEquation ()
	{
		return m_BlendEq;
	}

	void gsstate::setBlendColor (const gsgeom::gscolor &c)
	{
		m_BlendColor = c;
	}

	void gsstate::setBlendFunc (const BLEND_POS &bp, const BLEND_TYPE &bt, const BLEND_FUNC &bf)
	{
		if (bp == BLEND_COLOR)
		{
			if (bt == BLEND_SRC)
				m_ColorFuncSrc = bf;
			if (bt == BLEND_DST)
				m_ColorFuncDst = bf;
		}
		if (bp == BLEND_ALPHA)
		{
			if (bt == BLEND_SRC)
				m_AlphaFuncSrc = bf;
			if (bt == BLEND_DST)
				m_AlphaFuncDst = bf;
		}
	}

	void gsstate::setBlendFunc (const BLEND_FUNC &src, const BLEND_FUNC &dest)
	{
		m_ColorFuncSrc = src;
		m_AlphaFuncSrc = src;
		m_ColorFuncDst = dest;
		m_AlphaFuncDst = dest;
	}
	
	void gsstate::setBlendFunc (const BLEND_FUNC &colorSrc, const BLEND_FUNC &colorDst, const BLEND_FUNC &alphaSrc, const BLEND_FUNC &alphaDst) 
	{
		m_ColorFuncSrc = colorSrc;
		m_AlphaFuncSrc = alphaSrc;
		m_ColorFuncDst = colorDst;
		m_AlphaFuncDst = alphaDst;
	}

	int gsstate::getBlendFunc (const BLEND_POS &bp, const BLEND_TYPE &bt) 
	{
		if (bp == BLEND_COLOR)
		{
			if (bt == BLEND_SRC)
				return m_ColorFuncSrc;
			else
				return m_ColorFuncDst;
		}
		else
		{
			if (bt == BLEND_SRC)
				return m_AlphaFuncSrc;
			else
				return m_AlphaFuncDst;
		}
	}
};
