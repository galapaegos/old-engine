#ifndef _gsresource_h_
#define _gsresource_h_

#include "gsutil/gsstring.h"
#include "gsgeom/gsobject.h"

namespace gs
{
	class GS gsresource : public gsgeom::gsobject
	{
	public:
		gsresource () { m_iId = -1; }
		virtual ~gsresource () {}

		virtual void load (const gsutil::gsstring &pFilename) = 0;
		virtual void unload () = 0;

		virtual void setId (const int id) { m_iId = id; }
		virtual int getId () { return m_iId; }

		virtual void setResourceId (const int id) { m_iResourceId = id; }
		virtual int getResourceId () { return m_iResourceId; }

	private:
		int m_iId;
		int m_iResourceId;
	};
};

#endif

