#include "ResourceManager.h"

namespace OTS
{
	template<> ResourceManager* Singleton<ResourceManager>::_singleton = 0;

	ResourceManager* ResourceManager::getSingletonPointer( void )
	{
		return _singleton;
	}

	ResourceManager& ResourceManager::getSingleton( void )
	{
		return (*_singleton);
	}

	ResourceManager::ResourceManager(void)
	{
		this->_pLogging = LoggingManager::getSingletonPointer();
		this->_resourceLocations = new std::vector<ResourceLocation>();
	}


	ResourceManager::~ResourceManager(void)
	{
		delete(_resourceLocations);
	}

	
	void ResourceManager::AddResourceLocation( OTS::STRING resourceLocation )
	{
		this->_pLogging->LogMessage("[ResourceManager] - Adding Resource location: " + resourceLocation);
		
		ResourceLocation loc;
		loc.location = resourceLocation;
		loc.state = RESOURCE_UNINITIALISED;
		this->_resourceLocations->push_back(loc);
	}

	void ResourceManager::InitialiseResourceLocations()
	{

	}
}