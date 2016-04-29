#include "Object.h"
#include <stdio.h>

bool Object::init(const char* resourcePath, SDL_Renderer* renderer)
{
	bool success = true;

	SDL_Surface* load = IMG_Load(resourcePath); // Load image to a temporary surface

	if (load == NULL)
	{
		printf("Image failed to load! Error: %s\n", IMG_GetError());
		success = false;
	}
	else
	{
		sprite = SDL_CreateTextureFromSurface(renderer, load); // Transfer the image to a texture
		if (sprite == NULL)
		{
			printf("Texture creation failed! Error: %s\n", SDL_GetError());
			success = false;
		}

		SDL_FreeSurface(load); // Free the temporary surface from memory
	}

	return success;
}

bool Object::init(const char* resourcePath, Vector2f pos, SDL_Renderer* renderer)
{
	bool success = true;

	SDL_Surface* load = IMG_Load(resourcePath); // Load image to a temporary surface

	if (load == NULL)
	{
		printf("Image failed to load! Error: %s\n", IMG_GetError());
		success = false;
	}
	else
	{
		sprite = SDL_CreateTextureFromSurface(renderer, load); // Transfer the image to a texture
		if (sprite == NULL)
		{
			printf("Texture creation failed! Error: %s\n", SDL_GetError());
			success = false;
		}

		SDL_FreeSurface(load); // Free the temporary surface from memory
	}

	position = pos; // Set the object's position

	SDL_QueryTexture(sprite, NULL, NULL, &width, &height); // Get dimensions of the image
	rect = SDL_Rect{ (int)position.x, (int)position.y, width, height }; // Create a rectangle to represent where the texture will be drawn onto the screen

	return success;
}

void Object::kill()
{
	SDL_DestroyTexture(sprite); // Free texture from memory
	sprite = NULL;
}

void Object::move(Vector2f pos)
{
	position = pos; // Set new position

	rect = SDL_Rect{ (int)position.x, (int)position.y, width, height }; // Update the rectangle
}

Vector2f Object::getPosition() // Get the position of the object
{
	return position;
}

void Object::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, sprite, NULL, &rect); // Render the object to the screen
}

void Object::draw(SDL_Renderer* renderer, Vector2f pos)
{
	SDL_RenderCopy(renderer, sprite, NULL, new SDL_Rect{ (int)pos.x, (int)pos.y, width, height }); // Render the object to the screen at a specified position
}