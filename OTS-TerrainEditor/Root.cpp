#include "Root.h"

namespace OTS {
	
	template<> Root* Singleton<Root>::_singleton = 0;

	Root* Root::getSingletonPointer( void )
	{
		return _singleton;
	}

	Root& Root::getSingleton( void )
	{
		return (*_singleton);
	}

	Root::Root(OTS::STRING& configFile = OTS::STRING("main.cfg")) :
		_pConfig(0),
		_pLogging(0),
		_pRender(0)
	{
		this->_pLogging = new LoggingManager();

		// Load configuration file
		this->_pLogging->LogMessage("[Root] - Starting up Config Manager.");
		this->_pConfig = new ConfigManager();
		this->_pConfig->LoadConfigFile(configFile);

		this->_pRender = new RenderSystem();
		this->_pRender->Initialize();
	}

	void Root::Initialize(OTS::STRING* windowName)
	{
		this->_pRender->CreateRenderWindow(windowName);
	}

	void Root::Start()
	{
		this->_pRender->RenderFrame();
	}

	Root::~Root()
	{
		delete this->_pRender;
		delete this->_pConfig;
		delete this->_pLogging;
	}
}
