#include "gsutil/gsXMLParser.h"

namespace gsutil
{
	gsXMLParser::gsXMLParser ()
	{
		m_pDocument = new gsXMLDocument ();
	}

	gsXMLParser::~gsXMLParser ()
	{
		delete m_pDocument;
	}

	void gsXMLParser::loadFile (const gsstring &pFile)
	{
		FILE *f = fopen (pFile.str (), "r+b");

		if (!f)
			return;

		fseek (f, 0, SEEK_END);
		int len = ftell (f);
		rewind (f);

		char *pf = new char [len+1];
		memset (pf, 0, len);
		fread (pf, len, 1, f);
		pf[len] = '\0';

		gsstring wholeFile = pf;
		delete [] pf;

		while (wholeFile.size () > 0)
		{
			int npos = wholeFile.find ('\n');
			gsstring s;
			if (npos == -1)
			{
				s = wholeFile.substring (0, wholeFile.size ());
				wholeFile.clear ();
			}
			else
			{
				s = wholeFile.substring (0, npos + 1);
				wholeFile.remove (s);
			}
			m_List.add (s);
		}

		parse (m_pDocument->getRoot ());
	}

	void gsXMLParser::saveFile (const gsstring &pFile)
	{
		FILE *f = fopen (pFile.str (), "w+");

		if (!f)
			return;

		gsutil::gsqueue<gsstring> list;

		//generate property crap, that stupid '<?xml...' line
		for (unsigned int y = 0; y < m_pDocument->getPropertySize (); y++)
		{
			gsXMLElement *e = m_pDocument->getProperty (y);
			gsstring temp = "<" + e->getName ();
			for (unsigned int z = 0; z < e->getAttributeSize (); z++)
			{
				gsXMLElement *c = e->getAttribute (z);
				temp += " " + c->getName () + "=" + "\"" + c->getValue () + "\"";
			}
			temp += "?>\n";
			list.add (temp);
		}

		//generate strings to write
		writeHelper (getRoot (), list);

		//write file
		for (unsigned int x = 0; x < list.getSize (); x++)
			fwrite (list[x].str (), list[x].size (), 1, f);

		fclose (f);
	}

	void gsXMLParser::writeHelper (gsXMLElement *e, gsqueue <gsstring> &list, const int &tabs)
	{
		gsstring temp;
		for (int t = 0; t < tabs; t++)
			temp += "\t";
		temp += "<" + e->getName ();

		for (unsigned int x = 0; x < e->getAttributeSize (); x++)
		{
			gsXMLElement *attr = e->getAttribute (x);
			temp += " ";
			temp += attr->getName ();
			temp += "=";
			temp += "\"";
			temp += attr->getValue ();
			temp += "\"";
		}

		if (e->getChildrenSize () > 0)
		{
			temp += ">\n";
			list.add (temp);

			for (unsigned int c = 0; c < e->getChildrenSize (); c++)
				writeHelper (e->getChild (c), list, tabs+1);

			temp.clear ();
			for (int t = 0; t < tabs; t++)
				temp += "\t";
			temp += "</" + e->getName () + ">\n";
			list.add (temp);
		}
		else
		{
			if (e->getValue () == "")
			{
				temp += " />\n";
			}
			else
			{
				temp += ">";
				temp += e->getValue ();
				temp += "</" + e->getName () + ">\n";
			}

			list.add (temp);
		}
	}

	const gsstring gsXMLParser::find (const gsstring &path)
	{
		gsstring temp = path;
		
		temp.remove (0, 1);

		if (temp == getRoot ()->getName ())
			return getRoot ()->getValue ();

		int in = temp.find ("/");
		if (in != -1)
			temp.remove (0, in);

		for (unsigned int x = 0; x < getRoot ()->getChildrenSize (); x++)
		{
			gsstring ret = findHelper (getRoot ()->getChild (x), temp);
			if (ret != "")
				return ret;
		}

		return "";
	}

	const gsstring gsXMLParser::findHelper (gsXMLElement *pNode, const gsstring &path)
	{
		gsstring temp = path;

		//first character should be a '/'
		if (temp[0] == '/')
			temp.remove (0, 1);
		
		//element name
		int in = temp.find ("/");

		if (in == -1)
		{
			if (temp == pNode->getName ())
				return pNode->getValue ();
		}

		gsstring elementName = temp.substring (0, in);
		temp.remove  (0, in);

		if (temp.size () < 1)
		{
			temp = "";
			return temp;
		}

		for (unsigned int x = 0; x < pNode->getChildrenSize (); x++)
		{
			if (pNode->getName () == elementName)
				return findHelper (pNode->getChild (x), temp);
		}

		temp = "";
		return temp;
	}

	gsXMLElement *gsXMLParser::findElement (const gsstring &path)
	{
		gsstring temp = path;
		
		temp.remove (0, 1);

		if (temp == getRoot ()->getName ())
			return getRoot ();

		int in = temp.find ("/");
		if (in != -1)
			temp.remove (0, in);

		for (unsigned int x = 0; x < getRoot ()->getChildrenSize (); x++)
		{
			gsutil::gsXMLElement *ret = findElementHelper (getRoot ()->getChild (x), temp);
			if (ret)
				return ret;
		}
		
		return NULL;
	}

	gsXMLElement *gsXMLParser::findElementHelper (gsXMLElement *pNode, const gsstring &path)
	{
		gsstring temp = path;

		//first character should be a '/'
		if (temp[0] == '/')
			temp.remove (0, 1);
		
		//element name
		int in = temp.find ("/");

		if (in == -1)
		{
			if (temp == pNode->getName ())
				return pNode;
		}

		gsstring elementName = temp.substring (0, in);
		temp.remove  (0, in);

		//if (temp.size () < 1)
		//	return NULL;

		for (unsigned int x = 0; x < pNode->getChildrenSize (); x++)
		{
			if (pNode->getName () == elementName)
				return findElementHelper (pNode->getChild (x), temp);
		}

		return NULL;
	}

	void gsXMLParser::print (int iSpaces)
	{
		for (unsigned int y = 0; y < m_pDocument->getPropertySize (); y++)
		{
			gsXMLElement *e = m_pDocument->getProperty (y);
			//printf ("Property:%s  Value:%s\n", e->getName ().str (), e->getValue ().str ());

			printHelper (iSpaces + 1, e);
		}

		printHelper (iSpaces, m_pDocument->getRoot ());
	}

	void gsXMLParser::printHelper (int iSpaces, gsXMLElement *pNode)
	{
		for (int j = 0; j < iSpaces; j++)
			printf (" ");

		printf ("Node: %s\n", pNode->getName ().str ());

		for (int k = 0; k < iSpaces; k++)
			printf (" ");

		printf ("Value: %s\n", pNode->getValue ().str ());
		
		for (unsigned int a = 0; a < pNode->getAttributeSize (); a++)
		{
			for (int j = 0; j < iSpaces; j++)
				printf (" ");

			gsXMLElement *attr = pNode->getAttribute (a);

			printf ("Attribute:%s  Value:%s\n", attr->getName ().str (), attr->getValue ().str ());
		}

		for (unsigned int x = 0; x < pNode->getChildrenSize (); x++)
			printHelper (iSpaces + 1, pNode->getChild (x));
	}

	void gsXMLParser::parse (gsXMLElement *pNode)
	{
		strip ();

		gsstring s = m_List[0];

		int o = s.find ('<');
		int c = s.find ('>');

		//parse error
		if (o > c)
			return;

		gsstring nodeName = s.substring (o, c+1);

		if (nodeName[1] == '?')
		{
			gsXMLElement *property = new gsXMLElement;

			extractName (property, nodeName);

			m_pDocument->addProperty (property);

			m_List.erase (0);

			parse (pNode);
		}
		else if (nodeName.find ('/') > -1)
		{
			// for <test />
			extractName (pNode, nodeName);
		}
		else
		{
			extractName (pNode, nodeName);
			m_List[0].remove (nodeName);

			//nodeName.remove ("<");
			//nodeName.remove (">");
			nodeName = pNode->getName ();

			//do a lookup to see if the next node is this nodeName
			//if it is not, we need to continue to parse until it comes back up here

			//issue with removing value from same line tags: ex '<node>test</node>'

			bool onSameLine = false;

			//check and see if we have another tag on this line
			s = m_List[0];
			if ((s.find ('<') == -1) && (s.find ('>') == -1))
				m_List.erase (0);
			else
				onSameLine = true;

			strip ();
			s = m_List[0];

			int l = s.find ('<');
			int g = s.find ('>');

			gsstring possibleEndNode = s.substring (l, g - l + 1);
			s.remove (possibleEndNode);
			possibleEndNode.remove ("<");
			possibleEndNode.remove (">");
			possibleEndNode.remove ("/");

			while (possibleEndNode != nodeName)
			{
				gsXMLElement *pChild = new gsXMLElement;

				parse (pChild);
				pNode->addChild (pChild);

				m_List.erase (0);

				strip ();

				gsstring s = m_List[0];
				int l = s.find ('<');
				int g = s.find ('>');

				possibleEndNode = s.substring (l, g+1);
				possibleEndNode.remove ("<");
				possibleEndNode.remove (">");
				possibleEndNode.remove ("/");
			}

			if (onSameLine)
			{
				gsstring val;
				val = s.substring (0, l);
				pNode->setValue (val);
			}
		}
	}

	void gsXMLParser::strip ()
	{
		gsstring s = m_List[0];
		while ((s.size () > 0) && ((s[0] == ' ') || (s[0] == '\t') || (s[0] == '\n')))
		{
			if (m_List[0] == '\n')
				m_List.erase (0);
			else
				m_List[0].remove (0);
			s = m_List[0];
		}
	}

	void gsXMLParser::extractName (gsXMLElement *pNode, const gsstring &pString)
	{
		gsstring temp = pString;

		if (temp[0] == '?')
			temp.remove (0);

		int sp = temp.find (' ');
		int ca = temp.find ('>');

		// syntax error, means we dont' have an end '>'
		if (ca == -1)
			return;

		// node has attributes we need to extract
		if ((sp < ca) && (sp > 0))
		{
			//remove the '<' '>' tags, and thats our name
			temp.remove (0);

			gsstring n = temp.substring (0, sp-1);
			temp.remove (0, sp);

			pNode->setName (n);
		}
		else
		{
			//remove the '<' '>' tags, and thats our name
			temp.remove (0);
			temp.remove (temp.size () - 1);

			pNode->setName (temp);
		}

		//attributes
		while (temp.size () > 0)
		{
			while (temp[0] == ' ')
				temp.remove (0);

			int eq = temp.find ('=');
			if (eq == -1)
				break;

			gsstring attrName, attrValue;
			attrName = temp.substring (0, eq);
			//remove the name, equal sign, and the first "
			temp.remove (0, eq+2);

			int dq = temp.find ('"');
			attrValue = temp.substring (0, dq);
			temp.remove (0, dq+1);

			gsXMLElement *p = new gsXMLElement;
			p->setName (attrName);
			p->setValue (attrValue);

			pNode->addAttribute (p);
		}
	}
}
