#include "gstoolseditingscene.h"

namespace gs
{
	gstoolseditingscene::gstoolseditingscene (const gsutil::gsstring &title, 
		const int &x, const int &y, const int &w, const int &h, HWND hParent, 
		HINSTANCE hInstance, gsscene *s) : gswindow (WS_EX_TOOLWINDOW, 
		"gstoolseditingscene", title.str (), WS_OVERLAPPEDWINDOW, x, y, w, h, 
		hParent, hInstance, gstoolsEditingSceneWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pScene = s;

		m_pVertexList = new gslistbox (2, 2, w - 12, h/4 - 4, getHandle (), getInst ());
		m_pColorList = new gslistbox (2, h/4 - 4, w - 12, h/4 - 4, getHandle (), getInst ());
		m_pNormalList = new gslistbox (2, h/2 - 10, w - 12, h/4 - 4, getHandle (), getInst ());
		m_pTexCoordList = new gslistbox (2, 3*h/4 - 16, w - 12, h/4 - 4, getHandle (), getInst ());

		buildListBox ();
	}

	gstoolseditingscene::~gstoolseditingscene ()
	{
	}

	void gstoolseditingscene::buildListBox ()
	{
		for (int x = 0; x < m_pScene->m_vPoints.getSize (); x++)
		{
			gsutil::gsstring v = "";
			v += m_pScene->m_vPoints[x]->getX ();
			v += " ";
			v += m_pScene->m_vPoints[x]->getY ();
			v += " ";
			v += m_pScene->m_vPoints[x]->getZ ();

			m_pVertexList->add (v.str ());
		}

		for (x = 0; x < m_pScene->m_vColors.getSize (); x++)
		{
			gsutil::gsstring v = "";
			v += m_pScene->m_vColors[x]->getR ();
			v += " ";
			v += m_pScene->m_vColors[x]->getG ();
			v += " ";
			v += m_pScene->m_vColors[x]->getB ();
			v += " ";
			v += m_pScene->m_vColors[x]->getA ();

			m_pColorList->add (v.str ());
		}

		for (x = 0; x < m_pScene->m_vNormals.getSize (); x++)
		{
			gsutil::gsstring v = "";
			v += m_pScene->m_vNormals[x]->getX ();
			v += " ";
			v += m_pScene->m_vNormals[x]->getY ();
			v += " ";
			v += m_pScene->m_vNormals[x]->getZ ();

			m_pNormalList->add (v.str ());
		}

		for (int y = 0; y < m_pScene->m_vTexCoordinates.getSize (); y++)
		{
			gsutil::gsstring v = "";
			v += m_pScene->m_vTexCoordinates[x]->getX ();
			v += " ";
			v += m_pScene->m_vTexCoordinates[x]->getY ();

			m_pTexCoordList->add (v.str ());
		}
	}

	void gstoolseditingscene::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == LBN_DBLCLK)
		{
			if ((HWND)lParam == m_pVertexList->getHandle ())
			{
				int index = m_pVertexList->getSelected ();
				gstoolseditingmodify *w = new gstoolseditingmodify ("Edit Vertex", getX () + getWidth ()/2 - 120, getY () + getHeight ()/2 - 45, 240, 90,
					getHandle (), getInst (), m_pScene, index, gs::EDIT_VERTEX);
				add (w);
			}
			else if ((HWND)lParam == m_pColorList->getHandle ())
			{
				int index = m_pColorList->getSelected ();
				gstoolseditingmodify *w = new gstoolseditingmodify ("Edit Color", getX () + getWidth ()/2 - 120, getY () + getHeight ()/2 - 45, 240, 90,
					getHandle (), getInst (), m_pScene, index, gs::EDIT_COLOR);
				add (w);
			}
			else if ((HWND)lParam == m_pNormalList->getHandle ())
			{
				int index = m_pNormalList->getSelected ();
				gstoolseditingmodify *w = new gstoolseditingmodify ("Edit Normal", getX () + getWidth ()/2 - 120, getY () + getHeight ()/2 - 45, 240, 90,
					getHandle (), getInst (), m_pScene, index, gs::EDIT_NORMAL);
				add (w);
			}
			else if ((HWND)lParam == m_pTexCoordList->getHandle ())
			{
				int index = m_pTexCoordList->getSelected ();
				gstoolseditingmodify *w = new gstoolseditingmodify ("Edit Texture Coordinate", getWidth ()/2 - 120, getY () + getHeight ()/2 - 45, 240, 90,
					getHandle (), getInst (), m_pScene, index, gs::EDIT_TEXCOORD);
				add (w);
			}
		}
	}

	LRESULT gstoolseditingscene::gstoolsEditingSceneWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolseditingscene *w = (gstoolseditingscene*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
}