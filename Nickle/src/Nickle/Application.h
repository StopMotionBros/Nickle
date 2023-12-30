#pragma once

#include "Core.h"

namespace Nickle
{
	class NICKLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

