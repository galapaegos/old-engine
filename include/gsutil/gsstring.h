#ifndef _gsstring_h_
#define _gsstring_h_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "gsstack.h"
#include "gsqueue.h"

#define DEFAULT_SIZE 512

//TODO: I think I need to do a memcpy instead of a strcpy, in case the string
//has non-ascii characters

namespace gsutil
{
	class GS gsstring
	{
	public:
		gsstring ();
		gsstring (const gsstring &s);
		gsstring (const char *s);
		gsstring (const char &s);
		gsstring (const unsigned char &s);
		gsstring (const short &s);
		gsstring (const unsigned short &s);
		gsstring (const int &i);
		gsstring (const unsigned int &i);
		gsstring (const long &l);
		gsstring (const unsigned long &l);
		gsstring (const float &f);
		gsstring (const double &d);
		~gsstring ();

		// preserves contents
		void resize (const unsigned int &size);

		const char &operator[] (const unsigned int index) const
		{
			return m_Buffer[index];
		}

		char &operator[] (const unsigned int index)
		{
			return m_Buffer[index];
		}

		const char *str () const;

		int find (const gsstring &s) const;
		int find (const char *s) const;
		int find (const char &c) const;

		void remove (const char *s);
		void remove (const gsstring &s);
		void remove (const int &pos);
		void remove (const int &pos, const unsigned int &length);

		gsstring substring (const unsigned int &position, const unsigned int &length) const;

		void clear ();


		//TODO:  should handle the case of two pointers, const char* + const char*
		friend gsstring operator+ (const gsstring &s1, const gsstring &s2)
		{
			gsstring added = s1;
			int pos = s1.size ();
			int len = s2.size ();
			added.resize (pos + len);
			for (int x = 0; x < len; x++)
				added.m_Buffer[x+pos] = s2[x];
			added.m_Buffer[pos + len] = '\0';
			return added;
		}

		friend gsstring operator+ (const gsstring &s1, const int &i)
		{
			gsstring added = s1;
			gsstring temp(i);
			added += temp;
			return added;
		}

		friend gsstring operator+ (const gsstring &s1, const float &f)
		{
			gsstring added = s1;
			gsstring temp(f);
			added += temp;
			return added;
		}

		friend gsstring operator+ (const gsstring &s1, const double &d)
		{
			gsstring added = s1;
			gsstring temp(d);
			added += temp;
			return added;
		}

		// concatenates two strings together, and stores it in the left operand
		gsstring operator+= (gsstring s)
		{
			int pos = size ();
			int len = s.size ();
			resize (pos + len);
			for (int x = 0; x < len; x++)
				m_Buffer[x+pos] = s[x];
			m_Buffer[pos + len] = '\0';
			return (*this);
		}

		gsstring operator+= (const unsigned int &i)
		{
			(*this) += gsstring (i);
			return (*this);
		}

		gsstring operator+= (const int &i)
		{
			(*this) += gsstring (i);
			return (*this);
		}

		gsstring operator+= (const float &f)
		{
			(*this) += gsstring (f);
			return (*this);
		}

		gsstring operator+= (const double &d)
		{
			(*this) += gsstring (d);
			return (*this);
		}

		// copies a string into another string
		gsstring &operator= (const gsstring &s)
		{
			int len = s.size ();
			clear ();
			resize (len);
			for (int x = 0; x < len; x++)
				(*this).m_Buffer[x] = s[x];
			m_Buffer[len] = '\0';
			return (*this);
		}

		gsstring operator= (const char *s)
		{
			int len = (int)strlen (s);
			clear ();
			if (len > DEFAULT_SIZE)
				resize (len);
			for (int x = 0; x < len; x++)
				this->m_Buffer[x] = s[x];
			m_Buffer[len] = '\0';
			return (*this);
		}

		gsstring operator= (const char &c)
		{
			clear ();
			this->m_Buffer[0] = c;
			m_Buffer[1] = '\0';
			return (*this);
		}

		bool operator== (const gsstring &str)
		{
			int x = str.size ();
			if (x != size ())
				return false;

			for (int y = 0; y < x; y++)
			{
				if (m_Buffer[y] != str[y])
					return false;
			}

			return true;
		}

		bool operator== (const gsstring &str) const
		{
			int x = str.size ();
			if (x != size ())
				return false;

			for (int y = 0; y < x; y++)
			{
				if (m_Buffer[y] != str[y])
					return false;
			}

			return true;
		}
		
		bool operator== (const char *str)
		{
			int x = (int)strlen (str);
			if (x != size ())
				return false;

			for (int y = 0; y < x; y++)
			{
				if (m_Buffer[y] != str[y])
					return false;
			}

			return true;
		}

		bool operator!= (const gsstring &str)
		{
			int x = str.size ();
			if (x != size ())
				return true;

			for (int y = 0; y < x; y++)
			{
				if (m_Buffer[y] != str[y])
					return true;
			}

			return false;
		}

		bool operator!= (const char *str)
		{
			int x = (int)strlen (str);
			if (x != size ())
				return true;

			for (int y = 0; y < x; y++)
			{
				if (m_Buffer[y] != str[y])
					return true;
			}

			return false;
		}

		inline int size () const
		{
			return (int)strlen (m_Buffer);
		}
	private:
		char *m_Buffer;
		unsigned int m_iBufferSize;

		void init ();
	};
};

#endif
