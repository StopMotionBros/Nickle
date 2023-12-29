#pragma once

#ifdef NK_PLATFORM_WINDOWS

extern Nickle::Application* Nickle::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Nickle::CreateApplication();
	app->Run();
	delete app;
}

#endif