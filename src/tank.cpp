/*
 * tank.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tank.h"

Tank::Tank(SDL_Renderer* gameRenderer, int initX, int initY) {

	// initialize bearing to zero (tank always begins facing due north)
	bearing = 0;

	// set initial x and y positions
	xPos = initX;
	yPos = initY;

	// initialize tank texture
	SDL_Surface *tankSurface = IMG_Load("./res/green_tank/green_tank_1.png");
	if (tankSurface == NULL) {
		printf("Failed to load tank image! IMG_Error: %s\n", IMG_GetError());
		tankTexture = SDL_CreateTexture(gameRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 20, 20);
	}
	else {
		tankTexture = SDL_CreateTextureFromSurface(gameRenderer, tankSurface);
	}

}

Tank::~Tank(void) {

	SDL_DestroyTexture(tankTexture);

}

void Tank::handleKeyboardState(const Uint8 *keyboardState) {

	if (keyboardState[SDL_SCANCODE_UP]) {
		xPos += 3 * cos( (double) (90 - bearing) * M_PI / 180);
		yPos -= 3 * sin( (double) (90 - bearing) * M_PI / 180);
	}
	if (keyboardState[SDL_SCANCODE_DOWN]) {
		xPos -= 3 * cos( (double) (90 - bearing) * M_PI / 180);
		yPos += 3 * sin( (double) (90 - bearing) * M_PI / 180);
	}
	if (keyboardState[SDL_SCANCODE_LEFT]) {
		bearing = (bearing - 3) % 360;
	}
	if (keyboardState[SDL_SCANCODE_RIGHT]) {
		bearing = (bearing + 3) % 360;
	}

}

void Tank::draw(SDL_Renderer *gameRenderer) {

	SDL_Rect tankRect;
	tankRect.x = xPos;
	tankRect.y = yPos;
	tankRect.w = 80;
	tankRect.h = 80;

	SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0, 0, 0xFF);
	SDL_RenderCopyEx(gameRenderer, tankTexture, NULL, &tankRect, bearing, NULL, SDL_FLIP_NONE);

}
