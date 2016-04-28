#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include "Vector2f.h"

class Object
{
public:
	void draw(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, Vector2f pos);

	void move(Vector2f pos);

	Vector2f getPosition();

	bool init(const char* resourcePath, SDL_Renderer* renderer);
	bool init(const char* resourcePath, Vector2f pos, SDL_Renderer* renderer);

	void kill();

private:
	SDL_Texture* sprite;
	Vector2f position;
	SDL_Rect rect;
	int width, height;
};

#endif