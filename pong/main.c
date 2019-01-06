#include "hdrs/init.h"
#include "hdrs/exit.h"

#include "SDL2/SDL.h"
#include "SDL/SDL_image.h"

int main(int argc, char *argv[])
{	
  
	Window mainWin = {NULL, NULL, SDL_INIT_EVERYTHING, 0, 0, -1, 1024, 768, "Skippers struggle"}; //WINDOW STRUCT
	
	initFlags(&mainWin); //SDL INIT
	createWindow(&mainWin); //WINDOW CREATION
	createRenderer(&mainWin); //RENDERER CREATION

	SDL_Event event;
	
	game = 1;

	while(game)
	{
		while (SDL_PollEvent(&event))
		{
			if (SDL_QuitRequested())
				exitWindow(mainWin.window, mainWin.renderer, 1, 0);
			
			switch (event.type)
			{
				case SDL_KEYDOWN:

					switch (event.key.keysym.sym)
					{
						case 0x0D:
							exitWindow(mainWin.window, mainWin.renderer, 1, 0);
						
						default:
							break;
					}
			}	
		}

	}

	return 0;
	
}
