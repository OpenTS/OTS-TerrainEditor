#pragma once
#include <iostream>
#include <fstream>
#include "base.h"
#include "Singleton.h"

namespace OTS
{

	class LoggingManager : public Singleton<LoggingManager> 
	{
	public:
		LoggingManager(void);
		~LoggingManager(void);

		static LoggingManager& getSingleton( void );
		static LoggingManager* getSingletonPointer( void );

		void LogMessage(OTS::STRING Message);

	private:
		OTS::STRING _filename;
		std::ofstream _outputStream;
	};
}
