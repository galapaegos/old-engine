#include "ModelEditorToolsPaintPanel.h"

ModelEditorToolsPaintPanel::ModelEditorToolsPaintPanel (gswidget *parent) : 
	gswin::gstabpanel (0, "STATIC", "Paint", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, parent)
{
	m_pPaintBrush = new gswin::gsbutton (this, "Paint", BS_PUSHBUTTON|WS_CHILD, 5, 5, 50, 25);
	add (m_pPaintBrush);

	m_pFillBrush = new gswin::gsbutton (this, "Fill", BS_PUSHBUTTON|WS_CHILD, 60, 5, 50, 25);
	add (m_pFillBrush);

	//m_pPickColor = new gswin::gsbutton ("Color Chooser", BS_PUSHBUTTON|WS_CHILD, 5, 35, 50, 25, this);
	//add (m_pFillBrush);

	m_Color.set (1, 1, 1, 1);

	m_pChar = new gswin::gscheckbox (this, "Char", WS_CHILD, 5, 95, getWidth ()/4 - 10, 25);
	m_pFloat  = new gswin::gscheckbox (this, "Float", WS_CHILD, getWidth ()/4 + 5, 95, getWidth ()/4 - 10, 25);

	gswin::gsdescription *descR = new gswin::gsdescription (this, "Red:", 5, 125, 50, 20);
	m_pR = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 65, 125, 50, 20);

	gswin::gsdescription *descG = new gswin::gsdescription (this, "Green:", 5, 155, 50, 20);
	m_pG = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 65, 155, 50, 20);

	gswin::gsdescription *descB = new gswin::gsdescription (this, "Blue:", 5, 185, 50, 20);
	m_pB = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 65, 185, 50, 20);

	gswin::gsdescription *descA = new gswin::gsdescription (this, "Alpha:", 5, 215, 50, 20);
	m_pA = new gswin::gstextbox (this, "", WS_CHILD|ES_LEFT, 65, 215, 50, 20);

	m_pApply = new gswin::gsbutton (this, "Apply", BS_PUSHBUTTON|WS_CHILD, getWidth ()/2 - 30, getHeight () - 50, 60, 25);
	add (m_pApply);
}

ModelEditorToolsPaintPanel::~ModelEditorToolsPaintPanel ()
{
}

void ModelEditorToolsPaintPanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	/*if ((HWND)lp == m_pPickColor->getHandle ())
	{
		COLORREF custom[16] = {0};
		CHOOSECOLOR cc;
		memset (&cc, 0, sizeof (CHOOSECOLOR));
		cc.lStructSize = sizeof (CHOOSECOLOR);
		cc.Flags = CC_FULLOPEN|CC_ANYCOLOR;
		cc.hwndOwner = getHandle ();
		cc.lpCustColors = custom;

		if (ChooseColor (&cc))
		{
			unsigned long c = cc.rgbResult;

			float r = GetRValue (c) / 255.f;
			float g = GetGValue (c) / 255.f;
			float b = GetBValue (c) / 255.f;

			m_Color.set (r, g, b, 1);
		}
	}*/

	if ((HWND)lp == m_pApply->getHandle ())
	{
		int p1 = 0, p2 = 0, p3 = 0;
		p1 = ModelEditorConfig::get ()->Index.getX ();
		p2 = ModelEditorConfig::get ()->Index.getY ();
		p3 = ModelEditorConfig::get ()->Index.getZ ();

		if (p1 == -1 || p2 == -1 || p3 == -1)
		{
			MessageBox (NULL, "Please select primitive to color", "Message", MB_OK);
			return;
		}

		if ((m_pChar->getStatus () && m_pFloat->getStatus ()) || (!m_pChar->getStatus () && !m_pFloat->getStatus ()))
		{
			MessageBox (NULL, "Please select type of colors", "Message", MB_OK);
			return;
		}
		
		bool isFloat = m_pFloat->getStatus ();

		if (isFloat)
		{
			m_Color.set ((float)atof (m_pR->getText ().str ()), 
						 (float)atof (m_pG->getText ().str ()), 
						 (float)atof (m_pB->getText ().str ()), 
						 (float)atof (m_pA->getText ().str ()));
		}
		else
		{
			float r = (float)atof (m_pR->getText ().str ()) / 255.f;
			float g = (float)atof (m_pG->getText ().str ()) / 255.f;
			float b = (float)atof (m_pB->getText ().str ()) / 255.f;
			float a = (float)atof (m_pA->getText ().str ()) / 255.f;

			m_Color.set (r, g, b, a);
		}

		gsgeom::gsgeometryinfo *g = ModelEditorConfig::get ()->m_pCurrentScene->m_Geometry;
		g->m_vColors[p1] = m_Color;
		g->m_vColors[p2] = m_Color;
		g->m_vColors[p3] = m_Color;
	}
}
