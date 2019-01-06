#ifndef _GAME_INIT_H
#define _GAME_INIT_H

#include "SDL2/SDL.h"
#include "error.h"

typedef struct Window
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	uint32_t initFlags;
	uint32_t windowFlags;
	uint32_t renderFlags;
	int renderIndex;	
	short width;
	short height;
	char *title;
} Window;

char game;

int initFlags(Window *window);

int createWindow(Window *window);

int createRenderer(Window *window);


#endif
