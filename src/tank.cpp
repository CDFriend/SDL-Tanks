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

	printf("Tank position: [ x:%d, y:%d ]\n", xPos, yPos);

}

void Tank::draw(SDL_Surface *drawingSurface) {

	SDL_Rect tankRect;
	tankRect.x = xPos;
	tankRect.y = yPos;
	tankRect.w = 20;
	tankRect.h = 20;

	SDL_FillRect(drawingSurface, &tankRect, SDL_MapRGB(drawingSurface->format, 255, 0, 0));

}
