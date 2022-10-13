#pragma once
#include "Bravo/Core/Base.h"
#include "Bravo/Core/Log.h"
#include <filesystem>

#ifdef BRAVO_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define BRAVO_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { BRAVO##type##ERROR(msg, __VA_ARGS__); BRAVO_DEBUGBREAK(); } }
	#define BRAVO_INTERNAL_ASSERT_WITH_MSG(type, check, ...) BRAVO_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define BRAVO_INTERNAL_ASSERT_NO_MSG(type, check) BRAVO_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", BRAVO_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define BRAVO_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define BRAVO_INTERNAL_ASSERT_GET_MACRO(...) BRAVO_EXPAND_MACRO( BRAVO_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, BRAVO_INTERNAL_ASSERT_WITH_MSG, BRAVO_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define BRAVO_ASSERT(...) BRAVO_EXPAND_MACRO( BRAVO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define BRAVO_CORE_ASSERT(...) BRAVO_EXPAND_MACRO( BRAVO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define BRAVO_ASSERT(...)
	#define BRAVO_CORE_ASSERT(...)
#endif
