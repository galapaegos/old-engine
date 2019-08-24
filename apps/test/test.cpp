#include "test.h"

// prototypes
HWND				InitInstance(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

/* globals */
int				run = 1;
gskernel	*kern;
gscamera	*c;
bool		m_bRotate = false;
bool		m_bPicking = false;
int			m_oldx = 0;
int			m_oldy = 0;
int			selected = -1;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HWND hWindow;

	hWindow = InitInstance (hInstance, nCmdShow);
	
	kern = new gskernel ();
	gskernel::set (kern);

	kern->init ((void*)hWindow, 800, 600);

	gsscene *s = new gsscene;
	s->m_vPoints.add (new gsvec3f (0, 0, 0));
	s->m_vPoints.add (new gsvec3f (1, 0, 0));
	s->m_vPoints.add (new gsvec3f (0, 0, 1));

	s->m_vColors.add (new gscolor (1, 0, 0, 0));
	s->m_vColors.add (new gscolor (0, 1, 0, 0));
	s->m_vColors.add (new gscolor (0, 0, 1, 0));
	c = new gscamera;
	c->setProjection (800, 600, 45.f, 1.f, 300.f);
	c->setView (gsvec3f (0, 5, 5), gsvec3f (0, 0, 0), gsvec3f (0, 1, 0));

	gskernel::get ()->addEvent (gsevent (GS_CAMERA, (gsobject*)c));
	gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, (gsobject*)s));
	gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));

	while (run == 1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{	
			kern->execute ();
		}
	}

	for (int x = 0; x < kern->m_RenderQueue.getSize (); x++)
		delete kern->m_RenderQueue[x];

	kern->shutdown ();

	delete c;
	delete kern;

	return 0;
}

HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "galapaegos";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);

	RegisterClassEx(&wcex);

	hWnd = CreateWindow("galapaegos", "gskernel test", WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, 800, 600, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
	  return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	//UpdateWindow(hWnd);

	return hWnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;

	switch (message)
	{
		case WM_PAINT:
			BeginPaint(hWnd, &ps);
			kern->addEvent (gsevent (GS_RENDER, NULL));
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			{
				run = 0;
				PostQuitMessage(0);
			}
			break;

		case WM_RBUTTONDOWN:
			m_bRotate = true;
			break;

		case WM_RBUTTONUP:
			m_bRotate = false;
			break;

		case WM_MOUSEMOVE:
			{
				if (m_bRotate)
				{
					int newx = LOWORD (lParam);
					int newy = HIWORD (lParam);

					float difx = (float)newx - m_oldx;
					float dify = (float)newy - m_oldy;

					c->pitch (dify*0.05f);
					c->yaw (difx*0.05f);

					kern->addEvent (gsevent (GS_CAMERA, c));
					kern->addEvent (gsevent (GS_UPDATE, NULL));
				}

				m_oldx = LOWORD (lParam);
				m_oldy = HIWORD (lParam);
			}
			break;
			
		case WM_LBUTTONDOWN:
			{
				int index = gskernel::get ()->pick ((float)LOWORD (lParam), (float)HIWORD (lParam));

				gsray r = gskernel::get ()->m_Cam->getPicked ((float)LOWORD (lParam), (float)HIWORD (lParam));

				gsscene *a = new gsscene;
				a->m_iVectorType = gsscene::GS_LINE;
				a->m_vPoints.add (new gsvec3f (r.getPos ().getX (), r.getPos ().getY (),r.getPos ().getZ ()));
				a->m_vPoints.add (new gsvec3f (r.getPos ().getX () + r.getDir ().getX ()*5.f, 
												r.getPos ().getY () + r.getDir ().getY ()*5.f,
												r.getPos ().getZ () + r.getDir ().getZ ()*5.f));
				a->m_vColors.add (new gscolor (1.f, 0.f, 0.f, 0.f));
				a->m_vColors.add (new gscolor (1.f, 0.f, 0.f, 0.f));
				gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, a));
				gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));

				if ((selected == index) && (m_bPicking))
				{
					selected = index;

					gsscene *s = gskernel::get ()->getScene (index);

					MessageBox (NULL, "picked!", "msg", MB_OK);

					gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
				}
			}
			break;

		case WM_LBUTTONUP:
			{
				if (selected != -1)
				{
					selected = -1;

					//gsscene *s = gskernel::get ().getScene (selected);
					
					//s->m_vColors.clear ();

					//for (int x = 0; x < s->m_vPoints.getSize (); x++)
					//	s->m_vColors.add (new gsvector (1.f, 0.f, 0.f));

					//gskernel::get ().addEvent (gsevent (GS_UPDATE, NULL));
				}
			}
			break;

		case WM_KEYDOWN:
			{
				switch (wParam)
				{
					case VK_ESCAPE:
						run = 0;
						break;
						
					case 'A':
						{
							c->moveLeft (-0.05f);
							kern->addEvent (gsevent (GS_CAMERA, c));
							gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
						}
						break;
						
					case 'D':
						{
							c->moveLeft (0.05f);
							kern->addEvent (gsevent (GS_CAMERA, c));
							gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
						}
						break;
						
					case 'W':
						{
							c->moveForward (-0.05f);
							kern->addEvent (gsevent (GS_CAMERA, c));
							gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
						}
						break;
						
					case 'S':
						{
							c->moveForward (0.05f);
							kern->addEvent (gsevent (GS_CAMERA, c));
							gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));
						}
						break;
				}
			}
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}