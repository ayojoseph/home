Love Jooseph                0890515
CIS 2500                    Assignment 3
March 13th, 2015

************
Compiling the program
************

The program should be compiled using the following command in the assignment directory:

gcc -std=c99 -Wall -pedantic -Iinclude -c src/functions.c -lncurses

gcc -std=c99 -Wall -pedantic -Iinclude -c src/main.c -lncurses

gcc -Iinclude main.o functions.o -lncurses -o bin/runMe

************
Running the program
************

The following command should be typed to run the program:

./bin/runMe 'input file'

************
Known Limitations
************

-Terminal screen must me maximized for proper printing of rooms
-user can move hero out of rooms through wall
-cannot pick up items
-rooms cannot be bigger than 25X20
-items cannot not be placed in areas over 9 (cannot read second digit)
-Terminal must be manually increased so that the full board can be drawn correctly
-must use WSAD keys to move, Q is to quit the program
