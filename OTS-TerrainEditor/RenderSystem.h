#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Singleton.h"
#include "LoggingManager.h"
#include "ConfigManager.h"
#include "ColorValue.h"

namespace OTS
{
	class RenderSystem : public Singleton<RenderSystem> 
	{
	public:
		RenderSystem(void);
		~RenderSystem(void);
		static RenderSystem* RenderSystem::getSingletonPointer(  );
		static RenderSystem& RenderSystem::getSingleton(  );
		bool Initialize();
		void CreateRenderWindow(OTS::STRING* windowName);
		void SetViewport(uint32 x, uint32 y);
		void SetBackgroundColor(ColorValue color);
		void RenderFrame();
		bool IsWindowClosed();

		uint32 ScreenWidth() const { return _screenWidth; }
		void ScreenWidth(uint32 val) { _screenWidth = val; }

	private:
		LoggingManager* _pLogger;
		ConfigManager* _pConfig;

		// Config options
		uint32 _screenWidth;
		uint32 _screenHeight;
		bool _isWindowed;
		ColorValue _colorValue;
		int _monitor;

		GLFWwindow* _window;
		bool _shouldClose;

		void _loadConfig();
		GLFWmonitor* _getMonitor();
		void _handleGlfwError(int error, const char* description);
		void _handleGlfwWindowClose(GLFWwindow* window);

		// Static callbacks for C style callbacks
		static void glfwErrorCallback(int error, const char* description);
		static void glfwWindowCloseCallback(GLFWwindow* window);
	};
}


