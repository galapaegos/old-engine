#include <gsscene/gsmaterialset.h>

namespace gsscene
{
	gsmaterialset::gsmaterialset (const gsgeom::gscolor &diffuse, const gsgeom::gscolor &spec, const gsgeom::gscolor &ambient, const gsgeom::gscolor &emissive, const unsigned int &power) : gsmaterial (diffuse, spec, ambient, emissive, power), m_pShader (NULL)
	{
	}

	gsmaterialset::~gsmaterialset ()
	{
	}

	void gsmaterialset::addTexture (const unsigned int &stage, gsimage::gstexture *image, gsgeom::gstextureinfo *texInfo)
	{
		TextureInfo ti;
		ti.m_iStage = stage;
		ti.m_pImage = image;
		ti.m_pTexInfo = texInfo;

		m_pTextures.add (ti);
	}

	void gsmaterialset::remTexture (const unsigned int &stage)
	{
		//gsAssert (0 <= stage <= maxTexUnits)

		for (unsigned int x = 0; x < m_vTexList.getSize (); x++)
		{
			if (x == stage)
			{
				m_vTexList.erase (x);
				break;
			}
		}
	}

	void gsmaterialset::addShader (gsgeom::gsshader *shader)
	{
		gsAssert (shader);

		m_pShader = shader;
	}

	void gsmaterialset::addVariable (gsgeom::gsshadervariable *var)
	{
		gsAssert (var);

		m_varList.add (var);
	}

	unsigned int gsmaterialset::getNumTextures ()
	{
		return m_pTextures.getSize ();
	}

	void gsmaterialset::getTexture (const int &index, int *stage, gsimage::gstexture *tex, gsgeom::gstextureinfo *texInfo)
	{
		gsAssert (index < 0 && index > m_pTextures.getSize ());

		*stage = m_pTextures[index].m_iStage;
		tex = m_pTextures[index].m_pImage;
		texInfo = m_pTextures[index].m_pTexInfo;
	}
};
