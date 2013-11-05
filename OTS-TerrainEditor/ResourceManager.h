#pragma once
#include "base.h"
#include "Singleton.h"

namespace OTS
{

	class ResourceManager :
		public OTS::Singleton<ResourceManager>
	{
	

	public:
		ResourceManager(void);
		~ResourceManager(void);
		ResourceManager* getSingletonPointer();
		ResourceManager& getSingleton();
		void AddResourceLocation(OTS::STRING* resourceLocation);
	};
}
