/*
 * sprite_bank.cpp
 * 
 * WARNING: Untested!
 *
 *  Created on: Aug 27, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "tanks/engine/sprite_bank.h"

using namespace Tanks::Engine;

SpriteBank::SpriteBank(SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->bank = new std::map<std::string, SDL_Texture*>;
}

SpriteBank::~SpriteBank(void) {
    delete bank;
}

SDL_Texture* SpriteBank::loadTexture(const char *path) {
    
    // Attempt to find requested filepath in bank
    std::string reqString(path);
    std::map<std::string, SDL_Texture*>::iterator item = bank->find(reqString);
    
    // If the item is found, the texture has already been initialized and
    // can be returned.  Otherwise, a new texture must be created and added
    // before continuing.
    if (item != bank->end()) {
        return item->second;
    }
    else {
        SDL_Texture *newTexture = initSDLTexture(path);
        bank->insert(std::pair<std::string, SDL_Texture*>(reqString, newTexture));
        return newTexture;
    }
    
}

SDL_Texture* SpriteBank::initSDLTexture(const char* path) {
    SDL_Surface *surface = IMG_Load(path);
    if (surface == NULL) {
        printf("Failed to load bullet image! IMG_Error: %s\n", IMG_GetError());
        return SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 20, 20);
    }
    else {
        return SDL_CreateTextureFromSurface(renderer, surface);
    }
}
