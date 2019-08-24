#ifndef _gsd3d_h_
#define _gsd3d_h_

#include <windows.h>
#include <gstypes.h>
#include <gsgfx/gsrenderer.h>

#include <d3d9.h>
#include <d3d9caps.h>

namespace gsgfx
{
	class GS gsd3d : public gsgfx::gsrenderer
	{
	public:
		gsd3d ();
		~gsd3d ();

		virtual void create (gswin::gswindow *w);
		virtual void reset ();
		virtual void destroy ();

		virtual void beginframe ();
		virtual void endframe ();

		virtual void render (gsgeom::gsgeometrychunk *geometry);

		virtual void makeCurrent ();
		
		virtual void setProjection (const gsgeom::gsmatrix &proj);
		virtual void setView (const gsgeom::gsmatrix &view);

	private:

		LPDIRECT3D9 m_pD3d9;
		LPDIRECT3DDEVICE9 m_pDevice;
	};
};

#endif