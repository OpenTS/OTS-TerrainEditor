#pragma once
#include "base.h"
#include "Root.h"

namespace OTS
{
	class BaseApplication : FrameListener
	{
	public:
		BaseApplication(void);
		~BaseApplication(void);
		void Run();

		virtual bool FrameStarted( FrameEvent Event );

		virtual bool FrameQueued( FrameEvent Event );

	private:
		OTS::Root* _pRoot;
		OTS::ResourceManager* _pResource;

		void addResources();
	};
}
