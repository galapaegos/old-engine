#include "gstoolstexturing.h"

namespace gs
{
	gstoolstexturing::gstoolstexturing (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gswindow (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsTexturingWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pTextureList = new gslistbox (0, 0, w, h - 85, getHandle (), getInst ());
		//TODO: get executable directory, need to use FindFirstFile from win32
#ifdef WIN32
		WIN32_FIND_DATA findData;
		HANDLE fileHandle;
		int flag = 1;
		char temp[256];
		GetCurrentDirectory (255, temp);
		gsutil::gsstring search;
		search = temp;
		search += "/*.bmp";
		fileHandle = FindFirstFile(search.str(), &findData);
		if (fileHandle != INVALID_HANDLE_VALUE)
		{
			while (flag)
			{
				m_pTextureList->add (findData.cFileName);
				flag = FindNextFile(fileHandle, &findData);
			}
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

		m_pPreview = new gsbutton ("Preview", w/2 - 50, h - 95, 100, 25, getHandle (), getInst ());
		m_pApplyTexturing = new gsbutton ("Apply Texture", w/2 - 50, h - 65, 100, 25, getHandle (), getInst ());

		UpdateWindow (getHandle ());
	}
	
	gstoolstexturing::~gstoolstexturing ()
	{
		delete m_pTextureList;
		delete m_pApplyTexturing;
	}

	void gstoolstexturing::onDestroy ()
	{
		delete this;
	}

	void gstoolstexturing::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
		case ' ':
			{
				delete this;
			}
			break;
		}
	}

	void gstoolstexturing::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == LBN_DBLCLK)
		{
			int iIndex = m_pTextureList->getSelected ();
			// search for texture
			// render texture to screen

			gsstring tex = m_pTextureList->getSelectedItem ();

			char temp[256];
			GetCurrentDirectory (255, temp);
			gsstring file = temp;
			file += "\\";
			file += tex;
			HBITMAP hBitmap = (HBITMAP)LoadImage (getInst (), file.str (), IMAGE_BITMAP, 0, 0,
				LR_LOADFROMFILE);

			BITMAP bmp;
			GetObject (hBitmap, sizeof (BITMAP), &bmp);

			gstoolstexturepreview *p = new gstoolstexturepreview (tex, 
				getX ()  + getWidth ()/2 - bmp.bmWidth/2, getY () + getHeight ()/2 - bmp.bmHeight/2, 
				bmp.bmWidth, bmp.bmHeight, getHandle (), getInst (), hBitmap);
		}

		if (HIWORD (wParam) == BN_CLICKED)
		{
			if (m_pPreview->getHandle () == (HWND)lParam)
			{
				int iIndex = m_pTextureList->getSelected ();
				// search for texture
				// render texture to screen

				gsstring tex = m_pTextureList->getSelectedItem ();

				char temp[256];
				GetCurrentDirectory (255, temp);
				gsstring file = temp;
				file += "\\";
				file += tex;
				HBITMAP hBitmap = (HBITMAP)LoadImage (getInst (), file.str (), IMAGE_BITMAP, 0, 0,
					LR_LOADFROMFILE);

				BITMAP bmp;
				GetObject (hBitmap, sizeof (BITMAP), &bmp);

				gstoolstexturepreview *p = new gstoolstexturepreview (tex, 
					getX () - bmp.bmWidth/2, getY () - bmp.bmHeight/2, 
					bmp.bmWidth, bmp.bmHeight, getHandle (), getInst (), hBitmap);
			}
			else if (m_pApplyTexturing->getHandle () == (HWND) lParam)
			{
				int iIndex = m_pTextureList->getSelected ();
				gsstring tex = m_pTextureList->getSelectedItem ();
				gsgeom::gsscene *s = gsglobalconfig::get ()->getSelected ();

				//TODO:
				//int res = gs::gsresourcemgr::get ()->load (tex);
				int res = -1;
				//if (gskernel::get ()->getResourceMgr ()->findTextureResource (tex) > -1)
				//	res = gskernel::get ()->getResourceMgr ()->findTextureResource (tex);
				//else
                 //   res = gskernel::get ()->getResourceMgr ()->load (tex);

				//s->m_Geometry->m_Textures.add ((unsigned int)res);
				gsimage::gstexture *texture = NULL;
				s->m_Geometry->m_Textures.add (texture);
				s->m_Geometry->m_iTextureCount ++;

				for (int x = 0; x < s->m_Geometry->m_vPoints.getSize ()/3; x++)
				{
					s->m_Geometry->m_vTexCoordinates.add (gsvec2f (0.f, 0.f));
					s->m_Geometry->m_vTexCoordinates.add (gsvec2f (1.f, 0.f));
					s->m_Geometry->m_vTexCoordinates.add (gsvec2f (0.f, 1.f));
				}
			}
		}
	}

	LRESULT CALLBACK gstoolstexturing::gstoolsTexturingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolstexturing *w = (gstoolstexturing*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;
					
			case WM_DESTROY:
				w->onDestroy ();
				break;
					
			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
};