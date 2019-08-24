#ifndef _gsXMLParser_h_
#define _gsXMLParser_h_

#include <iostream>
#include <fstream>
#include <math.h>
#include "gslogger.h"

#include "gsXMLElement.h"
#include "gsXMLDocument.h"

namespace gsutil
{
	class GS gsXMLParser
	{
	public:
		gsXMLParser ();
		~gsXMLParser ();

		void loadFile (const gsstring &pFile);
		void saveFile (const gsstring &pFile);

		void parse (gsXMLElement *pNode);

		void print (int iSpaces=0);

		const gsstring find (const gsstring &path);
		gsXMLElement *findElement (const gsstring &path);

		gsXMLElement *getRoot () { return m_pDocument->getRoot (); }
		gsXMLDocument *getDocument () { return m_pDocument; }

	protected:
		void extractName (gsXMLElement *pNode, const gsstring &pString);

		void strip ();

		void printHelper (int iSpaces, gsXMLElement *pNode);
		const gsstring findHelper (gsXMLElement *pNode, const gsstring &path);
		gsXMLElement *findElementHelper (gsXMLElement *pNode, const gsstring &path);

		void writeHelper (gsXMLElement *e, gsqueue<gsstring> &list, const int &tabs=0);

	private:
		gsXMLDocument *m_pDocument;

		gsutil::gsqueue<gsutil::gsstring> m_List;
	};
};

#endif
