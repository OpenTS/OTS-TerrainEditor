#include "ResourceManager.h"

namespace OTS
{
	template<> ResourceManager* Singleton<ResourceManager>::_singleton = 0;

	ResourceManager::ResourceManager(void)
	{
	}


	ResourceManager::~ResourceManager(void)
	{
	}

}