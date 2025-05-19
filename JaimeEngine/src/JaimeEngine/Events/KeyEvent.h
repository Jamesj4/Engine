#pragma once
#include "Event.h"

namespace JaimeEngine 
{

	class JE_API KeyEvent : public Event 
	{
	public:
	
		inline int GetKeyCode() const { return m_KeyCode; };

		EVENT_CLASS_CATEGORY(EventCategoryInput)

	protected:
		KeyEvent(int keyCode)
			:m_KeyCode(keyCode) {}

		int m_KeyCode;

		
	};


	class JE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			:KeyEvent(keyCode)
			,m_RepeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return m_RepeatCount;}

		std::string ToString() const override
		{
			return "KeyPressedEvent: " + std::to_string(m_KeyCode) + "pressed " + std::to_string(m_RepeatCount) +" times";
		}

		EVENT_CLASS_TYPE(KeyPressed)
	

	protected:
		
		int m_RepeatCount;
	};


	class JE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			:KeyEvent(keyCode)
		{
		}

		std::string ToString() const override
		{
			return "KeyReleased: " + std::to_string(m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyReleased)


	protected:

	};

}