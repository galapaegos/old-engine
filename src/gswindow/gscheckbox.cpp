#include "gswindow/gscheckbox.h"

namespace gswin
{
	gscheckbox::gscheckbox (gswidget *parent, const gsutil::gsstring &title, unsigned long style, const int &id,
		const int x, const int y, const int w, const int h) : gsbutton (parent, title, style, 
		x, y, w, h)
	{
		m_bCheck = false;
	}

	gscheckbox::~gscheckbox ()
	{
	}

	void gscheckbox::check ()
	{
		SendMessage (getHandle (), BM_SETCHECK, BST_CHECKED, NULL);
		m_bCheck = true;
	}

	void gscheckbox::uncheck ()
	{
		SendMessage (getHandle (), BM_SETCHECK, BST_UNCHECKED, NULL);
		m_bCheck = false;
	}

	void gscheckbox::toggle ()
	{
		if (m_bCheck)
			uncheck ();
		else
			check ();
	}

	bool gscheckbox::getStatus ()
	{
		LRESULT res = SendMessage (getHandle (), BM_GETSTATE, NULL, NULL);

		if (res == BST_CHECKED)
			m_bCheck = true;
		else if (res == BST_UNCHECKED)
			m_bCheck = false;

		return m_bCheck;
	}

};
