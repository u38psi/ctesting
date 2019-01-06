#include "hdrs/exit.h"

int exitWindow(SDL_Window *window, SDL_Renderer *renderer, char exit, int error)
{
	game = !exit;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	if (exit)
	{
		SDL_Quit();
		return error;
	}
	
}
