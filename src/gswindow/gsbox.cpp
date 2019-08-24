#include "gswindow/gsbox.h"

namespace gswin
{
	gsbox::gsbox (const gswin::GS_ORIENTATION &o, gswidget *parent)
	{
		m_orientation = o;
		m_iChildren = 0;

		RECT r;
		GetClientRect (parent->getHandle (), &r);

		m_iCurrentX = m_iX = r.left;
		m_iCurrentY = m_iY = r.top;
		m_iWidth = r.right - r.left;
		m_iHeight = r.bottom - r.top;
	}

	gsbox::~gsbox ()
	{
	}

	void gsbox::add (gsbox *b, const GS_ADDMETHOD &am)
	{
		//do this later
		gsrect *r = new gsrect;
		r->m_pBox = b;
		r->m_iX = m_iCurrentX;
		r->m_iY = m_iCurrentY;
		m_ChildArea.add (r);
		
		switch (am)
		{
		case gsNONE:
			{
				r->resizes = false;
				switch (m_orientation)
				{
				case gsVERTICAL:
					{
						r->m_iWidth = m_iWidth;
						r->m_iHeight = b->getHeight ();

						unsigned int m_curY = 0;
						unsigned int resizableH = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								else if (area->m_pBox)
								{
									//r->m_iHeight = area->m_pBox->getHeight ();
									r->m_iHeight = resizableH;
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								}
								area->m_iY = m_curY;
								area->m_iHeight = resizableH;

								m_curY += (r->m_iHeight + 2);
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								else if (area->m_pBox)
								{
									area->m_iHeight = area->m_pBox->getHeight ();
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								}
								area->m_iY = m_curY;

								m_curY += (area->m_iHeight + 2);
							}
						}
						m_iCurrentY = m_curY;
					}
					break;

				case gsHORIZONTAL:
					{
						r->m_iWidth = b->getWidth ();
						r->m_iHeight = m_iHeight;

						unsigned int m_curX = 0;
						unsigned int resizableW = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								else if (area->m_pBox)
								{
									area->m_iWidth = area->m_pBox->getWidth ();
									area->m_pBox->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								}
								m_curX += (resizableW + 2);

								area->m_iX = m_curX;
								area->m_iHeight = resizableW;
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								else if (area->m_pBox)
								{
									area->m_iWidth = area->m_pBox->getWidth ();
									area->m_pBox->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								}
								m_curX += (area->m_iWidth + 2);

								area->m_iX = m_curX;
							}
						}
						m_iCurrentX = m_curX;
					}
					break;
				}
			}
			break;

		case gsEXPAND:
			{
				r->resizes = true;
				switch (m_orientation)
				{
				case gsVERTICAL:
					{
						unsigned int m_curY = 0;
						unsigned int resizableH = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								else if (area->m_pBox)
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								m_curY += (resizableH + 2);

								area->m_iY = m_curY;
								area->m_iHeight = resizableH;
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								m_curY += (area->m_iHeight + 2);

								area->m_iY = m_curY;
							}
						}
					}
					break;

				case gsHORIZONTAL:
					{
						unsigned int m_curX = 0;
						unsigned int resizableW = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								m_curX += (resizableW + 2);

								r->m_iX = m_curX;
								r->m_iWidth = resizableW;
							}
							else
							{
								area->m_pWindow->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								m_curX += (area->m_iWidth + 2);

								r->m_iX = m_curX;
							}
						}
					}
					break;
				}
			}
			break;
		}
	}

	void gsbox::add (gswidget *w, const GS_ADDMETHOD &am)
	{
		//
		gsrect *r = new gsrect;
		r->m_pWindow = w;
		m_ChildArea.add (r);

		switch (am)
		{
		case gsNONE:
			{
				r->resizes = false;

				switch (m_orientation)
				{
				case gsVERTICAL:
					{
						int defw, defh;
						w->getDefaultSize (&defw, &defh);
						
						if (w->getWidth ())
							r->m_iWidth = w->getWidth ();
						else
							r->m_iWidth = defw;

						if (w->getHeight ())
							r->m_iHeight = w->getHeight ();
						else
							r->m_iHeight = defh;

						r->m_iX = m_iCurrentX;
						r->m_iY = m_iCurrentY;

						unsigned int m_curY = 0;
						unsigned int resizableH = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								else if (area->m_pBox)
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								m_curY += (resizableH + 2);

								area->m_iY = m_curY;
								area->m_iWidth = resizableH;
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								m_curY += (area->m_iHeight + 2);

								area->m_iY = m_curY;
							}
						}
						m_iCurrentY = m_curY;
					}
					break;

				case gsHORIZONTAL:
					{
						int defw, defh;
						w->getDefaultSize (&defw, &defh);
						
						if (w->getWidth ())
							r->m_iWidth = w->getWidth ();
						else
							r->m_iWidth = defw;

						if (w->getHeight ())
							r->m_iHeight = w->getHeight ();
						else
							r->m_iHeight = defh;

						unsigned int m_curX = 0;
						unsigned int resizableW = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								m_curX += (resizableW + 2);

								area->m_iX = m_curX;
								area->m_iWidth = resizableW;
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								m_curX += (area->m_iWidth + 2);

								area->m_iX = m_curX;
							}
						}
						m_iCurrentX = m_curX;
					}
					break;
				}
			}
			break;

		case gsEXPAND:
			{
				r->resizes = true;

				switch (m_orientation)
				{
				case gsVERTICAL:
					{
						int defw, defh;
						w->getDefaultSize (&defw, &defh);
						
						if (w->getWidth ())
						{
							r->m_iWidth = w->getWidth ();
							r->resizes = false;
						}
						else
							r->m_iWidth = defw;

						if (w->getHeight ())
						{
							r->m_iHeight = w->getHeight ();
						}
						else
							r->m_iHeight = defh;

						unsigned int m_curY = 0;
						unsigned int resizableH = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								else if (area->m_pBox)
								{
									//TODO: grab size of box, shouldn't use resizableH!
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, resizableH);
								}
								m_curY += (resizableH + 2);

								area->m_iY = m_curY;
								area->m_iHeight = resizableH;
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (area->m_iX, m_curY, area->m_iWidth, area->m_iHeight);
								m_curY += (area->m_iWidth + 2);

								area->m_iY = m_curY;
							}
						}
						m_iCurrentY = m_curY;
					}
					break;

				case gsHORIZONTAL:
					{
						int defw, defh;
						w->getDefaultSize (&defw, &defh);
						
						if (w->getWidth ())
						{
							r->m_iWidth = w->getWidth ();
							r->resizes = false;
						}
						else
							r->m_iWidth = defw;

						if (w->getHeight ())
						{
							r->m_iHeight = w->getHeight ();
						}
						else
							r->m_iHeight = defh;

						unsigned int m_curX = 0;
						unsigned int resizableW = calcResizeSize ();
						for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
						{
							gsrect *area = m_ChildArea[x];
							if (area->resizes)
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (m_curX, area->m_iY, resizableW, area->m_iHeight);
								m_curX += (resizableW + 2);

								area->m_iX = m_curX;
								area->m_iWidth = resizableW;
							}
							else
							{
								if (area->m_pWindow)
									area->m_pWindow->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								else if (area->m_pBox)
									area->m_pBox->resize (m_curX, area->m_iY, area->m_iWidth, area->m_iHeight);
								m_curX += (area->m_iWidth + 2);

								area->m_iX = m_curX;
							}
						}
						m_iCurrentX = m_curX;
					}
					break;
				}
			}
			break;
		}
	}

	void gsbox::resize (const int &x, const int &y, const int &w, const int &h)
	{
		m_iCurrentX = m_iX = x;
		m_iCurrentY = m_iY = y;
		m_iWidth = w;
		m_iHeight = h;


		switch (m_orientation)
		{
		case gsHORIZONTAL:
			{
				unsigned int m_curX = m_iCurrentX;
				unsigned int resizableW = calcResizeSize ();
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					gsrect *area = m_ChildArea[x];
					if (area->resizes)
					{
						area->m_pWindow->resize (m_iCurrentX + m_curX, m_iCurrentY, resizableW, area->m_iHeight);
						m_curX += (resizableW + 2);

						area->m_iX = m_iCurrentX + m_curX;
						area->m_iWidth = resizableW;
					}
					else
					{
						if (area->m_pWindow)
							area->m_pWindow->resize (m_iCurrentX + m_curX, m_iCurrentY, area->m_iWidth, area->m_iHeight);
						m_curX += (area->m_iWidth + 2);

						area->m_iX = m_iCurrentX + m_curX;
					}
				}
				m_iCurrentX = m_curX;
			}
			break;

		case gsVERTICAL:
			{
				unsigned int m_curY = m_iCurrentY;
				unsigned int resizableH = calcResizeSize ();
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					gsrect *area = m_ChildArea[x];
					if (area->resizes)
					{
						area->m_pWindow->resize (m_iCurrentX, m_iCurrentY + m_curY, area->m_iWidth, resizableH);
						m_curY += (resizableH + 2);

						area->m_iY = m_iCurrentY + m_curY;
						area->m_iHeight = resizableH;
					}
					else
					{
						if (area->m_pWindow)
							area->m_pWindow->resize (m_iCurrentX, m_iCurrentY + m_curY, area->m_iWidth, area->m_iHeight);
						m_curY += (area->m_iHeight + 2);

						area->m_iY = m_iCurrentY + m_curY;
					}
				}
				m_iCurrentY = m_curY;
			}
			break;
		}
	}

	void gsbox::add (const int &space)
	{
		gsrect *r = new gsrect;
		r->resizes = false;
		switch (m_orientation)
		{
		case gsVERTICAL:
			{
				m_iCurrentY += space + 2;
				r->m_iHeight = space;
			}
			break;

		case gsHORIZONTAL:
			{
				m_iCurrentX += space + 2;
				r->m_iWidth = space;
			}
			break;
		}

		m_ChildArea.add (r);
	}

	unsigned int gsbox::calcResizeSize ()
	{
		unsigned int unresized = 0, resizable = 0;

		switch (m_orientation)
		{
		case gsHORIZONTAL:
			{
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					if (!m_ChildArea[x]->resizes)
						unresized += m_ChildArea[x]->m_iWidth;
					else
						resizable ++;
				}
			}
			break;

		case gsVERTICAL:
			{
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					if (!m_ChildArea[x]->resizes)
						unresized += m_ChildArea[x]->m_iHeight;
					else
						resizable ++;
				}
			}
			break;
		}

		unresized += 2*(m_ChildArea.getSize () - 1);

		if (!resizable)
		{
			if (m_orientation == gsHORIZONTAL)
				return m_iWidth;
			else if (m_orientation == gsVERTICAL)
				return m_iHeight;
		}

		return (m_iWidth - unresized)/resizable;
	}

	unsigned int gsbox::getWidth ()
	{
		switch (m_orientation)
		{
		case gsHORIZONTAL:
			{
				unsigned int m_curX = 0;
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					gsrect *area = m_ChildArea[x];
					m_curX += (area->m_iWidth + 2);
				}
				return m_curX;
			}
			break;

		case gsVERTICAL:
			{
				unsigned int highest = 0;
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					gsrect *area = m_ChildArea[x];
					if (highest < (unsigned int)area->m_iWidth)
						highest = (unsigned int)area->m_iWidth;
				}
				return highest;
			}
			break;
		}

		return 0;
	}

	unsigned int gsbox::getHeight ()
	{
		switch (m_orientation)
		{
		case gsHORIZONTAL:
			{
				unsigned int highest = 0;
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					gsrect *area = m_ChildArea[x];
					if (highest < (unsigned int)area->m_iHeight)
						highest = (unsigned int)area->m_iHeight;
				}
				return highest;
			}
			break;

		case gsVERTICAL:
			{
				unsigned int m_curY = 0;
				for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
				{
					gsrect *area = m_ChildArea[x];
					m_curY += (area->m_iHeight + 2);
				}
				return m_curY;
			}
			break;
		}

		return 0;
	}
};
