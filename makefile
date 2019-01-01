game: main.c
	gcc -o game -l SDL2 -l SDL_image main.c

clear:
	rm game

run: 
	./game
