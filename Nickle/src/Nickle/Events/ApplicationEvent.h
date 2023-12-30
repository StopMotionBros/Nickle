#pragma once

#include "Event.h"

namespace Nickle
{
	class NICKLE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height) :
			m_Width(width), m_Height(height){}

		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowResize);

	private:
		uint32_t m_Width, m_Height;
	};

	class NICKLE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowClose);
	};

	class NICKLE_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowFocus);
	};

	class NICKLE_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowLostFocus);
	};

	class NICKLE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int posX, int posY) :
			m_PosX(posX), m_PosY(posY){}

		inline int GetX() { return m_PosX; }
		inline int GetY() { return m_PosY; }

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "WindowMovedEvent: " << m_PosX << ", " << m_PosY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowMoved);

	private:
		int m_PosX, m_PosY;
	};

	class NICKLE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppTick);
	};

	class NICKLE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppUpdate);
	};

	class NICKLE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent(){}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppRender);
	};
}