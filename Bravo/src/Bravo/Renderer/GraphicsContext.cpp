#include "pch.h"
#include "Bravo/Renderer/GraphicsContext.h"

namespace Bravo {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		/*switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    BRAVO_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}*/

		BRAVO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}