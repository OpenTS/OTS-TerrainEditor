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
		this->_resourceLocations = new std::vector<ResourceLocation>();
	}


	ResourceManager::~ResourceManager(void)
	{

	}

	void ResourceManager::AddResourceLocation( OTS::STRING* resourceLocation )
	{
		ResourceLocation loc;
		loc.location = resourceLocation;
		loc.state = RESOURCE_UNINITIALISED;
		this->_resourceLocations->push_back(loc);
	}

	void ResourceManager::InitialiseResourceLocations()
	{

	}
}