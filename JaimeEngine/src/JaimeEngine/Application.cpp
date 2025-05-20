#pragma once
#include "jepch.h"

#include "Application.h"

#include "Log.h"
#include <glad/glad.h>

namespace JaimeEngine
{
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		JE_CORE_ASSERT(!s_Instance, "Application already exists")
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{

		EventDispatcher distpacher(e);
		distpacher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		JE_CORE_INFO("{0}", e.ToString());

		
		for (const auto& layer : m_LayerStack)
		{
			if (layer) 
			{
				layer->OnEventCall(e);
				if (e.m_Handled)
					break;
			}
		}
	
	}

	void Application::PushLayer(std::unique_ptr<Layer> layer)
	{
	
		if (layer)
		{
			layer->OnAttach();
			m_LayerStack.PushLayer(std::move(layer));
		}
	}

	void Application::PushOverlay(std::unique_ptr<Layer> overlay)
	{
		if (overlay) 
		{
			overlay->OnAttach();
			m_LayerStack.PushOverlay(std::move(overlay));
		}
		
		
	}

	void Application::Run()
	{

		while (m_Running) {
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			
			for (const std::unique_ptr<Layer>& layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			
				

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		m_Running = false;
		return true;
	}

}
