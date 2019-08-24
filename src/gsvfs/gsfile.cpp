#include <gsvfs/gsfile.h>

namespace gsvfs
{
	gsfile::gsfile () : m_pData (NULL), m_iSize (0)
	{
	}

	gsfile::gsfile (const gsutil::gsstring &pFile)
	{
		if (pFile.size () > 0)
		{
			FILE *f = fopen (pFile.str (), "r+b");
			if (f)
			{
				fseek (f, 0, SEEK_END);
				int size = ftell (f);
				fseek (f, 0, SEEK_SET);

				m_pData = new unsigned char[size + 1];
				fread (m_pData, size, 1, f);

				fclose (f);

				m_strFileName = pFile;
				m_iSize = size;
			}
		}
	}

	gsfile::~gsfile ()
	{
		if (m_pData != NULL)
			delete [] m_pData;
	}
};

