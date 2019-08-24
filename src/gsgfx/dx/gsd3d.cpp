#include "gsgfx/dx/gsd3d.h"

namespace gsgfx
{
	gsd3d::gsd3d ()
	{
		m_pD3d9 = Direct3DCreate9 (D3D_SDK_VERSION);
	}

	gsd3d::~gsd3d ()
	{
		m_pD3d9->Release ();
	}

	void gsd3d::create (gswin::gswindow *w)
	{
		m_pD3d9 = Direct3DCreate9 (D3D_SDK_VERSION);
		if (!m_pD3d9)
			return;

		D3DPRESENT_PARAMETERS pp;
		memset (&pp, 0, sizeof (D3DPRESENT_PARAMETERS));
		pp.Windowed = TRUE;
		pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		pp.BackBufferFormat = D3DFMT_UNKNOWN;
		
		m_pD3d9->CreateDevice (D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, (HWND)w->getHandle (), D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &m_pDevice);
		if (!m_pDevice)
			return;
	}

	void gsd3d::destroy ()
	{
		m_pDevice->Release ();
	}

	void gsd3d::reset ()
	{
	}

	void gsd3d::beginframe ()
	{
		m_pDevice->Clear (0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0);
	}

	void gsd3d::endframe ()
	{
		m_pDevice->Present (NULL, NULL, NULL, NULL);
	}

	void gsd3d::render (gsgeom::gsgeometrychunk *buffer)
	{
	}

	void gsd3d::makeCurrent ()
	{
	}
	
	void gsd3d::setProjection (const gsgeom::gsmatrix &proj)
	{
	}
	
	void gsd3d::setView (const gsgeom::gsmatrix &view)
	{
	}
};
