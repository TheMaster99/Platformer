#include "Object.h"
#include <stdio.h>

bool Object::init(const char* resourcePath)
{
	bool success = true;

	sprite = SDL_LoadBMP(resourcePath);

	if (sprite == NULL)
	{
		printf("Unable to load image %s! Error! %s\n", resourcePath, SDL_GetError());
		success = false;
	}

	return success;
}

bool Object::init(const char* resourcePath, Vector2f pos)
{
	bool success = true;

	sprite = SDL_LoadBMP(resourcePath);

	if (sprite == NULL)
	{
		printf("Unable to load image %s! Error! %s\n", resourcePath, SDL_GetError());
		success = false;
	}

	position = pos;

	if (position.x == NULL || position.y == NULL)
	{
		printf("Position vector is null!\n");
		success = false;
	}
	else
	{
		rect = new SDL_Rect{ (int)position.x, (int)position.y, NULL, NULL };
	}

	return success;
}

void Object::move(Vector2f pos)
{
	position = pos;

	if (position.x == NULL || position.y == NULL)
	{
		printf("Position vector is null!\n");
	}
	else
	{
		rect = new SDL_Rect{ (int)position.x, (int)position.y, NULL, NULL };
	}
}

Vector2f Object::getPosition()
{
	return position;
}

void Object::draw(SDL_Surface* gameSurface)
{
	SDL_BlitSurface(sprite, NULL, gameSurface, new SDL_Rect{ (int)position.x, (int)position.y, NULL, NULL });
}

void Object::draw(SDL_Surface* gameSurface, Vector2f pos)
{
	SDL_BlitSurface(sprite, NULL, gameSurface, new SDL_Rect{ (int)pos.x, (int)pos.y, NULL, NULL });
}