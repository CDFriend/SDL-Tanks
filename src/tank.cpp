/*
 * tank.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <iostream>
#include <math.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "bullet.h"
#include "tank.h"

const int TANK_WIDTH = 80;
const int TANK_HEIGHT = 80;

const int MINIMUM_RELOAD_TIME_MS = 300;

Tank::Tank(SDL_Renderer* gameRenderer, int initX, int initY) {

    // initialize bearing to zero (tank always begins facing due north)
    bearing = 0;

    // set initial x and y positions
    xPos = initX;
    yPos = initY;

    // should be able to shoot immediately after init
    lastShotTime = 0;

    this->gameRenderer = gameRenderer;

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

void Tank::handleKeyboardState(const Uint8 *keyboardState, std::vector<Bullet> *bullets) {

    // check arrow keys
    if (keyboardState[SDL_SCANCODE_UP]) {
        xPos += round( 3 * cos( (double) (90 - bearing) * M_PI / 180) );
        yPos -= round( 3 * sin( (double) (90 - bearing) * M_PI / 180) );
    }
    if (keyboardState[SDL_SCANCODE_DOWN]) {
        xPos -= round( 3 * cos( (double) (90 - bearing) * M_PI / 180) );
        yPos += round( 3 * sin( (double) (90 - bearing) * M_PI / 180) );
    }
    if (keyboardState[SDL_SCANCODE_LEFT]) {
        bearing = (bearing - 3) % 360;
    }
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        bearing = (bearing + 3) % 360;
    }

    // shoot if space bar
    if (keyboardState[SDL_SCANCODE_SPACE] &&
            SDL_GetTicks() - lastShotTime > MINIMUM_RELOAD_TIME_MS) {

        lastShotTime = SDL_GetTicks();

        Bullet* b = new Bullet(gameRenderer, xPos, yPos, bearing);
        bullets->push_back(*b);

    }

}

void Tank::draw(SDL_Renderer *gameRenderer) {

    SDL_Rect tankRect;
    tankRect.x = xPos + TANK_WIDTH / 2;
    tankRect.y = yPos + TANK_HEIGHT / 2;
    tankRect.w = TANK_WIDTH;
    tankRect.h = TANK_HEIGHT;

    SDL_RenderCopyEx(gameRenderer, tankTexture, NULL, &tankRect, bearing, NULL, SDL_FLIP_NONE);

}
