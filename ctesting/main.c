#include "SDL2/SDL.h"
#include "SDL/SDL_image.h"
#include "stdio.h"
#include "stdlib.h"


typedef struct Rect
{
	
	int red;
	int green;
	int blue;
	int alpha;
	int width;
	int height;
	int xpos;
	int ypos;
	SDL_Rect rect;
	
} Rect;

int main(int argc, char *argv[])
{
	int game = 1;

	SDL_Window *win;
	SDL_Renderer *rend; 

	SDL_Event event;
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("%s\n", SDL_GetError());
		return 1;
	}

	win = SDL_CreateWindow(
			"Testing", 
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			750,
			600,
			SDL_WINDOW_OPENGL);

	if (!win)
	{
		SDL_Log("%s\n", SDL_GetError());
		return 1;
	}

	rend = SDL_CreateRenderer(win, -1, 0);

	SDL_SetRenderDrawColor(rend, 0, 100, 200, 255);
	SDL_RenderClear(rend);
	
	Rect rect = {255, 255, 255, 255, 
			200, 100, 500, 500};
	
	SDL_SetRenderDrawColor(rend, rect.red, rect.green, rect.blue, rect.alpha);

	while (game)
	{
		
		while (SDL_PollEvent(&event))
		{

			SDL_SetRenderDrawColor(rend, rect.red, rect.green, rect.blue, rect.alpha);
			
			rect.rect.h = rect.height;
			rect.rect.x = rect.xpos;
			rect.rect.y = rect.ypos;

			SDL_RenderFillRect(rend, &rect.rect);
			SDL_RenderPresent(rend);
				
			if (SDL_QuitRequested())
				game = 0;
			
			switch (event.type)
			{
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case 0x0D:
							game = 0;
						
						case 0x61:
							rect.xpos -= 100;
							SDL_Log("%d\n", rect.xpos);
									
							SDL_SetRenderDrawColor(rend, 
										0, 100, 
										200, 255);
							SDL_RenderClear(rend);
							break;
						case 0x64:
							rect.xpos += 100;
							SDL_Log("%d\n", rect.xpos);
							
							SDL_SetRenderDrawColor(rend, 
										0, 100, 
										200, 255); 
							SDL_RenderClear(rend);
							break;

						default: 
							break;
					}				
			
					
				default:
					break;
			}
		}
	
	}

	SDL_DestroyWindow(win);

	SDL_Quit();


	return 0;
}
