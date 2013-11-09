#include "base.h"
#include "Singleton.h"
#include "ConfigManager.h"
#include "LoggingManager.h"
#include "RenderSystem.h"
#include "FrameListener.h"
#include "ResourceManager.h"

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
		void Start();
		void SetFrameListener(FrameListener* listener);
		
		ConfigManager* GetConfigManager();
		ResourceManager* GetResourceManager();

		RenderSystem* GetRenderSystem() const { return _pRender; }

	private:
		ConfigManager* _pConfig;
		LoggingManager* _pLogging;
		RenderSystem* _pRender;
		FrameListener* _pFrameListener;
		ResourceManager* _pResourceManager;
		
		bool _keepRendering;

		bool _fireFrameQueued();
	};	
}

#endif