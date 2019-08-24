#ifndef _gssingleton_h_
#define _gssingleton_h_

#include "gstypes.h"

namespace gsutil
{
	/**
	 * \ingroup Galapaegos3D
	 *
	 * \brief Singleton class
	 * \par requirements
	 *
	 * \version 1.0
	 * first version
	 *
	 * \date 03-22-2004
	 *
	 * \author Brad Hittle
	 *
	 * \par license
	 * This code is absolutely free to use and modify. The code is provided "as is" with
	 * no expressed or implied warranty. The author accepts no liability if it causes
	 * any damage to your computer, causes your pet to fall ill, increases baldness
	 * or makes your car start emitting strange noises when you start it up.
	 * This code has no bugs, just undocumented features!
	 * 
	 * \todo 
	 *
	 * \bug 
	 *
	 * \warning
	 *
	 */
	template <typename T> class GS gssingleton
	{
		static T *m_pSingleton;
		
	public:
		/**
		* \brief Constructor
		* Initializes the gSingleton object to default values 
		*/
		gssingleton () { }
		/**
		* \brief Destructor
		* Frees all memory that is still allocated for the gSingleton object
		*/
		~gssingleton () { m_pSingleton = 0; }
		
		/**
		 * \brief Get the instance of the object
		 * \return Address to the object
		 */
		static T* get () { return m_pSingleton; }
		static void set (T *obj) { m_pSingleton = obj; }
	};
	
	template <typename T> T* gssingleton<T>::m_pSingleton = 0;
};

#endif
