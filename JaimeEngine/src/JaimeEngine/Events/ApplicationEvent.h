#pragma once
#include "Event.h"


namespace JaimeEngine
{
	class JE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int widthSize, unsigned int heightSize)
			:m_Width(widthSize)
			,m_Height(heightSize)
		{ }



		inline std::string ToString() const override 
		{
			return "WindowResizeEvent " + std::to_string(m_Width) + ", " + std::to_string(m_Height);
		}

		inline unsigned int GetWidthSize() const { return m_Width; }
		inline unsigned int GetHeightSize() const { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	protected:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class JE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset)
			, m_YOffset(yOffset)
		{
		}

		inline std::string ToString() const override
		{
			return "WindowMovedEvent" + std::to_string(m_XOffset) + ", " + std::to_string(m_YOffset);
		}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	protected:
		float m_XOffset;
		float m_YOffset;
	};

	class JE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

	
		inline std::string ToString() const override
		{
			return "WindowClosed";
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class JE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class JE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class JE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}