#include "ResourceManager.h"
#include "dirent.h"
#include <direct.h>

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
		this->_meshList = new std::map<OTS::STRING, aiMesh>();
		
		char cwd[256];
		_getcwd(cwd, sizeof(cwd));

		this->_workingDir = OTS::STRING(cwd);
	}

	ResourceManager::~ResourceManager(void)
	{
		delete(_meshList);
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
		// Loop through all locations and initialize
		for (std::vector<ResourceLocation>::iterator it = _resourceLocations->begin(); it != _resourceLocations->end(); ++it)
		{
			// Check if resource already been initialized before reloading
			if(it->state == RESOURCE_UNINITIALISED)
			{
				// Loop through all 
				this->_pLogging->LogMessage("[ResourceManager] - Initializing resource location: " + it->location);
				DIR *dir;
				struct dirent *ent;

				dir = opendir(it->location.c_str());

				if(dir != nullptr)
				{
					while((ent = readdir(dir)) != NULL)
					{
						// 32768 means a file is found
						if(ent->d_type == 32768)
						{
							this->_pLogging->LogMessage("");	
						}
					}
				}
			}
		}
	}
}