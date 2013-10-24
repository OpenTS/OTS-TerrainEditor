#include "LoggingManager.h"
#include <time.h>
#include <iomanip>

namespace OTS
{
	template<> LoggingManager* Singleton<LoggingManager>::_singleton = 0;

	LoggingManager* LoggingManager::getSingletonPointer( void )
	{
		return _singleton;
	}

	LoggingManager& LoggingManager::getSingleton( void )
	{
		return (*_singleton);
	}

	LoggingManager::LoggingManager(void)
	{
		this->_filename = "main.log";
		this->_outputStream.open(this->_filename, std::ofstream::out | std::ofstream::app);

		if(this->_outputStream.fail())
		{
			// TODO: Add exception handling
		}
	}


	LoggingManager::~LoggingManager(void)
	{
		this->_outputStream.close();
	}

	void LoggingManager::LogMessage(OTS::STRING Message)
	{
		struct tm *pTime;
		time_t cTime;
		time(&cTime);
		pTime = localtime(&cTime);

		this->_outputStream << std::setw(2) << std::setfill('0') << pTime->tm_hour
							<< ":" << std::setw(2) << std::setfill('0') << pTime->tm_min
							<< ":" << std::setw(2) << std::setfill('0') << pTime->tm_sec
							<< " - " << Message << std::endl;
	}
}