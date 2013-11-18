#pragma once
#include "base.h"
#include "Singleton.h"
#include "LoggingManager.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <vector>
#include <map>

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
		OTS::STRING _workingDir;

		std::map<OTS::STRING, aiMesh>* _meshList;


	};
}
