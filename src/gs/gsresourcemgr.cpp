#include <gs/gsresourcemgr.h>

namespace gs
{
	gsresourcemgr::gsresourcemgr ()
	{
		m_iResource = 0;
	}

	gsresourcemgr::~gsresourcemgr ()
	{
	}

	int gsresourcemgr::load (const gsutil::gsstring &pstr)
	{
		gsstring temp = pstr;
		// file has no extension
		if (temp.find (".") == -1)
			return -1;

		temp.remove (0, temp.find (".")+1);

		//Add all the texture extensions here!!!
		if (temp == "bmp")
		{
			gsimage::gstexture *pTexture;
			pTexture = new gsimage::gsbmp;

			pTexture->load (pstr);
			//pTexture->setResourceId (m_iResource);

			m_pTextures.add (pTexture);
		}
		else if (temp == "jpg")
		{
			//gsimage::gstexture *pTexture;
			//pTexture = new gsimage::gsjpeg;

			//pTexture->load (pstr);
			//pTexture->setResourceId (m_iResource);

			//m_pTextures.add (pTexture);
		}
		else if (temp == "png")
		{
			gsimage::gstexture *pTexture;
			pTexture = new gsimage::gspng;

			pTexture->load (pstr);
			//pTexture->setResourceId (m_iResource);

			m_pTextures.add (pTexture);
		}
		else if (temp == "ppm")
		{
			gsimage::gstexture *pTexture;
			pTexture = new gsimage::gsppm;

			pTexture->load (pstr);
			//pTexture->setResourceId (m_iResource);

			m_pTextures.add (pTexture);
		}
		else if (temp == "scene")
		{
			//gsgeom::gsscene *s = gssceneloader::read (pstr);

			//m_pScenes.add (s);
		}
		else
			return -1;

		int indx = m_iResource;
		m_iResource++;

		return indx;
	}

	void gsresourcemgr::load (const gsutil::gsstring &path, const gsutil::gsstring &file)
	{
	}

	void gsresourcemgr::unload (const int resource)
	{
		//removes texture resource
		for (unsigned int x = 0; x < m_pTextures.getSize (); x++)
		{
			//if (m_pTextures[x]->getId () == resource)
			//{
			//	delete m_pTextures[x];
			//	m_pTextures.erase (x);
			//	return;
			//}
		}

		//need to remove a scene here
	}

	int gsresourcemgr::findTextureResource (const gsutil::gsstring &file)
	{
		for (unsigned int x = 0; x < m_pTextures.getSize (); x++)
		{
			if (m_pTextures[x]->getName () == file)
				return x;
		}

		return -1;
	}
};
