#ifndef _gsscriptobjecttoken_h_
#define _gsscriptobjecttoken_h_

#include <gsutil/gsqueue.h>
#include <gsutil/gsstring.h>

namespace gsscr
{
	class gsscriptobjecttoken
	{
	public:
		gsscriptobjecttoken () : m_tokenValue (""), m_tokenType ("") {}
		gsscriptobjecttoken (const gsutil::gsstring &str, const gsutil::gsstring &type="string") : m_tokenValue (str), m_tokenType (type) {}
		virtual ~gsscriptobjecttoken () {}

		gsutil::gsstring &getType () { return m_tokenType; }

		void setValue (const gsutil::gsstring &str, const gsutil::gsstring &type="string") { m_tokenValue = str; m_tokenType = type; }
		gsutil::gsstring &getValue () { return m_tokenValue; }

	private:
		gsutil::gsstring m_tokenType, m_tokenValue;
	};
};

#endif
