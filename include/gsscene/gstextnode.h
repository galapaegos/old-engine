#ifndef _gstextnode_h_
#define _gstextnode_h_

#include <gsutil/gsstring.h>

#include <gsgeom/gscolor.h>
#include <gsgeom/gsvector.h>

#include <gsscene/gsscenenode.h>

namespace gsscene
{
	class GS gstextnode : public gsscene::gsscenenode
	{
	public:
		gstextnode ();
		virtual ~gstextnode ();

		gsgeom::gscolor getColour ();
		gsgeom::gsvec3f getPosition ();
		gsutil::gsstring getString ();

		virtual void render (gsgfx::gsrenderer *renderer);

		void setColour (const gsgeom::gscolor &colour);
		void setPosition (const gsgeom::gsvec3f &pos);
		void setString (const gsutil::gsstring &text);

	protected:
		gsgeom::gsvec3f m_Position;
		gsgeom::gscolor m_Colour;
		gsutil::gsstring m_Text;
	};
};

#endif
