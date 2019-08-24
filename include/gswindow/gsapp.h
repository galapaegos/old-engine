#ifndef _gsapp_h_
#define _gsapp_h_

#include <gswindow/gswindow.h>

#define MAINAPP(x)\
	int main (int argc, char *argv[])\
	{\
		x *a = new x;\
		a->onInit ();\
		a->onHandle ();\
		a->onClose ();\
		delete a;\
	}

#define MAINAPPW32(x)\
	int __stdcall WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)\
	{\
		AllocConsole ();\
		freopen("conout$", "w", stdout);\
		freopen("conout$", "w", stderr);\
		x *a = new x;\
		a->onInit ();\
		a->onHandle ();\
		a->onClose ();\
		delete a;\
		return 0;\
	}

namespace gswin
{
	class GS gsapp
	{
	public:
		gsapp ();
		virtual ~gsapp ();

		void onInit ();
		void onHandle ();
		void onClose ();
	};
};

#endif
