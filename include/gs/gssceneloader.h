#ifndef _gssceneloader_h_
#define _gssceneloader_h_

#include <string.h>
#include <stdlib.h>

#include <gs/gsresourcemgr.h>

#include <gsutil/gsqueue.h>
#include <gsutil/gsstring.h>
#include <gsutil/gsthread.h>

#include <gsgeom/gslight.h>

//#include <gsscene/gsscenenode.h>

//#include "gswindow/gsprogress.h"

using namespace gsutil;

namespace gs
{
	namespace gssceneloader
	{
		//GS gsgeom::gsscene *read (const gsutil::gsstring &pfile);
		//void readHelper (FILE *f, gsgeom::gsscene *s, gsutil::gsqueue<gsutil::gsstring> &list);
		//void readFile (FILE *pFile, gsutil::gsqueue <gsutil::gsstring> &list, int readAhead=1000);
		//GS void write (gsgeom::gsscene *s, const gsutil::gsstring &pfile);
		//void writeHelper (gsgeom::gsscene *s, FILE *pf, const int &numTabs=0);

		//static gsstring m_strSceneVersion;
	};

	//gssceneloader::m_strSceneVersion = "0.1";
};

/*
/-----------------------------------------------\
| Assumes maximum width of 80 characters		|
\-----------------------------------------------/

[scene version=1.0]
{
    //camera is optional
	[camera]
	{
		[width]x[height] [fov] [near] [far]			|= 800x600 45 1 300
		[pos] [direction]							|= [0 5 5] [0 0 0]
	}
	number of vertices							|= n
	[verts]										|= [0 0 0] \n [0 0 0] \n [0 0 0] \n
	number of colors							|= n
	[colors]									|= [0 0 0] \n [0 0 0] \n [0 0 0] \n
	number of normals							|= n
	[normals]									|= [0 0 0] \n [0 0 0] \n [0 0 0] \n
	[number of textures]						|= n
	{
		[texture name]							|= [texturename.bmp]
		number of texture coordinates			|= n
		[texture coordinates]					|= [0 0] \n [0 0] \n [0 0] \n
	}
	[number of effects]
	[effect]
	{
		type
		-------
		types of effects have not been worked out yet, but multitexturing is one of them
	}
	...repeat for number of textures...
	numlights n									|= n
	[light]										|= n
	{
		[pos]									|= [0 0 0]
		[type]									|= type
		[color]									|= [0 0 0]
		[direction]								|= [0 0 0]
	}
	...repeat for number of lights...

	...repeat for child scenes...
	[scene version=1.0]
	...
}
*/

/*
namespace gs
{
	class GS gssceneloader
	{
	public:
		gssceneloader ();
		~gssceneloader ();

		static gsscene *read (const char *pstr);
		static void write (const char *pstr, gsscene *s);

	private:
		void eatNonNumber (gsqueue<char *> &list);
		void eatBrace (gsqueue<char *> &list);
		void eatSpace (gsqueue<char *> &list);
		void eat (const char character, gsqueue<char *> &list);
		int readInt (gsqueue<char *> &list);
		float readFloat (gsqueue<char *> &list);
		const char *readChar (gsqueue<char *> &list);
		gsvec2f *readVec2f (gsqueue<char *> &list);
		gsvec3f *readVec3f (gsqueue<char *> &list);
		gsvec4f *readVec4f (gsqueue<char *> &list);
		void readVersion (gsqueue<char *> &list);
		void readCamera (gsqueue<char *> &list);
		void readScene (gsqueue<char *> &list);
		void format (gsqueue<char *> &list);

		void writeString (const int depth, const char *str);
		void writeVersion (const int depth, gsscene *s);
		void writeCamera (const int depth, gsscene *s);
		void writeScene (const int depth, gsscene *s);

		gsqueue<char*> m_qFileList;

		gsscene *m_pScene;
	};
};*/

#endif

