#ifndef _gsXMLElement_h_
#define _gsXMLElement_h_

#include "gsarray.h"
#include "gsqueue.h"
#include "gsstring.h"

namespace gsutil
{
	class GS gsXMLElement
	{
	public:
		gsXMLElement () //: m_Attributes (20), m_Children (20)
		{ 
			m_strNodeName = ""; 
			m_strValue = ""; 
		}
		~gsXMLElement () {}

		void setName (const gsstring &pName) 
		{
			m_strNodeName = pName; 
		}

		void setValue (const gsstring &pValue)
		{
			m_strValue = pValue; 
		}

		void addChild (gsXMLElement *pChild)
		{
			m_Children.add (pChild);
		}

		void addAttribute (gsXMLElement *pAttrib)
		{
			m_Attributes.add (pAttrib);
		}

		const gsstring &getName () { return m_strNodeName; }
		const gsstring &getValue () { return m_strValue; }

		unsigned int getChildrenSize () { return m_Children.getSize (); }
		gsXMLElement *getChild (const unsigned int &x) { return m_Children[x]; }

		unsigned int getAttributeSize () { return m_Attributes.getSize (); }
		gsXMLElement *getAttribute (const unsigned int &x) { return m_Attributes[x]; }

		gsstring getAttribute (const gsstring &pString)
		{
			for (unsigned int x = 0; x < m_Attributes.getSize (); x++)
			{
				if (pString == m_Attributes[x]->getName ())
					return m_Attributes[x]->getValue ();
			}

			return "";
		}

	private:
		//gsarray <gsXMLElement*> m_Attributes;
		gsqueue <gsXMLElement*> m_Attributes;
		//gsarray <gsXMLElement*> m_Children;
		gsqueue <gsXMLElement*> m_Children;

		gsstring m_strValue; //temp, want this to be XMLType instead,
							//or maybe its just fine, should probably leave the value as 
							//a string and convert accordingly
		gsstring m_strNodeName;
	};
};

#endif
