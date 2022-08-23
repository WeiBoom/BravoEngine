#include "define.h"
#include "Application.h"

int main()
{
	// init application
	auto app = std::make_unique<Bravo::Application>("Bravo Engine");
	// tick render
	app->Loop();
}
