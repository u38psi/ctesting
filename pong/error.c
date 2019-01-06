#include "hdrs/error.h"

int error(int ret)
{
	SDL_Log("ERROR: %s\n", SDL_GetError());
	return ret;
}
