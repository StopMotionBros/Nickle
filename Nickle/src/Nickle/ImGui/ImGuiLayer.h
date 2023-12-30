#pragma once

#include "Nickle/Layer.h"

#include "Nickle/Events/ApplicationEvent.h"
#include "Nickle/Events/MouseEvent.h"
#include <Nickle/Events/KeyEvent.h>

namespace Nickle
{
	class NICKLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDeatach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnWindowResizedEvent(WindowResizedEvent& event);

		float m_Time = 0.0f;
	};
}