#include <iostream>
#include <fstream>
#include "ConfigManager.h"

namespace OTS
{
	template<> ConfigManager* Singleton<ConfigManager>::_singleton = 0;

	ConfigManager* ConfigManager::getSingletonPointer( void )
	{
		return _singleton;
	}

	ConfigManager& ConfigManager::getSingleton( void )
	{
		return (*_singleton);
	}

	ConfigManager::ConfigManager()
	{
		this->_pLoggingManager = LoggingManager::getSingletonPointer();
		this->_pSectionMap = new SectionMap();
		this->_delimiter = OTS::STRING("=");
	}

	ConfigManager::~ConfigManager(void)
	{
		delete _pSectionMap;
	}

	void ConfigManager::LoadConfigFile(OTS::STRING& filename)
	{
		std::ifstream inputStream;
		OTS::STRING sectionName;
		SettingsMap* settings = new SettingsMap();
		
		this->_pLoggingManager->LogMessage("[ConfigManager] - Loading config file: " + filename);

		inputStream.open(filename);

		if(inputStream.fail())
		{
			// TODO: Create some error messages
			// TODO: Log error
			throw 20;
		}

		while (!inputStream.eof())
		{
			OTS::STRING line;
			
			std::getline(inputStream,line);

			// Check line
			switch (line[0])
			{
				// Check for section
				case '[':
					if (!sectionName.empty())
					{
						this->_pSectionMap->insert(std::pair<OTS::STRING, SettingsMap>(sectionName, *settings));
						settings = new SettingsMap();
					}

					sectionName = line.substr(1, line.length() - 2);
					break;
				// Check for comment
				case '#':
					break;
				default:
					int position = line.find(this->_delimiter);

					if(!(position == std::string::npos))
					{
						settings->insert(std::pair<OTS::STRING, OTS::STRING>(line.substr(0, position),
									line.substr(position+1)));
					}

					break;
			}
		}

		// check if there is a sectionmap left
		if(!sectionName.empty())
		{
			this->_pSectionMap->insert(std::pair<OTS::STRING, SettingsMap>(sectionName, *settings));
		}
	}

	OTS::ConfigManager::SettingsMap* ConfigManager::GetSettingsSection( OTS::STRING section )
	{
		SectionMap::iterator it = this->_pSectionMap->find(section);

		if(it == this->_pSectionMap->end())
		{
			return NULL;
		}
		else
		{
			return &it->second;
		}
	}

	OTS::STRING ConfigManager::GetSetting(OTS::STRING section, OTS::STRING settingName)
	{
		OTS::ConfigManager::SettingsMap* settings = this->GetSettingsSection(section);

		if(settings == NULL)
		{
			return NULL;
		}
		else
		{
			return settings->find(settingName)->second;
		}
	}
}