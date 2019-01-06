#include "hdrs/ret.h"

int quit(Window *window, int ret)
{
	game = 0;
	SDL_DestroyWindow(window->window);
	SDL_DestroyRenderer(window->renderer);
	SDL_Quit();
	if (ret)
		error(ret);
}

