#pragma once
#include <map>
#include "base.h"
#include "Singleton.h"
#include "LoggingManager.h"

namespace OTS
{
	class ConfigManager : Singleton<ConfigManager>
	{
	
	public:
		ConfigManager();
		~ConfigManager(void);

		static ConfigManager& getSingleton( void );
		static ConfigManager*  getSingletonPointer( void );

		//! Loads a configfile
		/*! Loads the specified filename. Divides its into sections and puts in the SettingsMap.
			\param filename path to file.
		*/
		void LoadConfigFile(OTS::STRING& filename);
		
		// Some typedefs
		typedef std::map<OTS::STRING, OTS::STRING> SettingsMap;
		typedef std::map<OTS::STRING, SettingsMap> SectionMap;

		SettingsMap* GetSettingsSection(OTS::STRING section);

		//! Retrieves a setting.
		/*! /param section Name of the section where the setting is in
			/param settingName Name of the setting
			/return Value of the setting, NULL if not found.
		*/
		OTS::STRING GetSetting(OTS::STRING section, OTS::STRING settingName);

	private:
		SectionMap* _pSectionMap;
		OTS::STRING _delimiter;
		LoggingManager* _pLoggingManager;
	};
}
