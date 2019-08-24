#ifndef _gswinbox_h_
#define _gswinbox_h_

#include <gswindow/gscontrol.h>

namespace gswin
{
	enum GS_ORIENTATION
	{
		gsVERTICAL,
		gsHORIZONTAL
	};

	//by default, if no size is used it will expand the widget to the edge
	//it will use the default size if gsNONE is used, and
	//gsEXPAND will expand it all the way
	enum GS_ADDMETHOD
	{
		gsNONE = 0,
		gsEXPAND, //in a vertical box, this expands horizontally,
				  //in a horizontal box, it expands vertically
		gsRESIZE, //expands in both directions
	};

	class gsbox
	{
	public:
		gsbox (const GS_ORIENTATION &o, gswidget *parent);
		virtual ~gsbox ();

		virtual void add (gsbox *b, const GS_ADDMETHOD &am=gsNONE);
		virtual void add (gswidget *w, const GS_ADDMETHOD &am=gsNONE);
		virtual void add (const int &space);

		unsigned int getWidth ();
		unsigned int getHeight ();

		unsigned int getOrientation () { return m_orientation; }

		virtual void resize (const int &x, const int &y, const int &w, const int &h);

	protected:
		unsigned int calcResizeSize ();

		class gsrect
		{
		public:
			gsrect () : m_iX (0), m_iY (0), m_iWidth (0), m_iHeight (0), m_pWindow (NULL), m_pBox (NULL), resizes (false) {}
			int m_iWidth, m_iHeight;
			int m_iX, m_iY;
			bool resizes;
			gswidget *m_pWindow;
			gsbox *m_pBox;
		};

		unsigned int m_orientation;

		//area of child widget
		gsutil::gsqueue <gsrect*> m_ChildArea;

		int m_iX, m_iY, m_iWidth, m_iHeight;
		int m_iCurrentX, m_iCurrentY;
		unsigned int m_iChildren;
	};
};

#endif
