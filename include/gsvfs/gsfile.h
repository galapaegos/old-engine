#ifndef _gsfile_h_
#define _gsfile_h_

#include <gsutil/gsstring.h>
#include <gsutil/gsqueue.h>

namespace gsvfs
{
	class GS gsfile
	{
	public:
		gsfile ();
		gsfile (const gsutil::gsstring &pFile);
		~gsfile ();

		gsutil::gsstring getFileName () { return m_strFileName; }
		unsigned int getSize () { return m_iSize; }
		unsigned char *getData () { return m_pData; }

		void setFileName (const gsutil::gsstring &file) { m_strFileName = file; }
		void setData (unsigned char *pData) { m_pData = pData; }
		void setSize (const int &size) { m_iSize = size; }

	private:
		unsigned char *m_pData;
		gsutil::gsstring m_strFileName;

		unsigned int m_iSize;
	};
};

#endif

