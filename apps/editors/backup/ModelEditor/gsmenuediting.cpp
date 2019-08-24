#include "gsmenuediting.h"

namespace gs
{
	gsmenuediting::gsmenuediting (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gswindow (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gsmenuEditingWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		m_pPrimitives = new gsbutton ("Primitives", 0, 0, 100, 30, getHandle (), getInst ());
		m_pTextures = new gsbutton ("Textures", 100, 0, 100, 30, getHandle (), getInst ());
		m_pOptions = new gsbutton ("Options", 200, 0, 100, 30, getHandle (), getInst ());

		m_pLighting = new gsbutton ("Lighting", 0, 30, 100, 30, getHandle (), getInst ());
		m_pShaders = new gsbutton ("Shaders", 100, 30, 100, 30, getHandle (), getInst ());
		m_pTerrain = new gsbutton ("Terrain", 200, 30, 100, 30, getHandle (), getInst ());
		m_pEffect = new gsbutton ("Effect", 0, 60, 100, 30, getHandle (), getInst ());
		m_pEditing = new gsbutton ("Editing", 100, 60, 100, 30, getHandle (), getInst ());
		//m_pButton6 = new gsbutton ("Button6", 200, 60, 100, 30, getHandle (), getInst ());
	}
	
	gsmenuediting::~gsmenuediting ()
	{
		delete m_pPrimitives;
		delete m_pTextures;
		delete m_pOptions;
		delete m_pLighting;
		delete m_pShaders;
		delete m_pEffect;
		delete m_pEditing;
		delete m_pTerrain;
		//delete m_pButton6;
	}

	void gsmenuediting::onDestroy ()
	{
		delete this;
	}

	void gsmenuediting::onKeyDown (WPARAM wParam, LPARAM lParam)
	{
		switch (wParam)
		{
		case ' ':
			{
				delete this;
			}
			break;
		}
	}

	void gsmenuediting::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == BN_CLICKED)
		{
			int width = GetSystemMetrics (SM_CXSCREEN);
			int height = GetSystemMetrics (SM_CYSCREEN);
			if (m_pPrimitives->getHandle () == (HWND)lParam)
			{
				gstoolsprimitives *prim = new gstoolsprimitives (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW, 
					"primitivewindow", "Primitive Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 300, 400, 600, NULL, getInst ());
				prim->show ();
			}
			else if (m_pTextures->getHandle () == (HWND)lParam)
			{
				gstoolstexturing * text = new gstoolstexturing (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"texturewindow", "Texturing Window", WS_OVERLAPPEDWINDOW,
					width/2 - 150, height/2 - 200, 300, 400, NULL, getInst ());
				text->show ();
			}
			else if (m_pOptions->getHandle () == (HWND)lParam)
			{
				gstoolsoptions *opts = new gstoolsoptions (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"optionswindow", "Options Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 300, 400, 600, NULL, getInst ());
				opts->show ();
			}
			else if (m_pLighting->getHandle () == (HWND)lParam)
			{
				gstoolslighting *lgt = new gstoolslighting (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"lightingwindow", "Lighting Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 300, 400, 600, NULL, getInst ());
				lgt->show ();
			}
			else if (m_pShaders->getHandle () == (HWND)lParam)
			{
				gstoolsshaders *shd = new gstoolsshaders (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"shaderswindow", "Shader Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 300, 400, 600, NULL, getInst ());
				shd->show ();
			}
			else if (m_pTerrain->getHandle () == (HWND)lParam)
			{
				gstoolsterrain *ter = new gstoolsterrain (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"terrainwindow", "Terrain Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 300, 400, 600, NULL, getInst ());
				ter->show ();
			}
			else if (m_pEffect->getHandle () == (HWND)lParam)
			{
				gstoolseffect *eff = new gstoolseffect (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"effectwindow", "Effect Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 300, 400, 600, NULL, getInst ());
				eff->show ();
			}
			else if (m_pEditing->getHandle () == (HWND)lParam)
			{
				gstoolsediting *ed = new gstoolsediting (
					WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
					"editingwindow", "Editing Window", WS_OVERLAPPEDWINDOW,
					width/2 - 200, height/2 - 250, 400, 500, NULL, getInst ());
				ed->show ();
			}

			SendMessage (getHandle (), WM_DESTROY, NULL, NULL);
		}

		SetFocus (getParent ());
	}

	LRESULT CALLBACK gsmenuediting::gsmenuEditingWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gsmenuediting *w = (gsmenuediting*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{			
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;

			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;
					
			case WM_DESTROY:
				w->onDestroy ();
				break;
					
			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
};