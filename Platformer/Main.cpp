#include <SDL.h>
#include <SDL_image.h>
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
SDL_Renderer* gRenderer = NULL;

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
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer failed to initialize! Error: %s\n", SDL_GetError());
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_Image could not intiialize! Error: %s\n", IMG_GetError());
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	Vector2f splashPos = { 280, 0 };

	splash.init("resources/splash.png", splashPos, gRenderer);

	return success;
}

void close()
{
	splash.kill();

	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
	IMG_Quit();
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
		SDL_RenderClear(gRenderer);
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
			else if (e.type == SDL_MOUSEMOTION)
			{
				
			}
		}

		splash.draw(gRenderer);

		SDL_RenderPresent(gRenderer);
	}

		close();

		return 0;
}