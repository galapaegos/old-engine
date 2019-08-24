#ifndef _gstexture_h_
#define _gstexture_h_

#include <gsutil/gslogger.h>
#include <gsutil/gsstring.h>

namespace gsimage
{
	class GS gstexture
	{
	public:
		gstexture ();
		~gstexture ();

		void load (const gsutil::gsstring &pstr);
		void unload ();

		unsigned char *getData ();

		void set (const int &w, const int &h, const int &b);

		const int getWidth ();
		const int getHeight ();
		const int getBit ();

		void setPixel (const int &x, const int &h, char *data);

		gsutil::gsstring getName ();

		void setId (const int &id);
		int getId ();

	protected:
		gsutil::gsstring m_strName;
		unsigned char *m_pData;

		int	m_iType;

		int	m_iWidth;
		int	m_iHeight;
		int	m_iBits;
	};
};

#endif

