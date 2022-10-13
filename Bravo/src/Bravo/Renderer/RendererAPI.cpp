#include "pch.h"
#include "Bravo/Renderer/RendererAPI.h"

namespace Bravo {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:    BRAVO_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		//case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		BRAVO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}