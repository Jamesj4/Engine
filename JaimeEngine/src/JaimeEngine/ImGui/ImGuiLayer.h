#pragma once

#include "JaimeEngine/Layer.h"
#include <JaimeEngine/Events/MouseEvent.h>
#include <JaimeEngine/Events/KeyEvent.h>
#include <JaimeEngine/Events/ApplicationEvent.h>

namespace JaimeEngine
{
	class JE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEventCall(Event& event)override;
	private:

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);
	
	
		float m_Time;
	};
}