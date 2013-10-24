#include "RenderSystem.h"

namespace OTS
{
	template<> RenderSystem* Singleton<RenderSystem>::_singleton = 0;

	RenderSystem* RenderSystem::getSingletonPointer( void )
	{
		return _singleton;
	}

	RenderSystem& RenderSystem::getSingleton( void )
	{
		return (*_singleton);
	}

	RenderSystem::RenderSystem(void)
	{
		this->_pLogger = LoggingManager::getSingletonPointer();
		this->_pConfig = ConfigManager::getSingletonPointer();

		this->_loadConfig();
		glfwSetErrorCallback(glfwErrorCallback);
		this->_pLogger->LogMessage("[RenderSystem] - Constructed.");
	}


	RenderSystem::~RenderSystem(void)
	{
		glfwDestroyWindow(this->_window);
	}

	bool RenderSystem::Initialize()
	{
		if(!glfwInit())
		{
			this->_pLogger->LogMessage("[RenderSystem] - Failed initialize GLFW.");
			return false;
		}
		return true;
	}

	void RenderSystem::CreateRenderWindow(OTS::STRING* windowName)
	{
		GLFWmonitor* monitor = NULL;

		// Check if window should be fullscreen
		if (!_isWindowed)
		{
			monitor = this->_getMonitor();
		}

		this->_window = glfwCreateWindow(this->_screenWidth, this->_screenHeight, windowName->c_str(), monitor, NULL);

		if(this->_window == NULL)
		{
			this->_pLogger->LogMessage("[RenderSystem] - Error opening window.");
		}

		// Make opengl Context current
		glfwMakeContextCurrent(this->_window);
	}

	void RenderSystem::SetViewport(uint32 x, uint32 y)
	{
		glViewport(x, y, this->_screenWidth, this->_screenHeight);
	}

	void RenderSystem::_loadConfig()
	{
		this->_screenHeight = atoi(this->_pConfig->GetSetting("Video", "height").c_str());
		this->_screenWidth = atoi(this->_pConfig->GetSetting("Video", "width").c_str());
		// != NULL added to prevent warning C4800
		this->_isWindowed = atoi(this->_pConfig->GetSetting("Video", "windowed").c_str()) != NULL;
	}

	GLFWmonitor* RenderSystem::_getMonitor()
	{
		return NULL;
	}

	void RenderSystem::_handleGlfwError(int error, const char* description)
	{
		char buffer[100];
		sprintf_s(buffer, "[RenderSystem] - GLFW Error: %i :: %s", error, description);
		this->_pLogger->LogMessage(buffer);
	}

	void RenderSystem::SetBackgroundColor( ColorValue color )
	{
		this->_colorValue = color;
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void RenderSystem::glfwErrorCallback(int error, const char* description)
	{
		OTS::RenderSystem* rs = RenderSystem::getSingletonPointer();
		rs->_handleGlfwError(error, description);
	}

}