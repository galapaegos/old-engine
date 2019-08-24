#ifndef _gsrenderfeatures_h_
#define _gsrenderfeatures_h_

#include <gsutil/gsstring.h>

namespace gsgfx
{
	class gsrenderfeatures
	{
	public:
		gsrenderfeatures () {}
		~gsrenderfeatures () {}

		gsrenderfeatures operator= (const gsrenderfeatures &r)
		{
			m_strDriver = r.m_strDriver;
			bRenderTexture = r.bRenderTexture;

			return (*this);
		}

		gsutil::gsstring m_strDriver;

		bool bRenderTexture;
	};
};

#endif
