/*
 * TanksGame.h
 *
 *  Created on: Jul 31, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

#ifndef TANKSGAME_H
#define TANKSGAME_H

#include <SDL2/SDL.h>

#include "tank.h"

namespace Tanks {

    namespace Game {
    
        class TanksGame {
        
        public:
            // Opens an SDL window and blocks program execution until the window is closed.
            void mainLoop();
            TanksGame();
            ~TanksGame();
        
        private:
            // Creates an SDL window and screen surface.
            bool init_sdl();
        
            // Frees all resources related to SDL and closes the SDL window.
            void close_sdl();
        
            // SDL surfaces for running game window
            SDL_Window* gameWindow;
            SDL_Renderer* gameRenderer;
        
            // Human-controlled player object.
            Tank *playerTank;
        
        };
    
    }

}

#endif
