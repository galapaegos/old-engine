#include "test.h"

// prototypes
HWND				InitInstance(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

/* globals */
int				run = 1;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HWND hWindow;

	hWindow = InitInstance (hInstance, nCmdShow);

	HMENU hMenu = CreateMenu ();
	HMENU hSubMenu = CreateMenu ();
	HMENU hSubSubMenu = CreateMenu ();

	AppendMenu (hSubSubMenu, MF_STRING, 5, "Stuff");

	int x = AppendMenu (hSubMenu, MF_STRING, 0, "Open");
	int y = AppendMenu (hSubMenu, MF_STRING, 1, "Save");
	int z = AppendMenu (hSubMenu, MF_SEPARATOR, 2, "");
	int i = AppendMenu (hSubMenu, MF_STRING|MF_POPUP, (UINT_PTR)hSubSubMenu, "Export");
	int j = AppendMenu (hSubMenu, MF_SEPARATOR, 3, "");
	int k = AppendMenu (hSubMenu, MF_STRING, 4, "Close");

	AppendMenu (hMenu, MF_POPUP, (UINT_PTR)hSubMenu, "&File");


	if (SetMenu (hWindow, hMenu) == false)
		MessageBox (NULL, "unable to set menu", "error", MB_OK);

	while (run == 1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

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
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			{
				run = 0;
				PostQuitMessage(0);
			}
			break;

		case WM_KEYDOWN:
			{
				switch (wParam)
				{
				case VK_ESCAPE:
					run = 0;
					PostQuitMessage (0);
					break;
				}
			}
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}