//
//  HunterCentral.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef HunterCentral_h
#define HunterCentral_h

// Define dynamic library for Windows x32 and x64
#if defined(_WIN32) && defined(_HUNTER_DLL_BUILD)
	#define DYNAMIC_LIB __declspec(dllexport)
#elif defined(_WIN32) && !defined(_HUNTER_DLL_BUILD)
	#define DYNAMIC_LIB __declspec(dllimport)
#endif

// Define dynamic library for macOS
#if defined(__APPLE__) && defined(_HUNTER_DLL_BUILD)
	#define DYNAMIC_LIB __attribute__((visibility("default")))
#elif defined(__APPLE__) && !defined(_HUNTER_DLL_BUILD)
	#define DYNAMIC_LIB
#endif

// Define my debug environment
#ifdef _MYDEBUG
	#define HLOG(x) std::cout << x << std::endl
#else
	#define HLOG(x)
#endif

#endif /* HunterCentral_h */
