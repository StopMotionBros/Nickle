#pragma once

#include "Event.h"

#include <sstream>

namespace Nickle
{
	class NICKLE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY) :
			m_MouseX(mouseX), m_MouseY(mouseY){}

		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }

		std::string ToString()
		{
			std::stringstream ss{};
			ss << "MouseMovedEvent: " << m_MouseX << " , " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		float m_MouseX, m_MouseY;
	};

	class NICKLE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float scrollX, float scrollY) :
			m_ScrollX(scrollX), m_ScrollY(scrollY) {}

		inline float GetScrollX() { return m_ScrollX; }
		inline float GetScrollY() { return m_ScrollY; }

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "MouseScrolledEvent: " << m_ScrollX << ", " << m_ScrollY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseScrolled);
	private:
		float m_ScrollX, m_ScrollY;
	};

	class NICKLE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(int button) :
			m_Button(button){}

		int m_Button;
	};

	class NICKLE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button){}

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class NICKLE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button){}

		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}