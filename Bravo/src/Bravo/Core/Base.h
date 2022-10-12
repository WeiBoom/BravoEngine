
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