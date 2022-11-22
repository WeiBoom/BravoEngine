#include <Bravo.h>

class ExampleLayer : public Bravo::Layer
{
public:
	ExampleLayer(): Layer("Example"){}

	void OnUpdate() override { BRAVO_INFO("ExampleLayer::Update"); }
	void OnEvent(Bravo::Event& e) override { BRAVO_TRACE("{0}",e); }
};

class Sandbox : public  Bravo::Application
{
public :
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

// implment function from Bravo
Bravo::Application* Bravo::CreateApplication()
{
	return new Sandbox();
}
