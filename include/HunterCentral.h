//
//  HunterCentral.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef HunterCentral_h
#define HunterCentral_h

// Export API for Windows x32 and x64
#if defined(_WIN32) && defined(_HUNTER_DLL_BUILD)
	#define HUNTER_API __declspec(dllexport)
#elif defined(_WIN32) && !defined(_HUNTER_DLL_BUILD)
	#define HUNTER_API __declspec(dllimport)
#endif

// Export API for macOS
#if defined(__APPLE__) && defined(_HUNTER_DLL_BUILD)
	#define HUNTER_API __attribute__((visibility("default")))
#elif defined(__APPLE__) && !defined(_HUNTER_DLL_BUILD)
	#define HUNTER_API
#endif

// Define PLATFORM_WINDOW_FILE
#ifdef _WIN32
	#define	PLATFORM_WINDOW_FILE "WindowsOS/WindowsOSWindow.h"
#elif __APPLE__
	#define PLATFORM_WINDOW_FILE "macOS/macOSWindow.h"
#endif

// Define my debug environment
#ifdef _MYDEBUG
	#define HLOG(x) std::cout << x << std::endl
#else
	#define HLOG(x)
#endif

#endif /* HunterCentral_h */
