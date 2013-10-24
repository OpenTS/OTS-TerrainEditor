#include "base.h"
#include "Singleton.h"
#include "ConfigManager.h"
#include "LoggingManager.h"
#include "RenderSystem.h"

#ifndef ROOT_H
#define	ROOT_H

namespace OTS 
{
	class Root : public Singleton<Root> 
	{
	public:
		Root(OTS::STRING& configFile);
		~Root();
		static Root& getSingleton( void );
		static Root*  getSingletonPointer( void );
		void Initialize(OTS::STRING* windowName);
	
		RenderSystem* GetRenderSystem() const { return _pRender; }

	private:
		ConfigManager* _pConfig;
		LoggingManager* _pLogging;
		RenderSystem* _pRender;
		

	};	
}

#endif