#include <Bravo.h>

class Sandbox : public  Bravo::Application
{
public :
	Sandbox(){}
	~Sandbox() {}
};

// implment function from Bravo
Bravo::Application* Bravo::CreateApplication()
{
	return new Sandbox();
}
