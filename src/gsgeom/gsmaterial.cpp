#include <gsgeom/gsmaterial.h>

namespace gsgeom
{
	gsmaterial::gsmaterial (const gsgeom::gscolor &diffuse, const gsgeom::gscolor &spec, const gsgeom::gscolor &ambient, const gsgeom::gscolor &emissive, const unsigned int &power) : m_Diffuse (diffuse), m_Specular (spec), m_Ambient (ambient), m_Emissive (emissive), m_Power (power)
	{
	}
	
	gsmaterial::~gsmaterial ()
	{
	}

	gsgeom::gscolor gsmaterial::getAmbient () const
	{
		return m_Ambient;
	}

	gsgeom::gscolor gsmaterial::getDiffuse () const
	{
		return m_Diffuse;
	}

	gsgeom::gscolor gsmaterial::getEmissive () const
	{
		return m_Emissive;
	}

	unsigned int gsmaterial::getPower () const
	{
		return m_Power;
	}

	gsgeom::gscolor gsmaterial::getSpecular () const
	{
		return m_Specular;
	}

	void gsmaterial::setAmbient (const gsgeom::gscolor &ambient)
	{
		m_Ambient = ambient;
	}

	void gsmaterial::setDiffuse (const gsgeom::gscolor &diffuse)
	{
		m_Diffuse = diffuse;
	}

	void gsmaterial::setEmissive (const gsgeom::gscolor &emissive)
	{
		m_Emissive = emissive;
	}

	void gsmaterial::setPower (const unsigned int &power)
	{
		m_Power = power;
	}

	void gsmaterial::setSpecular (const gsgeom::gscolor &spec)
	{
		m_Specular = spec;
	}
};
