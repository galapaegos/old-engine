#ifndef _gsXMLDocument_h_
#define _gsXMLDocument_h_

#include "gsXMLElement.h"

namespace gsutil
{
	class GS gsXMLDocument
	{
	public:
		gsXMLDocument () { m_pRoot = new gsXMLElement (); }
		~gsXMLDocument () { if (m_pRoot != NULL) delete m_pRoot; }

		gsXMLElement *getRoot () { return m_pRoot; }
		gsXMLElement *getProperty (const int &x) { return m_pXMLProperties[x]; }

		unsigned int getPropertySize () { return m_pXMLProperties.getSize (); }

		void addProperty (gsXMLElement *pProperty) { m_pXMLProperties.add (pProperty); }

	private:
		gsXMLElement *m_pRoot;
		gsqueue<gsXMLElement*> m_pXMLProperties;
	};
};

#endif
