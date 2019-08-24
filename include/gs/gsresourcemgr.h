#ifndef _gsresourcemgr_h_
#define _gsresourcemgr_h_

#include <string>
#include "gsutil/gssingleton.h"
#include "gsutil/gsqueue.h"
#include "gssceneloader.h"
#include "gsgeom/gsobject.h"

//texture includes
#include "gsimage/gsbmp.h"
#include "gsimage/gsjpeg.h"
#include "gsimage/gspng.h"
#include "gsimage/gsppm.h"
#include "gsimage/gstga.h"

//scene includes
//#include "gsgeom/gsscene.h"
using namespace gsutil;

namespace gs
{
	// resourcemgr will contain textures, shaders, models, 
	//audio, and anything else that is 'resource' related
	//that I forgot to mention
	class GS gsresourcemgr : public gssingleton<gsresourcemgr>
	{
	public:
		gsresourcemgr ();
		~gsresourcemgr ();

		// returns the guid used for the loaded 'resource'
		int load (const gsutil::gsstring &pstr);
		void load (const gsutil::gsstring &path, const gsutil::gsstring &file);
		void unload (const int resource);

		gsimage::gstexture *getTextureResource (const int id) { if ((id < 0) || (id > m_iResource)) return NULL; return m_pTextures[id]; }

		int findTextureResource (const gsutil::gsstring &file);

	private:
		gsqueue<gsimage::gstexture*> m_pTextures;
		//gsqueue<gsgeom::gsscene*> m_pScenes;

		// Not implemented yet, plan to just read the file in, and
		//then store the file as a string for now.
		//gsqueue<gsshader*> m_pShaders;

		// gsresourcemgr resource id, should only be one
		int m_iResource;
	};
};

#endif

