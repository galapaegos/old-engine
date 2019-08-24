#include "gstoolsediting.h"

namespace gs
{
	gstoolsediting::gstoolsediting (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gswindow (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsEditingWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pList = new gslistbox (0, 0, w - 80, h, getHandle (), getInst ());
		buildList ();

		m_pAdd = new gsbutton ("Add", w - 78, 0, 70, 25, getHandle (), getInst ());
		m_pRemove = new gsbutton ("Detach", w - 78, 30, 70, 25, getHandle (), getInst ());
		m_pMove = new gsbutton ("Move", w - 78, 60, 70, 25, getHandle (), getInst ());
		m_pMerge = new gsbutton ("Merge", w - 78, 90, 70, 25, getHandle (), getInst ());
		m_pGenerateBB = new gsbutton ("Create BB", w - 78, 120, 70, 25, getHandle (), getInst ());
		m_pSave = new gsbutton ("Save", w - 78, 150, 70, 25, getHandle (), getInst ());

		m_bAddSrc = false;
		m_iAddSrc = 0;

		m_bMoveSrc = false;
		m_iMoveSrc = 0;

		m_bMergeSrc = false;
		m_iMergeSrc = 0;
	}
	
	gstoolsediting::~gstoolsediting ()
	{
		if (m_pList)
			delete m_pList;
	}

	void gstoolsediting::buildList ()
	{
		for (int x = 0; x < gskernel::get ()->m_RenderQueue.getSize (); x++)
		{
			gsscene *s = gskernel::get ()->getScene (x);
			addScene (s);
		}

		UpdateWindow (m_pList->getHandle ());
		UpdateWindow (m_pList->getParent ());
	}

	void gstoolsediting::addScene (gsscene *t, int spacing)
	{
		m_pList->add (t->m_strName.str ());
		m_sceneList.add (t);

		for (int x = 0; x < t->m_ChildNodes.getSize (); x++)
			addScene (t->m_ChildNodes[x], spacing+1);
	}

	void gstoolsediting::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == LBN_DBLCLK)
		{
			int iIndex = m_pList->getSelected ();
			gsgfx::gsscene *s = gskernel::get ()->getScene (iIndex);
			gstoolseditingscene *n = new gstoolseditingscene (s->m_strName.str (),
				getX () + getWidth ()/2 - 100, getY () + getHeight ()/2 - 200, 200, 400, getHandle (), getInst (), s);
		}

		if (HIWORD (wParam) == BN_CLICKED)
		{
			int iIndex = m_pList->getSelected ();
			if (iIndex < 0)
				return;

			gsgfx::gsscene *s = gskernel::get ()->getScene (iIndex);

			if (m_pAdd->getHandle () == (HWND)lParam)
			{
				if (!m_bAddSrc)
				{
					m_bAddSrc = true;
					m_iAddSrc = iIndex;

					m_pList->clearSelected ();
				}
				else
				{
					int m_iAddDest = iIndex;

					//Add src scene as a subscene to the second
					gsscene *src = m_sceneList[m_iAddSrc];
					gsscene *dest = m_sceneList[m_iAddDest];

					gskernel::get ()->addEvent (gsevent (GS_REM_SCENE, src));
					dest->m_ChildNodes.add (src);

					m_pList->clearList ();
					buildList ();
				}
			}
			else if (m_pRemove->getHandle () == (HWND)lParam)
			{
				int m_iRemoveSrc = iIndex;

				gsscene *src = m_sceneList[m_iRemoveSrc];
				gsscene *srcParent = gskernel::get ()->findParent (src);

				delete src;
				gskernel::get ()->addEvent (gsevent (GS_REM_SCENE, src));
			}
			else if (m_pMove->getHandle () == (HWND)lParam)
			{
				if (!m_bMoveSrc)
				{
					m_bMoveSrc = true;
					m_iMoveSrc = iIndex;

					m_pList->clearSelected ();
				}
				else
				{
					int m_iMoveDest = iIndex;

					//remove scene
					gsscene *src = m_sceneList[m_bMoveSrc];
					gsscene *dest = m_sceneList[m_iMoveDest];

					m_pList->clearList ();
					buildList ();
				}
			}
			else if (m_pMerge->getHandle () == (HWND)lParam)
			{
				//Merge selected scene, prompt user with another list to select the destination scene
				if (!m_bMergeSrc)
				{
					m_bMergeSrc = true;
					m_iMergeSrc = iIndex;

					m_pList->clearSelected ();
				}
				else if (m_bMergeSrc)
				{
					int m_iMergeDest = iIndex;

					//Perform merge
					gsscene *src = m_sceneList[m_iMergeSrc];
					gsscene *dest = m_sceneList[m_iMergeDest];

					if (src->m_iVectorType == dest->m_iVectorType)
					{
						for (int x = 0; x < src->m_vPoints.getSize (); x++)
							dest->m_vPoints.add (src->m_vPoints[x]);
						src->m_vPoints.clear ();

						for (x = 0; x < src->m_vColors.getSize (); x++)
							dest->m_vColors.add (src->m_vColors[x]);
						src->m_vColors.clear ();

						for (x = 0; x < src->m_vNormals.getSize (); x++)
							dest->m_vNormals.add (src->m_vNormals[x]);
						src->m_vNormals.clear ();

						for (x = 0; x < src->m_vTexCoordinates.getSize (); x++)
							dest->m_vTexCoordinates.add (src->m_vTexCoordinates[x]);
						src->m_vTexCoordinates.clear ();

						gskernel::get ()->addEvent (gsevent (GS_REM_SCENE, src));
					}

					m_pList->clearList ();
					buildList ();
				}
			}
			else if (m_pGenerateBB->getHandle () == (HWND)lParam)
			{
				// find min and max points and set a bounding box
				s->calculateBoundingBox ();
			}
			else if (m_pSave->getHandle () == (HWND)lParam)
			{
				OPENFILENAME f;
				char buf[255];
				memset (&f, 0, sizeof (OPENFILENAME));
				f.lStructSize = sizeof (OPENFILENAME);
				f.hwndOwner = getHandle ();
				f.lpstrFilter = "Scene\0*.scene\0";
				f.lpstrFile = buf;
				f.lpstrFile[0] = '\0';
				f.nFilterIndex = 0;
				f.nMaxFile = 256;
				f.lpstrFileTitle = "";
				f.nMaxFileTitle = 0;
				f.lpstrInitialDir = ""; //config will store this
				f.lpstrTitle = "";
				f.Flags = OFN_PATHMUSTEXIST;
				f.lpstrDefExt = "";

				if (GetSaveFileName (&f) != 0)
				{
					// create a gsscene, fill in the camera options and add 
					//the m_RenderQueue as child scenes to this one

					//gsscene *s = m_SceneLoader.read (f.lpstrFile);
					//gskernel::get ().addEvent (gsevent (GS_ADD_SCENE, s));
					//gskernel::get ().addEvent (gsevent (GS_UPDATE, NULL));

					gsstring pStr = f.lpstrFile;
					gskernel::get ()->addEvent (gsevent (GS_SAVE_SCENE, pStr));
					gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
				}
			}
		}
	}

	LRESULT CALLBACK gstoolsediting::gstoolsEditingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsediting *w = (gstoolsediting*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{			
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;
					
			case WM_DESTROY:
				w->onDestroy ();
				break;

			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;
					
			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
};