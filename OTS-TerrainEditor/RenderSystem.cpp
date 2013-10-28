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
		this->_shouldClose = false;
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
			throw 10;
		}

		// Make opengl Context current
		glfwMakeContextCurrent(this->_window);

		// Set window callbacks
		glfwSetWindowCloseCallback(this->_window, glfwWindowCloseCallback);
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
		this->_monitor = atoi(this->_pConfig->GetSetting("Video", "monitor").c_str());
	}

	void RenderSystem::RenderFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// Rendering should come here

		glfwSwapBuffers(this->_window);
		glfwPollEvents();
	}

	GLFWmonitor* RenderSystem::_getMonitor()
	{
		int count;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		
		return monitors[this->_monitor];
	}

	void RenderSystem::_handleGlfwError(int error, const char* description)
	{
		char buffer[100];
		sprintf_s(buffer, "[RenderSystem] - GLFW Error: %i :: %s", error, description);
		this->_pLogger->LogMessage(buffer);
	}

	void RenderSystem::_handleGlfwWindowClose(GLFWwindow* window)
	{
		this->_shouldClose = true;
	}

	void RenderSystem::SetBackgroundColor( ColorValue color )
	{
		this->_colorValue = color;
		glClearColor(color.r, color.g, color.b, color.a);
	}


	bool RenderSystem::IsWindowClosed()
	{
		return this->_shouldClose;
	}


	/***********************************************************************
	 * Static callback for using as CALLBACK functions
	 ***********************************************************************/
	void RenderSystem::glfwErrorCallback(int error, const char* description)
	{
		OTS::RenderSystem* rs = RenderSystem::getSingletonPointer();
		rs->_handleGlfwError(error, description);
	}

	void RenderSystem::glfwWindowCloseCallback(GLFWwindow* window)
	{
		OTS::RenderSystem* rs = RenderSystem::getSingletonPointer();
		rs->_handleGlfwWindowClose(window);
	}
}