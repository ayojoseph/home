all: bin/runMe


bin/runMe: main.o functions.o
	gcc -Iinclude main.o functions.o -lncurses -o bin/runMe
    
main.o: src/main.c -lncurses include/main.h -lncurses
	gcc -std=c99 -Wall -pedantic -Iinclude -c src/main.c -lncurses
    
functions.o: src/functions.c include/functions.h
	gcc -std=c99 -Wall -pedantic -Iinclude -c src/functions.c -lncurses
