#ifndef _gsarray_h_
#define _gsarray_h_

#include <memory.h>
#include "gstypes.h"

namespace gsutil
{
	template <class T> 
	class GS gsarray
	{
	public:
		gsarray ()
		{
			m_iCurrentArraySize = 4096;
			m_Data = new T[4096];

			m_iSize = 0;
		}
		
		gsarray (const int &size)
		{
			m_iCurrentArraySize = size;
			m_Data = new T[m_iCurrentArraySize+1];

			m_iSize = 0;
		}

		~gsarray ()
		{
			release ();
		}

		inline void add (const T &d)
		{
			if (m_iSize >= m_iCurrentArraySize)
			{
				//every time we need to resize array, we just double the size instead.
				m_iCurrentArraySize *= 2;

				//create a new pointer to the memory, copy memory
				T *p = new T[m_iCurrentArraySize + 1];
				memcpy (p, m_Data, sizeof (T)*m_iSize);

				//delete old pointer, update pointer
				delete [] m_Data;
				m_Data = p;
			}

			m_Data[m_iSize++] = d;
		}

		inline void resize (const unsigned int &newSize=0)
		{
			if (newSize == 0)
				m_iCurrentArraySize = m_iCurrentArraySize*2;

			T *p = new T[m_iCurrentArraySize + 1];
			memcpy (p, m_Data, sizeof (T)*m_iSize);

			//delete old pointer, update pointer
			delete [] m_Data;
			m_Data = p;
		}

		inline void remove (const unsigned int &index)
		{
			if (index >= m_iSize)
				return;

			T *p = new T[m_iCurrentArraySize + 1];
			//copy over section before index
			memcpy (p, m_Data, sizeof (T)*m_iSize - index);

			//copy over section after index
			memcpy (p, m_Data[index+1], sizeof (T)*m_iSize - index - 1);

			delete [] m_Data;
			m_Data = p;
		}

		inline void clear ()
		{
			if (m_iSize == 0)
				return;

			delete [] m_Data;
			m_Data = new T[m_iCurrentArraySize + 1];

			m_iSize = 0;
		}

		inline void release ()
		{
			if (m_iSize == 0)
				return;

			delete [] m_Data;
			m_Data = NULL;

			m_iSize = 0;
		}

		inline T &operator [] (const unsigned int i)
		{
			return m_Data[i];
		}

		inline const T &operator [] (const unsigned int i) const
		{
			return m_Data[i];
		}

		inline unsigned int getSize () const { return m_iSize; }

	private:
		T *m_Data;
		unsigned int m_iSize;
		unsigned int m_iCurrentArraySize;
	};
};

#endif
