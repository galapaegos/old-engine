#include "gsutil/gssystem.h"

namespace gsutil
{
	namespace gssystem
	{
		void getDirectoryList (const gsutil::gsstring &directory, const gsutil::gsstring &ext, gsutil::gsarray <gsutil::gsstring> &items)
		{
			if (directory == "")
				return;
#ifdef WIN32
			WIN32_FIND_DATA findData;
			HANDLE fileHandle;
			gsutil::gsstring search = directory;
			gsutil::gsstring pExt = ext;
			int flag = 1;
			if (pExt != "")
				search += "/*." + pExt;
			fileHandle = FindFirstFile(search.str(), &findData);
			if (fileHandle != INVALID_HANDLE_VALUE)
			{
				while (flag)
				{
					items.add (gsstring (findData.cFileName));
					flag = FindNextFile(fileHandle, &findData);
				}
			}
			else
			{
				char *pMsgBuf;
				char *pDisplayBuf;
				DWORD dw = GetLastError();

				FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
					NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
					(LPTSTR) &pMsgBuf,	0, NULL );

				pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
				wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
				MessageBox(NULL, pDisplayBuf, "Error", MB_OK);
			}
			FindClose(fileHandle);
#else
			//dirent **list;
			//int num = scandir (".", &list, NULL, NULL);
			//for (int j = 0; j < num; j++)
			//{
			//	char *name = list[j]->d_name;
			//	if (strstr (name, "bmp") != 0)
			//	{
			//		char item[256];
			//		strcpy (item, name);

			//		m_pTextureList->add (item);
			//	}

			//	delete list[n];
			//}
			//delete list;
#endif
		}

		unsigned int getDirectorySize (const gsutil::gsstring &directory, const gsutil::gsstring &ext)
		{
			if (directory == "")
				return 0;
#ifdef WIN32
			WIN32_FIND_DATA findData;
			HANDLE fileHandle;
			gsutil::gsstring search = directory;
			gsutil::gsstring pExt = ext;
			int count = 0;
			int flag = 1;
			if (pExt != "")
				search += "/*." + pExt;
			fileHandle = FindFirstFile(search.str(), &findData);
			if (fileHandle != INVALID_HANDLE_VALUE)
			{
				while (flag)
				{
					count ++;
					flag = FindNextFile(fileHandle, &findData);
				}
			}
			else
			{
				char *pMsgBuf;
				char *pDisplayBuf;
				DWORD dw = GetLastError();

				FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
					NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
					(LPTSTR) &pMsgBuf,	0, NULL );

				pDisplayBuf = (char*)LocalAlloc(LMEM_ZEROINIT, strlen(pMsgBuf)+40); 
				wsprintf(pDisplayBuf, "Failed with error %d: %s", dw, pMsgBuf); 
				MessageBox(NULL, pDisplayBuf, "Error", MB_OK);
			}
			FindClose(fileHandle);

			return count;
#else
			dirent **list;
			int num = scandir (".", &list, NULL, NULL);
			for (int j = 0; j < num; j++)
			{
				char *name = list[j]->d_name;
				if (strstr (name, "bmp") != 0)
				{
					char item[256];
					strcpy (item, name);

					//m_pTextureList->add (item);
				}

				delete list[j];
			}
			delete list;
#endif
		}

		gsutil::gsstring GS getCurrentDirectory ()
		{
			gsutil::gsstring temp;

#ifdef WIN32
			char t[256];
			GetCurrentDirectory (255, t);

			temp = t;
#endif

			return temp;
		}
	};
};
