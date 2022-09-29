#pragma once

#ifdef BRAVO_PLATFORM_WINDOW

extern Bravo::Application* Bravo::CreateApplication();

int main(int args, char** argv)
{
	std::cout << "welcome to Bravo Engine" << std::endl;
	auto app = Bravo::CreateApplication();
	app->Run();
	delete app;
}


#endif