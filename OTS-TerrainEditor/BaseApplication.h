#pragma once
#include "base.h"
#include "Root.h"

namespace OTS
{
	class BaseApplication
	{
	public:
		BaseApplication(void);
		~BaseApplication(void);
		void Run();

	private:
		OTS::Root* _pRoot;
	};
}
