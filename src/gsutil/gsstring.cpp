#include "gsutil/gsstring.h"

#if _MSC_VER == 1400
#define gcvt _gcvt
#define itoa _itoa
#define ltoa _ltoa
#define ultoa _ultoa
#endif

namespace gsutil
{
	gsstring::gsstring ()
	{
		init ();
	}

	gsstring::gsstring (const gsstring &s)
	{
		init ();
		int len = s.size ();
		clear ();
		if (len > DEFAULT_SIZE)
			resize (len);
		for (int x = 0; x < len; x++)
			(*this).m_Buffer[x] = s[x];
		m_Buffer[len] = '\0';
	}

	gsstring::gsstring (const char *s)
	{
		init ();
		int len = (int)strlen (s);
		clear ();
		if (len > DEFAULT_SIZE)
			resize (len);
		for (int x = 0; x < len; x++)
			this->m_Buffer[x] = s[x];
		m_Buffer[len] = '\0';
	}

	gsstring::gsstring (const char &c)
	{
		init ();
		this->m_Buffer[0] = c;
		m_Buffer[1] = '\0';
	}

	gsstring::gsstring (const short &s)
	{
		init ();
#ifdef WIN32
		itoa (s, m_Buffer, 10);
#else
		sprintf (m_Buffer, "%i", s);
#endif
	}

	gsstring::gsstring (const unsigned short &s)
	{
		init ();
#ifdef WIN32
		itoa (s, m_Buffer, 10);
#else
		sprintf (m_Buffer, "%i", s);
#endif
	}

	gsstring::gsstring (const int &i)
	{
		init ();
#ifdef WIN32
		itoa (i, m_Buffer, 10);
#else
		sprintf (m_Buffer, "%i", i);
#endif
	}

	gsstring::gsstring (const unsigned int &i)
	{
		init ();
#ifdef WIN32
		itoa (i, m_Buffer, 10);
#else
		sprintf (m_Buffer, "%ui", i);
#endif
	}

	gsstring::gsstring (const float &f)
	{
		init ();
#ifdef WIN32
		gcvt ((double)f, 12, m_Buffer);
#else
		sprintf (m_Buffer, "%f", f);
#endif
	}

	gsstring::gsstring (const long &l)
	{
		init ();
#ifdef WIN32
		ltoa (l, m_Buffer, 10);
#else
#endif
	}

	gsstring::gsstring (const unsigned long &l)
	{
		init ();
#ifdef WIN32
		ultoa (l, m_Buffer, 10);
#else
#endif
	}

	gsstring::gsstring (const double &d)
	{
		init ();
#ifdef WIN32
		gcvt ((double)d, 12, m_Buffer);
#else
		sprintf (m_Buffer, "%f", d);
#endif
	}

	gsstring::~gsstring ()
	{
		delete [] m_Buffer;
	}

	const char *gsstring::str () const
	{
		return m_Buffer;
	}

	// This isn't being used for resizing greater than DEFAULT_SIZE
	void gsstring::resize (const unsigned int &size)
	{
		while (m_iBufferSize < size)
			m_iBufferSize *= 2;
		
		char *temp = new char [m_iBufferSize+1];
		strncpy (temp, m_Buffer, (int)strlen (m_Buffer));
		delete [] m_Buffer;
		m_Buffer = temp;
	}

	void gsstring::init ()
	{
		m_Buffer = new char [DEFAULT_SIZE+1];
		memset (m_Buffer, 0, DEFAULT_SIZE);
		m_Buffer[0] = '\0';
		m_iBufferSize = DEFAULT_SIZE;
	}

	int gsstring::find (const gsstring &s) const
	{
		int slen = s.size ();
		int ilen = size ();
		int size = ilen - slen + 1;

		for (int x = 0; x < size; x++)
		{
			if (m_Buffer[x] == s[0])
			{
				bool notFound = false;

				if (slen > 1)
				{
					for (int y = 0; y < slen; y++)
					{
						if (m_Buffer[x + y] != s[y])
							notFound = true;
					}

					if (notFound == false)
						return x;
				}
				else if (slen == 1)
					return x;
			}
		}

		return -1;
	}

	int gsstring::find (const char &c) const
	{
		gsstring s = c;
		return find (s);
	}

	int gsstring::find (const char *c) const
	{
		gsstring s = c;
		return find (s);
	}

	void gsstring::remove (const char *s)
	{
		gsstring temp = s;
		remove (temp);
	}

	void gsstring::remove (const gsstring &s)
	{
		int slen = s.size ();
		int pos = find (s);

		remove (pos, slen);
	}

	// pos starts at 0
	void gsstring::remove (const int &pos)
	{
		int len = (int)strlen (m_Buffer);
		if (pos >= 0)
		{
			for (int x = pos; x < len - 1; x++)
				m_Buffer[x] = m_Buffer[x+1];
			m_Buffer[len - 1] = '\0';
		}
	}

	void gsstring::remove (const int &pos, const unsigned int &length)
	{
		int len = (int)strlen (m_Buffer);
		int dif = len - length;
		if (pos >= 0)
		{
			for (int x = pos; x < dif; x++)
				m_Buffer[x] = m_Buffer[x+length];
			m_Buffer[dif] = '\0';
		}
	}

	gsstring gsstring::substring (const unsigned int &pos, const unsigned int &length) const
	{
		gsstring temp;
		
		//int len = size ();
		if (pos >= 0 && length >= 0)
		{
			char *str = new char [length+1];
			for (unsigned int x = 0; x < length; x++)
				str[x] = m_Buffer[x + pos];
			str[length] = '\0';
			temp = str;
			delete [] str;
		}

		return temp;
	}

	void gsstring::clear ()
	{
		if (m_iBufferSize != DEFAULT_SIZE)
		{
			char *buffer = new char [DEFAULT_SIZE];
			delete [] m_Buffer;
			m_Buffer = buffer;
		}

		memset (m_Buffer, 0, DEFAULT_SIZE);
		m_Buffer[0] = '\0';
	}
};
