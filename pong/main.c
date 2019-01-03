#include "SDL2/SDL.h"
#include "SDL/SDL_image.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


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
	int xvel;
	int yvel;
	SDL_Rect rect;
	
} Rect;

void clearBlack(SDL_Renderer *rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
	SDL_RenderClear(rend);
}

void drawRect(SDL_Renderer *rend, Rect rect)
{

	SDL_SetRenderDrawColor(rend, rect.red, rect.green, rect.blue, rect.alpha);
	
	rect.rect.x = rect.xpos;
	rect.rect.y = rect.ypos;
	rect.rect.w = rect.width;
	rect.rect.h = rect.height;

	SDL_RenderFillRect(rend, &rect.rect);
	SDL_RenderPresent(rend);

}

int main(int argc, char *argv[])
{
	int game = 1;

	srand(time(NULL));

	int initX = rand() % 2;
	int initY = rand() % 2;

	int frameCount;

	int ballSpeed = 5;
	int nBallSpeed = -5;

	int winWidth = 750;
	int winHeight = 600;

	SDL_Window *win;
	SDL_Renderer *rend; 

	SDL_DisplayMode dm;

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
			winWidth,
			winHeight,
			SDL_WINDOW_OPENGL);

	if (!win)
	{
		SDL_Log("%s\n", SDL_GetError());
		return 1;
	}

	if (SDL_GetCurrentDisplayMode(0, &dm) != 0)
	{
		SDL_Log("%s\n", SDL_GetError());
		return 1;
	}

	rend = SDL_CreateRenderer(win, -1, 0);

	clearBlack(rend);
	
	Rect player1 = {255, 255, 255, 255, 
			10, 100, 0, winHeight/2, 0, 0};

	Rect player2 = {255, 255, 255, 255, 
			10, 100, winWidth-10, winHeight/2, 0, 0};

	Rect ball = {255, 255, 255, 255,
		     10, 10, winWidth/2-ball.width/2, rand() % (winHeight-ball.height), 0, 0};
	
	if (initX)
	{
		ball.xvel = ballSpeed;
	} else 
	{
		ball.xvel = nBallSpeed;
	}

	if (initY)
	{
		ball.yvel = ballSpeed;
	} else 
	{
		ball.yvel = nBallSpeed;
	}

	while (game)
	{
		clearBlack(rend);

		drawRect(rend, player1);
		drawRect(rend, player2);
		drawRect(rend, ball);
		
			
		while (SDL_PollEvent(&event))
		{	

			if (SDL_QuitRequested())
				game = 0;
			
			switch (event.type)
			{
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{

						case SDLK_w:
							player1.yvel = -20;
							break;

						case SDLK_s:										
							player1.yvel = 20;	
							break;
						
						case SDLK_UP:													
							player2.yvel = -20;
							break;

						case SDLK_DOWN:	
							player2.yvel = 20;
							break;

						default: 
							break;
					}
					
					break;

				case SDL_KEYUP:
					switch (event.key.keysym.sym)
					{
						case SDLK_w:
							if (player1.yvel < 0)
								player1.yvel = 0;
							break;

						case SDLK_s:
							if (player1.yvel > 0)
								player1.yvel = 0;
							break;
						
						case SDLK_UP:
							if (player2.yvel < 0)
								player2.yvel = 0;
							break;
						
						case SDLK_DOWN:
							if (player2.yvel > 0)
								player2.yvel = 0;
							break;
						default:
							break;
					}
					
					break;				
			
					
				default:
					break;
			}
			
			player1.ypos += player1.yvel;
			player2.ypos += player2.yvel;


			if (player1.ypos <= 0)
			{
				player1.ypos = 0;
			} else if (player1.ypos >= (winHeight-player1.height))
			{
				player1.ypos = winHeight-player1.height;
			} 

			if (player2.ypos <= 0)
			{
				player2.ypos = 0;
			} else if (player2.ypos >= (winHeight-player2.height))
			{
				player2.ypos = winHeight-player2.height;
			}
	
		}

		if (ball.ypos <= 0)
		{
			ball.yvel = ballSpeed;
		} else if (ball.ypos >= winHeight-ball.height)
		{
			ball.yvel = nBallSpeed;
		}

		if (ball.xpos <= player1.xpos + player1.width && ball.ypos <= player1.ypos + player1.height && ball.ypos >= player1.ypos)
		{
			ball.xvel = ballSpeed;
		} else if (ball.xpos >= player2.xpos - player2.width && ball.ypos <= player2.ypos + player2.height && ball.ypos >= player2.ypos)
		{
			ball.xvel = nBallSpeed;
		}

		if (ball.xpos < 0 || ball.xpos > winWidth)
		{
			game = 0;
		}
			
		ball.ypos += ball.yvel;
		ball.xpos += ball.xvel;
		
		SDL_Delay(1000 / 64);
		
	}

	SDL_DestroyWindow(win);

	SDL_Quit();


	return 0;
}
