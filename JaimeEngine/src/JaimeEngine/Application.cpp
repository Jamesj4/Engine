#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace JaimeEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent windowResizeEvent(1280, 730);

		JE_TRACE(windowResizeEvent.ToString());
		while (true) {

		}
	}
}
