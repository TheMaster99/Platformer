#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include "Vector2f.h"

class Object
{
public:
	void draw(SDL_Renderer* renderer); // Draw object at current position
	void draw(SDL_Renderer* renderer, Vector2f pos); // Draw object at specified position

	void move(Vector2f pos); // Move object to specified position

	Vector2f getPosition(); // Get position of the object

	int getWidth(); // Get width of the image
	int getHeight(); // Get height of the image

	bool init(const char* resourcePath, SDL_Renderer* renderer); // Initialize object with no position, which defaults to ( 0, 0 )
	bool init(const char* resourcePath, Vector2f pos, SDL_Renderer* renderer); // Initialize object with specified position

	void kill(); // Free object from memory

private:
	SDL_Texture* sprite; // The image that represents the object
	Vector2f position; // The position of the object. Default is ( 0, 0 ) because NULL == 0
	SDL_Rect rect; // The rectangle that represents where the image is to be drawn on the screen
	int width, height; // Dimensions of the image
};

#endif