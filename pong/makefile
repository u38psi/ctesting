game: main.c init.c ret.c
	gcc -o ret.o -c ret.c
	gcc -o init.o -c init.c
	gcc -o main.o -c main.c
	gcc -o game -lSDL2main -l SDL2 -l SDL2_image main.o init.o ret.o

clear:
	rm game *.o

run: 
	./game
