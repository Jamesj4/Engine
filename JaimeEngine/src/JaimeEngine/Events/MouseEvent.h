#pragma once

#include "Event.h"

namespace JaimeEngine
{
	class JE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:m_MouseX(x)
			,m_MouseY(y)
		{}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }


		std::string ToString() const override 
		{
			return "MouseMovedEvent: " + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
		}


		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:

		float m_MouseX;
		float m_MouseY;
	};



	class JE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_OffsetX(xOffset)
			,m_OffsetY(yOffset)
		{
		}

		inline float GetXOffset() const { return m_OffsetX; }
		inline float GetYOffset() const { return m_OffsetY; }


		std::string ToString() const override
		{
			return "MouseMovedEvent: " + std::to_string(m_OffsetX) + ", " + std::to_string(m_OffsetY);
		}


		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY( EventCategoryMouse | EventCategoryInput)

	private:

		float m_OffsetX;
		float m_OffsetY;
	};


	class JE_API MouseButtonEvent : public Event
	{
	
	public:

		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			:m_Button(button)
		{}

		int m_Button; 
	};


	class JE_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			return "MouseButtonPressedEvent: " + std::to_string(m_Button);
		}


		EVENT_CLASS_TYPE(MouseButtonPressed)

	};


	class JE_API MouseButtonReleasedEvent: public MouseButtonEvent
	{

	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			return "MouseButtonPressedReleased: " + std::to_string(m_Button);
		}


		EVENT_CLASS_TYPE(MouseButtonReleased)

	};

}