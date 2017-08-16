/*
 * bullet.h
 *
 *  Created on: Aug 15, 2017
 *      Author: Charlie Friend <charles.d.friend@gmail.com>
 */

class Bullet {

public:
	Bullet(SDL_Renderer *gameRenderer, int x, int y, int bearing);
	~Bullet();

	// Update the (xPos, yPos) position of the bullet.
	void update();

	// Draw the bullet on the screen.
	void draw(SDL_Renderer *gameRenderer);

private:
	// (x, y) location of the CENTER of the bullet
	int xPos;
	int yPos;

	// Direction of the bullet's movement (0 being north)
	int bearing;

	SDL_Texture *bulletTexture;

};
