#include <Nickle.h>

class TestLayer : public Nickle::Layer
{
public:
	TestLayer() :
		Layer("TestLayer"){}

	void OnUpdate() override
	{
	}

	void OnEvent(Nickle::Event& e) override
	{
		NK_TRACE(e);
	}
};

class Sandbox : public Nickle::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
		PushLayer(new Nickle::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Nickle::Application* Nickle::CreateApplication()
{
	return new Sandbox();
}