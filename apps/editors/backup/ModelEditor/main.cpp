#include "main.h"

/* prototypes */
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;

	gsglobalconfig *pconfig = new gsglobalconfig ();
	gsglobalconfig::set (pconfig);

	pconfig->loadConfig ();
	
	INITCOMMONCONTROLSEX iccex;
	iccex.dwSize = sizeof (INITCOMMONCONTROLSEX);
	iccex.dwICC = ICC_TAB_CLASSES|ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx (&iccex);

	int width = GetSystemMetrics (SM_CXSCREEN);
	int height = GetSystemMetrics (SM_CYSCREEN);
	int frameHeight = GetSystemMetrics (SM_CYCAPTION) + GetSystemMetrics (SM_CYMENU) + GetSystemMetrics (SM_CYSIZEFRAME);

	gsmainwindow *w = new gsmainwindow (0, "galapaegos", "World Editor", WS_OVERLAPPEDWINDOW|WS_MAXIMIZE,
		CW_USEDEFAULT, 0, width, height, NULL, hInstance);
	//gsstatuswindow *u = new gsstatuswindow (WS_EX_TOOLWINDOW, "gsstatuswindow", "Status", TCS_MULTILINE|WS_OVERLAPPEDWINDOW,
	//	0, height*3/4 + frameHeight, width, height/4 - 2*frameHeight, w->getHandle (), hInstance);
	gsworld *o = new gsworld (0, "gsworldoverlay", "World", WS_POPUP,
		0, frameHeight, width, height, w->getHandle (), hInstance);
	//gstoolswindow *t = new gstoolswindow (WS_EX_TOOLWINDOW, "gstoolswindow", "Tools", TCS_MULTILINE|WS_OVERLAPPEDWINDOW,
	//	0, frameHeight, width/4, height*3/4, w->getHandle (), hInstance);
	o->init ();

	RedrawWindow (w->getHandle (), NULL, NULL, RDW_INTERNALPAINT|RDW_NOCHILDREN);

	while (w->m_iRun == 1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			o->render ();
	}

	delete o;
	//delete u;
	delete w;

	delete pconfig;

	return (int)msg.wParam;
}