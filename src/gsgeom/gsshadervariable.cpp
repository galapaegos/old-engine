#include <gsgeom/gsshadervariable.h>

namespace gsgeom
{
	gsshadervariable::gsshadervariable ()
	{
	}

	gsshadervariable::gsshadervariable (const gsutil::gsstring &pname, 
		const gsutil::gsstring &ptype, const gsutil::gsstring &pval)
	{
		setName (pname);
		setType (ptype);
		setValue (pval);
	}

	gsshadervariable::~gsshadervariable ()
	{
	}
};

