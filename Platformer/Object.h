#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>
#include "Vector2f.h"

class Object
{
public:
	void draw(SDL_Surface* gameSurface);
	void draw(SDL_Surface* gameSurface, Vector2f pos);

	void move(Vector2f pos);

	bool init(const char* resourcePath);
	bool init(const char* resourcePath, Vector2f pos);

private:
	SDL_Surface* sprite;
	Vector2f position;
	SDL_Rect* rect;
};

#endif