/*
 * main.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: charlie
 */

#include <iostream>
#include <SDL2/SDL.h>

#include "tanks_game.h"

using namespace std;

int main(int argc, char* argv[]) {

	TanksGame game;
	game = TanksGame();

	game.mainLoop();

	return 0;

}
