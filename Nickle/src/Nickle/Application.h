#pragma once

#include "Core.h"

namespace Nickle
{
	class NK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

