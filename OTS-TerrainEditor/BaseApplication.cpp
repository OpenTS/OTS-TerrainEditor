#include "BaseApplication.h"

namespace OTS
{
	BaseApplication::BaseApplication(void) :
		_pRoot(0)
	{
	}


	BaseApplication::~BaseApplication(void)
	{
	}

	void BaseApplication::Run()
	{
		this->_pRoot = new OTS::Root(OTS::STRING("main.cfg"));
		this->_pRoot->Initialize(&OTS::STRING("Test"));
		
		this->_pRoot->GetRenderSystem()->SetViewport(0,0);
		this->_pRoot->GetRenderSystem()->SetBackgroundColor(ColorValue::BLACK);
	}
}

