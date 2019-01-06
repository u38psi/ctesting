#ifndef _GAME_INIT_H
#define _GAME_INIT_H


#include "exit.h"
#include "SDL2/SDL.h"

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

void initFlags(Window *window);

void createWindow(Window *window);

void createRenderer(Window *window);


#endif
