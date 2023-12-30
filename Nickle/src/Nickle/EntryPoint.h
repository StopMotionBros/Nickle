#pragma once

#ifdef NK_PLATFORM_WINDOWS

extern Nickle::Application* Nickle::CreateApplication();

int main(int argc, char** argv)
{
	Nickle::Log::Init();
	NK_CORE_WARN("This works");
	NK_TRACE("This as well");

	auto app = Nickle::CreateApplication();
	app->Run();
	delete app;
}

#endif