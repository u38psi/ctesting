game: main.c init.c exit.c
	gcc -o main.o -c main.c
	gcc -o init.o -c init.c
	gcc -o exit.o -c exit.c
	gcc -o game -l SDL2 -l SDL_image main.o init.o exit.o

clear:
	rm game *.o

run: 
	./game
