/*
 * bullet.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "bullet.h"

const int BULLET_SPEED = 5;
const int BULLET_WIDTH = 80;
const int BULLET_HEIGHT = 80;

Bullet::Bullet(SDL_Renderer *gameRenderer, int x, int y, int bearing) {
	this->xPos = x;
	this->yPos = y;
	this->bearing = bearing;

	// initialize tank texture
	SDL_Surface *tankSurface = IMG_Load("./res/bullet/bullet.png");
	if (tankSurface == NULL) {
		printf("Failed to load bullet image! IMG_Error: %s\n", IMG_GetError());
		bulletTexture = SDL_CreateTexture(gameRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 20, 20);
	}
	else {
		bulletTexture = SDL_CreateTextureFromSurface(gameRenderer, tankSurface);
	}
}

void Bullet::update() {
	xPos += round( 3 * cos( (double) (90 - bearing) * M_PI / 180) );
	yPos -= round( 3 * sin( (double) (90 - bearing) * M_PI / 180) );
}

void Bullet::draw(SDL_Renderer *gameRenderer) {

	SDL_Rect bulletRect;
	bulletRect.x = xPos + BULLET_WIDTH / 2;
	bulletRect.y = yPos + BULLET_HEIGHT / 2;
	bulletRect.w = BULLET_WIDTH;
	bulletRect.h = BULLET_HEIGHT;

	SDL_RenderCopyEx(gameRenderer, bulletTexture, NULL, &bulletRect, bearing, NULL, SDL_FLIP_NONE);

}
