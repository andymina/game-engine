//
//  game_engine.cpp
//  game-engine
//
//  Created by Andy Mina on 6/23/21.
//

#include <iostream>
#include "game_engine.hpp"
#include "game_enginePriv.hpp"

void game_engine::HelloWorld(const char * s)
{
    game_enginePriv *theObj = new game_enginePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void game_enginePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

