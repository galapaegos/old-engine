#ifndef _gstoolsterrain_h_
#define _gstoolsterrain_h_

#include "gstabpanel.h"
#include "gsbutton.h"
#include "gsgroup.h"
#include "gstextbox.h"
#include "gsdescription.h"

namespace gs
{
	class gstoolsterrain : public gstabpanel
	{
	public:
		gstoolsterrain (DWORD exStyle, const char *pclass, const char *ptitle, DWORD style,
			const int x, const int y, const int w, const int h,
			HWND hParent, HINSTANCE hInstance);
		~gstoolsterrain ();

		virtual void onKeyDown (WPARAM wParam, LPARAM lParam);
		virtual void onCommand (WPARAM wParam, LPARAM lParam);

		static LRESULT CALLBACK gstoolsTerrainWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	private:
		//Bounding Box dimensions
		gstextbox *m_pWidth, *m_pHeight, *m_pDepth;

		//Bounding Box location
		gstextbox *m_pX, *m_pY, *m_pZ;

		//triangle size
		gstextbox *m_pPrimitiveSize;

		//To generate a landscape within the bounding box, specify a texture
		gsbutton *m_pHeightMap;
		gsstring m_strHeightFile;

		//Ok, cancel
		gsbutton *m_pOk, *m_pCancel;
	};
};

#endif