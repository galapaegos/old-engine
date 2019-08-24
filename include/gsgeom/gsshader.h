#ifndef _gsshader_h_
#define _gsshader_h_

#include <gsutil/gsqueue.h>
#include <gsutil/gsstring.h>

namespace gsgeom
{
	class GS gsshader
	{
	public:
		gsshader ();
		~gsshader ();

		void load (const gsutil::gsstring &pVertex, const gsutil::gsstring &pFragment);
		void unload ();

		gsutil::gsstring &getFragmentProgram () { return m_pFragmentBody; }
		gsutil::gsstring &getVertexProgram () { return m_pVertexBody; }

		int getId () { return m_iId; }
		void setId (const int id) { m_iId = id; }

	private:
		gsutil::gsstring m_pVertexBody, m_strVertex, m_pFragmentBody, m_strFragment;
		int m_iId;
	};
};

#endif
