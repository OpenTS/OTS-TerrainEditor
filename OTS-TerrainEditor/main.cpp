#include "windows.h"
#include "BaseApplication.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
{
	OTS::BaseApplication* app = new OTS::BaseApplication();
	app->Run();
}


