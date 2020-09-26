#pragma once 
#include "PlatformDetection.h"
#include <memory>

#ifdef PLATFORM_WINDOWS

	#ifdef BUILD_DLL
	#define DLL_PORTING __declspec(dllexport)
	#else
	#define DLL_PORTING __declspec(dllimport)
	#endif

#endif

