/*
 * sprite_bank.h - Cache of SDL_Texture objects indexed by the filename of
 *                 the textures' respective image files.
 *
 *  Created on: Aug 27, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#ifndef SPRITE_BANK_H
#define SPRITE_BANK_H

#include <map>
#include <string>
#include <SDL2/SDL_image.h>

namespace Tanks {

    namespace Engine {
    
        class SpriteBank {
            
        public:
            // Constructor and destructor
            SpriteBank(SDL_Renderer *renderer);
            ~SpriteBank(void);
            
            // Get an SDL texture from a PNG file path. Load the texture from file if it 
            // is not already present in the bank.
            SDL_Texture* loadTexture(const char *path);
            
        private:
            // Map filepath -> SDL_Texture
            std::map<std::string, SDL_Texture*> *bank;
            
            // Renderer used to create textures
            SDL_Renderer *renderer;
            
            // Creates a new SDL_Texture object from an image file
            SDL_Texture* initSDLTexture(const char *path);
            
        };
        
    }

}

#endif
