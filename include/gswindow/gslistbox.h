#ifndef _gslistbox_h_
#define _gslistbox_h_

#include "gswindow/gscontrol.h"
#include "gsutil/gsqueue.h"
#include "gsimage/gstexture.h"

namespace gswin
{
#ifdef WIN32
	enum
	{
		gsLISTBOX_COMBOBOX = LBS_COMBOBOX,
		gsLISTBOX_DISABLENOSCROLL = LBS_DISABLENOSCROLL,
		gsLISTBOX_EXTENDEDSEL = LBS_EXTENDEDSEL,
		gsLISTBOX_HASSTRINGS = LBS_HASSTRINGS,
		gsLISTBOX_MULTICOLUMN = LBS_MULTICOLUMN,
		gsLISTBOX_MULTIPLESEL = LBS_MULTIPLESEL,
		gsLISTBOX_NODATA = LBS_NODATA,
		gsLISTBOX_NOINTEGRALHEIGHT = LBS_NOINTEGRALHEIGHT,
		gsLISTBOX_NOREDRAW = LBS_NOREDRAW,
		gsLISTBOX_NOSEL = LBS_NOSEL,
		gsLISTBOX_NOTIFY = LBS_NOTIFY,
		gsLISTBOX_OWNERDRAWFIXED = LBS_OWNERDRAWFIXED,
		gsLISTBOX_OWNERDRAWVARIABLE = LBS_OWNERDRAWVARIABLE,
		gsLISTBOX_SORT = LBS_SORT,
		gsLISTBOX_STANDARD = LBS_STANDARD,
		gsLISTBOX_USETABSTOPS = LBS_USETABSTOPS,
		gsLISTBOX_WANTKEYBOARDINPUT = LBS_WANTKEYBOARDINPUT
	};
#endif

	class gslistbox : public gscontrol
	{
	public:
		gslistbox (gswidget *parent, const gsutil::gsstring &windowTitle="", unsigned long style=gsLISTBOX_STANDARD, 
			const int &id=-1, const int &x=0, const int &y=0, const int &w=0, const int &h=0);
		virtual ~gslistbox ();

		void add (const gsutil::gsstring &item);
		void add (gsimage::gstexture *pBitmap);
		void add (gsimage::gstexture *pBitmap, const gsutil::gsstring &item);

		void clear ();
		void remove (int index);

		int getSelected ();
		gsutil::gsstring getSelectedItem ();

		inline int getSize () { return m_iSize; }

		virtual void getDefaultSize (int *w, int *h) { *w = 100; *h = 40; }

	private:
		int m_iSize;
	};
};

#endif
