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

// Minimum period between frame updates (ms).
// (1 / 60ips) * 1000
const int MIN_UPDATE_PERIOD = (int) (1000 / 60.0);

TanksGame::TanksGame(void) {

	// init gameWindow and gameRenderer
	printf("Init sdl_window...\n");
	init_sdl();

	playerTank = new Tank(gameRenderer, PLAYER1_INIT_X, PLAYER1_INIT_Y);

}

TanksGame::~TanksGame(void) {

	// free all SDL resources and quit SDL
	printf("Closing sdl_window...\n");
	close_sdl();

}

void TanksGame::mainLoop(void) {

	bool quitFlag = false;
	Uint32 lastFrameTime = SDL_GetTicks();

	while (!quitFlag) {

		// drop frames if updated faster than desired frame rate
		Uint32 timeDelta = SDL_GetTicks() - lastFrameTime;
		if (timeDelta < MIN_UPDATE_PERIOD) {
			continue;
		}

		lastFrameTime = SDL_GetTicks();

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
		SDL_SetRenderDrawColor(gameRenderer, GAMEBG_R, GAMEBG_G, GAMEBG_B, 0xFF);
		SDL_RenderClear(gameRenderer);

		// Handle user input for player tank
		//
		// NOTE: normally SDL_PushEvents() would have to be called here to update
		// the keyboard array, but it is implicitly called by SDL_PollEvents().
		playerTank->handleKeyboardState(SDL_GetKeyboardState(NULL));
		playerTank->draw(gameRenderer);

		// Update screen
		SDL_RenderPresent(gameRenderer);
	}



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
			// create renderer for window
			gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

			if (gameRenderer == NULL) {
				printf("Error initializing game renderer! SDL_Error: %s\n", SDL_GetError());
				return false;
			}
		}

	}

	return true;

}

void TanksGame::close_sdl() {

	SDL_DestroyRenderer(gameRenderer);
	gameRenderer = NULL;

	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	SDL_Quit();

}
