/*
 * tank.h
 *
 *  Created on: Aug 1, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

class Tank {

public:
	Tank(SDL_Renderer *gameRenderer, int initX, int initY);
	~Tank();
	void handleKeyboardState(const Uint8 *keyboardState);
	void draw(SDL_Renderer *drawingSurface);

private:
	int xPos;
	int yPos;
	int bearing;

	SDL_Texture* tankTexture;

};
