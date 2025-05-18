#pragma once
#include "jepch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <gl/GL.h>

namespace JaimeEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		while (m_Running) {
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
