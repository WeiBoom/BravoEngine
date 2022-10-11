#pragma once

#ifdef BRAVO_PLATFORM_WINDOWS

	#ifdef BRAVO_BUILD_DLL
		#define BRAVO_API __declspec(dllexport)
	#else
		#define BRAVO_API __declspec(dllimport)
	#endif

#else
	#error Bravo Engine only support Windows for now!
#endif