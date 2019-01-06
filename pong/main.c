#include "hdrs/main.h"

int main(int argc, char *argv[])
{		

	Window mainWin = {NULL, NULL, SDL_INIT_EVERYTHING, 0, 0, -1, 1024, 784, "Skippers struggle"}; 
	
	initFlags(&mainWin); 
	createWindow(&mainWin); 
	createRenderer(&mainWin); 

	SDL_Texture *skipper;
	SDL_Surface *temp;

	temp = IMG_Load("sprites/img_skipper.png");
	if (!temp)
	{
		error(1);
	}	

	skipper = SDL_CreateTextureFromSurface(mainWin.renderer, temp);

	SDL_FreeSurface(temp);

	SDL_RenderClear(mainWin.renderer);
	SDL_RenderCopy(mainWin.renderer, skipper, NULL, NULL);
	SDL_RenderPresent(mainWin.renderer);

	SDL_Event event;
	
	game = 1;

	while(game)
	{
		
		while (SDL_PollEvent(&event))
		{
			if (SDL_QuitRequested())
				quit(&mainWin, 0);	
			
			switch (event.type)
			{
				case SDL_KEYDOWN:

					switch (event.key.keysym.sym)
					{
						case 0x0D:
							quit(&mainWin, 0);
						
						default:
							break;
					}
			}	
		}

	}

	//DESTROY TEXTURE

	return 0;
	
}
