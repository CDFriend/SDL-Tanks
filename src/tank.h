/*
 * tank.h
 *
 *  Created on: Aug 1, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#ifndef TANK_H
#define TANK_H

#include <vector>
#include <SDL2/SDL.h>

#include "bullet.h"

class Tank {

public:
    Tank(SDL_Renderer *gameRenderer, int initX, int initY);
    ~Tank();
    void handleKeyboardState(const Uint8 *keyboardState, std::vector<Bullet> *bullets);
    void draw(SDL_Renderer *drawingSurface);

private:
    int xPos;
    int yPos;
    int bearing;

    SDL_Texture* tankTexture;
    SDL_Renderer* gameRenderer;

};

#endif
