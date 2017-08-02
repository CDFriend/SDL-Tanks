/*
 * tank.h
 *
 *  Created on: Aug 1, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

class Tank {

public:
	Tank(int initX, int initY);
	void handleKeyboardState(const Uint8 *keyboardState);
	void draw(SDL_Renderer *drawingSurface);

private:
	int xPos;
	int yPos;
	int bearing;

};
