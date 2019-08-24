#include "ModelEditorConfig.h"

ModelEditorConfig::ModelEditorConfig (const gsutil::gsstring &pConfig)
{
	m_pParser = new gsutil::gsXMLParser;
	m_strConfig = pConfig;

	m_pKernel = NULL;
	m_pCurrentScene = NULL;
	m_pMainWindow = NULL;
	m_pMainCamera = NULL;

	desktopWidth = GetSystemMetrics (SM_CXSCREEN);
	desktopHeight = GetSystemMetrics (SM_CYSCREEN);

	Index.set (-1, -1, -1);
}

ModelEditorConfig::~ModelEditorConfig ()
{
}

void ModelEditorConfig::loadConfig ()
{
	m_pParser->loadFile (m_strConfig);

	gsutil::gsXMLElement *root = m_pParser->getRoot ();
	if (!root)
		return;

	if (root->getName () == "Config")
	{
		for (unsigned int x = 0; x < root->getChildrenSize (); x++)
		{
			gsutil::gsXMLElement *c = root->getChild (x);
			if (c->getName () == "Windows")
			{
				for (unsigned int y = 0; y < c->getChildrenSize (); y++)
				{
					gsutil::gsXMLElement *d = c->getChild (y);

					WindowConfig *wc = new WindowConfig;

					
					for (unsigned int z = 0; z < d->getAttributeSize (); z++)
					{
						gsutil::gsXMLElement *attr = d->getAttribute (z);

						if (attr->getName () == "x")
							wc->x = atoi (attr->getValue ().str ());

						if (attr->getName () == "y")
							wc->y = atoi (attr->getValue ().str ());

						if (attr->getName () == "w")
							wc->w = atoi (attr->getValue ().str ());

						if (attr->getName () == "h")
							wc->h = atoi (attr->getValue ().str ());
					}

					wc->winName = d->getName ();

					m_Config.add (wc);
				}
			}
		}
	}
}

void ModelEditorConfig::saveConfig ()
{
	//update DOM xml sections
	gsutil::gsXMLElement *root = m_pParser->getRoot ();
	if (root->getChildrenSize () == 0)
	{
		//generating xml file
		gsutil::gsXMLDocument *pDoc = m_pParser->getDocument ();
		root->setName ("Config");

		gsutil::gsXMLElement *header = new gsutil::gsXMLElement;
		header->setName ("?xml");
		pDoc->addProperty (header);

		gsutil::gsXMLElement *ver = new gsutil::gsXMLElement;
		ver->setName ("version");
		ver->setValue ("1.0");
		header->addAttribute (ver);

		gsutil::gsXMLElement *enc = new gsutil::gsXMLElement;
		enc->setName ("encoding");
		enc->setValue ("ISO-8859-1");
		header->addAttribute (enc);

		gsutil::gsXMLElement *windows = new gsutil::gsXMLElement;
		windows->setName ("Windows");

		root->addChild (windows);
	}

	if (root->getName () == "Config")
	{
		for (unsigned int x = 0; x < root->getChildrenSize (); x++)
		{
			gsutil::gsXMLElement *c = root->getChild (x);
			if (c->getName () == "Windows")
			{
				for (unsigned int y = 0; y < m_Config.getSize (); y++)
				{
					WindowConfig *wc = m_Config[y];

					bool update = false;
					for (unsigned int z = 0; z < c->getChildrenSize (); z++)
					{
						gsutil::gsXMLElement *d = c->getChild (z);

						if (d->getName () == wc->winName)
						{
							for (unsigned int zz = 0; zz < d->getAttributeSize (); zz++)
							{
								gsutil::gsXMLElement *e = d->getAttribute (zz);
								if (e->getName () == "x")
									e->setValue (gsutil::gsstring (wc->x));

								if (e->getName () == "y")
									e->setValue (gsutil::gsstring (wc->y));

								if (e->getName () == "w")
									e->setValue (gsutil::gsstring (wc->w));

								if (e->getName () == "h")
									e->setValue (gsutil::gsstring (wc->h));
							}

							update = true;
						}
					}

					if (!update)
					{
						gsutil::gsXMLElement *child = new gsutil::gsXMLElement;
						child->setName (wc->winName);

						gsutil::gsXMLElement *xAttr = new gsutil::gsXMLElement;
						xAttr->setName ("x");
						xAttr->setValue (gsutil::gsstring (wc->x));
						child->addAttribute (xAttr);

						gsutil::gsXMLElement *yAttr = new gsutil::gsXMLElement;
						yAttr->setName ("y");
						yAttr->setValue (gsutil::gsstring (wc->y));
						child->addAttribute (yAttr);

						gsutil::gsXMLElement *wAttr = new gsutil::gsXMLElement;
						wAttr->setName ("w");
						wAttr->setValue (gsutil::gsstring (wc->w));
						child->addAttribute (wAttr);

						gsutil::gsXMLElement *hAttr = new gsutil::gsXMLElement;
						hAttr->setName ("h");
						hAttr->setValue (gsutil::gsstring (wc->h));
						child->addAttribute (hAttr);

						c->addChild (child);
					}
				}
			}
		}
	}

	m_pParser->saveFile (m_strConfig);
}

ModelEditorConfig::WindowConfig *ModelEditorConfig::getWindow (const gsutil::gsstring &windowName)
{
	for (unsigned int x = 0; x < m_Config.getSize (); x++)
	{
		if (m_Config[x]->winName == windowName)
			return m_Config[x];
	}

	return NULL;
}

void ModelEditorConfig::setWindow (const WindowConfig &config)
{
	for (unsigned int x = 0; x < m_Config.getSize (); x++)
	{
		if (m_Config[x]->winName == config.winName)
		{
			m_Config[x]->x = config.x; m_Config[x]->y = config.y;
			m_Config[x]->w = config.w; m_Config[x]->h = config.h;
			return;
		}
	}

	WindowConfig *wc = new WindowConfig;
	wc->x = config.x; wc->y = config.y;
	wc->w = config.w; wc->h = config.h;
	wc->winName = config.winName;

	m_Config.add (wc);
}
