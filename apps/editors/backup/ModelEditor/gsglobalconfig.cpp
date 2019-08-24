#include "gsglobalconfig.h"

namespace gs
{
	gsglobalconfig::gsglobalconfig ()
	{
		m_fPrimDist = 2.f;
		m_pConfigDocument = new gsXMLParser;
	}

	gsglobalconfig::~gsglobalconfig ()
	{
		for (int x = 0; x < m_PrimitiveList.getSize (); x++)
			delete m_PrimitiveList[x];
		m_PrimitiveList.clear ();
	}

	void gsglobalconfig::loadConfig ()
	{
		m_pConfigDocument->loadFile ("config.xml");

		gsutil::gsstring searchPath = "/config/primitives";

		//reading the primitives we created
		gsstring dirSearch = m_pConfigDocument->find (searchPath);
		gsqueue<gsstring*> m_List;

		gsstring path;
#ifdef WIN32
		WIN32_FIND_DATA findData;
		HANDLE fileHandle;
		int flag = 1;
		char temp[256];
		GetCurrentDirectory (255, temp);
		gsutil::gsstring search;
		search = temp;
		path = temp;
		path += "\\" + dirSearch + "\\";
		search += "\\" + dirSearch;
		search += "/*.scene";
		//MessageBox (NULL, search.str (), "msg", MB_OK);
		fileHandle = FindFirstFile(search.str(), &findData);
		if (fileHandle != INVALID_HANDLE_VALUE)
		{
			while (flag)
			{
				m_List.add (new gsstring (findData.cFileName));
				flag = FindNextFile(fileHandle, &findData);
			}
		}
		else
		{
		}
		FindClose(fileHandle);
#else
		dirent **list;
		int num = scandir (".", &list, NULL, NULL);
		for (int j = 0; j < num; j++)
		{
			char *name = list[n]->d_name;
			if (strstr (name, "bmp") != 0)
			{
				char item[256];
				strcpy (item, name);

				m_pTextureList->add (item);
			}

			delete list[n];
		}
		delete list;
#endif

		for (int x = 0; x < m_List.getSize (); x++)
		{
			gsstring file = path + *m_List[x];
			gsgeom::gsscene *s = gs::gssceneloader::read (file);
			s->m_strName = *m_List[x];
			addPrimitive (s);
		}
	}

	void gsglobalconfig::saveConfig ()
	{
		m_pConfigDocument->saveFile ("config.xml");
	}
};