#include <gsscene/gstextnode.h>

namespace gsscene
{
	gstextnode::gstextnode ()
	{
	}

	gstextnode::~gstextnode ()
	{
	}

	gsgeom::gscolor gstextnode::getColour ()
	{
		return m_Colour;
	}

	gsgeom::gsvec3f gstextnode::getPosition ()
	{
		return m_Position;
	}

	gsutil::gsstring gstextnode::getString ()
	{
		return m_Text;
	}

	void gstextnode::render (gsgfx::gsrenderer *renderer)
	{
		gsscenenode::render (renderer);

		renderer->drawText (m_Position, m_Colour, m_Text);
	}

	void gstextnode::setColour (const gsgeom::gscolor &colour)
	{
		m_Colour = colour;
	}

	void gstextnode::setPosition (const gsgeom::gsvec3f &pos)
	{
		m_Position =  pos;
	}

	void gstextnode::setString (const gsutil::gsstring &text)
	{
		m_Text = text;
	}
};
