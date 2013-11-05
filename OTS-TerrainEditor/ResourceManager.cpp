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
	}


	ResourceManager::~ResourceManager(void)
	{
	}

}