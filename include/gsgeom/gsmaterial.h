#ifndef _gsmaterial_h_
#define _gsmaterial_h_

#include <gsgeom/gscolor.h>
#include <gsimage/gstexture.h>

namespace gsgeom
{
	class GS gsmaterial
	{
	public:
		gsmaterial (const gsgeom::gscolor &diffuse=gsgeom::gscolor (0.8f, 0.8f, 0.8f, 1.f), 
					const gsgeom::gscolor &spec=gsgeom::gscolor (0.f, 0.f, 0.f, 1.f), 
					const gsgeom::gscolor &ambient=gsgeom::gscolor (0.2f, 0.2f, 0.2f, 1.f), 
					const gsgeom::gscolor &emissive=gsgeom::gscolor (0.f, 0.f, 0.f, 1.f), 
					const unsigned int &power=0);
		~gsmaterial ();

		gsgeom::gscolor getAmbient () const;
		gsgeom::gscolor getDiffuse () const;
		gsgeom::gscolor getEmissive () const;
		unsigned int getPower () const;
		gsgeom::gscolor getSpecular () const;

		void setAmbient (const gsgeom::gscolor &ambient);
		void setDiffuse (const gsgeom::gscolor &diffuse);
		void setEmissive (const gsgeom::gscolor &emissive);
		void setPower (const unsigned int &power);
		void setSpecular (const gsgeom::gscolor &spec);

		//void setDiffuse (const gsimage::gstexture *m_pTexture, const int &state=0);

	protected:
		gsgeom::gscolor m_Diffuse, m_Specular, m_Ambient, m_Emissive;
		unsigned int m_Power;

		typedef struct
		{
			gsimage::gstexture *m_pTexture;
			unsigned char m_iStage;
		} TexInfo;

		gsutil::gsqueue <TexInfo> m_TexList;
	};
};

#endif
