#include <SDL.h>
#include <SDL_image.h>
#include <vector>
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

std::vector<Object> objects; // Array of objects

bool init() // Initialize everything that will be required for SDL to run
{
	bool success = true;


	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize SDL
	{
		printf("SDL could not initialize! Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); // Create SDL window
		if (gWindow == NULL)
		{
			printf("Window could not be created! Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED); // Initialize SDL renderer
			if (gRenderer == NULL)
			{
				printf("Renderer failed to initialize! Error: %s\n", SDL_GetError());
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0); // Set default render color to black

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) // Initialize image loading to handle .png images
				{
					printf("SDL_Image could not intiialize! Error: %s\n", IMG_GetError());
				}
			}
		}
	}

	return success;
}

bool loadMedia() // Load objects, images, etc. that will be used
{
	bool success = true;

	objects.push_back(Object()); // Add new object to array, then initialize the new object and set it's position

	objects.at(0).init("resources/splash.png", gRenderer);

	Vector2f splashPos = Vector2f{ SCREEN_WIDTH / 2 - (float)objects.at(0).getWidth() / 2, 0 };

	objects.at(0).move(splashPos);

	objects.push_back(Object());

	objects.at(1).init("resources/splash.png", gRenderer);
	objects.at(1).move(Vector2f{ 0, 0 });

	return success;
}

void close() // Release objects, images, etc. from memory
{
	for (Object o : objects) // Iterate through all objects
	{
		o.kill(); // Kill each object
	}

	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
	IMG_Quit();
}

int main(int argc, char* args[])
{
	if (!init()) // Initialize
	{
		printf("Failed to intialize!\n");
	}
	else
	{
		if (!loadMedia()) // Load
		{
			printf("Failed to load media!\n");
		}
	}

	while (!quit) // Main game loop
	{
		SDL_RenderClear(gRenderer); // Clear the previous frame from the renderer
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) // User clicks exit button
				quit = true;
			else if (e.type == SDL_KEYDOWN) // User presses a key on the keyboard
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					objects.at(0).move(Vector2f{ 0, 0 });
					break;
				case SDLK_SPACE:
					objects.at(0).move(Vector2f{ SCREEN_WIDTH / 2 - (float)objects.at(0).getWidth()/2, 0 });
					break;
				case SDLK_s:
					objects.at(0).move(Vector2f{ SCREEN_WIDTH - (float)objects.at(0).getWidth(), 0 });
					break;
				case SDLK_a:
					objects.at(0).move(Vector2f{ objects.at(0).getPosition().x - 5, 0 });
					break;
				case SDLK_d:
					objects.at(0).move(Vector2f{ objects.at(0).getPosition().x + 5, 0 });
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
			}
			else if (e.type == SDL_MOUSEMOTION) // User moves the mouse
			{
				
			}
		}

		for (Object o : objects)
		{
			o.draw(gRenderer);
		}

		SDL_RenderPresent(gRenderer); // Update window with the new frame
	}

		close(); // Game loop has ended because bool quit is true

		return 0;
}