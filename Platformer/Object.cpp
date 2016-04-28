#include "Object.h"
#include <stdio.h>

bool Object::init(const char* resourcePath, SDL_Renderer* renderer)
{
	bool success = true;

	SDL_Surface* load = IMG_Load(resourcePath);

	if (load == NULL)
	{
		printf("Image failed to load! Error: %s\n", IMG_GetError());
		success = false;
	}
	else
	{
		sprite = SDL_CreateTextureFromSurface(renderer, load);
		if (sprite == NULL)
		{
			printf("Texture creation failed! Error: %s\n", SDL_GetError());
			success = false;
		}

		SDL_FreeSurface(load);
	}

	return success;
}

bool Object::init(const char* resourcePath, Vector2f pos, SDL_Renderer* renderer)
{
	bool success = true;

	SDL_Surface* load = IMG_Load(resourcePath);

	if (load == NULL)
	{
		printf("Image failed to load! Error: %s\n", IMG_GetError());
		success = false;
	}
	else
	{
		sprite = SDL_CreateTextureFromSurface(renderer, load);
		if (sprite == NULL)
		{
			printf("Texture creation failed! Error: %s\n", SDL_GetError());
			success = false;
		}

		SDL_FreeSurface(load);
	}

	position = pos;

	SDL_QueryTexture(sprite, NULL, NULL, &width, &height);
	rect = SDL_Rect{ (int)position.x, (int)position.y, width, height };

	return success;
}

void Object::kill()
{
	SDL_DestroyTexture(sprite);
	sprite = NULL;
}

void Object::move(Vector2f pos)
{
	position = pos;

	rect = SDL_Rect{ (int)position.x, (int)position.y, width, height };
}

Vector2f Object::getPosition()
{
	return position;
}

void Object::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, sprite, new SDL_Rect{ 0,0,720,720 }, &rect);
}

void Object::draw(SDL_Renderer* renderer, Vector2f pos)
{
	SDL_RenderCopy(renderer, sprite, NULL, new SDL_Rect{ (int)pos.x, (int)pos.y, width, height });
}