#include <SDL.h>
#include <stdio.h>
#include "Vector2f.h"
#include "Object.h"

bool init();
bool loadMedia();
void close();

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gSplash = NULL;

Object splash;

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	Vector2f splashPos = { 280, 0 };

	splash.init("resources/splash.bmp", splashPos);

	return success;
}

void close()
{
	SDL_FreeSurface(gSplash);
	gSplash = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to intialize!\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Vector2f v1 = { 0,6 };
			Vector2f v2 = { 5,3 };
			v1 += v2;
			
			if (v1.y == 9)
			{
				splash.draw(gScreenSurface);

				SDL_UpdateWindowSurface(gWindow);
			}

			SDL_Delay(10000);
		}
	}

	close();

	return 0;
}