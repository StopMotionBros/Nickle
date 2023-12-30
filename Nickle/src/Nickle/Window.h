#pragma once

#include "nkpch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Nickle
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width, Height;

		WindowProps(uint32_t width = 1280, uint32_t height = 720, const std::string& title = "Nickle Engine") :
			Title(title), Width(width), Height(height) {}
	};

	class NICKLE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}