#ifndef _gsqueue_h_
#define _gsqueue_h_

#include <memory.h>
#include "gstypes.h"

namespace gsutil
{
	template <class T> class GS gsqueue
	{
		class Container
		{
		public:
			Container () { next = NULL; prev = NULL; }
			~Container () { }

			Container *next;
			Container *prev;

			//Crashes because its stupid
			T data;
		};

	public:
		gsqueue () { pHead = NULL; pTail = NULL; m_iSize = 0; }
		~gsqueue () { if (pHead != NULL) clear (); }

		inline void add (const T &d)
		{
			Container *p = new Container;
			p->data = d;
			p->next = NULL;
			p->prev = NULL;

			if (pHead == NULL)
			{
				pHead = p;
				pTail = p;
			}
			else
			{
				p->next = pTail;
				pTail->prev = p;
				pTail = p;
			}

			m_iSize ++;
		}

		inline void erase (const unsigned int &index)
		{
			Container *node = pHead;
			for (unsigned int x = 0; x < index; x++)
				node = node->prev;
			
			Container *prev = node->prev;
			Container *next = node->next;

			delete node;

			m_iSize --;

			if ((next == NULL) && (prev == NULL))
			{
				pHead = NULL;
				pTail = NULL;
			}
			else if (next == NULL)
			{
				pHead = prev;
				prev->next = NULL;
			}
			else if (prev == NULL)
			{
				pTail = next;
				next->prev = NULL;
			}
			else
			{
				next->prev = prev;
				prev->next = next;
			}
		}

		inline void clear ()
		{
			if (m_iSize == 0)
				return;

			Container *node = pHead;

			while (node != NULL)
			{
				Container *temp = node;
				node = node->prev;
				delete temp;
			}

			pHead = NULL;
			pTail = NULL;

			m_iSize = 0;
		}

		inline T &operator [] (const unsigned int &i)
		{
			Container *node = pHead;
			for (unsigned int x = 0; x < i; x++)
				node = node->prev;
				
			return node->data;
		}
		
		inline const T &operator [] (const unsigned int &i) const
		{
			Container *node = pHead;
			for (unsigned int x = 0; x < i; x++)
				node = node->prev;
				
			return node->data;
		}

		inline unsigned int getSize () const { return m_iSize; }

	private:
		Container *pHead;
		Container *pTail;

		unsigned int m_iSize;
	};
};

#endif
