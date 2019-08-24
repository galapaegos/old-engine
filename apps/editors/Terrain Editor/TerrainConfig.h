#ifndef _TerrainConfig_h_
#define _TerrainConfig_h_

#include <gsgeom/gsscene.h>
#include <gsutil/gssingleton.h>
#include <gsutil/gssystem.h>
#include <gsutil/gsXMLParser.h>

class TerrainConfig : public gsutil::gssingleton <TerrainConfig>
{
public:
	TerrainConfig (const gsutil::gsstring &pConfig);
	~TerrainConfig ();

	void loadConfig ();
	void saveConfig ();

	gsutil::gsstring m_worldData;

	gsgeom::gsscene *m_pScene;
	gsgeom::gsscene *m_pPicked;

	bool m_bFlatten;
	bool m_bRaise;

private:
	gsutil::gsXMLParser *m_pParser;
	gsutil::gsstring m_strConfig;
};

#endif
