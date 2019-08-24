#include "gstoolsprimitives.h"

namespace gs
{
	gstoolsprimitives::gstoolsprimitives (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gswindow (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsPrimitivesWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		//TODO: Need to change this to dynamically generate the buttons
		// You can add your own primitives in, so we need a quick way to add scene nodes
		//as a new primitive.

		//probably want something akin to this: 
		//<config>
		// <primitives>
		//  <button label="/\\">triangle.scene</button>
		//  <button label="|=|">box.scene</button>
		//  <button label="<>">quad.scene</button>
		// </primitives>
		//</config>

		// box
		m_PrimitiveList.add (new gsbutton ("|=|", 0+32*1, 0, 32, 32, getHandle (), getInst ()));

		//square
		m_PrimitiveList.add (new gsbutton ("<>", 0+32*2, 0, 32, 32, getHandle (), getInst ()));

		// triangle
		m_PrimitiveList.add (new gsbutton ("/\\", 0+32*0, 0, 32, 32, getHandle (), getInst ()));
	}
	
	gstoolsprimitives::~gstoolsprimitives ()
	{
		for (int x = 0; x < m_PrimitiveList.getSize (); x++)
			delete m_PrimitiveList[x];
		m_PrimitiveList.clear ();
	}

	void gstoolsprimitives::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == BN_CLICKED)
		{
			for (int x = 0; x < m_PrimitiveList.getSize (); x++)
			{
				if (m_PrimitiveList[x]->getHandle () == (HWND)lParam)
				{
					float dist = gsglobalconfig::get ()->getPrimDist ();

					float w = 0;
					float h = 0;
					//float w = (float)gskernel::get ()->getWidth ();
					//float h = (float)gskernel::get ()->getHeight ();

					gsray r = gskernel::get ()->pickRay (w/2, h/2);
					gsvec3f pos (r.getPos ().getX (), r.getPos ().getY (), r.getPos ().getZ ());
					gsvec3f dir (r.getDir ().getX (), r.getDir ().getY (), r.getDir ().getZ ());
					gsvec3f v = pos + dir*dist;

					gsscene *temp = gsglobalconfig::get ()->getPrimitive (x);

					gsscene *s = new gsscene ();
					s->m_strName = temp->m_strName;
					s->m_iVectorType = gsgeom::gsscene::GS_TRIANGLE;
					for (int x = 0; x < temp->m_vPoints.getSize (); x++)
					{
						gsvec3f *l = temp->m_vPoints[x];
						s->m_vPoints.add (new gsvec3f (v.getX () + l->getX (), 
														v.getY () + l->getY (), 
														v.getZ () + l->getZ ()));
					}
					for (int x = 0; x < temp->m_vColors.getSize (); x++)
						s->m_vColors.add (new gscolor (1, 1, 1, 1));
					gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, s));
					gskernel::get ()->addEvent (gsevent (GS_UPDATE, NULL));

					delete this;
				}
			}
		}
	}

	void gstoolsprimitives::onDestroy ()
	{
		delete this;
	}	
	void gstoolsprimitives::onPaint ()
	{
		PAINTSTRUCT ps;
		BeginPaint (getHandle (), &ps);
		EndPaint (getHandle (), &ps);
	}

	void gstoolsprimitives::onKeyDown (WPARAM wParam, LPARAM lParam)
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
	LRESULT CALLBACK gstoolsprimitives::gstoolsPrimitivesWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsprimitives *w = (gstoolsprimitives*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{
			case WM_PAINT:
				w->onPaint ();
				break;

			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;

			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
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