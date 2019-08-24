#ifndef _gsshadervariable_h_
#define _gsshadervariable_h_

#include <gsutil/gsstring.h>

namespace gsgeom
{
	class GS gsshadervariable
	{
	public:
		gsshadervariable ();
		gsshadervariable (const gsutil::gsstring &pname, const gsutil::gsstring &ptype, const gsutil::gsstring &pval);
		~gsshadervariable ();

		void setName (const gsutil::gsstring &pname) { m_strName = pname; }
		void setType (const gsutil::gsstring &ptype) { m_strType = ptype; }
		void setValue (const gsutil::gsstring &pval) { m_strValue = pval; }

		gsutil::gsstring getName () { return m_strName; }
		gsutil::gsstring getType () { return m_strType; }
		gsutil::gsstring getValue () { return m_strValue; }

		unsigned int getId () { return m_iId; }
		void setId (const unsigned int &id) { m_iId = id; }

	private:
		gsutil::gsstring m_strName, m_strType, m_strValue;
		unsigned int m_iId;
	};
};

#endif
