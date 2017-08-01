/*
 * tanks_game.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <iostream>
#include <SDL2/SDL.h>

#include "tanks_game.h"

const int PLAYER1_INIT_X = 200;
const int PLAYER1_INIT_Y = 200;

const int GAMEBG_R = 0;
const int GAMEBG_G = 0;
const int GAMEBG_B = 255;

TanksGame::TanksGame(void) {

	playerTank = new Tank(PLAYER1_INIT_X, PLAYER1_INIT_Y);

	gameWindow = NULL;
	gameSurface = NULL;

	gameBgColor = 0xFFFFFFFF;

}

void TanksGame::mainLoop(void) {

	init_sdl();

	bool quitFlag = false;

	while (!quitFlag) {

		// Poll events - e is local and should be disposed of at the end of
		// the loop.
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {

			// Check for quit event
			if (e.type == SDL_QUIT) {
				quitFlag = true;
			}

		}

		// Draw game background.
		SDL_FillRect(gameSurface, NULL, gameBgColor);

		// Handle user input for player tank
		//
		// NOTE: normally SDL_PushEvents() would have to be called here to update
		// the keyboard array, but it is implicitly called by SDL_PollEvents().
		playerTank->handleKeyboardState(SDL_GetKeyboardState(NULL));
		playerTank->draw(gameSurface);

		SDL_UpdateWindowSurface(gameWindow);
	}

	printf("Event loop ended. Closing SDL...\n");

	close_sdl();

}

bool TanksGame::init_sdl() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error initialing SDL! SDL_Error: %s\n", SDL_GetError());
		return false;
	} else {

		// initialize game window
		gameWindow = SDL_CreateWindow("Tanks", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

		if (gameWindow == NULL) {
			printf("Error initializing game window! SDL_Error: %s\n",
					SDL_GetError());
			return false;
		} else {
			gameSurface = SDL_GetWindowSurface(gameWindow);
		}

	}

	// Create game BG color using game surface color format
	gameBgColor = SDL_MapRGB(gameSurface->format, GAMEBG_R, GAMEBG_G, GAMEBG_B);

	return true;

}

void TanksGame::close_sdl() {

	SDL_FreeSurface(gameSurface);
	gameSurface = NULL;

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	SDL_Quit();

}
