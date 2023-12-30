#pragma once

#include "Event.h"

namespace Nickle
{
	class NICKLE_API ImGuiMouseButtonEvent : public Event
	{
	protected:
		ImGuiMouseButtonEvent(int button):
			m_Button(button){}

		int m_Button;
	};

	class NICKLE_API ImGuiMouseButtonPressedEvent : public ImGuiMouseButtonEvent
	{

	};
}