/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: charlie
 */

#include <iostream>

#include "tanks/game/tanks_game.h"

int main(int argc, char* argv[]) {

    Tanks::Game::TanksGame game;

    game.mainLoop();

    return 0;

}
