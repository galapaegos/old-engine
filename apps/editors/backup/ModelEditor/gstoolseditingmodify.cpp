#include "gstoolseditingmodify.h"

namespace gs
{
	gstoolseditingmodify::gstoolseditingmodify (const gsutil::gsstring &title, const int &x, const int &y, const int &w, const int &h, 
		HWND hParent, HINSTANCE hInstance, gsscene *s, const int &index, const EDITING_TYPE &type) : gswindow (WS_EX_TOOLWINDOW, 
		"gstoolseditingmodifyscene", title.str (), WS_OVERLAPPEDWINDOW, x, y, w, h, hParent, hInstance, gstoolsEditingModifyWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_type = type;
		m_pScene = s;
		m_iIndex = index;
		gsutil::gsstring val;

		switch (type)
		{
		case gs::EDIT_VERTEX:
			{
				val = gsstring (m_pScene->m_vPoints[index]->getX ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vPoints[index]->getY ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vPoints[index]->getZ ());
			}
			break;

		case gs::EDIT_COLOR:
			{
				val = gsstring (m_pScene->m_vColors[index]->getR ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vColors[index]->getG ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vColors[index]->getB ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vColors[index]->getA ());
			}
			break;

		case gs::EDIT_NORMAL:
			{
				val = gsstring (m_pScene->m_vNormals[index]->getX ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vNormals[index]->getY ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vNormals[index]->getZ ());
			}
			break;

		case gs::EDIT_TEXCOORD:
			{
				val = gsstring (m_pScene->m_vTexCoordinates[index]->getX ()) + gsstring (" ") + 
					gsstring (m_pScene->m_vTexCoordinates[index]->getY ());
			}
			break;
		}

		m_pEdit = new gstextbox (val.str (), 10, 10, 200, 25, getHandle (), getInst ());

		m_pOk = new gsbutton ("Ok", 10, 40, 60, 25, getHandle (), getInst ());
		m_pCancel = new gsbutton ("Cancel", 80, 40, 60, 25, getHandle (), getInst ());

		UpdateWindow (getHandle ());
	}

	gstoolseditingmodify::~gstoolseditingmodify ()
	{
		delete m_pEdit;
		delete m_pOk;
		delete m_pCancel;
	}

	void gstoolseditingmodify::onKeyDown (WPARAM wParam, LPARAM lParam)
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

	void gstoolseditingmodify::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == BN_CLICKED)
		{
			if (m_pOk->getHandle () == (HWND)lParam)
			{
				switch (m_type)
				{
				case gs::EDIT_VERTEX:
					{
						float fx, fy, fz;
						sscanf (m_pEdit->getText ().str (), "%f %f %f", &fx, &fy, &fz);
						m_pScene->m_vPoints[m_iIndex]->set (fx, fy, fz);
					}
					break;

				case gs::EDIT_COLOR:
					{
						float fr, fg, fb, fa;
						sscanf (m_pEdit->getText ().str (), "%f %f %f %f", &fr, &fg, &fb, &fa);
						m_pScene->m_vColors[m_iIndex]->set (fr, fg, fb, fa);
					}
					break;

				case gs::EDIT_NORMAL:
					{
						float fx, fy, fz;
						sscanf (m_pEdit->getText ().str (), "%f %f %f", &fx, &fy, &fz);
						m_pScene->m_vNormals[m_iIndex]->set (fx, fy, fz);
					}
					break;

				case gs::EDIT_TEXCOORD:
					{
						float fx, fy;
						sscanf (m_pEdit->getText ().str (), "%f %f", &fx, &fy);
						m_pScene->m_vTexCoordinates[m_iIndex]->set (fx, fy);
					}
					break;
				}

				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
				delete this;
			}
			else if (m_pCancel->getHandle () == (HWND)lParam)
			{
				delete this;
			}
		}
	}

	LRESULT gstoolseditingmodify::gstoolsEditingModifyWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolseditingmodify *w = (gstoolseditingmodify*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
		case WM_COMMAND:
			w->onCommand (wParam, lParam);
			break;

		case WM_DESTROY:
			w->onDestroy ();
			break;

		default:
			return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
}