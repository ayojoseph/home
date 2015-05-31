#ifndef _LJOSEPH_MAINH
#define _LJOSEPH_MAINH
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct cursorpos
{
	int * xpos;
	int * ypos;
	int pen;
	char ori;
	char color;
}Cursor;

typedef struct commands {

	char * feed;
	char * raw;
	int value;
	char * dir;

}Command;

// typedef struct cur
// {
// 	int * x;
// 	int * y;
// }typecursor;

struct count
{
	int feed;
}count;


void drawboard();

Command * getEditString(char * s);

void setXy(Command * com, int * x, int * y, char * ori);

void printMarker(int * x, int * y, char * ori);

void feedPrint();



#endif