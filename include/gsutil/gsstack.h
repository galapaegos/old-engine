#ifndef _gsstack_h_
#define _gsstack_h_

#include "gstypes.h"

namespace gsutil
{
	template <class T> class GS gsstack
	{
		struct Stack
		{
			Stack *next;
			Stack *prev;
			T data;
		};

	public:
		gsstack () {pTop = NULL; pBot = NULL; m_iSize = 0;}
		~gsstack () {if (pTop != NULL) {while (pTop != NULL) { Stack *p = pTop; pTop = pTop->prev; delete p; } } }

		void push (const T &d)
		{
			Stack *p = new Stack ();
			p->data = d;

			p->next = NULL;
			p->prev = NULL;

			if (pTop == NULL)
			{
				pBot = p;
				pTop = p;
			}
			else
			{
				pTop->next = p;
				p->prev = pTop;

				pTop = p;
			}

			m_iSize ++;
		}

		const T &pop ()
		{
			Stack *p;

			if (pTop != NULL)
			{
				p = pTop;
				pTop->prev;

				T d = p->data;

				delete p;
				m_iSize --;

				return d;
			}
			else
				return NULL;
		}

		int size () { return m_iSize; }

	private:
		Stack *pTop;
		Stack *pBot;

		int m_iSize;
	};
};

#endif
