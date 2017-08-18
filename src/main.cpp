/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: charlie
 */

#include <iostream>

#include "tanks_game.h"

using namespace std;

int main(int argc, char* argv[]) {

    TanksGame *game;
    game = new TanksGame();

    game->mainLoop();

    delete game;

    return 0;

}
