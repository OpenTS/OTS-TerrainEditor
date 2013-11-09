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
		this->_pResource = this->_pRoot->GetResourceManager();
		
		this->_pRoot->SetFrameListener(this);

		this->addResources();

		this->_pRoot->GetRenderSystem()->SetViewport(0,0);
		this->_pRoot->GetRenderSystem()->SetBackgroundColor(ColorValue(0.2f,0.8f,0.1f,1.0f));
		this->_pRoot->Start();
	}

	bool BaseApplication::FrameStarted( FrameEvent Event )
	{
		return true;
	}

	bool BaseApplication::FrameQueued( FrameEvent Event )
	{
		return true;
	}

	void BaseApplication::addResources()
	{
		ConfigManager* config = this->_pRoot->GetConfigManager();
		
		ConfigManager::SettingsMap* settings = config->GetSettingsSection("Resources");

		if(settings != nullptr)
		{
			for(ConfigManager::SettingsMap::iterator it = settings->begin(); it!=settings->end(); ++it)
			{
				this->_pResource->AddResourceLocation(it->second);
			}
		}
	}

}

