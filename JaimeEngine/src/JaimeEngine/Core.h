#pragma once

#ifdef JE_PLATFORM_WINDOWS
	#ifdef JE_BUILD_DLL
		#define JE_API _declspec(dllexport)
	#else
		#define JE_API _declspec(dllimport)
	#endif

#else
	#error JAIME ENGINE ONLY SUPPOR WINDOWS!
#endif

#ifdef JE_ENABLE_ASSERTS
	#define JE_ASSERT(x, ...) {if(!(x)) {JE_ERROR("Assertion Failed: {0}", __VA_ARGS__); _debugbreak();}}
	#define JE_CORE_ASSERT(x, ...) {if(!(x)) {JE_CORE_ERROR("Core Assertion Failed: {0}", __VA_ARGS__); _debugbreak();}}
#else
	#define JE_ASSERT(x, ...)
	#define JE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 