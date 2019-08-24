#include "TerrainConfig.h"

TerrainConfig::TerrainConfig (const gsutil::gsstring &pConfig)
{
	m_strConfig = pConfig;
	m_pParser = new gsutil::gsXMLParser;

	m_pScene = new gsgeom::gsscene;
	m_pPicked = NULL;

	m_bFlatten = false;
	m_bRaise = false;
}

TerrainConfig::~TerrainConfig ()
{
}

void TerrainConfig::loadConfig ()
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
			if (c->getName () == "WorldData")
				m_worldData = c->getValue ();
	
		}
	}
}

void TerrainConfig::saveConfig ()
{
	m_pParser->saveFile (m_strConfig);
}
