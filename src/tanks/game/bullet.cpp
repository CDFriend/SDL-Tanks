/*
 * bullet.cpp
 *
 *  Created on: Aug 15, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tanks/game/bullet.h"

const int BULLET_SPEED = 4;
const int BULLET_WIDTH = 84;
const int BULLET_HEIGHT = 84;

using namespace Tanks::Game;

Bullet::Bullet(SDL_Renderer *gameRenderer, int x, int y, int bearing) {
    this->xPos = x;
    this->yPos = y;
    this->bearing = bearing;

    // initialize tank texture
    SDL_Surface *bulletSurface = IMG_Load("./res/bullet/bullet.png");
    if (bulletSurface == NULL) {
        printf("Failed to load bullet image! IMG_Error: %s\n", IMG_GetError());
        bulletTexture = SDL_CreateTexture(gameRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 20, 20);
    }
    else {
        bulletTexture = SDL_CreateTextureFromSurface(gameRenderer, bulletSurface);
    }
}

Bullet::~Bullet() {
    SDL_DestroyTexture(bulletTexture);
}

void Bullet::update() {
    xPos += round( BULLET_SPEED * cos( (double) (90 - bearing) * M_PI / 180) );
    yPos -= round( BULLET_SPEED * sin( (double) (90 - bearing) * M_PI / 180) );
}

void Bullet::draw(SDL_Renderer *gameRenderer) {

    SDL_Rect bulletRect;
    bulletRect.x = xPos + BULLET_WIDTH / 2;
    bulletRect.y = yPos + BULLET_HEIGHT / 2;
    bulletRect.w = BULLET_WIDTH;
    bulletRect.h = BULLET_HEIGHT;

    SDL_RenderCopyEx(gameRenderer, bulletTexture, NULL, &bulletRect, bearing, NULL, SDL_FLIP_NONE);
}

bool Bullet::isOutsidePerimeter(int width, int height) {
    if (xPos < 0 || yPos < 0)
        return true;
    else if (xPos > width)
        return true;
    else if (yPos > height)
        return true;
    else
        return false;
}
