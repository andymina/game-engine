//
//  Hunter.h
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#ifndef Hunter_h
#define Hunter_h

#include "HunterCentral.h"
#include "HunterApp.h"
#include "Sprite.h"
#include "Renderer.h"
#include "HunterKeys.h"

#define START_GAME(classname)\
	int main() {\
		classname* gamePointer = new classname;\
		gamePointer->GetApplication()->RunGame();\
		delete gamePointer;\
	}\

#endif /* Hunter_h */
