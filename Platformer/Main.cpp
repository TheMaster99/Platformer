#include <SDL.h>
#include <stdio.h>
#include "Vector2f.h"
#include "Object.h"

bool init();
bool loadMedia();
void close();

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

bool quit = false;

SDL_Event e;

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
	}

	while (!quit)
	{
		SDL_FillRect(gScreenSurface, NULL, 0x000000);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					splash.move(Vector2f{ 0, 0 });
					break;
				case SDLK_SPACE:
					splash.move(Vector2f{ SCREEN_WIDTH / 2 - 360, 0 });
					break;
				case SDLK_s:
					splash.move(Vector2f{ SCREEN_WIDTH - 720, 0 });
					break;
				case SDLK_a:
					splash.move(Vector2f{ splash.getPosition().x - 5, 0 });
					break;
				case SDLK_d:
					splash.move(Vector2f{ splash.getPosition().x + 5, 0 });
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
			}
		}

		splash.draw(gScreenSurface);

		SDL_UpdateWindowSurface(gWindow);
	}

		close();

		return 0;
}