#pragma once

#include <memory>

#include "Bravo/Core/PlatformDetection.h"

#ifdef BRAVO_DEBUG
	#if defined (BRAVO_PLATFORM_WINDOWS)
		#define BRAVO_DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define BRAVO_ENABLE_ASSERTS
#else
	#define BRAVO_DEBUGBREAK()
#endif

#ifdef BRAVO_PLATFORM_WINDOWS

	#ifdef BRAVO_BUILD_DLL
		#define BRAVO_API __declspec(dllexport)
	#else
		#define BRAVO_API __declspec(dllimport)
	#endif

#else
	#error Bravo Engine only support Windows for now!
#endif

#define BIT(x) (1 << x)
#define BRAVO_EXPAND_MACRO(x) x
#define BRAVO_STRINGIFY_MACRO(x) #x
#define BRAVO_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Bravo
{
	// define unique_ptr as Scope
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	// define shared_ptr as Ref
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Bravo/Core/Log.h"
#include "Bravo/Core/Assert.h"