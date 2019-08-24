#include "gswindow/gsbox.h"

namespace gswin
{
	gsbox::gsbox (const gswin::GS_ORIENTATION &o, gswidget *parent)
	{
		m_orientation = o;
		m_iCurrentX = 2;
		m_iCurrentY = 2;
		m_iChildren = 0;

		if (parent)
		{
			RECT r;
			GetClientRect (parent->getHandle (), &r);

			resize (r.left, r.top, r.right - r.left - 1, r.bottom - r.top - 1);
		}
		else
			resize (0, 0, 0, 0);
	}

	gsbox::~gsbox ()
	{
	}

	void gsbox::add (gsbox *b)
	{
		int boxx = m_iX;
		int boxy = m_iY;
		int boxw = m_iWidth;
		int boxh = m_iHeight;

		m_iChildren ++;

		switch (m_orientation)
		{
		case gsVERTICAL:
			{
				//configure gsrect
				//Not sure how useful storing this alongside is, but you never know
				gsrect *r = new gsrect;

				int tmpw = 0, tmph = 0;
				b->getDefaultSize (&tmpw, &tmph);

				r->resized = true;
				r->m_iWidth = tmpw;
				r->m_iHeight = tmph;
				r->m_pWindow = NULL;
				r->m_pBox = b;

				m_iCurrentY = 2;
				for (unsigned int i = 0; i < m_ChildArea.getSize (); i++)
				{
					gsrect *r = m_ChildArea[i];

					if (r->resized)
					{
						int tmp = 0;
						if (m_iChildren > 0)
							tmp = (boxh/m_iChildren - 2*(m_iChildren - 1));
						r->m_iHeight = tmp;
						if (r->m_pWindow)
							r->m_pWindow->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentY += tmp;
					}
					else
					{
						if (r->m_pWindow)
							r->m_pWindow->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentY += r->m_iHeight + 2;
					}
				}

				b->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
				m_ChildArea.add (r);
			}
			break;

		case gsHORIZONTAL:
			{
				//configure gsrect
				//Not sure how useful storing this alongside is, but you never know
				gsrect *r = new gsrect;

				int tmpw = 0, tmph = 0;
				b->getDefaultSize (&tmpw, &tmph);

				r->resized = true;
				r->m_iWidth = tmpw;
				r->m_iHeight = tmph;
				r->m_pWindow = NULL;
				r->m_pBox = b;

				m_iCurrentX = 2;
				for (unsigned int i = 0; i < m_ChildArea.getSize (); i++)
				{
					gsrect *r = m_ChildArea[i];

					if (r->resized)
					{
						int tmp = 0;
						if (m_iChildren > 0)
							tmp = (boxw/m_iChildren - 2*(m_iChildren));
						r->m_iWidth = tmp;
						if (r->m_pWindow)
							r->m_pWindow->resize (m_iCurrentX + r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (m_iCurrentX + r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentX += tmp;
					}
					else
					{
						if (r->m_pWindow)
							r->m_pWindow->resize (r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentX += r->m_iWidth + 2;
					}
				}

				b->resize (m_iCurrentX + r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
				m_ChildArea.add (r);
			}
			break;
		}
	}

	void gsbox::add (gswidget *w, const GS_ADDMETHOD &am)
	{
		int boxx = m_iX;
		int boxy = m_iY;
		int boxw = m_iWidth;
		int boxh = m_iHeight;

		m_iChildren ++;

		switch (m_orientation)
		{
		case gsVERTICAL:
			{
				//configure gsrect
				//Not sure how useful storing this alongside is, but you never know
				gsrect *r = new gsrect;
				r->m_pWindow = w;
				r->m_pBox = NULL;

				int tmpw = 0, tmph = 0;
				w->getDefaultSize (&tmpw, &tmph);

				if (w->getWidth () == 0)
				{
					if (boxw > tmpw)
						r->m_iWidth = boxw - 2;
					else
						r->m_iWidth = tmpw;
				}
				else
					r->m_iWidth = w->getWidth () - 2;
					

				if (w->getHeight () == 0)
				{
					if ((am & gsEXPAND) || !tmph)
					{
						r->resized = true;
						if (m_iChildren > 0)
							r->m_iHeight = (boxh/m_iChildren - 2*m_iChildren);
						else
							r->m_iHeight = 0;
					}
					else
					{
						if (w->getResizeH ())
						{
							r->resized = true;
							r->m_iHeight = tmph;
						}
						else
						{
							r->resized = false;
							r->m_iHeight = tmph;
						}
					}
				}
				else
				{
					r->resized = false;
					r->m_iHeight = tmph;
				}

				m_iCurrentY = 2;
				for (unsigned int i = 0; i < m_ChildArea.getSize (); i++)
				{
					gsrect *r = m_ChildArea[i];

					if (r->resized)
					{
						int tmp = 0;
						if (m_iChildren > 0)
							tmp = (boxh/m_iChildren - 2*(m_iChildren - 1));
						r->m_iHeight = tmp;
						if (r->m_pWindow)
							r->m_pWindow->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentY += tmp;
					}
					else
					{
						if (r->m_pWindow)
							r->m_pWindow->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (r->m_iX, m_iCurrentY + r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentY += r->m_iHeight + 2;
					}
				}

				w->resize (w->getX (), m_iCurrentY + w->getY (), r->m_iWidth, r->m_iHeight);
				m_ChildArea.add (r);
			}
			break;

		case gsHORIZONTAL:
			{
				//configure gsrect
				//Not sure how useful storing this alongside is, but you never know
				gsrect *r = new gsrect;
				r->m_pWindow = w;
				r->m_pBox = NULL;

				int tmpw = 0, tmph = 0;
				w->getDefaultSize (&tmpw, &tmph);

				if (w->getWidth () == 0)
				{
					if ((am & gsEXPAND) || !tmpw)
					{
						r->resized = true;
						if (m_iChildren > 0)
							r->m_iWidth = (boxw/m_iChildren - 2*(m_iChildren));
						else
							r->m_iWidth = 0;
					}
					else
					{
						if (w->getResizeW ())
						{
							r->resized = true;
							r->m_iWidth = tmpw;
						}
						else
						{
							r->resized = false;
							r->m_iWidth = tmpw;
						}
					}
				}
				else
				{
					if (w->getResizeW ())
					{
						r->resized = true;
						r->m_iWidth = tmpw;
					}
					else
					{
						r->resized = false;
						r->m_iWidth = tmpw;
					}
				}

				if (w->getHeight () == 0)
					r->m_iHeight = tmph;
				else
					r->m_iHeight = w->getHeight () - 2;

				m_iCurrentX = 2;
				for (unsigned int i = 0; i < m_ChildArea.getSize (); i++)
				{
					gsrect *r = m_ChildArea[i];

					if (r->resized)
					{						
						int tmp = 0;
						if (m_iChildren > 0)
							tmp = (boxw/m_iChildren - 2*(m_iChildren));

						r->m_iWidth = tmp;
						if (r->m_pWindow)
							r->m_pWindow->resize (m_iCurrentX + r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (m_iCurrentX + r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentX += tmp;
					}
					else
					{
						if (r->m_pWindow)
							r->m_pWindow->resize (r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						else if (r->m_pBox)
							r->m_pBox->resize (r->m_iX, r->m_iY, r->m_iWidth, r->m_iHeight);
						m_iCurrentX += r->m_iWidth + 2;
					}
				}

				w->resize (m_iCurrentX + w->getX (), w->getY (), r->m_iWidth, r->m_iHeight);
				m_ChildArea.add (r);
			}
			break;
		}
	}

	void gsbox::resize (const int &x, const int &y, const int &w, const int &h)
	{
		m_iX = x;
		m_iY = y;
		m_iWidth = w;
		m_iHeight = h;

		switch (m_orientation)
		{
		case gsVERTICAL:
			{
				int cury = 2;
				for (unsigned int i = 0; i < m_iChildren; i++)
				{
					gsrect *r = m_ChildArea[i];
					if (r->resized)
					{
						if (m_iChildren > 0)
							r->m_iHeight = (m_iHeight/m_iChildren - 2*m_iChildren);
						else
							r->m_iHeight = 0;
					}

					if (r->m_pWindow)
						r->m_pWindow->resize (r->m_iX, r->m_iY + cury, r->m_iWidth, r->m_iHeight);
					else if (r->m_pBox)
						r->m_pBox->resize (r->m_iX, r->m_iY + cury, r->m_iWidth, r->m_iHeight);

					cury += r->m_iHeight;
					cury += 2;
				}
			}
			break;

		case gsHORIZONTAL:
			{
				int curx = 2;
				for (unsigned int i = 0; i < m_iChildren; i++)
				{
					gsrect *r = m_ChildArea[i];
					if (r->resized)
					{
						if (m_iChildren > 0)
							r->m_iWidth = (m_iWidth/m_iChildren - 2*m_iChildren);
						else
							r->m_iWidth = 0;
					}

					if (r->m_pWindow)
						r->m_pWindow->resize (r->m_iX + curx, r->m_iY, r->m_iWidth, r->m_iHeight);
					else if (r->m_pBox)
						r->m_pBox->resize (r->m_iX + curx, r->m_iY, r->m_iWidth, r->m_iHeight);

					curx += r->m_iWidth;
					curx += 2;
				}
			}
			break;
		}
	}

	void gsbox::getDefaultSize (int *w, int *h)
	{
		int maxw = 0;
		int maxh = 0;
		int curw = 2;
		int curh = 2;

		for (unsigned int x = 0; x < m_ChildArea.getSize (); x++)
		{
			gsrect *r = m_ChildArea[x];
			if (r->m_pWindow && (r->m_pWindow->getWidth () > maxw))
				maxw = r->m_pWindow->getWidth ();
			if (r->m_pWindow && (r->m_pWindow->getHeight () > maxh))
				maxh = r->m_pWindow->getHeight ();
			curw += m_ChildArea[x]->m_iWidth + 2;
			curh += m_ChildArea[x]->m_iHeight + 2;
		}
		switch (m_orientation)
		{
		case gsVERTICAL:
			{
				*w = maxw;
				*h = curh;
			}
			break;

		case gsHORIZONTAL:
			{
				*w = curw;
				*h = maxh;
			}
			break;
		}
	}

	void gsbox::add (const int &space)
	{
		gsrect *r = new gsrect;
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
};
