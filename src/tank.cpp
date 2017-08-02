/*
 * tank.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <iostream>
#include <SDL2/SDL.h>

#include "tank.h"

Tank::Tank(int initX, int initY) {

	// initialize bearing to zero (tank always begins facing due north)
	bearing = 0;

	// set initial x and y positions
	xPos = initX;
	yPos = initY;

}

void Tank::handleKeyboardState(const Uint8 *keyboardState) {

	if (keyboardState[SDL_SCANCODE_UP]) {
		yPos -= 3;
	}
	if (keyboardState[SDL_SCANCODE_DOWN]) {
		yPos += 3;
	}
	if (keyboardState[SDL_SCANCODE_LEFT]) {
		xPos -= 3;
	}
	if (keyboardState[SDL_SCANCODE_RIGHT]) {
		xPos += 3;
	}

}

void Tank::draw(SDL_Renderer *gameRenderer) {

	SDL_Rect tankRect;
	tankRect.x = xPos;
	tankRect.y = yPos;
	tankRect.w = 20;
	tankRect.h = 20;

	SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0, 0, 0xFF);
	SDL_RenderDrawRect(gameRenderer, &tankRect);

}
