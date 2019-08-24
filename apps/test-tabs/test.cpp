#include "test.h"

class window : public gswin::gswindow
{
public:
	window () : gswin::gswindow (0, "window", "Test", WS_BORDER|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX, 0, 0, 800, 600)
	{
		m_pTabCtrl = new gswin::gstabctl (0, "Title", WS_CHILD|WS_VISIBLE, this);
		add (m_pTabCtrl);

		m_pTab1 = new gswin::gstabpanel (0, "STATIC", "tab 1", WS_GROUP|WS_CHILD, m_pTabCtrl);
		m_pTabCtrl->add (m_pTab1);
		m_pTab1->show ();

		m_pTab2 = new gswin::gstabpanel (0, "STATIC", "tab 2", WS_GROUP|WS_CHILD, m_pTabCtrl);
		m_pTabCtrl->add (m_pTab2);
		m_pTab2->hide ();

		m_pTabCtrl->show ();
	}

	virtual ~window () {}

	virtual void handle ()
	{
		while (m_iRun == 1)
		{
			gswindow::handle ();
		}
	}

	virtual void onClose ()
	{
		m_iRun = 0;
	}

private:
	gswin::gstabctl *m_pTabCtrl;
	gswin::gstabpanel *m_pTab1;
	gswin::gstabpanel *m_pTab2;
};

int main (int argc, char *argv[])
{
	INITCOMMONCONTROLSEX cc;
	cc.dwSize = sizeof (INITCOMMONCONTROLSEX);
	cc.dwICC = ICC_TAB_CLASSES|ICC_PROGRESS_CLASS;
	if (!InitCommonControlsEx (&cc))
		MessageBox (NULL, "unable to init common controls", "msg", MB_OK);

	window *w = new window;

	w->handle ();

	return 0;
}
