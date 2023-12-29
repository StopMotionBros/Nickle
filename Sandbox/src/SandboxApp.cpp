#include <Nickle.h>

class Sandbox : public Nickle::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Nickle::Application* Nickle::CreateApplication()
{
	return new Sandbox();
}