#include <gsgeom/gsshader.h>

namespace gsgeom
{
	gsshader::gsshader ()
	{
		m_iId = -1;
	}

	gsshader::~gsshader ()
	{
	}

	void gsshader::load (const gsutil::gsstring &pVertex, const gsutil::gsstring &pFragment)
	{
		FILE *ffrag = fopen (pFragment.str (), "r+b");
		if (ffrag)
		{
			fseek (ffrag, 0, SEEK_END);
			int size = ftell (ffrag);
			fseek (ffrag, 0, SEEK_SET);
			char *tmp = new char[size+1];
			fread (tmp, size, 1, ffrag);
			tmp[size] = '\0';
			fclose (ffrag);

			m_pFragmentBody = tmp;
			delete [] tmp;
		}

		FILE *fvert = fopen (pVertex.str (), "r+b");
		if (fvert)
		{
			fseek (fvert, 0, SEEK_END);
			int size = ftell (fvert);
			fseek (fvert, 0, SEEK_SET);
			char *tmp = new char[size+1];
			fread (tmp, size, 1, fvert);
			tmp[size] = '\0';
			fclose (fvert);

			m_pVertexBody = tmp;
			delete [] tmp;
		}
	}

	void gsshader::unload ()
	{
	}
}

