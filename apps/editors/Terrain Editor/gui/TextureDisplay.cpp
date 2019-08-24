#include "TextureDisplay.h"
#include "TexturePreview.h"

TextureDisplay::TextureDisplay (const int &x, const int &y, const int &w, const int &h) : gswin::gswindow (0,
   "TextureDisplay", "Textures", WS_OVERLAPPEDWINDOW, x, y, w, h)
{
	gsutil::gsstring dir = TerrainConfig::get ()->m_worldData;
	
	
	int count = gsutil::gssystem::getDirectorySize (dir, "bmp");
	gsutil::gsarray <gsutil::gsstring> list (count);

	gsutil::gssystem::getDirectoryList (dir, "bmp", list);

	m_pList = new gswin::gslistbox (this, "", WS_CHILD|LBS_STANDARD|WS_VISIBLE, 5, 5, 
		getWidth () - 25, getHeight () - 55);
	for (unsigned int i = 0; i < list.getSize (); i++)
		m_pList->add (list[i]);
	m_pList->show ();

	list.clear ();

	m_pOk = new gswin::gsbutton (this, "Ok", BS_PUSHBUTTON|WS_CHILD, 5, getHeight () - 50, 
		getWidth ()/2 - 10, 25);
	m_pCancel = new gswin::gsbutton (this, "Cancel", BS_PUSHBUTTON|WS_CHILD, getWidth ()/2 + 5, 
		getHeight () - 50, getWidth ()/2 - 10, 25);
}

TextureDisplay::~TextureDisplay ()
{
}

void TextureDisplay::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wp) == LBN_DBLCLK)
	{
		gsutil::gsstring file = TerrainConfig::get ()->m_worldData + m_pList->getSelectedItem ();

		HWND hFind = FindWindow (file.str (), NULL);

		if (!hFind)
		{
			TexturePreview *preview = new TexturePreview (0, file, file, WS_OVERLAPPEDWINDOW, 0, 0, 0, 0);
			preview->show ();
		}
		else
			ShowWindow (hFind, SW_NORMAL);
	}

	if ((HWND)lp == m_pOk->getHandle ())
	{
		//check for selected quad
		gsgeom::gsscene *s = TerrainConfig::get ()->m_pPicked;
		if (s)
		{
			if (!s->m_Geometry)
				s->m_Geometry = new gsgeom::gsgeometryinfo;
			if (s->m_Geometry->m_Textures.getSize () > 0)
			{
				s->m_Geometry->m_vTexCoordinates.clear ();
				while (s->m_Geometry->m_Textures.getSize () > 0)
				{
					//gsimage::gstexture *t = s->m_Geometry->m_Textures[0];
					s->m_Geometry->m_Textures.erase (0);
					//delete t;
				}
			}

			gsutil::gsstring file = TerrainConfig::get ()->m_worldData + m_pList->getSelectedItem ();

			gsimage::gstexture *t = new gsimage::gsbmp;
			t->load (file);

			if (t->getWidth () > 0 && t->getHeight () > 0)
			{
				//add texture and render it to this quad
				s->m_Geometry->m_Textures.add (t);

				s->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
				s->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));
				s->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 1));
				s->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
			}
			else
				printf ("unable to load file:%s\n", file.str ());
		}
	}

	if ((HWND)lp == m_pCancel->getHandle ())
	{
	}
}
