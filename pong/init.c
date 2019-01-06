#include "hdrs/init.h"

void initFlags(Window *window)
{
	if (SDL_Init(window->initFlags) != 0)
	{
		SDL_Log("ERROR: %s\n", SDL_GetError());
		exitWindow(window->window, window->renderer, 1, 1);
	}
	
}

void createWindow(Window *window)
{
	window->window = SDL_CreateWindow(window->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window->width, window->height, window->windowFlags);
	
	if (!window->window)
	{
		SDL_Log("ERROR: %s\n", SDL_GetError());
		exitWindow(window->window, window->renderer, 1, 1);
	}

}

void createRenderer(Window *window)
{
	window->renderer = SDL_CreateRenderer(window->window, window->renderIndex, window->renderFlags);

	if (!window->renderer)
	{
		SDL_Log("ERROR: %s\n", SDL_GetError());
		exitWindow(window->window, window->renderer, 1, 1);
	}
}
