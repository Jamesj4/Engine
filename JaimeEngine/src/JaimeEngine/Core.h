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