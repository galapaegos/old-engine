#include "test.h"

class gswindowtest : public gs::gswindow
{
public:
	gswindowtest (HINSTANCE hInst) : gswindow (0, "gslistboxtest", "Listbox Test Demo", WS_OVERLAPPEDWINDOW,
		0, 0, 800, 600, NULL, hInst, gswindowtestWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));
		m_iRun = 1;

		m_pListBox = new gslistbox (50, 50, 250, 100, getHandle (), getInst ());
		m_pListBox->add ("Item 1");
		m_pListBox->add ("Item 2");
		m_pListBox->add ("Item 3");
	}

	~gswindowtest ()
	{
	}

	int getRun () { return m_iRun; }

	void onClose ()
	{
		m_iRun = 0;
		PostQuitMessage (0);
	}

	void onCommand (WPARAM wParam, LPARAM lParam)
	{
	}

	void onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			{
				m_iRun = 0;
				PostQuitMessage (0);
			}
			break;
		}
	}

	static LRESULT gswindowtestWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gswindowtest *w = (gswindowtest*)GetWindowLong (hWnd, GWL_USERDATA);

		switch (message) 
		{
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			case WM_CLOSE:
				w->onClose ();
				break;

			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;

			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
private:
	int m_iRun;
	gslistbox *m_pListBox;
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;

	INITCOMMONCONTROLSEX iccex;
	iccex.dwSize = sizeof (INITCOMMONCONTROLSEX);
	iccex.dwICC = ICC_TAB_CLASSES;
	InitCommonControlsEx (&iccex);

	gswindowtest *w = new gswindowtest (hInstance);

	while (w->getRun () == 1)
	{
		if (PeekMessage(&msg, w->getHandle (), 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep (10);
	}

	delete w;

	return 0;
}