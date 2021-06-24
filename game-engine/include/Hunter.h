//
//  Hunter.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef Hunter_h
#define Hunter_h

#include <HunterCentral.h>
#include <HunterApp.h>

#define START_GAME(classname)\
	int main() {\
		classname::Init();\
		classname::GetApplication()->RunGame();\
	}\

#endif /* Hunter_h */
