#include "gstoolsterrain.h"

namespace gs
{
	gstoolsterrain::gstoolsterrain (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style, 
		const int x, const int y, const int w, const int h, HWND hParent, HINSTANCE hInstance) :
	gstabpanel (exStyle, pclass, ptitle, style, 
		x, y, w, h, hParent, hInstance, gstoolsTerrainWndProc)
	{
		SetWindowLong (getHandle (), GWL_USERDATA, reinterpret_cast<LONG>(this));

		gsdescription *widthDesc = new gsdescription ("Width: ", 15, 15, 50, 20, getHandle (), getInst ());
		m_pWidth = new gstextbox ("", 75, 15, 45, 20, getHandle (), getInst ());
		gsdescription *heightDesc = new gsdescription ("Height: ", 130, 15, 50, 20, getHandle (), getInst ());
		m_pHeight = new gstextbox ("", 190, 15, 45, 20, getHandle (), getInst ());
		gsdescription *depthDesc = new gsdescription ("Depth: ", 245, 15, 50, 20, getHandle (), getInst ());
		m_pDepth = new gstextbox ("", 305, 15, 45, 20, getHandle (), getInst ());

		gsdescription *bbX = new gsdescription ("Locate X:", 15, 45, 50, 20, getHandle (), getInst ());
		m_pX = new gstextbox ("", 75, 45, 45, 20, getHandle (), getInst ());
		gsdescription *bbY = new gsdescription ("Locate Y:", 130, 45, 50, 20, getHandle (), getInst ());
		m_pY = new gstextbox ("", 190, 45, 45, 20, getHandle (), getInst ());
		gsdescription *bbZ = new gsdescription ("Locate Z:", 245, 45, 50, 20, getHandle (), getInst ());
		m_pZ = new gstextbox ("", 305, 45, 45, 20, getHandle (), getInst ());

		gsdescription *psDesc = new gsdescription ("Primitive Size", 15, 75, 120, 20, getHandle (), getInst ());
		m_pPrimitiveSize = new gstextbox ("1", 145, 75, 45, 20, getHandle (), getInst ());
		m_pHeightMap = new gsbutton ("Height Map", 15, 105, 80, 20, getHandle (), getInst ());

		m_pOk = new gsbutton ("Ok", w/4 - 40 + 5, h - 60, 80, 25, getHandle (), getInst ());
		m_pCancel = new gsbutton ("Cancel", 3*w/4 - 40 + 5, h - 60, 80, 25, getHandle (), getInst ());

		m_strHeightFile = "";
	}
	
	gstoolsterrain::~gstoolsterrain ()
	{
	}

	void gstoolsterrain::onKeyDown (WPARAM wParam, LPARAM lParam)
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

	void gstoolsterrain::onCommand (WPARAM wParam, LPARAM lParam)
	{
		if (HIWORD (wParam) == BN_CLICKED)
		{
			if (m_pOk->getHandle () == (HWND)lParam)
			{
				gsscene *s = new gsscene;

				float w = (float)atof (m_pWidth->getText ().str ());
				float h = (float)atof (m_pHeight->getText ().str ());
				float d = (float)atof (m_pDepth->getText ().str ());

				float x = (float)atof (m_pX->getText ().str ());
				float y = (float)atof (m_pY->getText ().str ());
				float z = (float)atof (m_pZ->getText ().str ());

				float ps = (float)atof (m_pPrimitiveSize->getText ().str ());

				if (m_strHeightFile != "")
				{
					//TODO: make this float-based, just like other case
					gsimage::gsbmp tex;
					tex.load (m_strHeightFile);
					unsigned char *pData = tex.getData ();

					int texW = tex.getWidth ();
					int texH = tex.getHeight ();

					gsutil::gsqueue<gsvec3f*> pTempVecs;

					//TODO: scale all the heightmap values between the selected heights linearly
					if ((texW == w) && (texH == h) && (ps == 1))
					{
						for (int x = 0; x < texW; x++)
						{
							for (int y = 0; y < texH; y++)
								pTempVecs.add (new gsvec3f ((float)x, (pData[x*texW + y]/255.f), (float)y));
						}
					}
					else
					{
						MessageBox (NULL, "width and height not the same as texture dimensions, unsuppported atm", "Warning", MB_OK);
						
						//gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, s));

						delete this;
					}

					s->m_strName = "terrain";
					for (int a = 0; a < tex.getWidth () - 1; a++)
					{
						for (int b = 0; b < tex.getHeight () - 1; b++)
						{
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + pTempVecs[a*texW + b]->getX (),
								y + pTempVecs[a*texW + b]->getY (),
								z + pTempVecs[a*texW + b]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + pTempVecs[a*texW + b + 1]->getX (),
								y + pTempVecs[a*texW + b + 1]->getY (),
								z + pTempVecs[a*texW + b + 1]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + pTempVecs[a*texW + texW + b]->getX (),
								y + pTempVecs[a*texW + texW + b]->getY (),
								z + pTempVecs[a*texW + texW + b]->getZ ()));

							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + pTempVecs[a*texW + b + 1]->getX (),
								y + pTempVecs[a*texW + b + 1]->getY (),
								z + pTempVecs[a*texW + b + 1]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + pTempVecs[a*texW + texW + b + 1]->getX (),
								y + pTempVecs[a*texW + texW + b + 1]->getY (),
								z + pTempVecs[a*texW + texW + b + 1]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + pTempVecs[a*texW + texW + b]->getX (),
								y + pTempVecs[a*texW + texW + b]->getY (),
								z + pTempVecs[a*texW + texW + b]->getZ ()));
						}
					}

					pTempVecs.clear ();
				}
				else
				{
					s->m_BoundingBox.set (gsvec3f (x, y, z), gsvec3f (x + w, y + h, z + d));

					gsutil::gsqueue <gsgeom::gsvec3f*> temp;

					//lets store all the verts temporarily
					for (float i = 0.f; i < w + ps; i += ps)
					{
						for (float j = 0.f; j < d + ps; j += ps)
							temp.add (new gsvec3f (i, 0.f, j));
					}

					int gw = (int)(w/ps);
					int gh = (int)(h/ps);

					for (int a = 0; a < gw; a++)
					{
						for (int b = 0; b < gh; b++)
						{
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + temp[a*(gw + 1) + b]->getX (), 
								y + temp[a*(gw + 1) + b]->getY (), 
								z + temp[a*(gw + 1) + b]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + temp[a*(gw + 1) + b + 1]->getX (), 
								y + temp[a*(gw + 1) + b + 1]->getY (), 
								z + temp[a*(gw + 1) + b + 1]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + temp[(a+1)*(gw + 1) + b]->getX (), 
								y + temp[(a+1)*(gw + 1) + b]->getY (), 
								z + temp[(a+1)*(gw + 1) + b]->getZ ()));

							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + temp[(a+1)*(gw + 1) + b]->getX (), 
								y + temp[(a+1)*(gw + 1) + b]->getY (), 
								z + temp[(a+1)*(gw + 1) + b]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + temp[a*(gw + 1) + b + 1]->getX (), 
								y + temp[a*(gw + 1) + b + 1]->getY (), 
								z + temp[a*(gw + 1) + b + 1]->getZ ()));
							s->m_Geometry->m_vPoints.add (gsvec3f (
								x + temp[(a+1)*(gw + 1) + b + 1]->getX (), 
								y + temp[(a+1)*(gw + 1) + b + 1]->getY (), 
								z + temp[(a+1)*(gw + 1) + b + 1]->getZ ()));
						}
					}

					while (temp.getSize () > 0)
					{
						delete temp[0];
						temp.erase (0);
					}
				}

				//gskernel::get ()->addEvent (gsevent (GS_ADD_SCENE, s));

				delete this;
			}
			else if (m_pHeightMap->getHandle () == (HWND)lParam)
			{
				OPENFILENAME f;
				char buf[255];
				memset (&f, 0, sizeof (f));
				f.lStructSize = sizeof (f);
				f.hwndOwner = getHandle ();
				f.lpstrFilter = "Bitmaps\0*.bmp\0";
				f.nMaxFile = 256;
				f.lpstrFile = buf;
				f.lpstrFile[0] = '\0';
				f.lpstrInitialDir = ""; //config will store this
				f.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;

				if (GetOpenFileName (&f) != 0)
					m_strHeightFile = (char*)f.lpstrFile;
			}
			else if (m_pCancel->getHandle () == (HWND)lParam)
				delete this;
		}
	}

	LRESULT CALLBACK gstoolsterrain::gstoolsTerrainWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		gstoolsterrain *w = (gstoolsterrain*)GetWindowLong (hWnd, GWL_USERDATA);
		
		switch (message)
		{			
			case WM_KEYDOWN:
				w->onKeyDown (wParam, lParam);
				break;
					
			case WM_DESTROY:
				w->onDestroy ();
				break;
				
			case WM_COMMAND:
				w->onCommand (wParam, lParam);
				break;
					
			default:
				return DefWindowProc (hWnd, message, wParam, lParam);
		}
		
		return 0;
	}
};