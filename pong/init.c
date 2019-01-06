#include "hdrs/init.h"

int initFlags(Window *window)
{
	if (SDL_Init(window->initFlags) != 0)
	{
		error(1);
	}
	
}

int createWindow(Window *window)
{
	window->window = SDL_CreateWindow(window->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window->width, window->height, window->windowFlags);
	
	if (!window->window)
	{
		error(1);
	}

}

int createRenderer(Window *window)
{
	window->renderer = SDL_CreateRenderer(window->window, window->renderIndex, window->renderFlags);

	if (!window->renderer)
	{
		error(1);
	}
}
