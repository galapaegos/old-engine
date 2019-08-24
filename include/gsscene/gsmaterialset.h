#ifndef _gsmaterialset_h_
#define _gsmaterialset_h_

#include <gsgeom/gsmaterial.h>
#include <gsgeom/gstextureinfo.h>

#include <gsgfx/gsrenderer.h>

namespace gsscene
{
	class GS gsmaterialset : public gsgeom::gsmaterial
	{
	public:
		gsmaterialset (const gsgeom::gscolor &diffuse=gsgeom::gscolor (0.5f, 0.5f, 0.5f, 1.f), 
					const gsgeom::gscolor &spec=gsgeom::gscolor (1.f, 1.f, 1.f, 1.f), 
					const gsgeom::gscolor &ambient=gsgeom::gscolor (0.3f, 0.3f, 0.3f, 1.f), 
					const gsgeom::gscolor &emissive=gsgeom::gscolor (1.f, 1.f, 1.f, 1.f), 
					const unsigned int &power=1);
		virtual ~gsmaterialset ();

		void addTexture (const unsigned int &stage, gsimage::gstexture *image, gsgeom::gstextureinfo *texInfo=0);
		void remTexture (const unsigned int &stage);

		void addShader (gsgeom::gsshader *shader);
		void addVariable (gsgeom::gsshadervariable *var);

		unsigned int getNumTextures ();
		void getTexture (const int &index, int *stage, gsimage::gstexture *tex, gsgeom::gstextureinfo *texInfo);

	protected:
		gsgeom::gsshader *m_pShader;
		gsutil::gsqueue <gsgeom::gsshadervariable*> m_varList;

		typedef struct
		{
			gsimage::gstexture *m_pImage;
			gsgeom::gstextureinfo *m_pTexInfo;
			unsigned int m_iStage;
		} TextureInfo;
		gsutil::gsqueue <TextureInfo> m_pTextures;
	};
};

#endif
