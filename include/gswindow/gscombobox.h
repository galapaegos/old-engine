#ifndef _gscombobox_h_
#define _gscombobox_h_

#include "gscontrol.h"
#include "gsutil/gsqueue.h"
#include "gsimage/gstexture.h"

namespace gswin
{
#ifdef WIN32
	enum
	{
		gsCOMBOBOX_AUTOHSCROLL = CBS_AUTOHSCROLL,
		gsCOMBOBOX_DISABLENOSCROLL = CBS_DISABLENOSCROLL,
		gsCOMBOBOX_DROPDOWN = CBS_DROPDOWN,
		gsCOMBOBOX_DROPDOWNLIST = CBS_DROPDOWNLIST,
		gsCOMBOBOX_HASSTRINGS = CBS_HASSTRINGS,
		gsCOMBOBOX_LOWERCASE = CBS_LOWERCASE,
		gsCOMBOBOX_NOINTEGRALHEIGHT = CBS_NOINTEGRALHEIGHT,
		gsCOMBOBOX_OEMCONVERT = CBS_OEMCONVERT,
		gsCOMBOBOX_OWNERDRAWFIXED = CBS_OWNERDRAWFIXED,
		gsCOMBOBOX_OWNERDRAWVARIABLE = CBS_OWNERDRAWVARIABLE,
		gsCOMBOBOX_SIMPLE = CBS_SIMPLE,
		gsCOMBOBOX_SORT = CBS_SORT,
		gsCOMBOBOX_UPPERCASE = CBS_UPPERCASE
	};
#endif

	class gscombobox : public gscontrol
	{
	public:
		gscombobox (gswidget *parent, const gsutil::gsstring &title="", long style=gsCOMBOBOX_SIMPLE, const int &id=-1,
			const int x=0, const int y=0, const int w=100, const int h=40);
		virtual ~gscombobox ();

		void add (const gsutil::gsstring &pItem);
		void add (gsimage::gstexture *pBitmap);
		void add (gsimage::gstexture *pBitmap, const gsutil::gsstring &pItem);

		void remove (int index);

		int getSelected ();
		gsutil::gsstring getSelectedItem ();

		inline int getSize () { return m_iSize; }

	private:
		int m_iSize;
	};
};

#endif
