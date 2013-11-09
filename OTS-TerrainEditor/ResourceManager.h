#pragma once
#include "base.h"
#include "Singleton.h"
#include "LoggingManager.h"
#include <vector>

namespace OTS
{
	enum ResourceState
	{
		RESOURCE_UNINITIALISED,
		RESOURCE_INITIALISED
	}; 


	struct ResourceLocation
	{
		OTS::STRING location;
		ResourceState state;
	};

	class ResourceManager :
		public OTS::Singleton<ResourceManager>
	{
	

	public:
		ResourceManager(void);
		~ResourceManager(void);
		ResourceManager* getSingletonPointer();
		ResourceManager& getSingleton();
		
		void AddResourceLocation(OTS::STRING resourceLocation);
		void InitialiseResourceLocations();

	private:
		LoggingManager* _pLogging;
		std::vector<ResourceLocation>* _resourceLocations;

	};
}
