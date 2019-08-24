#include "gsworld.h"

namespace gs
{
	gsworld::gsworld (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance) : 
	gswindow (exStyle, pclass, ptitle, style,
		x, y, w, h,
		hParent, hInstance, gsworldWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		setRoot (hParent);

		m_bPicking = false;
		m_iSelected = -1;

		m_bRotate = false;
		m_bTranslate = false;
		m_bRotateObject = false;
		m_bMove = false;
		m_bAction = false;

		m_bXAxis = false;
		m_bYAxis = false;
		m_bZAxis = false;

		m_iOldx = 0;
		m_iOldy = 0;

		m_pKeyStatus = new gskeystatus (0, "keystatus", "", WS_POPUP, 
			getWidth () - 80, y, 80, 150, getHandle (), getInst ());
		//m_pKeyStatus = new gskeystatus (WS_EX_TOOLWINDOW, "keystatus", "KeyStatus", WS_OVERLAPPEDWINDOW,
		//	getWidth () - 80, y, 80, 150, getHandle (), getInst ());
		m_pKeyStatus->show ();
	}
	gsworld::~gsworld ()
	{
		destroy ();
	}

	void gsworld::init ()
	{
		kern = new gskernel;
		gskernel::set (kern);

		WINDOWINFO inf;
		GetWindowInfo (getHandle (), &inf);

		int width = inf.rcClient.right - inf.rcClient.left;
		int height = inf.rcClient.bottom - inf.rcClient.top;

		kern->init (getHandle (), width, height);

		gscamera *c = new gscamera;
		c->setProjection (width, height, 45.f, 0.1f, 300.f);
		c->setView (gsvec3f (0, 1, 5), gsvec3f (0, 1, 0), gsvec3f (0, 1, 0));
		gskernel::get ()->addEvent (gsevent (GS_CAMERA, c));

		{
			gsscene *grid = new gsscene ();
			grid->m_strName = "grid";
			grid->m_iVectorType = gsscene::GS_LINE;
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-9.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-9.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-8.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-8.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-7.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-7.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-6.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-6.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-5.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-5.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-4.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-4.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-3.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-3.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-2.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-2.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (-1.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-1.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (0.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (0.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (1.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (1.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (2.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (2.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (3.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (3.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (4.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (4.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (5.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (5.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (6.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (6.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (7.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (7.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (8.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (8.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (9.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (9.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 10.f));

			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -10.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -9.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -9.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -8.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -8.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -7.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -7.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -6.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -6.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -5.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -5.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -4.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -4.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -3.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -3.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -2.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -2.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, -1.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, -1.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 0.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 0.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 1.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 1.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 2.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 2.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 3.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 3.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 4.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 4.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 5.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 5.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 6.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 6.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 7.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 7.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 8.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 8.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 9.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 9.f));
			grid->m_vPoints.add (new gsvec3f (-10.f, 0, 10.f));
			grid->m_vPoints.add (new gsvec3f (10.f, 0, 10.f));

			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));

			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));
			grid->m_vColors.add (new gscolor (1.f, 1.f, 1.f));

			kern->addEvent (gsevent (GS_ADD_SCENE, grid));
		}

		//gsscene *ply2 = new gsscene ();
		//ply2->m_iVectorType = gsscene::GS_TRIANGLE;
		//ply2->m_vPoints.add (new gsvec3f (2, 0.5, 2));
		//ply2->m_vPoints.add (new gsvec3f (2, 0.5, 0));
		//ply2->m_vPoints.add (new gsvec3f (0, 0.5, 2));
		//ply2->m_vColors.add (new gsvec3f (1, 0, 0));
		//ply2->m_vColors.add (new gsvec3f (0, 1, 0));
		//ply2->m_vColors.add (new gsvec3f (0, 1, 1));
		//gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, ply2));

		gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
	}

	void gsworld::destroy ()
	{
		/*for (int x = 0; x < gskernel::get ()->m_RenderQueue.getSize (); x++)
		{
			gsscene *s = kern->getScene (x);
			cleanScene (s);
		}*/

		//if (m_pKeyStatus)
		//	delete m_pKeyStatus;
		//if (m_pEditMenu)
		//	delete m_pEditMenu;

		kern->shutdown ();

		delete kern;
	}

	void gsworld::cleanScene (gsscene *s)
	{
		for (int x = 0; x < s->m_ChildNodes.getSize (); x++)
			cleanScene (s->m_ChildNodes[x]);

		if (strncmp (s->m_strName.str (), "pick", 10) == 0)
		{
			for (int b = 0; b < s->m_vColors.getSize (); b++)
			{
				if (s->m_vColors[b])
					delete s->m_vColors[b];
			}
			s->m_vColors.clear ();

			delete s;
			return;
		}

		for (int a = 0; a < s->m_vPoints.getSize (); a++)
		{
			if (s->m_vPoints[a])
				delete s->m_vPoints[a];
		}
		s->m_vPoints.clear ();

		for (int b = 0; b < s->m_vColors.getSize (); b++)
		{
			if (s->m_vColors[b])
				delete s->m_vColors[b];
		}
		s->m_vColors.clear ();

		for (int c = 0; c < s->m_vNormals.getSize (); c++)
			delete s->m_vNormals[c];
		s->m_vNormals.clear ();

		for (int d = 0; d < s->m_vTexCoordinates.getSize (); d++)
			delete s->m_vTexCoordinates[c];
		s->m_vTexCoordinates.clear ();

		delete s;
	}

	void gsworld::render ()
	{
		kern->execute ();
	}

	void gsworld::onPaint ()
	{
		PAINTSTRUCT ps;
		BeginPaint (getHandle (), &ps);
		kern->addEvent (gsevent (GS_UPDATE, NULL));
		EndPaint (getHandle (), &ps);
	}

	void gsworld::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
		case 'W':
			{
				gskernel::get ()->addEvent (gsevent (GS_CAMERA_MOVE_F, -0.1f));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
			}
			break;

		case 'S':
			{
				gskernel::get ()->addEvent (gsevent (GS_CAMERA_MOVE_F, 0.1f));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
			}
			break;

		case 'Q':
			{
				gskernel::get ()->addEvent (gsevent (GS_CAMERA_MOVE_L, -0.1f));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
			}
			break;

		case 'E':
			{
				gskernel::get ()->addEvent (gsevent (GS_CAMERA_MOVE_L, 0.1f));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
			}
			break;

		case 'A':
			{
				gskernel::get ()->addEvent (gsevent (GS_CAMERA_YAW, 0.5f));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
			}
			break;

		case 'D':
			{
				gskernel::get ()->addEvent (gsevent (GS_CAMERA_YAW, -0.5f));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
			}
			break;

			// scale the face
		case 'C':
			{
				if (m_bScale)
				{
					m_bScale = false;
					m_bXAxis = false;
					m_bYAxis = false;
					m_bZAxis = false;

					m_pKeyStatus->uncheckX ();
					m_pKeyStatus->uncheckY ();
					m_pKeyStatus->uncheckZ ();
				}
				else
					m_bScale = true;
			}
			break;

			// moves the selected face around
		case 'V':
			{
				m_pKeyStatus->toggleV ();
				if (m_bMove)
				{
					m_bMove = false;
					m_bXAxis = false;
					m_bYAxis = false;
					m_bZAxis = false;

					m_pKeyStatus->uncheckX ();
					m_pKeyStatus->uncheckY ();
					m_pKeyStatus->uncheckZ ();
				}
				else
					m_bMove = true;
			}
			break;

			// rotates the selected face around
		case 'R':
			{
				//m_pKeyStatus->toggleR ();
				if (m_bRotateObject)
					m_bRotateObject = false;
				else
					m_bRotateObject = true;
			}
			break;

			// change two of the points values
		case 'T':
			{
				//m_pKeyStatus->toggleT ();
				if (m_bTranslate)
				{
					m_bTranslate = false;
					m_bXAxis = false;
					m_bYAxis = false;
					m_bZAxis = false;

					m_pKeyStatus->uncheckX ();
					m_pKeyStatus->uncheckY ();
					m_pKeyStatus->uncheckZ ();
				}
				else
					m_bTranslate = true;
			}
			break;

		case 'X':
			{
				m_pKeyStatus->toggleX ();
				if (m_bXAxis == false)
				{
					m_bXAxis = true;
					m_bYAxis = false;
					m_bZAxis = false;
					m_pKeyStatus->uncheckY ();
					m_pKeyStatus->uncheckZ ();
				}
				else
					m_bXAxis = false;
			}
			break;
			
		case 'Y':
			{
				m_pKeyStatus->toggleY ();
				if (m_bYAxis == false)
				{
					m_bXAxis = false;
					m_bYAxis = true;
					m_bZAxis = false;
					m_pKeyStatus->uncheckX ();
					m_pKeyStatus->uncheckZ ();
				}
				else
					m_bYAxis = false;
			}
			break;

		case 'Z':
			{
				m_pKeyStatus->toggleZ ();
				if (m_bZAxis == false)
				{
					m_bXAxis = false;
					m_bYAxis = false;
					m_bZAxis = true;
					m_pKeyStatus->uncheckX ();
					m_pKeyStatus->uncheckY ();
				}
				else
					m_bZAxis = false;
			}
			break;

		case 'P':
			{
				gstoolsprimitives *prim = new gstoolsprimitives (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW, 
					"primitivewindow", "Primitive Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 300, 400, 600, NULL, getInst ());
				prim->show ();
			}
			break;

		case 'O':
			{
				gstoolsoptions *opts = new gstoolsoptions (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"optionswindow", "Options Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 300, 400, 600, NULL, getInst ());
				opts->show ();
			}
			break;

		case 'L':
			{
				gstoolslighting *lgt = new gstoolslighting (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"lightingwindow", "Lighting Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 300, 400, 600, NULL, getInst ());
				lgt->show ();
			}
			break;

		case 'F':
			{
				gstoolseffect *eff = new gstoolseffect (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"effectwindow", "Effect Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 300, 400, 600, NULL, getInst ());
				eff->show ();
			}
			break;
			
		case 'I':
			{
				gstoolsediting *ed = new gstoolsediting (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"editingwindow", "Editing Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 250, 400, 500, NULL, getInst ());
				ed->show ();
			}
			break;

		case 'G':
			{
				gstoolsterrain *ter = new gstoolsterrain (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"terrainwindow", "Terrain Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 300, 400, 600, NULL, getInst ());
				ter->show ();
			}
			break;

		case 'H':
			{
				gstoolsshaders *shd = new gstoolsshaders (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"shaderswindow", "Shader Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 200, getHeight ()/2 - 300, 400, 600, NULL, getInst ());
				shd->show ();
			}
			break;

		case 'U':
			{
				gstoolstexturing * text = new gstoolstexturing (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"texturewindow", "Texturing Window", WS_OVERLAPPEDWINDOW,
					getWidth ()/2 - 150, getHeight ()/2 - 200, 300, 400, NULL, getInst ());
				text->show ();
			}
			break;
		}
	}

	void gsworld::onLButtonDown (WPARAM wParam, LPARAM lParam)
	{
		float fx = LOWORD (lParam);
		float fy = (float)kern->getHeight () - HIWORD (lParam);

		int index = gskernel::get ()->pick (fx, fy);

		// we have an intersection
		if (index != -1)
		{
			gsface newface = gskernel::get ()->pickFace (fx, fy);
			gsscene *s = gskernel::get ()->m_RenderQueue[index];

			//nothing has been selected, so we need to select the item
			if (!m_bPicking)
			{
				m_bPicking = true;
				m_iSelected = index;
				m_pSelectedFace = newface;

				//add the selection here
				gsscene *sel = new gsscene;
				sel->m_strName = "pick";
				sel->m_iVectorType = gsscene::GS_LINE;
				sel->m_vPoints.add (newface.getP1 ());
				sel->m_vPoints.add (newface.getP2 ());
				sel->m_vPoints.add (newface.getP2 ());
				sel->m_vPoints.add (newface.getP3 ());
				sel->m_vPoints.add (newface.getP3 ());
				sel->m_vPoints.add (newface.getP1 ());

				sel->m_vColors.add (new gscolor (1, 1, 0, 1));
				sel->m_vColors.add (new gscolor (1, 1, 0, 1));
				sel->m_vColors.add (new gscolor (1, 1, 0, 1));
				sel->m_vColors.add (new gscolor (1, 1, 0, 1));
				sel->m_vColors.add (new gscolor (1, 1, 0, 1));
				sel->m_vColors.add (new gscolor (1, 1, 0, 1));

				gsglobalconfig::get ()->setSelected (s);

				s->m_ChildNodes.add (sel);
				//gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, sel));
			}
			else
			{
				gsscene *prev = kern->m_RenderQueue[m_iSelected];

				// remove the selection
				for (int x = 0; x < prev->m_ChildNodes.getSize (); x++)
				{
					gsscene *child = prev->m_ChildNodes[x];
					if (strcmp (child->m_strName.str (), "pick") == 0)
					{
						prev->m_ChildNodes.erase (x);
						gsglobalconfig::get ()->setSelected (NULL);
					}
				}

				//if (m_pSelectedFace == newface)
				if (((m_pSelectedFace.getP1 ()->getX () == newface.getP1 ()->getX ()) &&
					(m_pSelectedFace.getP1 ()->getY () == newface.getP1 ()->getY ()) &&
					(m_pSelectedFace.getP1 ()->getZ () == newface.getP1 ()->getZ ()) &&
					(m_pSelectedFace.getP2 ()->getX () == newface.getP2 ()->getX ()) &&
					(m_pSelectedFace.getP2 ()->getY () == newface.getP2 ()->getY ()) &&
					(m_pSelectedFace.getP2 ()->getZ () == newface.getP2 ()->getZ ()) &&
					(m_pSelectedFace.getP3 ()->getX () == newface.getP3 ()->getX ()) &&
					(m_pSelectedFace.getP3 ()->getY () == newface.getP3 ()->getY ()) &&
					(m_pSelectedFace.getP3 ()->getZ () == newface.getP3 ()->getZ ())))
				{
					m_bPicking = false;
					m_iSelected = -1;
				}
				else
				{
					m_pSelectedFace = newface;
					m_iSelected = index;

					gsscene *sel = new gsscene;
					sel->m_strName = "pick";
					sel->m_iVectorType = gsscene::GS_LINE;
					sel->m_vPoints.add (new gsvec3f (newface.getP1 ()->getX (),
													newface.getP1 ()->getY (),
													newface.getP1 ()->getZ ()));
					sel->m_vPoints.add (new gsvec3f (newface.getP2 ()->getX (),
													newface.getP2 ()->getY (),
													newface.getP2 ()->getZ ()));
					sel->m_vPoints.add (new gsvec3f (newface.getP2 ()->getX (),
													newface.getP2 ()->getY (),
													newface.getP2 ()->getZ ()));
					sel->m_vPoints.add (new gsvec3f (newface.getP3 ()->getX (),
													newface.getP3 ()->getY (),
													newface.getP3 ()->getZ ()));
					sel->m_vPoints.add (new gsvec3f (newface.getP3 ()->getX (),
													newface.getP3 ()->getY (),
													newface.getP3 ()->getZ ()));
					sel->m_vPoints.add (new gsvec3f (newface.getP1 ()->getX (),
													newface.getP1 ()->getY (),
													newface.getP1 ()->getZ ()));
					sel->m_vColors.add (new gscolor (1, 1, 0));
					sel->m_vColors.add (new gscolor (1, 1, 0));
					sel->m_vColors.add (new gscolor (1, 1, 0));
					sel->m_vColors.add (new gscolor (1, 1, 0));
					sel->m_vColors.add (new gscolor (1, 1, 0));
					sel->m_vColors.add (new gscolor (1, 1, 0));

					gsglobalconfig::get ()->setSelected (s);

					s->m_ChildNodes.add (sel);
				}
			}
		}
		else
		{
			if (m_bPicking)
			{
				gsscene *s = gskernel::get ()->getScene (m_iSelected);
				m_iSelected = -1;
				m_bPicking = false;

				// remove the selection
				for (int x = 0; x < s->m_ChildNodes.getSize (); x++)
				{
					gsscene *child = s->m_ChildNodes[x];
					if (strcmp (child->m_strName.str (), "pick") == 0)
					{
						s->m_ChildNodes.erase (x);
						gsglobalconfig::get ()->setSelected (NULL);
					}
				}
			}
		}

		gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
	}

	void gsworld::onMButtonDown (WPARAM wParam, LPARAM lParam)
	{
		m_bRotate = true;
	}

	void gsworld::onRButtonDown (WPARAM wParam, LPARAM lParam)
	{
		m_bAction = true;
	}

	void gsworld::onLButtonUp (WPARAM wParam, LPARAM lParam)
	{
	}

	void gsworld::onMButtonUp (WPARAM wParam, LPARAM lParam)
	{
		m_bRotate = false;
	}

	void gsworld::onRButtonUp (WPARAM wParam, LPARAM lParam)
	{
		m_bAction = false;
	}

	void gsworld::onMouseMove (WPARAM wParam, LPARAM lParam)
	{
		int newx = HIWORD (lParam);
		int newy = LOWORD (lParam);

		if (m_bRotate)
		{
			float difx = (float)newx - (float)m_iOldx;
			float dify = (float)newy - (float)m_iOldy;

			gskernel::get ()->addEvent (gsevent (GS_CAMERA_YAW, dify*0.1f));
			gskernel::get ()->addEvent (gsevent (GS_CAMERA_PITCH, difx*0.1f));
			gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
		}
		if (m_bAction && m_bMove && m_bPicking && !m_bRotate)
		{
			float difx = (float)(newx - m_iOldx)*0.05f;

			if (m_bXAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				p1->set (p1->getX () - difx, p1->getY (), p1->getZ ());
				p2->set (p2->getX () - difx, p2->getY (), p2->getZ ());
				p3->set (p3->getX () - difx, p3->getY (), p3->getZ ());
			}
			else if (m_bYAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				p1->set (p1->getX (), p1->getY () - difx, p1->getZ ());
				p2->set (p2->getX (), p2->getY () - difx, p2->getZ ());
				p3->set (p3->getX (), p3->getY () - difx, p3->getZ ());
			}
			else if (m_bZAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				p1->set (p1->getX (), p1->getY (), p1->getZ () + difx);
				p2->set (p2->getX (), p2->getY (), p2->getZ () + difx);
				p3->set (p3->getX (), p3->getY (), p3->getZ () + difx);
			}

			gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
		}

		if (m_bAction && m_bTranslate && m_bPicking && !m_bRotate)
		{
			float difx = (newx - m_iOldx)*0.05f;

			bool bp1 = m_pKeyStatus->isCheckedP1 ();
			bool bp2 = m_pKeyStatus->isCheckedP2 ();
			bool bp3 = m_pKeyStatus->isCheckedP3 ();

			if (m_bXAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				if (bp1 && bp2)
				{
					p1->set (p1->getX () - difx, p1->getY (), p1->getZ ());
					p2->set (p2->getX () - difx, p2->getY (), p2->getZ ());
				}
				else if (bp2 && bp3)
				{
					p2->set (p2->getX () - difx, p2->getY (), p2->getZ ());
					p3->set (p3->getX () - difx, p3->getY (), p3->getZ ());
				}
				else if (bp3 && bp1)
				{
					p3->set (p3->getX () - difx, p3->getY (), p3->getZ ());
					p1->set (p1->getX () - difx, p1->getY (), p1->getZ ());
				}
			}
			else if (m_bYAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				if (bp1 && bp2)
				{
					p1->set (p1->getX (), p1->getY () - difx, p1->getZ ());
					p2->set (p2->getX (), p2->getY () - difx, p2->getZ ());
				}
				else if (bp2 && bp3)
				{
					p2->set (p2->getX (), p2->getY () - difx, p2->getZ ());
					p3->set (p3->getX (), p3->getY () - difx, p3->getZ ());
				}
				else if (bp3 && bp1)
				{
					p3->set (p3->getX (), p3->getY () - difx, p3->getZ ());
					p1->set (p1->getX (), p1->getY () - difx, p1->getZ ());
				}
			}
			else if (m_bZAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				if (bp1 && bp2)
				{
					p1->set (p1->getX (), p1->getY (), p1->getZ () + difx);
					p2->set (p2->getX (), p2->getY (), p2->getZ () + difx);
				}
				else if (bp2 && bp3)
				{
					p2->set (p2->getX (), p2->getY (), p2->getZ () + difx);
					p3->set (p3->getX (), p3->getY (), p3->getZ () + difx);
				}
				else if (bp3 && bp1)
				{
					p3->set (p3->getX (), p3->getY (), p3->getZ () + difx);
					p1->set (p1->getX (), p1->getY (), p1->getZ () + difx);
				}
				
			}

			gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
		}
		if (m_bAction && m_bRotateObject && m_bPicking && !m_bRotate)
		{
			float difx = (float)(newx - m_iOldx);

			if (m_bXAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				gsmatrix m;
				m.rotX (difx);
				gsvec3f t1 = m * (*p1);
				gsvec3f t2 = m * (*p2);
				gsvec3f t3 = m * (*p3);

				p1->set (t1.getX (), t1.getY (), t1.getZ ());
				p2->set (t2.getX (), t2.getY (), t2.getZ ());
				p3->set (t3.getX (), t3.getY (), t3.getZ ());
			}
			else if (m_bYAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				gsmatrix m;
				m.rotY (difx);
				gsvec3f t1 = m * (*p1);
				gsvec3f t2 = m * (*p2);
				gsvec3f t3 = m * (*p3);

				p1->set (t1.getX (), t1.getY (), t1.getZ ());
				p2->set (t2.getX (), t2.getY (), t2.getZ ());
				p3->set (t3.getX (), t3.getY (), t3.getZ ());
			}
			else if (m_bZAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				gsmatrix m;
				m.rotZ (difx);
				gsvec3f t1 = m * (*p1);
				gsvec3f t2 = m * (*p2);
				gsvec3f t3 = m * (*p3);

				p1->set (t1.getX (), t1.getY (), t1.getZ ());
				p2->set (t2.getX (), t2.getY (), t2.getZ ());
				p3->set (t3.getX (), t3.getY (), t3.getZ ());
			}

			gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
		}
		if (m_bAction && m_bScale && m_bPicking && !m_bRotate)
		{
			float difx = (float)(newx - m_iOldx);

			if (m_bXAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				gsmatrix m;
				m.scale (gsvec3f (difx, 1.f, 1.f));
				gsvec3f t1 = m * (*p1);
				gsvec3f t2 = m * (*p2);
				gsvec3f t3 = m * (*p3);

				p1->set (t1.getX (), t1.getY (), t1.getZ ());
				p2->set (t2.getX (), t2.getY (), t2.getZ ());
				p3->set (t3.getX (), t3.getY (), t3.getZ ());
			}
			else if (m_bYAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				gsmatrix m;
				m.scale (gsvec3f (1.f, difx, 1.f));
				gsvec3f t1 = m * (*p1);
				gsvec3f t2 = m * (*p2);
				gsvec3f t3 = m * (*p3);

				p1->set (t1.getX (), t1.getY (), t1.getZ ());
				p2->set (t2.getX (), t2.getY (), t2.getZ ());
				p3->set (t3.getX (), t3.getY (), t3.getZ ());
			}
			else if (m_bZAxis)
			{
				gsvec3f *p1 = m_pSelectedFace.getP1 ();
				gsvec3f *p2 = m_pSelectedFace.getP2 ();
				gsvec3f *p3 = m_pSelectedFace.getP3 ();

				gsmatrix m;
				m.scale (gsvec3f (1.f, 1.f, difx));
				gsvec3f t1 = m * (*p1);
				gsvec3f t2 = m * (*p2);
				gsvec3f t3 = m * (*p3);

				p1->set (t1.getX (), t1.getY (), t1.getZ ());
				p2->set (t2.getX (), t2.getY (), t2.getZ ());
				p3->set (t3.getX (), t3.getY (), t3.getZ ());
			}

			gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
		}

		m_iOldx = HIWORD (lParam);
		m_iOldy = LOWORD (lParam);
	}

	void gsworld::onCommand (WPARAM wParam, LPARAM lParam)
	{
		// We've got a menu to handle
		if (HIWORD(wParam) == 0)
		{
			switch (LOWORD(wParam))
			{
			case EDIT_FACE:
				{
					//gsmenuediting *edit = new gsmenuediting (0, 
					//	"gsediting", "Editing Face", WS_OVERLAPPEDWINDOW,
					//	0, 0, 400, 500, NULL, getInst ());
					//edit->show ();
					//MessageBox (NULL, "edit face", "message", MB_OK);
				}
				break;

			case EDIT_SNAPTOGRID:
				break;
			}
		}
	}

	LRESULT CALLBACK gsworld::gsworldWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsworld *w = (gsworld*)GetWindowLong (hWnd, GWL_USERDATA);

		switch (message) 
		{
			case WM_PAINT:
				w->onPaint ();
				break;

			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;

			case WM_MOUSEMOVE:
				w->onMouseMove (wParam, lParam);
				break;

			case WM_LBUTTONDOWN:
				w->onLButtonDown (wParam, lParam);
				break;

			case WM_LBUTTONUP:
				w->onLButtonUp (wParam, lParam);
				break;

			case WM_MBUTTONDOWN:
				w->onMButtonDown (wParam, lParam);
				break;

			case WM_MBUTTONUP:
				w->onMButtonUp (wParam, lParam);
				break;

			case WM_RBUTTONDOWN:
				w->onRButtonDown (wParam, lParam);
				break;

			case WM_RBUTTONUP:
				w->onRButtonUp (wParam, lParam);
				break;

			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
};